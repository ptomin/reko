// test.c
// Generated by decompiling test.exe
// using Reko decompiler version 0.7.2.0.

#include "test.h"

// 00011000: void fn00011000(Stack word32 dwArg00, Stack word32 dwArg04, Stack word32 dwArg08, Stack word32 dwArg0C)
void fn00011000(word32 dwArg00, word32 dwArg04, word32 dwArg08, word32 dwArg0C)
{
	memset(fp + -0x0014, 0x00, 0x05);
	memcpy(calloc(0x01, 0x05), fp + ~0x1B, 0x05);
	dwLoc24->b0000 = 0x0C;
	dwLoc24->dw0001 = 0x00;
}

// 000110A0: Register Eq_42 Win32CrtStartup()
DWORD Win32CrtStartup()
{
	fn000111C4(r2);
	fn000110E8(dwLoc18, dwLoc14, dwLoc10, dwLoc0C);
	return r2;
}

// 000110E8: void fn000110E8(Stack word32 dwArg00, Stack word32 dwArg04, Stack word32 dwArg08, Stack word32 dwArg0C)
void fn000110E8(word32 dwArg00, word32 dwArg04, word32 dwArg08, word32 dwArg0C)
{
	fn000114E4();
	fn00011000(dwLoc28, dwLoc24, dwLoc20, dwLoc1C);
	fn00011278(0x00, r4);
}

// 0001116C: void fn0001116C(Register (ptr Eq_76) r2, Register (ptr (ptr word32)) r4)
void fn0001116C(Eq_76 * r2, word32 * * r4)
{
	r2->ptrFFFFFFEC = r4;
	r2->ptrFFFFFFF0 = r2->ptrFFFFFFEC;
	r2->dwFFFFFFF4 = **r2->ptrFFFFFFEC;
	word32 r8_17 = r2->dwFFFFFFF4;
	r2->dwFFFFFFE8 = r8_17;
	word32 sp_21;
	word32 r30_22;
	word32 ra_23;
	word32 r2_24;
	word32 r4_25;
	word32 r8_26;
	word32 r5_27;
	XcptFilter();
}

// 000111C4: void fn000111C4(Register Eq_42 r2)
void fn000111C4(DWORD r2)
{
	ui32 r8_7 = globals->dw13030;
	if (r8_7 != 0x00)
	{
		if (r8_7 != 0xB064)
		{
			globals->dw13034 = ~r8_7;
			return;
		}
	}
	word32 sp_20;
	word32 ra_21;
	word32 r8_22;
	word32 r9_23;
	uint32 r2_24;
	COREDLL.dll!Ordinal_2696();
	ui32 r8_32 = r2_24 >> 0x10 ^ r2_24 + 0xFFFF;
	ui32 dwLoc0C_33 = r8_32;
	if (r8_32 == 0x00)
		dwLoc0C_33 = 0xB064;
	globals->dw13030 = dwLoc0C_33;
	globals->dw13034 = ~dwLoc0C_33;
}

// 00011278: void fn00011278(Register Eq_71 r4, Stack word32 dwArg00)
void fn00011278(UINT r4, word32 dwArg00)
{
	fn000112A8(r4, 0x00, 0x00, dwLoc18, dwLoc14, dwLoc10);
}

// 000112A8: void fn000112A8(Register Eq_71 r4, Register int32 r5, Register int32 r6, Stack word32 dwArg00, Stack word32 dwArg04, Stack word32 dwArg08)
void fn000112A8(UINT r4, int32 r5, int32 r6, word32 dwArg00, word32 dwArg04, word32 dwArg08)
{
	globals->b13038 = (byte) (r6 << 0x18 >> 0x18);
	if (r5 != 0x00)
	{
		fn0001147C(&globals->dw12018, &globals->dw1201C, dwLoc18, dwLoc14);
		if (r6 != 0x00)
			;
		else
		{
			fn00011460();
			TerminateProcess((void *) 66, r4);
		}
	}
	else if (globals->t13040 == 0x00)
	{
l00011374:
		fn0001147C(&globals->dw12010, &globals->dw12014, r4, r5);
	}
	else
	{
		do
		{
			globals->t1303C = (word32) globals->t1303C - 0x04;
			Eq_183 r9_31 = globals->t1303C;
			if ((word32) (r9_31 < globals->t13040) != 0x00)
			{
				free(globals->t13040);
				globals->t1303C.u0 = 0x00;
				globals->t13040 = globals->t1303C;
				goto l00011374;
			}
		} while (*globals->t1303C == null);
		<anonymous> * r8_40 = *globals->t1303C;
		word32 sp_41;
		word32 ra_42;
		word32 r6_43;
		word32 r5_44;
		word32 r4_45;
		word32 r8_46;
		word32 r9_47;
		word32 r2_48;
		r8_40();
	}
}

