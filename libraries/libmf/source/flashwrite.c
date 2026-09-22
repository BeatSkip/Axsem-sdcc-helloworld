/**
******************************************************************************
* @file flashwrite.c
* @brief Flash write
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

int8_t flash_write(uint16_t waddr, uint16_t wdata)
{
	criticalsection_t int_state;
	uint32_t rowNum			= waddr / AXM0F2_FLASH_ROW_SIZE;	/* Destination row number */
	uint8_t  rowOffset		= ((waddr % AXM0F2_FLASH_ROW_SIZE) & ~1U); /* Even address offset in the destination row */
	uint8_t  retValue		= LIBMF_FLASH_STATUS_SUCCESS;
	uint32_t parameters[(AXM0F2_FLASH_USER_DATA_BUF_SZ + AXM0F2_FLASH_SRAM_ROM_DATA) / sizeof(uint32_t)] __attribute__((aligned (4))); /* RAM buffer - aligned on 4-byte address */
	uint16_t *para_ptr		= (uint16_t *)parameters; /* Pointer to access RAM buffer in byte */
	uint32_t clkSelectReg;

	if(__flash_lock == AXM0F2_FLASH_LOCK)
	{
		return(LIBMF_FLASH_STATUS_LOCKED);
	}

	if (waddr < AXM0F2_FLASH_SIZE)
	{
		/* Copy data to be written into internal buffer @ address offset */
		para_ptr[4] =  wdata;

		/* Load Flash Bytes system call*/
		parameters[0] = (uint32_t) (AXM0F2_FLASH_MACRO_FROM_ROW						<< AXM0F2_FLASH_PARAM_MACRO_SEL_OFFSET) |
						 (uint32_t) (rowOffset      									<< AXM0F2_FLASH_PARAM_ADDR_OFFSET) 		|
						 (uint32_t) (AXM0F2_FLASH_KEY_TWO(AXM0F2_FLASH_API_OPCODE_LOAD) << AXM0F2_FLASH_PARAM_KEY_TWO_OFFSET) 	|
						 AXM0F2_FLASH_KEY_ONE;
		parameters[1] = sizeof(uint16_t) - 1;

		CPUSS->SYSARG = (uint32_t) &parameters[0];
		CPUSS->SYSREQ =  AXM0F2_FLASH_CPUSS_REQ_START | AXM0F2_FLASH_API_OPCODE_LOAD ;
		AXM0F2_NOP;
		retValue = AXM0F2_FLASH_API_RETURN;

		if(retValue == LIBMF_FLASH_STATUS_SUCCESS)
		{
			/* Mask all the interrupts to guarantee the Flash write in atomic way */
			int_state = enter_critical();

			/* Clock Backup */
			clkSelectReg = SRSSLT->CLK_SELECT;

			SRSSLT->CLK_SELECT = AXM0F2_FLASH_CLK_SEL_IMO; /* Select IMO clock */

			/* Write Row system call */
			parameters[0]  = (uint32_t)(((uint32_t) AXM0F2_FLASH_KEY_TWO(AXM0F2_FLASH_API_OPCODE_PROGRAM_ROW) <<  AXM0F2_FLASH_PARAM_KEY_TWO_OFFSET) |
							 (uint32_t)(rowNum 																  << AXM0F2_FLASH_PARAM_ROW_NUM_OFFSET) |
							  AXM0F2_FLASH_KEY_ONE);

			CPUSS->SYSARG = (uint32_t) &parameters[0];
			CPUSS->SYSREQ = AXM0F2_FLASH_CPUSS_REQ_START | AXM0F2_FLASH_API_OPCODE_PROGRAM_ROW;
			AXM0F2_NOP;
			retValue = AXM0F2_FLASH_API_RETURN;

			/* Restore HFCLK divider and source for pump  */
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

int8_t flash_write(uint16_t waddr, uint16_t wdata)
{
	FLASH->FLASHDATA = wdata;    /* Set data needs to be programmed */
	FLASH->ADDR = waddr;         /* Set address needs to be written */

	if (waddr & 0x3) {
		/* Address is multiple of 2, use up_half option */
		FLASH->CTL = (AXM0_FLASH_CONTROL_CONF | AXM0_FLASH_CMD_START_PROG | AXM0_FLASH_CMD_16_BIT_WRT | AXM0_FLASH_CMD_UP_HALF);
	} else {
		/* Address is multiple of 4, use low_half option */
		FLASH->CTL  = (AXM0_FLASH_CONTROL_CONF | AXM0_FLASH_CMD_START_PROG | AXM0_FLASH_CMD_16_BIT_WRT);
	}

	while(!(FLASH->CTL_b.STATE)); 	/* Wait till write is finished */

	return LIBMF_FLASH_STATUS_SUCCESS;
}

#endif /* __AXM0xx */

#else /* Other than ARM */

int8_t flash_write(uint16_t waddr, uint16_t wdata)
{
	NVADDR0 = waddr;
	NVADDR1 = waddr >> 8;
	NVDATA0 = wdata;
	NVDATA1 = wdata >> 8;
	NVSTATUS = 0x30;
	return flash_wait(128);
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */

