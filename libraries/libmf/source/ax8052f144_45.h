/**
******************************************************************************
* @file ax8052f144_45.h
* @brief Macro definition for AX5044_45 radio registers
* @internal
* @author Pradeep Kumar G R
* $Rev: $
* $Date: $
******************************************************************************
* Copyright 2016 Semiconductor Components Industries LLC (d/b/a "ON Semiconductor").
* All rights reserved. This software and/or documentation is licensed by ON Semiconductor
* under limited terms and conditions. The terms and conditions pertaining to the software
* and/or documentation are available at http://www.onsemi.com/site/pdf/ONSEMI_T&C.pdf
* ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software") and
* if applicable the software license agreement. Do not use this software and/or
* documentation unless you have carefully read and you agree to the limited terms and
* conditions. By using this software and/or documentation, you agree to the limited
* terms and conditions.
*
* THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
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

#ifndef AX8052F144_45_H
#define AX8052F144_45_H

#include <ax8052.h>

/********** Radio Registers, X Address Space **********/
/* Revision & Interface Probing */
SFRX(AX5044_45_SILICONREVISION,		0x4000)		/* Silicon Revision */
SFRX(AX5044_45_SCRATCH,				0x4001)		/* Scratch Register */

/* Operating Mode */
SFRX(AX5044_45_PWRMODE,				0x4002)		/* Power Mode */

/* Voltage Regulator */
SFRX(AX5044_45_POWSTAT,				0x4003)		/* Power Management Status */
SFRX(AX5044_45_POWSTICKYSTAT,		0x4004)		/* Power Management Sticky Status */
SFRX(AX5044_45_POWIRQMASK,			0x4005)		/* Power Management Interrupt Mask */

/* Interrupt Control */
SFRX(AX5044_45_IRQMASK1,			0x4006)		/* IRQ Mask */
SFRX(AX5044_45_IRQMASK0,			0x4007)		/* IRQ Mask */
SFRX(AX5044_45_RADIOEVENTMASK0,		0x4009)		/* Radio Event Mask */
SFRX(AX5044_45_IRQINVERSION1,		0x400A)		/* IRQ Inversion */
SFRX(AX5044_45_IRQINVERSION0,		0x400B)		/* IRQ Inversion */
SFRX(AX5044_45_IRQREQUEST1,			0x400C)		/* IRQ Request */
SFRX(AX5044_45_IRQREQUEST0,			0x400D)		/* IRQ Request */
SFRX(AX5044_45_RADIOEVENTREQ0,		0x400F)		/* Radio Event Request */

/* Modulation & Framing */
SFRX(AX5044_45_MODULATION,			0x4010)		/* Modulation */
SFRX(AX5044_45_ENCODING1,			0x4011)		/* Encoder/Decoder Settings */
SFRX(AX5044_45_ENCODING0,			0x4012)		/* Encoder/Decoder Settings */
SFRX(AX5044_45_FRAMING,				0x4013)		/* Framing settings */
SFRX(AX5044_45_CRCCFG,				0x4014)		/* CRC settings */
SFRX(AX5044_45_CRCINIT3,			0x4015)		/* CRC Initialisation Data */
SFRX(AX5044_45_CRCINIT2,			0x4016)		/* CRC Initialisation Data */
SFRX(AX5044_45_CRCINIT1,			0x4017)		/* CRC Initialisation Data */
SFRX(AX5044_45_CRCINIT0,			0x4018)		/* CRC Initialisation Data */

/* Forward Error Correction */
SFRX(AX5044_45_FEC,					0x4019)		/* FEC (Viterbi) Configuration */
SFRX(AX5044_45_FECSYNC,				0x401A)		/* Interleaver Synchronisation Threshold */
SFRX(AX5044_45_FECSTATUS,			0x401B)		/* FEC Status */

/* Status */
SFRX(AX5044_45_RADIOSTATE,			0x401C)		/* Radio Controller State */
SFRX(AX5044_45_XTALSTATUS,			0x401D)		/* Crystal Oscillator Status */

/* Pin Configuration */
SFRX(AX5044_45_PINSTATE,			0x4020)		/* Pinstate */
SFRX(AX5044_45_PINFUNCSYSCLK,		0x4021)		/* SYSCLK Pin Function */
SFRX(AX5044_45_PINFUNCDCLK,			0x4022)		/* DCLK Pin Function */
SFRX(AX5044_45_PINFUNCDATA,			0x4023)		/* DATA Pin Function */
SFRX(AX5044_45_PINFUNCIRQ,			0x4024)		/* IRQ Pin Function */
SFRX(AX5044_45_PINFUNCANTSEL,		0x4025)		/* ANTSEL Pin Function */
SFRX(AX5044_45_PINFUNCPWRAMP,		0x4026)		/* PWRAMP Pin Function */
SFRX(AX5044_45_PWRAMP,				0x4027)		/* PWRAMP Control */

/* FIFO */
SFRX(AX5044_45_FIFOSTAT,			0x4028)		/* FIFO Control */
SFRX(AX5044_45_FIFODATA,			0x4029)		/* FIFO Data */
SFRX(AX5044_45_FIFOCOUNT1,			0x402A)		/* Number of Words currently in FIFO */
SFRX(AX5044_45_FIFOCOUNT0,			0x402B)		/* Number of Words currently in FIFO */
SFRX(AX5044_45_FIFOFREE1,			0x402C)		/* Number of Words that can be written to FIFO */
SFRX(AX5044_45_FIFOFREE0,			0x402D)		/* Number of Words that can be written to FIFO */
SFRX(AX5044_45_FIFOTHRESH0,			0x402F)		/* FIFO Threshold */

/* Synthesizer */
SFRX(AX5044_45_PLLLOOP,				0x4030)		/* PLL Loop Filter Settings */
SFRX(AX5044_45_PLLCPI,				0x4031)		/* PLL Charge Pump Current (Boosted) */
SFRX(AX5044_45_PLLRANGINGA1,		0x4032)		/* PLL Autoranging */
SFRX(AX5044_45_PLLRANGINGA0,		0x4033)		/* PLL Autoranging */
SFRX(AX5044_45_FREQUENCYA3,			0x4034)		/* Synthesizer Frequency */
SFRX(AX5044_45_FREQUENCYA2,			0x4035)		/* Synthesizer Frequency */
SFRX(AX5044_45_FREQUENCYA1,			0x4036)		/* Synthesizer Frequency */
SFRX(AX5044_45_FREQUENCYA0,			0x4037)		/* Synthesizer Frequency */
SFRX(AX5044_45_PLLLOOPBOOST,		0x4038)		/* PLL Loop Filter Settings (Boosted) */
SFRX(AX5044_45_PLLCPIBOOST,			0x4039)		/* PLL Charge Pump Current */
SFRX(AX5044_45_PLLRANGINGB1,		0x403A)		/* PLL Autoranging */
SFRX(AX5044_45_PLLRANGINGB0,		0x403B)		/* PLL Autoranging */
SFRX(AX5044_45_FREQUENCYB3,			0x403C)		/* Synthesizer Frequency */
SFRX(AX5044_45_FREQUENCYB2,			0x403D)		/* Synthesizer Frequency */
SFRX(AX5044_45_FREQUENCYB1,			0x403E)		/* Synthesizer Frequency */
SFRX(AX5044_45_FREQUENCYB0,			0x403F)		/* Synthesizer Frequency */
SFRX(AX5044_45_PLLVCODIV,			0x4040)		/* PLL Divider Settings */

/* Signal Strength */
SFRX(AX5044_45_RSSI,				0x4041)		/* Received Signal Strength Indicator */
SFRX(AX5044_45_BGNDRSSI,			0x4042)		/* Background RSSI */
SFRX(AX5044_45_DIVERSITY,			0x4043)		/* Antenna Diversity Configuration */
SFRX(AX5044_45_AGCCOUNTER,			0x4044)		/* AGC Current Value */

/* Receiver Tracking */
SFRX(AX5044_45_TRKDATARATE2,		0x4045)		/* Datarate Tracking */
SFRX(AX5044_45_TRKDATARATE1,		0x4046)		/* Datarate Tracking */
SFRX(AX5044_45_TRKDATARATE0,		0x4047)		/* Datarate Tracking */
SFRX(AX5044_45_TRKAMPL1,			0x4048)		/* Amplitude Tracking */
SFRX(AX5044_45_TRKAMPL0,			0x4049)		/* Amplitude Tracking */
SFRX(AX5044_45_TRKPHASE1,			0x404A)		/* Phase Tracking */
SFRX(AX5044_45_TRKPHASE0,			0x404B)		/* Phase Tracking */
SFRX(AX5044_45_TRKRFFREQ2,			0x404D)		/* RF Frequency Tracking */
SFRX(AX5044_45_TRKRFFREQ1,			0x404E)		/* RF Frequency Tracking */
SFRX(AX5044_45_TRKRFFREQ0,			0x404F)		/* RF Frequency Tracking */
SFRX(AX5044_45_TRKFREQ1,			0x4050)		/* Frequency Tracking */
SFRX(AX5044_45_TRKFREQ0,			0x4051)		/* Frequency Tracking */
SFRX(AX5044_45_TRKFSKDEMOD1,		0x4052)		/* FSK Demodulator Tracking */
SFRX(AX5044_45_TRKFSKDEMOD0,		0x4053)		/* FSK Demodulator Tracking */
SFRX(AX5044_45_TRKAFSKDEMOD1,		0x4054)		/* AFSK Demodulator Tracking */
SFRX(AX5044_45_TRKAFSKDEMOD0,		0x4055)		/* AFSK Demodulator Tracking */

/* Timer */
SFRX(AX5044_45_TIMER2,				0x4059)		/* 1MHz Timer */
SFRX(AX5044_45_TIMER1,				0x405A)		/* 1MHz Timer */
SFRX(AX5044_45_TIMER0,				0x405B)		/* 1MHz Timer */
SFRX(AX5044_45_TIMERCLK,			0x405C)		/* Internal Timer Clock Setting */

/* Time Stamp */
SFRX(AX5044_45_RCTRLTIMESTAMP2,		0x4060)		/* Radio Controller Timestamp Count */
SFRX(AX5044_45_RCTRLTIMESTAMP1,		0x4061)		/* Radio Controller Timestamp Count */
SFRX(AX5044_45_RCTRLTIMESTAMP0,		0x4062)		/* Radio Controller Timestamp Count */
SFRX(AX5044_45_RCTRLTIMETXENA,		0x4064)		/* Radio Controller Timestamp Enable */

/* Wakeup Timer */
SFRX(AX5044_45_WAKEUPTIMER1,		0x4068)		/* Wakeup Timer */
SFRX(AX5044_45_WAKEUPTIMER0,		0x4069)		/* Wakeup Timer */
SFRX(AX5044_45_WAKEUP1,				0x406A)		/* Wakeup Time */
SFRX(AX5044_45_WAKEUP0,				0x406B)		/* Wakeup Time */
SFRX(AX5044_45_WAKEUPFREQ1,			0x406C)		/* Wakeup Frequency */
SFRX(AX5044_45_WAKEUPFREQ0,			0x406D)		/* Wakeup Frequency */
SFRX(AX5044_45_WAKEUPXOEARLY,		0x406E)		/* Wakeup Crystal Oscillator Early */

/* DSPmode 2 */
SFRX(AX5044_45_DSPMODESHREG,		0x406F)		/* DSPmode SPI Shift Register Access */

/* Physical Layer Parameters */
/* Receiver Parameters */
SFRX(AX5044_45_IFFREQ1,				0x4100)		/* 2nd LO / IF Frequency */
SFRX(AX5044_45_IFFREQ0,				0x4101)		/* 2nd LO / IF Frequency */
SFRX(AX5044_45_DECIMATION1,			0x4102)		/* Decimation Factor */
SFRX(AX5044_45_DECIMATION0,			0x4103)		/* Decimation Factor */
SFRX(AX5044_45_RXDATARATE2,			0x4104)		/* Receiver Datarate */
SFRX(AX5044_45_RXDATARATE1,			0x4105)		/* Receiver Datarate */
SFRX(AX5044_45_RXDATARATE0,			0x4106)		/* Receiver Datarate */
SFRX(AX5044_45_MAXDROFFSET2,		0x4107)		/* Maximum Receiver Datarate Offset */
SFRX(AX5044_45_MAXDROFFSET1,		0x4108)		/* Maximum Receiver Datarate Offset */
SFRX(AX5044_45_MAXDROFFSET0,		0x4109)		/* Maximum Receiver Datarate Offset */
SFRX(AX5044_45_MAXRFOFFSET2,		0x410A)		/* Maximum Receiver RF Offset */
SFRX(AX5044_45_MAXRFOFFSET1,		0x410B)		/* Maximum Receiver RF Offset */
SFRX(AX5044_45_MAXRFOFFSET0,		0x410C)		/* Maximum Receiver RF Offset */
SFRX(AX5044_45_FSKDMAX1,			0x410D)		/* Four FSK Rx Deviation */
SFRX(AX5044_45_FSKDMAX0,			0x410E)		/* Four FSK Rx Deviation */
SFRX(AX5044_45_FSKDMIN1,			0x410F)		/* Four FSK Rx Deviation */
SFRX(AX5044_45_FSKDMIN0,			0x4110)		/* Four FSK Rx Deviation */
SFRX(AX5044_45_AFSKSPACE1,			0x4111)		/* AFSK Space (0) Frequency */
SFRX(AX5044_45_AFSKSPACE0,			0x4112)		/* AFSK Space (0) Frequency */
SFRX(AX5044_45_AFSKMARK1,			0x4113)		/* AFSK Mark (1) Frequency */
SFRX(AX5044_45_AFSKMARK0,			0x4114)		/* AFSK Mark (1) Frequency */
SFRX(AX5044_45_AFSKCTRL,			0x4115)		/* AFSK Control */
SFRX(AX5044_45_AMPLFILTER,			0x4116)		/* Amplitude Filter */
SFRX(AX5044_45_RFZIGZAGAMPL,		0x4117)		/* RF Zigzag Scanner Amplitude Exponent and Man-tissa */
SFRX(AX5044_45_RFZIGZAGFREQ,		0x4118)		/* RF Zigzag Scanner Frequency */
SFRX(AX5044_45_RFFREQUENCYLEAK,		0x4119)		/* RF Frequency Recovery Loop Leakiness */
SFRX(AX5044_45_FREQUENCYLEAK,		0x411A)		/* Baseband Frequency Recovery Loop Leakiness */
SFRX(AX5044_45_RXPARAMSETS,			0x411B)		/* Receiver Parameter Set Indirection */
SFRX(AX5044_45_RXPARAMCURSET,		0x411C)		/* Receiver Parameter Current Set */
SFRX(AX5044_45_RSSIIRQTHRESH,		0x411D)		/* RSSI Interrupt Threshold */
SFRX(AX5044_45_RSSIIRQDIR,			0x411E)		/* RSSI Interrupt Threshold Direction */

/* Receiver Parameter Set 0 */
SFRX(AX5044_45_AGCTARGET0,			0x4120)		/* AGC Target */
SFRX(AX5044_45_AGCINCREASE0,		0x4121)		/* AGC Gain Increase Settings */
SFRX(AX5044_45_AGCREDUCE0,			0x4122)		/* AGC Gain Reduce Settings */
SFRX(AX5044_45_AGCAHYST0,			0x4123)		/* AGC Digital Threshold Range */
SFRX(AX5044_45_TIMEGAIN0,			0x4124)		/* Timing Gain */
SFRX(AX5044_45_DRGAIN0,				0x4125)		/* Data Rate Gain */
SFRX(AX5044_45_PHASEGAIN0,			0x4126)		/* Filter Index, Phase Gain */
SFRX(AX5044_45_FREQUENCYGAINA0,		0x4127)		/* Frequency Gain A */
SFRX(AX5044_45_FREQUENCYGAINB0,		0x4128)		/* Frequency Gain B */
SFRX(AX5044_45_FREQUENCYGAINC0,		0x4129)		/* Frequency Gain C */
SFRX(AX5044_45_FREQUENCYGAIND0,		0x412A)		/* Frequency Gain D */
SFRX(AX5044_45_AMPLGAIN0,			0x412B)		/* Amplitude Gain */
SFRX(AX5044_45_FREQDEV10,			0x412C)		/* Receiver Frequency Deviation */
SFRX(AX5044_45_FREQDEV00,			0x412D)		/* Receiver Frequency Deviation */
SFRX(AX5044_45_FOURFSK0,			0x412E)		/* Four FSK Control */
SFRX(AX5044_45_BBOFFSRES0,			0x412F)		/* Baseband Offset Compensation Resistors */

/* Receiver Parameter Set 1 */
SFRX(AX5044_45_AGCTARGET1,			0x4130)		/* AGC Target */
SFRX(AX5044_45_AGCINCREASE1,		0x4131)		/* AGC Gain Increase Settings */
SFRX(AX5044_45_AGCREDUCE1,			0x4132)		/* AGC Gain Reduce Settings */
SFRX(AX5044_45_AGCAHYST1,			0x4133)		/* AGC Digital Threshold Range */
SFRX(AX5044_45_TIMEGAIN1,			0x4134)		/* Timing Gain */
SFRX(AX5044_45_DRGAIN1,				0x4135)		/* Data Rate Gain */
SFRX(AX5044_45_PHASEGAIN1,			0x4136)		/* Filter Index, Phase Gain */
SFRX(AX5044_45_FREQUENCYGAINA1,		0x4137)		/* Frequency Gain A */
SFRX(AX5044_45_FREQUENCYGAINB1,		0x4138)		/* Frequency Gain B */
SFRX(AX5044_45_FREQUENCYGAINC1,		0x4139)		/* Frequency Gain C */
SFRX(AX5044_45_FREQUENCYGAIND1,		0x413A)		/* Frequency Gain D */
SFRX(AX5044_45_AMPLITUDEGAIN1,		0x413B)		/* Amplitude Gain */
SFRX(AX5044_45_FREQDEV11,			0x413C)		/* Receiver Frequency Deviation */
SFRX(AX5044_45_FREQDEV01,			0x413D)		/* Receiver Frequency Deviation */
SFRX(AX5044_45_FOURFSK1,			0x413E)		/* Four FSK Control */
SFRX(AX5044_45_BBOFFSRES1,			0x413F)		/* Baseband Offset Compensation Resistors */

/* Receiver Parameter Set 2 */
SFRX(AX5044_45_AGCTARGET2,			0x4140)		/* AGC Target */
SFRX(AX5044_45_AGCINCREASE2,		0x4141)		/* AGC Gain Increase Settings */
SFRX(AX5044_45_AGCREDUCE2,			0x4142)		/* AGC Gain Reduce Settings */
SFRX(AX5044_45_AGCAHYST2,			0x4143)		/* AGC Digital Threshold Range */
SFRX(AX5044_45_TIMEGAIN2,			0x4144)		/* Timing Gain */
SFRX(AX5044_45_DRGAIN2,				0x4145)		/* Data Rate Gain */
SFRX(AX5044_45_PHASEGAIN2,			0x4146)		/* Filter Index, Phase Gain */
SFRX(AX5044_45_FREQUENCYGAINA2,		0x4147)		/* Frequency Gain A */
SFRX(AX5044_45_FREQUENCYGAINB2,		0x4148)		/* Frequency Gain B */
SFRX(AX5044_45_FREQUENCYGAINC2,		0x4149)		/* Frequency Gain C */
SFRX(AX5044_45_FREQUENCYGAIND2,		0x414A)		/* Frequency Gain D */
SFRX(AX5044_45_AMPLITUDEGAIN2,		0x414B)		/* Amplitude Gain */
SFRX(AX5044_45_FREQDEV12,			0x414C)		/* Receiver Frequency Deviation */
SFRX(AX5044_45_FREQDEV02,			0x414D)		/* Receiver Frequency Deviation */
SFRX(AX5044_45_FOURFSK2,			0x414E)		/* Four FSK Control */
SFRX(AX5044_45_BBOFFSRES2,			0x414F)		/* Baseband Offset Compensation Resistors */

