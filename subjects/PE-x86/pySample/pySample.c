// pySample.c
// Generated by decompiling pySample.dll
// using Decompiler version 0.6.0.0.

#include "pySample.h"

PyObject * fn10001000(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_21 = PyArg_ParseTuple(ptrArg08, "ii:sum", 0x00);
	if (eax_21 != null)
		return Py_BuildValue("i", 0x00);
	else
		return eax_21;
}

PyObject * fn10001050(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_19 = PyArg_ParseTuple(ptrArg08, "ii:dif", 0x00);
	if (eax_19 != null)
		return Py_BuildValue("i", 0x00);
	else
		return eax_19;
}

PyObject * fn100010A0(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_19 = PyArg_ParseTuple(ptrArg08, "ii:div", 0x00);
	if (eax_19 != null)
		return Py_BuildValue("i", 0x00);
	else
		return eax_19;
}

PyObject * fn100010F0(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_19 = PyArg_ParseTuple(ptrArg08, "ff:fdiv", 0x00);
	if (eax_19 != null)
		return Py_BuildValue("f", 0x00);
	else
		return eax_19;
}

PyObject * py_unused(PyObject * self, PyObject * args)
{
	PyObject * eax_12 = PyArg_ParseTuple(args, ":unused", 0x00);
	if (eax_12 != null)
	{
		PyObject * eax_21 = &_Py_NoneStruct;
		eax_21->ob_refcnt = eax_21->ob_refcnt + 0x01;
		return &_Py_NoneStruct;
	}
	else
		return eax_12;
}

void initpySample()
{
	Py_InitModule4("pySample", globals->methods, null, null, 1007);
	return;
}

word32 fn100011E9(word32 dwArg08)
{
	word32 eax_216;
	word32 ebp_100 = 0x00;
	if (dwArg08 == 0x00)
	{
		if (Mem0[0x10003070:word32] <= 0x00)
		{
			eax_216 = 0x00;
			return eax_216;
		}
		globals->t10003070 = globals->t10003070 - 0x01;
	}
	word32 ecx_36 = *adjust_fdiv;
	globals->dw100033A4 = ecx_36;
	byte SCZO_240 = cond(dwArg08 - 0x01);
	if (dwArg08 == 0x01)
	{
		Eq_125 edi_83 = fs->ptr0018->t0004;
		while (true)
		{
			Eq_125 dwLoc18_109 = edi_83;
			LONG * dwLoc1C_110 = &globals->t100033AC;
			Eq_125 eax_94 = InterlockedCompareExchange(&globals->t100033AC, edi_83, 0x00);
			if (eax_94 == 0x00)
				break;
			SCZO_240 = cond(eax_94 - edi_83);
			if (eax_94 == edi_83)
			{
				ebp_100 = 0x01;
				break;
			}
			Sleep(1000);
		}
		ptr32 esp_119;
		Eq_125 ebp_118;
		ui32 ebx_117;
		ui32 esi_116;
		ui32 edi_115;
		struct Eq_164 * fs_112;
		word32 dwLoc14_111;
		word32 eax_101 = globals->dw100033A8;
		byte SZO_102 = cond(eax_101);
		if (eax_101 != 0x00)
		{
			amsg_exit();
			dwLoc14_111 = 0x1F;
			esp_119 = fp + ~0x17;
		}
		else
		{
			globals->dw100033A8 = 0x01;
			word32 eax_197;
			word32 ebp_198;
			byte SCZO_201;
			word32 ebx_204;
			word32 esi_205;
			word32 edi_206;
			struct Eq_216 * fs_207;
			initterm_e();
			dwLoc14_111 = 0x100020A8;
			byte SZO_209 = cond(eax_197);
			if (eax_197 != 0x00)
			{
				eax_216 = 0x00;
				return eax_216;
			}
			initterm();
			globals->dw100033A8 = 0x02;
			dwLoc18_109 = 0x1000209C;
			dwLoc1C_110 = &globals->t10002098;
			esp_119 = fp + ~0x1B;
		}
		LONG * esp_124 = esp_119 + 0x04;
		if (ebp_118 == 0x00)
		{
			*(esp_124 - 0x04) = (int32) ebp_118;
			*(esp_124 - 0x08) = (int32) 268448684;
			InterlockedExchange(*(esp_124 - 0x08), *(esp_124 - 0x04));
		}
		byte SCZO_127 = cond(globals->t100033B8);
		if (Mem46[0x100033B8:word32] != 0x00)
		{
			struct Eq_342 * esp_143 = esp_124 - 0x04;
			esp_143->t0000 = 0x100033B8;
			Eq_125 edi_145;
			word32 eax_146 = fn10001742(ebx_117, esi_116, edi_115, out edi_145);
			byte SZO_147 = cond(eax_146);
			Eq_125 ecx_150 = esp_143->t0000;
			if (eax_146 != 0x00)
			{
				esp_143->t0000 = esp_143->t001C;
				(esp_143 - 0x04)->t0000 = edi_145;
				(esp_143 - 0x08)->t0000 = esp_143->t0014;
				globals->t100033B8();
			}
		}
		Mem141[0x10003070:word32] = Mem46[0x10003070:word32] + 0x01;
	}
	else if (dwArg08 == 0x00)
	{
		while (true)
		{
			Eq_125 eax_264 = InterlockedCompareExchange(&globals->t100033AC, 0x01, 0x00);
			byte SZO_266 = cond(eax_264);
			if (eax_264 == 0x00)
				break;
			Sleep(1000);
		}
		word32 eax_269 = globals->dw100033A8;
		byte SCZO_270 = cond(eax_269 - 0x02);
		if (eax_269 != 0x02)
			amsg_exit();
		else
		{
			word32 dwLoc14_290 = globals->dw100033B4;
			word32 eax_293;
			word32 ebp_294;
			byte SCZO_297;
			word32 esi_301;
			word32 edi_302;
			struct Eq_194 * fs_303;
			decode_pointer();
			byte SZO_306 = cond(eax_293);
			ptr32 esp_310 = fp + ~0x13;
			if (eax_293 != 0x00)
			{
				word32 dwLoc18_332 = globals->dw100033B0;
				struct Eq_269 * fs_344;
				byte Z_339;
				Eq_271 eax_334;
				byte SZO_336;
				word32 esi_342;
				Eq_271 ebx_341;
				word32 ebp_335;
				decode_pointer();
				ptr32 ecx_346 = 268448684;
				ptr32 esp_347 = fp + ~0x17;
				Eq_271 edi_348 = eax_334;
				while (true)
				{
					edi_348 = edi_348 - 0x04;
					byte SCZO_360 = cond(edi_348 - ebx_341);
					if (edi_348 < ebx_341)
						break;
					eax_334 = *edi_348;
					SZO_336 = cond(eax_334);
					Z_339 = SZO_336;
					if (eax_334 != 0x00)
						eax_334();
				}
				free(ebx_341);
				word32 eax_367;
				encoded_null();
				globals->dw100033B0 = eax_367;
				globals->dw100033B4 = eax_367;
				esp_310 = fp + ~0x1B;
			}
			LONG * esp_324 = esp_310 - 0x04;
			*esp_324 = (int32) 0x00;
			*(esp_324 - 0x04) = (int32) 268448684;
			globals->dw100033A8 = 0x00;
			InterlockedExchange(*(esp_324 - 0x04), *esp_324);
		}
	}
	eax_216 = 0x01;
	return eax_216;
}

Eq_175 fn10001388(Eq_175 ecx, Eq_175 edx, ui32 ebx, ui32 esi, ui32 edi)
{
	struct Eq_404 * ebp_11 = fn100017E8(ebx, esi, edi, dwLoc0C, 0x100021E8, 0x10);
	Eq_175 ebx_159 = ebp_11->t0008;
	(ebp_11 - 0x1C)->t0000.u0 = 0x01;
	(ebp_11 - 0x04)->t0000.u0 = 0x00;
	globals->t10003008 = edx;
	(ebp_11 - 0x04)->t0000.u0 = 0x01;
	ptr32 esp_176 = fp - 0x08;
	Eq_175 edi_13 = ecx;
	Eq_175 esi_15 = edx;
	word32 ecx_156 = 0x00;
	if (edx == 0x00 && Mem24[0x10003070:word32] == 0x00)
	{
		(ebp_11 - 0x1C)->t0000.u0 = 0x00;
		goto l1000147A;
	}
	if (edx == 0x01 || edx == 0x02)
	{
		<anonymous> * eax_166 = globals->ptr100020CC;
		byte SCZO_167 = cond(eax_166);
		if (eax_166 != null)
		{
			*(fp - 0x0C) = (union Eq_175 *) ecx;
			*(fp - 0x10) = (union Eq_175 *) edx;
			*(fp - 0x14) = (union Eq_175 *) ebx_159;
			Eq_175 eax_208;
			eax_166();
			(ebp_11 - 0x1C)->t0000 = eax_208;
		}
		if ((ebp_11 - 0x1C)->t0000 == 0x00)
		{
l1000147A:
			(ebp_11 - 0x04)->t0000 = (ebp_11 - 0x04)->t0000 & 0x00;
			(ebp_11 - 0x04)->t0000.u0 = ~0x01;
			fn10001493();
			Eq_175 eax_40 = (ebp_11 - 0x1C)->t0000;
			fn1000182D(ebp_11, 0x10, dwArg00, dwArg04, dwArg08, dwArg0C);
			return eax_40;
		}
		union Eq_175 * esp_183 = esp_176 - 0x04;
		*esp_183 = (union Eq_175 *) edi_13;
		*(esp_183 - 0x04) = (union Eq_175 *) esi_15;
		*(esp_183 - 0x08) = (union Eq_175 *) ebx_159;
		Eq_175 eax_189 = fn100011E9(dwArg04);
		(ebp_11 - 0x1C)->t0000 = eax_189;
		esp_176 = esp_183;
		if (eax_189 == 0x00)
			goto l1000147A;
	}
	union Eq_175 * esp_57 = esp_176 - 0x04;
	*esp_57 = (union Eq_175 *) edi_13;
	*(esp_57 - 0x04) = (union Eq_175 *) esi_15;
	*(esp_57 - 0x08) = (union Eq_175 *) ebx_159;
	Eq_175 eax_63 = fn100017C6(0x10, dwArg04);
	(ebp_11 - 0x1C)->t0000 = eax_63;
	ptr32 esp_143 = esp_57;
	byte SCZO_66 = cond(esi_15 - 0x01);
	if (esi_15 == 0x01 && eax_63 == 0x00)
	{
		*esp_57 = (union Eq_175 *) edi_13;
		*(esp_57 - 0x04) = (union Eq_175 *) eax_63;
		*(esp_57 - 0x08) = (union Eq_175 *) ebx_159;
		fn100017C6(0x10, dwArg04);
		*esp_57 = (union Eq_175 *) edi_13;
		*(esp_57 - 0x04) = 0x00;
		*(esp_57 - 0x08) = (union Eq_175 *) ebx_159;
		fn100011E9(dwArg04);
		<anonymous> * eax_144 = globals->ptr100020CC;
		esp_143 = esp_57;
		byte SZO_145 = cond(eax_144);
		if (eax_144 != null)
		{
			*esp_57 = (union Eq_175 *) edi_13;
			*(esp_57 - 0x04) = 0x00;
			*(esp_57 - 0x08) = (union Eq_175 *) ebx_159;
			eax_144();
		}
	}
	if (esi_15 == 0x00 || esi_15 == 0x03)
	{
		union Eq_175 * esp_81 = esp_143 - 0x04;
		*esp_81 = (union Eq_175 *) edi_13;
		*(esp_81 - 0x04) = (union Eq_175 *) esi_15;
		*(esp_81 - 0x08) = (union Eq_175 *) ebx_159;
		Eq_175 eax_87 = fn100011E9(dwArg04);
		if (eax_87 == 0x00)
			(ebp_11 - 0x1C)->t0000 = (ebp_11 - 0x1C)->t0000 & eax_87;
		byte SCZO_94 = cond((ebp_11 - 0x1C)->t0000);
		if ((ebp_11 - 0x1C)->t0000 != 0x00)
		{
			<anonymous> * eax_96 = globals->ptr100020CC;
			byte SZO_97 = cond(eax_96);
			if (eax_96 != null)
			{
				*esp_81 = (union Eq_175 *) edi_13;
				*(esp_81 - 0x04) = (union Eq_175 *) esi_15;
				*(esp_81 - 0x08) = (union Eq_175 *) ebx_159;
				Eq_175 eax_113;
				eax_96();
				(ebp_11 - 0x1C)->t0000 = eax_113;
			}
		}
	}
	goto l1000147A;
}

void fn10001493()
{
	globals->t10003008.u0 = ~0x00;
	return;
}

BOOL DllMain(HANDLE hModule, Eq_175 dwReason, Eq_175 lpReserved)
{
	if (dwReason == 0x01)
		fn10001864();
	return fn10001388(lpReserved, dwReason, ebx, esi, edi);
}

