/**
******************************************************************************
* @file axm0f231.h
* @brief Macro definition for AX5031 radio registers
* @internal
* @author Thomas Sailer
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
* @ingroup RADIO
*
* @details
*/

#ifndef AXM0F231_H
#define AXM0F231_H

#include <axm0f2.h>

#define AX5031_REG_SILICONREVISION   0x0000 /* Silicon Revision */
#define AX5031_REG_SCRATCH           0x0001 /* Scratch */
#define AX5031_REG_PWRMODE           0x0002 /* Power Mode */
#define AX5031_REG_XTALOSC           0x0003 /* Crystal Oscillator Control */
#define AX5031_REG_FIFOCONTROL       0x0004 /* FIFO Control */
#define AX5031_REG_FIFODATA          0x0005 /* FIFO Data */
#define AX5031_REG_IRQMASK           0x0006 /* IRQ Mask */
#define AX5031_REG_IRQREQUEST        0x0007 /* IRQ Request */
#define AX5031_REG_IFMODE            0x0008 /* Interface Mode */
#define AX5031_REG_PINCFG1           0x000C /* Pin Configuration 1 */
#define AX5031_REG_PINCFG2           0x000D /* Pin Configuration 2 */
#define AX5031_REG_PINCFG3           0x000E /* Pin Configuration 3 */
#define AX5031_REG_IRQINVERSION      0x000F /* IRQ Inversion */
#define AX5031_REG_MODULATION        0x0010 /* Modulation */
#define AX5031_REG_ENCODING          0x0011 /* Encoding */
#define AX5031_REG_FRAMING           0x0012 /* Framing Mode */
#define AX5031_REG_CRCINIT3          0x0014 /* CRC Initial Value 3 */
#define AX5031_REG_CRCINIT2          0x0015 /* CRC Initial Value 2 */
#define AX5031_REG_CRCINIT1          0x0016 /* CRC Initial Value 1 */
#define AX5031_REG_CRCINIT0          0x0017 /* CRC Initial Value 0 */
#define AX5031_REG_FEC               0x0018 /* Forward Error Correction */
#define AX5031_REG_VREG              0x001B /* Voltage Regulator */
#define AX5031_REG_FREQB3            0x001C /* Frequency B 3 */
#define AX5031_REG_FREQB2            0x001D /* Frequency B 2 */
#define AX5031_REG_FREQB1            0x001E /* Frequency B 1 */
#define AX5031_REG_FREQB0            0x001F /* Frequency B 0 */
#define AX5031_REG_FREQA3            0x0020 /* Frequency A 3 */
#define AX5031_REG_FREQA2            0x0021 /* Frequency A 2 */
#define AX5031_REG_FREQA1            0x0022 /* Frequency A 1 */
#define AX5031_REG_FREQA0            0x0023 /* Frequency A 0 */
#define AX5031_REG_FSKDEV2           0x0025 /* FSK Deviation 2 */
#define AX5031_REG_FSKDEV1           0x0026 /* FSK Deviation 1 */
#define AX5031_REG_FSKDEV0           0x0027 /* FSK Deviation 0 */
#define AX5031_REG_PLLLOOP           0x002C /* PLL Loop Filter */
#define AX5031_REG_PLLRANGING        0x002D /* PLL Autoranging Control */
#define AX5031_REG_PLLRNGCLK         0x002E /* PLL Autoranging Clock */
#define AX5031_REG_TXPWR             0x0030 /* Transmit Power */
#define AX5031_REG_TXBITRATEHI       0x0031 /* Transmitter Bitrate High */
#define AX5031_REG_TXBITRATEMID      0x0032 /* Transmitter Bitrate Middle */
#define AX5031_REG_TXBITRATELO       0x0033 /* Transmitter Bitrate Low */
#define AX5031_REG_MODULATORMISC     0x0034 /* Modulator Miscellaneous Control */
#define AX5031_REG_FIFOCOUNT         0x0035 /* FIFO Count */
#define AX5031_REG_FIFOTHRESH        0x0036 /* FIFO Threshold */
#define AX5031_REG_FIFOCONTROL2      0x0037 /* FIFO Control 2 */
#define AX5031_REG_XTALCAP           0x004F /* Crystal Oscillator Load Capacitance */
#define AX5031_REG_FOURFSK           0x0050 /* 4-FSK Control */
#define AX5031_REG_XTALOSCCFG        0x0051 /* Crystal Oscillator Mode Configuration */

#endif /* AXM0F231_H */
