/**
******************************************************************************
* @file radiocommslpexit.c
* @brief Wakes up radio from sleep
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

#define RADIO 5043

#include "radiodefs.h"
#include "cpu.h"
#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0
#include "axm0_xbar.h"

__reentrantb void radio_commsleepexit(void) __reentrant
{
    // Initialize SPI0 Interface
	axm0_xbar_spi0_config(SPI0_MOSI, SPI0_MISO, SPI0_SELECT, SPI0_CLOCK, SPI0_SYSCLK);
	// FIFODATA & FIFOSTAT address mapping taken in axm0f143.h
    // Restore IRQ setting and pullup
	radio_probeirq();
}

#endif

#ifdef __AXM0F2
#include "axm0_config.h"

__reentrantb void radio_commsleepexit(void) __reentrant
{
	/*
	 * Port 2:
	 * P2[0]: SmartIO  off
	 * P2[1]: SmartIO  off
	 * P2[2]: ANTSEL   input
	 * P2[3]: PWRAMP   input
	 * P2[4]: IRQ      input
	 * P2[5]: MOSI     0_1
	 * P2[6]: MISO     input - Weak pull up/down
	 * P2[7]: CLK      0_1
	 */
    GPIO_PRT2->PC = 0x00DF1240;

	/*
	 * Port 3:
	 * P3[0]: SEL      0_1
	 * P3[1]: SYSCLK   input
	 */
	GPIO_PRT3->DR_SET = 0x00000001;
    SET_BIT_FIELDS(GPIO_PRT3->PC, 0x0000003F, 0x0000000E);

	/* Connect P2[0..2] to SCB */
	HSIOM->PORT_SEL2 |= 0x00000FFF;
	HSIOM->PORT_SEL3 &= ~0x000000FF;
	// restore IRQ setting and pullup
	radio_probeirq();
}

#endif

#else

__reentrantb void radio_commsleepexit(void) __reentrant
{
	DIRR = 0x15;                            //  PORTR SPI pin configuration
	PORTR = 0xEB;
	RADIOMUX |= 0x40;                       //  IRQ is Port R.5;
	RADIOACC = RACC;                        //  Radio Chip Data Access Width - 8 bit, Radio Chip Address Access Width - 7/12 Bit automatic
#if defined SDCC
	RADIOFDATAADDR = FDATA;                 //  Radio Chip FIFO Data Register Address - 0x029
	RADIOFSTATADDR = FSTAT;                 //  Radio Chip FIFO Status Register Address - 0x028
#else
	RADIOFDATAADDR0 = (FDATA) & 0xFF;
	RADIOFDATAADDR1 = (FDATA) >> 8;
	RADIOFSTATADDR0 = (FSTAT) & 0xFF;
	RADIOFSTATADDR1 = (FSTAT) >> 8;
#endif
	// restore IRQ setting and pullup
	radio_probeirq();
}

#endif
