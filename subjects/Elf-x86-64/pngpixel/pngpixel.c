// pngpixel.c
// Generated by decompiling pngpixel
// using Reko decompiler version 0.7.1.0.

#include "pngpixel.h"

// 0000000000400AE8: void _init()
void _init()
{
	if (globals->qw601FF8 != 0x00)
		fn0000000000400CC0();
	return;
}

// 0000000000400CC0: void fn0000000000400CC0()
void fn0000000000400CC0()
{
	word64 rsp_3;
	globals->qw601FF8();
	return;
}

// 0000000000400CD0: void _start(Register word64 rax, Register (ptr Eq_17) rdx, Stack Eq_18 qwArg00, Stack word32 dwArg04)
void _start(word64 rax,  * rdx, Eq_18 qwArg00, word32 dwArg04)
{
	__align(fp + 0x08);
	word64 rax_22 = DPB(rax, __libc_start_main(&globals->t4012F9, qwArg00, fp + 0x08, &globals->t401780, &globals->t4017F0, rdx, DPB(qwArg00, fp + 0x04, 0)), 0);
	__hlt();
}

// 0000000000400D00: Register ptr64 deregister_tm_clones(Register word64 r8)
ptr64 deregister_tm_clones(word64 r8)
{
	if (false || 0x00 == 0x00)
		return fp + 0x04;
	else
	{
		ptr64 rsp_43;
		word32 eax_44;
		word64 rax_45;
		word64 rbp_46;
		word64 r8_47;
		byte SCZO_48;
		byte CZ_49;
		byte SZO_50;
		byte C_51;
		byte Z_52;
		word32 edi_53;
		word64 rdi_54;
		eax();
		return rsp_43;
	}
}

// 0000000000400D40: void register_tm_clones()
void register_tm_clones()
{
	if (0x00 == 0x00 || 0x00 == 0x00)
		return;
	else
	{
		word64 rsp_43;
		word64 rsi_44;
		word64 rbp_45;
		byte SCZO_46;
		word64 rax_47;
		byte Z_48;
		byte SZO_49;
		byte C_50;
		word64 rdi_51;
		word32 eax_52;
		eax();
		return;
	}
}

// 0000000000400D80: void __do_global_dtors_aux(Register word64 r8)
void __do_global_dtors_aux(word64 r8)
{
	if (globals->b602108 == 0x00)
	{
		deregister_tm_clones(r8);
		globals->b602108 = 0x01;
	}
	return;
}

// 0000000000400DA0: void frame_dummy()
void frame_dummy()
{
frame_dummy_entry:
	rsp = fp
	rdi = 0x00601E10
	SCZO = cond(globals->qw601E10 - 0x00)
	Z = SCZO
	branch Test(NE,Z) l0000000000400DB0
	goto l0000000000400DAB
l0000000000400DA0:
l0000000000400DAB:
	register_tm_clones()
	return
l0000000000400DB0:
	rax = 0x00
	SZO = cond(0x00)
	Z = SZO
	C = false
	branch Test(EQ,Z) l0000000000400DAB
l0000000000400DBA:
	rsp = fp - 0x04
	dwLoc04 = rbp
	qwLoc04 = DPB(qwLoc04, dwLoc04, 0)
	rbp = fp - 0x04
	eax()
	rbp = qwLoc04
	rsp = fp + 0x04
	register_tm_clones()
	return
l0000000000400DC0_thunk_register_tm_clones:
frame_dummy_exit:
}

// 0000000000400DC6: void component(Register uint32 ecx, Register word32 edx, Register word32 esi, Register word32 edi, Register word32 r8d, Register ptr64 r13)
void component(uint32 ecx, word32 edx, word32 esi, word32 edi, word32 r8d, ptr64 r13)
{
	*(r13 - 0x28) = r8d;
	if (ecx > 0x10)
	{
		uint64 rax_85 = (uint64) fprintf(globals->ptr602100, "pngpixel: invalid bit depth %u
", tLoc34);
		exit(0x01);
	}
	else
	{
		word64 rax_60 = globals->a401828[(uint64) ecx * 0x08];
		Eq_173 eax_61 = (word32) rax_60;
		word64 rsp_62;
		word64 rbp_63;
		byte SCZO_64;
		word64 rdi_65;
		word32 esi_66;
		word32 edx_67;
		word32 ecx_68;
		word64 r13_69;
		word32 r8d_70;
		word32 eax_71;
		word64 rax_72;
		byte SZO_73;
		byte C_74;
		word64 rdx_75;
		byte CZ_76;
		word64 rsi_77;
		word32 edi_78;
		eax_61();
		return;
	}
}

// 0000000000400EE9: Register word64 print_pixel(Register byte dil, Register (ptr Eq_194) fs, Stack word64 qwArg04, Stack word64 qwArg0C)
word64 print_pixel(byte dil, Eq_194 * fs, word64 qwArg04, word64 qwArg0C)
{
	word64 rsp_36;
	word64 rbp_37;
	word64 rbx_38;
	byte SCZO_39;
	word64 rdi_40;
	word64 rsi_41;
	word64 rdx_42;
	word32 ecx_43;
	word64 rax_44;
	struct Eq_206 * fs_45;
	word32 eax_46;
	byte SZO_47;
	byte C_48;
	byte al_49;
	byte CZ_50;
	word32 esi_51;
	byte Z_52;
	byte dil_53;
	png_get_bit_depth();
	word64 rsp_61;
	word64 rbp_62;
	word64 rbx_63;
	byte SCZO_64;
	word64 rdi_65;
	word64 rsi_66;
	word64 rdx_67;
	word32 ecx_68;
	word64 rax_69;
	struct Eq_225 * fs_70;
	word32 eax_71;
	byte SZO_72;
	byte C_73;
	byte al_74;
	byte CZ_75;
	word32 esi_76;
	byte Z_77;
	byte dil_78;
	png_get_color_type();
	word64 rax_25 = fs->qw0028;
	uint32 eax_79 = (word32) al_74;
	if (eax_79 > 0x06)
	{
		word64 rsp_126;
		word64 rbp_127;
		word64 rbx_128;
		byte SCZO_129;
		word64 rdi_130;
		word64 rsi_131;
		word64 rdx_132;
		word32 ecx_133;
		word64 rax_134;
		struct Eq_251 * fs_135;
		word32 eax_136;
		byte SZO_137;
		byte C_138;
		byte al_139;
		byte CZ_140;
		word32 esi_141;
		byte Z_142;
		byte dil_143;
		png_error();
		if ((rax_25 ^ fs_135->qw0028) != 0x00)
			__stack_chk_fail();
		return qwArg0C;
	}
	else
	{
		word64 rax_103 = globals->a401958[(uint64) eax_79 * 0x08];
		Eq_272 eax_104 = (word32) rax_103;
		word64 rsp_105;
		word64 rbp_106;
		word64 rbx_107;
		byte SCZO_108;
		word64 rdi_109;
		word64 rsi_110;
		word64 rdx_111;
		word32 ecx_112;
		word64 rax_113;
		struct Eq_283 * fs_114;
		word32 eax_115;
		byte SZO_116;
		byte C_117;
		byte al_118;
		byte CZ_119;
		word32 esi_120;
		byte Z_121;
		byte dil_122;
		eax_104();
		return rbp_106;
	}
}

// 00000000004012F9: void main(Register (ptr Eq_295) rsi, Register word32 edi, Register word64 r13, Register (ptr Eq_298) fs)
void main(Eq_295 * rsi, word32 edi, word64 r13, Eq_298 * fs)
{
	ptr64 rbp_136 = fp - 0x04;
	if (edi != 0x04)
	{
		FILE * rax_1023 = globals->ptr602100;
		word64 rax_1028 = DPB(rax_1023, fwrite(&globals->v401A70, 0x01, 0x27, rax_1023), 0);
		goto l000000000040175D;
	}
	word64 rsp_105;
	word64 rbp_106;
	byte SCZO_107;
	word32 edi_108;
	word64 rsi_109;
	uint64 rax_110;
	struct Eq_328 * fs_111;
	word32 eax_112;
	byte SZO_113;
	byte C_114;
	byte Z_115;
	word64 rdi_116;
	word32 esi_117;
	word32 ecx_118;
	word64 rcx_119;
	word32 edx_120;
	word64 rdx_121;
	word64 r13_122;
	word64 r9_123;
	word64 r8_124;
	byte SO_125;
	byte cl_126;
	byte al_127;
	byte dil_128;
	atol();
	word64 rsp_135;
	byte SCZO_137;
	word32 edi_138;
	word64 rsi_139;
	uint64 rax_140;
	word32 eax_142;
	byte SZO_143;
	byte C_144;
	byte Z_145;
	word64 rdi_146;
	word32 esi_147;
	word32 ecx_148;
	word64 rcx_149;
	word32 edx_150;
	word64 rdx_151;
	word64 r13_152;
	word64 r9_153;
	word64 r8_154;
	byte SO_155;
	byte cl_156;
	byte al_157;
	byte dil_158;
	atol();
	FILE * rax_165 = fopen(rsi->ptr0018, "rb");
	if (rax_165 == null)
	{
		uint64 rax_1022 = (uint64) fprintf(globals->ptr602100, "pngpixel: %s: could not open file
", tLocA4);
		goto l000000000040175D;
	}
	word64 rsp_176;
	byte SCZO_178;
	word32 edi_179;
	word64 rsi_180;
	word64 rax_181;
	word32 eax_183;
	byte SZO_184;
	byte C_185;
	byte Z_186;
	word64 rdi_187;
	word32 esi_188;
	word32 ecx_189;
	word64 rcx_190;
	word32 edx_191;
	word64 rdx_192;
	word64 r13_193;
	word64 r9_194;
	word64 r8_195;
	byte SO_196;
	byte cl_197;
	byte al_198;
	byte dil_199;
	png_create_read_struct();
	if (rax_181 == 0x00)
	{
		FILE * rax_1007 = globals->ptr602100;
		word64 rax_1012 = DPB(rax_1007, fwrite(&globals->v401A18, 0x01, 0x2E, rax_1007), 0);
		goto l000000000040175D;
	}
	word64 rsp_207;
	word64 rbp_208;
	byte SCZO_209;
	word32 edi_210;
	word64 rsi_211;
	word64 rax_212;
	struct Eq_435 * fs_213;
	word32 eax_214;
	byte SZO_215;
	byte C_216;
	byte Z_217;
	word64 rdi_218;
	word32 esi_219;
	word32 ecx_220;
	word64 rcx_221;
	word32 edx_222;
	word64 rdx_223;
	word64 r13_224;
	word64 r9_225;
	word64 r8_226;
	byte SO_227;
	byte cl_228;
	byte al_229;
	byte dil_230;
	png_create_info_struct();
	if (rax_212 != 0x00)
	{
		word64 rsp_313;
		word64 rbp_314;
		byte SCZO_315;
		word32 edi_316;
		word64 rsi_317;
		word64 rax_318;
		struct Eq_474 * fs_319;
		word32 eax_320;
		byte SZO_321;
		byte C_322;
		byte Z_323;
		word64 rdi_324;
		word32 esi_325;
		word32 ecx_326;
		word64 rcx_327;
		word32 edx_328;
		word64 rdx_329;
		word64 r13_330;
		word64 r9_331;
		word64 r8_332;
		byte SO_333;
		byte cl_334;
		byte al_335;
		byte dil_336;
		png_init_io();
		word64 rsp_341;
		word64 rbp_342;
		byte SCZO_343;
		word32 edi_344;
		word64 rsi_345;
		word64 rax_346;
		struct Eq_499 * fs_347;
		word32 eax_348;
		byte SZO_349;
		byte C_350;
		byte Z_351;
		word64 rdi_352;
		word32 esi_353;
		word32 ecx_354;
		word64 rcx_355;
		word32 edx_356;
		word64 rdx_357;
		word64 r13_358;
		word64 r9_359;
		word64 r8_360;
		byte SO_361;
		byte cl_362;
		byte al_363;
		byte dil_364;
		png_read_info();
		word64 rsp_369;
		word64 rbp_370;
		byte SCZO_371;
		word32 edi_372;
		word64 rsi_373;
		word64 rax_374;
		struct Eq_524 * fs_375;
		word32 eax_376;
		byte SZO_377;
		byte C_378;
		byte Z_379;
		word64 rdi_380;
		word32 esi_381;
		word32 ecx_382;
		word64 rcx_383;
		word32 edx_384;
		word64 rdx_385;
		word64 r13_386;
		word64 r9_387;
		word64 r8_388;
		byte SO_389;
		byte cl_390;
		byte al_391;
		byte dil_392;
		png_get_rowbytes();
		word64 rsp_397;
		word64 rbp_398;
		byte SCZO_399;
		word32 edi_400;
		word64 rsi_401;
		word64 rax_402;
		struct Eq_549 * fs_403;
		word32 eax_404;
		byte SZO_405;
		byte C_406;
		byte Z_407;
		word64 rdi_408;
		word32 esi_409;
		word32 ecx_410;
		word64 rcx_411;
		word32 edx_412;
		word64 rdx_413;
		word64 r13_414;
		word64 r9_415;
		word64 r8_416;
		byte SO_417;
		byte cl_418;
		byte al_419;
		byte dil_420;
		png_malloc();
		word64 rsp_443;
		word64 rbp_444;
		byte SCZO_445;
		word32 edi_446;
		word64 rsi_447;
		word64 rax_448;
		struct Eq_574 * fs_449;
		word32 eax_450;
		byte SZO_451;
		byte C_452;
		byte Z_453;
		word64 rdi_454;
		word32 esi_455;
		word32 ecx_456;
		word64 rcx_457;
		word32 edx_458;
		word64 rdx_459;
		word64 r13_460;
		word64 r9_461;
		word64 r8_462;
		byte SO_463;
		byte cl_464;
		byte al_465;
		byte dil_466;
		png_get_IHDR();
		if (eax_450 != 0x00)
		{
			word32 eax_473 = (word32) (uint64) dwLoc74;
			if (eax_473 != 0x00)
			{
				if (eax_473 != 0x01)
				{
					word64 rsp_954;
					word64 rbp_955;
					byte SCZO_956;
					word32 edi_957;
					word64 rsi_958;
					word64 rax_959;
					struct Eq_637 * fs_960;
					word32 eax_961;
					byte SZO_962;
					byte C_963;
					byte Z_964;
					word64 rdi_965;
					word32 esi_966;
					word32 ecx_967;
					word64 rcx_968;
					word32 edx_969;
					word64 rdx_970;
					word64 r13_971;
					word64 r9_972;
					word64 r8_973;
					byte SO_974;
					byte cl_975;
					byte al_976;
					byte dil_977;
					png_error();
				}
				else
					dwLoc68 = 0x07;
			}
			else
				dwLoc68 = 0x01;
			word64 rsp_481;
			byte SCZO_483;
			word32 edi_484;
			word64 rsi_485;
			word64 rax_486;
			struct Eq_668 * fs_487;
			word32 eax_488;
			byte SZO_489;
			byte C_490;
			byte Z_491;
			word64 rdi_492;
			word32 esi_493;
			word32 ecx_494;
			word64 rcx_495;
			word32 edx_496;
			word64 rdx_497;
			word64 r13_498;
			word64 r9_499;
			word64 r8_500;
			byte SO_501;
			byte cl_502;
			byte al_503;
			byte dil_504;
			ptr64 rbp_482;
			png_start_read_image();
			int32 dwLoc64_505 = 0x00;
l0000000000401673:
			int32 eax_535 = (word32) (uint64) dwLoc64_505;
			if (eax_535 >= dwLoc68)
			{
l000000000040167F:
				*(rbp_482 - 0x40) = 0x00;
				word64 rsp_551;
				word64 rbp_552;
				byte SCZO_553;
				word32 edi_554;
				word64 rsi_555;
				word64 rax_556;
				struct Eq_709 * fs_557;
				word32 eax_558;
				byte SZO_559;
				byte C_560;
				byte Z_561;
				word64 rdi_562;
				word32 esi_563;
				word32 ecx_564;
				word64 rcx_565;
				word32 edx_566;
				word64 rdx_567;
				word64 r13_568;
				word64 r9_569;
				word64 r8_570;
				byte SO_571;
				byte cl_572;
				byte al_573;
				byte dil_574;
				png_free();
				word64 rsp_579;
				word64 rbp_580;
				byte SCZO_581;
				word32 edi_582;
				word64 rsi_583;
				word64 rax_584;
				struct Eq_734 * fs_585;
				word32 eax_586;
				byte SZO_587;
				byte C_588;
				byte Z_589;
				word64 rdi_590;
				word32 esi_591;
				word32 ecx_592;
				word64 rcx_593;
				word32 edx_594;
				word64 rdx_595;
				word64 r13_596;
				word64 r9_597;
				word64 r8_598;
				byte SO_599;
				byte cl_600;
				byte al_601;
				byte dil_602;
				png_destroy_info_struct();
l00000000004016DE:
				word64 rsp_255;
				byte SCZO_257;
				word32 edi_258;
				word64 rsi_259;
				word64 rax_260;
				word32 eax_262;
				byte SZO_263;
				byte C_264;
				byte Z_265;
				word64 rdi_266;
				word32 esi_267;
				word32 ecx_268;
				word64 rcx_269;
				word32 edx_270;
				word64 rdx_271;
				word64 r13_272;
				word64 r9_273;
				word64 r8_274;
				byte SO_275;
				byte cl_276;
				byte al_277;
				byte dil_278;
				png_destroy_read_struct();
l000000000040175D:
				if ((*(rbp_136 - 0x08) ^ fs->qw0028) != 0x00)
					__stack_chk_fail();
				return;
			}
			word32 dwLoc58_643;
			word32 dwLoc54_642;
			word32 dwLoc60_641;
			word32 dwLoc5C_640;
			if ((word32) (uint64) dwLoc74 == 0x01)
			{
				word32 eax_764;
				if (dwLoc64_505 > 0x01)
					eax_764 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) (0x01 << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x07 - dwLoc64_505)) >> 0x01))))) - 0x01);
				else
					eax_764 = 0x07;
				word32 eax_802;
				uint32 edx_798 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) (eax_764 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc64_505))) & 0x01)) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc64_505) + 0x01)) >> 0x01)))))))))))) & 0x07))) + (word32) ((uint64) dwLoc84));
				if (dwLoc64_505 > 0x01)
					eax_802 = (word32) (uint64) ((word32) (uint64) (0x07 - dwLoc64_505) >> 0x01);
				else
					eax_802 = 0x03;
				if ((word32) (uint64) (word32) (uint64) (edx_798 >> (byte) ((uint64) eax_802)) == 0x00)
					goto l000000000040166F;
				word32 eax_888;
				dwLoc5C_640 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (uint64) dwLoc64_505 & 0x01) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc64_505) + 0x01)) >> 0x01))))))))) & 0x07);
				dwLoc60_641 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) ((word32) (uint64) ((word32) (uint64) dwLoc64_505 & 0x01) == 0x00) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) dwLoc64_505) >> 0x01))))))))) & 0x07);
				dwLoc54_642 = (word32) (uint64) (word32) (uint64) (0x01 << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x07 - dwLoc64_505)) >> 0x01)))));
				if (dwLoc64_505 > 0x02)
					eax_888 = (word32) (uint64) (word32) (uint64) (0x08 >> (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc64_505) - 0x01)) >> 0x01)))));
				else
					eax_888 = 0x08;
				dwLoc58_643 = eax_888;
			}
			else
			{
				dwLoc5C_640 = 0x00;
				dwLoc60_641 = 0x00;
				dwLoc54_642 = 0x01;
				dwLoc58_643 = 0x01;
			}
			uint32 dwLoc50_658 = (word32) (uint64) dwLoc60_641;
			while (true)
			{
				uint64 rax_682 = (uint64) dwLoc80;
				uint32 eax_683 = (word32) rax_682;
				if (dwLoc50_658 >= eax_683)
					break;
				word64 rsp_694;
				byte SCZO_696;
				word32 edi_697;
				word64 rsi_698;
				word64 rax_699;
				struct Eq_194 * fs_700;
				word32 eax_701;
				byte SZO_702;
				byte C_703;
				byte Z_704;
				word64 rdi_705;
				word32 esi_706;
				word32 ecx_707;
				word64 rcx_708;
				word32 edx_709;
				word64 rdx_710;
				word64 r13_711;
				word64 r9_712;
				word64 r8_713;
				byte SO_714;
				byte cl_715;
				byte al_716;
				byte dil_717;
				png_read_row();
				uint64 rax_688 = DPB(rax_682, puts("png_read_row"), 0);
				if ((uint64) dwLoc50_658 == rax_140)
				{
					uint32 dwLoc4C_732 = (word32) (uint64) dwLoc5C_640;
					while (dwLoc4C_732 < (word32) ((uint64) dwLoc84))
					{
						if ((uint64) dwLoc4C_732 == rax_110)
						{
							rbp_482 = print_pixel((byte) rax_181, fs_700, qwLoc9C, qwLoc94);
							goto l000000000040167F;
						}
						dwLoc4C_732 = dwLoc4C_732 + (word32) ((uint64) dwLoc54_642);
					}
				}
				dwLoc50_658 = dwLoc50_658 + (word32) ((uint64) dwLoc58_643);
			}
