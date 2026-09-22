/**
******************************************************************************
* @file spi0.c
* @brief SPI 0 drivers APIs
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
#include "spi.h"

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

/** Descriptor initialization for SPI 0 */
struct spi_descriptor _spi0_descriptor = {
	0,          /* FIFO pointer */
	0,          /* Buffer size */
	0,          /* Buffer index */
	SCB0,       /* SCB0 used */
	SCB0_IRQn,  /* SCB IRQ number */
	0,          /* SCB number 0 */
	0           /* SPI status */
};

/** Function description can be found in header file */
uint8_t spi0_init(uint8_t speed, uint8_t sel_div, uint8_t mode, uint8_t bitorder)
{
    return spi_init(&_spi0_descriptor, speed, sel_div, mode, bitorder);
}

/** Function description can be found in header file */
void spi0_write(uint8_t *wrbuf, uint8_t wrlength)
{
    return spi_write(&_spi0_descriptor, wrbuf, wrlength);
}

/** Function description can be found in header file */
void spi0_read(uint8_t *rdBbuf, uint8_t rdLength)
{
    return spi_read(&_spi0_descriptor, rdBbuf, rdLength);
}

extern uint8_t spi0_close(void)
{
    return spi_close(&_spi0_descriptor);
}

/** Function description can be found in header file */
uint8_t spi0_wait_until_done(void)
{
    return spi_wait_until_done(&_spi0_descriptor);
}

/** Function description can be found in header file */
uint8_t spi0_get_status(void)
{
    return spi_get_status(&_spi0_descriptor);
}

void SCB0_Handler(void)
{
    spi_handler(&_spi0_descriptor);
}

#endif /* __AXM0F2 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */
