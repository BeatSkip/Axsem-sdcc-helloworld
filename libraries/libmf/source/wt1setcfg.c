/**
******************************************************************************
* @file wt1setcfg.c
* @brief Timer 1 APIs
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

#if defined __ARMEL__ || defined __ARMEB__
#include "axm0_config.h"

#ifdef __AXM0F2
#include "libmfosc.h"

__reentrantb void wtimer1_setclksrc(uint8_t clksrc, uint8_t prescaler) __reentrant
{
	wtimer1_clksrc = clksrc;
	wtimer1_prescaler = prescaler;
	uint32_t ctrl = TCPWM->CTRL & 0x00000010;
	TCPWM->CTRL &= ~0x00000010;
	SET_BIT_FIELDS(TCPWM_CNT4->CTRL, 0x00000700, (prescaler << 8));
	TCPWM->CTRL |= ctrl;
	TCPWM->CMD |= ctrl << 24;
}

#elif defined __AXM0

__reentrantb void wtimer1_setclksrc(uint8_t clksrc, uint8_t prescaler) __reentrant
{
	CMU->PCLK_CFG_b.CL_SYSCFG_EN = 0x1;
	CMU->PCLK_CFG_b.XBAR_EN = 0x1;

	if (clksrc == CLKSRC_FRCOSC) {
		/* Enable FRC OSC */
		CMU->CFG_b.HS_OSC_PD = 0x0;
	} else if (clksrc == CLKSRC_LPOSC) {
		/* Enable LP OSC */
		CMU->CFG_b.LP_OSC_PD = 0x0;
	} else if (clksrc == CLKSRC_XOSC) {
		/* Enable HS XTAL */
		CMU->CFG_b.HS_XOSC_PD = 0x0;

		/** TODO - Bring out HS XTAL on PA0 and PA1
		    Configure the crossbar to disable pull downs
		    Set pins PA0 and PA1 for HS XTAL */

		/* Wait till the XTAL is ready */
		while (CMU->OSC_ON_STS_b.HS_XOSC != 0x1);
	} else if (clksrc == CLKSRC_LPXOSC) {
		/* Disable pull ups and pull downs on XTAL lines */
		//XBAR->PULL_DOWN_CFG = AXM0_CONFIG_XBAR_LPXTAL_PD;

		/* Set the pins PA3 and PA4 for LPXTAL */
		//XBAR->PA_CFG = AXM0_CONFIG_XBAR_LPXTAL;

		/* Disable pull ups and pull downs on XTAL lines */
		XBAR->PULL_DOWN_CFG_b.PA3 = 0x0;
		XBAR->PULL_DOWN_CFG_b.PA4 = 0x0;

		/* Set the pins PA3 and PA4 for LPXTAL */
		XBAR->PA_CFG_b.PA3 = 0x0;
		XBAR->PA_CFG_b.PA4 = 0x0;

		/* Enable LP XTAL */
		CMU->CFG_b.LP_XOSC_PD = 0x0;

		while(CMU->OSC_READY_STS_b.LP_XOSC != 0x1);
	} else {
		/* Do Nothing for RSYS_CLK */
	}

	wtimer1_setconfig((clksrc & 0x07) | ((prescaler & 0x07) << 3));
}

__reentrantb void wtimer1_setconfig(uint8_t cfg) __reentrant
{

	/* Enable the ticker timer peripheral clock */
	CMU->PCLK_CFG_b.TICKER_EN = 0x1;

	/* Check if the settings are unchanged */
	if (!((TICKER->TTCFG ^ cfg) & 0x3F))
		return;

	/* Write the clock source and prescalar values in config register */
	TICKER->TTCFG = (cfg & 0x3F);
}

#endif

#else

__reentrantb void wtimer1_setconfig(uint8_t cfg) __reentrant
{
	if (!((WTCFGB ^ cfg) & 0x3F))
		return;
	cfg &= 0x3F;
	WTCFGB |= 0x04;
	WTCFGB = 0x0F;
	WTCFGB &= cfg | 0xFC;
	WTCFGB = cfg;
}

#endif
