/**
******************************************************************************
* @file axm0_uart.h
* @brief UART structure and APIs declarations
* @internal
* @author   Pradeep Kumar G R, Thomas Sailer
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

#ifndef AXM0_UART_H
#define AXM0_UART_H

#if defined __ARMEL__ || defined __ARMEB__
#include "libmftypes.h"
#include "cpu.h"
#include "libmfuart0.h"

struct uart_fifo_pointers {
	uint16_t txwr;
	uint16_t txrd;
	uint16_t rxwr;
	uint16_t rxrd;
};

struct uart_descriptor {
	struct uart_fifo_pointers *fifoptr;
	uint8_t                   *txbuffer;
	uint8_t                   *rxbuffer;
	const uint16_t            *txbuffersize;
	const uint16_t            *rxbuffersize;
	void                      *membase;
	IRQn_Type                 irqnum;
	uint8_t                   uartnum;
};

extern const struct uart_descriptor _uart0_descriptor;
extern const struct uart_descriptor _uart1_descriptor;

#ifdef __AXM0

#include "axm0.h"
#include "axm0_config.h"

#define AXM0_UART_DEFAULT_CLK_DIV       5
#define AXM0_UART_INIT_NUM_SHFT         26
#define AXM0_UART_DEFAULT_NUM_SHFT      48
#define AXM0_TIM_OP_MODE_MUL_SAWTTH_DN  5
#define AXM0_UART_DISABLE_BIT           0

#endif /* __AXM0 */

#ifdef __AXM0F2

#include "axm0f2.h"
#include "axm0_config.h"

#define AXM0_UART_DEFAULT_CLK_DIV           5
#define AXM0_UART_INIT_NUM_SHFT             26
#define AXM0_UART_DEFAULT_NUM_SHFT          48
#define AXM0_TIM_OP_MODE_MUL_SAWTTH_DN      5
#define AXM0_UART_DISABLE_BIT               0

#define AXM0F2_UART_CTRL_STD_MODE_BIT_POS   24
#define AXM0F2_UART_CTRL_STD_MODE_EN        0
#define AXM0F2_UART_CTRL_PARITY_BIT_POS     5
#define AXM0F2_UART_CTRL_PARITY_OFF         0
#define AXM0F2_UART_CTRL_STOP_BIT_POS       0
#define AXM0F2_UART_CTRL_DATA_LEN_BIT_POS   0
#define AXM0F2_UART_CTRL_RCV_TRGLEV_BIT_POS 0
#define AXM0F2_UART_CTRL_RCV_TRGLEV         7
#define AXM0F2_UART_CTRL_FIFOCLEAR_BIT_POS  16
#define AXM0F2_UART_CTRL_SCB_EN_BIT_POS     31
#define AXM0F2_UART_CTRL_SCB_EN             1
#define AXM0F2_UART_CTRL_SCB_MODE_BIT_POS   24
#define AXM0F2_UART_CTRL_SCB_MODE_UART      2
#define AXM0F2_UART_CTRL_OVS_BIT_POS        0
#define AXM0F2_UART_CTRL_OVS                (8 - 1) /* 48M / 8 =  6M */

#define AXM0F2_HSIOM_PORT_SEL_MASK          0xF
#define AXM0F2_HSIOM_PORT_SEL_UART1         0xB
#define AXM0F2_HSIOM_PORT_SEL_UART1_TX      20
#define AXM0F2_HSIOM_PORT_SEL_UART1_RX      16

#define AXM0F2_HSIOM_PORT_SEL_MASK          0xF
#define AXM0F2_HSIOM_PORT_SEL_UART0         0x9
#define AXM0F2_HSIOM_PORT_SEL_UART0_TX      4
#define AXM0F2_HSIOM_PORT_SEL_UART0_RX      0

#define AXM0F2_GPIO_SCB2_UART1_TX_PIN       5
#define AXM0F2_GPIO_SCB2_UART1_RX_PIN       4

#define AXM0F2_GPIO_SCB2_UART0_TX_PIN       1
#define AXM0F2_GPIO_SCB2_UART0_RX_PIN       0

#define AXM0F2_GPIO_PIN_EN                  1
#define AXM0F2_GPIO_PIN_DIS                 0

#define AXM0F2_GPIO_PORT_PC_DM_MASK         7
#define AXM0F2_GPIO_PORT_PC_DM_UART_TX      6
#define AXM0F2_GPIO_PORT_PC_DM_UART_RX      6

#define AXM0F2_GPIO_PORT_PC_DM_UART1_TX_POS 15
#define AXM0F2_GPIO_PORT_PC_DM_UART1_RX_POS 12

#define AXM0F2_GPIO_PORT_PC_DM_UART0_TX_POS 3
#define AXM0F2_GPIO_PORT_PC_DM_UART0_RX_POS 0