/* Receiver Parameter Set 3 */
SFRX(AX5044_45_AGCTARGET3,			0x4150)		/* AGC Target */
SFRX(AX5044_45_AGCINCREASE3,		0x4151)		/* AGC Gain Increase Settings */
SFRX(AX5044_45_AGCREDUCE3,			0x4152)		/* AGC Gain Reduce Settings */
SFRX(AX5044_45_AGCAHYST3,			0x4153)		/* AGC Digital Threshold Range */
SFRX(AX5044_45_TIMEGAIN3,			0x4154)		/* Timing Gain */
SFRX(AX5044_45_DRGAIN3,				0x4155)		/* Data Rate Gain */
SFRX(AX5044_45_PHASEGAIN3,			0x4156)		/* Filter Index, Phase Gain */
SFRX(AX5044_45_FREQUENCYGAINA3,		0x4157)		/* Frequency Gain A */
SFRX(AX5044_45_FREQUENCYGAINB3,		0x4158)		/* Frequency Gain B */
SFRX(AX5044_45_FREQUENCYGAINC3,		0x4159)		/* Frequency Gain C */
SFRX(AX5044_45_FREQUENCYGAIND3,		0x415A)		/* Frequency Gain D */
SFRX(AX5044_45_AMPLITUDEGAIN3,		0x415B)		/* Amplitude Gain */
SFRX(AX5044_45_FREQDEV13,			0x415C)		/* Receiver Frequency Deviation */
SFRX(AX5044_45_FREQDEV03,			0x415D)		/* Receiver Frequency Deviation */
SFRX(AX5044_45_FOURFSK3,			0x415E)		/* Four FSK Control */
SFRX(AX5044_45_BBOFFSRES3,			0x415F)		/* Baseband Offset Compensation Resistors */

/* Transmitter Parameters */
SFRX(AX5044_45_MODCFGF,				0x4160)		/* Modulator Configuration F */
SFRX(AX5044_45_FSKDEV2,				0x4161)		/* FSK Frequency Deviation */
SFRX(AX5044_45_FSKDEV1,				0x4162)		/* FSK Frequency Deviation */
SFRX(AX5044_45_FSKDEV0,				0x4163)		/* FSK Frequency Deviation */
SFRX(AX5044_45_TXRATE3,				0x4164)		/* Transmitter Bitrate */
SFRX(AX5044_45_TXRATE2,				0x4165)		/* Transmitter Bitrate */
SFRX(AX5044_45_TXRATE1,				0x4166)		/* Transmitter Bitrate */
SFRX(AX5044_45_TXRATE0,				0x4167)		/* Transmitter Bitrate */
SFRX(AX5044_45_TXPWRCOEFFA1,		0x4168)		/* Transmitter Predistortion Coefficient A */
SFRX(AX5044_45_TXPWRCOEFFA0,		0x4169)		/* Transmitter Predistortion Coefficient A */
SFRX(AX5044_45_TXPWRCOEFFB1,		0x416A)		/* Transmitter Predistortion Coefficient B */
SFRX(AX5044_45_TXPWRCOEFFB0,		0x416B)		/* Transmitter Predistortion Coefficient B */
SFRX(AX5044_45_TXPWRCOEFFC1,		0x416C)		/* Transmitter Predistortion Coefficient C */
SFRX(AX5044_45_TXPWRCOEFFC0,		0x416D)		/* Transmitter Predistortion Coefficient C */
SFRX(AX5044_45_TXPWRCOEFFD1,		0x416E)		/* Transmitter Predistortion Coefficient D */
SFRX(AX5044_45_TXPWRCOEFFD0,		0x416F)		/* Transmitter Predistortion Coefficient D */
SFRX(AX5044_45_TXPWRCOEFFE1,		0x4170)		/* Transmitter Predistortion Coefficient E */
SFRX(AX5044_45_TXPWRCOEFFE0,		0x4171)		/* Transmitter Predistortion Coefficient E */
SFRX(AX5044_45_MODCFGA,				0x4172)		/* Modulator Configuration A */
SFRX(AX5044_45_TXCLKDIV,			0x4173)		/* Transmitter Clock Divider */
SFRX(AX5044_45_TXAMPLSHAPE,			0x4174)		/* Transmitter Amplitude Shaping */
SFRX(AX5044_45_TXDCCREG,			0x4175)		/* Transmitter Trim Registers */
SFRX(AX5044_45_TXMISC,				0x4176)		/* Transmitter Miscellaneous Registers */

/* PLL Parameters */
SFRX(AX5044_45_PLLVCOI,				0x4180)		/* VCO Current */
SFRX(AX5044_45_PLLLOCKDET,			0x4181)		/* PLL Lock Detect Delay */
SFRX(AX5044_45_PLLRNGCFG,			0x4182)		/* PLL Ranging Configuration */
SFRX(AX5044_45_PLLDITHER,			0x4183)		/* PLL Dither */
SFRX(AX5044_45_PLLSTATMASK,			0x4184)		/* PLL Staus Interrupt Mask */
SFRX(AX5044_45_PLLCOMP,				0x4185)		/* PLL Ranging ADC Control & Read-out */

/* Crystal Oscillator */
SFRX(AX5044_45_XTALCAP,				0x418A)		/* Crystal Oscillator Load Capacitance Configuration */
SFRX(AX5044_45_XTALOSC,				0x418B)		/* Crystal Oscillator Configuration */
SFRX(AX5044_45_XTALAMPL,			0x418C)		/* Crystal Oscillator Critical Amplitude */

/* Baseband */
SFRX(AX5044_45_BBTUNE,				0x4190)		/* Baseband Tuning */
SFRX(AX5044_45_BBOFFSCAP,			0x4191)		/* Baseband Offset Compensation Capacitors */

/* ADC */
SFRX(AX5044_45_ADCCLK,				0x4193)		/* SAR ADC Clock Settings */
SFRX(AX5044_45_ADCMISC,				0x4194)		/* SAR ADC Miscellaneous Settings */

/* MAC Layer Parameters */
/* Packet Format */
SFRX(AX5044_45_PKTADDRCFG,			0x4200)		/* Packet Address Config */
SFRX(AX5044_45_PKTLENPOS,			0x4201)		/* Packet Length Byte Position */
SFRX(AX5044_45_PKTLENBITS,			0x4202)		/* Packet Length Significant Bits */
SFRX(AX5044_45_PKTLENOFFSET1,		0x4203)		/* Packet Length Offset 1 */
SFRX(AX5044_45_PKTLENOFFSET0,		0x4204)		/* Packet Length Offset 0 */
SFRX(AX5044_45_PKTMAXLEN1,			0x4205)		/* Packet Maximum Length 1 */
SFRX(AX5044_45_PKTMAXLEN0,			0x4206)		/* Packet Maximum Length 0 */
SFRX(AX5044_45_PKTADDRA4,			0x4207)		/* Packet Address A 4 */
SFRX(AX5044_45_PKTADDRA3,			0x4208)		/* Packet Address A 3 */
SFRX(AX5044_45_PKTADDRA2,			0x4209)		/* Packet Address A 2 */
SFRX(AX5044_45_PKTADDRA1,			0x420A)		/* Packet Address A 1 */
SFRX(AX5044_45_PKTADDRA0,			0x420B)		/* Packet Address A 0 */
SFRX(AX5044_45_PKTADDRB4,			0x420C)		/* Packet Address B 4 */
SFRX(AX5044_45_PKTADDRB3,			0x420D)		/* Packet Address B 3 */
SFRX(AX5044_45_PKTADDRB2,			0x420E)		/* Packet Address B 2 */
SFRX(AX5044_45_PKTADDRB1,			0x420F)		/* Packet Address B 1 */
SFRX(AX5044_45_PKTADDRB0,			0x4210)		/* Packet Address B 0 */
SFRX(AX5044_45_PKTADDRENA,			0x4211)		/* Packet Address Enable */
SFRX(AX5044_45_PKTADDRMASK4,		0x4212)		/* Packet Address Mask 4 */
SFRX(AX5044_45_PKTADDRMASK3,		0x4213)		/* Packet Address Mask 3 */
SFRX(AX5044_45_PKTADDRMASK2,		0x4214)		/* Packet Address Mask 2 */
SFRX(AX5044_45_PKTADDRMASK1,		0x4215)		/* Packet Address Mask 1 */
SFRX(AX5044_45_PKTADDRMASK0,		0x4216)		/* Packet Address Mask 0 */

/* Pattern Match */
SFRX(AX5044_45_MATCH0APAT3,			0x4220)		/* Pattern Match Unit 0a, Pattern */
SFRX(AX5044_45_MATCH0APAT2,			0x4221)		/* Pattern Match Unit 0a, Pattern */
SFRX(AX5044_45_MATCH0APAT1,			0x4222)		/* Pattern Match Unit 0a, Pattern */
SFRX(AX5044_45_MATCH0APAT0,			0x4223)		/* Pattern Match Unit 0a, Pattern */
SFRX(AX5044_45_MATCH0ALEN,			0x4224)		/* Pattern Match Unit 0a, Pattern Length */
SFRX(AX5044_45_MATCH0AMIN,			0x4225)		/* Pattern Match Unit 0a, Minimum Match */
SFRX(AX5044_45_MATCH0AMAX,			0x4226)		/* Pattern Match Unit 0a, Maximum Match */
SFRX(AX5044_45_MATCH0BPAT3,			0x4227)		/* Pattern Match Unit 0b, Pattern */
SFRX(AX5044_45_MATCH0BPAT2,			0x4228)		/* Pattern Match Unit 0b, Pattern */
SFRX(AX5044_45_MATCH0BPAT1,			0x4229)		/* Pattern Match Unit 0b, Pattern */
SFRX(AX5044_45_MATCH0BPAT0,			0x422A)		/* Pattern Match Unit 0b, Pattern */
SFRX(AX5044_45_MATCH0BLEN,			0x422B)		/* Pattern Match Unit 0b, Pattern Length */
SFRX(AX5044_45_MATCH0BMIN,			0x422C)		/* Pattern Match Unit 0b, Minimum Match */
SFRX(AX5044_45_MATCH0BMAX,			0x422D)		/* Pattern Match Unit 0b, Maximum Match */
SFRX(AX5044_45_MATCH1PAT1,			0x4230)		/* Pattern Match Unit 1, Pattern */
SFRX(AX5044_45_MATCH1PAT0,			0x4231)		/* Pattern Match Unit 1, Pattern */
SFRX(AX5044_45_MATCH1LEN,			0x4232)		/* Pattern Match Unit 1, Pattern Length */
SFRX(AX5044_45_MATCH1MIN,			0x4233)		/* Pattern Match Unit 1, Minimum Match */
SFRX(AX5044_45_MATCH1MAX,			0x4234)		/* Pattern Match Unit 1, Maximum Match */

/* Packet Controller */
SFRX(AX5044_45_TMGTXBOOST,			0x4240)		/* Transmit PLL Boost Time */
SFRX(AX5044_45_TMGTXSETTLE,			0x4241)		/* Transmit PLL (post Boost) Settling Time */
SFRX(AX5044_45_TMGRXBOOST,			0x4242)		/* Receive PLL Boost Time */
SFRX(AX5044_45_TMGRXSETTLE,			0x4243)		/* Receive PLL (post Boost) Settling Time */
SFRX(AX5044_45_TMGRXOFFSACQ0,		0x4244)		/* Receive Baseband DC Offset Acquisition First Stage Time */
SFRX(AX5044_45_TMGRXOFFSACQ1,		0x4245)		/* Receive Baseband DC Offset Acquisition Second Stage Time */
SFRX(AX5044_45_TMGRXOFFSACQ2,		0x4246)		/* Receive Baseband DC Offset Acquisition After Di-versity Time */
SFRX(AX5044_45_TMGRXCOARSEAGC,		0x4247)		/* Receive Coarse AGC Time */
SFRX(AX5044_45_TMGRXAGC,			0x4248)		/* Receiver AGC Settling Time */
SFRX(AX5044_45_TMGRXRSSI,			0x4249)		/* Receiver RSSI Settling Time */
SFRX(AX5044_45_TMGRXPREAMBLE1,		0x424A)		/* Receiver Preamble 1 Timeout */
SFRX(AX5044_45_TMGRXPREAMBLE2,		0x424B)		/* Receiver Preamble 2 Timeout */
SFRX(AX5044_45_TMGRXPREAMBLE3,		0x424C)		/* Receiver Preamble 3 Timeout */
SFRX(AX5044_45_RSSIREFERENCE,		0x4250)		/* RSSI Offset */
SFRX(AX5044_45_RSSIABSTHR,			0x4251)		/* RSSI Absolute Threshold */
SFRX(AX5044_45_BGNDRSSIGAIN,		0x4252)		/* Background RSSI Averaging Time Constant */
SFRX(AX5044_45_BGNDRSSITHR,			0x4253)		/* Background RSSI Relative Threshold */
SFRX(AX5044_45_PKTCHUNKSIZE,		0x4254)		/* Packet Chunk Size */
SFRX(AX5044_45_PKTMISCFLAGS,		0x4255)		/* Packet Controller Miscellaneous Flags */
SFRX(AX5044_45_PKTSTOREFLAGS,		0x4256)		/* Packet Controller Store Flags */
SFRX(AX5044_45_PKTACCEPTFLAGS,		0x4257)		/* Packet Controller Accept Flags */

/* Special Functions */
/* General Purpose ADC */
SFRX(AX5044_45_GPADCCTRL,			0x4300)		/* General Purpose ADC Control */
SFRX(AX5044_45_GPADCPERIOD,			0x4301)		/* GPADC Sampling Period */
SFRX(AX5044_45_GPADCVALUE1,			0x4308)		/* GPADC Value */
SFRX(AX5044_45_GPADCVALUE0,			0x4309)		/* GPADC Value */

/* Low Power Oscillator Calibration */
SFRX(AX5044_45_LPOSCCONFIG,			0x4310)		/* Low Power Oscillator Configuration */
SFRX(AX5044_45_LPOSCSTATUS,			0x4311)		/* Low Power Oscillator Status */
SFRX(AX5044_45_LPOSCCLKMUX,			0x4312)		/* LPOSC Reference Frequency Divider */
SFRX(AX5044_45_LPOSCKFILT1,			0x4313)		/* Low Power Oscillator Calibration Filter Constant */
SFRX(AX5044_45_LPOSCKFILT0,			0x4314)		/* Low Power Oscillator Calibration Filter Constant */
SFRX(AX5044_45_LPOSCREF1,			0x4315)		/* Low Power Oscillator Calibration Reference */
SFRX(AX5044_45_LPOSCREF0,			0x4316)		/* Low Power Oscillator Calibration Reference */
SFRX(AX5044_45_LPOSCFREQ1,			0x4317)		/* Low Power Oscillator Calibration Frequency */
SFRX(AX5044_45_LPOSCFREQ0,			0x4318)		/* Low Power Oscillator Calibration Frequency */
SFRX(AX5044_45_LPOSCPER1,			0x4319)		/* Low Power Oscillator Calibration Period */
SFRX(AX5044_45_LPOSCPER0,			0x431A)		/* Low Power Oscillator Calibration Period */

/* DSPmode Interface */
SFRX(AX5044_45_DSPMODECFG,			0x4320)		/* DSP Mode Setting */
SFRX(AX5044_45_DSPMODESKIP2,		0x4321)		/* DSP Mode Skip 2 */
SFRX(AX5044_45_DSPMODESKIP1,		0x4322)		/* DSP Mode Skip 1 */
SFRX(AX5044_45_DSPMODESKIP0,		0x4323)		/* DSP Mode Skip 0 */

/* Vector Modulator */
SFRX(AX5044_45_MODVECINTERP1,		0x4324)		/* Vector Modulator Interpolation Register */
SFRX(AX5044_45_MODVECINTERP0,		0x4325)		/* Vector Modulator Interpolation Register */
SFRX(AX5044_45_MODVECSHIFT,			0x4326)		/* Vector Modulator Vecshift Register */
SFRX(AX5044_45_MODMAXPHASE1,		0x4327)		/* Vector Modulator Maxphase Register */
SFRX(AX5044_45_MODMAXPHASE0,		0x4328)		/* Vector Modulator Maxphase Register */

/* DAC */
SFRX(AX5044_45_DACVALUE1,			0x4330)		/* DAC Value */
SFRX(AX5044_45_DACVALUE0,			0x4331)		/* DAC Value */
SFRX(AX5044_45_DACCONFIG,			0x4332)		/* DAC Configuration */

/* FIFO */
SFRX(AX5044_45_FIFOMEM,				0x4E00)		/* FIFO Memory -> 0x0E00 to 0x0EFF */

/* Spares */
SFRX(AX5044_45_SPAREOUT,			0x4F00)		/* Spare Output */
SFRX(AX5044_45_SPAREIN,				0x4F01)		/* Spare Input */

/* Test Multiplexer */
SFRX(AX5044_45_TMMUX,				0x4F02)		/* TM BOX settings */

/* Digital Test Observation Mux */
SFRX(AX5044_45_TESTOBS,				0x4F03)		/* Test Observation */
SFRX(AX5044_45_TESTOBSSKIP1,		0x4F04)		/* Test Observation Skip */
SFRX(AX5044_45_TESTOBSSKIP0,		0x4F05)		/* Test Observation Skip */
SFRX(AX5044_45_TESTOBSREAD1,		0x4F06)		/* Test Observation Signal Readback */
SFRX(AX5044_45_TESTOBSREAD0,		0x4F07)		/* Test Observation Signal Readback */

/* Power Management */
SFRX(AX5044_45_POWCTRL1,			0x4F08)		/* Power Control 1 */
SFRX(AX5044_45_POWCTRL0,			0x4F09)		/* Power Control 0 */
SFRX(AX5044_45_POWSTATOVER,			0x4F0A)		/* Power Status Overrides */
SFRX(AX5044_45_POWAPEOVER,			0x4F0B)		/* Power APE Overrides */
SFRX(AX5044_45_RFAPEOVER,			0x4F0C)		/* RF APE Override */
SFRX(AX5044_45_REF,					0x4F0D)		/* Reference Adjust */
SFRX(AX5044_45_POWCTRLSLEEP,		0x4F0E)		/* Sleep Power Control */

/* Crystal Oscillator */
SFRX(AX5044_45_XTALREADY,			0x4F12)		/* Crystal Oscillator Ready Detection Mode */

/* PLL */
SFRX(AX5044_45_PLLRNGMISC,			0x4F17)		/* PLL Miscelaneous Autoranging */
SFRX(AX5044_45_PLLRNGMISC2,			0x4F18)		/* PLL Miscellaneous Autoranging 2 */
SFRX(AX5044_45_PLLRNGMISC3,			0x4F19)		/* PLL Miscellaneous Autoranging 3 */
SFRX(AX5044_45_PLLVCOFREQ1,			0x4F1A)		/* Measured VCO Frequency */
SFRX(AX5044_45_PLLVCOFREQ0,			0x4F1B)		/* Measured VCO Frequency */
SFRX(AX5044_45_PLLVCOFREQERR1,		0x4F1C)		/* Measured VCO Frequency Error */
SFRX(AX5044_45_PLLVCOFREQERR0,		0x4F1D)		/* Measured VCO Frequency Error */
SFRX(AX5044_45_PLLVCOBESTERR1,		0x4F1E)		/* Best Measured VCO Frequency Error */
SFRX(AX5044_45_PLLVCOBESTERR0,		0x4F1F)		/* BestMeasured VCO Frequency Error */

/* RF */
SFRX(AX5044_45_RFMISC,				0x4F20)		/* Misc RF Flags */

