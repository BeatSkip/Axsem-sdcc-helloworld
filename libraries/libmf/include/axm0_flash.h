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

#define AXM0_FLASH_CONTROL_CONF			(uint32_t)0xA45B0000

#define AXM0_FLASH_CMD_START_PROG		(uint32_t)(1 << 0)
#define AXM0_FLASH_CMD_PAGE_ERASE		(uint32_t)(1 << 1)
#define AXM0_FLASH_CMD_16_BIT_WRT		(uint32_t)(1 << 3)
#define AXM0_FLASH_CMD_UP_HALF   		(uint32_t)(1 << 4)

#define AXM0_FLASH_LOCK_ALL             (uint32_t)0xFFFFFFFF

#endif /* AXM0_FLASH_H */
#endif /* defined __ARMEL__ || defined __ARMEB__ */
