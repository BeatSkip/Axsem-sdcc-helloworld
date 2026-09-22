/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer, Pradeep Kumar GR
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
#include "libmfosc.h"

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0

/**
 * \brief set up LPXOSC
 *
 */

__reentrantb void setup_lpxosc(void) __reentrant
{
	/* Enable CMU and XBAR */
	CMU_OR->PCLK_CFG = CMU_PCLK_CFG_XBAR_EN_Msk | CMU_PCLK_CFG_CL_SYSCFG_EN_Msk;

	/* Disable pull ups and pull downs on XTAL lines */
	XBAR->PULL_DOWN_CFG = AXM0_CONFIG_XBAR_LPXTAL_PD;

	/* Set the pins PA3 and PA4 for LPXTAL */
	XBAR->PA_CFG = AXM0_CONFIG_XBAR_LPXTAL;

	/* Enable LP XTAL */
	CMU->CFG_b.LP_XOSC_PD = 0x0;

	while(CMU->OSC_READY_STS_b.LP_XOSC != 0x1);
}

#endif

#else

/**
 * \brief set up LPXOSC
 *
 */

__reentrantb void setup_lpxosc(void) __reentrant
{
	ANALOGA |= 0x18;
	DIRA &= (uint8_t)~0x18;
	PORTA &= (uint8_t)~0x18;
	MISCCTRL &= (uint8_t)~0x01;
}

#endif
