// STRLEN.c
// Generated by decompiling STRLEN
// using Decompiler version 0.6.0.0.

#include "STRLEN.h"

void fn00001000(int32 d0, byte * a0)
{
	struct Eq_4 * a6_9 = *(struct Eq_4 **) 0x04;
	int32 d2_236 = d0;
	byte * a2_248 = a0;
	struct Eq_11 * a4_7 = (struct Eq_11 *) 37822;
	if (a6_9->w0014 - 0x24 < 0x00)
	{
		word32 * a0_503 = &globals->dw13C8;
		word32 d0_506 = 0x0C;
		do
		{
			*a0_503 = 0x00;
			a0_503 = a0_503 + 0x01;
			d0_506 = d0_506 - 0x01;
		} while (d0_506 != 0x00);
	}
	a4_7->ptrFFFF800A = fp;
	a4_7->ptrFFFF800E = a6_9;
	struct Eq_27 * d0_20 = FindTask(0x00);
	struct Eq_33 * d0_113 = OpenLibrary(0x12BC, 0x00);
	if (d0_113 != null)
	{
		int32 d4_458;
		a4_7->ptrFFFF8012 = d0_113;
		if (d0_20->ptr00AC == null)
		{
			d4_458 = 0x02;
			d2_236 = 0x08;
		}
		else
		{
			byte * a0_461 = a0;
			d4_458 = 0x03;
			do
			{
				if (*a0_515 - 0x20 == 0x00)
					d4_458 = DPB(d4_458, (word16) d4_458 + 0x01, 0);
				a0_461 = a0_515 + 0x01;
				a0_515 = a0_461;
			} while (*a0_515 != 0x00);
		}
		int32 d0_106 = d4_458 << 0x02;
		int32 d0_108 = d0_106 + d2_236;
		int32 d1_112 = 0x00010001;
		d0_113 = AllocMem(d0_108 + 0x11, 0x00010001);
		if (d0_113 != null)
		{
			struct Eq_68 * dwLoc14_160;
			word32 a0_165;
			d0_113->dw0000 = d0_108 + 0x11;
			int32 d4_124 = d4_458 - 0x01;
			d0_113->dw000C = d4_124;
			d0_113->ptr0008 = d0_113->dw000C + 0x01 + d0_106 / 0x0010;
			Mem132[0x00:word32] = 0x00;
			struct Eq_68 * d0_133 = d0_20->ptr00AC;
			d0_133->dw0000 = d0_108 + 0x11;
			d0_133->dw000C = d4_124 - 0x01;
			d0_133->ptr0008 = (byte *) (&d0_133->ptr0010 + d0_106 / 0x0028);
			Mem151[0x00:word32] = 0x00;
			struct Eq_68 * d0_152 = d0_20->ptr00AC;
			if (d0_152 == null)
			{
				fn00001214(d0_20);
				a4_7->ptrFFFF8016 = d0_152;
				a4_7->ptrFFFF801A = d0_152;
				Mem402[0x00:word32] = 0x00;
				dwLoc14_160 = d0_152;
				int32 d0_405 = d0_152->dw0024;
				if (d0_405 != 0x00)
					Enable();
				Supervisor(d0_133);
				d0_133->dw0004 = d0_405;
				if (d0_405 == 0x00)
				{
					fn0000127C(0x0014);
					return;
				}
				a4_7->dwFFFF801E = d0_405;
				a4_7->dwFFFF8022 = d0_405;
				a4_7->dwFFFF8026 = d0_405;
				d0_20->dw009C = d0_405;
				d0_20->dw00A0 = d0_405;
				word32 d0_430 = ((word32[]) 0x08)[d0_405];
				if (d0_430 != 0x00)
					d0_20->dw00A4 = d0_430;
l000011F8:
				a0_165 = d0_20->dw003A;
				goto l00001202;
			}
			ui32 d0_203 = ((ui32[]) 0x0010)[d0_152];
			Eq_200 (* a0_210)[] = (d0_203 << 0x02) + 0x01;
			int32 d0_211 = (int32) null[d0_203].b0000;
			Mem212[a0_210 + d0_211:byte] = 0x00;
			d0_133->ptr0010 = a0_210;
			ui32 d0_218 = ((ui32[]) 0x0010)[d0_211];
			byte * a1_221 = d0_133->ptr0008;
			Eq_200 (* a0_226)[] = (d0_218 << 0x02) + 0x01;
			int32 d0_227 = (int32) null[d0_218].b0000;
			Mem228[a0_226 + d0_227:byte] = 0x00;
			d0_133->ptr0010 = a0_226;
			byte ** a6_231 = &d0_133->ptr0010;
			int32 d3_232 = 0x01;
			struct Eq_237 * a0_234 = a0 + d2_236;
l000010DA:
			a0_234 = a0_234 - 0x01;
			if (a0_234->b0000 - 0x20 > 0x00)
			{
				d2_236 = d2_236 - 0x01;
				if (d2_236 != ~0x00)
					goto l000010DA;
			}
			a0_234[0x01] = (struct Eq_237) 0x00;
			do
			{
l000010E6:
				byte v37_257 = *a2_248;
				a2_248 = a2_248 + 0x01;
				d1_112 = DPB(d1_112, v37_257, 0);
				if (v37_257 == 0x00)
					goto l00001148;
			} while (v37_257 == 0x20 || v37_257 == 0x09);
			if (d3_232 - d0_133->dw000C != 0x00)
			{
				*a6_231 = (byte **) a1_221;
				a6_231 = a6_231;
				d3_232 = DPB(d3_232, (word16) d3_232 + 0x01, 0);
				if (v37_257 != 0x22)
				{
					*a1_221 = v37_257;
					a1_221 = a1_221 + 0x01;
					while (true)
					{
						byte v45_339 = *a2_248;
						a2_248 = a2_248 + 0x01;
						d1_112 = DPB(d1_112, v45_339, 0);
						if (v45_339 == 0x00)
							break;
						if (v45_339 == 0x20)
							goto l00001116;
						*a1_221 = v45_339;
						a1_221 = a1_221 + 0x01;
					}
				}
				else
					while (true)
					{
						byte v70_355 = *a2_248;
						a2_248 = a2_248 + 0x01;
						d1_112 = DPB(d1_112, v70_355, 0);
						if (v70_355 == 0x00)
							break;
						if (v70_355 == 0x22)
						{
l00001116:
							*a1_221 = 0x00;
							a1_221 = a1_221 + 0x01;
							goto l000010E6;
						}
						if (v70_355 == 0x2A)
						{
							byte v73_374 = *a2_248;
							a2_248 = a2_248 + 0x01;
							d1_112 = DPB(d1_112, v73_374, 0);
							if ((v73_374 & 223) == 0x4E)
								d1_112 = 0x0A;
							else if ((v73_374 & 223) == 0x45)
								d1_112 = 0x001B;
						}
						*a1_221 = (byte) d1_112;
						a1_221 = a1_221 + 0x01;
					}
			}
l00001148:
			*a1_221 = 0x00;
			*a6_231 = (byte **) null;
			execPrivate4();
			a4_7->dwFFFF801E = d0_227;
			execPrivate5();
			a4_7->dwFFFF8022 = d0_227;
			dwLoc14_160 = &d0_133->ptr0010;
			dwLoc18 = d3_232;
			if (a4_7->ptrFFFF800E->w0014 - 0x24 >= 0x00)
			{
				int32 v87_299 = d0_20->dw00E0;
				a4_7->dwFFFF8026 = v87_299;
				if (v87_299 != 0x00)
				{
l0000117E:
					if (d0_20->b0008 - 0x0D == 0x00)
					{
						word32 * a0_289 = d0_20->ptr00B0;
						a0_165 = a0_289 + 0x01 - *a0_289;
l00001202:
						a4_7->dwFFFF8032 = a0_165;
						a4_7->ptrFFFF8036 = fp - 0x18;
						fn00001354(dwLoc18, dwLoc14_160);
						fn0000127C(0x00);
						return;
					}
					goto l000011F8;
				}
			}
			a4_7->dwFFFF8026 = d0_227;
			goto l0000117E;
		}
		CloseLibrary(a4_7->ptrFFFF8012);
		Alert(0x00010000);
	}
	else
		Alert(0x00038007);
	if (d0_20->ptr00AC == null)
	{
		fn00001214(d0_20);
		fn0000126C(d0_113);
	}
	return;
}

