// pySample.c
// Generated by decompiling pySample.dll
// using Reko decompiler version 0.7.2.0.

#include "pySample.h"

// 10001000: Register (ptr Eq_2) fn10001000(Stack (ptr Eq_3) ptrArg04, Stack (ptr Eq_4) ptrArg08)
PyObject * fn10001000(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_20 = PyArg_ParseTuple(ptrArg08, "ii:sum", fp - 0x04, fp - 0x08);
	if (eax_20 != null)
		return Py_BuildValue("i", dwLoc04 + dwLoc08);
	return eax_20;
}

// 10001050: Register (ptr Eq_2) fn10001050(Stack (ptr Eq_3) ptrArg04, Stack (ptr Eq_4) ptrArg08)
PyObject * fn10001050(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_20 = PyArg_ParseTuple(ptrArg08, "ii:dif", fp - 0x08, fp - 0x04);
	if (eax_20 != null)
		return Py_BuildValue("i", dwLoc08 - dwLoc04);
	return eax_20;
}

// 100010A0: Register (ptr Eq_2) fn100010A0(Stack (ptr Eq_3) ptrArg04, Stack (ptr Eq_4) ptrArg08)
PyObject * fn100010A0(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_20 = PyArg_ParseTuple(ptrArg08, "ii:div", fp - 0x08, fp - 0x04);
	if (eax_20 != null)
		return Py_BuildValue("i", (int32) ((int64) dwLoc08 / dwLoc04));
	return eax_20;
}

// 100010F0: Register (ptr Eq_2) fn100010F0(Stack (ptr Eq_3) ptrArg04, Stack (ptr Eq_4) ptrArg08)
PyObject * fn100010F0(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_20 = PyArg_ParseTuple(ptrArg08, "ff:fdiv", fp - 0x08, fp - 0x04);
	if (eax_20 != null)
		return Py_BuildValue("f", (real64) rLoc08 / rLoc04);
	return eax_20;
}

// 10001140: Register (ptr Eq_99) py_unused(Stack (ptr Eq_100) self, Stack (ptr Eq_101) args)
PyObject * py_unused(PyObject * self, PyObject * args)
{
	PyObject * eax_15 = PyArg_ParseTuple(args, ":unused");
	if (eax_15 == null)
		return eax_15;
	PyObject * eax_24 = &_Py_NoneStruct;
	eax_24->ob_refcnt = eax_24->ob_refcnt + 0x01;
	return &_Py_NoneStruct;
}

// 10001170: void initpySample()
void initpySample()
{
	Py_InitModule4("pySample", globals->methods, null, null, 1007);
}

