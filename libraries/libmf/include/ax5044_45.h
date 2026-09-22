/**
******************************************************************************
* @file ax5044_45.h
* @brief Macro definition for ax5044_45 radio registers
* @internal
* @author Pradeep Kumar G R
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

#ifndef AX5044_45_H
#define AX5044_45_H

/* Revision & Interface Probing */
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

#endif /* AX5044_45_H */
