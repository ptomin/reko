#region License
/* 
 * Copyright (C) 1999-2015 John Källén.
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

using Reko.Core.CLanguage;
using Reko.Core.Serialization;
using Reko.Core.Types;
using Reko.Core;
using Reko.Core.Configuration;
using Reko.Core.Services;
using Reko.Loading;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Xml;
using System.Xml.Serialization;
using System.ComponentModel.Design;

namespace Reko.Tools.C2Xml
{
    public class CmdListener : DecompilerEventListener
    {
        public ICodeLocation CreateAddressNavigator(Program program, Address address)
        {
            return new NullCodeLocation(address.ToString());
        }

        public ICodeLocation CreateProcedureNavigator(Program program, Procedure proc)
        {
            return new NullCodeLocation(proc.Name);
        }

        public ICodeLocation CreateBlockNavigator(Program program, Block block)
        {
            return new NullCodeLocation(block.Name);
        }

        public void AddDiagnostic(ICodeLocation location, Diagnostic d)
        {
            Console.Out.WriteLine("{0}: {1}: {2}",
                location.Text,
                d.ImageKey,
                d.Message);
        }

        public void Warn(ICodeLocation location, string message)
        {
            Console.Out.WriteLine("{0}: warning: {1}", location.Text, message);
        }

        public void Error(ICodeLocation location, string message)
        {
            Console.Out.WriteLine("{0}: error: {1}", location.Text, message);
        }

        public void Error(ICodeLocation location, Exception ex, string message)
        {
            Console.Out.WriteLine("{0}: error: {1}", location.Text, message);
            Console.Out.WriteLine("    {0}", ex.Message);
            while (ex != null)
            {
                Console.Out.WriteLine("    {0}", ex.StackTrace);
                ex = ex.InnerException;
            }
        }

        public void ShowStatus(string caption)
        {
        }

        public void ShowProgress(string caption, int numerator, int denominator)
        {
        }
    }

    /// <summary>
    /// Parses a C compilation unit and transforms all declarations to the 
    /// XML syntax used by Reko.
    /// </summary>
    public class XmlConverter 
    {
        private TextReader rdr;
        private TextWriter wrt;
        private XmlWriter writer;
        private string inputFileName;
        private ParserState parserState;

        public XmlConverter(TextReader rdr, XmlWriter writer)
        {
            this.rdr = rdr;
            this.writer = writer;
            this.parserState = new ParserState();
       }

        public XmlConverter(TextReader rdr, TextWriter wrt, XmlWriter writer, string inputFileName)
        {
            this.rdr = rdr;
            this.wrt = wrt;
            this.writer = writer;
            this.inputFileName = inputFileName;
            this.parserState = new ParserState();
        }

        public void Convert1()
        {
            var services = new ServiceContainer();

            var config = new DecompilerConfiguration();
            services.AddService<DecompilerEventListener>(new CmdListener());
            services.AddService<IConfigurationService>(config);
            services.AddService<ITypeLibraryLoaderService>(new TypeLibraryLoaderServiceImpl(services));
            //services.AddService<IDiagnosticsService>(diagnosticSvc);
            services.AddService<IFileSystemService>(new FileSystemServiceImpl());
            services.AddService<DecompilerHost>(new NullDecompilerHost());

            var ldr = new Loader(services);
            var decompiler = new DecompilerDriver(ldr, services);
            decompiler.Load("Blade.exe");
            //var sc = new ServiceContainer()
            //var ldr = sc.RequireService<ILoader>();

            var eps = new SortedList<Address, string>();
            foreach (var ep in decompiler.Project.Programs[0].EntryPoints)
                if (ep.Name != null)
                    eps[ep.Address] = ep.Name;

            TextReader input = new StreamReader(inputFileName);

            var s = input.ReadToEnd();

            var protos = s.Split(';');           

            var lexer = new CLexer(rdr);
            var parser = new CParser(parserState, lexer);
            var declarations = parser.Parse();
            var symbolTable = new SymbolTable
            {
                NamedTypes = {
                    { "size_t", new PrimitiveType_v1 { Domain = Domain.UnsignedInt, ByteSize = 4 } },    //$BUGBUG: arch-dependent!
                    { "va_list", new PrimitiveType_v1 { Domain = Domain.Pointer, ByteSize = 4 } } //$BUGBUG: arch-dependent!
                }
            };

            foreach (var decl in declarations)
            {
                symbolTable.AddDeclaration(decl);
            }

            foreach (var ep in eps)
            {
                string prototype = null;
                ProcedureBase_v1 proc = null;

                var procName = ep.Value;

                foreach (var p in symbolTable.Procedures)
                {
                    if (p.Name == procName)
                    {
                        proc = p;
                        break;
                    }
                }

                foreach (var proto in protos)
                {
                    var patt1 = " " + procName + "(";
                    var patt2 = "*" + procName + "(";
                    if (proto.Contains(patt1) || proto.Contains(patt2))
                    {
                        prototype = proto.Trim();
                        break;
                    }
                }

                wrt.WriteLine("/*");
                wrt.WriteLine("................................................................................");
                wrt.WriteLine("................................................................................");
                wrt.WriteLine("................................................................................");
                wrt.WriteLine("................................................................................");
                wrt.WriteLine("*/");

                wrt.WriteLine("");
                wrt.WriteLine("/*");
                wrt.WriteLine("* Module:                 Blade.exe");
                wrt.WriteLine("* Entry point:            0x{0}", ep.Key);
                wrt.WriteLine("*/");
                if (prototype == null)
                {
                    wrt.WriteLine("// TODO fix prototype");
                    wrt.WriteLine("void {0}()", procName);
                    wrt.WriteLine("{");
                    wrt.WriteLine("        assert(\"{0}\" == NULL);", procName);
                    wrt.WriteLine("}");
                    continue;
                }
                wrt.WriteLine("// TODO implement");
                wrt.WriteLine(prototype);

                wrt.WriteLine("{");
                var retType = "";
                retType = proc.Signature.ReturnValue.Type.ToString();
                if (retType == "prim(SignedInt,4)")
                    retType = "int";
                else if (retType == "prim(Real,8)")
                    retType = "double";
                else if (retType == "prim(Real,4)")
                    retType = "float";
                else if (retType == "ptr(prim(Real,8))")
                    retType = "double *";
                else if (retType == "ptr(prim(Character,1))")
                    retType = "const char *";
                else if (retType == "ptr(entity_t)")
                    retType = "entity_t *";
                else if (retType == "ptr(material_t)")
                    retType = "material_t *";
                else if (retType == "void")
                    retType = "void";
                else if (retType == "boolean")
                    retType = "boolean";
                else if (retType == "ptr(PyObject)")
                    retType = "PyObject *";
                else
                    retType = "/*TODO*/" + retType;

                var proc_var_decl = prototype.Replace(proc.Name, "(*bld_proc)");
                var proc_conv = prototype.Replace(proc.Name, "(*)");

                wrt.WriteLine("        {0};", proc_var_decl);

                wrt.WriteLine("        bld_proc = ({0})GetProcAddress(blade, \"{1}\");", proc_conv, proc.Name);

                wrt.Write("        ");
                if (retType != "void")
                    wrt.Write("return ");
                wrt.Write("bld_proc(");
                bool needComma = false;
                foreach(var arg in proc.Signature.Arguments)
                {
                    if (needComma)
                        wrt.Write(", ");
                    needComma = true;
                    wrt.Write(arg.Name);
                }
                wrt.WriteLine(");");
                wrt.WriteLine("}");
                wrt.WriteLine("");
            }

            wrt.WriteLine("/*");
            wrt.WriteLine("................................................................................");
            wrt.WriteLine("................................................................................");
            wrt.WriteLine("................................................................................");
            wrt.WriteLine("................................................................................");
            wrt.WriteLine("*/");

            /*var lib = new SerializedLibrary
            {
                Types = symbolTable.Types.ToArray(),
                Procedures = symbolTable.Procedures.ToList(),
            };
            var ser = SerializedLibrary.CreateSerializer();
            ser.Serialize(writer, lib);*/
        }

        public void Convert()
        {
            var lexer = new CLexer(rdr);
            var parser = new CParser(parserState, lexer);
            var declarations = parser.Parse();
            var symbolTable = new SymbolTable
            {
                NamedTypes = {
                    { "size_t", new PrimitiveType_v1 { Domain = Domain.UnsignedInt, ByteSize = 4 } },    //$BUGBUG: arch-dependent!
                    { "va_list", new PrimitiveType_v1 { Domain = Domain.Pointer, ByteSize = 4 } } //$BUGBUG: arch-dependent!
                }
            };

            foreach (var decl in declarations)
            {
                symbolTable.AddDeclaration(decl);
            }


            var lib = new SerializedLibrary
            {
                Types = symbolTable.Types.ToArray(),
                Procedures = symbolTable.Procedures.ToList(),
            };
            var ser = SerializedLibrary.CreateSerializer();
            ser.Serialize(writer, lib);
        }
    }
}
