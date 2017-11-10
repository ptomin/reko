﻿#region License
/* 
 * Copyright (C) 1999-2017 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Code;
using Reko.Core.Expressions;
using Reko.Core.Services;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

namespace Reko.Analysis
{
    /// <summary>
    /// This interprocedural program analysis determines, for each procedure,
    /// which out parameters are not actually used, and removes them both from
    /// the procedure itself and also from all of its callers.
    /// </summary>
    public class UnusedOutValuesRemover
    {
        public static TraceSwitch trace = new TraceSwitch(typeof(UnusedOutValuesRemover).Name, "Trace removal of ununsed out values");

        private List<SsaTransform> ssts;
        private WorkList<SsaState> wl;
        private Program program;
        private Dictionary<Procedure, SsaState> procToSsa;
        private ProgramDataFlow dataFlow;
        private DecompilerEventListener eventListener;

        public UnusedOutValuesRemover(
            Program program,
            List<SsaTransform> ssts,
            ProgramDataFlow dataFlow,
            DecompilerEventListener eventListener)
        { 
            this.dataFlow = dataFlow;
            this.program = program;
            this.ssts = ssts;
            this.eventListener = eventListener;
            this.procToSsa = ssts
                .Select(t => t.SsaState)
                .ToDictionary(s => s.Procedure);
        }

        public void Transform()
        {
            bool change;
            do
            {
                if (eventListener.IsCanceled())
                    return;
                change = false;
                this.wl = new WorkList<SsaState>(ssts.Select(t => t.SsaState));
                SsaState ssa;
                while (wl.GetWorkItem(out ssa))
                {
                    if (this.eventListener.IsCanceled())
                        return;
                    var vp = new ValuePropagator(program.Architecture, ssa, eventListener);
                    vp.Transform();
                    change |= RemoveUnusedDefinedValues(ssa, wl);
                }
            } while (change);
            foreach (var proc in procToSsa.Keys)
            {
                var liveOut = CollectLiveOutStorages(proc);
                var flow = this.dataFlow[proc];
                flow.LiveOut = SummarizeStorageBitranges(flow.LiveOut.Concat(liveOut));
                /*
                flow.LiveOut = flow.LiveOut.Concat(liveOut)
                    .Where(de => de.Key is RegisterStorage)
                    .Select(de => new KeyValuePair<RegisterStorage, BitRange>((RegisterStorage)de.Key, de.Value))
                    .GroupBy(
                        de => de.Key.Domain,
                        (g, items) => items
                            .OrderByDescending(i => i.Value.Extent)
                            .Select(i => new KeyValuePair<RegisterStorage, BitRange>(
                                program.Architecture.GetSubregister(i.Key, i.Value.Lsb, i.Value.Extent),
                                i.Value))
                            .First())
                    .ToDictionary(k => (Storage)k.Key, v => v.Value);*/
                flow.grfLiveOut |= liveOut.Keys
                    .OfType<FlagGroupStorage>()
                    .Select(stg => stg.FlagGroupBits)
                    .Aggregate(0u, (grf, total) => total |= grf);
            }
        }

        private Dictionary<Storage, BitRange> SummarizeStorageBitranges(
            IEnumerable<KeyValuePair<Storage, BitRange>> items)
        {
            var registerDomains = new Dictionary<StorageDomain, KeyValuePair<Storage, BitRange>>();
            var fpuStorages = new Dictionary<Storage, BitRange>();
            foreach (var item in items)
            {
                RegisterStorage reg;
                FpuStackStorage fpu;
                if (item.Key.As(out reg))
                {
                    KeyValuePair<Storage, BitRange> widestRange;
                    if (!registerDomains.TryGetValue(reg.Domain, out widestRange))
                    {
                        widestRange = new KeyValuePair<Storage, BitRange>(reg, item.Value);
                        registerDomains.Add(reg.Domain, widestRange);
                    }
                    else
                    {
                        int min = Math.Min(item.Value.Lsb, widestRange.Value.Lsb);
                        int max = Math.Min(item.Value.Msb, widestRange.Value.Msb);
                        if (item.Key.Covers(widestRange.Key))
                        {
                            widestRange = new KeyValuePair<Storage, BitRange>(reg, item.Value);
                            registerDomains[reg.Domain] = widestRange;
                        }
                    }
                }
                else if (item.Key.As(out fpu))
                {
                    fpuStorages[fpu] = new BitRange(0, (int)fpu.BitSize);
                }
            }
            return registerDomains.Select(r => r.Value).Concat(fpuStorages)
                .ToDictionary(k => k.Key, v => v.Value);
        }

        /// <summary>
        /// Remove any UseInstructions in the exit block of the procedure that 
        /// can be proved to be dead out.
        /// </summary>
        /// <param name="ssa"></param>
        /// <param name="wl"></param>
        public bool RemoveUnusedDefinedValues(SsaState ssa, WorkList<SsaState> wl)
        {
            bool change = false;
            Debug.Print("UVR: {0}", ssa.Procedure);
            var liveOutStorages = CollectLiveOutStorages(ssa.Procedure);
            var deadStms = new HashSet<Statement>();
            var deadStgs = new HashSet<Storage>();
            FindDeadStatementsInExitBlock(ssa, liveOutStorages, deadStms, deadStgs);

            // Now remove statements that are known to be dead.
            foreach (var stm in deadStms)
            {
                Debug.Print("UVR: {0}, deleting {1}", ssa.Procedure.Name, stm.Instruction);
                ssa.DeleteStatement(stm);
                change = true;
            }

            // If any instructions were removed, update the callers. 
            if (!ssa.Procedure.Signature.ParametersValid && deadStms.Count > 0)
            {
                DeadCode.Eliminate(ssa);
                foreach (Statement stm in program.CallGraph.CallerStatements(ssa.Procedure))
                {
                    var ci = stm.Instruction as CallInstruction;
                    if (ci == null)
                        continue;
                    var ssaCaller = this.procToSsa[stm.Block.Procedure];
                    if (RemoveDeadUses(ssaCaller, ci, deadStgs))
                    {
                        wl.Add(ssaCaller);
                    }
                }
            }
            return change;
        }

        private static void FindDeadStatementsInExitBlock(
            SsaState ssa,
            Dictionary<Storage, BitRange> liveOutStorages,
            HashSet<Statement> deadStms, 
            HashSet<Storage> deadStgs)
        {
            foreach (var stm in ssa.Procedure.ExitBlock.Statements)
            {
                var use = stm.Instruction as UseInstruction;
                if (use == null)
                    continue;
                var ids = ExpressionIdentifierUseFinder.Find(ssa.Identifiers, use.Expression);
                foreach (var id in ids)
                {
                    var stg = id.Storage;
                    if (!liveOutStorages.ContainsKey(stg))
                    {
                        deadStgs.Add(stg);
                        deadStms.Add(stm);
                    }
                }
            }
        }

        /// <summary>
        /// Collects the storages that are live-out by looking at all known
        /// call sites and forming the union of all live storages at the call
        /// site.
        /// </summary>
        /// <param name="procCallee">Procedure that was called</param>
        /// <returns></returns>
        private Dictionary<Storage, BitRange> CollectLiveOutStorages(Procedure procCallee)
        {
            var liveOutStorages = new Dictionary<Storage, BitRange>();

            var sig = procCallee.Signature;
            if (sig.ParametersValid)
            {
                // Already have a signature, use that to define the 
                // set of live storages.

                if (!sig.HasVoidReturn)
                {
                    liveOutStorages.Add(
                        sig.ReturnValue.Storage,
                        new BitRange(0, sig.ReturnValue.DataType.BitSize));
                }
            }
            else
            {
                var urf = new UsedRegisterFinder(program.Architecture, dataFlow, eventListener);
                foreach (Statement stm in program.CallGraph.CallerStatements(procCallee))
                {
                    var ci = stm.Instruction as CallInstruction;
                    if (ci == null)
                        continue;
                    var ssaCaller = this.procToSsa[stm.Block.Procedure];
                    foreach (var def in ci.Definitions)
                    {
                        var id = def.Expression as Identifier;
                        if (id == null)
                            continue;
                        var sid = ssaCaller.Identifiers[id];
                        if (sid.Uses.Count > 0)
                        {
                            var br = urf.Classify(ssaCaller, sid);
                            BitRange brOld;
                            if (liveOutStorages.TryGetValue(def.Storage, out brOld))
                            {
                                br = br | brOld;
                            }
                            if (!br.IsEmpty)
                            {
                                liveOutStorages[def.Storage] = br;
                            }
                        }
                    }
                }
            }
            return liveOutStorages;
        }

        private bool RemoveDeadUses(SsaState ssa, CallInstruction ci, HashSet<Storage> deadStgs)
        {
            var deadUses = new List<CallBinding>();
            foreach (var use in ci.Definitions)
            {
                var id = use.Expression as Identifier;
                if (id == null)
                    continue;
                if (deadStgs.Contains(id.Storage))
                {
                    deadUses.Add(use);
                }
            }
            if (deadUses.Count > 0)
            {
                ci.Definitions.ExceptWith(deadUses);
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}