/**
******************************************************************************
* @file flashwait.c
* @brief Waits for flash to complete erase/write operation
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

/* Flash wait not required. Flash_write/erase handles themselves */

#else /* Other than ARM */

int8_t flash_wait(uint16_t timeout)
{
	uint8_t __autodata st;
	uint8_t __autodata cnth = timeout >> 8;
	uint8_t __autodata cntl = timeout;
	++cnth;
	++cntl;
	do {
		do {
			st = NVSTATUS;
			if (!(st & 2))
				return LIBMF_FLASH_STATUS_LOCKED;
			if (!(st & 1))
				return LIBMF_FLASH_STATUS_SUCCESS;
			--cntl;
		} while (cntl);
		--cnth;
	} while (cnth);
	return LIBMF_FLASH_STATUS_FAIL;
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */


