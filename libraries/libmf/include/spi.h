/**
******************************************************************************
* @file spi.h
* @brief SPI Header file
* @internal
* @author   Pradeep Kumar GR
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
* @ingroup SPI
*
* @details
*/

#include "cpu.h"
#include "libmftypes.h"
#include "axm0_config.h"
#include "libmfwtimer.h"
#include "libmfspi.h"

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

#include "axm0f2vectors.h"

#define AXM0F2_DIV_CTL_ADRS_OFFSET (uint32_t)(0x300/4)

/* Interrupt masks */
#define SPI_INTR_M_DONE         (uint32_t)(1 << 9)

#define SPI_INTR_TX_UNDERFLOW   (uint32_t)(1 << 6)
#define SPI_INTR_TX_OVERFLOW    (uint32_t)(1 << 5)
#define SPI_INTR_TX_EMPTY       (uint32_t)(1 << 4)
#define SPI_INTR_TX_NOT_FULL    (uint32_t)(1 << 1)
#define SPI_INTR_TX_TRIGGER     (uint32_t)(1 << 0)

#define SPI_INTR_RX_UNDERFLOW   (uint32_t)(1 << 6)
#define SPI_INTR_RX_OVEERFLOW   (uint32_t)(1 << 5)
#define SPI_INTR_RX_FULL        (uint32_t)(1 << 3)
#define SPI_INTR_RX_NOT_EMPTY   (uint32_t)(1 << 2)
#define SPI_INTR_RX_TRIGGER     (uint32_t)(1 << 0)

/* SPI descriptor definition */
struct spi_descriptor {
	uint8_t     *bufferptr;
	uint8_t     buffersize;
	uint8_t     bufferindex;
	void        *membase;
	IRQn_Type   irqnum;
	uint8_t     spinum;
	uint8_t     status;
};

extern struct spi_descriptor _spi0_descriptor;

extern uint8_t spi_init(struct spi_descriptor *spi_desc, uint8_t speed, uint8_t sel_div, uint8_t mode, uint8_t bitorder);
extern void spi_write(struct spi_descriptor *spi_desc, uint8_t *wrBuf, uint8_t wrLength);
extern void spi_read(struct spi_descriptor *spi_desc, uint8_t *rdBbuf, uint8_t rdLength);
extern uint8_t spi_close(struct spi_descriptor *spi_desc);
extern void spi_handler(struct spi_descriptor *spi_desc);
extern uint8_t spi_get_status(struct spi_descriptor *spi_desc);
extern uint8_t spi_wait_until_done(struct spi_descriptor *spi_desc);

#endif /* __AXM0F2 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */

