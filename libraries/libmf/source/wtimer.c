/**
******************************************************************************
* @file wtimer.c
* @brief Timer 0 and Timer 1 APIs
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

#define WTIMER0_MARGIN       0x1000
#define WTIMER1_MARGIN       0x1000
#define WTIMER_LPXOSC_SLEEP  8

extern unsigned int RAM2KADDR;

struct wtimer_state __xdata wtimer_state[2];
struct wtimer_callback __xdata * __xdata wtimer_pending;

#if defined(SDCC)
typedef __reentrantb void (*handler_t)(struct wtimer_callback __xdata *desc) __reentrant;
#else
typedef void (*handler_t)(struct wtimer_callback __xdata *desc);
#endif

#if defined(SDCC) || defined(__ICC8051__)
#define WTFLAG_CANSLEEPANY (WTFLAG_CANSLEEP | WTFLAG_CANSLEEPCONT)
#else
#define WTFLAG_CANSLEEPANY (WTFLAG_CANSLEEP)
#endif

#if defined(SDCC)

static void dummy0(void) __naked
{
	__asm;
	.area HOME   (CODE)
	__endasm;
}

void wtimer_irq(void) __interrupt(1)
{
	uint8_t __autodata dpssave = DPS;
	uint8_t __autodata s = WTSTAT;
	DPS = 0;
	if (s & 0x01) {
		wtimer0_update();
		wtimer0_schedq();
		s |= WTSTAT;
	}
	if (s & 0x20) {
		wtimer1_update();
		wtimer1_schedq();
		WTSTAT;
	}
	DPS = dpssave;
}

static void dummy1(void) __naked
{
	__asm;
	.area CSEG   (CODE)
	__endasm;
}

#elif defined __CX51__ || defined __C51__

void wtimer_irq(void) interrupt 1
{
	uint8_t __autodata dpssave = DPS;
	uint8_t __autodata s = WTSTAT;
	DPS = 0;
	if (s & 0x01) {
		wtimer0_update();
		wtimer0_schedq();
		s |= WTSTAT;
	}
	if (s & 0x20) {
		wtimer1_update();
		wtimer1_schedq();
		WTSTAT;
	}
	DPS = dpssave;
}

#elif defined __ICC8051__

#pragma vector=0x0b
__interrupt void wtimer_irq(void)
{
	uint8_t __autodata dpssave = DPS;
	uint8_t __autodata s = WTSTAT;
	DPS = 0;
	if (s & 0x01) {
		wtimer0_update();
		wtimer0_schedq();
		s |= WTSTAT;
	}
	if (s & 0x20) {
		wtimer1_update();
		wtimer1_schedq();
		WTSTAT;
	}
	DPS = dpssave;
}

#elif defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0F2

#include "axm0_config.h"
#include "libmfosc.h"

#define AXM0F2_WDT_WRITE_SLEEP_DELAY_LFCLK	2
#define AXM0F2_WDT_WRITE_DELAY_LFCLK		5

static struct wtimer_desc __xdata wdt_match_delay;          /* Descriptor to schedule delay after wdt_match write to maintain 2/5 LFCLK cycle */

void WCOWDT_Handler(void)
{
	wtimer0_update();
	wtimer0_schedq();
	WCO->WDT_CONTROL = (WCO->WDT_CONTROL & ~0x00040400) | 0x00000004;
	WCO->WDT_CONTROL;
}

void TCPWM4_Handler(void)
{
	wtimer1_update();
	wtimer1_schedq();
	TCPWM_CNT4->INTR = (TCPWM_CNT4->INTR & ~0x00000003) | 0x00000002;
}

#else

void WakeupTimer_Handler(void)
{
	if (WUT->WTSTS) {
		wtimer0_update();
		wtimer0_schedq();
		WUT->WTSTS = 0x1;
	}
}
void TickerTimer_Handler(void)
{
	if (TICKER->TTSTS) {
		wtimer1_update();
		wtimer1_schedq();
		TICKER->TTSTS = 0x1;
	}
}

#endif

#else

#error "Compiler unsupported"

#endif

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0F2

/* Call back function to add min 5 LFCLK cycle delay between two WDT_MATCH register write */
static void wdt_match_delay_callback(struct wtimer_desc __xdata *desc)
{
	desc;
	wtimer0_schedq();
}

/* Call back function to add 2 LFCLK cycle delay before entering sleep, after writing WDT_MATCH register */
static void wdt_match_sleep_delay_callback(struct wtimer_desc __xdata *desc)
{
	desc;
	/* Do nothing */
}

/*
 * Resources used:
 *
 * wtimer0:
 *   - WCOWDT
 *   - clock: ILO, nominal 40kHz
 * wtimer1
 *   - TCPWM4
 *   - PERI DIV16_5
 *   - clock: IMO, divided by 1, nominal 48MHz
 */

