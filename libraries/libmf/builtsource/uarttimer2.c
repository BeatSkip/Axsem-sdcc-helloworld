/**
******************************************************************************
* @file uarttimer.c
* @brief uart timer for baud rate generation
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
* @ingroup UART
*
* @details
*/

#include "cpu.h"
#include "libmfuart.h"

#define uart_timer_baud uart_timer2_baud
#if defined __ARMEL__ || defined __ARMEB__
/* Nothing */
#else
#define TCLKSRC T2CLKSRC
#define TMODE   T2MODE
#define TPERIOD T2PERIOD
#endif

#if defined __ARMEL__ || defined __ARMEB__

#include "axm0_uart.h"

#ifdef __AXM0

__reentrantb inline void axm0_uart_timer_baud(TIM_Type *membase, uint8_t clksrc, uint32_t baud, uint32_t clkfreq) __reentrant;

__reentrantb void uart_timer_baud(uint8_t clksrc, uint32_t baud, uint32_t clkfreq) __reentrant
{
	/* Enable UART timer clock and configure baud */
	CMU->PCLK_CFG_b.TIM2_EN = 1;
	axm0_uart_timer_baud(TIM2, clksrc, baud, clkfreq);
}

__reentrantb inline void axm0_uart_timer_baud(TIM_Type *timer_membase, uint8_t clksrc, uint32_t baud, uint32_t clkfreq) __reentrant
{
	uint8_t baud_higher_byte, num_of_shift = AXM0_UART_INIT_NUM_SHFT;

	timer_membase->CFG_b.INT_EN_OVER    = AXM0_UART_DISABLE_BIT;            /* Interrupt Disable */
	timer_membase->CFG_b.MOD            = AXM0_TIM_OP_MODE_MUL_SAWTTH_DN;   /* clock mode: multiple saw tooth down */
	timer_membase->CFG_b.CLK_SEL        = clksrc;                           /* Clock source */

	/* Find out clock divider and timer period value */
	while (num_of_shift) {
		/* Extract MSB */
		baud_higher_byte = baud >> 24;

		if (!baud_higher_byte && num_of_shift >= 8) {
			/* MSB is zero */
			baud <<= 8;
			num_of_shift -= 8;
			continue;
		}
		if (!(baud_higher_byte & 0xF0) && num_of_shift >= 4) {
			baud <<= 4;
			num_of_shift -= 4;
			continue;
		}
		if (!(baud_higher_byte & 0xC0) && num_of_shift >= 2) {
			baud <<= 2;
			num_of_shift -= 2;
			continue;
		}
		if (!(baud_higher_byte & 0x80)) {
			baud <<= 1;
			--num_of_shift;
			continue;
		}
		break;
	}

	clkfreq >>= num_of_shift;

	/* Generate timer period using baud rate required and clock frequency */
	baud /= clkfreq;

	num_of_shift = 0x38;

	/* If timer period more than 16 bit */
	while (baud >= 16384 && (num_of_shift & 0xF0)) {
		/* Adjust timer period within 16 bit */
		baud >>= 1;
		num_of_shift -= 8;
	}

	/* Set period to match with default clock divider */
	baud >>= AXM0_UART_DEFAULT_CLK_DIV;

	/* Calculate and set clock divider using num_of_shift calculated above */
	timer_membase->CFG_b.CLK_DIV = AXM0_UART_DEFAULT_CLK_DIV - ((AXM0_UART_DEFAULT_NUM_SHFT - num_of_shift)/8); /* clock divider */

	/* Set timer period */
	timer_membase->PER = baud * 16; /* clock period */

/*	timer_membase->CFG_b.INT_EN_OVER = 1;  TODO Interrupt enable */
}

#endif /* __AXM0 */

#ifdef __AXM0F2

static __reentrantb uint32_t uart_timer_baud_int(uint32_t baud, uint32_t clkfreq) __reentrant
{
	uint32_t quotient;

	baud *= AXM0F2_UART_CTRL_OVS + 1;
	if (baud) {
		quotient = clkfreq;
		quotient += baud >> 1;
		quotient /= baud;
		if (quotient)
			--quotient;
		if (quotient > 0xFFFF)
			quotient = 0xFFFF;
	} else {
		quotient = 0xFFFF;
	}
	quotient <<= 8;
	return quotient;
}

static __reentrantb uint32_t uart_timer_baud_frac(uint32_t baud, uint32_t clkfreq) __reentrant
{
	uint32_t quotient;

	baud *= AXM0F2_UART_CTRL_OVS + 1;
	if (baud) {
		quotient = clkfreq << 5;
		quotient += baud >> 1;
		quotient /= baud;
		if (quotient < 0x20)
			quotient = 0x20;
		if (quotient > 0x20001F)
			quotient = 0x20001F;
	} else {
		quotient = 0x20001F;
	}
	quotient -= 0x20;
	quotient <<= 3;
	return quotient;
}

__reentrantb void uart_timer_baud(uint8_t clksrc, uint32_t baud, uint32_t clkfreq) __reentrant
{
	PERI->DIV_16_CTL2 = uart_timer_baud_int(baud, clkfreq);
	PERI->DIV_CMD = 0x8000FF42u;
}

#endif /* __AXM0F2 */

#else /* Other than ARM */

__reentrantb void uart_timer_baud(uint8_t clksrc, uint32_t baud, uint32_t clkfreq) __reentrant
{
	uint8_t sh = 26;
	while (sh) {
		uint8_t bdhi = baud >> 24;
		if (!bdhi && sh >= 8) {
			baud <<= 8;
			sh -= 8;
			continue;
		}
		if (!(bdhi & 0xF0) && sh >= 4) {
			baud <<= 4;
			sh -= 4;
			continue;
		}
		if (!(bdhi & 0xC0) && sh >= 2) {
			baud <<= 2;
			sh -= 2;
			continue;
		}
		if (!(bdhi & 0x80)) {
			baud <<= 1;
			--sh;
			continue;
		}
		break;
	}
	clkfreq >>= sh;
	baud /= clkfreq;
	sh = 0x38;
	while (baud >= 16384 && (sh & 0xF0)) {
		baud >>= 1;
		sh -= 8;
	}
	TCLKSRC = sh | (clksrc & 7);
	TMODE = 0x04;
	TPERIOD = baud;
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */
