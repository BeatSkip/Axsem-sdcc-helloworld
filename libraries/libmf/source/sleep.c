/**
******************************************************************************
* @file sleep.c
* @brief PMU hibernate mode APIs
* @internal
* @author   Thomas Sailer, Radhika Raghavendran, Pradeep Kumar GR
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
* @ingroup pmu
*
* @details
*/

#include "cpu.h"
#include "libmftypes.h"

#ifdef SDCC

/**
 * \brief enter sleep mode
 *
 */
__reentrantb void enter_sleep(void) __reentrant __naked
{
	__asm
	mov     dptr,#_RADIOMUX
	movx    a,@dptr
	anl     a,#~0x40
	movx    @dptr,a
	clr     _EA
	clr     a
	mov     _EIE,a
	mov     _E2IE,a
	mov     dptr,#_GPIOENABLE
	movx    @dptr,a
	mov     r0,#0xff
	mov     @r0,a
	dec     r0
	mov     @r0,a
	mov     a,_PCON
	anl     a,#0x0c
	orl     a,#0x02
	mov     _PCON,a
	mov     _CODECONFIG,#0xd3
	ljmp    0xe047
	__endasm;
}

#elif defined __CX51__ || defined __C51__

__reentrantb void enter_sleep(void) __reentrant
{
	for (;;) {
		RADIOMUX &= (uint8_t)~0x40;
		__disable_irq();
		EIE = 0x00;
		E2IE = 0x00;
		GPIOENABLE = 0;
		PCON = 0x02 | (PCON & 0x0C);
		CODECONFIG = 0xD3;
#pragma asm
		ljmp 0xE047
#pragma endasm
	}
}

#elif defined __ICC8051__

__noreturn __reentrantb void enter_sleep(void) __reentrant
{
	for (;;) {
		RADIOMUX &= (uint8_t)~0x40;
		__disable_irq();
		EIE = 0x00;
		E2IE = 0x00;
		asm("clr     a");
		asm("mov     r0,#0xff");
		asm("mov     @r0,a");
		asm("dec     r0");
		asm("mov     @r0,a");
		GPIOENABLE = 0;
		PCON = 0x02 | (PCON & 0x0C);
		CODECONFIG = 0xD3;
		asm("ljmp 0xE047");
	}
}

#elif defined __ARMEL__ || defined __ARMEB__

extern uint32_t __StackTop;

#ifdef __AXM0F2
#include "axm0_config.h"

extern uint8_t __startcause;
extern void Reset_Handler_NoStartCause(void) __attribute__((noreturn));

static inline void jump_reset(void) __attribute__((noreturn));

static inline void jump_reset(void)
{
	asm("mov\tsp, %0\n\tmov\tpc, %1"									/* copy __StackTop to sp and Reset_Handler_NoStartCause to pc */
                :														/* No output operator */
                : "r" (&__StackTop), "r" (&Reset_Handler_NoStartCause)	/* Input operator */
                :														/* No clobbers */
     );
}

#endif

__reentrantb void enter_sleep(void) __attribute__((noreturn)) __reentrant;

__reentrantb void enter_sleep(void) __reentrant
{
	__disable_irq();
#ifdef __AXM0
	/* Power up the PMU clock */
	CMU_OR->PCLK_CFG = CMU_PCLK_CFG_PMU_EN_Msk;

	/* Set the power mode register 0x40400000 to 0x1 */
	PMU->MOD = PMU_MOD_HIBERNATE_Msk;
#endif
#ifdef __AXM0F2
	uint8_t clksel = SRSSLT->CLK_SELECT;
	SRSSLT->CLK_SELECT |= 0xC0;

	SET_BIT_FIELDS(GPIO_PRT2->PC, (7 << 18), (3 << 18)); /* Fix: To avoid extra current consumption in low power mode, weak pull down and strong pull up on MISO line */
#endif

	/* Set the SCB SCR 2 bit to 1 */
	SCB->SCR = 0x4;

	/* Instruction Synchronization Barrier */
	__ISB();

	/* CM0+ to sleep */
	__WFI();

#ifdef __AXM0F2
	SRSSLT->CLK_SELECT = clksel;
	__startcause = STARTCAUSE_WAKEUPSLEEP;
	GPIO_PRT2->PC |= (7 << 18); /* Restore MISO line back to weak pull down and weak pull up */
	jump_reset();
#endif
}

#else

#error "Compiler unsupported"

#endif