// 100011E9: Register word32 fn100011E9(Stack uint32 dwArg08)
word32 fn100011E9(uint32 dwArg08)
{
	word32 eax_123;
	Eq_139 ebp_203 = 0x00;
	if (dwArg08 == 0x00)
	{
		if (globals->dw10003070 <= 0x00)
		{
			eax_123 = 0x00;
			return eax_123;
		}
		globals->dw10003070 = globals->dw10003070 - 0x01;
	}
	globals->dw100033A4 = *adjust_fdiv;
	if (dwArg08 == 0x01)
	{
		Eq_139 edi_82 = fs->ptr0018->t0004;
		while (true)
		{
			Eq_139 eax_93 = InterlockedCompareExchange(&globals->t100033AC, edi_82, 0x00);
			if (eax_93 == 0x00)
				break;
			if (eax_93 == edi_82)
			{
				ebp_203 = 0x01;
				break;
			}
			Sleep(1000);
		}
		if (globals->dw100033A8 != 0x00)
			_amsg_exit(0x1F);
		globals->dw100033A8 = 0x01;
		if (_initterm_e(&globals->t100020A0, &globals->t100020A8) != 0x00)
		{
			eax_123 = 0x00;
			return eax_123;
		}
		_initterm(&globals->t10002098, &globals->t1000209C);
		globals->dw100033A8 = 0x02;
		if (ebp_203 == 0x00)
			InterlockedExchange(&globals->t100033AC, ebp_203);
		if (globals->ptr100033B8 != null)
		{
			word32 edi_161;
			word32 eax_162 = fn10001742(InterlockedCompareExchange, 268448684, 0x02, out edi_161);
			if (eax_162 != 0x00)
			{
				*(fp - 0x14) = fp->dw000C;
				*(fp - 0x18) = edi_161;
				*(fp - 0x1C) = fp->dw0004;
				word32 esp_176;
				word32 eax_177;
				word32 ebp_178;
				byte SZO_179;
				byte C_180;
				byte SCZO_181;
				byte Z_182;
				word32 ecx_183;
				word32 ebx_184;
				word32 esi_185;
				word32 edi_186;
				struct Eq_391 * fs_187;
				globals->ptr100033B8();
			}
		}
		globals->dw10003070 = globals->dw10003070 + 0x01;
	}
	else if (dwArg08 == 0x00)
	{
		while (InterlockedCompareExchange(&globals->t100033AC, 0x01, 0x00) != 0x00)
			Sleep(1000);
		if (globals->dw100033A8 != 0x02)
			_amsg_exit(0x1F);
		word32 * eax_232 = _decode_pointer(globals->ptr100033B4);
		word32 * ebx_233 = eax_232;
		ptr32 esp_238 = fp - 0x10;
		if (eax_232 != null)
		{
			ptr32 esp_263 = fp - 0x10;
			word32 * edi_264 = _decode_pointer(globals->ptr100033B0);
			while (true)
			{
				edi_264 = edi_264 - 0x04;
				if (edi_264 < ebx_233)
					break;
				<anonymous> * eax_285 = *edi_264;
				if (eax_285 != null)
				{
					word32 eax_290;
					word32 ebp_291;
					byte SZO_292;
					byte C_293;
					byte SCZO_294;
					byte Z_295;
					word32 ecx_296;
					word32 esi_298;
					struct Eq_331 * fs_300;
					eax_285();
				}
			}
			word32 ** esp_278 = esp_263 - 0x04;
			*esp_278 = ebx_233;
			free(*esp_278);
			void * eax_282 = _encoded_null();
			globals->ptr100033B0 = eax_282;
			globals->ptr100033B4 = eax_282;
			esp_238 = (char *) esp_278 + 0x04;
		}
		LONG * esp_251 = esp_238 - 0x04;
		*esp_251 = (int32) 0x00;
		*(esp_251 - 0x04) = 268448684;
		globals->dw100033A8 = 0x00;
		InterlockedExchange(*(esp_251 - 0x04), *esp_251);
	}
	eax_123 = 0x01;
	return eax_123;
}

