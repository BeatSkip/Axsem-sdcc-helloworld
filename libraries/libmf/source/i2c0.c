/**
******************************************************************************
* @file i2c0.c
* @brief I2C 0 drivers APIs
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

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

#include "cpu.h"
#include "axm0f2.h"
#include "i2c.h"
#include <libmfwtimer.h>

/*
struct i2c_descriptor {
	uint8_t               *txpointer;
	uint8_t               *rxpointer;
	uint8_t               txdatalength;
	uint8_t               rxdatalength;
    uint8_t               txindex;
	uint8_t               rxindex;
	void                  *membase;
	IRQn_Type             irqnum;
	uint8_t               status;
	uint8_t               repeated;
	uint8_t               flag;
};
*/

/** Descriptor initialization for I2C 0 */
struct i2c_descriptor _i2c0_descriptor = {
	NULL,
	NULL,
	0,
	0,
	0,
	0,
	SCB0,
	SCB0_IRQn,
	0,
	0,
	0
};

/** Function description can be found in header file */
void i2c0_portconfig()
{
    /* Port 4.0 and 4.1 deep sleep source 2 */
    SET_BIT_FIELDS(HSIOM->PORT_SEL4, (0x000000FF), (0x000000EE)); /* 0x40020400 */
    GPIO_PRT4->DR |= 0x00000003; /* 0x40040400 */
    SET_BIT_FIELDS(GPIO_PRT4->PC, (7 << 0), (4 << 0)); /* 0x40040408 */
    SET_BIT_FIELDS(GPIO_PRT4->PC, (7 << 3), (4 << 3)); /* 0x40040408 */
}

/** Function description can be found in header file */
uint8_t i2c0_init(uint8_t mode, uint8_t speed, uint8_t sel_div, uint8_t clk_src)
{
    uint8_t status = 0;

    __disable_irq();
    i2c0_portconfig();
    __enable_irq();
    status = i2c_init(&_i2c0_descriptor,mode,speed,sel_div,clk_src);
    return(status);
}

/** Function description can be found in header file */
void i2c0_write(uint16_t slaveAddress, uint8_t *wrData, uint8_t length, uint8_t repeated)
{
    i2c_write(&_i2c0_descriptor,slaveAddress,wrData,length,repeated);
}

/** Function description can be found in header file */
void i2c0_read(uint16_t slaveAddress, uint8_t *rdData, uint8_t length, uint8_t repeated)
{
    i2c_read(&_i2c0_descriptor,slaveAddress,rdData,length,repeated);
}

/** Function description can be found in header file */
uint8_t i2c0_getstatus()
{
    return(i2c_getstatus(&_i2c0_descriptor));
}

/** Function description can be found in header file */
uint8_t i2c0_wait_until_done()
{
    return(i2c_wait_until_done(&_i2c0_descriptor));
}

/** Function description can be found in header file */
extern uint8_t i2c0_close(void)
{
    return i2c_close(&_i2c0_descriptor);
}

void SCB0_Handler(void)     //P4.0 SCL and P4.1 SDA
{
    i2c_handler(&_i2c0_descriptor);
}

#endif // __AXM0F2

#endif // defined