l000000000040166F:
			dwLoc64_505 = dwLoc64_505 + 0x01;
			goto l0000000000401673;
		}
		word64 rsp_983;
		word64 rbp_984;
		byte SCZO_985;
		word32 edi_986;
		word64 rsi_987;
		word64 rax_988;
		struct Eq_601 * fs_989;
		word32 eax_990;
		byte SZO_991;
		byte C_992;
		byte Z_993;
		word64 rdi_994;
		word32 esi_995;
		word32 ecx_996;
		word64 rcx_997;
		word32 edx_998;
		word64 rdx_999;
		word64 r13_1000;
		word64 r9_1001;
		word64 r8_1002;
		byte SO_1003;
		byte cl_1004;
		byte al_1005;
		byte dil_1006;
		png_error();
	}
	FILE * rax_303 = globals->ptr602100;
	word64 rax_308 = DPB(rax_303, fwrite(&globals->v4019E8, 0x01, 44, rax_303), 0);
	goto l00000000004016DE;
}

// 0000000000401780: void __libc_csu_init(Register word64 rsi, Register word32 edi)
void __libc_csu_init(word64 rsi, word32 edi)
{
	_init();
	if (0x0000000000601E08 - 0x0000000000601E00 >> 0x03 != 0x00)
	{
		do
		{
			word64 rsp_74;
			word64 rdi_75;
			word64 rsi_76;
			word32 r15d_77;
			word32 edi_78;
			word64 r15_79;
			word64 rbp_80;
			word64 r12_81;
			word64 rbx_82;
			word64 r14_83;
			word64 r13_84;
			word64 rdx_85;
			byte SCZO_86;
			byte SZO_87;
			byte C_88;
			byte Z_89;
			word32 ebx_90;
			globals->u601E00();
		} while (rbx_82 + 0x01 != rbp_80);
	}
	return;
}

// 00000000004017F0: void __libc_csu_fini()
void __libc_csu_fini()
{
	return;
}

// 00000000004017F4: void _fini()
void _fini()
{
	return;
}
