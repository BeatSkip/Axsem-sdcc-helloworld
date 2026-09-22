/**
******************************************************************************
* @file i2c1.c
* @brief I2C 1 drivers APIs
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

/** Descriptor initialization for I2C 1 */
struct i2c_descriptor _i2c1_descriptor = {
	NULL,
	NULL,
	0,
	0,
	0,
	0,
	SCB2,
	SCB2_IRQn,
	0,
	0,
    0
};

/** Function description can be found in header file */
void i2c1_portconfig()
{
    /* Port 1.2 and 1.3 deep sleep source 2 */
    SET_BIT_FIELDS(HSIOM->PORT_SEL1, (0x0000FF00), (0x0000EE00));
    GPIO_PRT1->DR |= 0x0000000C;
    SET_BIT_FIELDS(GPIO_PRT1->PC, (7 << 6), (4 << 6));
    SET_BIT_FIELDS(GPIO_PRT1->PC, (7 << 9), (4 << 9));
}

/** Function description can be found in header file */
uint8_t i2c1_init(uint8_t mode, uint8_t speed, uint8_t sel_div, uint8_t clk_src)
{
    uint8_t status = 0;

    __disable_irq();
    i2c1_portconfig();
    __enable_irq();
    status = i2c_init(&_i2c1_descriptor,mode,speed,sel_div,clk_src);
    return(status);
}

/** Function description can be found in header file */
void i2c1_write(uint16_t slaveAddress, uint8_t *wrData, uint8_t length, uint8_t repeated)
{
    i2c_write(&_i2c1_descriptor,slaveAddress,wrData,length,repeated);
}

/** Function description can be found in header file */
void i2c1_read(uint16_t slaveAddress, uint8_t *rdData, uint8_t length, uint8_t repeated)
{
    i2c_read(&_i2c1_descriptor,slaveAddress,rdData,length,repeated);
}

/** Function description can be found in header file */
uint8_t i2c1_getstatus()
{
    return(i2c_getstatus(&_i2c1_descriptor));
}

/** Function description can be found in header file */
uint8_t i2c1_wait_until_done()
{
    return(i2c_wait_until_done(&_i2c1_descriptor));
}

/** Function description can be found in header file */
extern uint8_t i2c1_close(void)
{
    return i2c_close(&_i2c1_descriptor);
}

void SCB2_Handler(void)     //P1.2 SCL and P1.3 SDA
{
    i2c_handler(&_i2c1_descriptor);
}


#endif // __AXM0F2

#endif // defined
