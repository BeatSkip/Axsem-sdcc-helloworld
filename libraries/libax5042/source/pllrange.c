/**
******************************************************************************
* @file pllrange.c
* @brief
* @internal
* @author   Thomas Sailer
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a "ON Semiconductor").
* All rights reserved.  This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions.  The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software") and
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
* @ingroup
*
* @details
*/

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include <axm0f142.h>
#endif
#ifdef __AXM0F2
#include <axm0f242.h>
#endif
#else
#include <ax8052f142.h>
#endif
#include <libmfradio.h>
#include <libax5042.h>

/**
 * \brief Ranges the AX5042 PLL
 * After 10 attemts an error is returned
 *
 * \returns PLL range result
 */

uint8_t ax5042_pllrange(uint8_t range)
{
    uint8_t __autodata r, rcount = 10;

    radio_write8(AX5042_REG_PWRMODE, 0x00);
    radio_write8(AX5042_REG_PWRMODE, 0x0C);   	// set mode synth TX

    radio_write8(AX5042_REG_PLLRANGING, 0x10 | (range & 0x0f));  // start value typical 0x08

    do
    {
        delay(2000);
        r = radio_read8(AX5042_REG_PLLRANGING);
	if (!(r & 0x10))
		break;
    } while (--rcount);

    r &= 0x3F;
    return r;
}
