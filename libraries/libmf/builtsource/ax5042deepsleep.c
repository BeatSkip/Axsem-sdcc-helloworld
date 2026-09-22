/**
******************************************************************************
* @file radiodeepsleep.c
* @brief Puts radio into deep sleep
* @internal
* @author   Thomas Sailer, Pradeep Kumar GR
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
* @ingroup RADIO
*
* @details
*/

#include "libmftypes.h"
#include "libmfradio.h"

#define RADIO 5042

#include "radiodefs.h"

#if DEEPSLEEP
#include "cpu.h"
#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0F2

/* FIXME */

__reentrantb void radio_enter_deepsleep(void) __reentrant
{
	GPIO_PRT2->DR |= 0x0A; // MISO, SEL
	// ensure last bit read before entering deep sleep is a zero;
	// this is held until after wakeup is complete; otherwise,
	// the wakeup protocol will not work
	radio_write8(RADIO_PWRMODE, PWRMODE_PWRDOWN);
	radio_write8(RADIO_PWRMODE, PWRMODE_DEEPSLEEP);
	HSIOM->PORT_SEL2 &= ~0xFFF;
	// turn off pull-up if MISO is driven low
	GPIO_PRT2->DR &= 0xFD | GPIO_PRT2->PS;
}

__reentrantb uint8_t radio_wakeup_deepsleep(void) __reentrant
{
    HSIOM->PORT_SEL2 &= ~0xFFF;
	GPIO_PRT2->PC = (GPIO_PRT2->PC & ~0x00000FFF) | 0x00000DBE;
	GPIO_PRT2->DR |= 0x0B; // SEL, MOSI high, MISO pullup
	HSIOM->PORT_SEL2 |= 0xFFF;
	{
		uint8_t i = radio_wakeup_deepsleep_core();
		if (i)
			return i;
	}
	if (radio_probeirq())
		return RADIO_ERR_IRQ;
	return 0;
}

#elif defined __AXM0

#include "axm0_xbar.h"

__reentrantb void radio_enter_deepsleep(void) __reentrant
{
	// Configure PR0,PR2,PR3 & PR4 as GPIO
	XBAR->PR_CFG_b.PR0 = 0;
	XBAR->PR_CFG_b.PR2 = 0;
	XBAR->PR_CFG_b.PR3 = 0;
	XBAR->PR_CFG_b.PR4 = 0;
	XBAR->PULL_UP_CFG_b.PR3 = 0;                  //  Turn off pull-up if MISO is driven low
	GPIO_OR->OUT_EN = 0x15000000;                 //  PR0(M_SEL) - Output, PR1(RSYS_CLK) - Input, PR2(M_SCK) - Output, PR3(M_MISO) - Input & PR4(M_MOSI) - Output

        GPIO_OR->DATA_OUT = 0x09000000;               //  Set SEL as High

	radio_write8(RADIO_PWRMODE, PWRMODE_PWRDOWN);
	radio_write8(RADIO_PWRMODE, PWRMODE_DEEPSLEEP);
}

__reentrantb uint8_t radio_wakeup_deepsleep(void) __reentrant
{
	// Initialize SPI0 Interface
	axm0_xbar_spi0_config(SPI0_MOSI, SPI0_MISO, SPI0_SELECT, SPI0_CLOCK, SPI0_SYSCLK);
	// FIFODATA & FIFOSTAT address mapping taken in axm0f143.h

	uint8_t i = radio_wakeup_deepsleep_core();
	if (i)
		return i;

	if (radio_probeirq())
		return RADIO_ERR_IRQ;
	return 0;
}

#endif

#else

__reentrantb void radio_enter_deepsleep(void) __reentrant
{
	PORTR |= 0x09;
	// ensure last bit read before entering deep sleep is a zero;
	// this is held until after wakeup is complete; otherwise,
	// the wakeup protocol will not work
	radio_write8(RADIO_PWRMODE, PWRMODE_PWRDOWN);
	radio_write8(RADIO_PWRMODE, PWRMODE_DEEPSLEEP);
	RADIOMUX &= (uint8_t)~0x40;                 //  Port R.0, R.2, R.3 and R.4 is GPIO
	// turn off pull-up if MISO is driven low
	PORTR &= 0xF7 | PINR;
}

__reentrantb uint8_t radio_wakeup_deepsleep(void) __reentrant
{
	DIRR = 0x15;
	PORTR = 0xEB;
	RADIOMUX = 0x07;
	RADIOACC = RACC;
#if defined SDCC
	RADIOFDATAADDR = FDATA;
	RADIOFSTATADDR = FSTAT;
#else
	RADIOFDATAADDR0 = (FDATA) & 0xFF;
	RADIOFDATAADDR1 = (FDATA) >> 8;
	RADIOFSTATADDR0 = (FSTAT) & 0xFF;
	RADIOFSTATADDR1 = (FSTAT) >> 8;
#endif
	GPIOENABLE = 1;
	{
		uint8_t i = radio_wakeup_deepsleep_core();
		if (i)
			return i;
	}
	if (radio_probeirq())
		return RADIO_ERR_IRQ;
	return 0;
}

#endif // defined

#endif