// 10001388: Register word32 fn10001388(Register Eq_395 ecx, Register Eq_197 edx, Register (ptr Eq_172) ebx, Register ptr32 esi, Register word32 edi)
word32 fn10001388(LPVOID ecx, DWORD edx,  * ebx, ptr32 esi, word32 edi)
{
	struct Eq_400 * ebp_10 = fn100017E8(ebx, esi, edi, dwLoc0C, 0x100021E8, 0x10);
	ui32 ebx_158 = ebp_10->dw0008;
	*(ebp_10 - 0x1C) = 0x01;
	*(ebp_10 - 0x04) = 0x00;
	globals->t10003008 = edx;
	*(ebp_10 - 0x04) = 0x01;
	ptr32 esp_175 = fp - 0x08;
	Eq_395 edi_12 = ecx;
	Eq_197 esi_14 = edx;
	if (edx == 0x00 && globals->dw10003070 == 0x00)
	{
		*(ebp_10 - 0x1C) = 0x00;
		goto l1000147A;
	}
	if (edx == 0x01 || edx == 0x02)
	{
		<anonymous> * eax_165 = globals->ptr100020CC;
		if (eax_165 != null)
		{
			*(fp - 0x0C) = (LPVOID *) ecx;
			*(fp - 0x10) = (uint32) edx;
			*(fp - 0x14) = ebx_158;
			word32 ecx_202;
			word32 edx_204;
			word32 eax_207;
			byte SZO_208;
			byte C_209;
			byte SCZO_210;
			byte Z_211;
			eax_165();
			*(ebp_10 - 0x1C) = eax_207;
		}
		if (*(ebp_10 - 0x1C) != 0x00)
		{
			LPVOID * esp_182 = esp_175 - 0x04;
			*esp_182 = (LPVOID *) edi_12;
			*(esp_182 - 0x04) = (uint32) esi_14;
			*(esp_182 - 0x08) = ebx_158;
			ui32 eax_188 = fn100011E9(dwArg04);
			*(ebp_10 - 0x1C) = eax_188;
			esp_175 = (char *) esp_182 + 0x04;
			if (eax_188 != 0x00)
				goto l100013FA;
		}
l1000147A:
		*(ebp_10 - 0x04) = *(ebp_10 - 0x04) & 0x00;
		*(ebp_10 - 0x04) = ~0x01;
		fn10001493();
		word32 eax_39 = *(ebp_10 - 0x1C);
		fn1000182D(ebp_10, 0x10, dwArg00, dwArg04, dwArg08, dwArg0C);
		return eax_39;
	}
	else
	{
l100013FA:
		LPVOID * esp_56 = esp_175 - 0x04;
		*esp_56 = (LPVOID *) edi_12;
		*(esp_56 - 0x04) = (uint32) esi_14;
		*(esp_56 - 0x08) = ebx_158;
		word32 eax_62 = fn100017C6(dwArg00, dwArg04);
		*(ebp_10 - 0x1C) = eax_62;
		ptr32 esp_142 = (char *) esp_56 + 0x04;
		if (esi_14 == 0x01 && eax_62 == 0x00)
		{
			*esp_56 = (LPVOID *) edi_12;
			*(esp_56 - 0x04) = eax_62;
			*(esp_56 - 0x08) = ebx_158;
			fn100017C6(dwArg00, dwArg04);
			*esp_56 = (LPVOID *) edi_12;
			*(esp_56 - 0x04) = 0x00;
			*(esp_56 - 0x08) = ebx_158;
			fn100011E9(dwArg04);
			esp_142 = (char *) esp_56 + 0x04;
			<anonymous> * eax_143 = globals->ptr100020CC;
			if (eax_143 != null)
			{
				*esp_56 = (LPVOID *) edi_12;
				*(esp_56 - 0x04) = 0x00;
				*(esp_56 - 0x08) = ebx_158;
				word32 ecx_155;
				word32 edx_157;
				word32 eax_160;
				byte SZO_161;
				byte C_162;
				byte SCZO_163;
				byte Z_164;
				eax_143();
			}
		}
		if (esi_14 == 0x00 || esi_14 == 0x03)
		{
			LPVOID * esp_80 = esp_142 - 0x04;
			*esp_80 = (LPVOID *) edi_12;
			*(esp_80 - 0x04) = (uint32) esi_14;
			*(esp_80 - 0x08) = ebx_158;
			ui32 eax_86 = fn100011E9(dwArg04);
			if (eax_86 == 0x00)
				*(ebp_10 - 0x1C) = *(ebp_10 - 0x1C) & eax_86;
			if (*(ebp_10 - 0x1C) != 0x00)
			{
				<anonymous> * eax_95 = globals->ptr100020CC;
				if (eax_95 != null)
				{
					*esp_80 = (LPVOID *) edi_12;
					*(esp_80 - 0x04) = (uint32) esi_14;
					*(esp_80 - 0x08) = ebx_158;
					word32 esp_105;
					word32 edi_106;
					word32 ecx_107;
					word32 esi_108;
					word32 edx_109;
					word32 ebx_110;
					word32 eax_112;
					byte SZO_113;
					byte C_114;
					byte SCZO_115;
					byte Z_116;
					eax_95();
					*(ebp_10 - 0x1C) = eax_112;
				}
			}
		}
		goto l1000147A;
	}
}

// 10001493: void fn10001493()
void fn10001493()
{
	globals->t10003008 = ~0x00;
}

// 1000149E: Register Eq_741 DllMain(Stack Eq_742 hModule, Stack Eq_197 dwReason, Stack Eq_395 lpReserved)
BOOL DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == 0x01)
		fn10001864();
	return fn10001388(lpReserved, dwReason, ebx, esi, edi);
}