/* Parameterisation AGC */
SFRX(AX5044_45_AGCCONFIG,			0x4F28)		/* AGC Configuration */
SFRX(AX5044_45_AGCRESETVALUE,		0x4F29)		/* AGC Reset Value */
SFRX(AX5044_45_AGCCTARGET,			0x4F2A)		/* AGC Target */
SFRX(AX5044_45_AGCCINCREASE,		0x4F2B)		/* AGC Gain Increase Settings */
SFRX(AX5044_45_AGCCREDUCE,			0x4F2C)		/* AGC Gain Reduce Settings */
SFRX(AX5044_45_AGCCAHYST,			0x4F2D)		/* AGC Digital Threshold Range */
SFRX(AX5044_45_AGCCBBOFFSRES,		0x4F2E)		/* Baseband Offset Compensation Resistors */
SFRX(AX5044_45_AGCA0BBOFFSRES,		0x4F2F)		/* Baseband Offset Compensation Resistors during Off-set Acquisition Phase 0 */
SFRX(AX5044_45_AGCA1BBOFFSRES,		0x4F30)		/* Baseband Offset Compensation Resistors during Off-set Acquisition Phase 1 */
SFRX(AX5044_45_AGCA2BBOFFSRES,		0x4F31)		/* Baseband Offset Compensation Resistors during Off-set Acquisition Phase 2 */
SFRX(AX5044_45_AGCA0COUNTER,		0x4F32)		/* AGC Gain during Offset Acquisition Phase 0 */
SFRX(AX5044_45_AGCA1COUNTER,		0x4F33)		/* AGC Gain during Offset Acquisition Phase 1 */
SFRX(AX5044_45_AGCBBGAIN2,			0x4F34)		/* Baseband Gain Override */
SFRX(AX5044_45_AGCBBGAIN1,			0x4F35)		/* Baseband Gain Override */
SFRX(AX5044_45_AGCBBGAIN0,			0x4F36)		/* Baseband Gain Override */
SFRX(AX5044_45_AGCANA,				0x4F37)		/* AGC Analog Gain */
SFRX(AX5044_45_AGCDIG3,				0x4F38)		/* AGC Digital Gain */
SFRX(AX5044_45_AGCDIG2,				0x4F39)		/* AGC Digital Gain */
SFRX(AX5044_45_AGCDIG1,				0x4F3A)		/* AGC Digital Gain */
SFRX(AX5044_45_AGCDIG0,				0x4F3B)		/* AGC Digital Gain */
SFRX(AX5044_45_AGCGAINCEILING,		0x4F3C)		/* AGC Gain Ceiling */

/* ADC Conditioning */
SFRX(AX5044_45_ADCIDCLEVEL1,		0x4F3F)		/* ADC I Path DC Level */
SFRX(AX5044_45_ADCIDCLEVEL0,		0x4F40)		/* ADC I Path DC Level */
SFRX(AX5044_45_ADCQDCLEVEL1,		0x4F41)		/* ADC Q Path DC Level */
SFRX(AX5044_45_ADCQDCLEVEL0,		0x4F42)		/* ADC Q Path DC Level */
SFRX(AX5044_45_ADCDCCFG1,			0x4F43)		/* ADC DC Level Configuration ADC */
SFRX(AX5044_45_ADCDCCFG0,			0x4F44)		/* ADC DC Level Configuration */
SFRX(AX5044_45_ADCDBG,				0x4F45)		/* SAR ADC Debug Options */
SFRX(AX5044_45_ADCTEST,				0x4F46)		/* SAR ADC Testmode Settings SEL */
SFRX(AX5044_45_ADCWEIGHT0I1,		0x4F47)		/* Calibration Weight of MSB 0, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT0I0,		0x4F48)		/* Calibration Weight of MSB 0, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT1I1,		0x4F49)		/* Calibration Weight of MSB 1, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT1I0,		0x4F4A)		/* Calibration Weight of MSB 1, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT2I1,		0x4F4B)		/* Calibration Weight of MSB 2, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT2I0,		0x4F4C)		/* Calibration Weight of MSB 2, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT3I1,		0x4F4D)		/* Calibration Weight of MSB 3, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT3I0,		0x4F4E)		/* Calibration Weight of MSB 3, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT4I1,		0x4F4F)		/* Calibration Weight of MSB 4, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT4I0,		0x4F50)		/* Calibration Weight of MSB 4, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT5I1,		0x4F51)		/* Calibration Weight of MSB 5, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT5I0,		0x4F52)		/* Calibration Weight of MSB 5, I-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT0Q1,		0x4F53)		/* Calibration Weight of MSB 0, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT0Q0,		0x4F54)		/* Calibration Weight of MSB 0, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT1Q1,		0x4F55)		/* Calibration Weight of MSB 1, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT1Q0,		0x4F56)		/* Calibration Weight of MSB 1, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT2Q1,		0x4F57)		/* Calibration Weight of MSB 2, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT2Q0,		0x4F58)		/* Calibration Weight of MSB 2, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT3Q1,		0x4F59)		/* Calibration Weight of MSB 3, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT3Q0,		0x4F5A)		/* Calibration Weight of MSB 3, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT4Q1,		0x4F5B)		/* Calibration Weight of MSB 4, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT4Q0,		0x4F5C)		/* Calibration Weight of MSB 4, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT5Q1,		0x4F5D)		/* Calibration Weight of MSB 5, Q-Channel ADC */
SFRX(AX5044_45_ADCWEIGHT5Q0,		0x4F5E)		/* Calibration Weight of MSB 5, Q-Channel ADC */
SFRX(AX5044_45_ADCSCALINGI1,		0x4F5F)		/* Scaling Factor for LSB value, I-Channel ADC */
SFRX(AX5044_45_ADCSCALINGI0,		0x4F60)		/* Scaling Factor for LSB value, I-Channel ADC */
SFRX(AX5044_45_ADCSCALINGQ1,		0x4F61)		/* Scaling Factor for LSB value, Q-Channel ADC */
SFRX(AX5044_45_ADCSCALINGQ0,		0x4F62)		/* Scaling Factor for LSB value, Q-Channel ADC */
SFRX(AX5044_45_ADCOFFSETI,			0x4F63)		/* ADC Offset, I-Channel */
SFRX(AX5044_45_ADCOFFSETQ,			0x4F64)		/* ADC Offset, Q-Channel */
SFRX(AX5044_45_ADCDOUTI1,			0x4F65)		/* ADC Output, I-Channel */
SFRX(AX5044_45_ADCDOUTI0,			0x4F66)		/* ADC Output, I-Channel */
SFRX(AX5044_45_ADCDOUTQ1,			0x4F67)		/* ADC Output, Q-Channel */
SFRX(AX5044_45_ADCDOUTQ0,			0x4F68)		/* ADC Output, Q-Channel */
SFRX(AX5044_45_ADCREGOUT1,			0x4F69)		/* Weighted & Scaled ADC Output */
SFRX(AX5044_45_ADCREGOUT0,			0x4F6A)		/* Weighted & Scaled ADC Output */
SFRX(AX5044_45_ADCCLKDIV1,			0x4F6B)		/* if adc clk Divider */
SFRX(AX5044_45_ADCCLKDIV0,			0x4F6C)		/* if adc clk Divider */

/* Baseband */
SFRX(AX5044_45_DECSHIFT,			0x4F70)		/* Decimation Filter Gain */
SFRX(AX5044_45_RECVMISC,			0x4F71)		/* Receiver Miscellaneous Configuration */
SFRX(AX5044_45_BBTUNEDBG,			0x4F72)		/* Baseband Calibration */
SFRX(AX5044_45_BBTUNEFREQ,			0x4F73)		/* Baseband Calibration Frequency FILT */
SFRX(AX5044_45_BBIBIAS,				0x4F74)		/* Baseband Filter Bypass */
SFRX(AX5044_45_BBBYPASS,			0x4F75)		/* Baseband Filter Bypass */
SFRX(AX5044_45_BBDETECTOR1,			0x4F76)		/* Baseband Power Detector 1 */
SFRX(AX5044_45_BBDETECTOR0,			0x4F77)		/* Baseband Power Detector 0 */
SFRX(AX5044_45_BBOFFSFUNC,			0x4F78)		/* Baseband Offset Compensation Function */
SFRX(AX5044_45_BBOFFSRNG,			0x4F79)		/* Baseband Offset Compensation Range */

/* Modulator */
SFRX(AX5044_45_MODGAMMAA1,			0x4F80)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMAA0,			0x4F81)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMA0A1,			0x4F82)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMA0A0,			0x4F83)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMA1A1,			0x4F84)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMA1A0,			0x4F85)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMAB1,			0x4F86)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMAB0,			0x4F87)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMAC1,			0x4F88)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMAC0,			0x4F89)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMAD1,			0x4F8A)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMAD0,			0x4F8B)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMAE1,			0x4F8C)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODGAMMAE0,			0x4F8D)		/* Modulator Amplitude Predistortion Coefficient */
SFRX(AX5044_45_MODDEBUG,			0x4F8E)		/* Modulator Debug Flags */
SFRX(AX5044_45_MODCFGP,				0x4F8F)		/* Modulator Configuration P */
SFRX(AX5044_45_MODMSHAPE,			0x4F90)		/* Modulator Mismatch Shaping Shift Register */

/* Radio Controller */
SFRX(AX5044_45_RCTRLFRMDBG1,		0x4FA0)		/* Radio Controller Frame Test Control Injection */
SFRX(AX5044_45_RCTRLFRMDBG0,		0x4FA1)		/* Radio Controller Frame Test Data Injection */
SFRX(AX5044_45_RCTRLDBGCTRL,		0x4FA2)		/* Radio Controller Debug Control */
SFRX(AX5044_45_RCTRLFRMRXOBS1,		0x4FA4)		/* Radio Controller Framing Input Observation */
SFRX(AX5044_45_RCTRLFRMRXOBS0,		0x4FA5)		/* Radio Controller Framing Input Observation */
SFRX(AX5044_45_RCTRLFRMTXOBS1,		0x4FA6)		/* Radio Controller Framing Output Observation */
SFRX(AX5044_45_RCTRLFRMTXOBS0,		0x4FA7)		/* Radio Controller Framing Output Observation */

/* Scan */
SFRX(AX5044_45_SCANMISC,			0x4FB0)		/* Scan miscellaneous */
SFRX(AX5044_45_SCANCHAIN1,			0x4FBF)		/* One Scan Chain */
SFRX(AX5044_45_SCANCHAIN3,			0x4FBE)		/* Three Scan Chains */

/* FEC */
SFRX(AX5044_45_FECMEM,				0x4FC0)		/* FEC Memory -> 0x0FC0 to 0x0FEF */


/********** Radio RegistersNB, X Address SpaceNB, Non-Blocking Version **********/
#if !defined AX5044_45_DISABLE_NONBLOCKING
/* Revision & Interface Probing, Non-Blocking */
SFRX(AX5044_45_SILICONREVISIONNB,		0x5000)		/* Silicon Revision, Non-Blocking */
SFRX(AX5044_45_SCRATCHNB,				0x5001)		/* Scratch Register, Non-Blocking */

/* Operating Mode, Non-Blocking */
SFRX(AX5044_45_PWRMODENB,				0x5002)		/* Power Mode, Non-Blocking */

/* Voltage Regulator, Non-Blocking */
SFRX(AX5044_45_POWSTATNB,				0x5003)		/* Power Management Status, Non-Blocking */
SFRX(AX5044_45_POWSTICKYSTATNB,			0x5004)		/* Power Management Sticky Status, Non-Blocking */
SFRX(AX5044_45_POWIRQMASKNB,			0x5005)		/* Power Management Interrupt Mask, Non-Blocking */

/* Interrupt Control, Non-Blocking */
SFRX(AX5044_45_IRQMASK1NB,				0x5006)		/* IRQ Mask, Non-Blocking */
SFRX(AX5044_45_IRQMASK0NB,				0x5007)		/* IRQ Mask, Non-Blocking */
SFRX(AX5044_45_RADIOEVENTMASK0NB,		0x5009)		/* Radio Event Mask, Non-Blocking */
SFRX(AX5044_45_IRQINVERSION1NB,			0x500A)		/* IRQ Inversion, Non-Blocking */
SFRX(AX5044_45_IRQINVERSION0NB,			0x500B)		/* IRQ Inversion, Non-Blocking */
SFRX(AX5044_45_IRQREQUEST1NB,			0x500C)		/* IRQ Request, Non-Blocking */
SFRX(AX5044_45_IRQREQUEST0NB,			0x500D)		/* IRQ Request, Non-Blocking */
SFRX(AX5044_45_RADIOEVENTREQ0NB,		0x500F)		/* Radio Event Request, Non-Blocking */

/* Modulation & Framing, Non-Blocking */
SFRX(AX5044_45_MODULATIONNB,			0x5010)		/* Modulation, Non-Blocking */
SFRX(AX5044_45_ENCODING1NB,				0x5011)		/* Encoder/Decoder Settings, Non-Blocking */
SFRX(AX5044_45_ENCODING0NB,				0x5012)		/* Encoder/Decoder Settings, Non-Blocking */
SFRX(AX5044_45_FRAMINGNB,				0x5013)		/* Framing settings, Non-Blocking */
SFRX(AX5044_45_CRCCFGNB,				0x5014)		/* CRC settings, Non-Blocking */
SFRX(AX5044_45_CRCINIT3NB,				0x5015)		/* CRC Initialisation Data, Non-Blocking */
SFRX(AX5044_45_CRCINIT2NB,				0x5016)		/* CRC Initialisation Data, Non-Blocking */
SFRX(AX5044_45_CRCINIT1NB,				0x5017)		/* CRC Initialisation Data, Non-Blocking */
SFRX(AX5044_45_CRCINIT0NB,				0x5018)		/* CRC Initialisation Data, Non-Blocking */

/* Forward Error Correction, Non-Blocking */
SFRX(AX5044_45_FECNB,					0x5019)		/* FEC (Viterbi) Configuration, Non-Blocking */
SFRX(AX5044_45_FECSYNCNB,				0x501A)		/* Interleaver Synchronisation Threshold, Non-Blocking */
SFRX(AX5044_45_FECSTATUSNB,				0x501B)		/* FEC Status, Non-Blocking */

/* Status, Non-Blocking */
SFRX(AX5044_45_RADIOSTATENB,			0x501C)		/* Radio Controller State, Non-Blocking */
SFRX(AX5044_45_XTALSTATUSNB,			0x501D)		/* Crystal Oscillator Status, Non-Blocking */

/* Pin Configuration, Non-Blocking */
SFRX(AX5044_45_PINSTATENB,				0x5020)		/* Pinstate, Non-Blocking */
SFRX(AX5044_45_PINFUNCSYSCLKNB,			0x5021)		/* SYSCLK Pin Function, Non-Blocking */
SFRX(AX5044_45_PINFUNCDCLKNB,			0x5022)		/* DCLK Pin Function, Non-Blocking */
SFRX(AX5044_45_PINFUNCDATANB,			0x5023)		/* DATA Pin Function, Non-Blocking */
SFRX(AX5044_45_PINFUNCIRQNB,			0x5024)		/* IRQ Pin Function, Non-Blocking */
SFRX(AX5044_45_PINFUNCANTSELNB,			0x5025)		/* ANTSEL Pin Function, Non-Blocking */
SFRX(AX5044_45_PINFUNCPWRAMPNB,			0x5026)		/* PWRAMP Pin Function, Non-Blocking */
SFRX(AX5044_45_PWRAMPNB,				0x5027)		/* PWRAMP Control, Non-Blocking */

/* FIFO, Non-Blocking */
SFRX(AX5044_45_FIFOSTATNB,				0x5028)		/* FIFO Control, Non-Blocking */
SFRX(AX5044_45_FIFODATANB,				0x5029)		/* FIFO Data, Non-Blocking */
SFRX(AX5044_45_FIFOCOUNT1NB,			0x502A)		/* Number of Words currently in FIFO, Non-Blocking */
SFRX(AX5044_45_FIFOCOUNT0NB,			0x502B)		/* Number of Words currently in FIFO, Non-Blocking */
SFRX(AX5044_45_FIFOFREE1NB,				0x502C)		/* Number of Words that can be written to FIFO, Non-Blocking */
SFRX(AX5044_45_FIFOFREE0NB,				0x502D)		/* Number of Words that can be written to FIFO, Non-Blocking */
SFRX(AX5044_45_FIFOTHRESH0NB,			0x502F)		/* FIFO Threshold, Non-Blocking */

/* Synthesizer, Non-Blocking */
SFRX(AX5044_45_PLLLOOPNB,				0x5030)		/* PLL Loop Filter Settings, Non-Blocking */
SFRX(AX5044_45_PLLCPINB,				0x5031)		/* PLL Charge Pump Current (Boosted), Non-Blocking */
SFRX(AX5044_45_PLLRANGINGA1NB,			0x5032)		/* PLL Autoranging, Non-Blocking */
SFRX(AX5044_45_PLLRANGINGA0NB,			0x5033)		/* PLL Autoranging, Non-Blocking */
SFRX(AX5044_45_FREQA3NB,				0x5034)		/* Synthesizer Frequency, Non-Blocking */
SFRX(AX5044_45_FREQA2NB,				0x5035)		/* Synthesizer Frequency, Non-Blocking */
SFRX(AX5044_45_FREQA1NB,				0x5036)		/* Synthesizer Frequency, Non-Blocking */
SFRX(AX5044_45_FREQA0NB,				0x5037)		/* Synthesizer Frequency, Non-Blocking */
SFRX(AX5044_45_PLLLOOPBOOSTNB,			0x5038)		/* PLL Loop Filter Settings (Boosted), Non-Blocking */
SFRX(AX5044_45_PLLCPIBOOSTNB,			0x5039)		/* PLL Charge Pump Current, Non-Blocking */
SFRX(AX5044_45_PLLRANGINGB1NB,			0x503A)		/* PLL Autoranging, Non-Blocking */
SFRX(AX5044_45_PLLRANGINGB0NB,			0x503B)		/* PLL Autoranging, Non-Blocking */
SFRX(AX5044_45_FREQB3NB,				0x503C)		/* Synthesizer Frequency, Non-Blocking */
SFRX(AX5044_45_FREQB2NB,				0x503D)		/* Synthesizer Frequency, Non-Blocking */
SFRX(AX5044_45_FREQB1NB,				0x503E)		/* Synthesizer Frequency, Non-Blocking */
SFRX(AX5044_45_FREQB0NB,				0x503F)		/* Synthesizer Frequency, Non-Blocking */
SFRX(AX5044_45_PLLVCODIVNB,				0x5040)		/* PLL Divider Settings, Non-Blocking */

/* Signal Strength, Non-Blocking */
SFRX(AX5044_45_RSSINB,					0x5041)		/* Received Signal Strength Indicator, Non-Blocking */
SFRX(AX5044_45_BGNDRSSINB,				0x5042)		/* Background RSSI, Non-Blocking */
SFRX(AX5044_45_DIVERSITYNB,				0x5043)		/* Antenna Diversity Configuration, Non-Blocking */
SFRX(AX5044_45_AGCCOUNTERNB,			0x5044)		/* AGC Current Value, Non-Blocking */

