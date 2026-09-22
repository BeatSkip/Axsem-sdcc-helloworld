/**
******************************************************************************
* @file wt0setcfg.c
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

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0

#include "axm0_config.h"

__reentrantb void wtimer0_setclksrc(uint8_t clksrc, uint8_t prescaler) __reentrant
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
		XBAR->PULL_DOWN_CFG_b.PA3 = 0x0;
		XBAR->PULL_DOWN_CFG_b.PA4 = 0x0;

		/* Set the pins PA3 and PA4 for LPXTAL */
		XBAR->PA_CFG_b.PA3 = 0x0;
		XBAR->PA_CFG_b.PA4 = 0x0;

		/* Enable LP XTAL */
		CMU->CFG_b.LP_XOSC_PD = 0x0;

		while(CMU->OSC_READY_STS_b.LP_XOSC != 0x1);
	} else {
		/* do nothing */
	}

	wtimer0_setconfig((clksrc & 0x07) | ((prescaler & 0x07) << 3));
}

__reentrantb void wtimer0_setconfig(uint8_t cfg) __reentrant
{
	/* Enable the wakeup timer peripheral clock */
	CMU->PCLK_CFG_b.WUT_EN = 0x1;

	/* Check if the settings are unchanged */
	if (!((WUT->WTCFG ^ cfg) & 0x3F))
		return;

	/* Write the clock source and prescalar values in config register */
	WUT->WTCFG = (cfg & 0x3F);
}

#elif defined __AXM0F2

#define AXM0F2_REG_WCO_WDT_CONFIG_LFCLK_SEL_MASK    (uint32_t)0xC0000000
#define AXM0F2_REG_WCO_WDT_CONFIG_LFCLK_WCO_MASK    (uint32_t)0x40000000
#define AXM0F2_REG_WCO_WDT_CONFIG_LFCLK_ILO_MASK    (uint32_t)0x00000000
#define AXM0F2_REG_WCO_CONFIG_CLK_EN_MASK           (uint32_t)0x00000003
#define AXM0F2_REG_WCO_CONFIG_CLK_EN_WCO_MASK       (uint32_t)0x00000001
#define AXM0F2_REG_WCO_CONFIG_CLK_EN_ILO_MASK       (uint32_t)0x00000002
#define AXM0F2_TIMER_4WCO_DELAY_US                  124
#define AXM0F2_TIMER_4ILO_DELAY_US                  268
#define AXM0F2_REG_WCO_CONFIG_IP_ENABLE             (uint32_t)0x80000000

#include "libmfosc.h"
#include "axm0_config.h"

__reentrantb void wtimer0_setclksrc(uint8_t clksrc, uint8_t prescaler) __reentrant
{
    criticalsection_t crit;
    wtimer0_clksrc = clksrc;

	if (clksrc == CLKSRC_FRCOSC)
    {
		/* Enable FRC OSC */
	}
	else if (clksrc == CLKSRC_LPOSC)
	{
		/* Enable LP OSC */
        /* ILO */
        /* Reset both _EN bits in WCO->WDT_CLKEN register */
        WCO->WDT_CLKEN &= ~AXM0F2_REG_WCO_CONFIG_CLK_EN_MASK;

        /* Wait 4 new clock source-cycles for change to come into effect */
        delay(AXM0F2_TIMER_4ILO_DELAY_US);

        crit = enter_critical();
		/* ILO clock select */
        WCO->WDT_CONFIG = (WCO->WDT_CONFIG & ~AXM0F2_REG_WCO_WDT_CONFIG_LFCLK_SEL_MASK) | AXM0F2_REG_WCO_WDT_CONFIG_LFCLK_ILO_MASK;
        exit_critical(crit);

		/* ILO clock enable */
        WCO->WDT_CLKEN = (WCO->WDT_CLKEN & ~AXM0F2_REG_WCO_CONFIG_CLK_EN_MASK) | AXM0F2_REG_WCO_CONFIG_CLK_EN_ILO_MASK;

	}
	else if (clksrc == CLKSRC_XOSC)
    {
		/* Enable HS XTAL */
	}
	else if (clksrc == CLKSRC_LPXOSC)
    {
        /* WCO */
        /* Disable pull ups and pull downs on WCO lines */
        HSIOM->PORT_SEL0 &= ~(0xF << 16 | 0xF << 20);   /* Select GPIO */
        GPIO_PRT0->DR    &= ~(0x1 << 4  | 0x1 << 5);    /* Clear output data */
        GPIO_PRT0->PC    &= ~(0x7 << 12 | 0x7 << 15);   /* Analog mode */
        GPIO_PRT0->PC2   &= ~(0x1 << 4  | 0x1 << 5);    /* input buffer disable */

        WCO->CONFIG &= ~0x02; 							/* Disable LPM_AUTO */
        WCO->CONFIG |= AXM0F2_REG_WCO_CONFIG_IP_ENABLE; /* WCO IP Enable */

        /* Reset both _EN bits in WCO->WDT_CLKEN register */
        WCO->WDT_CLKEN &= ~AXM0F2_REG_WCO_CONFIG_CLK_EN_MASK;

        /* Wait 4 new clock source-cycles for change to come into effect */
        delay(AXM0F2_TIMER_4WCO_DELAY_US);

        crit = enter_critical();
		/* WCO clock select */
        WCO->WDT_CONFIG = (WCO->WDT_CONFIG & ~AXM0F2_REG_WCO_WDT_CONFIG_LFCLK_SEL_MASK) | AXM0F2_REG_WCO_WDT_CONFIG_LFCLK_WCO_MASK;
        exit_critical(crit);

		/* WCO clock enable */
        WCO->WDT_CLKEN = (WCO->WDT_CLKEN & ~AXM0F2_REG_WCO_CONFIG_CLK_EN_MASK) | AXM0F2_REG_WCO_CONFIG_CLK_EN_WCO_MASK;
    }
	else
    {
		/* Do nothing */
	}
}

#endif

#else

__reentrantb void wtimer0_setconfig(uint8_t cfg) __reentrant
{
	if (!((WTCFGA ^ cfg) & 0x3F))
		return;
	cfg &= 0x3F;
	WTCFGA |= 0x04;
	WTCFGA = 0x0F;
	WTCFGA &= cfg | 0xFC;
	WTCFGA = cfg;
}

#endif
