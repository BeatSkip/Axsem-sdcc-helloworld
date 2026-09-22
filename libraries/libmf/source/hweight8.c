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

#if defined(SDCC)

__reentrantb uint8_t hweight8(uint8_t x) __reentrant __naked
{
	x;
	__asm;
	mov	a,dpl
	anl	a,#0x55
	xch	a,dpl
	rr	a
	anl	a,#0x55
	add	a,dpl
	mov	dpl,a
	anl	a,#0x33
	xch	a,dpl
	rr	a
	rr	a
	anl	a,#0x33
	add	a,dpl
	mov	dpl,a
	anl	a,#0x0f
	xch	a,dpl
	swap	a
	anl	a,#0x0f
	add	a,dpl
	mov	dpl,a
	ret
	__endasm;
}

#else

__reentrantb uint8_t hweight8(uint8_t x) __reentrant
{
	x = (x & 0x55) + ((x >> 1) & 0x55);
	x = (x & 0x33) + ((x >> 2) & 0x33);
	x = (x & 0x0F) + ((x >> 4) & 0x0F);
	return x;
}

#endif
