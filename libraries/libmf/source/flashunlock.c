/**
******************************************************************************
* @file flashunlock.c
* @brief Unlocks flash erase/write protection
* @internal
* @author   Thomas Sailer, Pradeep Kumar GR
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

uint8_t __flash_lock = AXM0F2_FLASH_LOCK; /* By default flash is locked */

void flash_unlock(void)
{
	__flash_lock = AXM0F2_FLASH_UNLOCK; /* Flash unlock */
}

#endif /* __AXM0F2 */

#ifdef __AXM0

void flash_unlock(void)
{
    CMU->PCLK_CFG_b.FLASH_EN = 1;   /* Enable flash clock */

    FLASH->PROTECT0 = 0x0;          /* Unlock pages from 0-31   */
    FLASH->PROTECT1 = 0x0;          /* Unlock pages from 32-63  */
    FLASH->PROTECT2 = 0x0;          /* Unlock pages from 64-95  */
    FLASH->PROTECT3 = 0x0;          /* Unlock pages from 96-127 */
}

#endif

#else /* Other than ARM */

void flash_unlock(void)
{
	criticalsection_t crit;
	crit = enter_critical();
	NVKEY = 0x41;
	NVKEY = 0x78;
	exit_critical(crit);
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */

