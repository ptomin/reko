#region License
/* 
 * Copyright (C) 1999-2019 John Källén.
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

using Moq;
using NUnit.Framework;
using Reko.Arch.XCore;
using Reko.Core;
using Reko.Core.Rtl;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reko.UnitTests.Arch.XCore
{
    [TestFixture]
    public class XCoreRewriterTests : RewriterTestBase
    {
        private readonly XCore200Architecture arch;
        private readonly Address addr;

        public XCoreRewriterTests()
        {
            this.arch = new XCore200Architecture("xcore");
            this.addr = Address.Ptr32(0x00100000);
        }

        public override IProcessorArchitecture Architecture => arch;

        public override Address LoadAddress => addr;

        protected override IEnumerable<RtlInstructionCluster> GetRtlStream(MemoryArea mem, IStorageBinder binder, IRewriterHost host)
        {
            var state = arch.CreateProcessorState();
            var rdr = arch.CreateImageReader(mem, 0);
            return arch.CreateRewriter(rdr, state, binder, host);
        }

        [Test]
        public void XCore200Rw_foo()
        {
            var mem = new MemoryArea(Address.Ptr32(0x00100000), new byte[65536]);
            var rnd = new Random(4711);
            rnd.NextBytes(mem.Bytes);
            var rdr = arch.CreateImageReader(mem, 0);
            var state = arch.CreateProcessorState();
            var binder = arch.CreateFrame();
            var host = new Mock<IRewriterHost>();
            var rw = arch.CreateRewriter(rdr, state, binder, host.Object);
            var instrs = rw.ToArray();
        }

        [Test]
        public void XCore200Rw_addi()
        {
            Given_HexString("0497"); // addi	r0,r1,00000004
            AssertCode(
                "0|L--|00100000(2): 1 instructions",
                "1|L--|r0 = r1 + 0x00000004");
        }

        [Test]
        public void XCore200Rw_and()
        {
            Given_HexString("113C"); // and	r5,r8,r5
            AssertCode(
                "0|L--|00100000(2): 1 instructions",
                "1|L--|r5 = r8 & r5");
        }

        [Test]
        public void XCore200Rw_andnot()
        {
            Given_HexString("2D2F"); // andnot	r11,r1
            AssertCode(
                "0|L--|00100000(2): 1 instructions",
                "1|L--|r11 = r11 & ~r1");
        }

        [Test]
        public void XCore200Rw_bau()
        {
            Given_HexString("1127"); // bau	r1
            AssertCode(
                "0|L--|00100000(2): 1 instructions",
                "1|L--|goto r1");
        }

        [Test]
        public void XCore200Rw_bla()
        {
            Given_HexString("EF27"); // bla
            AssertCode(
                "0|L--|00100000(2): 1 instructions",
                "1|L--|@@@");
        }

        [Test]
        public void XCore200Rw_eq()
        {
            Given_HexString("E437"); // eq	r2,r5,r4
            AssertCode(
                "0|L--|00100000(2): 1 instructions",
                "1|L--|r2 = r5 == r4");
        }
    }
}
