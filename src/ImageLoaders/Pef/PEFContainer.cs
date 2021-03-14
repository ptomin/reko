#region License
/* 
 * Copyright (C) 2018-2021 Stefano Moioli <smxdev4@gmail.com>.
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
using Reko.Core.Memory;
using Reko.Core.Types;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Reko.ImageLoaders.Pef
{
    public class PEFContainer
    {
        public readonly PEFContainerHeader ContainerHeader;
        private readonly PEFSectionHeader[] sectionHeaders;
        private readonly string?[] sectionNameTable;

        public PEFContainer(PEFContainerHeader hdr, PEFSectionHeader[] secHdrs, string[] sectionNameTable)
        {
            this.ContainerHeader = hdr;
            this.sectionHeaders = secHdrs;
            this.sectionNameTable = sectionNameTable;
        }

        /////

        public IEnumerable<ImageSegment> GetImageSegments(EndianByteImageReader rdr, Address addrLoad)
        {
            var addr = addrLoad;
            for (int i=0; i<ContainerHeader.sectionCount; i++)
            {
                PEFSectionHeader sectionHeader = sectionHeaders[i];
                
                byte[] containerData = rdr.ReadAt(sectionHeader.containerOffset, rdr => rdr.ReadBytes(sectionHeader.packedSize));

                if (sectionHeader.IsCompressedSection())
                {
                    MemoryStream output = new MemoryStream();

                    // if the section is packed, the data we just read is the compressed section data we need to interpret
                    var interp = new PefOpcodeInterpreter(containerData, output);
                    interp.RunProgram();

                    // replace PEF bytecode with decoded output from the interpreter
                    containerData = output.ToArray();
                }

                if (sectionHeader.defaultAddress != 0)
                    addr = Address.Ptr32(sectionHeader.defaultAddress);
                else
                    addr = addrLoad;
                var segment = new ImageSegment(
                    sectionNameTable[i] ?? $"seg{sectionHeader.defaultAddress:X8}",
                    new ByteMemoryArea(addr, containerData),
                    sectionHeader.GetAccessMode());
                yield return segment;

                addrLoad = (segment.Address + containerData.Length).Align(0x1000);
            }
        }

        private static IEnumerable<PEFSectionHeader> ReadSections(PEFContainerHeader containerHeader, EndianByteImageReader rdr)
        {
            for (int i = 0; i < containerHeader.sectionCount; i++)
            {
                yield return rdr.ReadStruct<PEFSectionHeader>();
            }       
        }

        private static string? GetStandardSectionName(PEFSectionHeader section)
        {
            return section.sectionKind switch
            {
                PEFSectionType.Code => ".text",
                PEFSectionType.UnpackedData => ".data",
                PEFSectionType.PatternInitializedData => ".data",
                PEFSectionType.Constant => ".rodata",
                PEFSectionType.Loader => ".loader",
                PEFSectionType.Debug => ".debug",
                PEFSectionType.ExecutableData => ".data",
                PEFSectionType.Exception => ".exception",
                PEFSectionType.Traceback => ".traceback",
                _ => null
            };
        }

        private static IEnumerable<string> ReadSectionNameTable(IEnumerable<PEFSectionHeader> sectionHeaders, EndianByteImageReader rdr)
        {
            long start = rdr.Offset;

            return sectionHeaders.Select(hdr =>
            {
                if (hdr.nameOffset == -1)
                {
                    return GetStandardSectionName(hdr) ?? "(unnamed)";
                }
                return rdr.ReadAt(start + hdr.nameOffset, rdr => rdr.ReadCString(PrimitiveType.Char, Encoding.ASCII).ToString());
            });
        }

        public static PEFContainer Load(EndianByteImageReader rdr)
        {
            var hdr = rdr.ReadStruct<PEFContainerHeader>();
            if (hdr.sectionCount == 0)
                throw new BadImageFormatException($"Binary image has 0 sections.");
            var secHdrs = ReadSections(hdr, rdr).ToArray();
            var sectionNameTable = ReadSectionNameTable(secHdrs, rdr).ToArray();
            var result = new PEFContainer(hdr, secHdrs, sectionNameTable);
            return result;
        }
    }
}
