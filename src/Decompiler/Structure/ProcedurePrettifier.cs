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

using System;
using Reko.Core;
using Reko.Core.Absyn;

namespace Reko.Structure
{
    /// <summary>
    /// Performs aesthetic post-processing on the structured code graph.
    /// </summary>
    public class ProcedurePrettifier : IAbsynVisitor<AbsynStatement>
    {
        private Procedure proc;

        public ProcedurePrettifier(Procedure proc)
        {
            this.proc = proc;
        }

        public AbsynStatement VisitAssignment(AbsynAssignment ass)
        {
            return ass;
        }

        public AbsynStatement VisitBreak(AbsynBreak brk)
        {
            return brk;
        }

        public AbsynStatement VisitCase(AbsynCase absynCase)
        {
            return absynCase;
        }

        public AbsynStatement VisitContinue(AbsynContinue cont)
        {
            return cont;
        }

        public AbsynStatement VisitDeclaration(AbsynDeclaration decl)
        {
            return decl;
        }

        public AbsynStatement VisitDefault(AbsynDefault def)
        {
            return def;
        }

        public AbsynStatement VisitDoWhile(AbsynDoWhile loop)
        {
            for (int i = 0; i < loop.Body.Count; ++i)
            {
                loop.Body[i] = loop.Body[i].Accept(this);
            }
            return loop;
        }

        public AbsynStatement VisitGoto(AbsynGoto gotoStm)
        {
            return gotoStm;
        }

        public AbsynStatement VisitIf(AbsynIf ifStm)
        {
            for (int i = 0; i < ifStm.Then.Count; ++i)
            {
                ifStm.Then[i] = ifStm.Then[i].Accept(this);
            }

            for (int i = 0; i < ifStm.Then.Count; ++i)
            {
                ifStm.Then[i] = ifStm.Then[i].Accept(this);
            }

            if (ifStm.Then.Count == 0 && ifStm.Else.Count > 0)
            {
                ifStm.Condition = ifStm.Condition.Invert();
                ifStm.Then.AddRange(ifStm.Else);
                ifStm.Else.Clear();
            }
            return ifStm;
        }

        public AbsynStatement VisitLabel(AbsynLabel lbl)
        {
            return lbl;
        }

        public AbsynStatement VisitLineComment(AbsynLineComment comment)
        {
            return comment;
        }

        public AbsynStatement VisitReturn(AbsynReturn ret)
        {
            return ret;
        }

        public AbsynStatement VisitSideEffect(AbsynSideEffect side)
        {
            return side;
        }

        public AbsynStatement VisitSwitch(AbsynSwitch absynSwitch)
        {
            for (int i = 0; i < absynSwitch.Statements.Count; ++i)
            {
                absynSwitch.Statements[i] = absynSwitch.Statements[i].Accept(this);
            }
            return absynSwitch;
        }

        public AbsynStatement VisitWhile(AbsynWhile loop)
        {
            for (int i = 0; i < loop.Body.Count; ++i)
            {
                loop.Body[i] = loop.Body[i].Accept(this);
            }
            return loop;
        }

        public void Transform()
        {
            for (int i = 0; i < proc.Body.Count; ++i)
            {
                proc.Body[i] = proc.Body[i].Accept(this);
            }
        }
    }
}