/* Receiver Tracking, Non-Blocking */
SFRX(AX5044_45_TRKDATARATE2NB,			0x5045)		/* Datarate Tracking, Non-Blocking */
SFRX(AX5044_45_TRKDATARATE1NB,			0x5046)		/* Datarate Tracking, Non-Blocking */
SFRX(AX5044_45_TRKDATARATE0NB,			0x5047)		/* Datarate Tracking, Non-Blocking */
SFRX(AX5044_45_TRKAMPL1NB,				0x5048)		/* Amplitude Tracking, Non-Blocking */
SFRX(AX5044_45_TRKAMPL0NB,				0x5049)		/* Amplitude Tracking, Non-Blocking */
SFRX(AX5044_45_TRKPHASE1NB,				0x504A)		/* Phase Tracking, Non-Blocking */
SFRX(AX5044_45_TRKPHASE0NB,				0x504B)		/* Phase Tracking, Non-Blocking */
SFRX(AX5044_45_TRKRFFREQ2NB,			0x504D)		/* RF Frequency Tracking, Non-Blocking */
SFRX(AX5044_45_TRKRFFREQ1NB,			0x504E)		/* RF Frequency Tracking, Non-Blocking */
SFRX(AX5044_45_TRKRFFREQ0NB,			0x504F)		/* RF Frequency Tracking, Non-Blocking */
SFRX(AX5044_45_TRKFREQ1NB,				0x5050)		/* Frequency Tracking, Non-Blocking */
SFRX(AX5044_45_TRKFREQ0NB,				0x5051)		/* Frequency Tracking, Non-Blocking */
SFRX(AX5044_45_TRKFSKDEMOD1NB,			0x5052)		/* FSK Demodulator Tracking, Non-Blocking */
SFRX(AX5044_45_TRKFSKDEMOD0NB,			0x5053)		/* FSK Demodulator Tracking, Non-Blocking */
SFRX(AX5044_45_TRKAFSKDEMOD1NB,			0x5054)		/* AFSK Demodulator Tracking, Non-Blocking */
SFRX(AX5044_45_TRKAFSKDEMOD0NB,			0x5055)		/* AFSK Demodulator Tracking, Non-Blocking */

/* Timer, Non-Blocking */
SFRX(AX5044_45_TIMER2NB,				0x5059)		/* 1MHz Timer, Non-Blocking */
SFRX(AX5044_45_TIMER1NB,				0x505A)		/* 1MHz Timer, Non-Blocking */
SFRX(AX5044_45_TIMER0NB,				0x505B)		/* 1MHz Timer, Non-Blocking */
SFRX(AX5044_45_TIMERCLKNB,				0x505C)		/* Internal Timer Clock Setting, Non-Blocking */

/* Time Stamp, Non-Blocking */
SFRX(AX5044_45_RCTRLTIMESTAMP2NB,		0x5060)		/* Radio Controller Timestamp Count, Non-Blocking */
SFRX(AX5044_45_RCTRLTIMESTAMP1NB,		0x5061)		/* Radio Controller Timestamp Count, Non-Blocking */
SFRX(AX5044_45_RCTRLTIMESTAMP0NB,		0x5062)		/* Radio Controller Timestamp Count, Non-Blocking */
SFRX(AX5044_45_RCTRLTIMETXENANB,		0x5064)		/* Radio Controller Timestamp Enable, Non-Blocking */

/* Wakeup Timer, Non-Blocking */
SFRX(AX5044_45_WAKEUPTIMER1NB,			0x5068)		/* Wakeup Timer, Non-Blocking */
SFRX(AX5044_45_WAKEUPTIMER0NB,			0x5069)		/* Wakeup Timer, Non-Blocking */
SFRX(AX5044_45_WAKEUP1NB,				0x506A)		/* Wakeup Time, Non-Blocking */
SFRX(AX5044_45_WAKEUP0NB,				0x506B)		/* Wakeup Time, Non-Blocking */
SFRX(AX5044_45_WAKEUPFREQ1NB,			0x506C)		/* Wakeup Frequency, Non-Blocking */
SFRX(AX5044_45_WAKEUPFREQ0NB,			0x506D)		/* Wakeup Frequency, Non-Blocking */
SFRX(AX5044_45_WAKEUPXOEARLYNB,			0x506E)		/* Wakeup Crystal Oscillator Early, Non-Blocking */

/* DSPmode 2, Non-Blocking */
SFRX(AX5044_45_DSPMODESHREGNB,			0x506F)		/* DSPmode SPI Shift Register Access, Non-Blocking */

/* Physical Layer Parameters, Non-Blocking */
/* Receiver Parameters, Non-Blocking */
SFRX(AX5044_45_IFFREQ1NB,				0x5100)		/* 2nd LO / IF Frequency, Non-Blocking */
SFRX(AX5044_45_IFFREQ0NB,				0x5101)		/* 2nd LO / IF Frequency, Non-Blocking */
SFRX(AX5044_45_DECIMATION1NB,			0x5102)		/* Decimation Factor, Non-Blocking */
SFRX(AX5044_45_DECIMATION0NB,			0x5103)		/* Decimation Factor, Non-Blocking */
SFRX(AX5044_45_RXDATARATE2NB,			0x5104)		/* Receiver Datarate, Non-Blocking */
SFRX(AX5044_45_RXDATARATE1NB,			0x5105)		/* Receiver Datarate, Non-Blocking */
SFRX(AX5044_45_RXDATARATE0NB,			0x5106)		/* Receiver Datarate, Non-Blocking */
SFRX(AX5044_45_MAXDROFFSET2NB,			0x5107)		/* Maximum Receiver Datarate Offset, Non-Blocking */
SFRX(AX5044_45_MAXDROFFSET1NB,			0x5108)		/* Maximum Receiver Datarate Offset, Non-Blocking */
SFRX(AX5044_45_MAXDROFFSET0NB,			0x5109)		/* Maximum Receiver Datarate Offset, Non-Blocking */
SFRX(AX5044_45_MAXRFOFFSET2NB,			0x510A)		/* Maximum Receiver RF Offset, Non-Blocking */
SFRX(AX5044_45_MAXRFOFFSET1NB,			0x510B)		/* Maximum Receiver RF Offset, Non-Blocking */
SFRX(AX5044_45_MAXRFOFFSET0NB,			0x510C)		/* Maximum Receiver RF Offset, Non-Blocking */
SFRX(AX5044_45_FSKDMAX1NB,				0x510D)		/* Four FSK Rx Deviation, Non-Blocking */
SFRX(AX5044_45_FSKDMAX0NB,				0x510E)		/* Four FSK Rx Deviation, Non-Blocking */
SFRX(AX5044_45_FSKDMIN1NB,				0x510F)		/* Four FSK Rx Deviation, Non-Blocking */
SFRX(AX5044_45_FSKDMIN0NB,				0x5110)		/* Four FSK Rx Deviation, Non-Blocking */
SFRX(AX5044_45_AFSKSPACE1NB,			0x5111)		/* AFSK Space (0) Frequency, Non-Blocking */
SFRX(AX5044_45_AFSKSPACE0NB,			0x5112)		/* AFSK Space (0) Frequency, Non-Blocking */
SFRX(AX5044_45_AFSKMARK1NB,				0x5113)		/* AFSK Mark (1) Frequency, Non-Blocking */
SFRX(AX5044_45_AFSKMARK0NB,				0x5114)		/* AFSK Mark (1) Frequency, Non-Blocking */
SFRX(AX5044_45_AFSKCTRLNB,				0x5115)		/* AFSK Control, Non-Blocking */
SFRX(AX5044_45_AMPLFILTERNB,			0x5116)		/* Amplitude Filter, Non-Blocking */
SFRX(AX5044_45_RFZIGZAGAMPLNB,			0x5117)		/* RF Zigzag Scanner Amplitude Exponent and Man-tissa, Non-Blocking */
SFRX(AX5044_45_RFZIGZAGFREQNB,			0x5118)		/* RF Zigzag Scanner Frequency, Non-Blocking */
SFRX(AX5044_45_RFFREQUENCYLEAKNB,		0x5119)		/* RF Frequency Recovery Loop Leakiness, Non-Blocking */
SFRX(AX5044_45_FREQUENCYLEAKNB,			0x511A)		/* Baseband Frequency Recovery Loop Leakiness, Non-Blocking */
SFRX(AX5044_45_RXPARAMSETSNB,			0x511B)		/* Receiver Parameter Set Indirection, Non-Blocking */
SFRX(AX5044_45_RXPARAMCURSETNB,			0x511C)		/* Receiver Parameter Current Set, Non-Blocking */
SFRX(AX5044_45_RSSIIRQTHRESHNB,			0x511D)		/* RSSI Interrupt Threshold, Non-Blocking */
SFRX(AX5044_45_RSSIIRQDIRNB,			0x511E)		/* RSSI Interrupt Threshold Direction, Non-Blocking */

/* Receiver Parameter Set 0, Non-Blocking */
SFRX(AX5044_45_AGCTARGET0NB,			0x5120)		/* AGC Target, Non-Blocking */
SFRX(AX5044_45_AGCINCREASE0NB,			0x5121)		/* AGC Gain Increase Settings, Non-Blocking */
SFRX(AX5044_45_AGCREDUCE0NB,			0x5122)		/* AGC Gain Reduce Settings, Non-Blocking */
SFRX(AX5044_45_AGCAHYST0NB,				0x5123)		/* AGC Digital Threshold Range, Non-Blocking */
SFRX(AX5044_45_TIMEGAIN0NB,				0x5124)		/* Timing Gain, Non-Blocking */
SFRX(AX5044_45_DRGAIN0NB,				0x5125)		/* Data Rate Gain, Non-Blocking */
SFRX(AX5044_45_PHASEGAIN0NB,			0x5126)		/* Filter IndexNB, Phase Gain, Non-Blocking */
SFRX(AX5044_45_FREQGAINA0NB,			0x5127)		/* Frequency Gain A, Non-Blocking */
SFRX(AX5044_45_FREQGAINB0NB,			0x5128)		/* Frequency Gain B, Non-Blocking */
SFRX(AX5044_45_FREQGAINC0NB,			0x5129)		/* Frequency Gain C, Non-Blocking */
SFRX(AX5044_45_FREQGAIND0NB,			0x512A)		/* Frequency Gain D, Non-Blocking */
SFRX(AX5044_45_AMPLGAIN0NB,				0x512B)		/* Amplitude Gain, Non-Blocking */
SFRX(AX5044_45_FREQDEV10NB,				0x512C)		/* Receiver Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FREQDEV00NB,				0x512D)		/* Receiver Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FOURFSK0NB,				0x512E)		/* Four FSK Control, Non-Blocking */
SFRX(AX5044_45_BBOFFSRES0NB,			0x512F)		/* Baseband Offset Compensation Resistors, Non-Blocking */

/* Receiver Parameter Set 1, Non-Blocking */
SFRX(AX5044_45_AGCTARGET1NB,			0x5130)		/* AGC Target, Non-Blocking */
SFRX(AX5044_45_AGCINCREASE1NB,			0x5131)		/* AGC Gain Increase Settings, Non-Blocking */
SFRX(AX5044_45_AGCREDUCE1NB,			0x5132)		/* AGC Gain Reduce Settings, Non-Blocking */
SFRX(AX5044_45_AGCAHYST1NB,				0x5133)		/* AGC Digital Threshold Range, Non-Blocking */
SFRX(AX5044_45_TIMEGAIN1NB,				0x5134)		/* Timing Gain, Non-Blocking */
SFRX(AX5044_45_DRGAIN1NB,				0x5135)		/* Data Rate Gain, Non-Blocking */
SFRX(AX5044_45_PHASEGAIN1NB,			0x5136)		/* Filter IndexNB, Phase Gain, Non-Blocking */
SFRX(AX5044_45_FREQGAINA1NB,			0x5137)		/* Frequency Gain A, Non-Blocking */
SFRX(AX5044_45_FREQGAINB1NB,			0x5138)		/* Frequency Gain B, Non-Blocking */
SFRX(AX5044_45_FREQGAINC1NB,			0x5139)		/* Frequency Gain C, Non-Blocking */
SFRX(AX5044_45_FREQGAIND1NB,			0x513A)		/* Frequency Gain D, Non-Blocking */
SFRX(AX5044_45_AMPLGAIN1NB,				0x513B)		/* Amplitude Gain, Non-Blocking */
SFRX(AX5044_45_FREQDEV11NB,				0x513C)		/* Receiver Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FREQDEV01NB,				0x513D)		/* Receiver Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FOURFSK1NB,				0x513E)		/* Four FSK Control, Non-Blocking */
SFRX(AX5044_45_BBOFFSRES1NB,			0x513F)		/* Baseband Offset Compensation Resistors, Non-Blocking */

/* Receiver Parameter Set 2, Non-Blocking */
SFRX(AX5044_45_AGCTARGET2NB,			0x5140)		/* AGC Target, Non-Blocking */
SFRX(AX5044_45_AGCINCREASE2NB,			0x5141)		/* AGC Gain Increase Settings, Non-Blocking */
SFRX(AX5044_45_AGCREDUCE2NB,			0x5142)		/* AGC Gain Reduce Settings, Non-Blocking */
SFRX(AX5044_45_AGCAHYST2NB,				0x5143)		/* AGC Digital Threshold Range, Non-Blocking */
SFRX(AX5044_45_TIMEGAIN2NB,				0x5144)		/* Timing Gain, Non-Blocking */
SFRX(AX5044_45_DRGAIN2NB,				0x5145)		/* Data Rate Gain, Non-Blocking */
SFRX(AX5044_45_PHASEGAIN2NB,			0x5146)		/* Filter IndexNB, Phase Gain, Non-Blocking */
SFRX(AX5044_45_FREQGAINA2NB,			0x5147)		/* Frequency Gain A, Non-Blocking */
SFRX(AX5044_45_FREQGAINB2NB,			0x5148)		/* Frequency Gain B, Non-Blocking */
SFRX(AX5044_45_FREQGAINC2NB,			0x5149)		/* Frequency Gain C, Non-Blocking */
SFRX(AX5044_45_FREQGAIND2NB,			0x514A)		/* Frequency Gain D, Non-Blocking */
SFRX(AX5044_45_AMPLGAIN2NB,				0x514B)		/* Amplitude Gain, Non-Blocking */
SFRX(AX5044_45_FREQDEV12NB,				0x514C)		/* Receiver Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FREQDEV02NB,				0x514D)		/* Receiver Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FOURFSK2NB,				0x514E)		/* Four FSK Control, Non-Blocking */
SFRX(AX5044_45_BBOFFSRES2NB,			0x514F)		/* Baseband Offset Compensation Resistors, Non-Blocking */

/* Receiver Parameter Set 3, Non-Blocking */
SFRX(AX5044_45_AGCTARGET3NB,			0x5150)		/* AGC Target, Non-Blocking */
SFRX(AX5044_45_AGCINCREASE3NB,			0x5151)		/* AGC Gain Increase Settings, Non-Blocking */
SFRX(AX5044_45_AGCREDUCE3NB,			0x5152)		/* AGC Gain Reduce Settings, Non-Blocking */
SFRX(AX5044_45_AGCAHYST3NB,				0x5153)		/* AGC Digital Threshold Range, Non-Blocking */
SFRX(AX5044_45_TIMEGAIN3NB,				0x5154)		/* Timing Gain, Non-Blocking */
SFRX(AX5044_45_DRGAIN3NB,				0x5155)		/* Data Rate Gain, Non-Blocking */
SFRX(AX5044_45_PHASEGAIN3NB,			0x5156)		/* Filter IndexNB, Phase Gain, Non-Blocking */
SFRX(AX5044_45_FREQGAINA3NB,			0x5157)		/* Frequency Gain A, Non-Blocking */
SFRX(AX5044_45_FREQGAINB3NB,			0x5158)		/* Frequency Gain B, Non-Blocking */
SFRX(AX5044_45_FREQGAINC3NB,			0x5159)		/* Frequency Gain C, Non-Blocking */
SFRX(AX5044_45_FREQGAIND3NB,			0x515A)		/* Frequency Gain D, Non-Blocking */
SFRX(AX5044_45_AMPLGAIN3NB,				0x515B)		/* Amplitude Gain, Non-Blocking */
SFRX(AX5044_45_FREQDEV13NB,				0x515C)		/* Receiver Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FREQDEV03NB,				0x515D)		/* Receiver Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FOURFSK3NB,				0x515E)		/* Four FSK Control, Non-Blocking */
SFRX(AX5044_45_BBOFFSRES3NB,			0x515F)		/* Baseband Offset Compensation Resistors, Non-Blocking */

/* Transmitter Parameters, Non-Blocking */
SFRX(AX5044_45_MODCFGFNB,				0x5160)		/* Modulator Configuration F, Non-Blocking */
SFRX(AX5044_45_FSKDEV2NB,				0x5161)		/* FSK Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FSKDEV1NB,				0x5162)		/* FSK Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_FSKDEV0NB,				0x5163)		/* FSK Frequency Deviation, Non-Blocking */
SFRX(AX5044_45_TXRATE3NB,				0x5164)		/* Transmitter Bitrate, Non-Blocking */
SFRX(AX5044_45_TXRATE2NB,				0x5165)		/* Transmitter Bitrate, Non-Blocking */
SFRX(AX5044_45_TXRATE1NB,				0x5166)		/* Transmitter Bitrate, Non-Blocking */
SFRX(AX5044_45_TXRATE0NB,				0x5167)		/* Transmitter Bitrate, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFA1NB,			0x5168)		/* Transmitter Predistortion Coefficient A, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFA0NB,			0x5169)		/* Transmitter Predistortion Coefficient A, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFB1NB,			0x516A)		/* Transmitter Predistortion Coefficient B, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFB0NB,			0x516B)		/* Transmitter Predistortion Coefficient B, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFC1NB,			0x516C)		/* Transmitter Predistortion Coefficient C, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFC0NB,			0x516D)		/* Transmitter Predistortion Coefficient C, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFD1NB,			0x516E)		/* Transmitter Predistortion Coefficient D, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFD0NB,			0x516F)		/* Transmitter Predistortion Coefficient D, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFE1NB,			0x5170)		/* Transmitter Predistortion Coefficient E, Non-Blocking */
SFRX(AX5044_45_TXPWRCOEFFE0NB,			0x5171)		/* Transmitter Predistortion Coefficient E, Non-Blocking */
SFRX(AX5044_45_MODCFGANB,				0x5172)		/* Modulator Configuration A, Non-Blocking */
SFRX(AX5044_45_TXCLKDIVNB,				0x5173)		/* Transmitter Clock Divider, Non-Blocking */
SFRX(AX5044_45_TXAMPLSHAPENB,			0x5174)		/* Transmitter Amplitude Shaping, Non-Blocking */
SFRX(AX5044_45_TXDCCREGNB,				0x5175)		/* Transmitter Trim Registers, Non-Blocking */
SFRX(AX5044_45_TXMISCNB,				0x5176)		/* Transmitter Miscellaneous Registers, Non-Blocking */

/* PLL Parameters, Non-Blocking */
SFRX(AX5044_45_PLLVCOINB,				0x5180)		/* VCO Current, Non-Blocking */
SFRX(AX5044_45_PLLLOCKDETNB,			0x5181)		/* PLL Lock Detect Delay, Non-Blocking */
SFRX(AX5044_45_PLLRNGCFGNB,				0x5182)		/* PLL Ranging Configuration, Non-Blocking */
SFRX(AX5044_45_PLLDITHERNB,				0x5183)		/* PLL Dither, Non-Blocking */
SFRX(AX5044_45_PLLSTATMASKNB,			0x5184)		/* PLL Staus Interrupt Mask, Non-Blocking */
SFRX(AX5044_45_PLLCOMPNB,				0x5185)		/* PLL Ranging ADC Control & Read-out, Non-Blocking */

/* Crystal Oscillator, Non-Blocking */
SFRX(AX5044_45_XTALCAPNB,				0x518A)		/* Crystal Oscillator Load Capacitance Configuration, Non-Blocking */
SFRX(AX5044_45_XTALOSCNB,				0x518B)		/* Crystal Oscillator Configuration, Non-Blocking */
SFRX(AX5044_45_XTALAMPLNB,				0x518C)		/* Crystal Oscillator Critical Amplitude, Non-Blocking */

/* Baseband, Non-Blocking */
SFRX(AX5044_45_BBTUNENB,				0x5190)		/* Baseband Tuning, Non-Blocking */
SFRX(AX5044_45_BBOFFSCAPNB,				0x5191)		/* Baseband Offset Compensation Capacitors, Non-Blocking */