__reentrantb void wtimer_doinit(uint8_t wakeup) __reentrant
{
	NVIC_DisableIRQ(WCOWDT_IRQn);
	NVIC_DisableIRQ(TCPWM4_IRQn);

	if (wakeup) {
		wtimer0_update();
	} else {
	    TCPWM->CTRL &= ~0x00000010;
	    wtimer_pending 			 = WTIMER_NULLCB;
		wtimer_state[0].time.ref = WCO->WDT_CTRLOW;
		wtimer_state[0].time.cur = 0;
		wtimer_state[0].queue 	 = WTIMER_NULLDESC;
	}

    wtimer_state[1].time.ref = TCPWM_CNT4->COUNTER;
	wtimer_state[1].time.cur = 0;
	wtimer_state[1].queue = WTIMER_NULLDESC;
	wtimer0_schedq();
	wtimer1_schedq();

	if (!wakeup) {
		WCO->WDT_CONFIG |= 0x00000001;
		WCO->WDT_CONTROL |= 0x00000001;
		while (!(WCO->WDT_CONTROL & 0x00000002));
	}

    // divider 5: divide by 1
    PERI->PCLK_CTL8 = 0x00000045;
    TCPWM_CNT4->PERIOD = 0x0000FFFF;

    TCPWM_CNT4->INTR_MASK = 0x00000002;
    TCPWM_CNT4->TR_CTRL1 = 0x0000000C;
    TCPWM->CTRL |= 0x00000010;
    TCPWM->CMD = 0x10000000;
    // Reset Interrupts
    WCO->WDT_CONTROL = (WCO->WDT_CONTROL & ~0x00040400) | 0x00000004;
    WCO->WDT_CONTROL;
    TCPWM_CNT4->INTR = (TCPWM_CNT4->INTR & ~0x00000003) | 0x00000002;

    NVIC_ClearPendingIRQ(WCOWDT_IRQn);
    NVIC_ClearPendingIRQ(TCPWM4_IRQn);

	NVIC_EnableIRQ(WCOWDT_IRQn);
	NVIC_EnableIRQ(TCPWM4_IRQn);
}

extern uint8_t __startcause;

__reentrantb void wtimer_init(void) __reentrant
{
	wtimer_doinit(__startcause == STARTCAUSE_WAKEUPSLEEP);
}

#endif /* __AXM0F2 */

#ifdef __AXM0

static __reentrantb void wtimer_doinit(uint8_t wakeup) __reentrant
{
	/* Disable Wakeup Timer and Ticker Timer interrupts */
	NVIC_DisableIRQ(WakeupTimer_IRQn);
	NVIC_DisableIRQ(TickerTimer_IRQn);

	wtimer_pending = WTIMER_NULLCB;

	if (wakeup) {
		wtimer0_update();
	} else {
		/* clear out the wakeup timer queue */
		wtimer_state[0].queue = WTIMER_NULLDESC;
		if (WUT->WTCFG_b.WTSRC != 0x7)
			WUT->WTSTS = 0x1;
	}

	/* Clear out the ticker timer queue */
	wtimer_state[1].queue = WTIMER_NULLDESC;
	if (TICKER->TTCFG_b.TTSRC != 0x7)
		TICKER->TTSTS = 0x1;

	wtimer0_schedq();
	wtimer1_schedq();

	/* Enable Wakeup Timer and Ticker Timer interrupts */
	NVIC_EnableIRQ(WakeupTimer_IRQn);
	NVIC_EnableIRQ(TickerTimer_IRQn);
}

__reentrantb void wtimer_init(void) __reentrant
{
	wtimer_doinit(PMU->STS);
}

#endif /* __AXM0 */

#else // end of #if defined __ARMEL__ || defined __ARMEB__

static __reentrantb void wtimer_doinit(uint8_t wakeup) __reentrant
{
	IE_1 = 0;
	wtimer_pending = WTIMER_NULLCB;
	WTIRQEN = 0x21;
	if (wakeup) {
		if (SILICONREV == 0x8E && !(DBGLNKSTAT & 0x10))
			wtimer_state[0].time.ref = 0;
		wtimer0_update();
	} else {
		wtimer_state[0].time.ref = WTCNTA0;
		wtimer_state[0].time.ref |= ((uint16_t)WTCNTR1) << 8;
		wtimer_state[0].time.cur = 0;
		wtimer_state[0].queue = WTIMER_NULLDESC;
	}
	wtimer_state[1].time.ref = WTCNTB0;
	wtimer_state[1].time.ref |= ((uint16_t)WTCNTR1) << 8;
	wtimer_state[1].time.cur = 0;
	wtimer_state[1].queue = WTIMER_NULLDESC;
	wtimer0_schedq();
	wtimer1_schedq();
	IE_1 = 1;
}

__reentrantb void wtimer_init(void) __reentrant
{
	wtimer_doinit(PCON & 0x40);
}
#endif

