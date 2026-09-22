/**
******************************************************************************
* @file axm0_flash.h
* @brief Flash macro definitions
* @internal
* @author   Pradeep Kumar G R
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
* @ingroup FLASH
*
* @details
*/


#if defined __ARMEL__ || defined __ARMEB__
#ifndef AXM0_FLASH_H
#define AXM0_FLASH_H
#include "libmftypes.h"
#include "axm0_config.h"

#define AXM0F2_FLASH_LOCK			0
#define AXM0F2_FLASH_UNLOCK			1

#define AXM0F2_FLASH_CLK_SEL_IMO	0x10

#define AXM0F2_FLASH_SIZE 			0x10000
#define AXM0F2_FLASH_ROW_SIZE		0x80
#define AXM0F2_FLASH_NUMBER_ROWS	(AXM0F2_FLASH_SIZE / AXM0F2_FLASH_ROW_SIZE)
#define AXM0F2_FLASH_SRAM_ROM_KEY1  0
#define AXM0F2_FLASH_SRAM_ROM_DATA  (AXM0F2_FLASH_SRAM_ROM_KEY1 + 0x08u)
#define AXM0F2_FLASH_KEY_TWO(x)     ((uint32_t) (((uint16_t) 0xD3u) + ((uint16_t) (x))))
#define AXM0F2_FLASH_MACRO_FROM_ROW 0
#define AXM0F2_NOP					__asm("NOP\n")
#define AXM0F2_FLASH_API_RETURN		(((CPUSS->SYSARG & 0xF0000000u) == 0xF0000000u) ? \
									(CPUSS->SYSARG & 0x000000FFu) : \
									(((CPUSS->SYSARG & 0xF0000000u) == 0xA0000000u) ? \
									 LIBMF_FLASH_STATUS_SUCCESS : (CPUSS->SYSARG & 0x000000FFu)))

#define AXM0F2_FLASH_PARAM_MACRO_SEL_OFFSET	24
#define AXM0F2_FLASH_PARAM_ADDR_OFFSET		16
#define AXM0F2_FLASH_PARAM_KEY_TWO_OFFSET	8
#define AXM0F2_FLASH_PARAM_ROW_NUM_OFFSET	16
#define AXM0F2_FLASH_KEY_ONE				0xB6
#define AXM0F2_FLASH_CPUSS_REQ_START		(1 << 31)
#define AXM0F2_SYS_CLK_IMO_CONFIG_ENABLE	(1 << 31)
#define AXM0F2_SYS_CLK_IMO_MIN_FREQ_MHZ		24

#define AXM0F2_FLASH_PROTECT_UNLOCK			1
#define AXM0F2_FLASH_PROTECT_LOCK			2
#define AXM0F2_FLASH_PROTECT_OFFSET			16
#define AXM0F2_FLASH_PROTECTION_BYTES		64
#define AXM0F2_FLASH_PROTECTION_LOCK_BITS	0xFF
#define AXM0F2_FLASH_PROTECTION_UNLOCK_BITS	0x00

#define AXM0F2_SYS_CLK_WCO_CONFIG_DPLL_ENABLE   (1 << 30)
#define AXM0F2_SYS_CLK_SELECT_DIRECT_SEL_MASK   3
#define AXM0F2_SYS_CLK_HFCLK_IMO                0
#define AXM0F2_SYS_CLK_SELECT_PUMP_SEL_SHIFT    4
#define AXM0F2_SYS_CLK_SELECT_PUMP_SEL_MASK     3
#define AXM0F2_SYS_CLK_SELECT_PUMP_SEL_IMO      1
#define AXM0F2_SYS_CLK_IMO_CONFIG_ENABLE        (1 << 31)
#define AXM0F2_SYS_CLK_SELECT_HFCLK_SEL_MASK 0x0

#define AXM0F2_FLASH_API_OPCODE_LOAD		0x4
#define AXM0F2_FLASH_API_OPCODE_WRITE_ROW 	0x5
#define AXM0F2_FLASH_API_OPCODE_PROGRAM_ROW	0x6
#define AXM0F2_FLASH_API_OPCODE_PROTECT		0xD
#define AXM0F2_FLASH_API_OPCODE_CLK_CONFIG 	0x15

#define AXM0F2_FLASH_PAGE_LATCH_START_ADDR	0
#define AXM0F2_FLASH_USER_DATA_BUF_SZ		4

extern uint8_t __flash_lock; /* Flash lock emulation variable */

#endif /* AXM0_FLASH_H */
#endif /* defined __ARMEL__ || defined __ARMEB__ */
