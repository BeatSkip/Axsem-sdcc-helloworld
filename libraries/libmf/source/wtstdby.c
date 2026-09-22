/**
******************************************************************************
* @file wtstdby.c
* @brief  PMU Low power mode APIs
* @internal
* @author   Thomas Sailer, Radhika Raghavendran
* $Rev:  $
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
* @ingroup pmu
*
* @details
*/

#include "cpu.h"
#include "libmftypes.h"

#if defined(SDCC)

#pragma codeseg WTSTDBY0

// fixme: make enter_* reentrant, make wtimer_runcallbacks/idle reentrant

__reentrantb void wtimer_standby(void) __reentrant
{
	__asm
	.area HOME     (CODE)
	.area WTSTDBY0 (CODE)
	.area WTSTDBY1 (CODE)
	.area WTSTDBY2 (CODE)

	.area WTSTDBY2 (CODE)
	mov	a,#0x0C
	anl	a,_PCON
	orl	a,#0x01
	mov	_PCON,a
	ret
	__endasm;
}


#else

__reentrantb void wtimer_standby(void) __reentrant
{
	enter_standby();
}

#endif
