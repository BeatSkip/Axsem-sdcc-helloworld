/**
******************************************************************************
* @file libmfflash.h
* @brief Flash driver APIs declaration
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

#ifndef LIBMFFLASH_H
#define LIBMFFLASH_H

#include "libmftypes.h"

/*
 * FLASH
 */

#define LIBMF_FLASH_STATUS_SUCCESS 			0
#define LIBMF_FLASH_STATUS_FAIL 			1
#define LIBMF_FLASH_STATUS_INVALID_PARAM 	2
#define LIBMF_FLASH_STATUS_LOCKED 			3

extern void flash_unlock(void);
extern void flash_lock(void);
extern int8_t flash_wait(uint16_t timeout);
extern int8_t flash_pageerase(uint16_t pgaddr);
extern int8_t flash_write(uint16_t waddr, uint16_t wdata);
extern uint16_t flash_read(uint16_t raddr);

extern uint8_t flash_apply_calibration(void);
typedef uint8_t flash_deviceid_t[6];
#if defined(SDCC)
static __xdata flash_deviceid_t __at(0xfc06) flash_deviceid;
#elif defined __CX51__ || defined __C51__
static flash_deviceid_t xdata flash_deviceid _at_ 0xfc06;
#elif defined __ICC8051__
static __xdata __no_init flash_deviceid_t flash_deviceid @ 0xfc06;
#endif

#endif /* LIBMFFLASH_H */
