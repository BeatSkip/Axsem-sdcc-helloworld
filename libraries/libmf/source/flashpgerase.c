/**
******************************************************************************
* @file flasherase.c
* @brief Flash erase operation
* @internal
* @author   Thomas Sailer, Pradeep Kumar G R
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

#include "cpu.h"
#include "libmfflash.h"

#if defined __ARMEL__ || defined __ARMEB__

#ifdef __AXM0F2
#include "axm0f2.h"
#include "axm0f2_flash.h"
#include "libmfstring.h"

int8_t flash_pageerase(uint16_t pgaddr)
{
	criticalsection_t int_state;
	uint32_t rowNum			= pgaddr / AXM0F2_FLASH_ROW_SIZE;	/* Destination row number */
	uint32_t retValue		= LIBMF_FLASH_STATUS_SUCCESS;
	uint32_t parameters[(AXM0F2_FLASH_USER_DATA_BUF_SZ + AXM0F2_FLASH_SRAM_ROM_DATA) / sizeof(uint32_t)] __attribute__((aligned (4))); /* RAM buffer - aligned on 4-byte address */
	volatile uint32_t clkSelectReg;

	if(__flash_lock == AXM0F2_FLASH_LOCK)
	{
		return(LIBMF_FLASH_STATUS_LOCKED);
	}

	if (pgaddr < AXM0F2_FLASH_SIZE)
	{
		/* Cache - Copy data from destination row to RAM buffer */
		(void)memset((void *)&parameters[2], 0, ((AXM0F2_FLASH_USER_DATA_BUF_SZ) / sizeof(uint32_t)));

		/* Load Flash Bytes system call*/
		parameters[0] = (uint32_t) (AXM0F2_FLASH_MACRO_FROM_ROW						<< AXM0F2_FLASH_PARAM_MACRO_SEL_OFFSET) |
						 (uint32_t) (AXM0F2_FLASH_PAGE_LATCH_START_ADDR      			<< AXM0F2_FLASH_PARAM_ADDR_OFFSET) 		|
						 (uint32_t) (AXM0F2_FLASH_KEY_TWO(AXM0F2_FLASH_API_OPCODE_LOAD) << AXM0F2_FLASH_PARAM_KEY_TWO_OFFSET) 	|
						 AXM0F2_FLASH_KEY_ONE;
		parameters[1] = 1 - 1; 	/* Write minimum 1 byte of empty buffer to erase */

		CPUSS->SYSARG = (uint32_t) &parameters[0];
		CPUSS->SYSREQ =  AXM0F2_FLASH_CPUSS_REQ_START | AXM0F2_FLASH_API_OPCODE_LOAD ;
		AXM0F2_NOP;
		retValue = AXM0F2_FLASH_API_RETURN;

		if(retValue == LIBMF_FLASH_STATUS_SUCCESS)
		{
			/* Mask all the interrupts to guarantee the Flash write in atomic way */
			int_state = enter_critical();

			/* Clock select Backup */
			clkSelectReg = SRSSLT->CLK_SELECT;

			SRSSLT->CLK_SELECT = AXM0F2_FLASH_CLK_SEL_IMO; /* Select IMO clock */

			/* Write empty buffer to erase */
			parameters[0]  = (uint32_t) (((uint32_t) AXM0F2_FLASH_KEY_TWO(AXM0F2_FLASH_API_OPCODE_WRITE_ROW) << AXM0F2_FLASH_PARAM_KEY_TWO_OFFSET) |
							  (uint32_t)(rowNum << AXM0F2_FLASH_PARAM_ROW_NUM_OFFSET) |
							   AXM0F2_FLASH_KEY_ONE);

			CPUSS->SYSARG = (uint32_t) &parameters[0];
			CPUSS->SYSREQ = AXM0F2_FLASH_CPUSS_REQ_START | AXM0F2_FLASH_API_OPCODE_WRITE_ROW;
			AXM0F2_NOP;
			retValue = AXM0F2_FLASH_API_RETURN;

			/* Restore clock select  */
			SRSSLT->CLK_SELECT = clkSelectReg;

			exit_critical(int_state);
		}
	}
	else
	{
		retValue = LIBMF_FLASH_STATUS_INVALID_PARAM;
	}

	return (retValue);
}

#elif defined __AXM0

#include "axm0_flash.h"

int8_t flash_pageerase(uint16_t pgaddr)
{
    FLASH->ADDR = pgaddr;  /* Address needs to be erased */

    /* Page erase command */
    FLASH->CTL = (AXM0_FLASH_CONTROL_CONF | AXM0_FLASH_CMD_PAGE_ERASE);

    while(!(FLASH->CTL_b.STATE)); /* Wait till erase is finished */

    return LIBMF_FLASH_STATUS_SUCCESS;
}

#endif /* __AXM0F2 */

#else /* Other than ARM */

int8_t flash_pageerase(uint16_t pgaddr)
{
	NVADDR0 = pgaddr;
	NVADDR1 = pgaddr >> 8;
	NVSTATUS = 0x20;
	return flash_wait(65535);
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */
