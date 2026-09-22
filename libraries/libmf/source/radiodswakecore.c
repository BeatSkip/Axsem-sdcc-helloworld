/**
******************************************************************************
* @file radiodswakecore.c
* @brief Radio wake up
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

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0

#include "axm0_xbar.h"

__reentrantb uint8_t radio_wakeup_deepsleep_core(void) __reentrant
{
	uint8_t i = 30, j = 0;

	XBAR->PR_CFG_b.PR3 = 0;                         // PR3 config as GPIO
	GPIO_AND->OUT_EN = ~(1 << SPI0_MISO);           // PR3(MISO) as Input
	GPIO_OR->OUT_EN = (1 << SPI0_SELECT);           // PR0 (SEL) as Output
	do {
		do {
			// Precharge
			GPIO_AND->DATA_OUT = ~(1 << SPI0_SELECT); // To exit radio deep sleep mode, lower the SEL line

			// MISO will goes to Low during radio init & will rise to high at the end of the radio initialization
			if (GPIO->DATA & (1 << SPI0_MISO)) {      // check MISO went to High after radio init
				i = 0;
				goto dswakeup;
			}
			GPIO_OR->OUT_EN = (1 << SPI0_SELECT);     // Set PR0(SEL) as High
		} while (--j);
	} while (--i);
	i = 4; /* RADIO_ERR_WAKEUPTIMEOUT */
  dswakeup:
        GPIO_OR->OUT_EN = (1 << SPI0_SELECT);   //(RR0) SEL High
	return i;
}

#endif

#ifdef __AXM0F2

__reentrantb uint8_t radio_wakeup_deepsleep_core(void) __reentrant
{
	uint8_t i = 3, j = 0;
	HSIOM->PORT_SEL2 &= ~0xFFF;
    GPIO_PRT2->PC |= 0x38;                     // MISO PD_PU
	GPIO_PRT2->DR_CLR = 0x02;                        // MISO low
	do {
		do {
			// precharge
			GPIO_PRT2->PC &= ~0x0020;    // MISO 0_1 strong drive
			GPIO_PRT2->PC |= 0x0020;     // MISO PD_PU
			GPIO_PRT3->DR_CLR = 0x01;        // To exit radio deep sleep mode, lower the SEL line
			if (GPIO_PRT2->PS & 0x02) {      // check MISO went to High after radio init
				i = 0;
				goto dswakeup;
			}
			GPIO_PRT3->DR_SET = 0x01;        // SEL high
		} while (--j);
	} while (--i);
	i = 4; /* RADIO_ERR_WAKEUPTIMEOUT */
  dswakeup:
	GPIO_PRT2->PC &= ~0x0030;                    // MISO input
	GPIO_PRT2->DR_SET = 0x02;                        // MISO high
	GPIO_PRT3->DR_SET = 0x01;                        // SEL high
	HSIOM->PORT_SEL2 |= 0xFFF;
	return i;
}

#endif

#else

__reentrantb uint8_t radio_wakeup_deepsleep_core(void) __reentrant
{
	uint8_t i = 3, j = 0;
	PORTR &= (uint8_t)~0x08;                         // PR3(MISO) high-Z (pullup off)
	do {
		do {
			// precharge
			DIRR |= 0x08;                    // PR3(MISO) drive low
			DIRR &= (uint8_t)~0x08;          // PR3(MISO) high-Z
			PORTR &= (uint8_t)~1;            // To exit radio deep sleep mode, lower the SEL line
			if (PINR & 0x08) {               // check MISO went to High after radio init
				i = 0;
				goto dswakeup;
			}
			PORTR |= 1;                      // PR0(SEL) high
		} while (--j);
	} while (--i);
	i = 4; /* RADIO_ERR_WAKEUPTIMEOUT */
  dswakeup:
	PORTR |= 0x09;                                   // (PR3)MISO pullup & (RR0) SEL high
	RADIOMUX = 0x47;                                 // RADIOSYSCLK-Off, IRQ is Port R.5, Radio Clock - Port R.1, Port R.0, R.2, R.3, R.4 is Radio SPI
	return i;
}

#endif // defined