// 000113D8: void fn000113D8(Register Eq_71 r4, Stack word32 dwArg00)
void fn000113D8(UINT r4, word32 dwArg00)
{
	fn000112A8(r4, 0x01, 0x00, dwLoc18, dwLoc14, dwLoc10);
}

// 00011408: void fn00011408()
void fn00011408()
{
	fn000112A8(0x00, 0x00, 0x01, dwLoc18, dwLoc14, dwLoc10);
}

// 00011434: void fn00011434()
void fn00011434()
{
	fn000112A8(0x00, 0x01, 0x01, dwLoc18, dwLoc14, dwLoc10);
}

// 00011460: void fn00011460()
void fn00011460()
{
}

// 0001147C: void fn0001147C(Register (ptr word32) r4, Register (ptr word32) r5, Stack Eq_71 dwArg00, Stack int32 dwArg04)
void fn0001147C(word32 * r4, word32 * r5, UINT dwArg00, int32 dwArg04)
{
	word32 * dwArg00_26 = r4;
	while ((word32) (dwArg00_26 < r5) != 0x00)
	{
		if (*dwArg00_26 != 0x00)
		{
			<anonymous> * r8_17 = *dwArg00_26;
			word32 sp_18;
			word32 ra_19;
			word32 r5_20;
			word32 r4_21;
			word32 r9_22;
			word32 r8_23;
			r8_17();
		}
		dwArg00_26 = dwArg00_26 + 0x01;
	}
}

// 000114E4: void fn000114E4()
void fn000114E4()
{
	fn0001147C(&globals->dw12008, &globals->dw1200C, dwLoc18, dwLoc14);
	fn0001147C(&globals->dw12000, &globals->dw12004, dwLoc18, dwLoc14);
}

// 0001152C: Register (ptr code) fn0001152C(Register (ptr code) r2, Stack word32 dwArg00)
code * fn0001152C(code * r2, word32 dwArg00)
{
	Eq_183 r8_10 = globals->t13040;
	struct Eq_310 * sp_111 = fp + -0x0038;
	Eq_10 dwLoc20_138 = 0x00;
	Eq_316 r8_19 = globals->t1303C - r8_10;
	if (r8_19 >= 0x00)
	{
		if (r8_10 != 0x00)
		{
			word32 ra_132;
			word32 r4_133;
			word32 r8_134;
			word32 r9_135;
			Eq_10 r2_136;
			word32 r5_137;
			msize();
			dwLoc20_138 = r2_136;
		}
		if ((word32) (dwLoc20_138 < (word32) r8_19 + 0x04) != 0x00)
		{
			if (r8_10 == 0x00)
			{
				malloc(0x0010);
				sp_111 = fp + ~0x3B;
			}
			else
			{
				Eq_10 dwLoc18_100 = dwLoc20_138 << 0x01;
				if ((word32) (dwLoc20_138 < 0x0201) == 0x00)
					dwLoc18_100 = (word32) dwLoc20_138 + 0x0200;
				if ((word32) (dwLoc20_138 < dwLoc18_100) != 0x00)
				{
					realloc(r8_10, dwLoc18_100);
					sp_111 = fp + ~0x3B;
				}
				if (sp_111->t0014 == 0x00)
				{
					if ((word32) (sp_111->t0018 < sp_111->t0024) != 0x00)
					{
						sp_111 = (struct Eq_310 *) ((char *) sp_111 - 0x04);
						sp_111->t0014 = realloc(sp_111->t001C, sp_111->t0024);
					}
				}
			}
			if (sp_111->t0014 == 0x00)
			{
				sp_111->ptr002C = null;
				return sp_111->ptr002C;
			}
			sp_111->t0028 = (word32) sp_111->t0014 + ((sp_111->t0028 - sp_111->t001C >> 0x02) << 0x02);
			sp_111->t001C = sp_111->t0014;
		}
		*sp_111->t0028 = sp_111->ptr0038;
		sp_111->t0028 = (word32) sp_111->t0028 + 0x04;
		globals->t1303C = sp_111->t0028;
		globals->t13040 = sp_111->t001C;
		sp_111->ptr002C = sp_111->ptr0038;
		return sp_111->ptr002C;
	}
	else
		return sp_111->ptr002C;
}

// 000116FC: void fn000116FC(Register (ptr code) r2, Stack word32 dwArg00)
void fn000116FC(code * r2, word32 dwArg00)
{
	if (fn0001152C(r2, dwLoc20) != 0x00)
		fp->dwFFFFFFF4 = 0x00;
	else
		fp->dwFFFFFFF4 = -0x01;
	fp->dwFFFFFFF0 = fp->dwFFFFFFF4;
}

