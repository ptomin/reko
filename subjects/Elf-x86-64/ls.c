// ls.c
// Generated by decompiling ls
// using Decompiler version 0.6.0.0.

#include "ls.h"

void _init()
{
	word64 rax_5 = Mem0[0x0000000000619FF8 + 0x00:word64];
	byte SZO_6 = cond(rax_5);
	if (rax_5 != 0x00)
		__gmon_start__();
	return;
}

void fn0000000000404890(word64 rax,  * rdx, word64 qwArg00, word32 dwArg04)
{
	__align(fp + 0x08);
	rax_20 = DPB(rax, __libc_start_main(&globals->t4028C0, qwArg00, fp + 0x08, 4267616, 0x00411ED0, rdx, fp), 0);
	__hlt();
}

void _fini()
{
	return;
}

