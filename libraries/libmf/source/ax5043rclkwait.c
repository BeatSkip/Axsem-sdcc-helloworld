/**
******************************************************************************
* @file ax5043waitxtal.c
* @brief Wait for rclk to be enabled
* @internal
* @author Pradeep Kumar GR
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
* @ingroup
*
* @details
*/

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include "axm0f143.h"
#endif /* __AXM0 */
#ifdef __AXM0F2
#include "axm0f243.h"
#endif /* __AXM0F2 */
#else
#include "ax8052f143.h"
#endif
#include "libmftypes.h"
#include "libmfradio.h"
#include "libmfwtimer.h"

__reentrantb void ax5043_rclk_wait_stable(uint8_t wtflag) __reentrant
{
    uint8_t irqmask;
    criticalsection_t crit = enter_critical();

    /* Backup IRQMASK1 register content */
    irqmask = radio_read8(AX5043_REG_IRQMASK1);

    /* Enable xtal ready interrupt */
    radio_write8(AX5043_REG_IRQMASK1,(radio_read8(AX5043_REG_IRQMASK1) | 0x01));

    for(;;) {
        reenter_critical();
        if(radio_read8(AX5043_REG_XTALSTATUS) & 0x01)
            break;

        wtimer_idle(wtflag);

        exit_critical(crit);
        wtimer_runcallbacks();
    }

    /* Restore IRQMASK1 register content */
    radio_write8(AX5043_REG_IRQMASK1, irqmask);

    exit_critical(crit); /* Restore all Interrupts */
}
