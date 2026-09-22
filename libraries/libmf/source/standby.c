/**
******************************************************************************
* @file standby.c
* @brief PMU sleep mode functions
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
* @ingroup pmu
*
* @details
*/
#include "cpu.h"
#include "libmftypes.h"

#if defined(SDCC)

/**
 * \brief enter standby mode
 *
 */

__reentrantb void enter_standby(void) __reentrant __naked
{
	__asm
	mov	a,_PCON
	anl	a,#0x0C
	orl	a,#0x01
	mov	_PCON,a
	nop
	ret
	nop
	nop
	nop
	nop
	nop
	__endasm;
}

#elif 0 && (defined(__CX51__) || defined(__C51__))

__reentrantb void enter_standby(void) __reentrant
{
#pragma asm
	mov	a,_PCON
	anl	a,#0x0C
	orl	a,#0x01
	mov	_PCON,a
	nop
	ret
	nop
	nop
	nop
	nop
	nop
#pragma endasm
}

#elif defined __ARMEL__ || defined __ARMEB__

__reentrantb void enter_standby(void) __reentrant
{
#ifdef __AXM0
	/* Power up the PMU clock */
	CMU_OR->PCLK_CFG = CMU_PCLK_CFG_PMU_EN_Msk;
	CMU->PCLK_CFG_b.CL_SYSCFG_EN = 0x1;

	/* TODO : AXM0_REVA */
	CMU->CFG_b.SYS_CLK_DIV = 0x3;

	/* Set the power mode register 0x40400000 to 0x0 */
	PMU->MOD = PMU_MOD_CM0LP_Msk;
#endif
#ifdef __AXM0F2
	GPIO_PRT2->PC = (GPIO_PRT2->PC & (~(7 << 18))) | (3 << 18);    /* Fix: To avoid extra current consumption in low power mode, weak pull down and strong pull up on MISO line */
#endif

	/* Set the cortex M0+ SCR register 0xE000ED10 to 0x0 */
	SCB->SCR = 0x00000000;

	/* Instruction Synchronization Barrier */
	__ISB();

	/* CM0+ to standby */
	__WFI();

#ifdef __AXM0
	/* TODO: AXM0_REVA */
	CMU->CFG_b.SYS_CLK_DIV = 0x0;
#endif
#ifdef __AXM0F2
	GPIO_PRT2->PC |= (7 << 18); /* Restore MISO line back to weak pull down and weak pull up */
#endif
}

#else

__reentrantb void enter_standby(void) __reentrant
{
	PCON = (PCON & 0x0C) | 0x01;
	nop();
	nop();
	nop();
	nop();
	nop();
	nop();
	nop();
}

#endif
