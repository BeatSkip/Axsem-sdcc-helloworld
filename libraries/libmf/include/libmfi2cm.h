/**
******************************************************************************
* @file libmfi2cm.h
* @brief I2C API header
* @internal
* @author   Sai Pramod Kumar D
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
* @ingroup I2C
*
* @details
*/

#ifndef LIBMFI2CM_H
#define LIBMFI2CM_H

#include "cpu.h"
#include "libmftypes.h"

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

#define LIBMF_I2C_SLOW_MODE 		    0
#define LIBMF_I2C_STANDARD_MODE 	    1
#define LIBMF_I2C_FAST_MODE 		    2
#define LIBMF_I2C_FAST_PLUS_MODE	    3

#define LIBMF_I2C_MASTER 		        0
#define LIBMF_I2C_SLAVE 		        1
#define LIBMF_I2C_MASTERSLAVE 		    2

#define LIBMF_I2C_INTERNAL_CLK	        0
#define LIBMF_I2C_EXTERNAL_CLK	        1

#define LIBMF_I2C_INT_DIV_0             0
#define LIBMF_I2C_INT_DIV_1             1
#define LIBMF_I2C_INT_DIV_2             2
#define LIBMF_I2C_INT_DIV_3             3
#define LIBMF_I2C_INT_DIV_4             4
#define LIBMF_I2C_INT_DIV_5             5

/**
 *
 * Description: I2C0 SCL and SDA Port configs are done
 *
 * Input: NONE
 *
 * Output: NONE
 *
 */
extern void i2c0_portconfig();

/**
 *
 * Description: I2C0 initialization
 *
 * Input:
 *      mode - LIBMF_I2C_MASTER
 *      speed - LIBMF_I2C_SLOW_MODE(50KHz),LIBMF_I2C_STANDARD_MODE(100KHz),LIBMF_I2C_FAST_MODE(400KHz),LIBMF_I2C_FAST_PLUS_MODE(1MHz)
 *      sel_div - Integer divider number to be selected (0 to 5)
 *      clk_src - LIBMF_I2C_INTERNAL_CLK
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *
 */
extern uint8_t i2c0_init(uint8_t mode, uint8_t speed, uint8_t sel_div, uint8_t clk_src);

/**
 *
 * Description: I2C0 write
 *
 * Input:
 *      slaveAddress - 7bit/10bit Slave address
 *      wrData - Holds pointer to write buffer
 *      length - Length in bytes to be written to I2C bus
 *      repeated - 0 : STOP is sent at end of write
 *                 1 : STOP is not sent at end of write
 *
 * Output: Returns nothing
 *
 */
extern void i2c0_write(uint16_t slaveAddress, uint8_t *wrData, uint8_t length, uint8_t repeated);

/**
 *
 * Description: I2C0 read
 *
 * Input:
 *      slaveAddress - 7bit/10bit Slave address
 *      rdData - Holds pointer to read buffer
 *      length - Length in bytes to be read from the I2C bus
 *      repeated - 0 : STOP is sent at end of read
 *                 1 : STOP is not sent at end of read
 *
 * Output: Returns nothing
 *
 */
extern void i2c0_read(uint16_t slaveAddress, uint8_t *rdData, uint8_t length, uint8_t repeated);

/**
 *
 * Description: I2C0 get status
 *
 * Input: nothing
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *      LIBMF_I2C_BUS_ERROR
 *      LIBMF_I2C_ARB_LOST
 *
 */
extern uint8_t i2c0_getstatus();

/**
 *
 * Description: I2C0 wait until done - Wait in  standby mode till I2C is done with transfer
 *
 * Input: Nothing
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *      LIBMF_I2C_BUS_ERROR
 *      LIBMF_I2C_ARB_LOST
 *
 */
extern uint8_t i2c0_wait_until_done();

/**
 *
 * Description: I2C0 close - Disables I2C module
 *
 * Input: nothing
 *
 * Output: Returns nothing
 *
 */
extern uint8_t i2c0_close(void);

/**
 *
 * Description: I2C1 SCL and SDA Port configs are done
 *
 * Input: NONE
 *
 * Output: NONE
 *
 */
extern void i2c1_portconfig();

/**
 *
 * Description: I2C1 initialization
 *
 * Input:
 *      mode - LIBMF_I2C_MASTER
 *      speed - LIBMF_I2C_SLOW_MODE(50KHz),LIBMF_I2C_STANDARD_MODE(100KHz),LIBMF_I2C_FAST_MODE(400KHz),LIBMF_I2C_FAST_PLUS_MODE(1MHz)
 *      sel_div - Integer divider number to be selected (0 to 5)
 *      clk_src - LIBMF_I2C_INTERNAL_CLK
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *
 */
extern uint8_t i2c1_init(uint8_t mode, uint8_t speed, uint8_t sel_div, uint8_t clk_src);

/**
 *
 * Description: I2C1 write
 *
 * Input:
 *      slaveAddress - 7bit/10bit Slave address
 *      wrData - Holds pointer to write buffer
 *      length - Length in bytes to be written to I2C bus
 *      repeated - 0 : STOP is sent at end of write
 *                 1 : STOP is not sent at end of write
 *
 * Output: Returns nothing
 *
 */
extern void i2c1_write(uint16_t slaveAddress, uint8_t *wrData, uint8_t length, uint8_t repeated);

/**
 *
 * Description: I2C1 read
 *
 * Input:
 *      slaveAddress - 7bit/10bit Slave address
 *      rdData - Holds pointer to read buffer
 *      length - Length in bytes to be read from the I2C bus
 *      repeated - 0 : STOP is sent at end of read
 *                 1 : STOP is not sent at end of read
 *
 * Output: Returns nothing
 *
 */
extern void i2c1_read(uint16_t slaveAddress, uint8_t *rdData, uint8_t length, uint8_t repeated);

/**
 *
 * Description: I2C1 get status
 *
 * Input: nothing
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *      LIBMF_I2C_BUS_ERROR
 *      LIBMF_I2C_ARB_LOST
 *
 */
extern uint8_t i2c1_getstatus();

/**
 *
 * Description: I2C1 wait until done - Wait in  standby mode till I2C is done with transfer
 *
 * Input: Nothing
 *
 * Output: Returns status
 *      AXM0_STATUS_SUCCESS
 *      AXM0_STATUS_FAIL
 *      AXM0_STATUS_INVALID_PARAM
 *      AXM0_STATUS_IN_PROGRESS
 *      LIBMF_I2C_BUS_ERROR
 *      LIBMF_I2C_ARB_LOST
 *
 */
extern uint8_t i2c1_wait_until_done();

/**
 *
 * Description: I2C1 close - Disables I2C module
 *
 * Input: nothing
 *
 * Output: Returns nothing
 *
 */
extern uint8_t i2c1_close(void);

#endif /* __AXM0F2 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */

#endif /* LIBMFI2CM_H */
