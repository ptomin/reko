#region License
/* Copyright (C) 1999-2017 John K�ll�n.
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
using Reko.Core.Lib;
using Reko.Core.Output;
using Reko.Core.Serialization;
using Reko.Core.Services;
using Reko.Core.Types;
using Reko.Scanning;
using Reko.Loading;
using Reko.Analysis;
using Reko.Structure;
using Reko.Typing;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml;
using Reko.Core.Assemblers;
using System.Threading;
using Reko.Core.Configuration;
using System.Diagnostics;
using Reko.Core.Code;

namespace Reko
{
    public interface IDecompiler
    {
        Project Project { get; }

        bool Load(string fileName, string loader=null);
        Program LoadRawImage(string file, LoadDetails raw);
        void ScanPrograms();
        ProcedureBase ScanProcedure(ProgramAddress paddr);
        void AnalyzeDataFlow();
        void ReconstructTypes();
        void StructureProgram();
        void WriteDecompilerProducts();

        void Assemble(string file, Assembler asm);
    }

	/// <summary>
	/// The main driver class for decompilation of binaries. 
	/// </summary>
	/// <remarks>
	/// This class is named this way as the previous name 'Decompiler' causes C# to get confused
	/// between the namespace and the class name.
	/// </remarks>
	public class DecompilerDriver : IDecompiler
	{
		private DecompilerHost host;
		private readonly ILoader loader;
		private IScanner scanner;
        private DecompilerEventListener eventListener;
        private IServiceProvider services;

        public DecompilerDriver(ILoader ldr, IServiceProvider services)
        {
            if (ldr == null)
                throw new ArgumentNullException("ldr");
            if (services == null)
                throw new ArgumentNullException("services");
            this.loader = ldr;
            this.host = services.RequireService<DecompilerHost>();
            this.services = services;
            this.eventListener = services.RequireService<DecompilerEventListener>();
        }

        public Project Project { get { return project; } set { project = value; ProjectChanged.Fire(this); } }
        public event EventHandler ProjectChanged;
        private Project project;

        /// <summary>
        /// Main entry point of the decompiler. Loads, decompiles, and outputs the results.
        /// </summary>
        public void Decompile(string filename, string loader = null)
        {
            try
            {
                Load(filename, loader);
                ScanPrograms();
                AnalyzeDataFlow();
                ReconstructTypes();
                StructureProgram();
                WriteDecompilerProducts();
            }
            catch (Exception ex)
            {
                eventListener.Error(
                    new NullCodeLocation(filename),
                    ex,
                    "An internal error occurred while decompiling.");
            }
            finally
            {
                eventListener.ShowStatus("Decompilation finished.");
            }
        }

        ///<summary>
        /// Determines the signature of the procedures,
		/// the locations and types of all the values in the program.
		///</summary>
        public virtual void AnalyzeDataFlow()
        {
            var eventListener = services.RequireService<DecompilerEventListener>();
            foreach (var program in project.Programs)
            {
                eventListener.ShowStatus("Performing interprocedural analysis.");
                var ir = new ImportResolver(project, program, eventListener);
                var dfa = new DataFlowAnalysis(program, ir, eventListener);
                if (program.NeedsSsaTransform)
                {
                    dfa.UntangleProcedures();
                }
                dfa.BuildExpressionTrees();
                host.WriteIntermediateCode(program, writer => { EmitProgram(program, dfa, writer); });
            }
            eventListener.ShowStatus("Interprocedural analysis complete.");
        }

        public void DumpAssembler(Program program, Formatter wr)
        {
            if (wr == null || program.Architecture == null)
                return;
            Dumper dump = new Dumper(program);
            dump.Dump(wr);
        }

        private void EmitProgram(Program program, DataFlowAnalysis dfa, TextWriter output)
        {
            if (output == null)
                return;
            foreach (Procedure proc in program.Procedures.Values)
            {
                if (program.NeedsSsaTransform && dfa != null)
                {
                    ProcedureFlow flow = dfa.ProgramDataFlow[proc];
                    TextFormatter f = new TextFormatter(output);
                    if (flow.Signature != null)
                        flow.Signature.Emit(proc.Name, FunctionType.EmitFlags.LowLevelInfo, f);
                    else if (proc.Signature != null)
                        proc.Signature.Emit(proc.Name, FunctionType.EmitFlags.LowLevelInfo, f);
                    else
                        output.Write("Warning: no signature found for {0}", proc.Name);
                    output.WriteLine();
                    flow.Emit(program.Architecture, output);
                    foreach (Block block in new DfsIterator<Block>(proc.ControlGraph).PostOrder().Reverse())
                    {
                        if (block == null)
                            continue;
                        block.Write(output);

                        BlockFlow bf = dfa.ProgramDataFlow[block];
                        if (bf != null)
                        {
                            bf.Emit(program.Architecture, output);
                            output.WriteLine();
                        }
                    }
                }
                else
                {
                    proc.Write(false, output);
                }
                output.WriteLine();
                output.WriteLine();
            }
            output.Flush();
        }

        /// <summary>
        /// Loads (or assembles) the decompiler project. If a binary file is
        /// specified instead, we create a simple project for the file.
        /// </summary>
        /// <param name="fileName">The filename to load.</param>
        /// <param name="loaderName">Optional .NET class name of a custom
        /// image loader</param>
        /// <returns>True if what was loaded was an actual project</returns>
        public bool Load(string fileName, string loaderName = null)
        {
            eventListener.ShowStatus("Loading source program.");
            byte[] image = loader.LoadImageBytes(fileName, 0);
            var projectLoader = new ProjectLoader(this.services, loader, eventListener);
            projectLoader.ProgramLoaded += (s, e) => { RunScriptOnProgramImage(e.Program, e.Program.User.OnLoadedScript); };
            this.Project = projectLoader.LoadProject(fileName, image);
            bool isProject;
            if (Project != null)
            {
                isProject = true;
            }
            else
            {
                var program = loader.LoadExecutable(fileName, image, loaderName, null);
                this.Project = CreateDefaultProject(fileName, program);
                this.Project.LoadedMetadata = program.Platform.CreateMetadata();
                program.EnvironmentMetadata = this.Project.LoadedMetadata;
                isProject = false;
            }
            BuildImageMaps();
            eventListener.ShowStatus("Source program loaded.");
            return isProject;
        }

        /// <summary>
        /// Build image maps for each program in preparation of the scanning
        /// phase.
        /// </summary>
        private void BuildImageMaps()
        {
            foreach (var program in this.Project.Programs)
            {
                program.BuildImageMap();
            }
        }

        public void RunScriptOnProgramImage(Program program, Script_v2 script)
        {
            if (script == null || !script.Enabled)
                return;
            IScriptInterpreter interpreter;
            try
            {
                //$TODO: should be in the config file, yeah.
                var type = Type.GetType("Reko.ImageLoaders.OdbgScript.OllyLang,Reko.ImageLoaders.OdbgScript");
                interpreter = (IScriptInterpreter)Activator.CreateInstance(type, services);
            }
            catch (Exception ex)
            {
                eventListener.Error(new NullCodeLocation(""), ex, "Unable to load OllyLang script interpreter.");
                return;
            }

            try
            {
                interpreter.LoadFromString(script.Script, null);
                interpreter.Run();
            }
            catch (Exception ex)
            {
                eventListener.Error(new NullCodeLocation(""), ex, "An error occurred while running the script.");
            }
        }

        public void Assemble(string fileName, Assembler asm)
        {
            eventListener.ShowStatus("Assembling program.");
            var program = loader.AssembleExecutable(fileName, asm, null);
            Project = CreateDefaultProject(fileName, program);
            eventListener.ShowStatus("Assembled program.");
        }

        /// <summary>
        /// Loads a program into memory, but performs no relocations.
        /// </summary>
        /// <param name="fileName"></param>
        /// <param name="arch"></param>
        /// <param name="platform"></param>
        public Program LoadRawImage(string fileName, LoadDetails raw)
        {
            eventListener.ShowStatus("Loading raw bytes.");
            byte[] image = loader.LoadImageBytes(fileName, 0);
            var program = loader.LoadRawImage(fileName, image, null, raw);
            Project = CreateDefaultProject(fileName, program);
            eventListener.ShowStatus("Raw bytes loaded.");
            return program;
        }

        protected Project CreateDefaultProject(string fileName, Program program)
        {
            program.Filename = fileName;
            program.EnsureFilenames(fileName);

            var project = new Project
            {
                Programs = { program },
            };
            return project;
        }

		/// <summary>
		/// Extracts type information from the typeless rewritten programs.
		/// </summary>
		/// <param name="host"></param>
		/// <param name="ivs"></param>
        public void ReconstructTypes()
        {
            foreach (var program in Project.Programs.Where(p => p.NeedsTypeReconstruction))
            {
                TypeAnalyzer analyzer = new TypeAnalyzer(eventListener);
                try
                {
                    try
                    {
                        analyzer.RewriteProgram(program);
                    }
                    catch (Exception ex)
                    {
                        eventListener.Error(new NullCodeLocation(""), ex, "Error when reconstructing types.");
                    }
                } 
                finally
                {
                    host.WriteTypes(program, analyzer.WriteTypes);
                }
            }
        }

        public void WriteDecompiledProcedures(Program program, TextWriter w)
        {
            WriteHeaderComment(Path.GetFileName(program.OutputFilename), program, w);
            w.WriteLine("#include \"{0}\"", Path.GetFileName(program.TypesFilename));
            w.WriteLine();
            var fmt = new AbsynCodeFormatter(new TextFormatter(w));
            foreach (var de in program.Procedures)
            {
                w.WriteLine("// {0}: {1}", de.Key, de.Value);
                var proc = de.Value;
                try
                {
                    fmt.Write(proc);
                    w.WriteLine();
                }
                catch (Exception ex)
                {
                    w.WriteLine();
                    w.WriteLine("// Exception {0} when writing procedure.", ex.Message);
                }
            }
        }

        public void WriteGlobals(Program program, TextWriter w)
        {
            WriteHeaderComment(Path.GetFileName(program.OutputFilename), program, w);
            w.WriteLine("#include \"{0}\"", Path.GetFileName(program.TypesFilename));
            w.WriteLine();
            var gdw = new GlobalDataWriter(program, services);
            gdw.WriteGlobals(new TextFormatter(w));
            w.WriteLine();
        }
    
        public void WriteDecompiledTypes(Program program, TextWriter w)
        {
            WriteHeaderComment(Path.GetFileName(program.TypesFilename), program, w);
            w.WriteLine("/*"); program.TypeStore.Write(w); w.WriteLine("*/");
            var tf = new TextFormatter(w)
            {
                Indentation = 0,
            };
            var fmt = new TypeFormatter(tf);
            foreach (EquivalenceClass eq in program.TypeStore.UsedEquivalenceClasses)
            {
                if (eq.DataType != null)
                {
                    tf.WriteKeyword("typedef");     //$REVIEW: C/C++-specific
                    tf.Write(" ");
                    fmt.Write(eq.DataType, eq.Name);
                    w.WriteLine(";");
                    w.WriteLine();
                }
            }
        }

        /// <summary>
        /// Starts a scan at address <paramref name="addr"/> on the user's request.
        /// </summary>
        /// <param name="addr"></param>
        /// <returns>a ProcedureBase, because the target procedure may have been a thunk or 
        /// an linked procedure the user has decreed not decompileable.</returns>
        public ProcedureBase ScanProcedure(ProgramAddress paddr)
        {
            if (scanner == null)        //$TODO: it's unfortunate that we depend on the scanner of the Decompiler class.
                scanner = CreateScanner(paddr.Program);
            Procedure_v1 sProc;
            var procName = paddr.Program.User.Procedures.TryGetValue(
                paddr.Address, out sProc) ? sProc.Name : null;
            return scanner.ScanProcedure(paddr.Address, procName, paddr.Program.Architecture.CreateProcessorState());
        }

		/// <summary>
		/// Generates the control flow graph and finds executable code in each program.
		/// </summary>
		/// <param name="program">the program whose flow graph we seek</param>
		/// <param name="cfg">configuration information</param>
		public void ScanPrograms()
		{
			if (Project.Programs.Count == 0)
				throw new InvalidOperationException("Programs must be loaded first.");

            foreach (Program program in Project.Programs)
            {
                ScanProgram(program);
            }
		}

        private void ScanProgram(Program program)
        {
            if (!program.NeedsScanning)
                return;
            try
            {
                eventListener.ShowStatus("Rewriting reachable machine code.");
                scanner = CreateScanner(program);
                scanner.ScanImage();
                CheckCFG(program);
                eventListener.ShowStatus("Finished rewriting reachable machine code.");
            }
            finally
            {
                eventListener.ShowStatus("Writing .asm and .dis files.");
                host.WriteDisassembly(program, w => DumpAssembler(program, w));
                host.WriteIntermediateCode(program, w => EmitProgram(program, null, w));
            }
        }

        private void CheckCFG(Program program)
        {
            foreach(var proc in program.Procedures.Values)
            {
                foreach (var block in proc.ControlGraph.Blocks)
                {
                    var lastIntruction = (block.Statements.Count == 0) ?
                        null : 
                        block.Statements.Last.Instruction;
                    if (block.Succ.Count >= 2 &&
                        !(lastIntruction is Branch) &&
                        !(lastIntruction is SwitchInstruction))
                    {
                        while (block.Succ.Count >= 2)
                            proc.ControlGraph.RemoveEdge(block, block.ElseBlock);
                    }
                }
            }
        }

        public IDictionary<Address, FunctionType> LoadCallSignatures(
            Program program, 
            ICollection<SerializedCall_v1> userCalls)
        {
            return
                userCalls
                .Where(sc => sc != null && sc.Signature != null)
                .Select(sc =>
                {
                //$BUG: need access to platform.Metadata.
                    var sser = program.CreateProcedureSerializer();
                    Address addr;
                    if (program.Architecture.TryParseAddress(sc.InstructionAddress, out addr))
                    {
                        return new KeyValuePair<Address, FunctionType>(
                            addr,
                            sser.Deserialize(sc.Signature, program.Architecture.CreateFrame()));
                    }
                    else
                        return new KeyValuePair<Address, FunctionType>(null, null);
                })
                .ToDictionary(item => item.Key, item => item.Value);
        }

        private IScanner CreateScanner(Program program)
        {
            return new Scanner(
                program,
                new ImportResolver(project, program, eventListener),
                services);
        }

        /// <summary>
        /// Extracts structured program constructs out of snarled goto nests, if possible.
        /// Since procedures are now independent of each other, this analysis
        /// is done one procedure at a time.
        /// </summary>
        public void StructureProgram()
		{
            foreach (var program in project.Programs)
            {
                int i = 0;
                foreach (Procedure proc in program.Procedures.Values)
                {
                    if (eventListener.IsCanceled())
                        return;
                    try
                    {
                        eventListener.ShowProgress("Rewriting procedures to high-level language.", i, program.Procedures.Values.Count);
                        ++i;
                        IStructureAnalysis sa = new StructureAnalysis(eventListener, program, proc);
                        sa.Structure();
                    }
                    catch (Exception e)
                    {
                        eventListener.Error(
                            eventListener.CreateProcedureNavigator(program, proc),
                            e,
                            "An error occurred while rewriting procedure to high-level language.");
                    }
                }
                WriteDecompilerProducts();
            }
			eventListener.ShowStatus("Rewriting complete.");
		}

		public void WriteDecompilerProducts()
		{
            foreach (var program in Project.Programs)
            {
                host.WriteTypes(program, w => WriteDecompiledTypes(program, w));
                host.WriteDecompiledCode(program, w => WriteDecompiledProcedures(program, w));
                host.WriteGlobals(program, w => WriteGlobals(program, w));
            }
		}

		public void WriteHeaderComment(string filename, Program program, TextWriter w)
		{
			w.WriteLine("// {0}", filename);
			w.WriteLine("// Generated by decompiling {0}", Path.GetFileName(program.Filename));
			w.WriteLine("// using Reko decompiler version {0}.", AssemblyMetadata.AssemblyFileVersion);
			w.WriteLine();
		}
	}
}
