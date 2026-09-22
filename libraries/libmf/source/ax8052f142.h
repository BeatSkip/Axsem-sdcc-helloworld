/**
******************************************************************************
* @file
* @brief
* @internal
* @author Thomas Sailer
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

#ifndef AX8052F142_H
#define AX8052F142_H

#include <ax8052.h>

/* Radio Registers, X Address Space */

SFRX(AX5042_ADCMISC,               0x4038)   /* ADC Miscellaneous Control */
SFRX(AX5042_AGCATTACK,             0x403A)   /* AGC Attack Speed */
SFRX(AX5042_AGCCOUNTER,            0x403C)   /* AGC Counter */
SFRX(AX5042_AGCDECAY,              0x403B)   /* AGC Decay Speed */
SFRX(AX5042_AGCTARGET,             0x4039)   /* AGC Target Value */
SFRX(AX5042_AMPLITUDEGAIN,         0x4047)   /* Amplitude Estimator Bandwidth */
SFRX(AX5042_APEOVERRIDE,           0x4070)   /* APE Override */
SFRX(AX5042_CICDECHI,              0x403E)   /* Decimation Factor High */
SFRX(AX5042_CICDECLO,              0x403F)   /* Decimation Factor Low */
SFRX(AX5042_CICSHIFT,              0x403D)   /* Decimation Filter Attenuation */
SFRX(AX5042_CRCINIT0,              0x4017)   /* CRC Initial Value 0 */
SFRX(AX5042_CRCINIT1,              0x4016)   /* CRC Initial Value 1 */
SFRX(AX5042_CRCINIT2,              0x4015)   /* CRC Initial Value 2 */
SFRX(AX5042_CRCINIT3,              0x4014)   /* CRC Initial Value 3 */
SFRX(AX5042_DATARATEHI,            0x4040)   /* Datarate High */
SFRX(AX5042_DATARATELO,            0x4041)   /* Datarate Low */
SFRX(AX5042_DSPMODE,               0x4009)   /* DSP Mode Interface Control */
SFRX(AX5042_ENCODING,              0x4011)   /* Encoding */
SFRX(AX5042_FEC,                   0x4018)   /* Forward Error Correction */
SFRX(AX5042_FECSTATUS,             0x401A)   /* Forward Error Correction Status */
SFRX(AX5042_FECSYNC,               0x4019)   /* Forward Error Correction Sync Threshold */
SFRX(AX5042_FIFOCONTROL,           0x4004)   /* FIFO Control */
SFRX(AX5042_FIFODATA,              0x4005)   /* FIFO Data */
SFRX(AX5042_FRAMING,               0x4012)   /* Framing Mode */
SFRX(AX5042_FREQ0,                 0x4023)   /* Frequency 0 */
SFRX(AX5042_FREQ1,                 0x4022)   /* Frequency 1 */
SFRX(AX5042_FREQ2,                 0x4021)   /* Frequency 2 */
SFRX(AX5042_FREQ3,                 0x4020)   /* Frequency 3 */
SFRX(AX5042_FREQUENCYGAIN,         0x4045)   /* Frequency Estimator Bandwidth */
SFRX(AX5042_FREQUENCYGAIN2,        0x4046)   /* Frequency Estimator Bandwidth 2 */
SFRX(AX5042_FSKDEV0,               0x4027)   /* FSK Deviation 0 */
SFRX(AX5042_FSKDEV1,               0x4026)   /* FSK Deviation 1 */
SFRX(AX5042_FSKDEV2,               0x4025)   /* FSK Deviation 2 */
SFRX(AX5042_IFFREQHI,              0x4028)   /* IF Frequency Low */
SFRX(AX5042_IFFREQLO,              0x4029)   /* IF Frequency High */
SFRX(AX5042_IFMODE,                0x4008)   /* Interface Mode */
SFRX(AX5042_IRQINVERSION,          0x400F)   /* IRQ Inversion */
SFRX(AX5042_IRQMASK,               0x4006)   /* IRQ Mask */
SFRX(AX5042_IRQREQUEST,            0x4007)   /* IRQ Request */
SFRX(AX5042_MODULATION,            0x4010)   /* Modulation */
SFRX(AX5042_MODULATORMISC,         0x4034)   /* Modulator Miscellaneous Control */
SFRX(AX5042_PHASEGAIN,             0x4044)   /* Phase Estimator Bandwidth */
SFRX(AX5042_PINCFG1,               0x400C)   /* Pin Configuration 1 */
SFRX(AX5042_PINCFG2,               0x400D)   /* Pin Configuration 2 */
SFRX(AX5042_PINCFG3,               0x400E)   /* Pin Configuration 3 */
SFRX(AX5042_PLLLOOP,               0x402C)   /* PLL Loop Filter */
SFRX(AX5042_PLLRANGING,            0x402D)   /* PLL Autoranging Control */
SFRX(AX5042_PLLRNGCLK,             0x402E)   /* PLL Autoranging Clock */
SFRX(AX5042_PLLRNGMISC,            0x4074)   /* PLL Autoranging Miscellaneous */
SFRX(AX5042_PLLVCOI,               0x4072)   /* PLL VCO Current */
SFRX(AX5042_PWRMODE,               0x4002)   /* Power Mode */
SFRX(AX5042_REF,                   0x407C)   /* Reference */
SFRX(AX5042_RXMISC,                0x407D)   /* Receiver Miscellaneous Control */
SFRX(AX5042_SCRATCH,               0x4001)   /* Scratch */
SFRX(AX5042_SILICONREVISION,       0x4000)   /* Silicon Revision */
SFRX(AX5042_TIMINGGAINHI,          0x4042)   /* Timing Estimator Bandwidth High */
SFRX(AX5042_TIMINGGAINLO,          0x4043)   /* Timing Estimator Bandwidth Low */
SFRX(AX5042_TRKAMPLITUDEHI,        0x4048)   /* Amplitude Tracking High */
SFRX(AX5042_TRKAMPLITUDELO,        0x4049)   /* Amplitude Tracking Low */
SFRX(AX5042_TRKFREQHI,             0x404C)   /* Frequency Tracking High */
SFRX(AX5042_TRKFREQLO,             0x404D)   /* Frequency Tracking Low */
SFRX(AX5042_TRKPHASEHI,            0x404A)   /* Phase Tracking High */
SFRX(AX5042_TRKPHASELO,            0x404B)   /* Phase Tracking Low */
SFRX(AX5042_TXBITRATEHI,           0x4031)   /* Transmitter Bitrate High */
SFRX(AX5042_TXBITRATELO,           0x4033)   /* Transmitter Bitrate Low */
SFRX(AX5042_TXBITRATEMID,          0x4032)   /* Transmitter Bitrate Middle */
SFRX(AX5042_TXDSPMODE,             0x400A)   /* Transmit DSP Mode */
SFRX(AX5042_TXPWR,                 0x4030)   /* Transmit Power */
SFRX(AX5042_XTALOSC,               0x4003)   /* Crystal Oscillator Control */