// 100015CF: Register word32 fn100015CF(Register (ptr Eq_172) ebx, Register ptr32 esi, Register word32 edi)
word32 fn100015CF( * ebx, ptr32 esi, word32 edi)
{
	Eq_760 eax_119;
	struct Eq_400 * ebp_10 = fn100017E8(ebx, esi, edi, dwLoc0C, 0x10002210, 0x14);
	*(fp - 0x0C) = (void **) globals->ptr100033B4;
	word32 * eax_16 = _decode_pointer(*(fp - 0x0C));
	*(ebp_10 - 0x1C) = eax_16;
	if (eax_16 == (word32 *) ~0x00)
	{
		*(fp - 0x0C) = ebp_10->dw0008;
		eax_119 = _onexit(*(fp - 0x0C));
	}
	else
	{
		*(fp - 0x0C) = 0x08;
		void ** esp_47;
		word32 esi_48;
		word32 eax_49;
		word32 ecx_50;
		struct Eq_799 * ebp_51;
		byte SCZO_52;
		byte Z_53;
		byte SZO_54;
		byte C_55;
		word32 ebx_56;
		word32 edi_57;
		lock();
		*(ebp_51 - 0x04) = *(ebp_51 - 0x04) & 0x00;
		*esp_47 = (void **) globals->ptr100033B4;
		*(ebp_51 - 0x1C) = _decode_pointer(*esp_47);
		*(esp_47 - 0x04) = (void **) globals->ptr100033B0;
		*(ebp_51 - 0x20) = _decode_pointer(*(esp_47 - 0x04));
		*(esp_47 - 0x08) = ebp_51 - 0x20;
		*(esp_47 - 0x0C) = ebp_51 - 0x1C;
		*(esp_47 - 0x10) = ebp_51->dw0008;
		Eq_760 eax_83 = __dllonexit(*(esp_47 - 0x10), *(esp_47 - 0x0C), *(esp_47 - 0x08));
		*(ebp_51 - 0x24) = (_onexit_t *) eax_83;
		*(esp_47 - 0x14) = *(ebp_51 - 0x1C);
		ptr32 esp_89;
		word32 esi_90;
		void * eax_91;
		word32 ecx_92;
		ptr32 ebp_93;
		byte SCZO_94;
		byte Z_95;
		byte SZO_96;
		byte C_97;
		word32 ebx_98;
		word32 edi_99;
		encode_pointer();
		globals->ptr100033B4 = eax_91;
		*(esp_89 - 0x04) = *(ebp_93 - 0x20);
		word32 esp_104;
		word32 esi_105;
		void * eax_106;
		word32 ecx_107;
		byte SCZO_109;
		byte Z_110;
		byte SZO_111;
		byte C_112;
		word32 ebx_113;
		word32 edi_114;
		encode_pointer();
		globals->ptr100033B0 = eax_106;
		*(ebp_10 - 0x04) = ~0x01;
		fn10001665();
		eax_119 = (Eq_760) *(ebp_10 - 0x24);
	}
	fn1000182D(ebp_10, 0x14, dwArg00, dwArg04, dwArg08, dwArg0C);
	return eax_119;
}

// 10001665: void fn10001665()
void fn10001665()
{
	word32 esp_4;
	word32 ecx_5;
	unlock();
}

// 1000166E: void fn1000166E(Register (ptr Eq_172) ebx, Register ptr32 esi, Register word32 edi, Stack word32 dwArg04)
void fn1000166E( * ebx, ptr32 esi, word32 edi, word32 dwArg04)
{
	fn100015CF(ebx, esi, edi);
}

// 10001680: void fn10001680()
void fn10001680()
{
	word32 * esi_12 = &globals->dw100021D8;
	if (false)
	{
		do
		{
			<anonymous> * eax_30 = *esi_12;
			if (eax_30 != null)
			{
				word32 esp_43;
				word32 edi_45;
				word32 eax_46;
				byte SCZO_47;
				byte C_48;
				byte SZO_49;
				byte Z_50;
				eax_30();
			}
			esi_12 = esi_12 + 0x01;
		} while (esi_12 < &globals->dw100021D8);
	}
}

// 100016D0: Register word32 fn100016D0(Stack Eq_488 dwArg04)
word32 fn100016D0(HMODULE dwArg04)
{
	if (dwArg04->unused != 23117)
		return 0x00;
	struct Eq_1024 * eax_21 = dwArg04 + dwArg04->dw003C / 0x0040;
	if (eax_21->dw0000 != 0x4550)
		return 0x00;
	return (word32) (eax_21->w0018 == 0x010B);
}

// 10001700: Register (ptr Eq_1041) fn10001700(Stack Eq_488 dwArg04, Stack uint32 dwArg08)
Eq_1041 * fn10001700(HMODULE dwArg04, uint32 dwArg08)
{
	struct Eq_1044 * ecx_6 = dwArg04 + dwArg04->dw003C / 0x0040;
	uint32 esi_14 = (word32) ecx_6->w0006;
	uint32 edx_15 = 0x00;
	struct Eq_1041 * eax_22 = &(ecx_6 + ((word32) ecx_6->w0014 + 0x18) / 22)->w0006 + 0x03;
	if (true)
	{
		do
		{
			uint32 ecx_49 = eax_22->dw0000;
			if (dwArg08 >= ecx_49 && dwArg08 < eax_22->dw0008 + ecx_49)
				return eax_22;
			edx_15 = edx_15 + 0x01;
			eax_22 = eax_22 + 0x01;
		} while (edx_15 < esi_14);
	}
	eax_22 = null;
	return eax_22;
}

