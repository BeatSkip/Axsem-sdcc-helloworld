/**
******************************************************************************
* @file i2c.h
* @brief I2C APIs declararion
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

#ifndef I2C_H
#define I2C_H

#include "cpu.h"
#include "libmftypes.h"
#include "axm0_config.h"
#include "libmfwtimer.h"
#include "libmfi2cm.h"

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2

/* I2C descriptor definition */
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

extern struct i2c_descriptor _i2c0_descriptor;
extern struct i2c_descriptor _i2c1_descriptor;

extern uint32_t i2c_timer_baud_int(uint8_t baud, uint32_t clkfreq);
extern uint8_t i2c_init(struct i2c_descriptor *i2c_desc,uint8_t mode, uint8_t speed, uint8_t sel_div, uint8_t clk_src);
extern void i2c_write(struct i2c_descriptor *i2c_desc, uint16_t slaveAddress, uint8_t *wrData, uint8_t length, uint8_t repeated);
extern void i2c_read(struct i2c_descriptor *i2c_desc, uint16_t slaveAddress, uint8_t *rdData, uint8_t length, uint8_t repeated);
extern uint8_t i2c_getstatus(struct i2c_descriptor *i2c_desc);
extern uint8_t i2c_wait_until_done(struct i2c_descriptor *i2c_desc);
extern uint8_t i2c_close(struct i2c_descriptor *i2c_desc);
extern void i2c_handler(struct i2c_descriptor *i2c_desc);

#define AXM0F2_DIV_CTL_ADRS_OFFSET (uint32_t)(0x300/4)

#define I2C_OVS_MASK        0xFF
#define I2C_STANDARD_OVS    0x99
#define I2C_FAST_OVS        0x77

#define MASTER_MODE_POS         31
#define SLAVE_MODE_POS          30
#define S_GENERAL_IGNORE_POS    11

#define I2C_READ_FLAG   1

/* Requests to complete any on-going transfer */
#define I2C_CMPLT_ANY_TRANSFER     (0x01u)

#define I2C_IDLE_STATE      0
#define I2C_WRITE_STATE     1
#define I2C_READ_STATE      2

#define TX_TRIGGER_LEVEL 4  /* 1 to 8, Shouldnot program 0 */
#define RX_TRIGGER_LEVEL 4  /* 1 to 8, Shouldnot program 0 */

#define I2C_FIFO_SIZE      8

#define I2C_CTRL_ENABLED_POS       31
#define I2C_CTRL_ENABLED           ((uint32_t) 0x01u << I2C_CTRL_ENABLED_POS)

#define I2C_DEFAULT_CTRL   0

#define I2C_DEFAULT_I2C_CTRL   (0x1 << S_GENERAL_IGNORE_POS)

#define MSB_FIRST_POS   8
#define DATA_WIDTH      7

#define I2C_DEFAULT_RX_CTRL    ((0x1 << MSB_FIRST_POS) | DATA_WIDTH)
#define I2C_DEFAULT_TX_CTRL    ((0x1 << MSB_FIRST_POS) | DATA_WIDTH)

#define I2C_INTR_MASTER_I2C_ARB_LOST       ((uint32_t) 0x01u)
#define I2C_INTR_MASTER_I2C_NACK           ((uint32_t) 0x01u << 1)
#define I2C_INTR_MASTER_I2C_ACK            ((uint32_t) 0x01u << 2)
#define I2C_INTR_MASTER_I2C_STOP           ((uint32_t) 0x01u << 4)
#define I2C_INTR_MASTER_I2C_BUS_ERROR      ((uint32_t) 0x01u << 8)
#define I2C_INTR_MASTER_SPI_DONE           ((uint32_t) 0x01u << 9)

#define I2C_INTR_MASTER_ALL    (I2C_INTR_MASTER_I2C_ARB_LOST  | \
                                             I2C_INTR_MASTER_I2C_NACK      | \
                                             I2C_INTR_MASTER_I2C_ACK       | \
                                             I2C_INTR_MASTER_I2C_STOP      | \
                                             I2C_INTR_MASTER_I2C_BUS_ERROR | \
                                             I2C_INTR_MASTER_SPI_DONE)

#define I2C_INTR_MASTER_MASK   (I2C_INTR_MASTER_I2C_ARB_LOST | \
                                                 I2C_INTR_MASTER_I2C_NACK     | \
                                                 I2C_INTR_MASTER_I2C_STOP     | \
                                                 I2C_INTR_MASTER_I2C_BUS_ERROR)

#define I2C_MASTER_CMD_M_NACK_POS          (3u)  /* [3] Master generate NACK                 */
#define I2C_MASTER_CMD_M_NACK              ((uint32_t) 0x01u << I2C_MASTER_CMD_M_NACK_POS)