/* Radio Registers, X Address Space, Non-Blocking Version */

SFRX(AX5042_ADCMISCNB,             0x5038)   /* ADC Miscellaneous Control, Non-Blocking */
SFRX(AX5042_AGCATTACKNB,           0x503A)   /* AGC Attack Speed, Non-Blocking */
SFRX(AX5042_AGCCOUNTERNB,          0x503C)   /* AGC Counter, Non-Blocking */
SFRX(AX5042_AGCDECAYNB,            0x503B)   /* AGC Decay Speed, Non-Blocking */
SFRX(AX5042_AGCTARGETNB,           0x5039)   /* AGC Target Value, Non-Blocking */
SFRX(AX5042_AMPLITUDEGAINNB,       0x5047)   /* Amplitude Estimator Bandwidth, Non-Blocking */
SFRX(AX5042_APEOVERRIDENB,         0x5070)   /* APE Override, Non-Blocking */
SFRX(AX5042_CICDECHINB,            0x503E)   /* Decimation Factor High, Non-Blocking */
SFRX(AX5042_CICDECLONB,            0x503F)   /* Decimation Factor Low, Non-Blocking */
SFRX(AX5042_CICSHIFTNB,            0x503D)   /* Decimation Filter Attenuation, Non-Blocking */
SFRX(AX5042_CRCINIT0NB,            0x5017)   /* CRC Initial Value 0, Non-Blocking */
SFRX(AX5042_CRCINIT1NB,            0x5016)   /* CRC Initial Value 1, Non-Blocking */
SFRX(AX5042_CRCINIT2NB,            0x5015)   /* CRC Initial Value 2, Non-Blocking */
SFRX(AX5042_CRCINIT3NB,            0x5014)   /* CRC Initial Value 3, Non-Blocking */
SFRX(AX5042_DATARATEHINB,          0x5040)   /* Datarate High, Non-Blocking */
SFRX(AX5042_DATARATELONB,          0x5041)   /* Datarate Low, Non-Blocking */
SFRX(AX5042_DSPMODENB,             0x5009)   /* DSP Mode Interface Control, Non-Blocking */
SFRX(AX5042_ENCODINGNB,            0x5011)   /* Encoding, Non-Blocking */
SFRX(AX5042_FECNB,                 0x5018)   /* Forward Error Correction, Non-Blocking */
SFRX(AX5042_FECSTATUSNB,           0x501A)   /* Forward Error Correction Status, Non-Blocking */
SFRX(AX5042_FECSYNCNB,             0x5019)   /* Forward Error Correction Sync Threshold, Non-Blocking */
SFRX(AX5042_FIFOCONTROLNB,         0x5004)   /* FIFO Control, Non-Blocking */
SFRX(AX5042_FIFODATANB,            0x5005)   /* FIFO Data, Non-Blocking */
SFRX(AX5042_FRAMINGNB,             0x5012)   /* Framing Mode, Non-Blocking */
SFRX(AX5042_FREQ0NB,               0x5023)   /* Frequency 0, Non-Blocking */
SFRX(AX5042_FREQ1NB,               0x5022)   /* Frequency 1, Non-Blocking */
SFRX(AX5042_FREQ2NB,               0x5021)   /* Frequency 2, Non-Blocking */
SFRX(AX5042_FREQ3NB,               0x5020)   /* Frequency 3, Non-Blocking */
SFRX(AX5042_FREQUENCYGAINNB,       0x5045)   /* Frequency Estimator Bandwidth, Non-Blocking */
SFRX(AX5042_FREQUENCYGAIN2NB,      0x5046)   /* Frequency Estimator Bandwidth 2, Non-Blocking */
SFRX(AX5042_FSKDEV0NB,             0x5027)   /* FSK Deviation 0, Non-Blocking */
SFRX(AX5042_FSKDEV1NB,             0x5026)   /* FSK Deviation 1, Non-Blocking */
SFRX(AX5042_FSKDEV2NB,             0x5025)   /* FSK Deviation 2, Non-Blocking */
SFRX(AX5042_IFFREQHINB,            0x5028)   /* IF Frequency Low, Non-Blocking */
SFRX(AX5042_IFFREQLONB,            0x5029)   /* IF Frequency High, Non-Blocking */
SFRX(AX5042_IFMODENB,              0x5008)   /* Interface Mode, Non-Blocking */
SFRX(AX5042_IRQINVERSIONNB,        0x500F)   /* IRQ Inversion, Non-Blocking */
SFRX(AX5042_IRQMASKNB,             0x5006)   /* IRQ Mask, Non-Blocking */
SFRX(AX5042_IRQREQUESTNB,          0x5007)   /* IRQ Request, Non-Blocking */
SFRX(AX5042_MODULATIONNB,          0x5010)   /* Modulation, Non-Blocking */
SFRX(AX5042_MODULATORMISCNB,       0x5034)   /* Modulator Miscellaneous Control, Non-Blocking */
SFRX(AX5042_PHASEGAINNB,           0x5044)   /* Phase Estimator Bandwidth, Non-Blocking */
SFRX(AX5042_PINCFG1NB,             0x500C)   /* Pin Configuration 1, Non-Blocking */
SFRX(AX5042_PINCFG2NB,             0x500D)   /* Pin Configuration 2, Non-Blocking */
SFRX(AX5042_PINCFG3NB,             0x500E)   /* Pin Configuration 3, Non-Blocking */
SFRX(AX5042_PLLLOOPNB,             0x502C)   /* PLL Loop Filter, Non-Blocking */
SFRX(AX5042_PLLRANGINGNB,          0x502D)   /* PLL Autoranging Control, Non-Blocking */
SFRX(AX5042_PLLRNGCLKNB,           0x502E)   /* PLL Autoranging Clock, Non-Blocking */
SFRX(AX5042_PLLRNGMISCNB,          0x5074)   /* PLL Autoranging Miscellaneous, Non-Blocking */
SFRX(AX5042_PLLVCOINB,             0x5072)   /* PLL VCO Current, Non-Blocking */
SFRX(AX5042_PWRMODENB,             0x5002)   /* Power Mode, Non-Blocking */
SFRX(AX5042_REFNB,                 0x507C)   /* Reference, Non-Blocking */
SFRX(AX5042_RXMISCNB,              0x507D)   /* Receiver Miscellaneous Control, Non-Blocking */
SFRX(AX5042_SCRATCHNB,             0x5001)   /* Scratch, Non-Blocking */
SFRX(AX5042_SILICONREVISIONNB,     0x5000)   /* Silicon Revision, Non-Blocking */
SFRX(AX5042_TIMINGGAINHINB,        0x5042)   /* Timing Estimator Bandwidth High, Non-Blocking */
SFRX(AX5042_TIMINGGAINLONB,        0x5043)   /* Timing Estimator Bandwidth Low, Non-Blocking */
SFRX(AX5042_TRKAMPLITUDEHINB,      0x5048)   /* Amplitude Tracking High, Non-Blocking */
SFRX(AX5042_TRKAMPLITUDELONB,      0x5049)   /* Amplitude Tracking Low, Non-Blocking */
SFRX(AX5042_TRKFREQHINB,           0x504C)   /* Frequency Tracking High, Non-Blocking */
SFRX(AX5042_TRKFREQLONB,           0x504D)   /* Frequency Tracking Low, Non-Blocking */
SFRX(AX5042_TRKPHASEHINB,          0x504A)   /* Phase Tracking High, Non-Blocking */
SFRX(AX5042_TRKPHASELONB,          0x504B)   /* Phase Tracking Low, Non-Blocking */
SFRX(AX5042_TXBITRATEHINB,         0x5031)   /* Transmitter Bitrate High, Non-Blocking */
SFRX(AX5042_TXBITRATELONB,         0x5033)   /* Transmitter Bitrate Low, Non-Blocking */
SFRX(AX5042_TXBITRATEMIDNB,        0x5032)   /* Transmitter Bitrate Middle, Non-Blocking */
SFRX(AX5042_TXDSPMODENB,           0x500A)   /* Transmit DSP Mode, Non-Blocking */
SFRX(AX5042_TXPWRNB,               0x5030)   /* Transmit Power, Non-Blocking */
SFRX(AX5042_XTALOSCNB,             0x5003)   /* Crystal Oscillator Control, Non-Blocking */

