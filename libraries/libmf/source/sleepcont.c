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

#include "cpu.h"
#include "libmftypes.h"

#if defined(SDCC)

#define REGTABLE_SIG0 0xBE
#define REGTABLE_SIG1 0x37

/**
 * \brief enter sleep mode, continue after call
 *
 */
__reentrantb void enter_sleep_cont(void) __reentrant __naked
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
	mov     @r0,#REGTABLE_SIG0
	dec     r0
	mov     @r0,#REGTABLE_SIG1
	dec     r0
	mov     @r0,sp
	mov     a,_PCON
	anl     a,#0x0c
	orl     a,#0x02
	mov     _PCON,a
	mov     _CODECONFIG,#0xd3
	ljmp    0xe047
	__endasm;
}

static void dummy(void) __naked
{
	__asm
	.area CSEG    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)

	.area GSINIT1 (CODE)
	mov     r0,#0xff
	mov     a,_PCON
	jb      acc.6,00001$
	clr     a
	mov     @r0,a
	dec     r0
	mov     @r0,a
	sjmp    00000$
00001$:
	cjne    @r0,#REGTABLE_SIG0,00000$
	dec     r0
	cjne    @r0,#REGTABLE_SIG1,00000$
	dec     r0
	mov     sp,@r0
	ljmp    __sdcc_external_startup
00000$:
	__endasm;
}

#elif defined(__ICC8051__)

__reentrantb void enter_sleep_cont(void) __reentrant
{
        for (;;) {
                RADIOMUX &= (uint8_t)~0x40;
                __disable_irq();
                EIE = 0x00;
                E2IE = 0x00;
		asm("mov     r0,#0xff");
		asm("mov     @r0,#0xBE");
		asm("dec     r0");
		asm("mov     @r0,#0x37");
		asm("dec     r0");
		asm("mov     @r0,sp");
                GPIOENABLE = 0;
                PCON = 0x02 | (PCON & 0x0C);
                CODECONFIG = 0xD3;
                asm("ljmp    0xE047");
        }
}

#elif defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0F2 // FIXME

__reentrantb void enter_sleep_cont(void) __reentrant
{
#ifdef __AXM0
	/* Power up the PMU clock */
	CMU_OR->PCLK_CFG = CMU_PCLK_CFG_PMU_EN_Msk;

	/* Set the power mode register 0x40400000 to 0x1 */
	PMU->MOD = PMU_MOD_HIBERNATE_Msk;

	// FIXME: save state, mechanism in crt startup to restore chip state
#endif
#ifdef __AXM0F2
	uint8_t clksel = SRSSLT->CLK_SELECT;
	SRSSLT->CLK_SELECT |= 0xC0;
	//SRSSLT->CLK_SELECT |= 0xCC;
	//__IOM uint32_t  DIV_16_CTL0
#endif

	/* Set the SCB SCR 2 bit to 1 */
	SCB->SCR = 0x4;

	/* Instruction Synchronization Barrier */
	__ISB();

	/* CM0+ to sleep */
	__WFI();

#ifdef __AXM0F2
	SRSSLT->CLK_SELECT = clksel;
#endif
}

#endif

#endif
