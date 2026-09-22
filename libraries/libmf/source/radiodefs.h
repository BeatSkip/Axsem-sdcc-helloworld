/**
******************************************************************************
* @file radiodefs.h
* @brief Radio defines include file
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
* @ingroup RADIO
*
* @details
*/

#ifndef RADIODEFS_H
#define RADIODEFS_H

#if RADIO == 5031

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include "axm0f131.h"
#elif defined __AXM0F2
#include "axm0f231.h"
#endif /* End of __AXM0 or __AXM0F2 */
#else
#include "ax8052f131.h"
#endif

#define radio_probeirq         ax5031_probeirq
#define radio_comminit         ax5031_comminit
#define radio_commsleepexit    ax5031_commsleepexit
#define radio_reset            ax5031_reset
#define radio_readfifo         ax5031_readfifo
#define radio_writefifo        ax5031_writefifo
#define RACC                   0x00
#define FDATA                  0x005
#define FSTAT                  0x004
#define DEEPSLEEP              0
#define VREGDELAY              10

#define RADIO_SILICONREVISION  AX5031_REG_SILICONREVISION
#define RADIO_SCRATCH          AX5031_REG_SCRATCH
#define RADIO_PWRMODE          AX5031_REG_PWRMODE

#define PWRMODE_PWRDOWN        0x00

#define SILICONREV1            0x21
#undef SILICONREV2

#elif RADIO == 5042

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2
#include "axm0f242.h"
#else
#include "axm0f142.h"
#endif
#else
#include "ax8052f142.h"
#endif

#define radio_probeirq         ax5042_probeirq
#define radio_comminit         ax5042_comminit
#define radio_commsleepexit    ax5042_commsleepexit
#define radio_reset            ax5042_reset
#define radio_readfifo         ax5042_readfifo
#define radio_writefifo        ax5042_writefifo
#define RACC                   0x00
#define FDATA                  0x005
#define FSTAT                  0x004
#define DEEPSLEEP              0
#define VREGDELAY              0

#define RADIO_SILICONREVISION  AX5042_REG_SILICONREVISION
#define RADIO_SCRATCH          AX5042_REG_SCRATCH
#define RADIO_PWRMODE          AX5042_REG_PWRMODE

#define PWRMODE_PWRDOWN        0x00

#define SILICONREV1            0x02
#undef SILICONREV2

#elif RADIO == 5043

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include "axm0f143.h"
#elif defined __AXM0F2
#include "axm0f243.h"
#endif /* End of __AXM0 or __AXM0F2 */
#else
#include "ax8052f143.h"
#endif

#define radio_probeirq         ax5043_probeirq
#define radio_comminit         ax5043_comminit
#define radio_commsleepexit    ax5043_commsleepexit
#define radio_reset            ax5043_reset
#define radio_readfifo         ax5043_readfifo
#define radio_writefifo        ax5043_writefifo
#define radio_enter_deepsleep  ax5043_enter_deepsleep
#define radio_wakeup_deepsleep ax5043_wakeup_deepsleep
#define radio_rclk_enable	   ax5043_rclk_enable
#define RACC                   0x0c
#define FDATA                  0x029
#define FSTAT                  0x028
#define DEEPSLEEP              1
#define VREGDELAY              10

#define RADIO_SILICONREVISION  AX5043_REG_SILICONREVISION
#define RADIO_SCRATCH          AX5043_REG_SCRATCH
#define RADIO_PWRMODE          AX5043_REG_PWRMODE

#define PWRMODE_PWRDOWN        0x00
#define PWRMODE_DEEPSLEEP      0x01

#define SILICONREV1            0x51
#undef SILICONREV2

#elif RADIO == 5044 /* or 5045 */

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
/* #include "axm0f144.h" */
#elif defined __AXM0F2
/* #include "axm0f244.h" */
#endif /* End of __AXM0 or __AXM0F2 */
#else /* Non - ARM */
#include "ax8052f144_45.h"
#endif

#define radio_probeirq         ax5044_45_probeirq
#define radio_comminit         ax5044_45_comminit
#define radio_commsleepexit    ax5044_45_commsleepexit
#define radio_reset            ax5044_45_reset
#define radio_readfifo         ax5044_45_readfifo
#define radio_writefifo        ax5044_45_writefifo
#define radio_enter_deepsleep  ax5044_45_enter_deepsleep
#define radio_wakeup_deepsleep ax5044_45_wakeup_deepsleep
#define radio_rclk_enable	   ax5044_45_rclk_enable
#define RACC                   0x0c
#define FDATA                  0x029
#define FSTAT                  0x028
#define DEEPSLEEP              1
#define VREGDELAY              10

#define RADIO_SILICONREVISION  AX5044_45_REG_SILICONREVISION
#define RADIO_SCRATCH          AX5044_45_REG_SCRATCH
#define RADIO_PWRMODE          AX5044_45_REG_PWRMODE

#define PWRMODE_PWRDOWN        0x00
#define PWRMODE_DEEPSLEEP      0x01

/**
 *  ___________________________________
 * | Device |  Rev  | Silicon Revision |
 * |________|_______|__________________|
 * | AX5044 | Rev A |     0x34      |
 * |        | Rev B |     0x37         |
 * |        | Rev C |     0x3A         |
 * |________|__________________________|
 * | AX5045 | Rev A |     0x35         |
 * |        | Rev B |     0x38         |
 * |        | Rev C |     0x3B         |
 * |        | Rev E |     0x46         |
 * |________|_______|__________________|
 *
 */

#define SILICONREV1             0x3A
#define SILICONREV2             0x46

#elif RADIO == 5051

#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0F2
#include "axm0f251.h"
#else
#include "axm0f151.h"
#endif
#else
#include "ax8052f151.h"
#endif

#define radio_probeirq         ax5051_probeirq
#define radio_comminit         ax5051_comminit
#define radio_commsleepexit    ax5051_commsleepexit
#define radio_reset            ax5051_reset
#define radio_readfifo         ax5051_readfifo
#define radio_writefifo        ax5051_writefifo
#define RACC                   0x00
#define FDATA                  0x005
#define FSTAT                  0x004
#define DEEPSLEEP              0
#define VREGDELAY              0

#define RADIO_SILICONREVISION  AX5051_REG_SILICONREVISION
#define RADIO_SCRATCH          AX5051_REG_SCRATCH
#define RADIO_PWRMODE          AX5051_REG_PWRMODE

#define PWRMODE_PWRDOWN        0x00

#define SILICONREV1            0x16
#define SILICONREV2            0x14

#else
#error unknown radio
#endif

#define RADIO_OK                0
#define RADIO_ERR_REVISION      1
#define RADIO_ERR_COMM          2
#define RADIO_ERR_IRQ           3
#define RADIO_ERR_WAKEUPTIMEOUT 4

extern __reentrantb uint8_t radio_probeirq(void) __reentrant;
extern __reentrantb uint8_t radio_wakeup_deepsleep_core(void) __reentrant;

#endif /* RADIODEFS_H */