void fn00001214(Eq_27 * a3)
{
	WaitPort(a3 + 0x005C);
	GetMsg(a3 + 0x005C);
	return;
}

void fn0000126C(Eq_33 * a2)
{
	Forbid();
	ReplyMsg(a2);
	return;
}

void fn00001278(word32 dwArg04)
{
	fn0000127C(dwArg04);
	return;
}

void fn0000127C(int32 d2)
{
	struct Eq_519 * a4_1 = (struct Eq_519 *) 37822;
	struct Eq_33 ** a7_4 = a4_1->ptrFFFF800A;
	struct Eq_33 * v8_9 = *(a7_4 - 0x04);
	struct Eq_33 * v6_6 = *(a7_4 - 0x08);
	if (v8_9->dw0004 != 0x00)
		execPrivate1();
	CloseLibrary(a4_1->ptrFFFF8012);
	if (v6_6 != null)
		fn0000126C(v6_6);
	FreeMem(v8_9, v8_9->dw0000);
	return;
}

void fn000012D0(word32 dwArg04)
{
	struct Eq_563 * a3_12 = (struct Eq_563 *) 0x1404;
	byte CVZN_14 = cond(0x1404);
	if (0x1404 != 0x00)
	{
		int32 d2_40 = 0x01;
		byte ZN_41 = cond(a3_12[0x04]);
		bool C_43 = false;
		bool V_44 = false;
		if (a3_12[0x04] != 0x00)
			do
			{
				d2_40 = d2_40 + 0x01;
				ZN_41 = cond(a3_12[d2_40 * 0x04]);
				C_43 = false;
				V_44 = false;
			} while (a3_12[d2_40 * 0x04] != 0x00);
		int32 d2_50 = d2_40 - 0x01;
		byte CVZNX_51 = cond(d2_50);
		if (d2_50 != 0x00)
			do
			{
				int32 d0_56 = d2_50 << 0x02;
				<anonymous> * a2_58 = a3_12[d0_56];
				word32 d2_63;
				a2_58();
				d2_50 = d2_63 - 0x01;
			} while (d2_63 != 0x01);
	}
	fn00001278(dwArg04);
	return;
}

