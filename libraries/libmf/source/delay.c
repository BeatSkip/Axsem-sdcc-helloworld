/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a “ON Semiconductor”).
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* (“ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software”) and
* if applicable the software license agreement.  Do not use this software and/or
* documentation unless you have carefully read and you agree to the limited terms and
* conditions.  By using this software and/or documentation, you agree to the limited
* terms and conditions.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* ON SEMICONDUCTOR SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL,
* INCIDENTAL, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
* @endinternal
*
* @ingroup
*
* @details
*/

#include "libmftypes.h"

#ifdef SDCC

/**
 * \brief delay (busy waiting)
 *
 */
__reentrantb void delay(uint16_t us) __reentrant __naked
{
	us;
	__asm
	mov	a,dpl
	jz	00002$
	inc	dph
00002$:	nop
	nop
00000$:	mov	a,#3
00001$:	djnz	acc,00001$
	djnz	dpl,00002$
	djnz	dph,00000$
	ret
	__endasm;
}

#elif defined __CX51__ || defined __C51__

__reentrantb void delay(uint16_t us) __reentrant
{
#pragma asm
	mov	a,r7		;
	jz	dly2		;
	inc	r6		;
dly2:	nop			;
	nop			;
dly0:	mov	a,#3		;
dly1:	djnz	acc,dly1	;
	djnz	r7,dly2		;
	djnz	r6,dly0		;
#pragma endasm
}

#elif defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0F2

__reentrantb void delay(unsigned int us) __reentrant
{
	if (!us)
		return;
	us <<= 3;
	__asm volatile(".syntax unified\n\t"
		       ".align 2\n"
		       "0:\n\t"
		       "nop\n\t"
		       "nop\n\t"
		       "subs\t%0, %0, #1\n\t"
		       "cmp\t%0, #0\n\t"
		       "bne\t0b" : "=r" (us) : "0" (us));
}

#else

__reentrantb void delay(unsigned int us) __reentrant
{
	if (!us)
		return;
	us <<= 2;
	do {
		nop();
	} while (--us);
	// inner loop
	// (1) 6: 46c0 nop
	// (1) 8: 3801 subs  r0, #1
	// (1) a: 2800 cmp   r0, #0
	// (2) c: d1fb bne.n 6 <delay+0x6>
	// 5 cycles
}

#endif

#else

__reentrantb void delay(uint16_t us) __reentrant
{
	uint8_t x;
	do {
		x = 3;
		do {
			--x;
		} while (x);
		--us;
	} while (us);
}

#endif
