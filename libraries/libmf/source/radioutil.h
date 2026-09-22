/**
******************************************************************************
* @file radioutil.h
* @brief Radio utility inline functions
* @internal
* @author   Thomas Sailer
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

#ifndef RADIOUTIL_H
#define RADIOUTIL_H

#define AXM0F2_RSEL_IDLE	do { GPIO_PRT3->DR_SET = (1 << 0); } while(0)   /* set idle high */
#define AXM0F2_RSEL_ACTIVE	do { GPIO_PRT3->DR_CLR = (1 << 0); } while(0)   /* set active low */

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

#define AXM0F2_GPIO_INTR_CNFG_BOTH_EDGES       3
#define AXM0F2_GPIO_PIN3_INTR_CNFG_BIT_POS     6
#define AXM0F2_GPIO_PIN6_INTR_CNFG_BIT_POS     12
#define AXM0F2_GPIO_INTR_DISABLE               0x3
#define AXM0F2_GPIO_PIN_DRIVE_MODE_MASK        0x7
#define AXM0F2_GPIO_PIN_STRONG_DRIVE_MODE      0x6
#define AXM0F2_GPIO_PORT_PIN_MASK              0x7F
#define AXM0F2_GPIO_PIN_MASK                   0x07
#define AXM0F2_GPIO_PWRAMP_PIN_INTR_MASK       0x08
#define AXM0F2_GPIO_PWRAMP_PIN_STATE_MASK      0x08
#define AXM0F2_GPIO_ANTSEL_PIN_INTR_MASK       0x40
#define AXM0F2_GPIO_ANTSEL_PIN_STATE_MASK      0x40
#define AXM0F2_GPIO_RADIO_IRQ_PIN_INTR_MASK    0x10
#define AXM0F2_GPIO_RADIO_IRQ_PIN_STATE_MASK   0x10


static inline __attribute__((always_inline,optimize("O3,unroll-all-loops"))) uint32_t _radio_spi_io(uint8_t wr, uint32_t addr, uint32_t data, unsigned int sz)
{
	criticalsection_t crit;
	uint16_t qstat;
	unsigned int fifosz, addrsz;
	if (addr & 0xC0000000) {
		addr >>= 2;
		addr ^= 0x8000;
	}
	addrsz = (addr >> 15) & 1;
	crit = enter_critical();
	SCB1->RX_FIFO_CTRL |= 0x00010000;
	SCB1->TX_FIFO_CTRL |= 0x00010000;
	SCB1->RX_FIFO_CTRL &= ~0x00010000;
	SCB1->TX_FIFO_CTRL &= ~0x00010000;
	AXM0F2_RSEL_ACTIVE;
	if (addrsz) {
		SCB1->TX_FIFO_WR = ((addr >> 8) & 0x7F) | wr;
		SCB1->TX_FIFO_WR = addr & 0xFF;
	} else {
		SCB1->TX_FIFO_WR = (addr & 0x7F) | wr;
	}
	switch (sz) {
	default:
		sz = 4;
		SCB1->TX_FIFO_WR = data >> 24;
	case 3:
		SCB1->TX_FIFO_WR = data >> 16;
	case 2:
		SCB1->TX_FIFO_WR = data >> 8;
	case 1:
		SCB1->TX_FIFO_WR = data;
	case 0:
		;
	}
	fifosz = 1 + addrsz + sz;
	while ((SCB1->RX_FIFO_STATUS & 0x1F) < fifosz);
	qstat = SCB1->RX_FIFO_RD << 8;
	if (addrsz)
		qstat |= SCB1->RX_FIFO_RD & 0xFF;
	for (data = 0; sz > 0; --sz) {
		data <<= 8;
		data |= SCB1->RX_FIFO_RD & 0xFF;
	}
	AXM0F2_RSEL_IDLE;
	exit_critical(crit);
	return data;
}

static inline __attribute__((always_inline,optimize("O3"))) void _radio_spi_bulkio(uint8_t wr, uint32_t addr, const uint8_t *dtx, uint8_t *drx, unsigned int sz)
{
	criticalsection_t crit;
	uint32_t sz_temp = sz;
	volatile uint8_t temp;
	uint16_t qstat;
	unsigned int fifosz, addrsz;
	if (addr & 0xC0000000) {
		addr >>= 2;
		addr ^= 0x8000;
	}
	addrsz = (addr >> 15) & 1;
	crit = enter_critical();
	SCB1->RX_FIFO_CTRL |= 0x00010000;
	SCB1->TX_FIFO_CTRL |= 0x00010000;
	SCB1->RX_FIFO_CTRL &= ~0x00010000;
	SCB1->TX_FIFO_CTRL &= ~0x00010000;
	AXM0F2_RSEL_ACTIVE;
	if (addrsz) {
		SCB1->TX_FIFO_WR = ((addr >> 8) & 0x7F) | wr;
		SCB1->TX_FIFO_WR = addr & 0xFF;
	} else {
		SCB1->TX_FIFO_WR = (addr & 0x7F) | wr;
	}
	if (dtx) {
		for (; sz > 0; --sz, ++dtx)
			SCB1->TX_FIFO_WR = *dtx;
	} else {
		for (; sz > 0; --sz)
			SCB1->TX_FIFO_WR = 0;
	}
	fifosz = 1 + addrsz + sz_temp;
	while ((SCB1->RX_FIFO_STATUS & 0x1F) < fifosz);
	qstat = SCB1->RX_FIFO_RD << 8;
	if (addrsz)
		qstat |= SCB1->RX_FIFO_RD & 0xFF;
	if (drx) {
		for (; sz_temp > 0; --sz_temp, ++drx)
			*drx = SCB1->RX_FIFO_RD;
	} else {
		for (; sz_temp > 0; --sz_temp)
            temp = SCB1->RX_FIFO_RD;
	}
	AXM0F2_RSEL_IDLE;
	exit_critical(crit);
}

#endif
#endif

#endif /* RADIOUTIL_H */
