/**
******************************************************************************
* @file libmfspi.h
* @brief SPI API header
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

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

/* Speed */
#define LIBMF_SPI_SPEED_1MHZ 1
#define LIBMF_SPI_SPEED_2MHZ 2
#define LIBMF_SPI_SPEED_3MHZ 3
#define LIBMF_SPI_SPEED_4MHZ 4
#define LIBMF_SPI_SPEED_5MHZ 5
#define LIBMF_SPI_SPEED_6MHZ 6
#define LIBMF_SPI_SPEED_7MHZ 7
#define LIBMF_SPI_SPEED_8MHZ 8

/* Integer divider selection */
#define LIBMF_SPI_INT_DIV_0  0
#define LIBMF_SPI_INT_DIV_1  1
#define LIBMF_SPI_INT_DIV_2  2
#define LIBMF_SPI_INT_DIV_3  3
#define LIBMF_SPI_INT_DIV_4  4
#define LIBMF_SPI_INT_DIV_5  5

/* Clock polarity and clock phase options */
#define LIBMF_SPI_CPOL0_CPHA0  0
#define LIBMF_SPI_CPOL0_CPHA1  1
#define LIBMF_SPI_CPOL1_CPHA0  2
#define LIBMF_SPI_CPOL1_CPHA1  3

/* Bit order options */
#define LIBMF_SPI_LSB_FIRST  0
#define LIBMF_SPI_MSB_FIRST  1

/**
 *
 * Description: SPI initialization
 *
 * Input:
 *      speed - SPI clock speed (1 to 8) 1: 1 MHz ... 8: 8 MHz
 *      sel_div - Integer divider number to be selected (0 to 5)
 *      mode - 0:CPOL 0 CPHA 0, 1:CPOL 0 CPHA 1, 2:CPOL 1 CPHA 0, 3:CPOL 1 CPHA 1
 *      bitorder - 0:LSB First, 1: MSB First
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *
 */
extern uint8_t spi0_init(uint8_t speed, uint8_t sel_div, uint8_t mode, uint8_t bitorder);

/**
 *
 * Description: SPI write
 *
 * Input:
 *      wrBuf - Holds pointer to write buffer
 *      wrLength - Length in bytes to be written to SPI bus
 *
 * Output: Returns nothing
 *
 */
extern void spi0_write(uint8_t *wrBuf, uint8_t wrLength);

/**
 *
 * Description: SPI read
 *
 * Input:
 *      rdBuf - Holds pointer to read buffer
 *      rdLength - Length in bytes to be read from the SPI bus
 *
 * Output: Returns nothing
 *
 */
extern void spi0_read(uint8_t *rdBuf, uint8_t rdLength);

/**
 *
 * Description: SPI wait until done - Wait in  standby mode till SPI is done with transfer
 *
 * Input: Nothing
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *
 */
extern uint8_t spi0_wait_until_done(void);

/**
 *
 * Description: SPI get status
 *
 * Input: nothing
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *
 */
extern uint8_t spi0_get_status(void);

/**
 *
 * Description: SPI close - Disables SPI module
 *
 * Input: nothing
 *
 * Output: Returns nothing
 *
 */
extern uint8_t spi0_close(void);

#endif /* __AXM0F2 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */
