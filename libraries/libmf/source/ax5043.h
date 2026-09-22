/**
******************************************************************************
* @file ax5043.h
* @brief Macro definition for AX5043 radio registers
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

#ifndef AX5043_H
#define AX5043_H

#define AX5043_REG_SILICONREVISION   0x0000 /* Silicon Revision */
#define AX5043_REG_SCRATCH           0x0001 /* Scratch */
#define AX5043_REG_PWRMODE           0x0002 /* Power Mode */
#define AX5043_REG_POWSTAT           0x0003 /* Power Management Status */
#define AX5043_REG_POWSTICKYSTAT     0x0004 /* Power Management Sticky Status */
#define AX5043_REG_POWIRQMASK        0x0005 /* Power Management Interrupt Mask */
#define AX5043_REG_IRQMASK1          0x0006 /* IRQ Mask 1 */
#define AX5043_REG_IRQMASK0          0x0007 /* IRQ Mask 0 */
#define AX5043_REG_RADIOEVENTMASK1   0x0008 /* Radio Event Mask 1 */
#define AX5043_REG_RADIOEVENTMASK0   0x0009 /* Radio Event Mask 0 */
#define AX5043_REG_IRQINVERSION1     0x000A /* IRQ Inversion 1 */
#define AX5043_REG_IRQINVERSION0     0x000B /* IRQ Inversion 0 */
#define AX5043_REG_IRQREQUEST1       0x000C /* IRQ Request 1 */
#define AX5043_REG_IRQREQUEST0       0x000D /* IRQ Request 0 */
#define AX5043_REG_RADIOEVENTREQ1    0x000E /* Radio Event Request 1 */
#define AX5043_REG_RADIOEVENTREQ0    0x000F /* Radio Event Request 0 */
#define AX5043_REG_MODULATION        0x0010 /* Modulation */
#define AX5043_REG_ENCODING          0x0011 /* Encoding */
#define AX5043_REG_FRAMING           0x0012 /* Framing Mode */
#define AX5043_REG_CRCINIT3          0x0014 /* CRC Initial Value 3 */
#define AX5043_REG_CRCINIT2          0x0015 /* CRC Initial Value 2 */
#define AX5043_REG_CRCINIT1          0x0016 /* CRC Initial Value 1 */
#define AX5043_REG_CRCINIT0          0x0017 /* CRC Initial Value 0 */
#define AX5043_REG_FEC               0x0018 /* Forward Error Correction */
#define AX5043_REG_FECSYNC           0x0019 /* Forward Error Correction Sync Threshold */
#define AX5043_REG_FECSTATUS         0x001A /* Forward Error Correction Status */
#define AX5043_REG_RADIOSTATE        0x001C /* Radio Controller State */
#define AX5043_REG_XTALSTATUS        0x001D /* Crystal Oscillator Status */
#define AX5043_REG_PINSTATE          0x0020 /* Pin State */
#define AX5043_REG_PINFUNCSYSCLK     0x0021 /* Pin Function SYSCLK */
#define AX5043_REG_PINFUNCDCLK       0x0022 /* Pin Function DCLK */
#define AX5043_REG_PINFUNCDATA       0x0023 /* Pin Function DATA */
#define AX5043_REG_PINFUNCIRQ        0x0024 /* Pin Function IRQ */
#define AX5043_REG_PINFUNCANTSEL     0x0025 /* Pin Function ANTSEL */
#define AX5043_REG_PINFUNCPWRAMP     0x0026 /* Pin Function PWRAMP */
#define AX5043_REG_PWRAMP            0x0027 /* PWRAMP Control */
#define AX5043_REG_FIFOSTAT          0x0028 /* FIFO Control */
#define AX5043_REG_FIFODATA          0x0029 /* FIFO Data */
#define AX5043_REG_FIFOCOUNT1        0x002A /* Number of Words currently in FIFO 1 */
#define AX5043_REG_FIFOCOUNT0        0x002B /* Number of Words currently in FIFO 0 */
#define AX5043_REG_FIFOFREE1         0x002C /* Number of Words that can be written to FIFO 1 */
#define AX5043_REG_FIFOFREE0         0x002D /* Number of Words that can be written to FIFO 0 */
#define AX5043_REG_FIFOTHRESH1       0x002E /* FIFO Threshold 1 */
#define AX5043_REG_FIFOTHRESH0       0x002F /* FIFO Threshold 0 */
#define AX5043_REG_PLLLOOP           0x0030 /* PLL Loop Filter Settings */
#define AX5043_REG_PLLCPI            0x0031 /* PLL Charge Pump Current */
#define AX5043_REG_PLLVCODIV         0x0032 /* PLL Divider Settings */
#define AX5043_REG_PLLRANGINGA       0x0033 /* PLL Autoranging A */
#define AX5043_REG_FREQA3            0x0034 /* Frequency A 3 */
#define AX5043_REG_FREQA2            0x0035 /* Frequency A 2 */
#define AX5043_REG_FREQA1            0x0036 /* Frequency A 1 */
#define AX5043_REG_FREQA0            0x0037 /* Frequency A 0 */
#define AX5043_REG_PLLLOOPBOOST      0x0038 /* PLL Loop Filter Settings (Boosted) */
#define AX5043_REG_PLLCPIBOOST       0x0039 /* PLL Charge Pump Current (Boosted) */
#define AX5043_REG_PLLRANGINGB       0x003B /* PLL Autoranging B */
#define AX5043_REG_FREQB3            0x003C /* Frequency B 3 */
#define AX5043_REG_FREQB2            0x003D /* Frequency B 2 */
#define AX5043_REG_FREQB1            0x003E /* Frequency B 1 */
#define AX5043_REG_FREQB0            0x003F /* Frequency B 0 */
#define AX5043_REG_RSSI              0x0040 /* Received Signal Strength Indicator */
#define AX5043_REG_BGNDRSSI          0x0041 /* Background RSSI */
#define AX5043_REG_DIVERSITY         0x0042 /* Antenna Diversity Configuration */
#define AX5043_REG_AGCCOUNTER        0x0043 /* AGC Counter */
#define AX5043_REG_TRKDATARATE2      0x0045 /* Datarate Tracking 2 */
#define AX5043_REG_TRKDATARATE1      0x0046 /* Datarate Tracking 1 */
#define AX5043_REG_TRKDATARATE0      0x0047 /* Datarate Tracking 0 */
#define AX5043_REG_TRKAMPLITUDE1     0x0048 /* Amplitude Tracking 1 */
#define AX5043_REG_TRKAMPLITUDE0     0x0049 /* Amplitude Tracking 0 */
#define AX5043_REG_TRKPHASE1         0x004A /* Phase Tracking 1 */
#define AX5043_REG_TRKPHASE0         0x004B /* Phase Tracking 0 */
#define AX5043_REG_TRKRFFREQ2        0x004D /* RF Frequency Tracking 2 */
#define AX5043_REG_TRKRFFREQ1        0x004E /* RF Frequency Tracking 1 */
#define AX5043_REG_TRKRFFREQ0        0x004F /* RF Frequency Tracking 0 */
#define AX5043_REG_TRKFREQ1          0x0050 /* Frequency Tracking 1 */
#define AX5043_REG_TRKFREQ0          0x0051 /* Frequency Tracking 0 */
#define AX5043_REG_TRKFSKDEMOD1      0x0052 /* FSK Demodulator Tracking 1 */
#define AX5043_REG_TRKFSKDEMOD0      0x0053 /* FSK Demodulator Tracking 0 */
#define AX5043_REG_TRKAFSKDEMOD1     0x0054 /* AFSK Demodulator Tracking 1 */
#define AX5043_REG_TRKAFSKDEMOD0     0x0055 /* AFSK Demodulator Tracking 0 */
#define AX5043_REG_TIMER2            0x0059 /* 1MHz Timer 2 */
#define AX5043_REG_TIMER1            0x005A /* 1MHz Timer 1 */
#define AX5043_REG_TIMER0            0x005B /* 1MHz Timer 0 */
#define AX5043_REG_WAKEUPTIMER1      0x0068 /* Wakeup Timer 1 */
#define AX5043_REG_WAKEUPTIMER0      0x0069 /* Wakeup Timer 0 */
#define AX5043_REG_WAKEUP1           0x006A /* Wakeup Time 1 */
#define AX5043_REG_WAKEUP0           0x006B /* Wakeup Time 0 */
#define AX5043_REG_WAKEUPFREQ1       0x006C /* Wakeup Frequency 1 */
#define AX5043_REG_WAKEUPFREQ0       0x006D /* Wakeup Frequency 0 */
#define AX5043_REG_WAKEUPXOEARLY     0x006E /* Wakeup Crystal Oscillator Early */
#define AX5043_REG_IFFREQ1           0xF100 /* 2nd LO / IF Frequency 1 */
#define AX5043_REG_IFFREQ0           0xF101 /* 2nd LO / IF Frequency 0 */
#define AX5043_REG_DECIMATION        0xF102 /* Decimation Factor */
#define AX5043_REG_RXDATARATE2       0xF103 /* Receiver Datarate 2 */
#define AX5043_REG_RXDATARATE1       0xF104 /* Receiver Datarate 1 */
#define AX5043_REG_RXDATARATE0       0xF105 /* Receiver Datarate 0 */
#define AX5043_REG_MAXDROFFSET2      0xF106 /* Maximum Receiver Datarate Offset 2 */
#define AX5043_REG_MAXDROFFSET1      0xF107 /* Maximum Receiver Datarate Offset 1 */
#define AX5043_REG_MAXDROFFSET0      0xF108 /* Maximum Receiver Datarate Offset 0 */
#define AX5043_REG_MAXRFOFFSET2      0xF109 /* Maximum Receiver RF Offset 2 */
#define AX5043_REG_MAXRFOFFSET1      0xF10A /* Maximum Receiver RF Offset 1 */
#define AX5043_REG_MAXRFOFFSET0      0xF10B /* Maximum Receiver RF Offset 0 */
#define AX5043_REG_FSKDMAX1          0xF10C /* Four FSK Rx Maximum Deviation 1 */
#define AX5043_REG_FSKDMAX0          0xF10D /* Four FSK Rx Maximum Deviation 0 */
#define AX5043_REG_FSKDMIN1          0xF10E /* Four FSK Rx Minimum Deviation 1 */
#define AX5043_REG_FSKDMIN0          0xF10F /* Four FSK Rx Minimum Deviation 0 */
#define AX5043_REG_AFSKSPACE1        0xF110 /* AFSK Space (0) Frequency 1 */
#define AX5043_REG_AFSKSPACE0        0xF111 /* AFSK Space (0) Frequency 0 */
#define AX5043_REG_AFSKMARK1         0xF112 /* AFSK Mark (1) Frequency 1 */
#define AX5043_REG_AFSKMARK0         0xF113 /* AFSK Mark (1) Frequency 0 */
#define AX5043_REG_AFSKCTRL          0xF114 /* AFSK Control */
#define AX5043_REG_AMPLFILTER        0xF115 /* Amplitude Filter */
#define AX5043_REG_FREQUENCYLEAK     0xF116 /* Baseband Frequency Recovery Loop Leakiness */
#define AX5043_REG_RXPARAMSETS       0xF117 /* Receiver Parameter Set Indirection */
#define AX5043_REG_RXPARAMCURSET     0xF118 /* Receiver Parameter Current Set */
#define AX5043_REG_AGCGAIN0          0xF120 /* AGC Speed */
#define AX5043_REG_AGCTARGET0        0xF121 /* AGC Target */
#define AX5043_REG_AGCAHYST0         0xF122 /* AGC Analog Hysteresis */
#define AX5043_REG_AGCMINMAX0        0xF123 /* AGC Analog Update Behaviour */
#define AX5043_REG_TIMEGAIN0         0xF124 /* Time Estimator Bandwidth */
#define AX5043_REG_DRGAIN0           0xF125 /* Data Rate Estimator Bandwidth */
#define AX5043_REG_PHASEGAIN0        0xF126 /* Phase Estimator Bandwidth */
#define AX5043_REG_FREQUENCYGAINA0   0xF127 /* Frequency Estimator Bandwidth A */
#define AX5043_REG_FREQUENCYGAINB0   0xF128 /* Frequency Estimator Bandwidth B */
#define AX5043_REG_FREQUENCYGAINC0   0xF129 /* Frequency Estimator Bandwidth C */
#define AX5043_REG_FREQUENCYGAIND0   0xF12A /* Frequency Estimator Bandwidth D */
#define AX5043_REG_AMPLITUDEGAIN0    0xF12B /* Amplitude Estimator Bandwidth */
#define AX5043_REG_FREQDEV10         0xF12C /* Receiver Frequency Deviation 1 */
#define AX5043_REG_FREQDEV00         0xF12D /* Receiver Frequency Deviation 0 */
#define AX5043_REG_FOURFSK0          0xF12E /* Four FSK Control */
#define AX5043_REG_BBOFFSRES0        0xF12F /* Baseband Offset Compensation Resistors */
#define AX5043_REG_AGCGAIN1          0xF130 /* AGC Speed */
#define AX5043_REG_AGCTARGET1        0xF131 /* AGC Target */
#define AX5043_REG_AGCAHYST1         0xF132 /* AGC Analog Hysteresis */
#define AX5043_REG_AGCMINMAX1        0xF133 /* AGC Analog Update Behaviour */
#define AX5043_REG_TIMEGAIN1         0xF134 /* Time Estimator Bandwidth */
#define AX5043_REG_DRGAIN1           0xF135 /* Data Rate Estimator Bandwidth */
#define AX5043_REG_PHASEGAIN1        0xF136 /* Phase Estimator Bandwidth */
#define AX5043_REG_FREQUENCYGAINA1   0xF137 /* Frequency Estimator Bandwidth A */
#define AX5043_REG_FREQUENCYGAINB1   0xF138 /* Frequency Estimator Bandwidth B */
#define AX5043_REG_FREQUENCYGAINC1   0xF139 /* Frequency Estimator Bandwidth C */
#define AX5043_REG_FREQUENCYGAIND1   0xF13A /* Frequency Estimator Bandwidth D */
#define AX5043_REG_AMPLITUDEGAIN1    0xF13B /* Amplitude Estimator Bandwidth */
#define AX5043_REG_FREQDEV11         0xF13C /* Receiver Frequency Deviation 1 */
#define AX5043_REG_FREQDEV01         0xF13D /* Receiver Frequency Deviation 0 */
#define AX5043_REG_FOURFSK1          0xF13E /* Four FSK Control */
#define AX5043_REG_BBOFFSRES1        0xF13F /* Baseband Offset Compensation Resistors */
#define AX5043_REG_AGCGAIN2          0xF140 /* AGC Speed */
#define AX5043_REG_AGCTARGET2        0xF141 /* AGC Target */
#define AX5043_REG_AGCAHYST2         0xF142 /* AGC Analog Hysteresis */
#define AX5043_REG_AGCMINMAX2        0xF143 /* AGC Analog Update Behaviour */
#define AX5043_REG_TIMEGAIN2         0xF144 /* Time Estimator Bandwidth */
#define AX5043_REG_DRGAIN2           0xF145 /* Data Rate Estimator Bandwidth */
#define AX5043_REG_PHASEGAIN2        0xF146 /* Phase Estimator Bandwidth */
#define AX5043_REG_FREQUENCYGAINA2   0xF147 /* Frequency Estimator Bandwidth A */
#define AX5043_REG_FREQUENCYGAINB2   0xF148 /* Frequency Estimator Bandwidth B */
#define AX5043_REG_FREQUENCYGAINC2   0xF149 /* Frequency Estimator Bandwidth C */
#define AX5043_REG_FREQUENCYGAIND2   0xF14A /* Frequency Estimator Bandwidth D */
#define AX5043_REG_AMPLITUDEGAIN2    0xF14B /* Amplitude Estimator Bandwidth */
#define AX5043_REG_FREQDEV12         0xF14C /* Receiver Frequency Deviation 1 */
#define AX5043_REG_FREQDEV02         0xF14D /* Receiver Frequency Deviation 0 */
#define AX5043_REG_FOURFSK2          0xF14E /* Four FSK Control */
#define AX5043_REG_BBOFFSRES2        0xF14F /* Baseband Offset Compensation Resistors */
#define AX5043_REG_AGCGAIN3          0xF150 /* AGC Speed */
#define AX5043_REG_AGCTARGET3        0xF151 /* AGC Target */
#define AX5043_REG_AGCAHYST3         0xF152 /* AGC Analog Hysteresis */
#define AX5043_REG_AGCMINMAX3        0xF153 /* AGC Analog Update Behaviour */
#define AX5043_REG_TIMEGAIN3         0xF154 /* Time Estimator Bandwidth */
#define AX5043_REG_DRGAIN3           0xF155 /* Data Rate Estimator Bandwidth */
#define AX5043_REG_PHASEGAIN3        0xF156 /* Phase Estimator Bandwidth */
#define AX5043_REG_FREQUENCYGAINA3   0xF157 /* Frequency Estimator Bandwidth A */
#define AX5043_REG_FREQUENCYGAINB3   0xF158 /* Frequency Estimator Bandwidth B */
#define AX5043_REG_FREQUENCYGAINC3   0xF159 /* Frequency Estimator Bandwidth C */
#define AX5043_REG_FREQUENCYGAIND3   0xF15A /* Frequency Estimator Bandwidth D */
#define AX5043_REG_AMPLITUDEGAIN3    0xF15B /* Amplitude Estimator Bandwidth */
#define AX5043_REG_FREQDEV13         0xF15C /* Receiver Frequency Deviation 1 */
#define AX5043_REG_FREQDEV03         0xF15D /* Receiver Frequency Deviation 0 */
#define AX5043_REG_FOURFSK3          0xF15E /* Four FSK Control */
#define AX5043_REG_BBOFFSRES3        0xF15F /* Baseband Offset Compensation Resistors */
#define AX5043_REG_MODCFGF           0xF160 /* Modulator Configuration F */
#define AX5043_REG_FSKDEV2           0xF161 /* FSK Deviation 2 */
#define AX5043_REG_FSKDEV1           0xF162 /* FSK Deviation 1 */
#define AX5043_REG_FSKDEV0           0xF163 /* FSK Deviation 0 */
#define AX5043_REG_MODCFGA           0xF164 /* Modulator Configuration A */
#define AX5043_REG_TXRATE2           0xF165 /* Transmitter Bitrate 2 */
#define AX5043_REG_TXRATE1           0xF166 /* Transmitter Bitrate 1 */
#define AX5043_REG_TXRATE0           0xF167 /* Transmitter Bitrate 0 */
#define AX5043_REG_TXPWRCOEFFA1      0xF168 /* Transmitter Predistortion Coefficient A 1 */
#define AX5043_REG_TXPWRCOEFFA0      0xF169 /* Transmitter Predistortion Coefficient A 0 */
#define AX5043_REG_TXPWRCOEFFB1      0xF16A /* Transmitter Predistortion Coefficient B 1 */
#define AX5043_REG_TXPWRCOEFFB0      0xF16B /* Transmitter Predistortion Coefficient B 0 */
#define AX5043_REG_TXPWRCOEFFC1      0xF16C /* Transmitter Predistortion Coefficient C 1 */
#define AX5043_REG_TXPWRCOEFFC0      0xF16D /* Transmitter Predistortion Coefficient C 0 */
#define AX5043_REG_TXPWRCOEFFD1      0xF16E /* Transmitter Predistortion Coefficient D 1 */
#define AX5043_REG_TXPWRCOEFFD0      0xF16F /* Transmitter Predistortion Coefficient D 0 */
#define AX5043_REG_TXPWRCOEFFE1      0xF170 /* Transmitter Predistortion Coefficient E 1 */
#define AX5043_REG_TXPWRCOEFFE0      0xF171 /* Transmitter Predistortion Coefficient E 0 */
#define AX5043_REG_PLLVCOI           0xF180 /* PLL VCO Current */
#define AX5043_REG_PLLVCOIR          0xF181 /* PLL VCO Current Readback */
#define AX5043_REG_PLLLOCKDET        0xF182 /* PLL Lock Detect Delay */
#define AX5043_REG_PLLRNGCLK         0xF183 /* PLL Autoranging Clock */
#define AX5043_REG_XTALCAP           0xF184 /* Crystal Oscillator Load Capacitance */
#define AX5043_REG_BBTUNE            0xF188 /* Baseband Tuning */
#define AX5043_REG_BBOFFSCAP         0xF189 /* Baseband Offset Compensation Capacitors */
#define AX5043_REG_PKTADDRCFG        0xF200 /* Packet Address Config */
#define AX5043_REG_PKTLENCFG         0xF201 /* Packet Length Configuration */
#define AX5043_REG_PKTLENOFFSET      0xF202 /* Packet Length Offset */
#define AX5043_REG_PKTMAXLEN         0xF203 /* Packet Maximum Length */
#define AX5043_REG_PKTADDR3          0xF204 /* Packet Address 3 */
#define AX5043_REG_PKTADDR2          0xF205 /* Packet Address 2 */
#define AX5043_REG_PKTADDR1          0xF206 /* Packet Address 1 */
#define AX5043_REG_PKTADDR0          0xF207 /* Packet Address 0 */
#define AX5043_REG_PKTADDRMASK3      0xF208 /* Packet Address Mask 3 */
#define AX5043_REG_PKTADDRMASK2      0xF209 /* Packet Address Mask 2 */
#define AX5043_REG_PKTADDRMASK1      0xF20A /* Packet Address Mask 1 */
#define AX5043_REG_PKTADDRMASK0      0xF20B /* Packet Address Mask 0 */
#define AX5043_REG_MATCH0PAT3        0xF210 /* Pattern Match Unit 0, Pattern 3 */
#define AX5043_REG_MATCH0PAT2        0xF211 /* Pattern Match Unit 0, Pattern 2 */
#define AX5043_REG_MATCH0PAT1        0xF212 /* Pattern Match Unit 0, Pattern 1 */
#define AX5043_REG_MATCH0PAT0        0xF213 /* Pattern Match Unit 0, Pattern 0 */
#define AX5043_REG_MATCH0LEN         0xF214 /* Pattern Match Unit 0, Pattern Length */
#define AX5043_REG_MATCH0MIN         0xF215 /* Pattern Match Unit 0, Minimum Match */
#define AX5043_REG_MATCH0MAX         0xF216 /* Pattern Match Unit 0, Maximum Match */
#define AX5043_REG_MATCH1PAT1        0xF218 /* Pattern Match Unit 1, Pattern 1 */
#define AX5043_REG_MATCH1PAT0        0xF219 /* Pattern Match Unit 1, Pattern 0 */
#define AX5043_REG_MATCH1LEN         0xF21C /* Pattern Match Unit 1, Pattern Length */
#define AX5043_REG_MATCH1MIN         0xF21D /* Pattern Match Unit 1, Minimum Match */
#define AX5043_REG_MATCH1MAX         0xF21E /* Pattern Match Unit 1, Maximum Match */
#define AX5043_REG_TMGTXBOOST        0xF220 /* Transmit PLL Boost Time */
#define AX5043_REG_TMGTXSETTLE       0xF221 /* Transmit PLL (post Boost) Settling Time */
#define AX5043_REG_TMGRXBOOST        0xF223 /* Receive PLL Boost Time */
#define AX5043_REG_TMGRXSETTLE       0xF224 /* Receive PLL (post Boost) Settling Time */
#define AX5043_REG_TMGRXOFFSACQ      0xF225 /* Receive Baseband DC Offset Acquisition Time */
#define AX5043_REG_TMGRXCOARSEAGC    0xF226 /* Receive Coarse AGC Time */
#define AX5043_REG_TMGRXAGC          0xF227 /* Receiver AGC Settling Time */
#define AX5043_REG_TMGRXRSSI         0xF228 /* Receiver RSSI Settling Time */
#define AX5043_REG_TMGRXPREAMBLE1    0xF229 /* Receiver Preamble 1 Timeout */
#define AX5043_REG_TMGRXPREAMBLE2    0xF22A /* Receiver Preamble 2 Timeout */
#define AX5043_REG_TMGRXPREAMBLE3    0xF22B /* Receiver Preamble 3 Timeout */
#define AX5043_REG_RSSIREFERENCE     0xF22C /* RSSI Offset */
#define AX5043_REG_RSSIABSTHR        0xF22D /* RSSI Absolute Threshold */
#define AX5043_REG_BGNDRSSIGAIN      0xF22E /* Background RSSI Averaging Time Constant */
#define AX5043_REG_BGNDRSSITHR       0xF22F /* Background RSSI Relative Threshold */
#define AX5043_REG_PKTCHUNKSIZE      0xF230 /* Packet Chunk Size */
#define AX5043_REG_PKTMISCFLAGS      0xF231 /* Packet Controller Miscellaneous Flags */
#define AX5043_REG_PKTSTOREFLAGS     0xF232 /* Packet Controller Store Flags */
#define AX5043_REG_PKTACCEPTFLAGS    0xF233 /* Packet Controller Accept Flags */
#define AX5043_REG_GPADCCTRL         0xF300 /* General Purpose ADC Control */
#define AX5043_REG_GPADCPERIOD       0xF301 /* GPADC Sampling Period */
#define AX5043_REG_GPADC13VALUE1     0xF308 /* GPADC13 Value 1 */
#define AX5043_REG_GPADC13VALUE0     0xF309 /* GPADC13 Value 0 */
#define AX5043_REG_LPOSCCONFIG       0xF310 /* Low Power Oscillator Calibration Configuration */
#define AX5043_REG_LPOSCSTATUS       0xF311 /* Low Power Oscillator Calibration Status */
#define AX5043_REG_LPOSCKFILT1       0xF312 /* Low Power Oscillator Calibration Filter Constant High Byte */
#define AX5043_REG_LPOSCKFILT0       0xF313 /* Low Power Oscillator Calibration Filter Constant Low Byte */
#define AX5043_REG_LPOSCREF1         0xF314 /* Low Power Oscillator Reference Frequency High Byte */
#define AX5043_REG_LPOSCREF0         0xF315 /* Low Power Oscillator Reference Frequency Low Byte */
#define AX5043_REG_LPOSCFREQ1        0xF316 /* Low Power Oscillator Frequency Tuning High Byte */
#define AX5043_REG_LPOSCFREQ0        0xF317 /* Low Power Oscillator Frequency Tuning Low Byte */
#define AX5043_REG_LPOSCPER1         0xF318 /* Low Power Oscillator Period High Byte */
#define AX5043_REG_LPOSCPER0         0xF319 /* Low Power Oscillator Period Low Byte */
#define AX5043_REG_DACVALUE1         0xF330 /* DAC Value 1 */
#define AX5043_REG_DACVALUE0         0xF331 /* DAC Value 0 */
#define AX5043_REG_DACCONFIG         0xF332 /* DAC Configuration */
#define AX5043_REG_0xF00             0xFF00
#define AX5043_REG_POWCTRL1          0xFF08 /* Power Control 1 */
#define AX5043_REG_0xF0C             0xFF0C
#define AX5043_REG_REF               0xFF0D /* Reference */
#define AX5043_REG_XTALOSC           0xFF10 /* Crystal Oscillator Control */
#define AX5043_REG_XTALAMPL          0xFF11 /* Crystal Oscillator Amplitude Control */
#define AX5043_REG_0xF18             0xFF18
#define AX5043_REG_0xF1C             0xFF1C
#define AX5043_REG_0xF21             0xFF21
#define AX5043_REG_0xF22             0xFF22
#define AX5043_REG_0xF23             0xFF23
#define AX5043_REG_0xF26             0xFF26
#define AX5043_REG_0xF30             0xFF30
#define AX5043_REG_0xF31             0xFF31
#define AX5043_REG_0xF32             0xFF32
#define AX5043_REG_0xF33             0xFF33
#define AX5043_REG_0xF34             0xFF34
#define AX5043_REG_0xF35             0xFF35
#define AX5043_REG_0xF44             0xFF44
#define AX5043_REG_MODCFGP           0xFF5F /* Modulator Configuration P */

#endif /* AX5043_H */