#define I2C_STATUS_M_READ_POS              (5u)  /* [5]    Master reads Slave           */
#define I2C_STATUS_M_READ                  ((uint32_t) 0x01u << I2C_STATUS_M_READ_POS)

#define I2C_STATUS_BUS_BUSY     0x1

#define I2C_INTR_RX_ALL             0xFED

#define I2C_MASTER_CMD_M_START         ((uint32_t) 0x01u)

#define I2C_MASTER_INTERRUPT_MASK       0x3FF
#define I2C_DATA_INTERRUPT_MASK         0xFF

#define I2C_INTR_TX_TRIGGER            ((uint32_t) 0x01u)
#define I2C_INTR_TX_FIFO_LEVEL         (I2C_INTR_TX_TRIGGER)
#define I2C_INTR_TX_NOT_FULL           ((uint32_t) 0x01u << 1)
#define I2C_INTR_TX_EMPTY              ((uint32_t) 0x01u << 4)
#define I2C_INTR_TX_OVERFLOW           ((uint32_t) 0x01u << 5)
#define I2C_INTR_TX_UNDERFLOW          ((uint32_t) 0x01u << 6)
#define I2C_INTR_TX_BLOCKED            ((uint32_t) 0x01u << 7)
#define I2C_INTR_TX_UART_NACK          ((uint32_t) 0x01u << 8)
#define I2C_INTR_TX_UART_DONE          ((uint32_t) 0x01u << 9)
#define I2C_INTR_TX_UART_ARB_LOST      ((uint32_t) 0x01u << 10)
#define I2C_INTR_RX_TRIGGER            ((uint32_t) 0x01u)
#define I2C_INTR_RX_FIFO_LEVEL         (I2C_INTR_RX_TRIGGER)
#define I2C_INTR_RX_NOT_EMPTY          ((uint32_t) 0x01u << 2)
#define I2C_INTR_RX_FULL               ((uint32_t) 0x01u << 3)
#define I2C_INTR_RX_OVERFLOW           ((uint32_t) 0x01u << 5)
#define I2C_INTR_RX_UNDERFLOW          ((uint32_t) 0x01u << 6)
#define I2C_INTR_RX_BLOCKED            ((uint32_t) 0x01u << 7)
#define I2C_INTR_RX_FRAME_ERROR        ((uint32_t) 0x01u << 8)
#define I2C_INTR_RX_PARITY_ERROR       ((uint32_t) 0x01u << 9)
#define I2C_INTR_RX_BAUD_DETECT        ((uint32_t) 0x01u << 10)
#define I2C_INTR_RX_BREAK_DETECT       ((uint32_t) 0x01u << 11)

#define I2C_CTRL_M_READY_DATA_ACK_POS         (8u)   /* [8]   Master ACKs data while RX FIFO != FULL*/

#define I2C_MASTER_CMD_M_ACK_POS        (2u)  /* [2] Master generate ACK                  */
#define I2C_MASTER_CMD_M_ACK            ((uint32_t) 0x01u << I2C_MASTER_CMD_M_ACK_POS)

#define I2C_TX_FIFO_CTRL_CLEAR_POS             (16u) /* [16]  Clear TX FIFO: cleared after set  */
#define I2C_TX_FIFO_CTRL_CLEAR                 ((uint32_t) 0x01u << I2C_TX_FIFO_CTRL_CLEAR_POS)

#define I2C_RX_FIFO_CTRL_CLEAR_POS             (16u) /* [16]  Clear TX FIFO: cleared after set  */
#define I2C_RX_FIFO_CTRL_CLEAR                 ((uint32_t) 0x01u << I2C_RX_FIFO_CTRL_CLEAR_POS)

#define I2C_SLAVE_ADDR_POS    (0x01u)    /* 7-bit address shift */
#define I2C_SLAVE_ADDR_MASK   (0xFEu)    /* 8-bit address mask */

/* Return 8-bit address. The input address should be 7-bits */
#define GET_I2C_8BIT_ADDRESS(addr) (((uint32_t) ((uint32_t) (addr) << I2C_SLAVE_ADDR_POS)) & I2C_SLAVE_ADDR_MASK)
#define GET_I2C_10BIT_ADDRESS(addr) (((uint32_t) ((uint32_t) (addr|0x08) << I2C_SLAVE_ADDR_POS)) & I2C_SLAVE_ADDR_MASK)

#define I2C_MASTER_CMD_M_START_ON_IDLE_POS     (1u)  /* [1] Master generate Start if bus is free */
#define I2C_MASTER_CMD_M_START_ON_IDLE ((uint32_t) 0x01u << I2C_MASTER_CMD_M_START_ON_IDLE_POS)

#define I2C_CTRL_M_READY_DATA_ACK      ((uint32_t) 0x01u << I2C_CTRL_M_READY_DATA_ACK_POS)

#endif /* __AXM0F2 */
#endif /* defined __ARMEL__ || defined __ARMEB__ */

#endif /* I2C_H */