/* Alternate Names */

#define AX5042_AMPLGAIN            AX5042_AMPLITUDEGAIN
#define AX5042_FREQGAIN            AX5042_FREQUENCYGAIN
#define AX5042_FREQGAIN2           AX5042_FREQUENCYGAIN2
#define AX5042_MODMISC             AX5042_MODULATORMISC
#define AX5042_TMGGAINHI           AX5042_TIMINGGAINHI
#define AX5042_TMGGAINLO           AX5042_TIMINGGAINLO
#define AX5042_TXRATEHI            AX5042_TXBITRATEHI
#define AX5042_TXRATELO            AX5042_TXBITRATELO
#define AX5042_TXRATEMID           AX5042_TXBITRATEMID

#define AX5042_AMPLGAINNB          AX5042_AMPLITUDEGAINNB
#define AX5042_FREQGAINNB          AX5042_FREQUENCYGAINNB
#define AX5042_FREQGAIN2NB         AX5042_FREQUENCYGAIN2NB
#define AX5042_MODMISCNB           AX5042_MODULATORMISCNB
#define AX5042_TMGGAINHINB         AX5042_TIMINGGAINHINB
#define AX5042_TMGGAINLONB         AX5042_TIMINGGAINLONB
#define AX5042_TXRATEHINB          AX5042_TXBITRATEHINB
#define AX5042_TXRATELONB          AX5042_TXBITRATELONB
#define AX5042_TXRATEMIDNB         AX5042_TXBITRATEMIDNB

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

#endif /* AX8052F142_H */
