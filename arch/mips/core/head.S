/*
 * crt0.S -- startup file for MIPS.
 *
 * Copyright (c) 1995, 1996, 1997, 2001 Cygnus Support
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 */

#include <mips/regdef.h>
#include <mips/cpu.h>

#define ST0_IE	0x00000001
#define ST0_ERL	0x00000004

	.text
	.align	2

	.globl	__start
	.globl	__stack
	.globl	_PrepC
	.ent	__start
	.set	noreorder

__start:
	mtc0	zero, C0_CAUSE
	nop

	mfc0	k0, C0_SR
	li	k1, ~(ST0_ERL | ST0_IE)
	and	k0, k1
	mtc0	k0, C0_SR
	nop

	la	sp, __stack

	la	v0, _PrepC
	jal	v0

	.end __start
