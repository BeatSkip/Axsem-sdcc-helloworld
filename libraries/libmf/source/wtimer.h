/**
******************************************************************************
* @file wtimer.h
* @brief Timer 0 and Timer 1 internal functions
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
#ifndef WTIMER_H
#define WTIMER_H

#include "libmfwtimer.h"

#if ((defined __ARMEL__) || (defined __ARMEB__)) && !(defined __AXM0F2)

struct wtimer_state {
	struct wtimer_desc __xdata *queue;
};

#else

struct wtimer_state {
	struct wtimer_state_time {
		uint32_t cur;
		uint16_t ref;
	} time;
	struct wtimer_desc __xdata *queue;
};

#endif

extern struct wtimer_state __xdata wtimer_state[2];
extern struct wtimer_callback __xdata * __xdata wtimer_pending;

#if defined __ARMEL__ || defined __ARMEB__
#define WTIMER_NULL      (0x0)
#define WTIMER_NULLDESC  ((struct wtimer_desc __xdata *)WTIMER_NULL)
#define WTIMER_NULLCB    ((struct wtimer_callback __xdata *)WTIMER_NULL)
#define WTIMER_PTR(x)    ((struct wtimer_desc __xdata *)((char __xdata *)&(x) - (char __xdata *)&((struct wtimer_desc __xdata *)0)->next))
#define WTIMER_CBPTR(x)  ((struct wtimer_callback __xdata *)((char __xdata *)&(x) - (char __xdata *)&((struct wtimer_callback __xdata *)0)->next))
#else
#define WTIMER_NULL      (0xFFFF)
#define WTIMER_NULLDESC  ((struct wtimer_desc __xdata *)WTIMER_NULL)
#define WTIMER_NULLCB    ((struct wtimer_callback __xdata *)WTIMER_NULL)
#define WTIMER_PTR(x)    ((struct wtimer_desc __xdata *)((char __xdata *)&(x) - (char __xdata *)&((struct wtimer_desc __xdata *)0)->next))
#define WTIMER_CBPTR(x)  ((struct wtimer_callback __xdata *)((char __xdata *)&(x) - (char __xdata *)&((struct wtimer_callback __xdata *)0)->next))
#endif

// the following routines must be called with (wtimer) interrupts disabled
extern __reentrantb void wtimer_addcb_core(struct wtimer_callback __xdata *desc) __reentrant;
extern __reentrantb uint8_t wtimer_removecb_core(struct wtimer_callback __xdata *desc) __reentrant;
extern __reentrantb void wtimer0_schedq(void) __reentrant;
extern __reentrantb void wtimer0_update(void) __reentrant;
extern __reentrantb void wtimer0_addcore(struct wtimer_desc __xdata *desc) __reentrant;
extern __reentrantb uint8_t wtimer0_removecb_core(struct wtimer_desc __xdata *desc) __reentrant;
extern __reentrantb void wtimer1_schedq(void) __reentrant;
extern __reentrantb void wtimer1_update(void) __reentrant;
extern __reentrantb void wtimer1_addcore(struct wtimer_desc __xdata *desc) __reentrant;
extern __reentrantb uint8_t wtimer1_removecb_core(struct wtimer_desc __xdata *desc) __reentrant;

#define WTIMER_USEASM

#endif /* WTIMER_H */
