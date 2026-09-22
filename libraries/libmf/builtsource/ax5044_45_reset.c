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

#define RADIO 5044

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
/* Place holder */
#elif defined __AXM0F2
/* Place holder */
#endif

#else /* Non - ARM: 8052 */

#define RADIODRV        SFRX(0x7045)

__reentrantb uint8_t ax5044_45_probeirq(void) __reentrant
{
	uint8_t p = 0x60;
	criticalsection_t crit = enter_critical();
	PORTR &= 0xEB;
	PORTR |= 0x2B;
	radio_write8(AX5044_45_REG_PINFUNCIRQ, 0x01); /* IRQ Line 1 */
	p &= PINR;
	radio_write8(AX5044_45_REG_PINFUNCIRQ, 0x00); /* IRQ Line 0 */
	p &= (uint8_t)~PINR;
	radio_write8(AX5044_45_REG_PINFUNCIRQ, 0x03);
	switch (p) {
	case 0x20: /* IRQ on PR5 */
		RADIOMUX &= (uint8_t)~0x08;
		break;

	case 0x40: /* IRQ on PR6 */
		RADIOMUX |= 0x08;
		break;

	default:
		/* Error */
		radio_write8(AX5044_45_REG_PINFUNCIRQ, 0x02); /* Disable IRQ line */
		exit_critical(crit);
		return 1;
	}
	PORTR &= (uint8_t)~p; /* disable pullup */
	exit_critical(crit);
	return 0;
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */

