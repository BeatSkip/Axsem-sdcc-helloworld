/**
******************************************************************************
* @file axm0f242.h
* @brief Macro definition for AX5042 radio registers
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

#ifndef AXM0F242_H
#define AXM0F242_H

#include <axm0f2.h>

#define AX5042_REG_SILICONREVISION   0x0000 /* Silicon Revision */
#define AX5042_REG_SCRATCH           0x0001 /* Scratch */
#define AX5042_REG_PWRMODE           0x0002 /* Power Mode */
#define AX5042_REG_XTALOSC           0x0003 /* Crystal Oscillator Control */
#define AX5042_REG_FIFOCONTROL       0x0004 /* FIFO Control */
#define AX5042_REG_FIFODATA          0x0005 /* FIFO Data */
#define AX5042_REG_IRQMASK           0x0006 /* IRQ Mask */
#define AX5042_REG_IRQREQUEST        0x0007 /* IRQ Request */
#define AX5042_REG_IFMODE            0x0008 /* Interface Mode */
#define AX5042_REG_DSPMODE           0x0009 /* DSP Mode Interface Control */
#define AX5042_REG_TXDSPMODE         0x000A /* Transmit DSP Mode */
#define AX5042_REG_PINCFG1           0x000C /* Pin Configuration 1 */
#define AX5042_REG_PINCFG2           0x000D /* Pin Configuration 2 */
#define AX5042_REG_PINCFG3           0x000E /* Pin Configuration 3 */
#define AX5042_REG_IRQINVERSION      0x000F /* IRQ Inversion */
#define AX5042_REG_MODULATION        0x0010 /* Modulation */
#define AX5042_REG_ENCODING          0x0011 /* Encoding */
#define AX5042_REG_FRAMING           0x0012 /* Framing Mode */
#define AX5042_REG_CRCINIT3          0x0014 /* CRC Initial Value 3 */
#define AX5042_REG_CRCINIT2          0x0015 /* CRC Initial Value 2 */
#define AX5042_REG_CRCINIT1          0x0016 /* CRC Initial Value 1 */
#define AX5042_REG_CRCINIT0          0x0017 /* CRC Initial Value 0 */
#define AX5042_REG_FEC               0x0018 /* Forward Error Correction */
#define AX5042_REG_FECSYNC           0x0019 /* Forward Error Correction Sync Threshold */
#define AX5042_REG_FECSTATUS         0x001A /* Forward Error Correction Status */
#define AX5042_REG_FREQ3             0x0020 /* Frequency 3 */
#define AX5042_REG_FREQ2             0x0021 /* Frequency 2 */
#define AX5042_REG_FREQ1             0x0022 /* Frequency 1 */
#define AX5042_REG_FREQ0             0x0023 /* Frequency 0 */
#define AX5042_REG_FSKDEV2           0x0025 /* FSK Deviation 2 */
#define AX5042_REG_FSKDEV1           0x0026 /* FSK Deviation 1 */
#define AX5042_REG_FSKDEV0           0x0027 /* FSK Deviation 0 */
#define AX5042_REG_IFFREQHI          0x0028 /* IF Frequency Low */
#define AX5042_REG_IFFREQLO          0x0029 /* IF Frequency High */
#define AX5042_REG_PLLLOOP           0x002C /* PLL Loop Filter */
#define AX5042_REG_PLLRANGING        0x002D /* PLL Autoranging Control */
#define AX5042_REG_PLLRNGCLK         0x002E /* PLL Autoranging Clock */
#define AX5042_REG_TXPWR             0x0030 /* Transmit Power */
#define AX5042_REG_TXBITRATEHI       0x0031 /* Transmitter Bitrate High */
#define AX5042_REG_TXBITRATEMID      0x0032 /* Transmitter Bitrate Middle */
#define AX5042_REG_TXBITRATELO       0x0033 /* Transmitter Bitrate Low */
#define AX5042_REG_MODULATORMISC     0x0034 /* Modulator Miscellaneous Control */
#define AX5042_REG_ADCMISC           0x0038 /* ADC Miscellaneous Control */
#define AX5042_REG_AGCTARGET         0x0039 /* AGC Target Value */
#define AX5042_REG_AGCATTACK         0x003A /* AGC Attack Speed */
#define AX5042_REG_AGCDECAY          0x003B /* AGC Decay Speed */
#define AX5042_REG_AGCCOUNTER        0x003C /* AGC Counter */
#define AX5042_REG_CICSHIFT          0x003D /* Decimation Filter Attenuation */
#define AX5042_REG_CICDECHI          0x003E /* Decimation Factor High */
#define AX5042_REG_CICDECLO          0x003F /* Decimation Factor Low */
#define AX5042_REG_DATARATEHI        0x0040 /* Datarate High */
#define AX5042_REG_DATARATELO        0x0041 /* Datarate Low */
#define AX5042_REG_TIMINGGAINHI      0x0042 /* Timing Estimator Bandwidth High */
#define AX5042_REG_TIMINGGAINLO      0x0043 /* Timing Estimator Bandwidth Low */
#define AX5042_REG_PHASEGAIN         0x0044 /* Phase Estimator Bandwidth */
#define AX5042_REG_FREQUENCYGAIN     0x0045 /* Frequency Estimator Bandwidth */
#define AX5042_REG_FREQUENCYGAIN2    0x0046 /* Frequency Estimator Bandwidth 2 */
#define AX5042_REG_AMPLITUDEGAIN     0x0047 /* Amplitude Estimator Bandwidth */
#define AX5042_REG_TRKAMPLITUDEHI    0x0048 /* Amplitude Tracking High */
#define AX5042_REG_TRKAMPLITUDELO    0x0049 /* Amplitude Tracking Low */
#define AX5042_REG_TRKPHASEHI        0x004A /* Phase Tracking High */
#define AX5042_REG_TRKPHASELO        0x004B /* Phase Tracking Low */
#define AX5042_REG_TRKFREQHI         0x004C /* Frequency Tracking High */
#define AX5042_REG_TRKFREQLO         0x004D /* Frequency Tracking Low */
#define AX5042_REG_APEOVERRIDE       0x0070 /* APE Override */
#define AX5042_REG_PLLVCOI           0x0072 /* PLL VCO Current */
#define AX5042_REG_PLLRNGMISC        0x0074 /* PLL Autoranging Miscellaneous */
#define AX5042_REG_REF               0x007C /* Reference */
#define AX5042_REG_RXMISC            0x007D /* Receiver Miscellaneous Control */

#endif /* AXM0F242_H */