void fn0000131C(word32 dwArg04)
{
	byte ZN_10 = cond(*(word32 *) 5112);
	if (*(word32 *) 5112 == 0x00)
	{
		struct Eq_632 * a3_29 = *(struct Eq_632 **) 0x140C;
		*(int32 *) 5112 = 0x01;
		byte CVZN_34 = cond(a3_29);
		a3_50 = a3_29;
		if (a3_29 != null)
			do
			{
				struct Eq_632 * a3_50;
				<anonymous> * a2_51 = a3_50->ptr0004;
				struct Eq_632 ** a3_53;
				a2_51();
				a3_50 = (struct Eq_632 *) *a3_53;
			} while (a3_50 != null);
		fn000012D0(dwArg04);
	}
	return;
}

void fn00001354(int32 dwArg04, Eq_68 * dwArg08)
{
	<anonymous> ** a3_46 = (<anonymous> **) 0x1400;
	byte CVZN_11 = cond(5116);
	if (5116 != 0x00)
	{
		byte ZN_42 = cond(*a3_46);
		if (*a3_46 != null)
			do
			{
				<anonymous> * v11_47 = *a3_46;
				v11_47();
			} while (*a3_46 != null);
	}
	fn0000131C(fn00001390());
	return;
}

word32 fn00001390()
{
	return fn000013AC(0x13A4);
}

int32 fn000013AC(ptr32 dwArg04)
{
	byte * a1_12 = dwArg04;
	int32 d0_18 = 0x00;
	while (true)
	{
		a1_12 = a1_12 + 0x01;
		if (*a1_12 == 0x00)
			break;
		d0_18 = d0_18 + 0x01;
	}
	return d0_18;
}

