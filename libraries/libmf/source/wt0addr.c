/**
******************************************************************************
* @file wt0addr.c
* @brief Timer 0 APIs
* @internal
* @author   Thomas Sailer, Radhika Raghavendran, Pradeep Kumar GR
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
* @ingroup timer
*
* @details
*/

#include "cpu.h"
#include "wtimer.h"

#if defined(WTIMER_USEASM) && defined(SDCC)

__reentrantb void wtimer0_addrelative(struct wtimer_desc __xdata *desc) __reentrant __naked
{
	__asm
	mov	a,_IE
	anl	a,#0x80
	push	acc
	clr	_EA
	push	dpl
	push	dph
	lcall	_wtimer0_update
	;; desc->time += wtimer_state[0].time.cur
	mov	dptr,#(_wtimer_state + 0x0000)
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	pop	dph
	pop	dpl
	mov	r6,dpl
	mov	r7,dph
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	movx	a,@dptr
	add	a,r2
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,r3
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,r4
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,r5
	movx	@dptr,a
	mov	dpl,r6
	mov	dph,r7
	lcall	_wtimer0_addcore
	lcall	_wtimer0_schedq
	pop	acc
	orl	_IE,a
	ret
	__endasm;
}

#elif (defined __ARMEL__ || defined __ARMEB__) && defined __AXM0

__reentrantb void wtimer0_addrelative(struct wtimer_desc __xdata *desc) __reentrant
{
	criticalsection_t crit = enter_critical();
	desc->time += WUT->WTCNT;
	wtimer0_addcore(desc);
	wtimer0_schedq();
	exit_critical(crit);
}

#else

__reentrantb void wtimer0_addrelative(struct wtimer_desc __xdata *desc) __reentrant
{
	criticalsection_t crit = enter_critical();
	wtimer0_update();
	desc->time += wtimer_state[0].time.cur;
	wtimer0_addcore(desc);
	wtimer0_schedq();
	exit_critical(crit);
}

#endif