/* ADC, Non-Blocking */
SFRX(AX5044_45_ADCCLKNB,				0x5193)		/* SAR ADC Clock Settings, Non-Blocking */
SFRX(AX5044_45_ADCMISCNB,				0x5194)		/* SAR ADC Miscellaneous Settings, Non-Blocking */

/* MAC Layer Parameters, Non-Blocking */
/* Packet Format, Non-Blocking */
SFRX(AX5044_45_PKTADDRCFGNB,			0x5200)		/* Packet Address Config, Non-Blocking */
SFRX(AX5044_45_PKTLENPOSNB,				0x5201)		/* Packet Length Byte Position, Non-Blocking */
SFRX(AX5044_45_PKTLENBITSNB,			0x5202)		/* Packet Length Significant Bits, Non-Blocking */
SFRX(AX5044_45_PKTLENOFFSET1NB,			0x5203)		/* Packet Length Offset 1, Non-Blocking */
SFRX(AX5044_45_PKTLENOFFSET0NB,			0x5204)		/* Packet Length Offset 0, Non-Blocking */
SFRX(AX5044_45_PKTMAXLEN1NB,			0x5205)		/* Packet Maximum Length 1, Non-Blocking */
SFRX(AX5044_45_PKTMAXLEN0NB,			0x5206)		/* Packet Maximum Length 0, Non-Blocking */
SFRX(AX5044_45_PKTADDRA4NB,				0x5207)		/* Packet Address A 4, Non-Blocking */
SFRX(AX5044_45_PKTADDRA3NB,				0x5208)		/* Packet Address A 3, Non-Blocking */
SFRX(AX5044_45_PKTADDRA2NB,				0x5209)		/* Packet Address A 2, Non-Blocking */
SFRX(AX5044_45_PKTADDRA1NB,				0x520A)		/* Packet Address A 1, Non-Blocking */
SFRX(AX5044_45_PKTADDRA0NB,				0x520B)		/* Packet Address A 0, Non-Blocking */
SFRX(AX5044_45_PKTADDRB4NB,				0x520C)		/* Packet Address B 4, Non-Blocking */
SFRX(AX5044_45_PKTADDRB3NB,				0x520D)		/* Packet Address B 3, Non-Blocking */
SFRX(AX5044_45_PKTADDRB2NB,				0x520E)		/* Packet Address B 2, Non-Blocking */
SFRX(AX5044_45_PKTADDRB1NB,				0x520F)		/* Packet Address B 1, Non-Blocking */
SFRX(AX5044_45_PKTADDRB0NB,				0x5210)		/* Packet Address B 0, Non-Blocking */
SFRX(AX5044_45_PKTADDRENANB,			0x5211)		/* Packet Address Enable, Non-Blocking */
SFRX(AX5044_45_PKTADDRMASK4NB,			0x5212)		/* Packet Address Mask 4, Non-Blocking */
SFRX(AX5044_45_PKTADDRMASK3NB,			0x5213)		/* Packet Address Mask 3, Non-Blocking */
SFRX(AX5044_45_PKTADDRMASK2NB,			0x5214)		/* Packet Address Mask 2, Non-Blocking */
SFRX(AX5044_45_PKTADDRMASK1NB,			0x5215)		/* Packet Address Mask 1, Non-Blocking */
SFRX(AX5044_45_PKTADDRMASK0NB,			0x5216)		/* Packet Address Mask 0, Non-Blocking */

/* Pattern Match, Non-Blocking */
SFRX(AX5044_45_MATCH0APAT3NB,			0x5220)		/* Pattern Match Unit 0aNB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH0APAT2NB,			0x5221)		/* Pattern Match Unit 0aNB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH0APAT1NB,			0x5222)		/* Pattern Match Unit 0aNB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH0APAT0NB,			0x5223)		/* Pattern Match Unit 0aNB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH0ALENNB,			0x5224)		/* Pattern Match Unit 0aNB, Pattern Length, Non-Blocking */
SFRX(AX5044_45_MATCH0AMINNB,			0x5225)		/* Pattern Match Unit 0aNB, Minimum Match, Non-Blocking */
SFRX(AX5044_45_MATCH0AMAXNB,			0x5226)		/* Pattern Match Unit 0aNB, Maximum Match, Non-Blocking */
SFRX(AX5044_45_MATCH0BPAT3NB,			0x5227)		/* Pattern Match Unit 0bNB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH0BPAT2NB,			0x5228)		/* Pattern Match Unit 0bNB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH0BPAT1NB,			0x5229)		/* Pattern Match Unit 0bNB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH0BPAT0NB,			0x522A)		/* Pattern Match Unit 0bNB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH0BLENNB,			0x522B)		/* Pattern Match Unit 0bNB, Pattern Length, Non-Blocking */
SFRX(AX5044_45_MATCH0BMINNB,			0x522C)		/* Pattern Match Unit 0bNB, Minimum Match, Non-Blocking */
SFRX(AX5044_45_MATCH0BMAXNB,			0x522D)		/* Pattern Match Unit 0bNB, Maximum Match, Non-Blocking */
SFRX(AX5044_45_MATCH1PAT1NB,			0x5230)		/* Pattern Match Unit 1NB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH1PAT0NB,			0x5231)		/* Pattern Match Unit 1NB, Pattern, Non-Blocking */
SFRX(AX5044_45_MATCH1LENNB,				0x5232)		/* Pattern Match Unit 1NB, Pattern Length, Non-Blocking */
SFRX(AX5044_45_MATCH1MINNB,				0x5233)		/* Pattern Match Unit 1NB, Minimum Match, Non-Blocking */
SFRX(AX5044_45_MATCH1MAXNB,				0x5234)		/* Pattern Match Unit 1NB, Maximum Match, Non-Blocking */

/* Packet Controller, Non-Blocking */
SFRX(AX5044_45_TMGTXBOOSTNB,			0x5240)		/* Transmit PLL Boost Time, Non-Blocking */
SFRX(AX5044_45_TMGTXSETTLENB,			0x5241)		/* Transmit PLL (post Boost) Settling Time, Non-Blocking */
SFRX(AX5044_45_TMGRXBOOSTNB,			0x5242)		/* Receive PLL Boost Time, Non-Blocking */
SFRX(AX5044_45_TMGRXSETTLENB,			0x5243)		/* Receive PLL (post Boost) Settling Time, Non-Blocking */
SFRX(AX5044_45_TMGRXOFFSACQ0NB,			0x5244)		/* Receive Baseband DC Offset Acquisition First Stage Time, Non-Blocking */
SFRX(AX5044_45_TMGRXOFFSACQ1NB,			0x5245)		/* Receive Baseband DC Offset Acquisition Second Stage Time, Non-Blocking */
SFRX(AX5044_45_TMGRXOFFSACQ2NB,			0x5246)		/* Receive Baseband DC Offset Acquisition After Di-versity Time, Non-Blocking */
SFRX(AX5044_45_TMGRXCOARSEAGCNB,		0x5247)		/* Receive Coarse AGC Time, Non-Blocking */
SFRX(AX5044_45_TMGRXAGCNB,				0x5248)		/* Receiver AGC Settling Time, Non-Blocking */
SFRX(AX5044_45_TMGRXRSSINB,				0x5249)		/* Receiver RSSI Settling Time, Non-Blocking */
SFRX(AX5044_45_TMGRXPREAMBLE1NB,		0x524A)		/* Receiver Preamble 1 Timeout, Non-Blocking */
SFRX(AX5044_45_TMGRXPREAMBLE2NB,		0x524B)		/* Receiver Preamble 2 Timeout, Non-Blocking */
SFRX(AX5044_45_TMGRXPREAMBLE3NB,		0x524C)		/* Receiver Preamble 3 Timeout, Non-Blocking */
SFRX(AX5044_45_RSSIREFERENCENB,			0x5250)		/* RSSI Offset, Non-Blocking */
SFRX(AX5044_45_RSSIABSTHRNB,			0x5251)		/* RSSI Absolute Threshold, Non-Blocking */
SFRX(AX5044_45_BGNDRSSIGAINNB,			0x5252)		/* Background RSSI Averaging Time Constant, Non-Blocking */
SFRX(AX5044_45_BGNDRSSITHRNB,			0x5253)		/* Background RSSI Relative Threshold, Non-Blocking */
SFRX(AX5044_45_PKTCHUNKSIZENB,			0x5254)		/* Packet Chunk Size, Non-Blocking */
SFRX(AX5044_45_PKTMISCFLAGSNB,			0x5255)		/* Packet Controller Miscellaneous Flags, Non-Blocking */
SFRX(AX5044_45_PKTSTOREFLAGSNB,			0x5256)		/* Packet Controller Store Flags, Non-Blocking */
SFRX(AX5044_45_PKTACCEPTFLAGSNB,		0x5257)		/* Packet Controller Accept Flags, Non-Blocking */

/* Special Functions, Non-Blocking */
/* General Purpose ADC, Non-Blocking */
SFRX(AX5044_45_GPADCCTRLNB,				0x5300)		/* General Purpose ADC Control, Non-Blocking */
SFRX(AX5044_45_GPADCPERIODNB,			0x5301)		/* GPADC Sampling Period, Non-Blocking */
SFRX(AX5044_45_GPADCVALUE1NB,			0x5308)		/* GPADC Value, Non-Blocking */
SFRX(AX5044_45_GPADCVALUE0NB,			0x5309)		/* GPADC Value, Non-Blocking */

/* Low Power Oscillator Calibration, Non-Blocking */
SFRX(AX5044_45_LPOSCCONFIGNB,			0x5310)		/* Low Power Oscillator Configuration, Non-Blocking */
SFRX(AX5044_45_LPOSCSTATUSNB,			0x5311)		/* Low Power Oscillator Status, Non-Blocking */
SFRX(AX5044_45_LPOSCCLKMUXNB,			0x5312)		/* LPOSC Reference Frequency Divider, Non-Blocking */
SFRX(AX5044_45_LPOSCKFILT1NB,			0x5313)		/* Low Power Oscillator Calibration Filter Constant, Non-Blocking */
SFRX(AX5044_45_LPOSCKFILT0NB,			0x5314)		/* Low Power Oscillator Calibration Filter Constant, Non-Blocking */
SFRX(AX5044_45_LPOSCREF1NB,				0x5315)		/* Low Power Oscillator Calibration Reference, Non-Blocking */
SFRX(AX5044_45_LPOSCREF0NB,				0x5316)		/* Low Power Oscillator Calibration Reference, Non-Blocking */
SFRX(AX5044_45_LPOSCFREQ1NB,			0x5317)		/* Low Power Oscillator Calibration Frequency, Non-Blocking */
SFRX(AX5044_45_LPOSCFREQ0NB,			0x5318)		/* Low Power Oscillator Calibration Frequency, Non-Blocking */
SFRX(AX5044_45_LPOSCPER1NB,				0x5319)		/* Low Power Oscillator Calibration Period, Non-Blocking */
SFRX(AX5044_45_LPOSCPER0NB,				0x531A)		/* Low Power Oscillator Calibration Period, Non-Blocking */

/* DSPmode Interface, Non-Blocking */
SFRX(AX5044_45_DSPMODECFGNB,			0x5320)		/* DSP Mode Setting, Non-Blocking */
SFRX(AX5044_45_DSPMODESKIP2NB,			0x5321)		/* DSP Mode Skip 2, Non-Blocking */
SFRX(AX5044_45_DSPMODESKIP1NB,			0x5322)		/* DSP Mode Skip 1, Non-Blocking */
SFRX(AX5044_45_DSPMODESKIP0NB,			0x5323)		/* DSP Mode Skip 0, Non-Blocking */

/* Vector Modulator, Non-Blocking */
SFRX(AX5044_45_MODVECINTERP1NB,			0x5324)		/* Vector Modulator Interpolation Register, Non-Blocking */
SFRX(AX5044_45_MODVECINTERP0NB,			0x5325)		/* Vector Modulator Interpolation Register, Non-Blocking */
SFRX(AX5044_45_MODVECSHIFTNB,			0x5326)		/* Vector Modulator Vecshift Register, Non-Blocking */
SFRX(AX5044_45_MODMAXPHASE1NB,			0x5327)		/* Vector Modulator Maxphase Register, Non-Blocking */
SFRX(AX5044_45_MODMAXPHASE0NB,			0x5328)		/* Vector Modulator Maxphase Register, Non-Blocking */

/* DAC, Non-Blocking */
SFRX(AX5044_45_DACVALUE1NB,				0x5330)		/* DAC Value, Non-Blocking */
SFRX(AX5044_45_DACVALUE0NB,				0x5331)		/* DAC Value, Non-Blocking */
SFRX(AX5044_45_DACCONFIGNB,				0x5332)		/* DAC Configuration, Non-Blocking */

/* FIFO, Non-Blocking */
SFRX(AX5044_45_FIFOMEMNB,				0x5E00)		/* FIFO Memory -> 0x0E00 to 0x0EFF, Non-Blocking */

/* Spares, Non-Blocking */
SFRX(AX5044_45_SPAREOUTNB,				0x5F00)		/* Spare Output, Non-Blocking */
SFRX(AX5044_45_SPAREINNB,				0x5F01)		/* Spare Input, Non-Blocking */

/* Test Multiplexer, Non-Blocking */
SFRX(AX5044_45_TMMUXNB,					0x5F02)		/* TM BOX settings, Non-Blocking */

/* Digital Test Observation Mux, Non-Blocking */
SFRX(AX5044_45_TESTOBSNB,				0x5F03)		/* Test Observation, Non-Blocking */
SFRX(AX5044_45_TESTOBSSKIP1NB,			0x5F04)		/* Test Observation Skip, Non-Blocking */
SFRX(AX5044_45_TESTOBSSKIP0NB,			0x5F05)		/* Test Observation Skip, Non-Blocking */
SFRX(AX5044_45_TESTOBSREAD1NB,			0x5F06)		/* Test Observation Signal Readback, Non-Blocking */
SFRX(AX5044_45_TESTOBSREAD0NB,			0x5F07)		/* Test Observation Signal Readback, Non-Blocking */

/* Power Management, Non-Blocking */
SFRX(AX5044_45_POWCTRL1NB,				0x5F08)		/* Power Control 1, Non-Blocking */
SFRX(AX5044_45_POWCTRL0NB,				0x5F09)		/* Power Control 0, Non-Blocking */
SFRX(AX5044_45_POWSTATOVERNB,			0x5F0A)		/* Power Status Overrides, Non-Blocking */
SFRX(AX5044_45_POWAPEOVERNB,			0x5F0B)		/* Power APE Overrides, Non-Blocking */
SFRX(AX5044_45_RFAPEOVERNB,				0x5F0C)		/* RF APE Override, Non-Blocking */
SFRX(AX5044_45_REFNB,					0x5F0D)		/* Reference Adjust, Non-Blocking */
SFRX(AX5044_45_POWCTRLSLEEPNB,			0x5F0E)		/* Sleep Power Control, Non-Blocking */

/* Crystal Oscillator, Non-Blocking */
SFRX(AX5044_45_XTALREADYNB,				0x5F12)		/* Crystal Oscillator Ready Detection Mode, Non-Blocking */

/* PLL, Non-Blocking */
SFRX(AX5044_45_PLLRNGMISCNB,			0x5F17)		/* PLL Miscelaneous Autoranging, Non-Blocking */
SFRX(AX5044_45_PLLRNGMISC2NB,			0x5F18)		/* PLL Miscellaneous Autoranging 2, Non-Blocking */
SFRX(AX5044_45_PLLRNGMISC3NB,			0x5F19)		/* PLL Miscellaneous Autoranging 3, Non-Blocking */
SFRX(AX5044_45_PLLVCOFREQ1NB,			0x5F1A)		/* Measured VCO Frequency, Non-Blocking */
SFRX(AX5044_45_PLLVCOFREQ0NB,			0x5F1B)		/* Measured VCO Frequency, Non-Blocking */
SFRX(AX5044_45_PLLVCOFREQERR1NB,		0x5F1C)		/* Measured VCO Frequency Error, Non-Blocking */
SFRX(AX5044_45_PLLVCOFREQERR0NB,		0x5F1D)		/* Measured VCO Frequency Error, Non-Blocking */
SFRX(AX5044_45_PLLVCOBESTERR1NB,		0x5F1E)		/* Best Measured VCO Frequency Error, Non-Blocking */
SFRX(AX5044_45_PLLVCOBESTERR0NB,		0x5F1F)		/* BestMeasured VCO Frequency Error, Non-Blocking */

/* RF, Non-Blocking */
SFRX(AX5044_45_RFMISCNB,				0x5F20)		/* Misc RF Flags, Non-Blocking */

/* Parameterisation AGC, Non-Blocking */
SFRX(AX5044_45_AGCCONFIGNB,				0x5F28)		/* AGC Configuration, Non-Blocking */
SFRX(AX5044_45_AGCRESETVALUENB,			0x5F29)		/* AGC Reset Value, Non-Blocking */
SFRX(AX5044_45_AGCCTARGETNB,			0x5F2A)		/* AGC Target, Non-Blocking */
SFRX(AX5044_45_AGCCINCREASENB,			0x5F2B)		/* AGC Gain Increase Settings, Non-Blocking */
SFRX(AX5044_45_AGCCREDUCENB,			0x5F2C)		/* AGC Gain Reduce Settings, Non-Blocking */
SFRX(AX5044_45_AGCCAHYSTNB,				0x5F2D)		/* AGC Digital Threshold Range, Non-Blocking */
SFRX(AX5044_45_AGCCBBOFFSRESNB,			0x5F2E)		/* Baseband Offset Compensation Resistors, Non-Blocking */
SFRX(AX5044_45_AGCA0BBOFFSRESNB,		0x5F2F)		/* Baseband Offset Compensation Resistors during Off-set Acquisition Phase 0, Non-Blocking */
SFRX(AX5044_45_AGCA1BBOFFSRESNB,		0x5F30)		/* Baseband Offset Compensation Resistors during Off-set Acquisition Phase 1, Non-Blocking */
SFRX(AX5044_45_AGCA2BBOFFSRESNB,		0x5F31)		/* Baseband Offset Compensation Resistors during Off-set Acquisition Phase 2, Non-Blocking */
SFRX(AX5044_45_AGCA0COUNTERNB,			0x5F32)		/* AGC Gain during Offset Acquisition Phase 0, Non-Blocking */
SFRX(AX5044_45_AGCA1COUNTERNB,			0x5F33)		/* AGC Gain during Offset Acquisition Phase 1, Non-Blocking */
SFRX(AX5044_45_AGCBBGAIN2NB,			0x5F34)		/* Baseband Gain Override, Non-Blocking */
SFRX(AX5044_45_AGCBBGAIN1NB,			0x5F35)		/* Baseband Gain Override, Non-Blocking */
SFRX(AX5044_45_AGCBBGAIN0NB,			0x5F36)		/* Baseband Gain Override, Non-Blocking */
SFRX(AX5044_45_AGCANANB,				0x5F37)		/* AGC Analog Gain, Non-Blocking */
SFRX(AX5044_45_AGCDIG3NB,				0x5F38)		/* AGC Digital Gain, Non-Blocking */
SFRX(AX5044_45_AGCDIG2NB,				0x5F39)		/* AGC Digital Gain, Non-Blocking */
SFRX(AX5044_45_AGCDIG1NB,				0x5F3A)		/* AGC Digital Gain, Non-Blocking */
SFRX(AX5044_45_AGCDIG0NB,				0x5F3B)		/* AGC Digital Gain, Non-Blocking */
SFRX(AX5044_45_AGCGAINCEILINGNB,		0x5F3C)		/* AGC Gain Ceiling, Non-Blocking */

/* ADC Conditioning, Non-Blocking */
SFRX(AX5044_45_ADCIDCLEVEL1NB,			0x5F3F)		/* ADC I Path DC Level, Non-Blocking */
SFRX(AX5044_45_ADCIDCLEVEL0NB,			0x5F40)		/* ADC I Path DC Level, Non-Blocking */
SFRX(AX5044_45_ADCQDCLEVEL1NB,			0x5F41)		/* ADC Q Path DC Level, Non-Blocking */
SFRX(AX5044_45_ADCQDCLEVEL0NB,			0x5F42)		/* ADC Q Path DC Level, Non-Blocking */
SFRX(AX5044_45_ADCDCCFG1NB,				0x5F43)		/* ADC DC Level Configuration ADC, Non-Blocking */
SFRX(AX5044_45_ADCDCCFG0NB,				0x5F44)		/* ADC DC Level Configuration, Non-Blocking */
SFRX(AX5044_45_ADCDBGNB,				0x5F45)		/* SAR ADC Debug Options, Non-Blocking */
SFRX(AX5044_45_ADCTESTNB,				0x5F46)		/* SAR ADC Testmode Settings SEL, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT0I1NB,			0x5F47)		/* Calibration Weight of MSB 0NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT0I0NB,			0x5F48)		/* Calibration Weight of MSB 0NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT1I1NB,			0x5F49)		/* Calibration Weight of MSB 1NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT1I0NB,			0x5F4A)		/* Calibration Weight of MSB 1NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT2I1NB,			0x5F4B)		/* Calibration Weight of MSB 2NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT2I0NB,			0x5F4C)		/* Calibration Weight of MSB 2NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT3I1NB,			0x5F4D)		/* Calibration Weight of MSB 3NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT3I0NB,			0x5F4E)		/* Calibration Weight of MSB 3NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT4I1NB,			0x5F4F)		/* Calibration Weight of MSB 4NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT4I0NB,			0x5F50)		/* Calibration Weight of MSB 4NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT5I1NB,			0x5F51)		/* Calibration Weight of MSB 5NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT5I0NB,			0x5F52)		/* Calibration Weight of MSB 5NB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT0Q1NB,			0x5F53)		/* Calibration Weight of MSB 0NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT0Q0NB,			0x5F54)		/* Calibration Weight of MSB 0NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT1Q1NB,			0x5F55)		/* Calibration Weight of MSB 1NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT1Q0NB,			0x5F56)		/* Calibration Weight of MSB 1NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT2Q1NB,			0x5F57)		/* Calibration Weight of MSB 2NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT2Q0NB,			0x5F58)		/* Calibration Weight of MSB 2NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT3Q1NB,			0x5F59)		/* Calibration Weight of MSB 3NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT3Q0NB,			0x5F5A)		/* Calibration Weight of MSB 3NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT4Q1NB,			0x5F5B)		/* Calibration Weight of MSB 4NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT4Q0NB,			0x5F5C)		/* Calibration Weight of MSB 4NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT5Q1NB,			0x5F5D)		/* Calibration Weight of MSB 5NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCWEIGHT5Q0NB,			0x5F5E)		/* Calibration Weight of MSB 5NB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCSCALINGI1NB,			0x5F5F)		/* Scaling Factor for LSB valueNB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCSCALINGI0NB,			0x5F60)		/* Scaling Factor for LSB valueNB, I-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCSCALINGQ1NB,			0x5F61)		/* Scaling Factor for LSB valueNB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCSCALINGQ0NB,			0x5F62)		/* Scaling Factor for LSB valueNB, Q-Channel ADC, Non-Blocking */
SFRX(AX5044_45_ADCOFFSETINB,			0x5F63)		/* ADC OffsetNB, I-Channel, Non-Blocking */
SFRX(AX5044_45_ADCOFFSETQNB,			0x5F64)		/* ADC OffsetNB, Q-Channel, Non-Blocking */
SFRX(AX5044_45_ADCDOUTI1NB,				0x5F65)		/* ADC OutputNB, I-Channel, Non-Blocking */
SFRX(AX5044_45_ADCDOUTI0NB,				0x5F66)		/* ADC OutputNB, I-Channel, Non-Blocking */
SFRX(AX5044_45_ADCDOUTQ1NB,				0x5F67)		/* ADC OutputNB, Q-Channel, Non-Blocking */
SFRX(AX5044_45_ADCDOUTQ0NB,				0x5F68)		/* ADC OutputNB, Q-Channel, Non-Blocking */
SFRX(AX5044_45_ADCREGOUT1NB,			0x5F69)		/* Weighted & Scaled ADC Output, Non-Blocking */
SFRX(AX5044_45_ADCREGOUT0NB,			0x5F6A)		/* Weighted & Scaled ADC Output, Non-Blocking */
SFRX(AX5044_45_ADCCLKDIV1NB,			0x5F6B)		/* if adc clk Divider, Non-Blocking */
SFRX(AX5044_45_ADCCLKDIV0NB,			0x5F6C)		/* if adc clk Divider, Non-Blocking */

/* Baseband, Non-Blocking */
SFRX(AX5044_45_DECSHIFTNB,				0x5F70)		/* Decimation Filter Gain, Non-Blocking */
SFRX(AX5044_45_RECVMISCNB,				0x5F71)		/* Receiver Miscellaneous Configuration, Non-Blocking */
SFRX(AX5044_45_BBTUNEDBGNB,				0x5F72)		/* Baseband Calibration, Non-Blocking */
SFRX(AX5044_45_BBTUNEFREQNB,			0x5F73)		/* Baseband Calibration Frequency FILT, Non-Blocking */
SFRX(AX5044_45_BBIBIASNB,				0x5F74)		/* Baseband Filter Bypass, Non-Blocking */
SFRX(AX5044_45_BBBYPASSNB,				0x5F75)		/* Baseband Filter Bypass, Non-Blocking */
SFRX(AX5044_45_BBDETECTOR1NB,			0x5F76)		/* Baseband Power Detector 1, Non-Blocking */
SFRX(AX5044_45_BBDETECTOR0NB,			0x5F77)		/* Baseband Power Detector 0, Non-Blocking */
SFRX(AX5044_45_BBOFFSFUNCNB,			0x5F78)		/* Baseband Offset Compensation Function, Non-Blocking */
SFRX(AX5044_45_BBOFFSRNGNB,				0x5F79)		/* Baseband Offset Compensation Range, Non-Blocking */

/* Modulator, Non-Blocking */
SFRX(AX5044_45_MODGAMMAA1NB,			0x5F80)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMAA0NB,			0x5F81)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMA0A1NB,			0x5F82)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMA0A0NB,			0x5F83)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMA1A1NB,			0x5F84)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMA1A0NB,			0x5F85)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMAB1NB,			0x5F86)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMAB0NB,			0x5F87)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMAC1NB,			0x5F88)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMAC0NB,			0x5F89)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMAD1NB,			0x5F8A)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMAD0NB,			0x5F8B)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMAE1NB,			0x5F8C)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODGAMMAE0NB,			0x5F8D)		/* Modulator Amplitude Predistortion Coefficient, Non-Blocking */
SFRX(AX5044_45_MODDEBUGNB,				0x5F8E)		/* Modulator Debug Flags, Non-Blocking */
SFRX(AX5044_45_MODCFGPNB,				0x5F8F)		/* Modulator Configuration P, Non-Blocking */
SFRX(AX5044_45_MODMSHAPENB,				0x5F90)		/* Modulator Mismatch Shaping Shift Register, Non-Blocking */

/* Radio Controller, Non-Blocking */
SFRX(AX5044_45_RCTRLFRMDBG1NB,			0x5FA0)		/* Radio Controller Frame Test Control Injection, Non-Blocking */
SFRX(AX5044_45_RCTRLFRMDBG0NB,			0x5FA1)		/* Radio Controller Frame Test Data Injection, Non-Blocking */
SFRX(AX5044_45_RCTRLDBGCTRLNB,			0x5FA2)		/* Radio Controller Debug Control, Non-Blocking */
SFRX(AX5044_45_RCTRLFRMRXOBS1NB,		0x5FA4)		/* Radio Controller Framing Input Observation, Non-Blocking */
SFRX(AX5044_45_RCTRLFRMRXOBS0NB,		0x5FA5)		/* Radio Controller Framing Input Observation, Non-Blocking */
SFRX(AX5044_45_RCTRLFRMTXOBS1NB,		0x5FA6)		/* Radio Controller Framing Output Observation, Non-Blocking */
SFRX(AX5044_45_RCTRLFRMTXOBS0NB,		0x5FA7)		/* Radio Controller Framing Output Observation, Non-Blocking */

/* Scan, Non-Blocking */
SFRX(AX5044_45_SCANMISCNB,				0x5FB0)		/* Scan miscellaneous, Non-Blocking */
SFRX(AX5044_45_SCANCHAIN1NB,			0x5FBF)		/* One Scan Chain, Non-Blocking */
SFRX(AX5044_45_SCANCHAIN3NB,			0x5FBE)		/* Three Scan Chains, Non-Blocking */

/* FEC, Non-Blocking */
SFRX(AX5044_45_FECMEMNB,				0x5FC0)		/* FEC Memory -> 0x0FC0 to 0x0FEF, Non-Blocking */
#endif /* !defined AX5044_45_DISABLE_NONBLOCKING */

/********** Revision & Interface Probing **********/
#define AX5044_45_REG_SILICONREVISION	0x0000		/* Silicon Revision */
#define AX5044_45_REG_SCRATCH			0x0001		/* Scratch Register */

/* Operating Mode */
#define AX5044_45_REG_PWRMODE			0x0002		/* Power Mode */

/* Voltage Regulator */
#define AX5044_45_REG_POWSTAT			0x0003		/* Power Management Status */
#define AX5044_45_REG_POWSTICKYSTAT		0x0004		/* Power Management Sticky Status */
#define AX5044_45_REG_POWIRQMASK		0x0005		/* Power Management Interrupt Mask */

/* Interrupt Control */
#define AX5044_45_REG_IRQMASK1			0x0006		/* IRQ Mask */
#define AX5044_45_REG_IRQMASK0			0x0007		/* IRQ Mask */
#define AX5044_45_REG_RADIOEVENTMASK0	0x0009		/* Radio Event Mask */
#define AX5044_45_REG_IRQINVERSION1		0x000A		/* IRQ Inversion */
#define AX5044_45_REG_IRQINVERSION0		0x000B		/* IRQ Inversion */
#define AX5044_45_REG_IRQREQUEST1		0x000C		/* IRQ Request */
#define AX5044_45_REG_IRQREQUEST0		0x000D		/* IRQ Request */
#define AX5044_45_REG_RADIOEVENTREQ0	0x000F		/* Radio Event Request */

/* Modulation & Framing */
#define AX5044_45_REG_MODULATION		0x0010		/* Modulation */
#define AX5044_45_REG_ENCODING1			0x0011		/* Encoder/Decoder Settings */
#define AX5044_45_REG_ENCODING0			0x0012		/* Encoder/Decoder Settings */
#define AX5044_45_REG_FRAMING			0x0013		/* Framing settings */
#define AX5044_45_REG_CRCCFG			0x0014		/* CRC settings */
#define AX5044_45_REG_CRCINIT3			0x0015		/* CRC Initialisation Data */
#define AX5044_45_REG_CRCINIT2			0x0016		/* CRC Initialisation Data */
#define AX5044_45_REG_CRCINIT1			0x0017		/* CRC Initialisation Data */
#define AX5044_45_REG_CRCINIT0			0x0018		/* CRC Initialisation Data */

/* Forward Error Correction */
#define AX5044_45_REG_FEC				0x0019		/* FEC (Viterbi) Configuration */
#define AX5044_45_REG_FECSYNC			0x001A		/* Interleaver Synchronisation Threshold */
#define AX5044_45_REG_FECSTATUS			0x001B		/* FEC Status */

/* Status */
#define AX5044_45_REG_RADIOSTATE		0x001C		/* Radio Controller State */
#define AX5044_45_REG_XTALSTATUS		0x001D		/* Crystal Oscillator Status */

/* Pin Configuration */
#define AX5044_45_REG_PINSTATE			0x0020		/* Pinstate */
#define AX5044_45_REG_PINFUNCSYSCLK		0x0021		/* SYSCLK Pin Function */
#define AX5044_45_REG_PINFUNCDCLK		0x0022		/* DCLK Pin Function */
#define AX5044_45_REG_PINFUNCDATA		0x0023		/* DATA Pin Function */
#define AX5044_45_REG_PINFUNCIRQ		0x0024		/* IRQ Pin Function */
#define AX5044_45_REG_PINFUNCANTSEL		0x0025		/* ANTSEL Pin Function */
#define AX5044_45_REG_PINFUNCPWRAMP		0x0026		/* PWRAMP Pin Function */
#define AX5044_45_REG_PWRAMP			0x0027		/* PWRAMP Control */

/* FIFO */
#define AX5044_45_REG_FIFOSTAT			0x0028		/* FIFO Control */
#define AX5044_45_REG_FIFODATA			0x0029		/* FIFO Data */
#define AX5044_45_REG_FIFOCOUNT1		0x002A		/* Number of Words currently in FIFO */
#define AX5044_45_REG_FIFOCOUNT0		0x002B		/* Number of Words currently in FIFO */
#define AX5044_45_REG_FIFOFREE1			0x002C		/* Number of Words that can be written to FIFO */
#define AX5044_45_REG_FIFOFREE0			0x002D		/* Number of Words that can be written to FIFO */
#define AX5044_45_REG_FIFOTHRESH0		0x002F		/* FIFO Threshold */

/* Synthesizer */
#define AX5044_45_REG_PLLLOOP			0x0030		/* PLL Loop Filter Settings */
#define AX5044_45_REG_PLLCPI			0x0031		/* PLL Charge Pump Current (Boosted) */
#define AX5044_45_REG_PLLRANGINGA1		0x0032		/* PLL Autoranging */
#define AX5044_45_REG_PLLRANGINGA0		0x0033		/* PLL Autoranging */
#define AX5044_45_REG_FREQA3			0x0034		/* Synthesizer Frequency */
#define AX5044_45_REG_FREQA2			0x0035		/* Synthesizer Frequency */
#define AX5044_45_REG_FREQA1			0x0036		/* Synthesizer Frequency */
#define AX5044_45_REG_FREQA0			0x0037		/* Synthesizer Frequency */
#define AX5044_45_REG_PLLLOOPBOOST		0x0038		/* PLL Loop Filter Settings (Boosted) */
#define AX5044_45_REG_PLLCPIBOOST		0x0039		/* PLL Charge Pump Current */
#define AX5044_45_REG_PLLRANGINGB1		0x003A		/* PLL Autoranging */
#define AX5044_45_REG_PLLRANGINGB0		0x003B		/* PLL Autoranging */
#define AX5044_45_REG_FREQB3			0x003C		/* Synthesizer Frequency */
#define AX5044_45_REG_FREQB2			0x003D		/* Synthesizer Frequency */
#define AX5044_45_REG_FREQB1			0x003E		/* Synthesizer Frequency */
#define AX5044_45_REG_FREQB0			0x003F		/* Synthesizer Frequency */
#define AX5044_45_REG_PLLVCODIV			0x0040		/* PLL Divider Settings */

/* Signal Strength */
#define AX5044_45_REG_RSSI				0x0041		/* Received Signal Strength Indicator */
#define AX5044_45_REG_BGNDRSSI			0x0042		/* Background RSSI */
#define AX5044_45_REG_DIVERSITY			0x0043		/* Antenna Diversity Configuration */
#define AX5044_45_REG_AGCCOUNTER		0x0044		/* AGC Current Value */

/* Receiver Tracking */
#define AX5044_45_REG_TRKDATARATE2		0x0045		/* Datarate Tracking */
#define AX5044_45_REG_TRKDATARATE1		0x0046		/* Datarate Tracking */
#define AX5044_45_REG_TRKDATARATE0		0x0047		/* Datarate Tracking */
#define AX5044_45_REG_TRKAMPL1			0x0048		/* Amplitude Tracking */
#define AX5044_45_REG_TRKAMPL0			0x0049		/* Amplitude Tracking */
#define AX5044_45_REG_TRKPHASE1			0x004A		/* Phase Tracking */
#define AX5044_45_REG_TRKPHASE0			0x004B		/* Phase Tracking */
#define AX5044_45_REG_TRKRFFREQ2		0x004D		/* RF Frequency Tracking */
#define AX5044_45_REG_TRKRFFREQ1		0x004E		/* RF Frequency Tracking */
#define AX5044_45_REG_TRKRFFREQ0		0x004F		/* RF Frequency Tracking */
#define AX5044_45_REG_TRKFREQ1			0x0050		/* Frequency Tracking */
#define AX5044_45_REG_TRKFREQ0			0x0051		/* Frequency Tracking */
#define AX5044_45_REG_TRKFSKDEMOD1		0x0052		/* FSK Demodulator Tracking */
#define AX5044_45_REG_TRKFSKDEMOD0		0x0053		/* FSK Demodulator Tracking */
#define AX5044_45_REG_TRKAFSKDEMOD1		0x0054		/* AFSK Demodulator Tracking */
#define AX5044_45_REG_TRKAFSKDEMOD0		0x0055		/* AFSK Demodulator Tracking */

/* Timer */
#define AX5044_45_REG_TIMER2			0x0059		/* 1MHz Timer */
#define AX5044_45_REG_TIMER1			0x005A		/* 1MHz Timer */
#define AX5044_45_REG_TIMER0			0x005B		/* 1MHz Timer */
#define AX5044_45_REG_TIMERCLK			0x005C		/* Internal Timer Clock Setting */

/* Time Stamp */
#define AX5044_45_REG_RCTRLTIMESTAMP2	0x0060		/* Radio Controller Timestamp Count */
#define AX5044_45_REG_RCTRLTIMESTAMP1	0x0061		/* Radio Controller Timestamp Count */
#define AX5044_45_REG_RCTRLTIMESTAMP0	0x0062		/* Radio Controller Timestamp Count */
#define AX5044_45_REG_RCTRLTIMETXENA	0x0064		/* Radio Controller Timestamp Enable */

/* Wakeup Timer */
#define AX5044_45_REG_WAKEUPTIMER1		0x0068		/* Wakeup Timer */
#define AX5044_45_REG_WAKEUPTIMER0		0x0069		/* Wakeup Timer */
#define AX5044_45_REG_WAKEUP1			0x006A		/* Wakeup Time */
#define AX5044_45_REG_WAKEUP0			0x006B		/* Wakeup Time */
#define AX5044_45_REG_WAKEUPFREQ1		0x006C		/* Wakeup Frequency */
#define AX5044_45_REG_WAKEUPFREQ0		0x006D		/* Wakeup Frequency */
#define AX5044_45_REG_WAKEUPXOEARLY		0x006E		/* Wakeup Crystal Oscillator Early */

