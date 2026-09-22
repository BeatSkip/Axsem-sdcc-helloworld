/**
******************************************************************************
* @file flashlock.c
* @brief Flash erase/write lock
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

void flash_lock(void)
{
	__flash_lock = AXM0F2_FLASH_LOCK; /* Flash lock */
}

#endif /* __AXM0F2 */

#ifdef __AXM0

#include "axm0_flash.h"

void flash_lock(void)
{
    uint32_t temp_pclk;
    temp_pclk = CMU->PCLK_CFG;                   /* Store PCLK register */
    CMU->PCLK_CFG_b.FLASH_EN = 1;                /* Enable flash clock */

    FLASH->PROTECT0 = AXM0_FLASH_LOCK_ALL;       /* Lock pages from 0-31   */
    FLASH->PROTECT1 = AXM0_FLASH_LOCK_ALL;       /* Lock pages from 32-63  */
    FLASH->PROTECT2 = AXM0_FLASH_LOCK_ALL;       /* Lock pages from 64-95  */
    FLASH->PROTECT3 = AXM0_FLASH_LOCK_ALL;       /* Lock pages from 96-127 */

    CMU->PCLK_CFG = temp_pclk;                   /* Restore PCLK register */
}

#endif

#else /* Other than ARM */

void flash_lock(void)
{
	NVKEY = 0;
}

#endif /* defined __ARMEL__ || defined __ARMEB__ */