word32 fn100016D0(word32 dwArg04)
{
	if (dwArg04->w0000 == 23117)
	{
		struct Eq_764 * eax_22 = dwArg04 + dwArg04->dw003C / 0x0040;
		if (eax_22->dw0000 == 0x4550)
			return (word32) (eax_22->w0018 == 0x010B);
	}
	return 0x00;
}

Eq_781 * fn10001700(word32 dwArg04, word32 dwArg08)
{
	struct Eq_784 * ecx_7 = dwArg04 + dwArg04->dw003C / 0x0040;
	uint32 esi_15 = (word32) ecx_7->w0006;
	uint32 edx_16 = 0x00;
	struct Eq_781 * eax_23 = (ecx_7 + ((word32) ecx_7->w0014 + 0x18) / 22)->w0006 + 0x03;
	if (true)
		do
		{
			uint32 ecx_50 = eax_23->dw0000;
			if (dwArg08 >= ecx_50 && dwArg08 < eax_23->dw0008 + ecx_50)
				return eax_23;
			edx_16 = edx_16 + 0x01;
			eax_23 = eax_23 + 0x01;
		} while (edx_16 < esi_15);
	eax_23 = null;
	return eax_23;
}

ui32 fn10001742(ui32 ebx, ui32 esi, ui32 edi, ptr32 & ediOut)
{
	ui32 eax_32;
	struct Eq_404 * ebp_11 = fn100017E8(ebx, esi, edi, dwLoc0C, 0x10002230, 0x08);
	*(ebp_11 - 0x04) = (union Eq_175 *) (*(ebp_11 - 0x04) & 0x00);
	*(fp - 0x0C) = 0x10000000;
	if (fn100016D0(dwArg00) != 0x00)
	{
		*(fp - 0x0C) = (union Eq_845 *) (ebp_11->t0008 - 0x10000000);
		*(fp - 0x10) = 0x10000000;
		struct Eq_881 * eax_55 = fn10001700(dwArg00, dwArg04);
		if (eax_55 != null)
		{
			eax_32 = ~(eax_55->dw0024 >> 0x1F) & 0x01;
			(ebp_11 - 0x04)->t0000.u0 = ~0x01;
l100017A8:
			*ediOut = fn1000182D(ebp_11, 0x08, dwArg00, dwArg04, dwArg08, dwArg0C);
			return eax_32;
		}
	}
	*(ebp_11 - 0x04) = ~0x01;
	eax_32 = 0x00;
	goto l100017A8;
}

word32 fn100017C6(word32 dwArg00, word32 dwArg08)
{
	if (dwArg08 == 0x01 && globals->ptr100020CC == null)
		DisableThreadLibraryCalls(dwArg00);
	return 0x01;
}

ptr32 fn100017E8(ui32 ebx, ui32 esi, ui32 edi, word32 dwArg00, word32 dwArg04, word32 dwArg08)
{
	ui32 * esp_14 = fp - 0x08 - dwArg08;
	*(esp_14 - 0x04) = ebx;
	*(esp_14 - 0x08) = esi;
	*(esp_14 - 0x0C) = edi;
	*(esp_14 - 0x10) = globals->dw10003000 ^ fp + 0x08;
	*(esp_14 - 0x14) = dwArg00;
	fs->ptr0000 = fp - 0x08;
	return fp + 0x08;
}

word32 fn1000182D(Eq_404 * ebp, word32 dwArg00, word32 dwArg04, word32 dwArg08, word32 dwArg0C, word32 dwArg10)
{
	fs->t0000 = *(ebp - 0x10);
	ebp->t0000 = dwArg00;
	return dwArg08;
}

void fn10001864()
{
	ui32 eax_9 = globals->dw10003000;
	if (eax_9 != 0xBB40E64E && (eax_9 & 0xFFFF0000) != 0x00)
		globals->dw10003004 = ~eax_9;
	else
	{
		GetSystemTimeAsFileTime(fp - 0x0C);
		ui32 esi_59 = dwLoc08 & 0x00 ^ dwLoc0C & 0x00 ^ GetCurrentProcessId() ^ GetCurrentThreadId() ^ GetTickCount();
		QueryPerformanceCounter(fp - 0x14);
		ui32 esi_69 = esi_59 ^ (dwLoc10 ^ dwLoc14);
		if (esi_69 == 0xBB40E64E)
			esi_69 = ~0x44BF19B0;
		else if ((esi_69 & 0xFFFF0000) == 0x00)
			esi_69 = esi_69 | esi_69 << 0x10;
		globals->dw10003000 = esi_69;
		globals->dw10003004 = ~esi_69;
	}
	return;
}