/* Physical Layer Parameters*/
/* Receiver Parameters */
#define AX5044_45_REG_IFFREQ1			0xF100		/* 2nd LO / IF Frequency */
#define AX5044_45_REG_IFFREQ0			0xF101		/* 2nd LO / IF Frequency */
#define AX5044_45_REG_DECIMATION1		0xF102		/* Decimation Factor */
#define AX5044_45_REG_DECIMATION0		0xF103		/* Decimation Factor */
#define AX5044_45_REG_RXDATARATE2		0xF104		/* Receiver Datarate */
#define AX5044_45_REG_RXDATARATE1		0xF105		/* Receiver Datarate */
#define AX5044_45_REG_RXDATARATE0		0xF106		/* Receiver Datarate */
#define AX5044_45_REG_MAXDROFFSET2		0xF107		/* Maximum Receiver Datarate Offset */
#define AX5044_45_REG_MAXDROFFSET1		0xF108		/* Maximum Receiver Datarate Offset */
#define AX5044_45_REG_MAXDROFFSET0		0xF109		/* Maximum Receiver Datarate Offset */
#define AX5044_45_REG_MAXRFOFFSET2		0xF10A		/* Maximum Receiver RF Offset */
#define AX5044_45_REG_MAXRFOFFSET1		0xF10B		/* Maximum Receiver RF Offset */
#define AX5044_45_REG_MAXRFOFFSET0		0xF10C		/* Maximum Receiver RF Offset */
#define AX5044_45_REG_FSKDMAX1			0xF10D		/* Four FSK Rx Deviation */
#define AX5044_45_REG_FSKDMAX0			0xF10E		/* Four FSK Rx Deviation */
#define AX5044_45_REG_FSKDMIN1			0xF10F		/* Four FSK Rx Deviation */
#define AX5044_45_REG_FSKDMIN0			0xF110		/* Four FSK Rx Deviation */
#define AX5044_45_REG_AFSKSPACE1		0xF111		/* AFSK Space (0) Frequency */
#define AX5044_45_REG_AFSKSPACE0		0xF112		/* AFSK Space (0) Frequency */
#define AX5044_45_REG_AFSKMARK1			0xF113		/* AFSK Mark (1) Frequency */
#define AX5044_45_REG_AFSKMARK0			0xF114		/* AFSK Mark (1) Frequency */
#define AX5044_45_REG_AFSKCTRL			0xF115		/* AFSK Control */
#define AX5044_45_REG_AMPLFILTER		0xF116		/* Amplitude Filter */
#define AX5044_45_REG_RFZIGZAGAMPL		0xF117		/* RF Zigzag Scanner Amplitude Exponent and Man-tissa */
#define AX5044_45_REG_RFZIGZAGFREQ		0xF118		/* RF Zigzag Scanner Frequency */
#define AX5044_45_REG_RFFREQUENCYLEAK	0xF119		/* RF Frequency Recovery Loop Leakiness */
#define AX5044_45_REG_FREQUENCYLEAK		0xF11A		/* Baseband Frequency Recovery Loop Leakiness */
#define AX5044_45_REG_RXPARAMSETS		0xF11B		/* Receiver Parameter Set Indirection */
#define AX5044_45_REG_RXPARAMCURSET		0xF11C		/* Receiver Parameter Current Set */
#define AX5044_45_REG_RSSIIRQTHRESH		0xF11D		/* RSSI Interrupt Threshold */
#define AX5044_45_REG_RSSIIRQDIR		0xF11E		/* RSSI Interrupt Threshold Direction */

/* Receiver Parameter Set 0 */
#define AX5044_45_REG_AGCTARGET0		0xF120		/* AGC Target */
#define AX5044_45_REG_AGCINCREASE0		0xF121		/* AGC Gain Increase Settings */
#define AX5044_45_REG_AGCREDUCE0		0xF122		/* AGC Gain Reduce Settings */
#define AX5044_45_REG_AGCAHYST0			0xF123		/* AGC Digital Threshold Range */
#define AX5044_45_REG_TIMEGAIN0			0xF124		/* Timing Gain */
#define AX5044_45_REG_DRGAIN0			0xF125		/* Data Rate Gain */
#define AX5044_45_REG_PHASEGAIN0		0xF126		/* Filter Index, Phase Gain */
#define AX5044_45_REG_FREQUENCYGAINA0	0xF127		/* Frequency Gain A */
#define AX5044_45_REG_FREQUENCYGAINB0	0xF128		/* Frequency Gain B */
#define AX5044_45_REG_FREQUENCYGAINC0	0xF129		/* Frequency Gain C */
#define AX5044_45_REG_FREQUENCYGAIND0	0xF12A		/* Frequency Gain D */
#define AX5044_45_REG_AMPLITUDEGAIN0	0xF12B		/* Amplitude Gain */
#define AX5044_45_REG_FREQDEV10			0xF12C		/* Receiver Frequency Deviation */
#define AX5044_45_REG_FREQDEV00			0xF12D		/* Receiver Frequency Deviation */
#define AX5044_45_REG_FOURFSK0			0xF12E		/* Four FSK Control */
#define AX5044_45_REG_BBOFFSRES0		0xF12F		/* Baseband Offset Compensation Resistors */

/* Receiver Parameter Set 1 */
#define AX5044_45_REG_AGCTARGET1		0xF130		/* AGC Target */
#define AX5044_45_REG_AGCINCREASE1		0xF131		/* AGC Gain Increase Settings */
#define AX5044_45_REG_AGCREDUCE1		0xF132		/* AGC Gain Reduce Settings */
#define AX5044_45_REG_AGCAHYST1			0xF133		/* AGC Digital Threshold Range */
#define AX5044_45_REG_TIMEGAIN1			0xF134		/* Timing Gain */
#define AX5044_45_REG_DRGAIN1			0xF135		/* Data Rate Gain */
#define AX5044_45_REG_PHASEGAIN1		0xF136		/* Filter Index, Phase Gain */
#define AX5044_45_REG_FREQUENCYGAINA1	0xF137		/* Frequency Gain A */
#define AX5044_45_REG_FREQUENCYGAINB1	0xF138		/* Frequency Gain B */
#define AX5044_45_REG_FREQUENCYGAINC1	0xF139		/* Frequency Gain C */
#define AX5044_45_REG_FREQUENCYGAIND1	0xF13A		/* Frequency Gain D */
#define AX5044_45_REG_AMPLITUDEGAIN1	0xF13B		/* Amplitude Gain */
#define AX5044_45_REG_FREQDEV11			0xF13C		/* Receiver Frequency Deviation */
#define AX5044_45_REG_FREQDEV01			0xF13D		/* Receiver Frequency Deviation */
#define AX5044_45_REG_FOURFSK1			0xF13E		/* Four FSK Control */
#define AX5044_45_REG_BBOFFSRES1		0xF13F		/* Baseband Offset Compensation Resistors */

/* Receiver Parameter Set 2 */
#define AX5044_45_REG_AGCTARGET2		0xF140		/* AGC Target */
#define AX5044_45_REG_AGCINCREASE2		0xF141		/* AGC Gain Increase Settings */
#define AX5044_45_REG_AGCREDUCE2		0xF142		/* AGC Gain Reduce Settings */
#define AX5044_45_REG_AGCAHYST2			0xF143		/* AGC Digital Threshold Range */
#define AX5044_45_REG_TIMEGAIN2			0xF144		/* Timing Gain */
#define AX5044_45_REG_DRGAIN2			0xF145		/* Data Rate Gain */
#define AX5044_45_REG_PHASEGAIN2		0xF146		/* Filter Index, Phase Gain */
#define AX5044_45_REG_FREQUENCYGAINA2	0xF147		/* Frequency Gain A */
#define AX5044_45_REG_FREQUENCYGAINB2	0xF148		/* Frequency Gain B */
#define AX5044_45_REG_FREQUENCYGAINC2	0xF149		/* Frequency Gain C */
#define AX5044_45_REG_FREQUENCYGAIND2	0xF14A		/* Frequency Gain D */
#define AX5044_45_REG_AMPLITUDEGAIN2	0xF14B		/* Amplitude Gain */
#define AX5044_45_REG_FREQDEV12			0xF14C		/* Receiver Frequency Deviation */
#define AX5044_45_REG_FREQDEV02			0xF14D		/* Receiver Frequency Deviation */
#define AX5044_45_REG_FOURFSK2			0xF14E		/* Four FSK Control */
#define AX5044_45_REG_BBOFFSRES2		0xF14F		/* Baseband Offset Compensation Resistors */

/* Receiver Parameter Set 3 */
#define AX5044_45_REG_AGCTARGET3		0xF150		/* AGC Target */
#define AX5044_45_REG_AGCINCREASE3		0xF151		/* AGC Gain Increase Settings */
#define AX5044_45_REG_AGCREDUCE3		0xF152		/* AGC Gain Reduce Settings */
#define AX5044_45_REG_AGCAHYST3			0xF153		/* AGC Digital Threshold Range */
#define AX5044_45_REG_TIMEGAIN3			0xF154		/* Timing Gain */
#define AX5044_45_REG_DRGAIN3			0xF155		/* Data Rate Gain */
#define AX5044_45_REG_PHASEGAIN3		0xF156		/* Filter Index, Phase Gain */
#define AX5044_45_REG_FREQUENCYGAINA3	0xF157		/* Frequency Gain A */
#define AX5044_45_REG_FREQUENCYGAINB3	0xF158		/* Frequency Gain B */
#define AX5044_45_REG_FREQUENCYGAINC3	0xF159		/* Frequency Gain C */
#define AX5044_45_REG_FREQUENCYGAIND3	0xF15A		/* Frequency Gain D */
#define AX5044_45_REG_AMPLITUDEGAIN3	0xF15B		/* Amplitude Gain */
#define AX5044_45_REG_FREQDEV13			0xF15C		/* Receiver Frequency Deviation */
#define AX5044_45_REG_FREQDEV03			0xF15D		/* Receiver Frequency Deviation */
#define AX5044_45_REG_FOURFSK3			0xF15E		/* Four FSK Control */
#define AX5044_45_REG_BBOFFSRES3		0xF15F		/* Baseband Offset Compensation Resistors */

/* Transmitter Parameters */
#define AX5044_45_REG_MODCFGF			0xF160		/* Modulator Configuration F */
#define AX5044_45_REG_FSKDEV2			0xF161		/* FSK Frequency Deviation */
#define AX5044_45_REG_FSKDEV1			0xF162		/* FSK Frequency Deviation */
#define AX5044_45_REG_FSKDEV0			0xF163		/* FSK Frequency Deviation */
#define AX5044_45_REG_TXRATE3			0xF164		/* Transmitter Bitrate */
#define AX5044_45_REG_TXRATE2			0xF165		/* Transmitter Bitrate */
#define AX5044_45_REG_TXRATE1			0xF166		/* Transmitter Bitrate */
#define AX5044_45_REG_TXRATE0			0xF167		/* Transmitter Bitrate */
#define AX5044_45_REG_TXPWRCOEFFA1		0xF168		/* Transmitter Predistortion Coefficient A */
#define AX5044_45_REG_TXPWRCOEFFA0		0xF169		/* Transmitter Predistortion Coefficient A */
#define AX5044_45_REG_TXPWRCOEFFB1		0xF16A		/* Transmitter Predistortion Coefficient B */
#define AX5044_45_REG_TXPWRCOEFFB0		0xF16B		/* Transmitter Predistortion Coefficient B */
#define AX5044_45_REG_TXPWRCOEFFC1		0xF16C		/* Transmitter Predistortion Coefficient C */
#define AX5044_45_REG_TXPWRCOEFFC0		0xF16D		/* Transmitter Predistortion Coefficient C */
#define AX5044_45_REG_TXPWRCOEFFD1		0xF16E		/* Transmitter Predistortion Coefficient D */
#define AX5044_45_REG_TXPWRCOEFFD0		0xF16F		/* Transmitter Predistortion Coefficient D */
#define AX5044_45_REG_TXPWRCOEFFE1		0xF170		/* Transmitter Predistortion Coefficient E */
#define AX5044_45_REG_TXPWRCOEFFE0		0xF171		/* Transmitter Predistortion Coefficient E */
#define AX5044_45_REG_MODCFGA			0xF172		/* Modulator Configuration A */
#define AX5044_45_REG_TXCLKDIV			0xF173		/* Transmitter Clock Divider */
#define AX5044_45_REG_TXAMPLSHAPE		0xF174		/* Transmitter Amplitude Shaping */
#define AX5044_45_REG_TXDCCREG			0xF175		/* Transmitter Trim Registers */
#define AX5044_45_REG_TXMISC			0xF176		/* Transmitter Miscellaneous Registers */

/* PLL Parameters */
#define AX5044_45_REG_PLLVCOI			0xF180		/* VCO Current */
#define AX5044_45_REG_PLLLOCKDET		0xF181		/* PLL Lock Detect Delay */
#define AX5044_45_REG_PLLRNGCFG			0xF182		/* PLL Ranging Configuration */
#define AX5044_45_REG_PLLDITHER			0xF183		/* PLL Dither */
#define AX5044_45_REG_PLLSTATMASK		0xF184		/* PLL Staus Interrupt Mask */
#define AX5044_45_REG_PLLCOMP			0xF185		/* PLL Ranging ADC Control & Read-out */

/* Crystal Oscillator */
#define AX5044_45_REG_XTALCAP			0xF18A		/* Crystal Oscillator Load Capacitance Configuration */
#define AX5044_45_REG_XTALOSC			0xF18B		/* Crystal Oscillator Configuration */
#define AX5044_45_REG_XTALAMPL			0xF18C		/* Crystal Oscillator Critical Amplitude */

/* Baseband */
#define AX5044_45_REG_BBTUNE			0xF190		/* Baseband Tuning */
#define AX5044_45_REG_BBOFFSCAP			0xF191		/* Baseband Offset Compensation Capacitors */

/* ADC */
#define AX5044_45_REG_ADCCLK			0xF193		/* SAR ADC Clock Settings */
#define AX5044_45_REG_ADCMISC			0xF194		/* SAR ADC Miscellaneous Settings */

/* MAC Layer Parameters */
/* Packet Format */
#define AX5044_45_REG_PKTADDRCFG		0xF200		/* Packet Address Config */
#define AX5044_45_REG_PKTLENPOS			0xF201		/* Packet Length Byte Position */
#define AX5044_45_REG_PKTLENBITS		0xF202		/* Packet Length Significant Bits */
#define AX5044_45_REG_PKTLENOFFSET1		0xF203		/* Packet Length Offset 1 */
#define AX5044_45_REG_PKTLENOFFSET0		0xF204		/* Packet Length Offset 0 */
#define AX5044_45_REG_PKTMAXLEN1		0xF205		/* Packet Maximum Length 1 */
#define AX5044_45_REG_PKTMAXLEN0		0xF206		/* Packet Maximum Length 0 */
#define AX5044_45_REG_PKTADDRA4			0xF207		/* Packet Address A 4 */
#define AX5044_45_REG_PKTADDRA3			0xF208		/* Packet Address A 3 */
#define AX5044_45_REG_PKTADDRA2			0xF209		/* Packet Address A 2 */
#define AX5044_45_REG_PKTADDRA1			0xF20A		/* Packet Address A 1 */
#define AX5044_45_REG_PKTADDRA0			0xF20B		/* Packet Address A 0 */
#define AX5044_45_REG_PKTADDRB4			0xF20C		/* Packet Address B 4 */
#define AX5044_45_REG_PKTADDRB3			0xF20D		/* Packet Address B 3 */
#define AX5044_45_REG_PKTADDRB2			0xF20E		/* Packet Address B 2 */
#define AX5044_45_REG_PKTADDRB1			0xF20F		/* Packet Address B 1 */
#define AX5044_45_REG_PKTADDRB0			0xF210		/* Packet Address B 0 */
#define AX5044_45_REG_PKTADDRENA		0xF211		/* Packet Address Enable */
#define AX5044_45_REG_PKTADDRMASK4		0xF212		/* Packet Address Mask 4 */
#define AX5044_45_REG_PKTADDRMASK3		0xF213		/* Packet Address Mask 3 */
#define AX5044_45_REG_PKTADDRMASK2		0xF214		/* Packet Address Mask 2 */
#define AX5044_45_REG_PKTADDRMASK1		0xF215		/* Packet Address Mask 1 */
#define AX5044_45_REG_PKTADDRMASK0		0xF216		/* Packet Address Mask 0 */

/* Pattern Match */
#define AX5044_45_REG_MATCH0APAT3		0xF220		/* Pattern Match Unit 0a, Pattern */
#define AX5044_45_REG_MATCH0APAT2		0xF221		/* Pattern Match Unit 0a, Pattern */
#define AX5044_45_REG_MATCH0APAT1		0xF222		/* Pattern Match Unit 0a, Pattern */
#define AX5044_45_REG_MATCH0APAT0		0xF223		/* Pattern Match Unit 0a, Pattern */
#define AX5044_45_REG_MATCH0ALEN		0xF224		/* Pattern Match Unit 0a, Pattern Length */
#define AX5044_45_REG_MATCH0AMIN		0xF225		/* Pattern Match Unit 0a, Minimum Match */
#define AX5044_45_REG_MATCH0AMAX		0xF226		/* Pattern Match Unit 0a, Maximum Match */
#define AX5044_45_REG_MATCH0BPAT3		0xF227		/* Pattern Match Unit 0b, Pattern */
#define AX5044_45_REG_MATCH0BPAT2		0xF228		/* Pattern Match Unit 0b, Pattern */
#define AX5044_45_REG_MATCH0BPAT1		0xF229		/* Pattern Match Unit 0b, Pattern */
#define AX5044_45_REG_MATCH0BPAT0		0xF22A		/* Pattern Match Unit 0b, Pattern */
#define AX5044_45_REG_MATCH0BLEN		0xF22B		/* Pattern Match Unit 0b, Pattern Length */
#define AX5044_45_REG_MATCH0BMIN		0xF22C		/* Pattern Match Unit 0b, Minimum Match */
#define AX5044_45_REG_MATCH0BMAX		0xF22D		/* Pattern Match Unit 0b, Maximum Match */
#define AX5044_45_REG_MATCH1PAT1		0xF230		/* Pattern Match Unit 1, Pattern */
#define AX5044_45_REG_MATCH1PAT0		0xF231		/* Pattern Match Unit 1, Pattern */
#define AX5044_45_REG_MATCH1LEN			0xF232		/* Pattern Match Unit 1, Pattern Length */
#define AX5044_45_REG_MATCH1MIN			0xF233		/* Pattern Match Unit 1, Minimum Match */
#define AX5044_45_REG_MATCH1MAX			0xF234		/* Pattern Match Unit 1, Maximum Match */

/* Packet Controller */
#define AX5044_45_REG_TMGTXBOOST		0xF240		/* Transmit PLL Boost Time */
#define AX5044_45_REG_TMGTXSETTLE		0xF241		/* Transmit PLL (post Boost) Settling Time */
#define AX5044_45_REG_TMGRXBOOST		0xF242		/* Receive PLL Boost Time */
#define AX5044_45_REG_TMGRXSETTLE		0xF243		/* Receive PLL (post Boost) Settling Time */
#define AX5044_45_REG_TMGRXOFFSACQ0		0xF244		/* Receive Baseband DC Offset Acquisition First Stage Time */
#define AX5044_45_REG_TMGRXOFFSACQ1		0xF245		/* Receive Baseband DC Offset Acquisition Second Stage Time */
#define AX5044_45_REG_TMGRXOFFSACQ2		0xF246		/* Receive Baseband DC Offset Acquisition After Di-versity Time */
#define AX5044_45_REG_TMGRXCOARSEAGC	0xF247		/* Receive Coarse AGC Time */
#define AX5044_45_REG_TMGRXAGC			0xF248		/* Receiver AGC Settling Time */
#define AX5044_45_REG_TMGRXRSSI			0xF249		/* Receiver RSSI Settling Time */
#define AX5044_45_REG_TMGRXPREAMBLE1	0xF24A		/* Receiver Preamble 1 Timeout */
#define AX5044_45_REG_TMGRXPREAMBLE2	0xF24B		/* Receiver Preamble 2 Timeout */
#define AX5044_45_REG_TMGRXPREAMBLE3	0xF24C		/* Receiver Preamble 3 Timeout */
#define AX5044_45_REG_RSSIREFERENCE		0xF250		/* RSSI Offset */
#define AX5044_45_REG_RSSIABSTHR		0xF251		/* RSSI Absolute Threshold */
#define AX5044_45_REG_BGNDRSSIGAIN		0xF252		/* Background RSSI Averaging Time Constant */
#define AX5044_45_REG_BGNDRSSITHR		0xF253		/* Background RSSI Relative Threshold */
#define AX5044_45_REG_PKTCHUNKSIZE		0xF254		/* Packet Chunk Size */
#define AX5044_45_REG_PKTMISCFLAGS		0xF255		/* Packet Controller Miscellaneous Flags */
#define AX5044_45_REG_PKTSTOREFLAGS		0xF256		/* Packet Controller Store Flags */
#define AX5044_45_REG_PKTACCEPTFLAGS	0xF257		/* Packet Controller Accept Flags */