__reentrantb void wtimer_init_deepsleep(void) __reentrant
{
	wtimer_doinit(0);
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer_addcb_core(struct wtimer_callback __xdata *desc) __reentrant
{
	struct wtimer_callback __xdata *d = WTIMER_CBPTR(wtimer_pending);
	for (;;) {
		struct wtimer_callback __xdata *dn = d->next;
		if (dn == WTIMER_NULLCB)
			break;
		d = dn;
	}
	d->next = (struct wtimer_callback __xdata *)desc;
	desc->next = WTIMER_NULLCB;
}

#if defined(WTIMER_USEASM) && defined(SDCC)

static void dummy2(void) __naked
{
	__asm;
	.area HOME   (CODE)
	__endasm;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_schedq(void) __reentrant
{
	__asm
	;; check wtimer_state[0].queue != WTIMER_NULL
	mov	dptr,#(_wtimer_state + 0x0006)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	cjne	r6,#(WTIMER_NULL & 0xFF),00000$
	cjne	r7,#(WTIMER_NULL >> 8),00000$
00001$:
	;; WTEVTA = wtimer_state[0].time.ref + (0x10000-WTIMER0_MARGIN)
	mov	dptr,#(_wtimer_state + 0x0004)
	movx	a,@dptr
	add	a,#((0x10000-WTIMER0_MARGIN) & 0xFF)
	mov	_WTEVTA0,a
	inc	dptr
	movx	a,@dptr
	addc	a,#((0x10000-WTIMER0_MARGIN) >> 8)
	mov	_WTEVTA1,a
	ret
00000$:
	;; R5:R4:R3:R2 = wtimer_state[0].time.cur - wtimer_state[0].queue->time;
	mov	dpl,r6
	mov	dph,r7
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
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
	mov	dptr,#(_wtimer_state + 0x0000)
	movx	a,@dptr
	clr	c
	subb	a,r2
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	subb	a,r3
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	subb	a,r4
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	subb	a,r5
	mov	r5,a
	jb	acc.7,00002$
	;; case R5:R4:R3:R2 >= 0
	;; wtimer_state[0].queue = wtimer_state[0].queue->next
	mov	dpl,r6
	mov	dph,r7
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#(_wtimer_state + 0x0006)
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	;; wtimer_addcb_core(old wtimer_state[0].queue)
	mov	dpl,r6
	mov	dph,r7
	lcall	_wtimer_addcb_core
	sjmp	_wtimer0_schedq
00002$:
	;; check R5:R4:R3:R2 < -(0x10000-WTIMER0_MARGIN)
	;; equivalent: (R5:R4:R3:R2 + (0x10000-WTIMER0_MARGIN)) < 0
	mov	a,r2
	add	a,#((0x10000-WTIMER0_MARGIN) & 0xFF)
	mov	a,r3
	addc	a,#((0x10000-WTIMER0_MARGIN) >> 8)
	clr	a
	addc	a,r4
	clr	a
	addc	a,r5
	jb	acc.7,00001$
	;; WTEVTA = wtimer_state[0].time.ref - R3:R2
	mov	dptr,#(_wtimer_state + 0x0004)
	movx	a,@dptr
	inc	dptr
	clr	c
	subb	a,r2
	mov	_WTEVTA0,a
	movx	a,@dptr
	subb	a,r3
	mov	_WTEVTA1,a
	ret
	__endasm;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_update(void) __reentrant __naked
{
	__asm
	mov	r2,_WTCNTA0
	mov	r3,_WTCNTR1
	mov	dptr,#(_wtimer_state + 0x0004)
	movx	a,@dptr
	xch	a,r2
	movx	@dptr,a
	inc	dptr
	clr	c
	subb	a,r2
	mov	r2,a
	movx	a,@dptr
	xch	a,r3
	movx	@dptr,a
	subb	a,r3
	mov	r3,a
	orl	a,ar2
	jz	00000$
	mov	dptr,#(_wtimer_state + 0x0000)
	movx	a,@dptr
	add	a,r2
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,r3
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0
	movx	@dptr,a
00000$:	ret
	__endasm;
}

static void dummy3(void) __naked
{
	__asm;
	.area CSEG   (CODE)
	__endasm;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_addcore(struct wtimer_desc __xdata *desc) __reentrant __naked
{
	__asm
	;; R5:R4 = &wtimer_state[0].queue
	mov	r4,#(_wtimer_state + 0x0006)
	mov	r5,#((_wtimer_state + 0x0006) >> 8)
_wtimer_addcore:
	;; R3:R2 = desc
	mov	r2,dpl
	mov	r3,dph
00000$:
	;; R7:R6 = R5:R4->next
	mov	dpl,r4
	mov	dph,r5
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	;; check R7:R6 != WTIMER_NULL
	cjne	r6,#(WTIMER_NULL & 0xFF),00002$
	cjne	r7,#(WTIMER_NULL >> 8),00002$
00001$:
	;; R3:R2->next = R7:R6
	mov	dpl,r2
	mov	dph,r3
	mov	a,r6
	movx	@dptr,a
	inc	dptr
	mov	a,r7
	movx	@dptr,a
	;; R5:R4->next = R3:R2
	mov	dpl,r4
	mov	dph,r5
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	ret
00002$:
	;; A.7 = sign (R3:R2->time - R7:R6->time)
	push	ar6
	push	ar7
	mov	dpl,r6
	mov	dph,r7
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
	clr	c
	movx	a,@dptr
	subb	a,r0
	inc	dptr
	movx	a,@dptr
	subb	a,r1
	inc	dptr
	movx	a,@dptr
	subb	a,r6
	inc	dptr
	movx	a,@dptr
	subb	a,r7
	jb	acc.7,00003$
	pop	ar5
	pop	ar4
	sjmp	00000$
00003$:
	pop	ar7
	pop	ar6
	sjmp	00001$
	__endasm;
}

static void dummy4(void) __naked
{
	__asm;
	.area HOME   (CODE)
	__endasm;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_schedq(void) __reentrant
{
	__asm
	;; check wtimer_state[1].queue != WTIMER_NULL
	mov	dptr,#(_wtimer_state + 0x000E)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	cjne	r6,#(WTIMER_NULL & 0xFF),00000$
	cjne	r7,#(WTIMER_NULL >> 8),00000$
00001$:
	;; WTEVTB = wtimer_state[1].time.ref + (0x10000-WTIMER1_MARGIN)
	mov	dptr,#(_wtimer_state + 0x000C)
	movx	a,@dptr
	add	a,#((0x10000-WTIMER1_MARGIN) & 0xFF)
	mov	_WTEVTB0,a
	inc	dptr
	movx	a,@dptr
	addc	a,#((0x10000-WTIMER1_MARGIN) >> 8)
	mov	_WTEVTB1,a
	ret
00000$:
	;; R5:R4:R3:R2 = wtimer_state[1].time.cur - wtimer_state[1].queue->time;
	mov	dpl,r6
	mov	dph,r7
	inc	dptr
	inc	dptr
	inc	dptr
	inc	dptr
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
	mov	dptr,#(_wtimer_state + 0x0008)
	movx	a,@dptr
	clr	c
	subb	a,r2
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	subb	a,r3
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	subb	a,r4
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	subb	a,r5
	mov	r5,a
	jb	acc.7,00002$
	;; case R5:R4:R3:R2 >= 0
	;; wtimer_state[1].queue = wtimer_state[1].queue->next
	mov	dpl,r6
	mov	dph,r7
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#(_wtimer_state + 0x000E)
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	;; wtimer_addcb_core(old wtimer_state[1].queue)
	mov	dpl,r6
	mov	dph,r7
	lcall	_wtimer_addcb_core
	sjmp	_wtimer1_schedq
00002$:
	;; check R5:R4:R3:R2 < -(0x10000-WTIMER1_MARGIN)
	;; equivalent: (R5:R4:R3:R2 + (0x10000-WTIMER1_MARGIN)) < 0
	mov	a,r2
	add	a,#((0x10000-WTIMER1_MARGIN) & 0xFF)
	mov	a,r3
	addc	a,#((0x10000-WTIMER1_MARGIN) >> 8)
	clr	a
	addc	a,r4
	clr	a
	addc	a,r5
	jb	acc.7,00001$
	;; WTEVTB = wtimer_state[1].time.ref - R3:R2
	mov	dptr,#(_wtimer_state + 0x000C)
	movx	a,@dptr
	inc	dptr
	clr	c
	subb	a,r2
	mov	_WTEVTB0,a
	movx	a,@dptr
	subb	a,r3
	mov	_WTEVTB1,a
	ret
	__endasm;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_update(void) __reentrant __naked
{
	__asm
	mov	r2,_WTCNTB0
	mov	r3,_WTCNTR1
	mov	dptr,#(_wtimer_state + 0x000C)
	movx	a,@dptr
	xch	a,r2
	movx	@dptr,a
	inc	dptr
	clr	c
	subb	a,r2
	mov	r2,a
	movx	a,@dptr
	xch	a,r3
	movx	@dptr,a
	subb	a,r3
	mov	r3,a
	orl	a,ar2
	jz	00000$
	mov	dptr,#(_wtimer_state + 0x0008)
	movx	a,@dptr
	add	a,r2
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,r3
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0
	movx	@dptr,a
00000$:	ret
	__endasm;
}

static void dummy5(void) __naked
{
	__asm;
	.area CSEG   (CODE)
	__endasm;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_addcore(struct wtimer_desc __xdata *desc) __reentrant __naked
{
	__asm
	;; R5:R4 = &wtimer_state[1].queue
	mov	r4,#(_wtimer_state + 0x000E)
	mov	r5,#((_wtimer_state + 0x000E) >> 8)
	ljmp	_wtimer_addcore
	__endasm;
}

static void wtimer_preparesleep(void) __naked
{
	__asm
	mov	_WTCFGB,#0x0F
	mov	_WTIRQEN,#0x01
	mov	dptr,#_SILICONREV
	movx	a,@dptr
	cjne	a,#0x8E,00000$
	;; R3:R2 = WTEVTA - wtimer_state[0].time.ref
	;; wtimer_state[0].time.ref = WTEVTA
	mov	dptr,#(_wtimer_state + 0x0004)
	mov	r2,_WTEVTA0
	movx	a,@dptr
	xch	a,r2
	movx	@dptr,a
	clr	c
	subb	a,r2
	mov	r2,a
	inc	dptr
	mov	r3,_WTEVTA1
	movx	a,@dptr
	xch	a,r3
	movx	@dptr,a
	subb	a,r3
	mov	r3,a
	mov	r4,#0
	;; check for LPXOSC source
	mov	a,_DBGLNKSTAT
	anl	a,#0x10
	jnz	00001$
	mov	a,_WTCFGA
	anl	a,#0x07
	cjne	a,#CLKSRC_LPXOSC,00001$
	mov	a,_WTCFGA
	swap	a
	rl	a
	anl	a,#0x07
	inc	a
	mov	r4,a
	mov	a,#((WTIMER_LPXOSC_SLEEP) << 2)
00002$:
	clr	c
	rrc	a
	djnz	r4,00002$
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	clr	a
	addc	a,r4
	mov	r4,a
00001$:
	;; wtimer_state[0].time.cur += R4:R3:R2
	mov	dptr,#(_wtimer_state + 0x0000)
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
	addc	a,#0
	movx	@dptr,a
00000$:
	ret
	__endasm;
}

static uint8_t wtimer_checkexpired(void) __naked
{
	__asm
	;; R3:R2 = WTEVTA1:WTEVTA0 - WTCNTR1:WTCNTA0 - 1
	setb	c
	mov	a,_WTEVTA0
	subb	a,_WTCNTA0
	mov	r2,a
	mov	a,_WTEVTA1
	subb	a,_WTCNTR1
	mov	r3,a
	;; R3:R2 + WTIMER0_MARGIN
	.if	(WTIMER0_MARGIN & 0xFF)
	mov	a,#(WTIMER0_MARGIN & 0xFF)
	add	a,r2
	mov	a,#(WTIMER0_MARGIN >> 8)
	addc	a,r3
	.else
	mov	a,#(WTIMER0_MARGIN >> 8)
	add	a,r3
	.endif
	jc	00000$
	;; R3:R2 = WTEVTB1:WTEVTB0 - WTCNTR1:WTCNTB0 - 1
	setb	c
	mov	a,_WTEVTB0
	subb	a,_WTCNTB0
	mov	r2,a
	mov	a,_WTEVTB1
	subb	a,_WTCNTR1
	mov	r3,a
	;; R3:R2 + WTIMER1_MARGIN
	.if	(WTIMER1_MARGIN & 0xFF)
	mov	a,#(WTIMER1_MARGIN & 0xFF)
	add	a,r2
	mov	a,#(WTIMER1_MARGIN >> 8)
	addc	a,r3
	.else
	mov	a,#(WTIMER1_MARGIN >> 8)
	add	a,r3
	.endif
	jc	00000$
	;; check WTSTAT & 0x21
	mov	a,_WTSTAT
	anl	a,#0x21
	jnz	00000$
	mov	dpl,a
	ret
00000$:
	mov	dpl,#1
	ret
	__endasm;
}

#elif defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0F2

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_update(void) __reentrant
{
	uint16_t __autodata t = WCO->WDT_CTRLOW;
	{
		uint16_t __autodata t1 = wtimer_state[0].time.ref;
		wtimer_state[0].time.ref = t;
		t -= t1;
	}
	if (!t)
		return;
	wtimer_state[0].time.cur += t;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_addcore(struct wtimer_desc __xdata *desc) __reentrant
{
	struct wtimer_desc __xdata * __autodata d = WTIMER_PTR(wtimer_state[0].queue);
	for (;;) {
		struct wtimer_desc __xdata * __autodata dn = d->next;
		int32_t __autodata td;
		if (dn == WTIMER_NULLDESC)
			break;
		td = desc->time - dn->time;
		if (td < 0)
			break;
		d = dn;
	}
	desc->next = d->next;
	d->next = desc;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_schedq(void) __reentrant
{
	static uint16_t prv_wdtmatch_wrt = 0;
	uint16_t nxt;

	while (wtimer_state[0].queue != WTIMER_NULLDESC) {
		int32_t __autodata td = wtimer_state[0].time.cur - wtimer_state[0].queue->time;
		if (td >= 0) {
			struct wtimer_callback __xdata * __autodata d = (struct wtimer_callback __xdata *)wtimer_state[0].queue;
			wtimer_state[0].queue = wtimer_state[0].queue->next;
			wtimer_addcb_core(d);
			continue;
		}
		if (td < -(0x10000-WTIMER0_MARGIN))
			break;
		{
			nxt = wtimer_state[0].time.ref - (uint16_t)td;

			/* If nxt is duplicate of WDT_MATCH, no action required*/
			if (nxt == WCO->WDT_MATCH)
			{
				return;
			}

			goto WRITE_MATCH; /* Handle delay between two WDT_MATCH write and before sleep, if required */
		}
	}
	{
		nxt = wtimer_state[0].time.ref + (uint16_t)(0x10000-WTIMER0_MARGIN);

		/* If trying to re-schedule with in WTIMER0_MARGIN, no action required */
		if (((nxt - WCO->WDT_MATCH) & 0xffff) <= WTIMER0_MARGIN)
		{
			return;
		}

WRITE_MATCH: /* Handles delay between two WDT_MATCH write and before sleep, if required */

		/* Remove wdt_match delay if any */
		wtimer1_remove(&wdt_match_delay);

		/* Check if time between previous write and present write is minimum 5 LFCLK cycle */
		if ((((wtimer_state[0].time.cur - prv_wdtmatch_wrt) & 0xffff) >= AXM0F2_WDT_WRITE_DELAY_LFCLK) &&
			(((nxt - wtimer_state[0].time.cur) & 0xffff) >= AXM0F2_WDT_WRITE_DELAY_LFCLK))
		{
			/* 5 LFCLK cycle delay is there, write WDT_MATCH register */
			WCO->WDT_MATCH = nxt;

			/* Take present write time snapshot */
			prv_wdtmatch_wrt = wtimer_state[0].time.cur;


			/* Set wdt_match sleep delay time to 2LFCLK cycle */
			wdt_match_delay.time = (AXM0F2_WDT_WRITE_SLEEP_DELAY_LFCLK *
								   ((AXM0XX_HFCLK_CLOCK_FREQ >> wtimer1_prescaler) /
									AXM0_FREQ_LPOSC_40K));

			wdt_match_delay.handler = wdt_match_sleep_delay_callback; /* Set handler for wdt_match sleep delay */

			/* Add descriptor to maintain 2 LFCLK cycle delay before entering sleep after WDT_MATCH write */
			wtimer1_addrelative(&wdt_match_delay);

			return;
		}

		/* Time between two WDT_MATCH register write is less than 5 LFCLK cycle */
		uint16_t wt1_wdt_match_cnt = nxt - wtimer_state[0].time.cur; /* Time required to delay the WDT_MATCH write */

		if (wt1_wdt_match_cnt > AXM0F2_WDT_WRITE_DELAY_LFCLK)
		{
			wt1_wdt_match_cnt = AXM0F2_WDT_WRITE_DELAY_LFCLK; /* Ceil delay to max 5 LFCLK cycle */
		}

		/* Update minimum delay required before writing to WDT_MATCH register */
		wdt_match_delay.time = (wt1_wdt_match_cnt *
							   ((AXM0XX_HFCLK_CLOCK_FREQ >> wtimer1_prescaler) /
							   AXM0_FREQ_LPOSC_40K));

		wdt_match_delay.handler = wdt_match_delay_callback; /* Set handler for wdt_match delay */

		/* Add wdt_match_delay descriptor */
		wtimer1_addrelative(&wdt_match_delay);
	}
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_update(void) __reentrant
{
	uint16_t __autodata t = TCPWM_CNT4->COUNTER;
	{
		uint16_t __autodata t1 = wtimer_state[1].time.ref;
		wtimer_state[1].time.ref = t;
		t -= t1;
	}
	if (!t)
		return;
	wtimer_state[1].time.cur += t;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_addcore(struct wtimer_desc __xdata *desc) __reentrant
{
	struct wtimer_desc __xdata * __autodata d = WTIMER_PTR(wtimer_state[1].queue);
	for (;;) {
		struct wtimer_desc __xdata * __autodata dn = d->next;
		int32_t __autodata td;
		if (dn == WTIMER_NULLDESC)
			break;
		td = desc->time - dn->time;
		if (td < 0)
			break;
		d = dn;
	}
	desc->next = d->next;
	d->next = desc;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_schedq(void) __reentrant
{
	while (wtimer_state[1].queue != WTIMER_NULLDESC) {
		int32_t __autodata td = wtimer_state[1].time.cur;
 		td -= wtimer_state[1].queue->time;
		if (td >= 0) {
			struct wtimer_callback __xdata * __autodata d = (struct wtimer_callback __xdata *)wtimer_state[1].queue;
			wtimer_state[1].queue = wtimer_state[1].queue->next;
			wtimer_addcb_core(d);
			continue;
		}
		if (td < -(0x10000-WTIMER1_MARGIN))
			break;
		{
			uint16_t __autodata nxt = wtimer_state[1].time.ref - (uint16_t)td;
			TCPWM_CNT4->CC = nxt;
		}

		return;
	}
	{
		uint16_t __autodata nxt = wtimer_state[1].time.ref + (uint16_t)(0x10000-WTIMER1_MARGIN);
		TCPWM_CNT4->CC = nxt;
	}
}

static __reentrantb void wtimer_preparesleep(void) __reentrant
{
	NVIC_DisableIRQ(TCPWM4_IRQn);
	TCPWM->CTRL &= ~0x00000010;
	PERI->PCLK_CTL8 = 0x000000FF;
}

static __reentrantb uint8_t wtimer_checkexpired(void) __reentrant
{
	{
		uint16_t __autodata t = WCO->WDT_CTRLOW;
		t -= WCO->WDT_MATCH;
		if (t < WTIMER0_MARGIN)
			return 1;
	}
	if (WCO->WDT_CONTROL & 0x00000004)
		return 1;
	{
		uint16_t __autodata t = TCPWM_CNT4->COUNTER;
		t -= TCPWM_CNT4->CC;
		if (t < WTIMER0_MARGIN)
			return 1;
	}
	if (TCPWM_CNT4->INTR_MASKED & 0x00000002)
		return 1;
	return 0;
}

#else

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_update(void) __reentrant
{
	/* This function is empty for compatibility reasons */
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_addcore(struct wtimer_desc __xdata *desc) __reentrant
{
	struct wtimer_desc __xdata * __autodata d = WTIMER_PTR(wtimer_state[0].queue);
	for (;;) {
		struct wtimer_desc __xdata * __autodata dn = d->next;
		int32_t __autodata td;
		if (dn == WTIMER_NULLDESC)
			break;
		td = desc->time - dn->time;
		if (td < 0)
			break;
		d = dn;
	}
	desc->next = d->next;
	d->next = desc;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_schedq(void) __reentrant
{
	uint32_t curtime = WUT->WTCNT;
	while (wtimer_state[0].queue != WTIMER_NULLDESC) {
		int32_t __autodata td = 0;
		td = curtime - wtimer_state[0].queue->time;
		if (td >= 0) {
			struct wtimer_callback __xdata * __autodata d = (struct wtimer_callback __xdata *)wtimer_state[0].queue;
			wtimer_state[0].queue = wtimer_state[0].queue->next;
			wtimer_addcb_core(d);
			continue;
		}
		WUT->WTEVT = curtime - td;
		WUT->WTCFG_b.WTIRQE = 0x1;
		return;
	}
	if (WUT->WTSTS)
	{
		WUT->WTEVT = 0x0;
		WUT->WTSTS = 0x1;
	}
	WUT->WTCFG_b.WTIRQE = 0x0;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_update(void) __reentrant
{
    /* Empty API for compatibility reasons */
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_addcore(struct wtimer_desc __xdata *desc) __reentrant
{
	struct wtimer_desc __xdata * __autodata d = WTIMER_PTR(wtimer_state[1].queue);
	for (;;) {
		struct wtimer_desc __xdata * __autodata dn = d->next;
		int32_t __autodata td;
		if (dn == WTIMER_NULLDESC)
			break;
		td = desc->time - dn->time;
		if (td < 0)
			break;
		d = dn;
	}
	desc->next = d->next;
	d->next = desc;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_schedq(void) __reentrant
{
	uint32_t curtime = TICKER->TTCNT;
	while (wtimer_state[1].queue != WTIMER_NULLDESC) {
		int32_t __autodata td = 0;
		td = curtime - wtimer_state[1].queue->time;
		if (td >= 0) {
			struct wtimer_callback __xdata * __autodata d = (struct wtimer_callback __xdata *)wtimer_state[1].queue;
			wtimer_state[1].queue = wtimer_state[1].queue->next;
			wtimer_addcb_core(d);
			continue;
		}
		TICKER->TTEVT = curtime - td;
		TICKER->TTCFG_b.TTIRQE = 0x1;
		return;
	}
	if (TICKER->TTSTS)
	{
		TICKER->TTEVT = 0x0;
		TICKER->TTSTS = 0x1;
	}
	TICKER->TTCFG_b.TTIRQE = 0x0;
}

static __reentrantb void wtimer_preparesleep(void) __reentrant
{
	/* Clear out the ticker timer settings for entering Nebo hibernate mode */
	TICKER->TTCFG = 0xF;
}

static __reentrantb uint8_t wtimer_checkexpired(void) __reentrant
{
	return WUT->WTSTS || TICKER->TTSTS;
}

#endif

#else

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_update(void) __reentrant
{
	uint16_t __autodata t;
	t = WTCNTA0;
	t |= ((uint16_t)WTCNTR1) << 8;
	{
		uint16_t __autodata t1 = wtimer_state[0].time.ref;
		wtimer_state[0].time.ref = t;
		t -= t1;
	}
	if (!t)
		return;
	wtimer_state[0].time.cur += t;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_addcore(struct wtimer_desc __xdata *desc) __reentrant
{
	struct wtimer_desc __xdata * __autodata d = WTIMER_PTR(wtimer_state[0].queue);
	for (;;) {
		struct wtimer_desc __xdata * __autodata dn = d->next;
		int32_t __autodata td;
		if (dn == WTIMER_NULLDESC)
			break;
		td = desc->time - dn->time;
		if (td < 0)
			break;
		d = dn;
	}
	desc->next = d->next;
	d->next = desc;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer0_schedq(void) __reentrant
{
	while (wtimer_state[0].queue != WTIMER_NULLDESC) {
		int32_t __autodata td = wtimer_state[0].time.cur - wtimer_state[0].queue->time;
		if (td >= 0) {
			struct wtimer_callback __xdata * __autodata d = (struct wtimer_callback __xdata *)wtimer_state[0].queue;
			wtimer_state[0].queue = wtimer_state[0].queue->next;
			wtimer_addcb_core(d);
			continue;
		}
		if (td < -(0x10000-WTIMER0_MARGIN))
			break;
		{
			uint16_t __autodata nxt = wtimer_state[0].time.ref - (uint16_t)td;
			WTEVTA0 = nxt;
			WTEVTA1 = nxt >> 8;
		}
		return;
	}
	{
		uint16_t __autodata nxt = wtimer_state[0].time.ref + (uint16_t)(0x10000-WTIMER0_MARGIN);
		WTEVTA0 = nxt;
		WTEVTA1 = nxt >> 8;
	}
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_update(void) __reentrant
{
	uint16_t __autodata t;
	t = WTCNTB0;
	t |= ((uint16_t)WTCNTR1) << 8;
	{
		uint16_t __autodata t1 = wtimer_state[1].time.ref;
		wtimer_state[1].time.ref = t;
		t -= t1;
	}
	if (!t)
		return;
	wtimer_state[1].time.cur += t;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_addcore(struct wtimer_desc __xdata *desc) __reentrant
{
	struct wtimer_desc __xdata * __autodata d = WTIMER_PTR(wtimer_state[1].queue);
	for (;;) {
		struct wtimer_desc __xdata * __autodata dn = d->next;
		int32_t __autodata td;
		if (dn == WTIMER_NULLDESC)
			break;
		td = desc->time - dn->time;
		if (td < 0)
			break;
		d = dn;
	}
	desc->next = d->next;
	d->next = desc;
}

// Must be called with (wtimer) interrupts disabled
__reentrantb void wtimer1_schedq(void) __reentrant
{
	while (wtimer_state[1].queue != WTIMER_NULLDESC) {
		int32_t __autodata td = wtimer_state[1].time.cur;
 		td -= wtimer_state[1].queue->time;
		if (td >= 0) {
			struct wtimer_callback __xdata * __autodata d = (struct wtimer_callback __xdata *)wtimer_state[1].queue;
			wtimer_state[1].queue = wtimer_state[1].queue->next;
			wtimer_addcb_core(d);
			continue;
		}
		if (td < -(0x10000-WTIMER1_MARGIN))
			break;
		{
			uint16_t __autodata nxt = wtimer_state[1].time.ref - (uint16_t)td;
			WTEVTB0 = nxt;
			WTEVTB1 = nxt >> 8;
		}

		return;
	}
	{
		uint16_t __autodata nxt = wtimer_state[1].time.ref + (uint16_t)(0x10000-WTIMER1_MARGIN);
		WTEVTB0 = nxt;
		WTEVTB1 = nxt >> 8;
	}
}


static __reentrantb void wtimer_preparesleep(void) __reentrant
{
	uint16_t __autodata t;
	WTCFGB = 0x0F;
	WTIRQEN = 0x01;
	if (SILICONREV != 0x8E)
		return;
	t = WTEVTA0;
	t |= ((uint16_t)WTEVTA1) << 8;
	{
		uint16_t t1 = wtimer_state[0].time.ref;
		wtimer_state[0].time.ref = t;
		t -= t1;
	}
	if (!(DBGLNKSTAT & 0x10))
		if ((WTCFGA & 0x07) == CLKSRC_LPXOSC)
			t += (((uint8_t)(WTIMER_LPXOSC_SLEEP)) << 1) >> ((WTCFGA >> 3) & 0x07);
	wtimer_state[0].time.cur += t;
}

static __reentrantb uint8_t wtimer_checkexpired(void) __reentrant
{
	{
		uint16_t __autodata t;
		t = WTCNTA0;
		t |= ((uint16_t)WTCNTR1) << 8;
		t -= WTEVTA0 | (((uint16_t)WTEVTA1) << 8);
		if (t < WTIMER0_MARGIN)
			return 1;
	}
	{
		uint16_t __autodata t;
		t = WTCNTB0;
		t |= ((uint16_t)WTCNTR1) << 8;
		t -= WTEVTB0 | (((uint16_t)WTEVTB1) << 8);
		if (t < WTIMER1_MARGIN)
			return 1;
	}
	if (WTSTAT & 0x21)
		return 1;
	return 0;
}

#endif

#if defined(SDCC)
extern __reentrantb uint8_t wtimer_cansleep(void) __reentrant;

static void wtimer_cansleep_dummy(void) __naked
{
	__asm
	.area HOME      (CODE)
	.area WTCANSLP0 (CODE)
	.area WTCANSLP1 (CODE)
	.area WTCANSLP2 (CODE)

	.area WTCANSLP0 (CODE)
_wtimer_cansleep_ret0:
	mov	dpl,#0x00
	ret

	.globl	_wtimer_cansleep
_wtimer_cansleep:
	;; wtimer_state[1].queue == WTIMER_NULLDESC
	mov	dptr,#(_wtimer_state + 0x000e)
	movx	a,@dptr
	cpl	a
	jnz	_wtimer_cansleep_ret0
	inc	dptr
	movx	a,@dptr
	cpl	a
	jnz	_wtimer_cansleep_ret0

	.area WTCANSLP2 (CODE)
	mov	dpl,#0x01
	ret

	.area HOME     (CODE)
	.area WTSTDBY0 (CODE)
	.area WTSTDBY1 (CODE)
	.area WTSTDBY2 (CODE)

	.area WTSTDBY1 (CODE)
	push	ar0
	push	ar1
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	lcall	_wtimer_runcallbacks
	mov	dpl,#WTFLAG_CANSTANDBY
	lcall	_wtimer_idle
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	pop	ar1
	pop	ar0
	ret

	.area CSEG      (CODE)
	__endasm;
}

#else

__reentrantb uint8_t wtimer_cansleep(void) __reentrant
{
	return (wtimer_state[1].queue == WTIMER_NULLDESC);
}

#endif

__reentrantb uint8_t wtimer_idle(uint8_t flags) __reentrant
{
	criticalsection_t crit = enter_critical();
	if (wtimer_pending != WTIMER_NULLCB || wtimer_checkexpired()) {
		exit_critical(crit);
		return WTIDLE_WORK;
	}
	if (flags & WTFLAG_CANSLEEPANY && wtimer_cansleep()) {
		wtimer_preparesleep();
#if defined __ARMEL__ || defined __ARMEB__
		/* TODO: Fix SRAM powerdown for RevB. */
#else
		// FIXME: copy wtimer_state[0] to IRAM if there are not too many cb's?
		if ((void __xdata *)(&wtimer_state[0]) < (void __xdata *)0x1000)
			PCON = (PCON & 0x0C) | 0x04;
		if ((void __xdata *)(&wtimer_state[0]) >= (void __xdata *)(0x1000-sizeof(wtimer_state[0])))
			PCON = (PCON & 0x0C) | 0x08;
#endif
#if defined(SDCC) || defined(__ICC8051__) || ((defined __ARMEL__ || defined __ARMEB__) && defined __AXM0F2)
		if (flags & WTFLAG_CANSLEEPCONT) {
			enter_sleep_cont();
			exit_critical(crit);
			return WTIDLE_SLEEP;
		}
#endif
		enter_sleep();
	} else if (flags & WTFLAG_CANSTANDBY) {
		enter_standby();
	}
	exit_critical(crit);
	return 0;
}

/*
 * This function is reentrant even though it is not marked reentrant.
 * When marked reentrant, code generation gets worse for SDCC
 * (IE is placed on stack rather than a register)
 */

#if defined(SDCC)
#pragma nooverlay
uint8_t wtimer_runcallbacks(void)
#elif defined(__ICC8051__)
uint8_t wtimer_runcallbacks(void)
#else
__reentrantb uint8_t wtimer_runcallbacks(void) __reentrant
#endif
{
	uint8_t __autodata ret = 0;
	for (;;) {
		criticalsection_t __autodata crit = enter_critical();
		wtimer0_update();
		wtimer0_schedq();
		wtimer1_update();
		wtimer1_schedq();
		for (;;) {
			{
				struct wtimer_callback __xdata * __autodata d = wtimer_pending;
				if (d != WTIMER_NULLCB) {
					wtimer_pending = d->next;
					exit_critical(crit);
					++ret;
					((handler_t)(d->handler))(d);
					reenter_critical();
					continue;
				}
			}
			{
				uint8_t __autodata exp = wtimer_checkexpired();
				exit_critical(crit);
				if (exp)
					break;
				return ret;
			}
		}
	}
}