#define AXM0F2_SCB_INTR_CAUSE_RX_MASK       0x00000008
#define AXM0F2_SCB_INTR_CAUSE_TX_MASK       0x00000004
#define AXM0F2_SCB_INTR_TX_UART_DONE_MASK   0x00000200
#define AXM0F2_SCB_INTR_TX_NOT_FULL_MASK    0x00000002
#define AXM0F2_SCB_INTR_TX_EMPTY_MASK       0x00000010
#define AXM0F2_SCB_INTR_RX_NOT_EMPTY_MASK   0x00000004

#define AXM0F2_SCB_FIFO_STAT_USED_MASK      0x0000000F
#define AXM0F2_SCB_FIFO_STAT_SR_VALID_MASK  0x00008000

#endif /* __AXM0F2 */

extern void axm0_uart_init(const struct uart_descriptor *uart_desc, uint8_t timernr, uint8_t wl, uint8_t stop);
extern void axm0_uart_txadvance(const struct uart_descriptor *uart_desc, uint8_t idx);
extern void axm0_uart_wait_txfree(const struct uart_descriptor *uart_desc, uint8_t v);
extern void axm0_uart_tx(const struct uart_descriptor *uart_desc, uint8_t v);
extern void axm0_uart_wait_txdone(const struct uart_descriptor *uart_desc);
extern void axm0_uart_rxadvance(const struct uart_descriptor *uart_desc, uint8_t idx);
extern void axm0_uart_writehexu16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig);
extern void axm0_uart_txpokehex(const struct uart_descriptor *uart_desc, uint8_t idx, uint8_t ch);
extern void axm0_uart_txpoke(const struct uart_descriptor *uart_desc, uint8_t idx, uint8_t ch);
extern void axm0_uart_writehexu32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig);
extern uint8_t axm0_uart_writehex16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig1, uint8_t flags1);
extern uint8_t axm0_uart_txfree(const struct uart_descriptor *uart_desc);
extern uint8_t axm0_uart_rxcountlinear(const struct uart_descriptor *uart_desc);
extern uint8_t axm0_uart_txfreelinear(const struct uart_descriptor *uart_desc);
extern uint8_t axm0_uart_rxpeek(const struct uart_descriptor *uart_desc, uint8_t idx);
extern uint8_t axm0_uart_txbusy(const struct uart_descriptor *uart_desc);
extern uint8_t axm0_uart_poll(const struct uart_descriptor *uart_desc);
extern uint8_t axm0_uart_writehex32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig1, uint8_t flags1);
extern uint8_t axm0_uart_writenum16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig1, uint8_t flags1);
extern uint8_t axm0_uart_writenum32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig1, uint8_t flags1);
extern uint8_t axm0_uart_rxcount(const struct uart_descriptor *uart_desc);
extern uint8_t axm0_uart_poll(const struct uart_descriptor *uart_desc);
extern uint8_t axm0_uart_iocore(const struct uart_descriptor *uart_desc);
extern uint8_t __xdata *axm0_uart_txbufptr(const struct uart_descriptor *uart_desc, uint8_t idx);
extern uint8_t axm0_uart_txbuffersize(const struct uart_descriptor *uart_desc);
extern uint8_t axm0_uart_rxbuffersize(const struct uart_descriptor *uart_desc);
extern uint8_t axm0_uart_txidle(const struct uart_descriptor *uart_desc);
extern const uint8_t __xdata *axm0_uart_rxbufptr(const struct uart_descriptor *uart_desc, uint8_t idx);
extern void axm0_uart_stop(const struct uart_descriptor *uart_desc);
extern void axm0_uart_tx(const struct uart_descriptor *uart_desc, uint8_t v);
extern void axm0_uart_wait_rxcount(const struct uart_descriptor *uart_desc, uint8_t v);
extern uint8_t axm0_uart_rx(const struct uart_descriptor *uart_desc);
extern void axm0_uart_writestr(const struct uart_descriptor *uart_desc, const char *ch);
extern uint8_t axm0_uart_writehex16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig1, uint8_t flags1);
extern uint8_t axm0_uart_writehex32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig1, uint8_t flags1);
extern void axm0_uart_writehexu16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig);
extern void axm0_uart_writehexu32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig);
extern uint8_t axm0_uart_writenum16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig1, uint8_t flags1);
extern uint8_t axm0_uart_writenum32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig1, uint8_t flags1);
extern void axm0_uart_writeu16(const struct uart_descriptor *uart_desc, uint16_t val, uint8_t nrdig);
extern void axm0_uart_writeu32(const struct uart_descriptor *uart_desc, uint32_t val, uint8_t nrdig);
extern void uart_wait_txfree(uint8_t v);
extern void uart_txpoke(uint8_t idx, uint8_t ch) ;
extern void uart_txadvance(uint8_t idx) ;

#endif /* defined __ARMEL__ || defined __ARMEB__ */
#endif /* AXM0_UART_H */