// 10001742: Register ui32 fn10001742(Register (ptr Eq_172) ebx, Register ptr32 esi, Register word32 edi, Register out ptr32 ediOut)
ui32 fn10001742( * ebx, ptr32 esi, word32 edi, ptr32 & ediOut)
{
	ui32 eax_31;
	struct Eq_400 * ebp_10 = fn100017E8(ebx, esi, edi, dwLoc0C, 0x10002230, 0x08);
	*(ebp_10 - 0x04) = *(ebp_10 - 0x04) & 0x00;
	*(fp - 0x0C) = 0x10000000;
	if (fn100016D0(dwArg00) != 0x00)
	{
		*(fp - 0x0C) = ebp_10->dw0008 - 0x10000000;
		*(fp - 0x10) = 0x10000000;
		struct Eq_1139 * eax_54 = fn10001700(dwArg00, dwArg04);
		if (eax_54 != null)
		{
			eax_31 = ~(eax_54->dw0024 >> 0x1F) & 0x01;
			*(ebp_10 - 0x04) = ~0x01;
			goto l100017A8;
		}
	}
	*(ebp_10 - 0x04) = ~0x01;
	eax_31 = 0x00;
l100017A8:
	word32 edi_37;
	*ediOut = fn1000182D(ebp_10, 0x08, dwArg00, dwArg04, dwArg08, dwArg0C);
	return eax_31;
}

// 100017C6: Register word32 fn100017C6(Stack Eq_488 dwArg04, Stack uint32 dwArg08)
word32 fn100017C6(HMODULE dwArg04, uint32 dwArg08)
{
	if (dwArg08 == 0x01 && globals->ptr100020CC == null)
		DisableThreadLibraryCalls(dwArg04);
	return 0x01;
}

// 100017E8: Register ptr32 fn100017E8(Register (ptr Eq_172) ebx, Register ptr32 esi, Register word32 edi, Stack word32 dwArg00, Stack word32 dwArg04, Stack ui32 dwArg08)
ptr32 fn100017E8( * ebx, ptr32 esi, word32 edi, word32 dwArg00, word32 dwArg04, ui32 dwArg08)
{
	ptr32 esp_14 = fp - 0x08 - dwArg08;
	*(esp_14 - 0x04) = (Eq_139 (**)(LONG *, Eq_139, Eq_139)) ebx;
	*(esp_14 - 0x08) = esi;
	*(esp_14 - 0x0C) = edi;
	*(esp_14 - 0x10) = globals->dw10003000 ^ fp + 0x08;
	*(esp_14 - 0x14) = dwArg00;
	fs->ptr0000 = fp - 0x08;
	return fp + 0x08;
}

// 1000182D: Register uint32 fn1000182D(Register (ptr Eq_400) ebp, Stack word32 dwArg00, Stack Eq_488 dwArg04, Stack uint32 dwArg08, Stack word32 dwArg0C, Stack word32 dwArg10)
uint32 fn1000182D(Eq_400 * ebp, word32 dwArg00, HMODULE dwArg04, uint32 dwArg08, word32 dwArg0C, word32 dwArg10)
{
	fs->dw0000 = *(ebp - 0x10);
	ebp->dw0000 = dwArg00;
	return dwArg08;
}

// 10001864: void fn10001864()
void fn10001864()
{
	ui32 eax_8 = globals->dw10003000;
	if (eax_8 != 0xBB40E64E && (eax_8 & 0xFFFF0000) != 0x00)
		globals->dw10003004 = ~eax_8;
	else
	{
		GetSystemTimeAsFileTime(fp - 0x0C);
		ui32 esi_58 = dwLoc08 & 0x00 ^ dwLoc0C & 0x00 ^ GetCurrentProcessId() ^ GetCurrentThreadId() ^ GetTickCount();
		QueryPerformanceCounter(fp - 0x14);
		ui32 esi_68 = esi_58 ^ (dwLoc10 ^ dwLoc14);
		if (esi_68 == 0xBB40E64E)
			esi_68 = ~0x44BF19B0;
		else if ((esi_68 & 0xFFFF0000) == 0x00)
			esi_68 = esi_68 | esi_68 << 0x10;
		globals->dw10003000 = esi_68;
		globals->dw10003004 = ~esi_68;
	}
}

