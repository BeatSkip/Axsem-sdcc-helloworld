/**
******************************************************************************
* @file radioreset.c
* @brief radio reset
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

#include "cpu.h"

#define RADIO 5031

#include "radiodefs.h"

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0
#include "axm0_xbar.h"
#endif

#ifdef __AXM0F2
#include "axm0f2.h"
#include "axm0f2_pin.h"
#include "radioutil.h"
#endif // __AXM0F2

uint8_t radio_reset(void) __reentrant
{
	uint8_t i;
	// Initialize Interface
#ifdef __AXM0
	axm0_xbar_spi0_config(SPI0_MOSI, SPI0_MISO, SPI0_SELECT, SPI0_CLOCK, SPI0_SYSCLK);
#endif // __AXM0

#if DEEPSLEEP
	// Ensure Device is not in Deep Sleep
	radio_wakeup_deepsleep_core();
#endif
    	// Reset Device
	radio_write8(RADIO_PWRMODE, 0x80);  // RST bit PWRMODE
	radio_write8(RADIO_PWRMODE, PWRMODE_PWRDOWN);  //PWRMODE
	// Wait some time for regulator startup
#if defined(VREGDELAY) && VREGDELAY > 0
	delay(VREGDELAY);
#endif

	// Check Silicon Version
	i = radio_read8(RADIO_SILICONREVISION);
	i = radio_read8(RADIO_SILICONREVISION);

#ifdef SILICONREV2
	if (i != SILICONREV1 && i != SILICONREV2)
		return RADIO_ERR_REVISION;
#else
	if (i != SILICONREV1)
		return RADIO_ERR_REVISION;
#endif

	// Check Scratch (To test communication to the AX5043/44/45 & Uc)
	radio_write8(RADIO_SCRATCH, 0x55);
	if (radio_read8(RADIO_SCRATCH) != 0x55)
		return RADIO_ERR_COMM;
	radio_write8(RADIO_SCRATCH, 0xAA);
	if (radio_read8(RADIO_SCRATCH) != 0xAA)
		return RADIO_ERR_COMM;
	// Initialize Radio Interface Registers
	if (radio_probeirq())
		return RADIO_ERR_IRQ;
	return RADIO_OK;
}

#else

#include "axcompiler.h"

__reentrantb uint8_t radio_reset(void) __reentrant
{
	uint8_t i;
	// Initialize Interface
	DIRR = 0x15;
	PORTR = 0xEB;
#if DEEPSLEEP
	RADIOMUX = 0x07;
#else
	RADIOMUX = 0x47;
#endif
	RADIOACC = RACC;
	GPIOENABLE = 1;
#if defined SDCC
	RADIOFDATAADDR = FDATA;
	RADIOFSTATADDR = FSTAT;
#else
	RADIOFDATAADDR0 = (FDATA) & 0xFF;
	RADIOFDATAADDR1 = (FDATA) >> 8;
	RADIOFSTATADDR0 = (FSTAT) & 0xFF;
	RADIOFSTATADDR1 = (FSTAT) >> 8;
#endif
#if DEEPSLEEP
	// Ensure Device is not in Deep Sleep
	radio_wakeup_deepsleep_core();
#endif
	// Reset Device
	radio_write8(RADIO_PWRMODE, 0x80);
	radio_write8(RADIO_PWRMODE, PWRMODE_PWRDOWN);
	// Wait some time for regulator startup
#if defined(VREGDELAY) && VREGDELAY > 0
	delay(VREGDELAY);
#endif
	// Check Scratch
	i = radio_read8(RADIO_SILICONREVISION);
	i = radio_read8(RADIO_SILICONREVISION);
#ifdef SILICONREV2
	if (i != SILICONREV1 && i != SILICONREV2)
		return RADIO_ERR_REVISION;
#else
	if (i != SILICONREV1)
		return RADIO_ERR_REVISION;
#endif
	radio_write8(RADIO_SCRATCH, 0x55);
	if (radio_read8(RADIO_SCRATCH) != 0x55)
		return RADIO_ERR_COMM;
	radio_write8(RADIO_SCRATCH, 0xAA);
	if (radio_read8(RADIO_SCRATCH) != 0xAA)
		return RADIO_ERR_COMM;
	// Initialize Radio Interface Registers
	if (radio_probeirq())
		return RADIO_ERR_IRQ;
	return RADIO_OK;
}
#endif



#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5031_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	uint8_t pc1 = radio_read8(AX5031_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	// Initialize Interface
	axm0_xbar_spi0_config(SPI0_MOSI, SPI0_MISO, SPI0_SELECT, SPI0_CLOCK, SPI0_SYSCLK);
	radio_write8(AX5031_REG_PINCFG1, pc1);
	radio_write8(AX5031_REG_PINCFG2, 0x22); /* IRQ Line 1 */
	p &= GPIO->DATA >> 24;
	radio_write8(AX5031_REG_PINCFG2, 0x20); /* IRQ Line 0 */
	p &= (uint8_t)~(GPIO->DATA >> 24);
	radio_write8(AX5031_REG_PINCFG2, 0x00);
	switch(p) {
	case 0x20: /* IRQ on PR5 */
		// PR5 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR5 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x20000000;     // Configure PR5 to input
		GPIO_AND->INT_TYP = ~0x20000000;    // Configure PR5 to level triggered
		GPIO_OR->INT_POL = 0x20000000;      // Configure PR5 to rising edge
		GPIO_AND->INT_EN = ~0x20000000;     // Disable PR5 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<29));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<29));       // Disable pull down
		break;

	case 0x40: /* IRQ on PR6 */
		// PR6 - RIRQ Pin configure as GPIO
		XBAR->PR_CFG_b.PR6 = 0;             // Digital - 0
		GPIO_AND->OUT_EN = ~0x40000000;     // Configure PR6 to input
		GPIO_AND->INT_TYP = ~0x40000000;    // Configure PR6 to level triggered
		GPIO_OR->INT_POL = 0x40000000;      // Configure PR6 to rising edge
		GPIO_AND->INT_EN = ~0x40000000;     // Disable PR6 interrupt

		XBAR_OR->PULL_UP_CFG = ((1<<30));           // Disable pull up
		XBAR_AND->PULL_DOWN_CFG = ~((1<<30));       // Disable pull down
		break;

	default:
		/* Error */
		radio_write8(AX5031_REG_PINCFG1, 0x20 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	exit_critical(crit);
	return 0;
}

#elif defined __AXM0F2

/* Configure Radio IRQ  */
__reentrantb uint8_t ax5031_probeirq(void) __reentrant
{
	uint8_t p = 0x10;
	uint8_t pc1 = radio_read8(AX5031_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	radio_write8(AX5031_REG_PINCFG1, pc1);
	radio_write8(AX5031_REG_PINCFG2, 0x22); /* IRQ Line 1 */
	p &= GPIO_PRT2->PS;
	radio_write8(AX5031_REG_PINCFG2, 0x20); /* IRQ Line 0 */
	p &= (uint8_t)~GPIO_PRT2->PS;
	radio_write8(AX5031_REG_PINCFG2, 0x00);
	switch(p) {
	case 0x10: /* IRQ on P2[4] */
		break;

	default:
		/* Error */
		GPIO_PRT2->PC |= 7 << 12; /* enable PD/PU */
		radio_write8(AX5031_REG_PINCFG1, 0x20 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	exit_critical(crit);
	return 0;
}

#endif

#else

__reentrantb uint8_t ax5031_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	uint8_t pc1 = radio_read8(AX5031_REG_PINCFG1) & 0x0F;
	criticalsection_t crit = enter_critical();
	PORTR = 0xEB;
	radio_write8(AX5031_REG_PINCFG1, pc1);
	radio_write8(AX5031_REG_PINCFG2, 0x22); /* IRQ Line 1 */
	p &= PINR;
	radio_write8(AX5031_REG_PINCFG2, 0x20); /* IRQ Line 0 */
	p &= (uint8_t)~PINR;
	radio_write8(AX5031_REG_PINCFG2, 0x00);
	switch (p) {
	case 0x20: /* IRQ on PR5 */
		RADIOMUX &= (uint8_t)~0x08;
		break;

	case 0x40: /* IRQ on PR6 */
		RADIOMUX |= 0x08;
		break;

	default:
		/* Error */
		radio_write8(AX5031_REG_PINCFG1, 0x20 | pc1); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	PORTR &= (uint8_t)~p; /* disable pullup */
	exit_critical(crit);
	return 0;
}

#endif