/* Special Functions */
/* General Purpose ADC */
#define AX5044_45_REG_GPADCCTRL			0xF300		/* General Purpose ADC Control */
#define AX5044_45_REG_GPADCPERIOD		0xF301		/* GPADC Sampling Period */
#define AX5044_45_REG_GPADCVALUE1		0xF308		/* GPADC Value */
#define AX5044_45_REG_GPADCVALUE0		0xF309		/* GPADC Value */

/* Low Power Oscillator Calibration */
#define AX5044_45_REG_LPOSCCONFIG		0xF310		/* Low Power Oscillator Configuration */
#define AX5044_45_REG_LPOSCSTATUS		0xF311		/* Low Power Oscillator Status */
#define AX5044_45_REG_LPOSCCLKMUX		0xF312		/* LPOSC Reference Frequency Divider */
#define AX5044_45_REG_LPOSCKFILT1		0xF313		/* Low Power Oscillator Calibration Filter Constant */
#define AX5044_45_REG_LPOSCKFILT0		0xF314		/* Low Power Oscillator Calibration Filter Constant */
#define AX5044_45_REG_LPOSCREF1			0xF315		/* Low Power Oscillator Calibration Reference */
#define AX5044_45_REG_LPOSCREF0			0xF316		/* Low Power Oscillator Calibration Reference */
#define AX5044_45_REG_LPOSCFREQ1		0xF317		/* Low Power Oscillator Calibration Frequency */
#define AX5044_45_REG_LPOSCFREQ0		0xF318		/* Low Power Oscillator Calibration Frequency */
#define AX5044_45_REG_LPOSCPER1			0xF319		/* Low Power Oscillator Calibration Period */
#define AX5044_45_REG_LPOSCPER0			0xF31A		/* Low Power Oscillator Calibration Period */

/* DAC */
#define AX5044_45_REG_DACVALUE1			0xF330		/* DAC Value */
#define AX5044_45_REG_DACVALUE0			0xF331		/* DAC Value */
#define AX5044_45_REG_DACCONFIG			0xF332		/* DAC Configuration */

/* Debug Registers */
#define AX5044_45_REG_0xF00				0xFF00
#define AX5044_45_REG_REF				0XFF0D
#define AX5044_45_REG_0xF17            	0xFF17
#define AX5044_45_REG_0xF18            	0xFF18
#define AX5044_45_REG_0xF19            	0xFF19
#define AX5044_45_REG_0xF20            	0xFF20
#define AX5044_45_REG_0xF29            	0xFF29
#define AX5044_45_REG_0xF2A            	0xFF2A
#define AX5044_45_REG_0xF2B            	0xFF2B
#define AX5044_45_REG_0xF2C            	0xFF2C
#define AX5044_45_REG_0xF2E            	0xFF2E
#define AX5044_45_REG_0xF32             0xFF32
#define AX5044_45_REG_0xF33             0xFF33	
#define AX5044_45_REG_0xF3F            	0xFF3F
#define AX5044_45_REG_0xF40            	0xFF40
#define AX5044_45_REG_0xF41            	0xFF41
#define AX5044_45_REG_0xF42            	0xFF42
#define AX5044_45_REG_0xF43            	0xFF43
#define AX5044_45_REG_0xF44            	0xFF44
#define AX5044_45_REG_0xF45            	0xFF45
#define AX5044_45_REG_0xF74            	0xFF74
#define AX5044_45_REG_0xFA0            	0xFFA0
#define AX5044_45_REG_MODCFGP          	0xFF8F /* Modulator Configuration P */

/**************** Standard Reg values ******************/
/* #define AX5044_45_PWRSTATE_POWERDOWN             	0x00 defined in radio template */
/* #define AX5044_45_PWRSTATE_DEEPSLEEP             	0x01 defined in radio template */
#define AX5044_45_PWRSTATE_VREGON                	0x04
#define AX5044_45_PWRSTATE_XTALOSCON             	0x05
#define AX5044_45_PWRSTATE_XTALVREGON            	0x06
#define AX5044_45_PWRSTATE_FIFOON                	0x07
#define AX5044_45_PWRSTATE_SYNTHRX               	0x08
#define AX5044_45_PWRSTATE_FULLRX                	0x09
#define AX5044_45_PWRSTATE_RXWAKEONRADIO         	0x0B
#define AX5044_45_PWRSTATE_SYNTHTX               	0x0C
#define AX5044_45_PWRSTATE_FULLTX                	0x0D

#define AX5044_45_MODULATION_ASK                 	0x00
#define AX5044_45_MODULATION_ASKCOHERENT         	0x01
#define AX5044_45_MODULATION_AM                  	0x02
#define AX5044_45_MODULATION_PSK                 	0x04
#define AX5044_45_MODULATION_OQPSK               	0x06
#define AX5044_45_MODULATION_MSK                 	0x07
#define AX5044_45_MODULATION_FSK                 	0x08
#define AX5044_45_MODULATION_4FSK                	0x09
#define AX5044_45_MODULATION_AFSK                	0x0A
#define AX5044_45_MODULATION_FM                  	0x0B
/* Helper to distinguish between PA and PLL controlled PSK */
#define AX5044_45_MODULATION_PSKPLL					MOD_PSKPLL

#define AX5044_45_AMPLITUDESHAPING_HARD        		0x00
#define AX5044_45_AMPLITUDESHAPING_RAISEDCOSINE   	0x01

#define AX5044_45_FREQUENCYSHAPING_HARD				0x00
#define AX5044_45_FREQUENCYSHAPING_GAUSSBT03      	0x02
#define AX5044_45_FREQUENCYSHAPING_GAUSSBT05      	0x03
#define AX5044_45_FREQUENCYSHAPING_GAUSSRECTBT03  	0x04
#define AX5044_45_FREQUENCYSHAPING_GAUSSRECTBT05  	0x05

#define AX5044_45_FRAMINGMODE_RAW                 	0x00
#define AX5044_45_FRAMINGMODE_RAWSOFT             	0x01
#define AX5044_45_FRAMINGMODE_HDLC                	0x02
#define AX5044_45_FRAMINGMODE_RAWPATTERNMATCH     	0x03
#define AX5044_45_FRAMINGMODE_WMBUS               	0x04
#define AX5044_45_FRAMINGMODE_WMBUS6              	0x05
#define AX5044_45_FRAMINGMODE_ZIGBEE900           	0x06
#define AX5044_45_FRAMINGMODE_ZIGBEE2G4           	0x07

#define AX5044_45_CRCMODE_OFF                     	0x00
#define AX5044_45_CRCMODE_CCITT                   	0x01
#define AX5044_45_CRCMODE_CRC16                   	0x02
#define AX5044_45_CRCMODE_DNP                     	0x03
#define AX5044_45_CRCMODE_CRC32                   	0x06

#define AX5044_45_LOOPFILTER_EXTERNAL             	0x00
#define AX5044_45_LOOPFILTER_INTERNAL             	0x01
#define AX5044_45_LOOPFILTER_INTERNAL_X2          	0x02
#define AX5044_45_LOOPFILTER_INTERNAL_X5          	0x03

#define AX5044_45_FIFOCMD_CLEARFIFODATA           	0x01
#define AX5044_45_FIFOCMD_CLEARFIFOERROR          	0x02
#define AX5044_45_FIFOCMD_CLEARFIFO               	0x03
#define AX5044_45_FIFOCMD_COMMIT                  	0x04
#define AX5044_45_FIFOCMD_ROLLBACK                	0x05

#define AX5044_45_FRAMINGTXCMD_DATA               	0x00
#define AX5044_45_FRAMINGTXCMD_RAWDATA            	0x01
#define AX5044_45_FRAMINGTXCMD_RAWUNENCDATA       	0x02
#define AX5044_45_FRAMINGTXCMD_DATAERROR          	0x03
#define AX5044_45_FRAMINGTXCMD_CRC                	0x04
#define AX5044_45_FRAMINGTXCMD_DELIMITER          	0x05
#define AX5044_45_FRAMINGTXCMD_ABORT              	0x06
#define AX5044_45_FRAMINGTXCMD_DATASYNC           	0x07

#define AX5044_45_PACKETCMD_NOP                   	0x00
#define AX5044_45_PACKETCMD_DATA                  	0xE1
#define AX5044_45_PACKETCMD_REPEATDATA            	0x62
#define AX5044_45_PACKETCMD_RSSI                  	0x31
#define AX5044_45_PACKETCMD_FREQOFFS              	0x52
#define AX5044_45_PACKETCMD_TIMER                 	0x70
#define AX5044_45_PACKETCMD_RFFREQOFFS            	0x73
#define AX5044_45_PACKETCMD_DATARATE              	0x74
#define AX5044_45_PACKETCMD_ANTRSSI2              	0x55
#define AX5044_45_PACKETCMD_ANTRSSI3              	0x75
#define AX5044_45_PACKETCMD_TXCTRL                	0x3C
#define AX5044_45_PACKETCMD_TXPWR                 	0xFD

#define AX5044_45_DSPIFSYNCSOURCE_OFF             	0x00
#define AX5044_45_DSPIFSYNCSOURCE_BITCLK          	0x01
#define AX5044_45_DSPIFSYNCSOURCE_SAMPLECLK       	0x02
#define AX5044_45_DSPIFSYNCSOURCE_BASEBANDCLK     	0x03

#define AX5044_45_DSPIFDATASOURCE_PWRAMP          	0x00
#define AX5044_45_DSPIFDATASOURCE_ANTSEL          	0x01
#define AX5044_45_DSPIFDATASOURCE_DATA            	0x02
#define AX5044_45_DSPIFDATASOURCE_INVALID         	0x03

#define AX5044_45_RADIOSTATE_IDLE                 	0x00
#define AX5044_45_RADIOSTATE_POWERDOWN            	0x01
#define AX5044_45_RADIOSTATE_TXPLLSETTLE          	0x04
#define AX5044_45_RADIOSTATE_TX                   	0x06
#define AX5044_45_RADIOSTATE_TXTAIL               	0x07
#define AX5044_45_RADIOSTATE_RXPLLSETTLE          	0x08
#define AX5044_45_RADIOSTATE_RXANTENNASELECT      	0x09
#define AX5044_45_RADIOSTATE_RXPREAMBLE1          	0x0C
#define AX5044_45_RADIOSTATE_RXPREAMBLE2          	0x0D
#define AX5044_45_RADIOSTATE_RXPREAMBLE3          	0x0E
#define AX5044_45_RADIOSTATE_RX                   	0x0F

#define AX5044_45_SCRMODE_MULTIPLICATIVE          	0x00
#define AX5044_45_SCRMODE_ADDITIVE                	0x01

#define AX5044_45_SCRPOLY_OFF                     	0x00
#define AX5044_45_SCRPOLY_PN9                     	0x01
#define AX5044_45_SCRPOLY_PN15                    	0x02
#define AX5044_45_SCRPOLY_PN17                    	0x03

#define AX5044_45_IRQNR_FIFONOTEMPTY              	0x00
#define AX5044_45_IRQNR_FIFONOTFULL               	0x01
#define AX5044_45_IRQNR_FIFOTHRCNT                	0x02
#define AX5044_45_IRQNR_FIFOTHRFREE               	0x03
#define AX5044_45_IRQNR_FIFOERROR                 	0x04
#define AX5044_45_IRQNR_PLLUNLOCK                 	0x05
#define AX5044_45_IRQNR_RADIOCTRL                 	0x06
#define AX5044_45_IRQNR_POWER                     	0x07
#define AX5044_45_IRQNR_XTALREADY                 	0x08
#define AX5044_45_IRQNR_WAKEUPTIMER               	0x09
#define AX5044_45_IRQNR_LPOSC                     	0x0A
#define AX5044_45_IRQNR_GPADC                     	0x0B
#define AX5044_45_IRQNR_PLLRNGDONE                	0x0C
#define AX5044_45_IRQNR_DSPMODE                   	0x0D
#define AX5044_45_IRQNR_RSSITHRESH                	0x0E
#define AX5044_45_IRQNR_MAXINDEX                  	AX5044_45_IRQNR_RSSITHRESH

#define AX5044_45_RADIOEVENTNR_DONE               	0x00
#define AX5044_45_RADIOEVENTNR_SETTLED            	0x01
#define AX5044_45_RADIOEVENTNR_RADIOSTATE_CHANGED 	0x02
#define AX5044_45_RADIOEVENTNR_RXPARAMSET_CHANGED 	0x03
#define AX5044_45_RADIOEVENTNR_FRAMECLK           	0x04
#define AX5044_45_RADIOEVENTNR_MAXINDEX           	AX5044_45_RADIOEVENTNR_FRAMECLK

#define AX5044_45_AGCCMD_NOP                      	0x00
#define AX5044_45_AGCCMD_RESTORE                  	0x01
#define AX5044_45_AGCCMD_RESET                    	0x02
#define AX5044_45_AGCCMD_SAVE_RESET               	0x03

#define AX5044_45_DACINPUT_DACVALUE               	0x00
#define AX5044_45_DACINPUT_TRKAMPLITUDE           	0x01
#define AX5044_45_DACINPUT_TRKRFFREQUENCY         	0x02
#define AX5044_45_DACINPUT_TRKFREQUENCY           	0x03
#define AX5044_45_DACINPUT_FSKDEMOD               	0x04
#define AX5044_45_DACINPUT_AFSKDEMOD              	0x05
#define AX5044_45_DACINPUT_RXSOFTDATA             	0x06
#define AX5044_45_DACINPUT_RSSI                   	0x07
#define AX5044_45_DACINPUT_SAMPLE_ROT_I           	0x08
#define AX5044_45_DACINPUT_SAMPLE_ROT_Q           	0x09
#define AX5044_45_DACINPUT_GPADC                  	0x0C

#define AX5044_45_PINFUNC_SYSCLK_0                	0x00
#define AX5044_45_PINFUNC_SYSCLK_1                	0x01
#define AX5044_45_PINFUNC_SYSCLK_Z                	0x02
#define AX5044_45_PINFUNC_SYSCLK_16MHZ_INV        	0x03
#define AX5044_45_PINFUNC_SYSCLK_16MHZ            	0x04
#define AX5044_45_PINFUNC_SYSCLK_8MHZ             	0x05
#define AX5044_45_PINFUNC_SYSCLK_4MHZ             	0x06
#define AX5044_45_PINFUNC_SYSCLK_2MHZ             	0x07
#define AX5044_45_PINFUNC_SYSCLK_1MHZ             	0x08
#define AX5044_45_PINFUNC_SYSCLK_500KHZ           	0x09
#define AX5044_45_PINFUNC_SYSCLK_250KHZ           	0x0A
#define AX5044_45_PINFUNC_SYSCLK_125KHZ           	0x0B
#define AX5044_45_PINFUNC_SYSCLK_63KHZ            	0x0C
#define AX5044_45_PINFUNC_SYSCLK_31KHZ            	0x0D
#define AX5044_45_PINFUNC_SYSCLK_16KHZ            	0x0E
#define AX5044_45_PINFUNC_SYSCLK_LPOSC            	0x0F
#define AX5044_45_PINFUNC_SYSCLK_TESTOBS          	0x1F

#define AX5044_45_PINFUNC_DCLK_0                  	0x00
#define AX5044_45_PINFUNC_DCLK_1                  	0x01
#define AX5044_45_PINFUNC_DCLK_Z                  	0x02
#define AX5044_45_PINFUNC_DCLK_DCLKIN             	0x03
#define AX5044_45_PINFUNC_DCLK_DCLKOUT            	0x04
#define AX5044_45_PINFUNC_DCLK_TXCLK              	0x05
#define AX5044_45_PINFUNC_DCLK_DSPMODE            	0x06
#define AX5044_45_PINFUNC_DCLK_TESTOBS            	0x07

#define AX5044_45_PINFUNC_DATA_0                  	0x00
#define AX5044_45_PINFUNC_DATA_1                  	0x01
#define AX5044_45_PINFUNC_DATA_Z                  	0x02
#define AX5044_45_PINFUNC_DATA_FRMDATA            	0x03
#define AX5044_45_PINFUNC_DATA_MDMDATA            	0x04
#define AX5044_45_PINFUNC_DATA_MDMASYNCDATA       	0x05
#define AX5044_45_PINFUNC_DATA_DSPMODE            	0x06
#define AX5044_45_PINFUNC_DATA_MDMDATAMON         	0x07
#define AX5044_45_PINFUNC_DATA_TESTOBS            	0x0F

#define AX5044_45_PINFUNC_IRQ_0                   	0x00
#define AX5044_45_PINFUNC_IRQ_1                   	0x01
#define AX5044_45_PINFUNC_IRQ_Z                   	0x02
#define AX5044_45_PINFUNC_IRQ_IRQ                 	0x03
#define AX5044_45_PINFUNC_IRQ_TESTOBS             	0x07

#define AX5044_45_PINFUNC_ANTSEL_0                	0x00
#define AX5044_45_PINFUNC_ANTSEL_1                	0x01
#define AX5044_45_PINFUNC_ANTSEL_Z                	0x02
#define AX5044_45_PINFUNC_ANTSEL_BBTUNECLK        	0x03
#define AX5044_45_PINFUNC_ANTSEL_TCXOENABLE       	0x04
#define AX5044_45_PINFUNC_ANTSEL_DAC              	0x05
#define AX5044_45_PINFUNC_ANTSEL_ANTSEL           	0x06
#define AX5044_45_PINFUNC_ANTSEL_TESTOBS          	0x07

#define AX5044_45_PINFUNC_PWRAMP_0                	0x00
#define AX5044_45_PINFUNC_PWRAMP_1                	0x01
#define AX5044_45_PINFUNC_PWRAMP_Z                	0x02
#define AX5044_45_PINFUNC_PWRAMP_DSYNCIN          	0x03
#define AX5044_45_PINFUNC_PWRAMP_DSYNCOUT         	0x04
#define AX5044_45_PINFUNC_PWRAMP_DAC              	0x05
#define AX5044_45_PINFUNC_PWRAMP_PWRAMP           	0x06
#define AX5044_45_PINFUNC_PWRAMP_TCXOENABLE       	0x07
#define AX5044_45_PINFUNC_PWRAMP_TESTOBS          	0x0F

#define AX5044_45_ADC_MUX_ADCOUT                  	0x00
#define AX5044_45_ADC_MUX_WEIGHT                  	0x01
#define AX5044_45_ADC_MUX_SCALING                 	0x02
#define AX5044_45_ADC_MUX_OFFSET                  	0x03

#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTI0    	0x01
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTI1    	0x02
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTI2    	0x03
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTI3    	0x04
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTI4    	0x05
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTI5    	0x06
#define AX5044_45_ADC_CALPARAMADDRESS_SCALINGI    	0x07
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTQ0    	0x09
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTQ1    	0x0A
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTQ2    	0x0B
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTQ3    	0x0C
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTQ4    	0x0D
#define AX5044_45_ADC_CALPARAMADDRESS_WEIGHTQ5    	0x0E
#define AX5044_45_ADC_CALPARAMADDRESS_SCALINGQ    	0x0F

/* PLL ranging methods */
#define AX5044_45_RNGMODE_SEQ_VTUNE              	0x00
#define AX5044_45_RNGMODE_SEQ_FREQ               	0x01
#define AX5044_45_RNGMODE_SUCCAP_VTUNE           	0x02
#define AX5044_45_RNGMODE_SUCCAP_FREQ            	0x03

#endif /* AX8052F144_45_H */
