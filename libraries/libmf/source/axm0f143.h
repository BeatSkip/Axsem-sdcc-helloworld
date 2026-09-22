/**
******************************************************************************
* @file axm0f143.h
* @brief Macro definition for AX5043 radio registers
* @internal
* @author Thomas Sailer, Pradeep Kumar G R
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

#ifndef AXM0F143_H
#define AXM0F143_H

#include <axm0.h>

#define AX5043_SILICONREVISION       (*(__I  uint8_t  *)(0x00020000 + SPI0_BASE)) /* Silicon Revision */
#define AX5043_SCRATCH               (*(__IO uint8_t  *)(0x00020004 + SPI0_BASE)) /* Scratch */
#define AX5043_PWRMODE               (*(__IO uint8_t  *)(0x00020008 + SPI0_BASE)) /* Power Mode */
#define AX5043_POWSTAT               (*(__I  uint8_t  *)(0x0002000C + SPI0_BASE)) /* Power Management Status */
#define AX5043_POWSTICKYSTAT         (*(__I  uint8_t  *)(0x00020010 + SPI0_BASE)) /* Power Management Sticky Status */
#define AX5043_POWIRQMASK            (*(__IO uint8_t  *)(0x00020014 + SPI0_BASE)) /* Power Management Interrupt Mask */
#define AX5043_IRQMASK               (*(__IO uint16_t *)(0x000A0018 + SPI0_BASE)) /* IRQ Mask */
#define AX5043_IRQMASK1              (*(__IO uint8_t  *)(0x00020018 + SPI0_BASE)) /* IRQ Mask 1 */
#define AX5043_IRQMASK0              (*(__IO uint8_t  *)(0x0002001C + SPI0_BASE)) /* IRQ Mask 0 */
#define AX5043_RADIOEVENTMASK        (*(__IO uint16_t *)(0x000A0020 + SPI0_BASE)) /* Radio Event Mask */
#define AX5043_RADIOEVENTMASK1       (*(__IO uint8_t  *)(0x00020020 + SPI0_BASE)) /* Radio Event Mask 1 */
#define AX5043_RADIOEVENTMASK0       (*(__IO uint8_t  *)(0x00020024 + SPI0_BASE)) /* Radio Event Mask 0 */
#define AX5043_IRQINVERSION          (*(__IO uint16_t *)(0x000A0028 + SPI0_BASE)) /* IRQ Inversion */
#define AX5043_IRQINVERSION1         (*(__IO uint8_t  *)(0x00020028 + SPI0_BASE)) /* IRQ Inversion 1 */
#define AX5043_IRQINVERSION0         (*(__IO uint8_t  *)(0x0002002C + SPI0_BASE)) /* IRQ Inversion 0 */
#define AX5043_IRQREQUEST            (*(__I  uint16_t *)(0x000A0030 + SPI0_BASE)) /* IRQ Request */
#define AX5043_IRQREQUEST1           (*(__I  uint8_t  *)(0x00020030 + SPI0_BASE)) /* IRQ Request 1 */
#define AX5043_IRQREQUEST0           (*(__I  uint8_t  *)(0x00020034 + SPI0_BASE)) /* IRQ Request 0 */
#define AX5043_RADIOEVENTREQ         (*(__I  uint16_t *)(0x000A0038 + SPI0_BASE)) /* Radio Event Request */
#define AX5043_RADIOEVENTREQ1        (*(__I  uint8_t  *)(0x00020038 + SPI0_BASE)) /* Radio Event Request 1 */
#define AX5043_RADIOEVENTREQ0        (*(__I  uint8_t  *)(0x0002003C + SPI0_BASE)) /* Radio Event Request 0 */
#define AX5043_MODULATION            (*(__IO uint8_t  *)(0x00020040 + SPI0_BASE)) /* Modulation */
#define AX5043_ENCODING              (*(__IO uint8_t  *)(0x00020044 + SPI0_BASE)) /* Encoding */
#define AX5043_FRAMING               (*(__IO uint8_t  *)(0x00020048 + SPI0_BASE)) /* Framing Mode */
#define AX5043_CRCINIT               (*(__IO uint32_t *)(0x020A0050 + SPI0_BASE)) /* CRC Initial Value */
#define AX5043_CRCINIT3              (*(__IO uint8_t  *)(0x00020050 + SPI0_BASE)) /* CRC Initial Value 3 */
#define AX5043_CRCINIT2              (*(__IO uint8_t  *)(0x00020054 + SPI0_BASE)) /* CRC Initial Value 2 */
#define AX5043_CRCINIT1              (*(__IO uint8_t  *)(0x00020058 + SPI0_BASE)) /* CRC Initial Value 1 */
#define AX5043_CRCINIT0              (*(__IO uint8_t  *)(0x0002005C + SPI0_BASE)) /* CRC Initial Value 0 */
#define AX5043_FEC                   (*(__IO uint8_t  *)(0x00020060 + SPI0_BASE)) /* Forward Error Correction */
#define AX5043_FECSYNC               (*(__IO uint8_t  *)(0x00020064 + SPI0_BASE)) /* Forward Error Correction Sync Threshold */
#define AX5043_FECSTATUS             (*(__I  uint8_t  *)(0x00020068 + SPI0_BASE)) /* Forward Error Correction Status */
#define AX5043_RADIOSTATE            (*(__I  uint8_t  *)(0x00020070 + SPI0_BASE)) /* Radio Controller State */
#define AX5043_XTALSTATUS            (*(__I  uint8_t  *)(0x00020074 + SPI0_BASE)) /* Crystal Oscillator Status */
#define AX5043_PINSTATE              (*(__I  uint8_t  *)(0x00020080 + SPI0_BASE)) /* Pin State */
#define AX5043_PINFUNCSYSCLK         (*(__IO uint8_t  *)(0x00020084 + SPI0_BASE)) /* Pin Function SYSCLK */
#define AX5043_PINFUNCDCLK           (*(__IO uint8_t  *)(0x00020088 + SPI0_BASE)) /* Pin Function DCLK */
#define AX5043_PINFUNCDATA           (*(__IO uint8_t  *)(0x0002008C + SPI0_BASE)) /* Pin Function DATA */
#define AX5043_PINFUNCIRQ            (*(__IO uint8_t  *)(0x00020090 + SPI0_BASE)) /* Pin Function IRQ */
#define AX5043_PINFUNCANTSEL         (*(__IO uint8_t  *)(0x00020094 + SPI0_BASE)) /* Pin Function ANTSEL */
#define AX5043_PINFUNCPWRAMP         (*(__IO uint8_t  *)(0x00020098 + SPI0_BASE)) /* Pin Function PWRAMP */
#define AX5043_PWRAMP                (*(__IO uint8_t  *)(0x0002009C + SPI0_BASE)) /* PWRAMP Control */
#define AX5043_FIFOSTAT              (*(__IO uint8_t  *)(0x000200A0 + SPI0_BASE)) /* FIFO Control */
#define AX5043_FIFODATA              (*(__IO uint8_t  *)(0x000200A4 + SPI0_BASE)) /* FIFO Data */
#define AX5043_FIFOCOUNT             (*(__I  uint16_t *)(0x000A00A8 + SPI0_BASE)) /* Number of Words currently in FIFO */
#define AX5043_FIFOCOUNT1            (*(__I  uint8_t  *)(0x000200A8 + SPI0_BASE)) /* Number of Words currently in FIFO 1 */
#define AX5043_FIFOCOUNT0            (*(__I  uint8_t  *)(0x000200AC + SPI0_BASE)) /* Number of Words currently in FIFO 0 */
#define AX5043_FIFOFREE              (*(__I  uint16_t *)(0x000A00B0 + SPI0_BASE)) /* Number of Words that can be written to FIFO */
#define AX5043_FIFOFREE1             (*(__I  uint8_t  *)(0x000200B0 + SPI0_BASE)) /* Number of Words that can be written to FIFO 1 */
#define AX5043_FIFOFREE0             (*(__I  uint8_t  *)(0x000200B4 + SPI0_BASE)) /* Number of Words that can be written to FIFO 0 */
#define AX5043_FIFOTHRESH            (*(__IO uint16_t *)(0x000A00B8 + SPI0_BASE)) /* FIFO Threshold */
#define AX5043_FIFOTHRESH1           (*(__IO uint8_t  *)(0x000200B8 + SPI0_BASE)) /* FIFO Threshold 1 */
#define AX5043_FIFOTHRESH0           (*(__IO uint8_t  *)(0x000200BC + SPI0_BASE)) /* FIFO Threshold 0 */
#define AX5043_PLLLOOP               (*(__IO uint8_t  *)(0x000200C0 + SPI0_BASE)) /* PLL Loop Filter Settings */
#define AX5043_PLLCPI                (*(__IO uint8_t  *)(0x000200C4 + SPI0_BASE)) /* PLL Charge Pump Current */
#define AX5043_PLLVCODIV             (*(__IO uint8_t  *)(0x000200C8 + SPI0_BASE)) /* PLL Divider Settings */
#define AX5043_PLLRANGINGA           (*(__IO uint8_t  *)(0x000200CC + SPI0_BASE)) /* PLL Autoranging A */
#define AX5043_FREQA                 (*(__IO uint32_t *)(0x020A00D0 + SPI0_BASE)) /* Frequency A */
#define AX5043_FREQA3                (*(__IO uint8_t  *)(0x000200D0 + SPI0_BASE)) /* Frequency A 3 */
#define AX5043_FREQA2                (*(__IO uint8_t  *)(0x000200D4 + SPI0_BASE)) /* Frequency A 2 */
#define AX5043_FREQA1                (*(__IO uint8_t  *)(0x000200D8 + SPI0_BASE)) /* Frequency A 1 */
#define AX5043_FREQA0                (*(__IO uint8_t  *)(0x000200DC + SPI0_BASE)) /* Frequency A 0 */
#define AX5043_PLLLOOPBOOST          (*(__IO uint8_t  *)(0x000200E0 + SPI0_BASE)) /* PLL Loop Filter Settings (Boosted) */
#define AX5043_PLLCPIBOOST           (*(__IO uint8_t  *)(0x000200E4 + SPI0_BASE)) /* PLL Charge Pump Current (Boosted) */
#define AX5043_PLLRANGINGB           (*(__IO uint8_t  *)(0x000200EC + SPI0_BASE)) /* PLL Autoranging B */
#define AX5043_FREQB                 (*(__IO uint32_t *)(0x020A00F0 + SPI0_BASE)) /* Frequency B */
#define AX5043_FREQB3                (*(__IO uint8_t  *)(0x000200F0 + SPI0_BASE)) /* Frequency B 3 */
#define AX5043_FREQB2                (*(__IO uint8_t  *)(0x000200F4 + SPI0_BASE)) /* Frequency B 2 */
#define AX5043_FREQB1                (*(__IO uint8_t  *)(0x000200F8 + SPI0_BASE)) /* Frequency B 1 */
#define AX5043_FREQB0                (*(__IO uint8_t  *)(0x000200FC + SPI0_BASE)) /* Frequency B 0 */
#define AX5043_RSSI                  (*(__I  uint8_t  *)(0x00020100 + SPI0_BASE)) /* Received Signal Strength Indicator */
#define AX5043_BGNDRSSI              (*(__IO uint8_t  *)(0x00020104 + SPI0_BASE)) /* Background RSSI */
#define AX5043_DIVERSITY             (*(__IO uint8_t  *)(0x00020108 + SPI0_BASE)) /* Antenna Diversity Configuration */
#define AX5043_AGCCOUNTER            (*(__IO uint8_t  *)(0x0002010C + SPI0_BASE)) /* AGC Counter */
#define AX5043_TRKDATARATE           (*(__I  uint32_t *)(0x02020114 + SPI0_BASE)) /* Datarate Tracking */
#define AX5043_TRKDATARATE2          (*(__I  uint8_t  *)(0x00020114 + SPI0_BASE)) /* Datarate Tracking 2 */
#define AX5043_TRKDATARATE1          (*(__I  uint8_t  *)(0x00020118 + SPI0_BASE)) /* Datarate Tracking 1 */
#define AX5043_TRKDATARATE0          (*(__I  uint8_t  *)(0x0002011C + SPI0_BASE)) /* Datarate Tracking 0 */
#define AX5043_TRKAMPLITUDE          (*(__I  uint16_t *)(0x000A0120 + SPI0_BASE)) /* Amplitude Tracking */
#define AX5043_TRKAMPLITUDE1         (*(__I  uint8_t  *)(0x00020120 + SPI0_BASE)) /* Amplitude Tracking 1 */
#define AX5043_TRKAMPLITUDE0         (*(__I  uint8_t  *)(0x00020124 + SPI0_BASE)) /* Amplitude Tracking 0 */
#define AX5043_TRKPHASE              (*(__I  uint16_t *)(0x000A0128 + SPI0_BASE)) /* Phase Tracking */
#define AX5043_TRKPHASE1             (*(__I  uint8_t  *)(0x00020128 + SPI0_BASE)) /* Phase Tracking 1 */
#define AX5043_TRKPHASE0             (*(__I  uint8_t  *)(0x0002012C + SPI0_BASE)) /* Phase Tracking 0 */
#define AX5043_TRKRFFREQ             (*(__IO uint32_t *)(0x02020134 + SPI0_BASE)) /* RF Frequency Tracking */
#define AX5043_TRKRFFREQ2            (*(__IO uint8_t  *)(0x00020134 + SPI0_BASE)) /* RF Frequency Tracking 2 */
#define AX5043_TRKRFFREQ1            (*(__IO uint8_t  *)(0x00020138 + SPI0_BASE)) /* RF Frequency Tracking 1 */
#define AX5043_TRKRFFREQ0            (*(__IO uint8_t  *)(0x0002013C + SPI0_BASE)) /* RF Frequency Tracking 0 */
#define AX5043_TRKFREQ               (*(__IO uint16_t *)(0x000A0140 + SPI0_BASE)) /* Frequency Tracking */
#define AX5043_TRKFREQ1              (*(__IO uint8_t  *)(0x00020140 + SPI0_BASE)) /* Frequency Tracking 1 */
#define AX5043_TRKFREQ0              (*(__IO uint8_t  *)(0x00020144 + SPI0_BASE)) /* Frequency Tracking 0 */
#define AX5043_TRKFSKDEMOD           (*(__I  uint16_t *)(0x000A0148 + SPI0_BASE)) /* FSK Demodulator Tracking */
#define AX5043_TRKFSKDEMOD1          (*(__I  uint8_t  *)(0x00020148 + SPI0_BASE)) /* FSK Demodulator Tracking 1 */
#define AX5043_TRKFSKDEMOD0          (*(__I  uint8_t  *)(0x0002014C + SPI0_BASE)) /* FSK Demodulator Tracking 0 */
#define AX5043_TRKAFSKDEMOD          (*(__I  uint16_t *)(0x000A0150 + SPI0_BASE)) /* AFSK Demodulator Tracking */
#define AX5043_TRKAFSKDEMOD1         (*(__I  uint8_t  *)(0x00020150 + SPI0_BASE)) /* AFSK Demodulator Tracking 1 */
#define AX5043_TRKAFSKDEMOD0         (*(__I  uint8_t  *)(0x00020154 + SPI0_BASE)) /* AFSK Demodulator Tracking 0 */
#define AX5043_TIMER                 (*(__I  uint32_t *)(0x02020164 + SPI0_BASE)) /* 1MHz Timer */
#define AX5043_TIMER2                (*(__I  uint8_t  *)(0x00020164 + SPI0_BASE)) /* 1MHz Timer 2 */
#define AX5043_TIMER1                (*(__I  uint8_t  *)(0x00020168 + SPI0_BASE)) /* 1MHz Timer 1 */
#define AX5043_TIMER0                (*(__I  uint8_t  *)(0x0002016C + SPI0_BASE)) /* 1MHz Timer 0 */
#define AX5043_WAKEUPTIMER           (*(__I  uint16_t *)(0x000A01A0 + SPI0_BASE)) /* Wakeup Timer */
#define AX5043_WAKEUPTIMER1          (*(__I  uint8_t  *)(0x000201A0 + SPI0_BASE)) /* Wakeup Timer 1 */
#define AX5043_WAKEUPTIMER0          (*(__I  uint8_t  *)(0x000201A4 + SPI0_BASE)) /* Wakeup Timer 0 */
#define AX5043_WAKEUP                (*(__IO uint16_t *)(0x000A01A8 + SPI0_BASE)) /* Wakeup Time */
#define AX5043_WAKEUP1               (*(__IO uint8_t  *)(0x000201A8 + SPI0_BASE)) /* Wakeup Time 1 */
#define AX5043_WAKEUP0               (*(__IO uint8_t  *)(0x000201AC + SPI0_BASE)) /* Wakeup Time 0 */
#define AX5043_WAKEUPFREQ            (*(__IO uint16_t *)(0x000A01B0 + SPI0_BASE)) /* Wakeup Frequency */
#define AX5043_WAKEUPFREQ1           (*(__IO uint8_t  *)(0x000201B0 + SPI0_BASE)) /* Wakeup Frequency 1 */
#define AX5043_WAKEUPFREQ0           (*(__IO uint8_t  *)(0x000201B4 + SPI0_BASE)) /* Wakeup Frequency 0 */
#define AX5043_WAKEUPXOEARLY         (*(__IO uint8_t  *)(0x000201B8 + SPI0_BASE)) /* Wakeup Crystal Oscillator Early */
#define AX5043_IFFREQ                (*(__IO uint16_t *)(0x0009C400 + SPI0_BASE)) /* 2nd LO / IF Frequency */
#define AX5043_IFFREQ1               (*(__IO uint8_t  *)(0x0001C400 + SPI0_BASE)) /* 2nd LO / IF Frequency 1 */
#define AX5043_IFFREQ0               (*(__IO uint8_t  *)(0x0001C404 + SPI0_BASE)) /* 2nd LO / IF Frequency 0 */
#define AX5043_DECIMATION            (*(__IO uint8_t  *)(0x0001C408 + SPI0_BASE)) /* Decimation Factor */
#define AX5043_RXDATARATE            (*(__IO uint32_t *)(0x0201C40C + SPI0_BASE)) /* Receiver Datarate */
#define AX5043_RXDATARATE2           (*(__IO uint8_t  *)(0x0001C40C + SPI0_BASE)) /* Receiver Datarate 2 */
#define AX5043_RXDATARATE1           (*(__IO uint8_t  *)(0x0001C410 + SPI0_BASE)) /* Receiver Datarate 1 */
#define AX5043_RXDATARATE0           (*(__IO uint8_t  *)(0x0001C414 + SPI0_BASE)) /* Receiver Datarate 0 */
#define AX5043_MAXDROFFSET           (*(__IO uint32_t *)(0x0201C418 + SPI0_BASE)) /* Maximum Receiver Datarate Offset */
#define AX5043_MAXDROFFSET2          (*(__IO uint8_t  *)(0x0001C418 + SPI0_BASE)) /* Maximum Receiver Datarate Offset 2 */
#define AX5043_MAXDROFFSET1          (*(__IO uint8_t  *)(0x0001C41C + SPI0_BASE)) /* Maximum Receiver Datarate Offset 1 */
#define AX5043_MAXDROFFSET0          (*(__IO uint8_t  *)(0x0001C420 + SPI0_BASE)) /* Maximum Receiver Datarate Offset 0 */
#define AX5043_MAXRFOFFSET           (*(__IO uint32_t *)(0x0201C424 + SPI0_BASE)) /* Maximum Receiver RF Offset */
#define AX5043_MAXRFOFFSET2          (*(__IO uint8_t  *)(0x0001C424 + SPI0_BASE)) /* Maximum Receiver RF Offset 2 */
#define AX5043_MAXRFOFFSET1          (*(__IO uint8_t  *)(0x0001C428 + SPI0_BASE)) /* Maximum Receiver RF Offset 1 */
#define AX5043_MAXRFOFFSET0          (*(__IO uint8_t  *)(0x0001C42C + SPI0_BASE)) /* Maximum Receiver RF Offset 0 */
#define AX5043_FSKDMAX               (*(__IO uint16_t *)(0x0009C430 + SPI0_BASE)) /* Four FSK Rx Maximum Deviation */
#define AX5043_FSKDMAX1              (*(__IO uint8_t  *)(0x0001C430 + SPI0_BASE)) /* Four FSK Rx Maximum Deviation 1 */
#define AX5043_FSKDMAX0              (*(__IO uint8_t  *)(0x0001C434 + SPI0_BASE)) /* Four FSK Rx Maximum Deviation 0 */
#define AX5043_FSKDMIN               (*(__IO uint16_t *)(0x0009C438 + SPI0_BASE)) /* Four FSK Rx Minimum Deviation */
#define AX5043_FSKDMIN1              (*(__IO uint8_t  *)(0x0001C438 + SPI0_BASE)) /* Four FSK Rx Minimum Deviation 1 */
#define AX5043_FSKDMIN0              (*(__IO uint8_t  *)(0x0001C43C + SPI0_BASE)) /* Four FSK Rx Minimum Deviation 0 */
#define AX5043_AFSKSPACE             (*(__IO uint16_t *)(0x0009C440 + SPI0_BASE)) /* AFSK Space (0) Frequency */
#define AX5043_AFSKSPACE1            (*(__IO uint8_t  *)(0x0001C440 + SPI0_BASE)) /* AFSK Space (0) Frequency 1 */
#define AX5043_AFSKSPACE0            (*(__IO uint8_t  *)(0x0001C444 + SPI0_BASE)) /* AFSK Space (0) Frequency 0 */
#define AX5043_AFSKMARK              (*(__IO uint16_t *)(0x0009C448 + SPI0_BASE)) /* AFSK Mark (1) Frequency */
#define AX5043_AFSKMARK1             (*(__IO uint8_t  *)(0x0001C448 + SPI0_BASE)) /* AFSK Mark (1) Frequency 1 */
#define AX5043_AFSKMARK0             (*(__IO uint8_t  *)(0x0001C44C + SPI0_BASE)) /* AFSK Mark (1) Frequency 0 */
#define AX5043_AFSKCTRL              (*(__IO uint8_t  *)(0x0001C450 + SPI0_BASE)) /* AFSK Control */
#define AX5043_AMPLFILTER            (*(__IO uint8_t  *)(0x0001C454 + SPI0_BASE)) /* Amplitude Filter */
#define AX5043_FREQUENCYLEAK         (*(__IO uint8_t  *)(0x0001C458 + SPI0_BASE)) /* Baseband Frequency Recovery Loop Leakiness */
#define AX5043_RXPARAMSETS_V1        (*(__IO uint8_t  *)(0x0001C458 + SPI0_BASE)) /* Receiver Parameter Set Indirection */
#define AX5043_RXPARAMCURSET_V1      (*(__IO uint8_t  *)(0x0001C45C + SPI0_BASE)) /* Receiver Parameter Current Set */
#define AX5043_RXPARAMSETS           (*(__IO uint8_t  *)(0x0001C45C + SPI0_BASE)) /* Receiver Parameter Set Indirection */
#define AX5043_RXPARAMCURSET         (*(__I  uint8_t  *)(0x0001C460 + SPI0_BASE)) /* Receiver Parameter Current Set */
#define AX5043_AGCGAIN0              (*(__IO uint8_t  *)(0x0001C480 + SPI0_BASE)) /* AGC Speed */
#define AX5043_AGCGAIN0_V1           (*(__IO uint8_t  *)(0x0001C480 + SPI0_BASE)) /* AGC Speed */
#define AX5043_AGCTARGET0            (*(__IO uint8_t  *)(0x0001C484 + SPI0_BASE)) /* AGC Target */
#define AX5043_AGCTARGET0_V1         (*(__IO uint8_t  *)(0x0001C484 + SPI0_BASE)) /* AGC Target */
#define AX5043_AGCAHYST0             (*(__IO uint8_t  *)(0x0001C488 + SPI0_BASE)) /* AGC Analog Hysteresis */
#define AX5043_TIMEGAIN0_V1          (*(__IO uint8_t  *)(0x0001C488 + SPI0_BASE)) /* Time Estimator Bandwidth */
#define AX5043_AGCMINMAX0            (*(__IO uint8_t  *)(0x0001C48C + SPI0_BASE)) /* AGC Analog Update Behaviour */
#define AX5043_DRGAIN0_V1            (*(__IO uint8_t  *)(0x0001C48C + SPI0_BASE)) /* Data Rate Estimator Bandwidth */
#define AX5043_PHASEGAIN0_V1         (*(__IO uint8_t  *)(0x0001C490 + SPI0_BASE)) /* Phase Estimator Bandwidth */
#define AX5043_TIMEGAIN0             (*(__IO uint8_t  *)(0x0001C490 + SPI0_BASE)) /* Time Estimator Bandwidth */
#define AX5043_DRGAIN0               (*(__IO uint8_t  *)(0x0001C494 + SPI0_BASE)) /* Data Rate Estimator Bandwidth */
#define AX5043_FREQUENCYGAINA0_V1    (*(__IO uint8_t  *)(0x0001C494 + SPI0_BASE)) /* Frequency Estimator Bandwidth A */
#define AX5043_FREQUENCYGAINB0_V1    (*(__IO uint8_t  *)(0x0001C498 + SPI0_BASE)) /* Frequency Estimator Bandwidth B */
#define AX5043_PHASEGAIN0            (*(__IO uint8_t  *)(0x0001C498 + SPI0_BASE)) /* Phase Estimator Bandwidth */
#define AX5043_FREQUENCYGAINA0       (*(__IO uint8_t  *)(0x0001C49C + SPI0_BASE)) /* Frequency Estimator Bandwidth A */
#define AX5043_FREQUENCYGAINC0_V1    (*(__IO uint8_t  *)(0x0001C49C + SPI0_BASE)) /* Frequency Estimator Bandwidth C */
#define AX5043_FREQUENCYGAINB0       (*(__IO uint8_t  *)(0x0001C4A0 + SPI0_BASE)) /* Frequency Estimator Bandwidth B */
#define AX5043_FREQUENCYGAIND0_V1    (*(__IO uint8_t  *)(0x0001C4A0 + SPI0_BASE)) /* Frequency Estimator Bandwidth D */
#define AX5043_AMPLITUDEGAIN0_V1     (*(__IO uint8_t  *)(0x0001C4A4 + SPI0_BASE)) /* Amplitude Estimator Bandwidth */
#define AX5043_FREQUENCYGAINC0       (*(__IO uint8_t  *)(0x0001C4A4 + SPI0_BASE)) /* Frequency Estimator Bandwidth C */
#define AX5043_FREQDEV10_V1          (*(__IO uint8_t  *)(0x0001C4A8 + SPI0_BASE)) /* Receiver Frequency Deviation 1 */
#define AX5043_FREQUENCYGAIND0       (*(__IO uint8_t  *)(0x0001C4A8 + SPI0_BASE)) /* Frequency Estimator Bandwidth D */
#define AX5043_AMPLITUDEGAIN0        (*(__IO uint8_t  *)(0x0001C4AC + SPI0_BASE)) /* Amplitude Estimator Bandwidth */
#define AX5043_FREQDEV00_V1          (*(__IO uint8_t  *)(0x0001C4AC + SPI0_BASE)) /* Receiver Frequency Deviation 0 */
#define AX5043_FOURFSK0_V1           (*(__IO uint8_t  *)(0x0001C4B0 + SPI0_BASE)) /* Four FSK Control */
#define AX5043_FREQDEV10             (*(__IO uint8_t  *)(0x0001C4B0 + SPI0_BASE)) /* Receiver Frequency Deviation 1 */
#define AX5043_BBOFFSRES0_V1         (*(__IO uint8_t  *)(0x0001C4B4 + SPI0_BASE)) /* Baseband Offset Compensation Resistors */
#define AX5043_FREQDEV00             (*(__IO uint8_t  *)(0x0001C4B4 + SPI0_BASE)) /* Receiver Frequency Deviation 0 */
#define AX5043_AGCGAIN1_V1           (*(__IO uint8_t  *)(0x0001C4B8 + SPI0_BASE)) /* AGC Speed */
#define AX5043_FOURFSK0              (*(__IO uint8_t  *)(0x0001C4B8 + SPI0_BASE)) /* Four FSK Control */
#define AX5043_AGCTARGET1_V1         (*(__IO uint8_t  *)(0x0001C4BC + SPI0_BASE)) /* AGC Target */
#define AX5043_BBOFFSRES0            (*(__IO uint8_t  *)(0x0001C4BC + SPI0_BASE)) /* Baseband Offset Compensation Resistors */
#define AX5043_AGCGAIN1              (*(__IO uint8_t  *)(0x0001C4C0 + SPI0_BASE)) /* AGC Speed */
#define AX5043_TIMEGAIN1_V1          (*(__IO uint8_t  *)(0x0001C4C0 + SPI0_BASE)) /* Time Estimator Bandwidth */
#define AX5043_AGCTARGET1            (*(__IO uint8_t  *)(0x0001C4C4 + SPI0_BASE)) /* AGC Target */
#define AX5043_DRGAIN1_V1            (*(__IO uint8_t  *)(0x0001C4C4 + SPI0_BASE)) /* Data Rate Estimator Bandwidth */
#define AX5043_AGCAHYST1             (*(__IO uint8_t  *)(0x0001C4C8 + SPI0_BASE)) /* AGC Analog Hysteresis */
#define AX5043_PHASEGAIN1_V1         (*(__IO uint8_t  *)(0x0001C4C8 + SPI0_BASE)) /* Phase Estimator Bandwidth */
#define AX5043_AGCMINMAX1            (*(__IO uint8_t  *)(0x0001C4CC + SPI0_BASE)) /* AGC Analog Update Behaviour */
#define AX5043_FREQUENCYGAINA1_V1    (*(__IO uint8_t  *)(0x0001C4CC + SPI0_BASE)) /* Frequency Estimator Bandwidth A */
#define AX5043_FREQUENCYGAINB1_V1    (*(__IO uint8_t  *)(0x0001C4D0 + SPI0_BASE)) /* Frequency Estimator Bandwidth B */
#define AX5043_TIMEGAIN1             (*(__IO uint8_t  *)(0x0001C4D0 + SPI0_BASE)) /* Time Estimator Bandwidth */
#define AX5043_DRGAIN1               (*(__IO uint8_t  *)(0x0001C4D4 + SPI0_BASE)) /* Data Rate Estimator Bandwidth */
#define AX5043_FREQUENCYGAINC1_V1    (*(__IO uint8_t  *)(0x0001C4D4 + SPI0_BASE)) /* Frequency Estimator Bandwidth C */
#define AX5043_FREQUENCYGAIND1_V1    (*(__IO uint8_t  *)(0x0001C4D8 + SPI0_BASE)) /* Frequency Estimator Bandwidth D */
#define AX5043_PHASEGAIN1            (*(__IO uint8_t  *)(0x0001C4D8 + SPI0_BASE)) /* Phase Estimator Bandwidth */
#define AX5043_AMPLITUDEGAIN1_V1     (*(__IO uint8_t  *)(0x0001C4DC + SPI0_BASE)) /* Amplitude Estimator Bandwidth */
#define AX5043_FREQUENCYGAINA1       (*(__IO uint8_t  *)(0x0001C4DC + SPI0_BASE)) /* Frequency Estimator Bandwidth A */
#define AX5043_FREQDEV11_V1          (*(__IO uint8_t  *)(0x0001C4E0 + SPI0_BASE)) /* Receiver Frequency Deviation 1 */
#define AX5043_FREQUENCYGAINB1       (*(__IO uint8_t  *)(0x0001C4E0 + SPI0_BASE)) /* Frequency Estimator Bandwidth B */
#define AX5043_FREQDEV01_V1          (*(__IO uint8_t  *)(0x0001C4E4 + SPI0_BASE)) /* Receiver Frequency Deviation 0 */
#define AX5043_FREQUENCYGAINC1       (*(__IO uint8_t  *)(0x0001C4E4 + SPI0_BASE)) /* Frequency Estimator Bandwidth C */
#define AX5043_FOURFSK1_V1           (*(__IO uint8_t  *)(0x0001C4E8 + SPI0_BASE)) /* Four FSK Control */
#define AX5043_FREQUENCYGAIND1       (*(__IO uint8_t  *)(0x0001C4E8 + SPI0_BASE)) /* Frequency Estimator Bandwidth D */
#define AX5043_AMPLITUDEGAIN1        (*(__IO uint8_t  *)(0x0001C4EC + SPI0_BASE)) /* Amplitude Estimator Bandwidth */
#define AX5043_BBOFFSRES1_V1         (*(__IO uint8_t  *)(0x0001C4EC + SPI0_BASE)) /* Baseband Offset Compensation Resistors */
#define AX5043_AGCGAIN2_V1           (*(__IO uint8_t  *)(0x0001C4F0 + SPI0_BASE)) /* AGC Speed */
#define AX5043_FREQDEV11             (*(__IO uint8_t  *)(0x0001C4F0 + SPI0_BASE)) /* Receiver Frequency Deviation 1 */
#define AX5043_AGCTARGET2_V1         (*(__IO uint8_t  *)(0x0001C4F4 + SPI0_BASE)) /* AGC Target */
#define AX5043_FREQDEV01             (*(__IO uint8_t  *)(0x0001C4F4 + SPI0_BASE)) /* Receiver Frequency Deviation 0 */
#define AX5043_FOURFSK1              (*(__IO uint8_t  *)(0x0001C4F8 + SPI0_BASE)) /* Four FSK Control */
#define AX5043_TIMEGAIN2_V1          (*(__IO uint8_t  *)(0x0001C4F8 + SPI0_BASE)) /* Time Estimator Bandwidth */
#define AX5043_BBOFFSRES1            (*(__IO uint8_t  *)(0x0001C4FC + SPI0_BASE)) /* Baseband Offset Compensation Resistors */
#define AX5043_DRGAIN2_V1            (*(__IO uint8_t  *)(0x0001C4FC + SPI0_BASE)) /* Data Rate Estimator Bandwidth */
#define AX5043_AGCGAIN2              (*(__IO uint8_t  *)(0x0001C500 + SPI0_BASE)) /* AGC Speed */
#define AX5043_PHASEGAIN2_V1         (*(__IO uint8_t  *)(0x0001C500 + SPI0_BASE)) /* Phase Estimator Bandwidth */
#define AX5043_AGCTARGET2            (*(__IO uint8_t  *)(0x0001C504 + SPI0_BASE)) /* AGC Target */
#define AX5043_FREQUENCYGAINA2_V1    (*(__IO uint8_t  *)(0x0001C504 + SPI0_BASE)) /* Frequency Estimator Bandwidth A */
#define AX5043_AGCAHYST2             (*(__IO uint8_t  *)(0x0001C508 + SPI0_BASE)) /* AGC Analog Hysteresis */
#define AX5043_FREQUENCYGAINB2_V1    (*(__IO uint8_t  *)(0x0001C508 + SPI0_BASE)) /* Frequency Estimator Bandwidth B */
#define AX5043_AGCMINMAX2            (*(__IO uint8_t  *)(0x0001C50C + SPI0_BASE)) /* AGC Analog Update Behaviour */
#define AX5043_FREQUENCYGAINC2_V1    (*(__IO uint8_t  *)(0x0001C50C + SPI0_BASE)) /* Frequency Estimator Bandwidth C */
#define AX5043_FREQUENCYGAIND2_V1    (*(__IO uint8_t  *)(0x0001C510 + SPI0_BASE)) /* Frequency Estimator Bandwidth D */
#define AX5043_TIMEGAIN2             (*(__IO uint8_t  *)(0x0001C510 + SPI0_BASE)) /* Time Estimator Bandwidth */
#define AX5043_AMPLITUDEGAIN2_V1     (*(__IO uint8_t  *)(0x0001C514 + SPI0_BASE)) /* Amplitude Estimator Bandwidth */
#define AX5043_DRGAIN2               (*(__IO uint8_t  *)(0x0001C514 + SPI0_BASE)) /* Data Rate Estimator Bandwidth */
#define AX5043_FREQDEV12_V1          (*(__IO uint8_t  *)(0x0001C518 + SPI0_BASE)) /* Receiver Frequency Deviation 1 */
#define AX5043_PHASEGAIN2            (*(__IO uint8_t  *)(0x0001C518 + SPI0_BASE)) /* Phase Estimator Bandwidth */
#define AX5043_FREQDEV02_V1          (*(__IO uint8_t  *)(0x0001C51C + SPI0_BASE)) /* Receiver Frequency Deviation 0 */
#define AX5043_FREQUENCYGAINA2       (*(__IO uint8_t  *)(0x0001C51C + SPI0_BASE)) /* Frequency Estimator Bandwidth A */
#define AX5043_FOURFSK2_V1           (*(__IO uint8_t  *)(0x0001C520 + SPI0_BASE)) /* Four FSK Control */
#define AX5043_FREQUENCYGAINB2       (*(__IO uint8_t  *)(0x0001C520 + SPI0_BASE)) /* Frequency Estimator Bandwidth B */
#define AX5043_BBOFFSRES2_V1         (*(__IO uint8_t  *)(0x0001C524 + SPI0_BASE)) /* Baseband Offset Compensation Resistors */
#define AX5043_FREQUENCYGAINC2       (*(__IO uint8_t  *)(0x0001C524 + SPI0_BASE)) /* Frequency Estimator Bandwidth C */
#define AX5043_AGCGAIN3_V1           (*(__IO uint8_t  *)(0x0001C528 + SPI0_BASE)) /* AGC Speed */
#define AX5043_FREQUENCYGAIND2       (*(__IO uint8_t  *)(0x0001C528 + SPI0_BASE)) /* Frequency Estimator Bandwidth D */
#define AX5043_AGCTARGET3_V1         (*(__IO uint8_t  *)(0x0001C52C + SPI0_BASE)) /* AGC Target */
#define AX5043_AMPLITUDEGAIN2        (*(__IO uint8_t  *)(0x0001C52C + SPI0_BASE)) /* Amplitude Estimator Bandwidth */
#define AX5043_FREQDEV12             (*(__IO uint8_t  *)(0x0001C530 + SPI0_BASE)) /* Receiver Frequency Deviation 1 */
#define AX5043_TIMEGAIN3_V1          (*(__IO uint8_t  *)(0x0001C530 + SPI0_BASE)) /* Time Estimator Bandwidth */
#define AX5043_DRGAIN3_V1            (*(__IO uint8_t  *)(0x0001C534 + SPI0_BASE)) /* Data Rate Estimator Bandwidth */
#define AX5043_FREQDEV02             (*(__IO uint8_t  *)(0x0001C534 + SPI0_BASE)) /* Receiver Frequency Deviation 0 */
#define AX5043_FOURFSK2              (*(__IO uint8_t  *)(0x0001C538 + SPI0_BASE)) /* Four FSK Control */
#define AX5043_PHASEGAIN3_V1         (*(__IO uint8_t  *)(0x0001C538 + SPI0_BASE)) /* Phase Estimator Bandwidth */
#define AX5043_BBOFFSRES2            (*(__IO uint8_t  *)(0x0001C53C + SPI0_BASE)) /* Baseband Offset Compensation Resistors */
#define AX5043_FREQUENCYGAINA3_V1    (*(__IO uint8_t  *)(0x0001C53C + SPI0_BASE)) /* Frequency Estimator Bandwidth A */
#define AX5043_AGCGAIN3              (*(__IO uint8_t  *)(0x0001C540 + SPI0_BASE)) /* AGC Speed */
#define AX5043_FREQUENCYGAINB3_V1    (*(__IO uint8_t  *)(0x0001C540 + SPI0_BASE)) /* Frequency Estimator Bandwidth B */
#define AX5043_AGCTARGET3            (*(__IO uint8_t  *)(0x0001C544 + SPI0_BASE)) /* AGC Target */
#define AX5043_FREQUENCYGAINC3_V1    (*(__IO uint8_t  *)(0x0001C544 + SPI0_BASE)) /* Frequency Estimator Bandwidth C */
#define AX5043_AGCAHYST3             (*(__IO uint8_t  *)(0x0001C548 + SPI0_BASE)) /* AGC Analog Hysteresis */
#define AX5043_FREQUENCYGAIND3_V1    (*(__IO uint8_t  *)(0x0001C548 + SPI0_BASE)) /* Frequency Estimator Bandwidth D */
#define AX5043_AGCMINMAX3            (*(__IO uint8_t  *)(0x0001C54C + SPI0_BASE)) /* AGC Analog Update Behaviour */
#define AX5043_AMPLITUDEGAIN3_V1     (*(__IO uint8_t  *)(0x0001C54C + SPI0_BASE)) /* Amplitude Estimator Bandwidth */
#define AX5043_FREQDEV13_V1          (*(__IO uint8_t  *)(0x0001C550 + SPI0_BASE)) /* Receiver Frequency Deviation 1 */
#define AX5043_TIMEGAIN3             (*(__IO uint8_t  *)(0x0001C550 + SPI0_BASE)) /* Time Estimator Bandwidth */
#define AX5043_DRGAIN3               (*(__IO uint8_t  *)(0x0001C554 + SPI0_BASE)) /* Data Rate Estimator Bandwidth */
#define AX5043_FREQDEV03_V1          (*(__IO uint8_t  *)(0x0001C554 + SPI0_BASE)) /* Receiver Frequency Deviation 0 */
#define AX5043_FOURFSK3_V1           (*(__IO uint8_t  *)(0x0001C558 + SPI0_BASE)) /* Four FSK Control */
#define AX5043_PHASEGAIN3            (*(__IO uint8_t  *)(0x0001C558 + SPI0_BASE)) /* Phase Estimator Bandwidth */
#define AX5043_BBOFFSRES3_V1         (*(__IO uint8_t  *)(0x0001C55C + SPI0_BASE)) /* Baseband Offset Compensation Resistors */
#define AX5043_FREQUENCYGAINA3       (*(__IO uint8_t  *)(0x0001C55C + SPI0_BASE)) /* Frequency Estimator Bandwidth A */
#define AX5043_FREQUENCYGAINB3       (*(__IO uint8_t  *)(0x0001C560 + SPI0_BASE)) /* Frequency Estimator Bandwidth B */
#define AX5043_FREQUENCYGAINC3       (*(__IO uint8_t  *)(0x0001C564 + SPI0_BASE)) /* Frequency Estimator Bandwidth C */
#define AX5043_FREQUENCYGAIND3       (*(__IO uint8_t  *)(0x0001C568 + SPI0_BASE)) /* Frequency Estimator Bandwidth D */
#define AX5043_AMPLITUDEGAIN3        (*(__IO uint8_t  *)(0x0001C56C + SPI0_BASE)) /* Amplitude Estimator Bandwidth */
#define AX5043_FREQDEV13             (*(__IO uint8_t  *)(0x0001C570 + SPI0_BASE)) /* Receiver Frequency Deviation 1 */
#define AX5043_FREQDEV03             (*(__IO uint8_t  *)(0x0001C574 + SPI0_BASE)) /* Receiver Frequency Deviation 0 */
#define AX5043_FOURFSK3              (*(__IO uint8_t  *)(0x0001C578 + SPI0_BASE)) /* Four FSK Control */
#define AX5043_BBOFFSRES3            (*(__IO uint8_t  *)(0x0001C57C + SPI0_BASE)) /* Baseband Offset Compensation Resistors */
#define AX5043_MODCFGF               (*(__IO uint8_t  *)(0x0001C580 + SPI0_BASE)) /* Modulator Configuration F */
#define AX5043_FSKDEV                (*(__IO uint32_t *)(0x0201C584 + SPI0_BASE)) /* FSK Deviation */
#define AX5043_FSKDEV2               (*(__IO uint8_t  *)(0x0001C584 + SPI0_BASE)) /* FSK Deviation 2 */
#define AX5043_FSKDEV1               (*(__IO uint8_t  *)(0x0001C588 + SPI0_BASE)) /* FSK Deviation 1 */
#define AX5043_FSKDEV0               (*(__IO uint8_t  *)(0x0001C58C + SPI0_BASE)) /* FSK Deviation 0 */
#define AX5043_MODCFGA               (*(__IO uint8_t  *)(0x0001C590 + SPI0_BASE)) /* Modulator Configuration A */
#define AX5043_TXRATE                (*(__IO uint32_t *)(0x0201C594 + SPI0_BASE)) /* Transmitter Bitrate */
#define AX5043_TXRATE2               (*(__IO uint8_t  *)(0x0001C594 + SPI0_BASE)) /* Transmitter Bitrate 2 */
#define AX5043_TXRATE1               (*(__IO uint8_t  *)(0x0001C598 + SPI0_BASE)) /* Transmitter Bitrate 1 */
#define AX5043_TXRATE0               (*(__IO uint8_t  *)(0x0001C59C + SPI0_BASE)) /* Transmitter Bitrate 0 */
#define AX5043_TXPWRCOEFFA           (*(__IO uint16_t *)(0x0009C5A0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient A */
#define AX5043_TXPWRCOEFFA1          (*(__IO uint8_t  *)(0x0001C5A0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient A 1 */
#define AX5043_TXPWRCOEFFA0          (*(__IO uint8_t  *)(0x0001C5A4 + SPI0_BASE)) /* Transmitter Predistortion Coefficient A 0 */
#define AX5043_TXPWRCOEFFB           (*(__IO uint16_t *)(0x0009C5A8 + SPI0_BASE)) /* Transmitter Predistortion Coefficient B */
#define AX5043_TXPWRCOEFFB1          (*(__IO uint8_t  *)(0x0001C5A8 + SPI0_BASE)) /* Transmitter Predistortion Coefficient B 1 */
#define AX5043_TXPWRCOEFFB0          (*(__IO uint8_t  *)(0x0001C5AC + SPI0_BASE)) /* Transmitter Predistortion Coefficient B 0 */
#define AX5043_TXPWRCOEFFC           (*(__IO uint16_t *)(0x0009C5B0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient C */
#define AX5043_TXPWRCOEFFC1          (*(__IO uint8_t  *)(0x0001C5B0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient C 1 */
#define AX5043_TXPWRCOEFFC0          (*(__IO uint8_t  *)(0x0001C5B4 + SPI0_BASE)) /* Transmitter Predistortion Coefficient C 0 */
#define AX5043_TXPWRCOEFFD           (*(__IO uint16_t *)(0x0009C5B8 + SPI0_BASE)) /* Transmitter Predistortion Coefficient D */
#define AX5043_TXPWRCOEFFD1          (*(__IO uint8_t  *)(0x0001C5B8 + SPI0_BASE)) /* Transmitter Predistortion Coefficient D 1 */
#define AX5043_TXPWRCOEFFD0          (*(__IO uint8_t  *)(0x0001C5BC + SPI0_BASE)) /* Transmitter Predistortion Coefficient D 0 */
#define AX5043_TXPWRCOEFFE           (*(__IO uint16_t *)(0x0009C5C0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient E */
#define AX5043_TXPWRCOEFFE1          (*(__IO uint8_t  *)(0x0001C5C0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient E 1 */
#define AX5043_TXPWRCOEFFE0          (*(__IO uint8_t  *)(0x0001C5C4 + SPI0_BASE)) /* Transmitter Predistortion Coefficient E 0 */
#define AX5043_PLLVCOI               (*(__IO uint8_t  *)(0x0001C600 + SPI0_BASE)) /* PLL VCO Current */
#define AX5043_PLLVCOIR              (*(__IO uint8_t  *)(0x0001C604 + SPI0_BASE)) /* PLL VCO Current Readback */
#define AX5043_PLLLOCKDET            (*(__IO uint8_t  *)(0x0001C608 + SPI0_BASE)) /* PLL Lock Detect Delay */
#define AX5043_PLLRNGCLK             (*(__IO uint8_t  *)(0x0001C60C + SPI0_BASE)) /* PLL Autoranging Clock */
#define AX5043_XTALCAP               (*(__IO uint8_t  *)(0x0001C610 + SPI0_BASE)) /* Crystal Oscillator Load Capacitance */
#define AX5043_BBTUNE                (*(__IO uint8_t  *)(0x0001C620 + SPI0_BASE)) /* Baseband Tuning */
#define AX5043_BBOFFSCAP             (*(__IO uint8_t  *)(0x0001C624 + SPI0_BASE)) /* Baseband Offset Compensation Capacitors */
#define AX5043_PKTADDRCFG            (*(__IO uint8_t  *)(0x0001C800 + SPI0_BASE)) /* Packet Address Config */
#define AX5043_PKTADDRCFG_V1         (*(__IO uint8_t  *)(0x0001C804 + SPI0_BASE)) /* Packet Address Config */
#define AX5043_PKTLENCFG             (*(__IO uint8_t  *)(0x0001C804 + SPI0_BASE)) /* Packet Length Configuration */
#define AX5043_PKTADDR1_V1           (*(__IO uint8_t  *)(0x0001C808 + SPI0_BASE)) /* Packet Address 1 */
#define AX5043_PKTLENOFFSET          (*(__IO uint8_t  *)(0x0001C808 + SPI0_BASE)) /* Packet Length Offset */
#define AX5043_PKTADDR0_V1           (*(__IO uint8_t  *)(0x0001C80C + SPI0_BASE)) /* Packet Address 0 */
#define AX5043_PKTMAXLEN             (*(__IO uint8_t  *)(0x0001C80C + SPI0_BASE)) /* Packet Maximum Length */
#define AX5043_PKTADDR               (*(__IO uint32_t *)(0x0209C810 + SPI0_BASE)) /* Packet Address */
#define AX5043_PKTADDR3              (*(__IO uint8_t  *)(0x0001C810 + SPI0_BASE)) /* Packet Address 3 */
#define AX5043_PKTADDRMASK1_V1       (*(__IO uint8_t  *)(0x0001C810 + SPI0_BASE)) /* Packet Address Mask 1 */
#define AX5043_PKTADDR2              (*(__IO uint8_t  *)(0x0001C814 + SPI0_BASE)) /* Packet Address 2 */
#define AX5043_PKTADDRMASK0_V1       (*(__IO uint8_t  *)(0x0001C814 + SPI0_BASE)) /* Packet Address Mask 0 */
#define AX5043_PKTADDR1              (*(__IO uint8_t  *)(0x0001C818 + SPI0_BASE)) /* Packet Address 1 */
#define AX5043_PKTLENCFG_V1          (*(__IO uint8_t  *)(0x0001C818 + SPI0_BASE)) /* Packet Length Configuration */
#define AX5043_PKTADDR0              (*(__IO uint8_t  *)(0x0001C81C + SPI0_BASE)) /* Packet Address 0 */
#define AX5043_PKTLENOFFSET_V1       (*(__IO uint8_t  *)(0x0001C81C + SPI0_BASE)) /* Packet Length Offset */
#define AX5043_PKTADDRMASK           (*(__IO uint32_t *)(0x0209C820 + SPI0_BASE)) /* Packet Address Mask */
#define AX5043_PKTADDRMASK3          (*(__IO uint8_t  *)(0x0001C820 + SPI0_BASE)) /* Packet Address Mask 3 */
#define AX5043_PKTMAXLEN_V1          (*(__IO uint8_t  *)(0x0001C820 + SPI0_BASE)) /* Packet Maximum Length */
#define AX5043_PKTADDRMASK2          (*(__IO uint8_t  *)(0x0001C824 + SPI0_BASE)) /* Packet Address Mask 2 */
#define AX5043_PKTADDRMASK1          (*(__IO uint8_t  *)(0x0001C828 + SPI0_BASE)) /* Packet Address Mask 1 */
#define AX5043_PKTADDRMASK0          (*(__IO uint8_t  *)(0x0001C82C + SPI0_BASE)) /* Packet Address Mask 0 */
#define AX5043_MATCH0PAT             (*(__IO uint32_t *)(0x0209C840 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern */
#define AX5043_MATCH0PAT3            (*(__IO uint8_t  *)(0x0001C840 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern 3 */
#define AX5043_MATCH0PAT2            (*(__IO uint8_t  *)(0x0001C844 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern 2 */
#define AX5043_MATCH0PAT1            (*(__IO uint8_t  *)(0x0001C848 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern 1 */
#define AX5043_MATCH0PAT0            (*(__IO uint8_t  *)(0x0001C84C + SPI0_BASE)) /* Pattern Match Unit 0, Pattern 0 */
#define AX5043_MATCH0LEN             (*(__IO uint8_t  *)(0x0001C850 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern Length */
#define AX5043_MATCH0MIN             (*(__IO uint8_t  *)(0x0001C854 + SPI0_BASE)) /* Pattern Match Unit 0, Minimum Match */
#define AX5043_MATCH0MAX             (*(__IO uint8_t  *)(0x0001C858 + SPI0_BASE)) /* Pattern Match Unit 0, Maximum Match */
#define AX5043_MATCH1PAT             (*(__IO uint16_t *)(0x0009C860 + SPI0_BASE)) /* Pattern Match Unit 1, Pattern */
#define AX5043_MATCH1PAT1            (*(__IO uint8_t  *)(0x0001C860 + SPI0_BASE)) /* Pattern Match Unit 1, Pattern 1 */
#define AX5043_MATCH1PAT0            (*(__IO uint8_t  *)(0x0001C864 + SPI0_BASE)) /* Pattern Match Unit 1, Pattern 0 */
#define AX5043_MATCH1LEN             (*(__IO uint8_t  *)(0x0001C870 + SPI0_BASE)) /* Pattern Match Unit 1, Pattern Length */
#define AX5043_MATCH1MIN             (*(__IO uint8_t  *)(0x0001C874 + SPI0_BASE)) /* Pattern Match Unit 1, Minimum Match */
#define AX5043_MATCH1MAX             (*(__IO uint8_t  *)(0x0001C878 + SPI0_BASE)) /* Pattern Match Unit 1, Maximum Match */
#define AX5043_TMGTXBOOST            (*(__IO uint8_t  *)(0x0001C880 + SPI0_BASE)) /* Transmit PLL Boost Time */
#define AX5043_TMGTXSETTLE           (*(__IO uint8_t  *)(0x0001C884 + SPI0_BASE)) /* Transmit PLL (post Boost) Settling Time */
#define AX5043_TMGRXBOOST            (*(__IO uint8_t  *)(0x0001C88C + SPI0_BASE)) /* Receive PLL Boost Time */
#define AX5043_TMGRXSETTLE           (*(__IO uint8_t  *)(0x0001C890 + SPI0_BASE)) /* Receive PLL (post Boost) Settling Time */
#define AX5043_TMGRXOFFSACQ          (*(__IO uint8_t  *)(0x0001C894 + SPI0_BASE)) /* Receive Baseband DC Offset Acquisition Time */
#define AX5043_TMGRXCOARSEAGC        (*(__IO uint8_t  *)(0x0001C898 + SPI0_BASE)) /* Receive Coarse AGC Time */
#define AX5043_TMGRXAGC              (*(__IO uint8_t  *)(0x0001C89C + SPI0_BASE)) /* Receiver AGC Settling Time */
#define AX5043_TMGRXRSSI             (*(__IO uint8_t  *)(0x0001C8A0 + SPI0_BASE)) /* Receiver RSSI Settling Time */
#define AX5043_TMGRXPREAMBLE1        (*(__IO uint8_t  *)(0x0001C8A4 + SPI0_BASE)) /* Receiver Preamble 1 Timeout */
#define AX5043_TMGRXPREAMBLE2        (*(__IO uint8_t  *)(0x0001C8A8 + SPI0_BASE)) /* Receiver Preamble 2 Timeout */
#define AX5043_TMGRXPREAMBLE3        (*(__IO uint8_t  *)(0x0001C8AC + SPI0_BASE)) /* Receiver Preamble 3 Timeout */
#define AX5043_RSSIREFERENCE         (*(__IO uint8_t  *)(0x0001C8B0 + SPI0_BASE)) /* RSSI Offset */
#define AX5043_RSSIABSTHR            (*(__IO uint8_t  *)(0x0001C8B4 + SPI0_BASE)) /* RSSI Absolute Threshold */
#define AX5043_BGNDRSSIGAIN          (*(__IO uint8_t  *)(0x0001C8B8 + SPI0_BASE)) /* Background RSSI Averaging Time Constant */
#define AX5043_BGNDRSSITHR           (*(__IO uint8_t  *)(0x0001C8BC + SPI0_BASE)) /* Background RSSI Relative Threshold */
#define AX5043_PKTCHUNKSIZE          (*(__IO uint8_t  *)(0x0001C8C0 + SPI0_BASE)) /* Packet Chunk Size */
#define AX5043_PKTMISCFLAGS          (*(__IO uint8_t  *)(0x0001C8C4 + SPI0_BASE)) /* Packet Controller Miscellaneous Flags */
#define AX5043_PKTSTOREFLAGS         (*(__IO uint8_t  *)(0x0001C8C8 + SPI0_BASE)) /* Packet Controller Store Flags */
#define AX5043_PKTACCEPTFLAGS        (*(__IO uint8_t  *)(0x0001C8CC + SPI0_BASE)) /* Packet Controller Accept Flags */
#define AX5043_GPADCCTRL             (*(__IO uint8_t  *)(0x0001CC00 + SPI0_BASE)) /* General Purpose ADC Control */
#define AX5043_GPADCPERIOD           (*(__IO uint8_t  *)(0x0001CC04 + SPI0_BASE)) /* GPADC Sampling Period */
#define AX5043_GPADC13VALUE          (*(__I  uint16_t *)(0x0009CC20 + SPI0_BASE)) /* GPADC13 Value */
#define AX5043_GPADC13VALUE1         (*(__I  uint8_t  *)(0x0001CC20 + SPI0_BASE)) /* GPADC13 Value 1 */
#define AX5043_GPADC13VALUE0         (*(__I  uint8_t  *)(0x0001CC24 + SPI0_BASE)) /* GPADC13 Value 0 */
#define AX5043_LPOSCCONFIG           (*(__IO uint8_t  *)(0x0001CC40 + SPI0_BASE)) /* Low Power Oscillator Calibration Configuration */
#define AX5043_LPOSCSTATUS           (*(__I  uint8_t  *)(0x0001CC44 + SPI0_BASE)) /* Low Power Oscillator Calibration Status */
#define AX5043_LPOSCKFILT            (*(__IO uint16_t *)(0x0009CC48 + SPI0_BASE))
#define AX5043_LPOSCKFILT1           (*(__IO uint8_t  *)(0x0001CC48 + SPI0_BASE)) /* Low Power Oscillator Calibration Filter Constant High Byte */
#define AX5043_LPOSCKFILT0           (*(__IO uint8_t  *)(0x0001CC4C + SPI0_BASE)) /* Low Power Oscillator Calibration Filter Constant Low Byte */
#define AX5043_LPOSCREF              (*(__IO uint16_t *)(0x0009CC50 + SPI0_BASE))
#define AX5043_LPOSCREF1             (*(__IO uint8_t  *)(0x0001CC50 + SPI0_BASE)) /* Low Power Oscillator Reference Frequency High Byte */
#define AX5043_LPOSCREF0             (*(__IO uint8_t  *)(0x0001CC54 + SPI0_BASE)) /* Low Power Oscillator Reference Frequency Low Byte */
#define AX5043_LPOSCFREQ             (*(__IO uint16_t *)(0x0009CC58 + SPI0_BASE))
#define AX5043_LPOSCFREQ1            (*(__IO uint8_t  *)(0x0001CC58 + SPI0_BASE)) /* Low Power Oscillator Frequency Tuning High Byte */
#define AX5043_LPOSCFREQ0            (*(__IO uint8_t  *)(0x0001CC5C + SPI0_BASE)) /* Low Power Oscillator Frequency Tuning Low Byte */
#define AX5043_LPOSCPER              (*(__IO uint16_t *)(0x0009CC60 + SPI0_BASE))
#define AX5043_LPOSCPER1             (*(__IO uint8_t  *)(0x0001CC60 + SPI0_BASE)) /* Low Power Oscillator Period High Byte */
#define AX5043_LPOSCPER0             (*(__IO uint8_t  *)(0x0001CC64 + SPI0_BASE)) /* Low Power Oscillator Period Low Byte */
#define AX5043_DACVALUE              (*(__IO uint16_t *)(0x0009CCC0 + SPI0_BASE)) /* DAC Value */
#define AX5043_DACVALUE1             (*(__IO uint8_t  *)(0x0001CCC0 + SPI0_BASE)) /* DAC Value 1 */
#define AX5043_DACVALUE0             (*(__IO uint8_t  *)(0x0001CCC4 + SPI0_BASE)) /* DAC Value 0 */
#define AX5043_DACCONFIG             (*(__IO uint8_t  *)(0x0001CCC8 + SPI0_BASE)) /* DAC Configuration */
#define AX5043_0xF00                 (*(__IO uint8_t  *)(0x0001FC00 + SPI0_BASE))
#define AX5043_POWCTRL1              (*(__IO uint8_t  *)(0x0001FC20 + SPI0_BASE)) /* Power Control 1 */
#define AX5043_0xF0C                 (*(__IO uint8_t  *)(0x0001FC30 + SPI0_BASE))
#define AX5043_REF                   (*(__IO uint8_t  *)(0x0001FC34 + SPI0_BASE)) /* Reference */
#define AX5043_XTALOSC               (*(__IO uint8_t  *)(0x0001FC40 + SPI0_BASE)) /* Crystal Oscillator Control */
#define AX5043_XTALAMPL              (*(__IO uint8_t  *)(0x0001FC44 + SPI0_BASE)) /* Crystal Oscillator Amplitude Control */
#define AX5043_0xF18                 (*(__IO uint8_t  *)(0x0001FC60 + SPI0_BASE))
#define AX5043_0xF1C                 (*(__IO uint8_t  *)(0x0001FC70 + SPI0_BASE))
#define AX5043_0xF21                 (*(__IO uint8_t  *)(0x0001FC84 + SPI0_BASE))
#define AX5043_0xF22                 (*(__IO uint8_t  *)(0x0001FC88 + SPI0_BASE))
#define AX5043_0xF23                 (*(__IO uint8_t  *)(0x0001FC8C + SPI0_BASE))
#define AX5043_0xF26                 (*(__IO uint8_t  *)(0x0001FC98 + SPI0_BASE))
#define AX5043_0xF30                 (*(__IO uint8_t  *)(0x0001FCC0 + SPI0_BASE))
#define AX5043_0xF31                 (*(__IO uint8_t  *)(0x0001FCC4 + SPI0_BASE))
#define AX5043_0xF32                 (*(__IO uint8_t  *)(0x0001FCC8 + SPI0_BASE))
#define AX5043_0xF33                 (*(__IO uint8_t  *)(0x0001FCCC + SPI0_BASE))
#define AX5043_0xF34                 (*(__IO uint8_t  *)(0x0001FCD0 + SPI0_BASE))
#define AX5043_0xF35                 (*(__IO uint8_t  *)(0x0001FCD4 + SPI0_BASE))
#define AX5043_0xF44                 (*(__IO uint8_t  *)(0x0001FD10 + SPI0_BASE))
#define AX5043_MODCFGP               (*(__IO uint8_t  *)(0x0001FD7C + SPI0_BASE)) /* Modulator Configuration P */
#define AX5043_SILICONREVISIONNB     (*(__I  uint8_t  *)(0x00060000 + SPI0_BASE)) /* Silicon Revision, non-blocking */
#define AX5043_SCRATCHNB             (*(__IO uint8_t  *)(0x00060004 + SPI0_BASE)) /* Scratch, non-blocking */
#define AX5043_PWRMODENB             (*(__IO uint8_t  *)(0x00060008 + SPI0_BASE)) /* Power Mode, non-blocking */
#define AX5043_POWSTATNB             (*(__I  uint8_t  *)(0x0006000C + SPI0_BASE)) /* Power Management Status, non-blocking */
#define AX5043_POWSTICKYSTATNB       (*(__I  uint8_t  *)(0x00060010 + SPI0_BASE)) /* Power Management Sticky Status, non-blocking */
#define AX5043_POWIRQMASKNB          (*(__IO uint8_t  *)(0x00060014 + SPI0_BASE)) /* Power Management Interrupt Mask, non-blocking */
#define AX5043_IRQMASKNB             (*(__IO uint16_t *)(0x000E0018 + SPI0_BASE)) /* IRQ Mask, non-blocking */
#define AX5043_IRQMASK1NB            (*(__IO uint8_t  *)(0x00060018 + SPI0_BASE)) /* IRQ Mask 1, non-blocking */
#define AX5043_IRQMASK0NB            (*(__IO uint8_t  *)(0x0006001C + SPI0_BASE)) /* IRQ Mask 0, non-blocking */
#define AX5043_RADIOEVENTMASKNB      (*(__IO uint16_t *)(0x000E0020 + SPI0_BASE)) /* Radio Event Mask, non-blocking */
#define AX5043_RADIOEVENTMASK1NB     (*(__IO uint8_t  *)(0x00060020 + SPI0_BASE)) /* Radio Event Mask 1, non-blocking */
#define AX5043_RADIOEVENTMASK0NB     (*(__IO uint8_t  *)(0x00060024 + SPI0_BASE)) /* Radio Event Mask 0, non-blocking */
#define AX5043_IRQINVERSIONNB        (*(__IO uint16_t *)(0x000E0028 + SPI0_BASE)) /* IRQ Inversion, non-blocking */
#define AX5043_IRQINVERSION1NB       (*(__IO uint8_t  *)(0x00060028 + SPI0_BASE)) /* IRQ Inversion 1, non-blocking */
#define AX5043_IRQINVERSION0NB       (*(__IO uint8_t  *)(0x0006002C + SPI0_BASE)) /* IRQ Inversion 0, non-blocking */
#define AX5043_IRQREQUESTNB          (*(__I  uint16_t *)(0x000E0030 + SPI0_BASE)) /* IRQ Request, non-blocking */
#define AX5043_IRQREQUEST1NB         (*(__I  uint8_t  *)(0x00060030 + SPI0_BASE)) /* IRQ Request 1, non-blocking */
#define AX5043_IRQREQUEST0NB         (*(__I  uint8_t  *)(0x00060034 + SPI0_BASE)) /* IRQ Request 0, non-blocking */
#define AX5043_RADIOEVENTREQNB       (*(__I  uint16_t *)(0x000E0038 + SPI0_BASE)) /* Radio Event Request, non-blocking */
#define AX5043_RADIOEVENTREQ1NB      (*(__I  uint8_t  *)(0x00060038 + SPI0_BASE)) /* Radio Event Request 1, non-blocking */
#define AX5043_RADIOEVENTREQ0NB      (*(__I  uint8_t  *)(0x0006003C + SPI0_BASE)) /* Radio Event Request 0, non-blocking */
#define AX5043_MODULATIONNB          (*(__IO uint8_t  *)(0x00060040 + SPI0_BASE)) /* Modulation, non-blocking */
#define AX5043_ENCODINGNB            (*(__IO uint8_t  *)(0x00060044 + SPI0_BASE)) /* Encoding, non-blocking */
#define AX5043_FRAMINGNB             (*(__IO uint8_t  *)(0x00060048 + SPI0_BASE)) /* Framing Mode, non-blocking */
#define AX5043_CRCINITNB             (*(__IO uint32_t *)(0x020E0050 + SPI0_BASE)) /* CRC Initial Value, non-blocking */
#define AX5043_CRCINIT3NB            (*(__IO uint8_t  *)(0x00060050 + SPI0_BASE)) /* CRC Initial Value 3, non-blocking */
#define AX5043_CRCINIT2NB            (*(__IO uint8_t  *)(0x00060054 + SPI0_BASE)) /* CRC Initial Value 2, non-blocking */
#define AX5043_CRCINIT1NB            (*(__IO uint8_t  *)(0x00060058 + SPI0_BASE)) /* CRC Initial Value 1, non-blocking */
#define AX5043_CRCINIT0NB            (*(__IO uint8_t  *)(0x0006005C + SPI0_BASE)) /* CRC Initial Value 0, non-blocking */
#define AX5043_FECNB                 (*(__IO uint8_t  *)(0x00060060 + SPI0_BASE)) /* Forward Error Correction, non-blocking */
#define AX5043_FECSYNCNB             (*(__IO uint8_t  *)(0x00060064 + SPI0_BASE)) /* Forward Error Correction Sync Threshold, non-blocking */
#define AX5043_FECSTATUSNB           (*(__I  uint8_t  *)(0x00060068 + SPI0_BASE)) /* Forward Error Correction Status, non-blocking */
#define AX5043_RADIOSTATENB          (*(__I  uint8_t  *)(0x00060070 + SPI0_BASE)) /* Radio Controller State, non-blocking */
#define AX5043_XTALSTATUSNB          (*(__I  uint8_t  *)(0x00060074 + SPI0_BASE)) /* Crystal Oscillator Status, non-blocking */
#define AX5043_PINSTATENB            (*(__I  uint8_t  *)(0x00060080 + SPI0_BASE)) /* Pin State, non-blocking */
#define AX5043_PINFUNCSYSCLKNB       (*(__IO uint8_t  *)(0x00060084 + SPI0_BASE)) /* Pin Function SYSCLK, non-blocking */
#define AX5043_PINFUNCDCLKNB         (*(__IO uint8_t  *)(0x00060088 + SPI0_BASE)) /* Pin Function DCLK, non-blocking */
#define AX5043_PINFUNCDATANB         (*(__IO uint8_t  *)(0x0006008C + SPI0_BASE)) /* Pin Function DATA, non-blocking */
#define AX5043_PINFUNCIRQNB          (*(__IO uint8_t  *)(0x00060090 + SPI0_BASE)) /* Pin Function IRQ, non-blocking */
#define AX5043_PINFUNCANTSELNB       (*(__IO uint8_t  *)(0x00060094 + SPI0_BASE)) /* Pin Function ANTSEL, non-blocking */
#define AX5043_PINFUNCPWRAMPNB       (*(__IO uint8_t  *)(0x00060098 + SPI0_BASE)) /* Pin Function PWRAMP, non-blocking */
#define AX5043_PWRAMPNB              (*(__IO uint8_t  *)(0x0006009C + SPI0_BASE)) /* PWRAMP Control, non-blocking */
#define AX5043_FIFOSTATNB            (*(__IO uint8_t  *)(0x000600A0 + SPI0_BASE)) /* FIFO Control, non-blocking */
#define AX5043_FIFODATANB            (*(__IO uint8_t  *)(0x000600A4 + SPI0_BASE)) /* FIFO Data, non-blocking */
#define AX5043_FIFOCOUNTNB           (*(__I  uint16_t *)(0x000E00A8 + SPI0_BASE)) /* Number of Words currently in FIFO, non-blocking */
#define AX5043_FIFOCOUNT1NB          (*(__I  uint8_t  *)(0x000600A8 + SPI0_BASE)) /* Number of Words currently in FIFO 1, non-blocking */
#define AX5043_FIFOCOUNT0NB          (*(__I  uint8_t  *)(0x000600AC + SPI0_BASE)) /* Number of Words currently in FIFO 0, non-blocking */
#define AX5043_FIFOFREENB            (*(__I  uint16_t *)(0x000E00B0 + SPI0_BASE)) /* Number of Words that can be written to FIFO, non-blocking */
#define AX5043_FIFOFREE1NB           (*(__I  uint8_t  *)(0x000600B0 + SPI0_BASE)) /* Number of Words that can be written to FIFO 1, non-blocking */
#define AX5043_FIFOFREE0NB           (*(__I  uint8_t  *)(0x000600B4 + SPI0_BASE)) /* Number of Words that can be written to FIFO 0, non-blocking */
#define AX5043_FIFOTHRESHNB          (*(__IO uint16_t *)(0x000E00B8 + SPI0_BASE)) /* FIFO Threshold, non-blocking */
#define AX5043_FIFOTHRESH1NB         (*(__IO uint8_t  *)(0x000600B8 + SPI0_BASE)) /* FIFO Threshold 1, non-blocking */
#define AX5043_FIFOTHRESH0NB         (*(__IO uint8_t  *)(0x000600BC + SPI0_BASE)) /* FIFO Threshold 0, non-blocking */
#define AX5043_PLLLOOPNB             (*(__IO uint8_t  *)(0x000600C0 + SPI0_BASE)) /* PLL Loop Filter Settings, non-blocking */
#define AX5043_PLLCPINB              (*(__IO uint8_t  *)(0x000600C4 + SPI0_BASE)) /* PLL Charge Pump Current, non-blocking */
#define AX5043_PLLVCODIVNB           (*(__IO uint8_t  *)(0x000600C8 + SPI0_BASE)) /* PLL Divider Settings, non-blocking */
#define AX5043_PLLRANGINGANB         (*(__IO uint8_t  *)(0x000600CC + SPI0_BASE)) /* PLL Autoranging A, non-blocking */
#define AX5043_FREQANB               (*(__IO uint32_t *)(0x020E00D0 + SPI0_BASE)) /* Frequency A, non-blocking */
#define AX5043_FREQA3NB              (*(__IO uint8_t  *)(0x000600D0 + SPI0_BASE)) /* Frequency A 3, non-blocking */
#define AX5043_FREQA2NB              (*(__IO uint8_t  *)(0x000600D4 + SPI0_BASE)) /* Frequency A 2, non-blocking */
#define AX5043_FREQA1NB              (*(__IO uint8_t  *)(0x000600D8 + SPI0_BASE)) /* Frequency A 1, non-blocking */
#define AX5043_FREQA0NB              (*(__IO uint8_t  *)(0x000600DC + SPI0_BASE)) /* Frequency A 0, non-blocking */
#define AX5043_PLLLOOPBOOSTNB        (*(__IO uint8_t  *)(0x000600E0 + SPI0_BASE)) /* PLL Loop Filter Settings (Boosted), non-blocking */
#define AX5043_PLLCPIBOOSTNB         (*(__IO uint8_t  *)(0x000600E4 + SPI0_BASE)) /* PLL Charge Pump Current (Boosted), non-blocking */
#define AX5043_PLLRANGINGBNB         (*(__IO uint8_t  *)(0x000600EC + SPI0_BASE)) /* PLL Autoranging B, non-blocking */
#define AX5043_FREQBNB               (*(__IO uint32_t *)(0x020E00F0 + SPI0_BASE)) /* Frequency B, non-blocking */
#define AX5043_FREQB3NB              (*(__IO uint8_t  *)(0x000600F0 + SPI0_BASE)) /* Frequency B 3, non-blocking */
#define AX5043_FREQB2NB              (*(__IO uint8_t  *)(0x000600F4 + SPI0_BASE)) /* Frequency B 2, non-blocking */
#define AX5043_FREQB1NB              (*(__IO uint8_t  *)(0x000600F8 + SPI0_BASE)) /* Frequency B 1, non-blocking */
#define AX5043_FREQB0NB              (*(__IO uint8_t  *)(0x000600FC + SPI0_BASE)) /* Frequency B 0, non-blocking */
#define AX5043_RSSINB                (*(__I  uint8_t  *)(0x00060100 + SPI0_BASE)) /* Received Signal Strength Indicator, non-blocking */
#define AX5043_BGNDRSSINB            (*(__IO uint8_t  *)(0x00060104 + SPI0_BASE)) /* Background RSSI, non-blocking */
#define AX5043_DIVERSITYNB           (*(__IO uint8_t  *)(0x00060108 + SPI0_BASE)) /* Antenna Diversity Configuration, non-blocking */
#define AX5043_AGCCOUNTERNB          (*(__IO uint8_t  *)(0x0006010C + SPI0_BASE)) /* AGC Counter, non-blocking */
#define AX5043_TRKDATARATENB         (*(__I  uint32_t *)(0x02060114 + SPI0_BASE)) /* Datarate Tracking, non-blocking */
#define AX5043_TRKDATARATE2NB        (*(__I  uint8_t  *)(0x00060114 + SPI0_BASE)) /* Datarate Tracking 2, non-blocking */
#define AX5043_TRKDATARATE1NB        (*(__I  uint8_t  *)(0x00060118 + SPI0_BASE)) /* Datarate Tracking 1, non-blocking */
#define AX5043_TRKDATARATE0NB        (*(__I  uint8_t  *)(0x0006011C + SPI0_BASE)) /* Datarate Tracking 0, non-blocking */
#define AX5043_TRKAMPLITUDENB        (*(__I  uint16_t *)(0x000E0120 + SPI0_BASE)) /* Amplitude Tracking, non-blocking */
#define AX5043_TRKAMPLITUDE1NB       (*(__I  uint8_t  *)(0x00060120 + SPI0_BASE)) /* Amplitude Tracking 1, non-blocking */
#define AX5043_TRKAMPLITUDE0NB       (*(__I  uint8_t  *)(0x00060124 + SPI0_BASE)) /* Amplitude Tracking 0, non-blocking */
#define AX5043_TRKPHASENB            (*(__I  uint16_t *)(0x000E0128 + SPI0_BASE)) /* Phase Tracking, non-blocking */
#define AX5043_TRKPHASE1NB           (*(__I  uint8_t  *)(0x00060128 + SPI0_BASE)) /* Phase Tracking 1, non-blocking */
#define AX5043_TRKPHASE0NB           (*(__I  uint8_t  *)(0x0006012C + SPI0_BASE)) /* Phase Tracking 0, non-blocking */
#define AX5043_TRKRFFREQNB           (*(__IO uint32_t *)(0x02060134 + SPI0_BASE)) /* RF Frequency Tracking, non-blocking */
#define AX5043_TRKRFFREQ2NB          (*(__IO uint8_t  *)(0x00060134 + SPI0_BASE)) /* RF Frequency Tracking 2, non-blocking */
#define AX5043_TRKRFFREQ1NB          (*(__IO uint8_t  *)(0x00060138 + SPI0_BASE)) /* RF Frequency Tracking 1, non-blocking */
#define AX5043_TRKRFFREQ0NB          (*(__IO uint8_t  *)(0x0006013C + SPI0_BASE)) /* RF Frequency Tracking 0, non-blocking */
#define AX5043_TRKFREQNB             (*(__IO uint16_t *)(0x000E0140 + SPI0_BASE)) /* Frequency Tracking, non-blocking */
#define AX5043_TRKFREQ1NB            (*(__IO uint8_t  *)(0x00060140 + SPI0_BASE)) /* Frequency Tracking 1, non-blocking */
#define AX5043_TRKFREQ0NB            (*(__IO uint8_t  *)(0x00060144 + SPI0_BASE)) /* Frequency Tracking 0, non-blocking */
#define AX5043_TRKFSKDEMODNB         (*(__I  uint16_t *)(0x000E0148 + SPI0_BASE)) /* FSK Demodulator Tracking, non-blocking */
#define AX5043_TRKFSKDEMOD1NB        (*(__I  uint8_t  *)(0x00060148 + SPI0_BASE)) /* FSK Demodulator Tracking 1, non-blocking */
#define AX5043_TRKFSKDEMOD0NB        (*(__I  uint8_t  *)(0x0006014C + SPI0_BASE)) /* FSK Demodulator Tracking 0, non-blocking */
#define AX5043_TRKAFSKDEMODNB        (*(__I  uint16_t *)(0x000E0150 + SPI0_BASE)) /* AFSK Demodulator Tracking, non-blocking */
#define AX5043_TRKAFSKDEMOD1NB       (*(__I  uint8_t  *)(0x00060150 + SPI0_BASE)) /* AFSK Demodulator Tracking 1, non-blocking */
#define AX5043_TRKAFSKDEMOD0NB       (*(__I  uint8_t  *)(0x00060154 + SPI0_BASE)) /* AFSK Demodulator Tracking 0, non-blocking */
#define AX5043_TIMERNB               (*(__I  uint32_t *)(0x02060164 + SPI0_BASE)) /* 1MHz Timer, non-blocking */
#define AX5043_TIMER2NB              (*(__I  uint8_t  *)(0x00060164 + SPI0_BASE)) /* 1MHz Timer 2, non-blocking */
#define AX5043_TIMER1NB              (*(__I  uint8_t  *)(0x00060168 + SPI0_BASE)) /* 1MHz Timer 1, non-blocking */
#define AX5043_TIMER0NB              (*(__I  uint8_t  *)(0x0006016C + SPI0_BASE)) /* 1MHz Timer 0, non-blocking */
#define AX5043_WAKEUPTIMERNB         (*(__I  uint16_t *)(0x000E01A0 + SPI0_BASE)) /* Wakeup Timer, non-blocking */
#define AX5043_WAKEUPTIMER1NB        (*(__I  uint8_t  *)(0x000601A0 + SPI0_BASE)) /* Wakeup Timer 1, non-blocking */
#define AX5043_WAKEUPTIMER0NB        (*(__I  uint8_t  *)(0x000601A4 + SPI0_BASE)) /* Wakeup Timer 0, non-blocking */
#define AX5043_WAKEUPNB              (*(__IO uint16_t *)(0x000E01A8 + SPI0_BASE)) /* Wakeup Time, non-blocking */
#define AX5043_WAKEUP1NB             (*(__IO uint8_t  *)(0x000601A8 + SPI0_BASE)) /* Wakeup Time 1, non-blocking */
#define AX5043_WAKEUP0NB             (*(__IO uint8_t  *)(0x000601AC + SPI0_BASE)) /* Wakeup Time 0, non-blocking */
#define AX5043_WAKEUPFREQNB          (*(__IO uint16_t *)(0x000E01B0 + SPI0_BASE)) /* Wakeup Frequency, non-blocking */
#define AX5043_WAKEUPFREQ1NB         (*(__IO uint8_t  *)(0x000601B0 + SPI0_BASE)) /* Wakeup Frequency 1, non-blocking */
#define AX5043_WAKEUPFREQ0NB         (*(__IO uint8_t  *)(0x000601B4 + SPI0_BASE)) /* Wakeup Frequency 0, non-blocking */
#define AX5043_WAKEUPXOEARLYNB       (*(__IO uint8_t  *)(0x000601B8 + SPI0_BASE)) /* Wakeup Crystal Oscillator Early, non-blocking */
#define AX5043_IFFREQNB              (*(__IO uint16_t *)(0x000DC400 + SPI0_BASE)) /* 2nd LO / IF Frequency, non-blocking */
#define AX5043_IFFREQ1NB             (*(__IO uint8_t  *)(0x0005C400 + SPI0_BASE)) /* 2nd LO / IF Frequency 1, non-blocking */
#define AX5043_IFFREQ0NB             (*(__IO uint8_t  *)(0x0005C404 + SPI0_BASE)) /* 2nd LO / IF Frequency 0, non-blocking */
#define AX5043_DECIMATIONNB          (*(__IO uint8_t  *)(0x0005C408 + SPI0_BASE)) /* Decimation Factor, non-blocking */
#define AX5043_RXDATARATENB          (*(__IO uint32_t *)(0x0205C40C + SPI0_BASE)) /* Receiver Datarate, non-blocking */
#define AX5043_RXDATARATE2NB         (*(__IO uint8_t  *)(0x0005C40C + SPI0_BASE)) /* Receiver Datarate 2, non-blocking */
#define AX5043_RXDATARATE1NB         (*(__IO uint8_t  *)(0x0005C410 + SPI0_BASE)) /* Receiver Datarate 1, non-blocking */
#define AX5043_RXDATARATE0NB         (*(__IO uint8_t  *)(0x0005C414 + SPI0_BASE)) /* Receiver Datarate 0, non-blocking */
#define AX5043_MAXDROFFSETNB         (*(__IO uint32_t *)(0x0205C418 + SPI0_BASE)) /* Maximum Receiver Datarate Offset, non-blocking */
#define AX5043_MAXDROFFSET2NB        (*(__IO uint8_t  *)(0x0005C418 + SPI0_BASE)) /* Maximum Receiver Datarate Offset 2, non-blocking */
#define AX5043_MAXDROFFSET1NB        (*(__IO uint8_t  *)(0x0005C41C + SPI0_BASE)) /* Maximum Receiver Datarate Offset 1, non-blocking */
#define AX5043_MAXDROFFSET0NB        (*(__IO uint8_t  *)(0x0005C420 + SPI0_BASE)) /* Maximum Receiver Datarate Offset 0, non-blocking */
#define AX5043_MAXRFOFFSETNB         (*(__IO uint32_t *)(0x0205C424 + SPI0_BASE)) /* Maximum Receiver RF Offset, non-blocking */
#define AX5043_MAXRFOFFSET2NB        (*(__IO uint8_t  *)(0x0005C424 + SPI0_BASE)) /* Maximum Receiver RF Offset 2, non-blocking */
#define AX5043_MAXRFOFFSET1NB        (*(__IO uint8_t  *)(0x0005C428 + SPI0_BASE)) /* Maximum Receiver RF Offset 1, non-blocking */
#define AX5043_MAXRFOFFSET0NB        (*(__IO uint8_t  *)(0x0005C42C + SPI0_BASE)) /* Maximum Receiver RF Offset 0, non-blocking */
#define AX5043_FSKDMAXNB             (*(__IO uint16_t *)(0x000DC430 + SPI0_BASE)) /* Four FSK Rx Maximum Deviation, non-blocking */
#define AX5043_FSKDMAX1NB            (*(__IO uint8_t  *)(0x0005C430 + SPI0_BASE)) /* Four FSK Rx Maximum Deviation 1, non-blocking */
#define AX5043_FSKDMAX0NB            (*(__IO uint8_t  *)(0x0005C434 + SPI0_BASE)) /* Four FSK Rx Maximum Deviation 0, non-blocking */
#define AX5043_FSKDMINNB             (*(__IO uint16_t *)(0x000DC438 + SPI0_BASE)) /* Four FSK Rx Minimum Deviation, non-blocking */
#define AX5043_FSKDMIN1NB            (*(__IO uint8_t  *)(0x0005C438 + SPI0_BASE)) /* Four FSK Rx Minimum Deviation 1, non-blocking */
#define AX5043_FSKDMIN0NB            (*(__IO uint8_t  *)(0x0005C43C + SPI0_BASE)) /* Four FSK Rx Minimum Deviation 0, non-blocking */
#define AX5043_AFSKSPACENB           (*(__IO uint16_t *)(0x000DC440 + SPI0_BASE)) /* AFSK Space (0) Frequency, non-blocking */
#define AX5043_AFSKSPACE1NB          (*(__IO uint8_t  *)(0x0005C440 + SPI0_BASE)) /* AFSK Space (0) Frequency 1, non-blocking */
#define AX5043_AFSKSPACE0NB          (*(__IO uint8_t  *)(0x0005C444 + SPI0_BASE)) /* AFSK Space (0) Frequency 0, non-blocking */
#define AX5043_AFSKMARKNB            (*(__IO uint16_t *)(0x000DC448 + SPI0_BASE)) /* AFSK Mark (1) Frequency, non-blocking */
#define AX5043_AFSKMARK1NB           (*(__IO uint8_t  *)(0x0005C448 + SPI0_BASE)) /* AFSK Mark (1) Frequency 1, non-blocking */
#define AX5043_AFSKMARK0NB           (*(__IO uint8_t  *)(0x0005C44C + SPI0_BASE)) /* AFSK Mark (1) Frequency 0, non-blocking */
#define AX5043_AFSKCTRLNB            (*(__IO uint8_t  *)(0x0005C450 + SPI0_BASE)) /* AFSK Control, non-blocking */
#define AX5043_AMPLFILTERNB          (*(__IO uint8_t  *)(0x0005C454 + SPI0_BASE)) /* Amplitude Filter, non-blocking */
#define AX5043_FREQUENCYLEAKNB       (*(__IO uint8_t  *)(0x0005C458 + SPI0_BASE)) /* Baseband Frequency Recovery Loop Leakiness, non-blocking */
#define AX5043_RXPARAMSETS_V1NB      (*(__IO uint8_t  *)(0x0005C458 + SPI0_BASE)) /* Receiver Parameter Set Indirection, non-blocking */
#define AX5043_RXPARAMCURSET_V1NB    (*(__IO uint8_t  *)(0x0005C45C + SPI0_BASE)) /* Receiver Parameter Current Set, non-blocking */
#define AX5043_RXPARAMSETSNB         (*(__IO uint8_t  *)(0x0005C45C + SPI0_BASE)) /* Receiver Parameter Set Indirection, non-blocking */
#define AX5043_RXPARAMCURSETNB       (*(__I  uint8_t  *)(0x0005C460 + SPI0_BASE)) /* Receiver Parameter Current Set, non-blocking */
#define AX5043_AGCGAIN0NB            (*(__IO uint8_t  *)(0x0005C480 + SPI0_BASE)) /* AGC Speed, non-blocking */
#define AX5043_AGCGAIN0_V1NB         (*(__IO uint8_t  *)(0x0005C480 + SPI0_BASE)) /* AGC Speed, non-blocking */
#define AX5043_AGCTARGET0NB          (*(__IO uint8_t  *)(0x0005C484 + SPI0_BASE)) /* AGC Target, non-blocking */
#define AX5043_AGCTARGET0_V1NB       (*(__IO uint8_t  *)(0x0005C484 + SPI0_BASE)) /* AGC Target, non-blocking */
#define AX5043_AGCAHYST0NB           (*(__IO uint8_t  *)(0x0005C488 + SPI0_BASE)) /* AGC Analog Hysteresis, non-blocking */
#define AX5043_TIMEGAIN0_V1NB        (*(__IO uint8_t  *)(0x0005C488 + SPI0_BASE)) /* Time Estimator Bandwidth, non-blocking */
#define AX5043_AGCMINMAX0NB          (*(__IO uint8_t  *)(0x0005C48C + SPI0_BASE)) /* AGC Analog Update Behaviour, non-blocking */
#define AX5043_DRGAIN0_V1NB          (*(__IO uint8_t  *)(0x0005C48C + SPI0_BASE)) /* Data Rate Estimator Bandwidth, non-blocking */
#define AX5043_PHASEGAIN0_V1NB       (*(__IO uint8_t  *)(0x0005C490 + SPI0_BASE)) /* Phase Estimator Bandwidth, non-blocking */
#define AX5043_TIMEGAIN0NB           (*(__IO uint8_t  *)(0x0005C490 + SPI0_BASE)) /* Time Estimator Bandwidth, non-blocking */
#define AX5043_DRGAIN0NB             (*(__IO uint8_t  *)(0x0005C494 + SPI0_BASE)) /* Data Rate Estimator Bandwidth, non-blocking */
#define AX5043_FREQUENCYGAINA0_V1NB  (*(__IO uint8_t  *)(0x0005C494 + SPI0_BASE)) /* Frequency Estimator Bandwidth A, non-blocking */
#define AX5043_FREQUENCYGAINB0_V1NB  (*(__IO uint8_t  *)(0x0005C498 + SPI0_BASE)) /* Frequency Estimator Bandwidth B, non-blocking */
#define AX5043_PHASEGAIN0NB          (*(__IO uint8_t  *)(0x0005C498 + SPI0_BASE)) /* Phase Estimator Bandwidth, non-blocking */
#define AX5043_FREQUENCYGAINA0NB     (*(__IO uint8_t  *)(0x0005C49C + SPI0_BASE)) /* Frequency Estimator Bandwidth A, non-blocking */
#define AX5043_FREQUENCYGAINC0_V1NB  (*(__IO uint8_t  *)(0x0005C49C + SPI0_BASE)) /* Frequency Estimator Bandwidth C, non-blocking */
#define AX5043_FREQUENCYGAINB0NB     (*(__IO uint8_t  *)(0x0005C4A0 + SPI0_BASE)) /* Frequency Estimator Bandwidth B, non-blocking */
#define AX5043_FREQUENCYGAIND0_V1NB  (*(__IO uint8_t  *)(0x0005C4A0 + SPI0_BASE)) /* Frequency Estimator Bandwidth D, non-blocking */
#define AX5043_AMPLITUDEGAIN0_V1NB   (*(__IO uint8_t  *)(0x0005C4A4 + SPI0_BASE)) /* Amplitude Estimator Bandwidth, non-blocking */
#define AX5043_FREQUENCYGAINC0NB     (*(__IO uint8_t  *)(0x0005C4A4 + SPI0_BASE)) /* Frequency Estimator Bandwidth C, non-blocking */
#define AX5043_FREQDEV10_V1NB        (*(__IO uint8_t  *)(0x0005C4A8 + SPI0_BASE)) /* Receiver Frequency Deviation 1, non-blocking */
#define AX5043_FREQUENCYGAIND0NB     (*(__IO uint8_t  *)(0x0005C4A8 + SPI0_BASE)) /* Frequency Estimator Bandwidth D, non-blocking */
#define AX5043_AMPLITUDEGAIN0NB      (*(__IO uint8_t  *)(0x0005C4AC + SPI0_BASE)) /* Amplitude Estimator Bandwidth, non-blocking */
#define AX5043_FREQDEV00_V1NB        (*(__IO uint8_t  *)(0x0005C4AC + SPI0_BASE)) /* Receiver Frequency Deviation 0, non-blocking */
#define AX5043_FOURFSK0_V1NB         (*(__IO uint8_t  *)(0x0005C4B0 + SPI0_BASE)) /* Four FSK Control, non-blocking */
#define AX5043_FREQDEV10NB           (*(__IO uint8_t  *)(0x0005C4B0 + SPI0_BASE)) /* Receiver Frequency Deviation 1, non-blocking */
#define AX5043_BBOFFSRES0_V1NB       (*(__IO uint8_t  *)(0x0005C4B4 + SPI0_BASE)) /* Baseband Offset Compensation Resistors, non-blocking */
#define AX5043_FREQDEV00NB           (*(__IO uint8_t  *)(0x0005C4B4 + SPI0_BASE)) /* Receiver Frequency Deviation 0, non-blocking */
#define AX5043_AGCGAIN1_V1NB         (*(__IO uint8_t  *)(0x0005C4B8 + SPI0_BASE)) /* AGC Speed, non-blocking */
#define AX5043_FOURFSK0NB            (*(__IO uint8_t  *)(0x0005C4B8 + SPI0_BASE)) /* Four FSK Control, non-blocking */
#define AX5043_AGCTARGET1_V1NB       (*(__IO uint8_t  *)(0x0005C4BC + SPI0_BASE)) /* AGC Target, non-blocking */
#define AX5043_BBOFFSRES0NB          (*(__IO uint8_t  *)(0x0005C4BC + SPI0_BASE)) /* Baseband Offset Compensation Resistors, non-blocking */
#define AX5043_AGCGAIN1NB            (*(__IO uint8_t  *)(0x0005C4C0 + SPI0_BASE)) /* AGC Speed, non-blocking */
#define AX5043_TIMEGAIN1_V1NB        (*(__IO uint8_t  *)(0x0005C4C0 + SPI0_BASE)) /* Time Estimator Bandwidth, non-blocking */
#define AX5043_AGCTARGET1NB          (*(__IO uint8_t  *)(0x0005C4C4 + SPI0_BASE)) /* AGC Target, non-blocking */
#define AX5043_DRGAIN1_V1NB          (*(__IO uint8_t  *)(0x0005C4C4 + SPI0_BASE)) /* Data Rate Estimator Bandwidth, non-blocking */
#define AX5043_AGCAHYST1NB           (*(__IO uint8_t  *)(0x0005C4C8 + SPI0_BASE)) /* AGC Analog Hysteresis, non-blocking */
#define AX5043_PHASEGAIN1_V1NB       (*(__IO uint8_t  *)(0x0005C4C8 + SPI0_BASE)) /* Phase Estimator Bandwidth, non-blocking */
#define AX5043_AGCMINMAX1NB          (*(__IO uint8_t  *)(0x0005C4CC + SPI0_BASE)) /* AGC Analog Update Behaviour, non-blocking */
#define AX5043_FREQUENCYGAINA1_V1NB  (*(__IO uint8_t  *)(0x0005C4CC + SPI0_BASE)) /* Frequency Estimator Bandwidth A, non-blocking */
#define AX5043_FREQUENCYGAINB1_V1NB  (*(__IO uint8_t  *)(0x0005C4D0 + SPI0_BASE)) /* Frequency Estimator Bandwidth B, non-blocking */
#define AX5043_TIMEGAIN1NB           (*(__IO uint8_t  *)(0x0005C4D0 + SPI0_BASE)) /* Time Estimator Bandwidth, non-blocking */
#define AX5043_DRGAIN1NB             (*(__IO uint8_t  *)(0x0005C4D4 + SPI0_BASE)) /* Data Rate Estimator Bandwidth, non-blocking */
#define AX5043_FREQUENCYGAINC1_V1NB  (*(__IO uint8_t  *)(0x0005C4D4 + SPI0_BASE)) /* Frequency Estimator Bandwidth C, non-blocking */
#define AX5043_FREQUENCYGAIND1_V1NB  (*(__IO uint8_t  *)(0x0005C4D8 + SPI0_BASE)) /* Frequency Estimator Bandwidth D, non-blocking */
#define AX5043_PHASEGAIN1NB          (*(__IO uint8_t  *)(0x0005C4D8 + SPI0_BASE)) /* Phase Estimator Bandwidth, non-blocking */
#define AX5043_AMPLITUDEGAIN1_V1NB   (*(__IO uint8_t  *)(0x0005C4DC + SPI0_BASE)) /* Amplitude Estimator Bandwidth, non-blocking */
#define AX5043_FREQUENCYGAINA1NB     (*(__IO uint8_t  *)(0x0005C4DC + SPI0_BASE)) /* Frequency Estimator Bandwidth A, non-blocking */
#define AX5043_FREQDEV11_V1NB        (*(__IO uint8_t  *)(0x0005C4E0 + SPI0_BASE)) /* Receiver Frequency Deviation 1, non-blocking */
#define AX5043_FREQUENCYGAINB1NB     (*(__IO uint8_t  *)(0x0005C4E0 + SPI0_BASE)) /* Frequency Estimator Bandwidth B, non-blocking */
#define AX5043_FREQDEV01_V1NB        (*(__IO uint8_t  *)(0x0005C4E4 + SPI0_BASE)) /* Receiver Frequency Deviation 0, non-blocking */
#define AX5043_FREQUENCYGAINC1NB     (*(__IO uint8_t  *)(0x0005C4E4 + SPI0_BASE)) /* Frequency Estimator Bandwidth C, non-blocking */
#define AX5043_FOURFSK1_V1NB         (*(__IO uint8_t  *)(0x0005C4E8 + SPI0_BASE)) /* Four FSK Control, non-blocking */
#define AX5043_FREQUENCYGAIND1NB     (*(__IO uint8_t  *)(0x0005C4E8 + SPI0_BASE)) /* Frequency Estimator Bandwidth D, non-blocking */
#define AX5043_AMPLITUDEGAIN1NB      (*(__IO uint8_t  *)(0x0005C4EC + SPI0_BASE)) /* Amplitude Estimator Bandwidth, non-blocking */
#define AX5043_BBOFFSRES1_V1NB       (*(__IO uint8_t  *)(0x0005C4EC + SPI0_BASE)) /* Baseband Offset Compensation Resistors, non-blocking */
#define AX5043_AGCGAIN2_V1NB         (*(__IO uint8_t  *)(0x0005C4F0 + SPI0_BASE)) /* AGC Speed, non-blocking */
#define AX5043_FREQDEV11NB           (*(__IO uint8_t  *)(0x0005C4F0 + SPI0_BASE)) /* Receiver Frequency Deviation 1, non-blocking */
#define AX5043_AGCTARGET2_V1NB       (*(__IO uint8_t  *)(0x0005C4F4 + SPI0_BASE)) /* AGC Target, non-blocking */
#define AX5043_FREQDEV01NB           (*(__IO uint8_t  *)(0x0005C4F4 + SPI0_BASE)) /* Receiver Frequency Deviation 0, non-blocking */
#define AX5043_FOURFSK1NB            (*(__IO uint8_t  *)(0x0005C4F8 + SPI0_BASE)) /* Four FSK Control, non-blocking */
#define AX5043_TIMEGAIN2_V1NB        (*(__IO uint8_t  *)(0x0005C4F8 + SPI0_BASE)) /* Time Estimator Bandwidth, non-blocking */
#define AX5043_BBOFFSRES1NB          (*(__IO uint8_t  *)(0x0005C4FC + SPI0_BASE)) /* Baseband Offset Compensation Resistors, non-blocking */
#define AX5043_DRGAIN2_V1NB          (*(__IO uint8_t  *)(0x0005C4FC + SPI0_BASE)) /* Data Rate Estimator Bandwidth, non-blocking */
#define AX5043_AGCGAIN2NB            (*(__IO uint8_t  *)(0x0005C500 + SPI0_BASE)) /* AGC Speed, non-blocking */
#define AX5043_PHASEGAIN2_V1NB       (*(__IO uint8_t  *)(0x0005C500 + SPI0_BASE)) /* Phase Estimator Bandwidth, non-blocking */
#define AX5043_AGCTARGET2NB          (*(__IO uint8_t  *)(0x0005C504 + SPI0_BASE)) /* AGC Target, non-blocking */
#define AX5043_FREQUENCYGAINA2_V1NB  (*(__IO uint8_t  *)(0x0005C504 + SPI0_BASE)) /* Frequency Estimator Bandwidth A, non-blocking */
#define AX5043_AGCAHYST2NB           (*(__IO uint8_t  *)(0x0005C508 + SPI0_BASE)) /* AGC Analog Hysteresis, non-blocking */
#define AX5043_FREQUENCYGAINB2_V1NB  (*(__IO uint8_t  *)(0x0005C508 + SPI0_BASE)) /* Frequency Estimator Bandwidth B, non-blocking */
#define AX5043_AGCMINMAX2NB          (*(__IO uint8_t  *)(0x0005C50C + SPI0_BASE)) /* AGC Analog Update Behaviour, non-blocking */
#define AX5043_FREQUENCYGAINC2_V1NB  (*(__IO uint8_t  *)(0x0005C50C + SPI0_BASE)) /* Frequency Estimator Bandwidth C, non-blocking */
#define AX5043_FREQUENCYGAIND2_V1NB  (*(__IO uint8_t  *)(0x0005C510 + SPI0_BASE)) /* Frequency Estimator Bandwidth D, non-blocking */
#define AX5043_TIMEGAIN2NB           (*(__IO uint8_t  *)(0x0005C510 + SPI0_BASE)) /* Time Estimator Bandwidth, non-blocking */
#define AX5043_AMPLITUDEGAIN2_V1NB   (*(__IO uint8_t  *)(0x0005C514 + SPI0_BASE)) /* Amplitude Estimator Bandwidth, non-blocking */
#define AX5043_DRGAIN2NB             (*(__IO uint8_t  *)(0x0005C514 + SPI0_BASE)) /* Data Rate Estimator Bandwidth, non-blocking */
#define AX5043_FREQDEV12_V1NB        (*(__IO uint8_t  *)(0x0005C518 + SPI0_BASE)) /* Receiver Frequency Deviation 1, non-blocking */
#define AX5043_PHASEGAIN2NB          (*(__IO uint8_t  *)(0x0005C518 + SPI0_BASE)) /* Phase Estimator Bandwidth, non-blocking */
#define AX5043_FREQDEV02_V1NB        (*(__IO uint8_t  *)(0x0005C51C + SPI0_BASE)) /* Receiver Frequency Deviation 0, non-blocking */
#define AX5043_FREQUENCYGAINA2NB     (*(__IO uint8_t  *)(0x0005C51C + SPI0_BASE)) /* Frequency Estimator Bandwidth A, non-blocking */
#define AX5043_FOURFSK2_V1NB         (*(__IO uint8_t  *)(0x0005C520 + SPI0_BASE)) /* Four FSK Control, non-blocking */
#define AX5043_FREQUENCYGAINB2NB     (*(__IO uint8_t  *)(0x0005C520 + SPI0_BASE)) /* Frequency Estimator Bandwidth B, non-blocking */
#define AX5043_BBOFFSRES2_V1NB       (*(__IO uint8_t  *)(0x0005C524 + SPI0_BASE)) /* Baseband Offset Compensation Resistors, non-blocking */
#define AX5043_FREQUENCYGAINC2NB     (*(__IO uint8_t  *)(0x0005C524 + SPI0_BASE)) /* Frequency Estimator Bandwidth C, non-blocking */
#define AX5043_AGCGAIN3_V1NB         (*(__IO uint8_t  *)(0x0005C528 + SPI0_BASE)) /* AGC Speed, non-blocking */
#define AX5043_FREQUENCYGAIND2NB     (*(__IO uint8_t  *)(0x0005C528 + SPI0_BASE)) /* Frequency Estimator Bandwidth D, non-blocking */
#define AX5043_AGCTARGET3_V1NB       (*(__IO uint8_t  *)(0x0005C52C + SPI0_BASE)) /* AGC Target, non-blocking */
#define AX5043_AMPLITUDEGAIN2NB      (*(__IO uint8_t  *)(0x0005C52C + SPI0_BASE)) /* Amplitude Estimator Bandwidth, non-blocking */
#define AX5043_FREQDEV12NB           (*(__IO uint8_t  *)(0x0005C530 + SPI0_BASE)) /* Receiver Frequency Deviation 1, non-blocking */
#define AX5043_TIMEGAIN3_V1NB        (*(__IO uint8_t  *)(0x0005C530 + SPI0_BASE)) /* Time Estimator Bandwidth, non-blocking */
#define AX5043_DRGAIN3_V1NB          (*(__IO uint8_t  *)(0x0005C534 + SPI0_BASE)) /* Data Rate Estimator Bandwidth, non-blocking */
#define AX5043_FREQDEV02NB           (*(__IO uint8_t  *)(0x0005C534 + SPI0_BASE)) /* Receiver Frequency Deviation 0, non-blocking */
#define AX5043_FOURFSK2NB            (*(__IO uint8_t  *)(0x0005C538 + SPI0_BASE)) /* Four FSK Control, non-blocking */
#define AX5043_PHASEGAIN3_V1NB       (*(__IO uint8_t  *)(0x0005C538 + SPI0_BASE)) /* Phase Estimator Bandwidth, non-blocking */
#define AX5043_BBOFFSRES2NB          (*(__IO uint8_t  *)(0x0005C53C + SPI0_BASE)) /* Baseband Offset Compensation Resistors, non-blocking */
#define AX5043_FREQUENCYGAINA3_V1NB  (*(__IO uint8_t  *)(0x0005C53C + SPI0_BASE)) /* Frequency Estimator Bandwidth A, non-blocking */
#define AX5043_AGCGAIN3NB            (*(__IO uint8_t  *)(0x0005C540 + SPI0_BASE)) /* AGC Speed, non-blocking */
#define AX5043_FREQUENCYGAINB3_V1NB  (*(__IO uint8_t  *)(0x0005C540 + SPI0_BASE)) /* Frequency Estimator Bandwidth B, non-blocking */
#define AX5043_AGCTARGET3NB          (*(__IO uint8_t  *)(0x0005C544 + SPI0_BASE)) /* AGC Target, non-blocking */
#define AX5043_FREQUENCYGAINC3_V1NB  (*(__IO uint8_t  *)(0x0005C544 + SPI0_BASE)) /* Frequency Estimator Bandwidth C, non-blocking */
#define AX5043_AGCAHYST3NB           (*(__IO uint8_t  *)(0x0005C548 + SPI0_BASE)) /* AGC Analog Hysteresis, non-blocking */
#define AX5043_FREQUENCYGAIND3_V1NB  (*(__IO uint8_t  *)(0x0005C548 + SPI0_BASE)) /* Frequency Estimator Bandwidth D, non-blocking */
#define AX5043_AGCMINMAX3NB          (*(__IO uint8_t  *)(0x0005C54C + SPI0_BASE)) /* AGC Analog Update Behaviour, non-blocking */
#define AX5043_AMPLITUDEGAIN3_V1NB   (*(__IO uint8_t  *)(0x0005C54C + SPI0_BASE)) /* Amplitude Estimator Bandwidth, non-blocking */
#define AX5043_FREQDEV13_V1NB        (*(__IO uint8_t  *)(0x0005C550 + SPI0_BASE)) /* Receiver Frequency Deviation 1, non-blocking */
#define AX5043_TIMEGAIN3NB           (*(__IO uint8_t  *)(0x0005C550 + SPI0_BASE)) /* Time Estimator Bandwidth, non-blocking */
#define AX5043_DRGAIN3NB             (*(__IO uint8_t  *)(0x0005C554 + SPI0_BASE)) /* Data Rate Estimator Bandwidth, non-blocking */
#define AX5043_FREQDEV03_V1NB        (*(__IO uint8_t  *)(0x0005C554 + SPI0_BASE)) /* Receiver Frequency Deviation 0, non-blocking */
#define AX5043_FOURFSK3_V1NB         (*(__IO uint8_t  *)(0x0005C558 + SPI0_BASE)) /* Four FSK Control, non-blocking */
#define AX5043_PHASEGAIN3NB          (*(__IO uint8_t  *)(0x0005C558 + SPI0_BASE)) /* Phase Estimator Bandwidth, non-blocking */
#define AX5043_BBOFFSRES3_V1NB       (*(__IO uint8_t  *)(0x0005C55C + SPI0_BASE)) /* Baseband Offset Compensation Resistors, non-blocking */
#define AX5043_FREQUENCYGAINA3NB     (*(__IO uint8_t  *)(0x0005C55C + SPI0_BASE)) /* Frequency Estimator Bandwidth A, non-blocking */
#define AX5043_FREQUENCYGAINB3NB     (*(__IO uint8_t  *)(0x0005C560 + SPI0_BASE)) /* Frequency Estimator Bandwidth B, non-blocking */
#define AX5043_FREQUENCYGAINC3NB     (*(__IO uint8_t  *)(0x0005C564 + SPI0_BASE)) /* Frequency Estimator Bandwidth C, non-blocking */
#define AX5043_FREQUENCYGAIND3NB     (*(__IO uint8_t  *)(0x0005C568 + SPI0_BASE)) /* Frequency Estimator Bandwidth D, non-blocking */
#define AX5043_AMPLITUDEGAIN3NB      (*(__IO uint8_t  *)(0x0005C56C + SPI0_BASE)) /* Amplitude Estimator Bandwidth, non-blocking */
#define AX5043_FREQDEV13NB           (*(__IO uint8_t  *)(0x0005C570 + SPI0_BASE)) /* Receiver Frequency Deviation 1, non-blocking */
#define AX5043_FREQDEV03NB           (*(__IO uint8_t  *)(0x0005C574 + SPI0_BASE)) /* Receiver Frequency Deviation 0, non-blocking */
#define AX5043_FOURFSK3NB            (*(__IO uint8_t  *)(0x0005C578 + SPI0_BASE)) /* Four FSK Control, non-blocking */
#define AX5043_BBOFFSRES3NB          (*(__IO uint8_t  *)(0x0005C57C + SPI0_BASE)) /* Baseband Offset Compensation Resistors, non-blocking */
#define AX5043_MODCFGFNB             (*(__IO uint8_t  *)(0x0005C580 + SPI0_BASE)) /* Modulator Configuration F, non-blocking */
#define AX5043_FSKDEVNB              (*(__IO uint32_t *)(0x0205C584 + SPI0_BASE)) /* FSK Deviation, non-blocking */
#define AX5043_FSKDEV2NB             (*(__IO uint8_t  *)(0x0005C584 + SPI0_BASE)) /* FSK Deviation 2, non-blocking */
#define AX5043_FSKDEV1NB             (*(__IO uint8_t  *)(0x0005C588 + SPI0_BASE)) /* FSK Deviation 1, non-blocking */
#define AX5043_FSKDEV0NB             (*(__IO uint8_t  *)(0x0005C58C + SPI0_BASE)) /* FSK Deviation 0, non-blocking */
#define AX5043_MODCFGANB             (*(__IO uint8_t  *)(0x0005C590 + SPI0_BASE)) /* Modulator Configuration A, non-blocking */
#define AX5043_TXRATENB              (*(__IO uint32_t *)(0x0205C594 + SPI0_BASE)) /* Transmitter Bitrate, non-blocking */
#define AX5043_TXRATE2NB             (*(__IO uint8_t  *)(0x0005C594 + SPI0_BASE)) /* Transmitter Bitrate 2, non-blocking */
#define AX5043_TXRATE1NB             (*(__IO uint8_t  *)(0x0005C598 + SPI0_BASE)) /* Transmitter Bitrate 1, non-blocking */
#define AX5043_TXRATE0NB             (*(__IO uint8_t  *)(0x0005C59C + SPI0_BASE)) /* Transmitter Bitrate 0, non-blocking */
#define AX5043_TXPWRCOEFFANB         (*(__IO uint16_t *)(0x000DC5A0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient A, non-blocking */
#define AX5043_TXPWRCOEFFA1NB        (*(__IO uint8_t  *)(0x0005C5A0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient A 1, non-blocking */
#define AX5043_TXPWRCOEFFA0NB        (*(__IO uint8_t  *)(0x0005C5A4 + SPI0_BASE)) /* Transmitter Predistortion Coefficient A 0, non-blocking */
#define AX5043_TXPWRCOEFFBNB         (*(__IO uint16_t *)(0x000DC5A8 + SPI0_BASE)) /* Transmitter Predistortion Coefficient B, non-blocking */
#define AX5043_TXPWRCOEFFB1NB        (*(__IO uint8_t  *)(0x0005C5A8 + SPI0_BASE)) /* Transmitter Predistortion Coefficient B 1, non-blocking */
#define AX5043_TXPWRCOEFFB0NB        (*(__IO uint8_t  *)(0x0005C5AC + SPI0_BASE)) /* Transmitter Predistortion Coefficient B 0, non-blocking */
#define AX5043_TXPWRCOEFFCNB         (*(__IO uint16_t *)(0x000DC5B0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient C, non-blocking */
#define AX5043_TXPWRCOEFFC1NB        (*(__IO uint8_t  *)(0x0005C5B0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient C 1, non-blocking */
#define AX5043_TXPWRCOEFFC0NB        (*(__IO uint8_t  *)(0x0005C5B4 + SPI0_BASE)) /* Transmitter Predistortion Coefficient C 0, non-blocking */
#define AX5043_TXPWRCOEFFDNB         (*(__IO uint16_t *)(0x000DC5B8 + SPI0_BASE)) /* Transmitter Predistortion Coefficient D, non-blocking */
#define AX5043_TXPWRCOEFFD1NB        (*(__IO uint8_t  *)(0x0005C5B8 + SPI0_BASE)) /* Transmitter Predistortion Coefficient D 1, non-blocking */
#define AX5043_TXPWRCOEFFD0NB        (*(__IO uint8_t  *)(0x0005C5BC + SPI0_BASE)) /* Transmitter Predistortion Coefficient D 0, non-blocking */
#define AX5043_TXPWRCOEFFENB         (*(__IO uint16_t *)(0x000DC5C0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient E, non-blocking */
#define AX5043_TXPWRCOEFFE1NB        (*(__IO uint8_t  *)(0x0005C5C0 + SPI0_BASE)) /* Transmitter Predistortion Coefficient E 1, non-blocking */
#define AX5043_TXPWRCOEFFE0NB        (*(__IO uint8_t  *)(0x0005C5C4 + SPI0_BASE)) /* Transmitter Predistortion Coefficient E 0, non-blocking */
#define AX5043_PLLVCOINB             (*(__IO uint8_t  *)(0x0005C600 + SPI0_BASE)) /* PLL VCO Current, non-blocking */
#define AX5043_PLLVCOIRNB            (*(__IO uint8_t  *)(0x0005C604 + SPI0_BASE)) /* PLL VCO Current Readback, non-blocking */
#define AX5043_PLLLOCKDETNB          (*(__IO uint8_t  *)(0x0005C608 + SPI0_BASE)) /* PLL Lock Detect Delay, non-blocking */
#define AX5043_PLLRNGCLKNB           (*(__IO uint8_t  *)(0x0005C60C + SPI0_BASE)) /* PLL Autoranging Clock, non-blocking */
#define AX5043_XTALCAPNB             (*(__IO uint8_t  *)(0x0005C610 + SPI0_BASE)) /* Crystal Oscillator Load Capacitance, non-blocking */
#define AX5043_BBTUNENB              (*(__IO uint8_t  *)(0x0005C620 + SPI0_BASE)) /* Baseband Tuning, non-blocking */
#define AX5043_BBOFFSCAPNB           (*(__IO uint8_t  *)(0x0005C624 + SPI0_BASE)) /* Baseband Offset Compensation Capacitors, non-blocking */
#define AX5043_PKTADDRCFGNB          (*(__IO uint8_t  *)(0x0005C800 + SPI0_BASE)) /* Packet Address Config, non-blocking */
#define AX5043_PKTADDRCFG_V1NB       (*(__IO uint8_t  *)(0x0005C804 + SPI0_BASE)) /* Packet Address Config, non-blocking */
#define AX5043_PKTLENCFGNB           (*(__IO uint8_t  *)(0x0005C804 + SPI0_BASE)) /* Packet Length Configuration, non-blocking */
#define AX5043_PKTADDR1_V1NB         (*(__IO uint8_t  *)(0x0005C808 + SPI0_BASE)) /* Packet Address 1, non-blocking */
#define AX5043_PKTLENOFFSETNB        (*(__IO uint8_t  *)(0x0005C808 + SPI0_BASE)) /* Packet Length Offset, non-blocking */
#define AX5043_PKTADDR0_V1NB         (*(__IO uint8_t  *)(0x0005C80C + SPI0_BASE)) /* Packet Address 0, non-blocking */
#define AX5043_PKTMAXLENNB           (*(__IO uint8_t  *)(0x0005C80C + SPI0_BASE)) /* Packet Maximum Length, non-blocking */
#define AX5043_PKTADDRNB             (*(__IO uint32_t *)(0x020DC810 + SPI0_BASE)) /* Packet Address, non-blocking */
#define AX5043_PKTADDR3NB            (*(__IO uint8_t  *)(0x0005C810 + SPI0_BASE)) /* Packet Address 3, non-blocking */
#define AX5043_PKTADDRMASK1_V1NB     (*(__IO uint8_t  *)(0x0005C810 + SPI0_BASE)) /* Packet Address Mask 1, non-blocking */
#define AX5043_PKTADDR2NB            (*(__IO uint8_t  *)(0x0005C814 + SPI0_BASE)) /* Packet Address 2, non-blocking */
#define AX5043_PKTADDRMASK0_V1NB     (*(__IO uint8_t  *)(0x0005C814 + SPI0_BASE)) /* Packet Address Mask 0, non-blocking */
#define AX5043_PKTADDR1NB            (*(__IO uint8_t  *)(0x0005C818 + SPI0_BASE)) /* Packet Address 1, non-blocking */
#define AX5043_PKTLENCFG_V1NB        (*(__IO uint8_t  *)(0x0005C818 + SPI0_BASE)) /* Packet Length Configuration, non-blocking */
#define AX5043_PKTADDR0NB            (*(__IO uint8_t  *)(0x0005C81C + SPI0_BASE)) /* Packet Address 0, non-blocking */
#define AX5043_PKTLENOFFSET_V1NB     (*(__IO uint8_t  *)(0x0005C81C + SPI0_BASE)) /* Packet Length Offset, non-blocking */
#define AX5043_PKTADDRMASKNB         (*(__IO uint32_t *)(0x020DC820 + SPI0_BASE)) /* Packet Address Mask, non-blocking */
#define AX5043_PKTADDRMASK3NB        (*(__IO uint8_t  *)(0x0005C820 + SPI0_BASE)) /* Packet Address Mask 3, non-blocking */
#define AX5043_PKTMAXLEN_V1NB        (*(__IO uint8_t  *)(0x0005C820 + SPI0_BASE)) /* Packet Maximum Length, non-blocking */
#define AX5043_PKTADDRMASK2NB        (*(__IO uint8_t  *)(0x0005C824 + SPI0_BASE)) /* Packet Address Mask 2, non-blocking */
#define AX5043_PKTADDRMASK1NB        (*(__IO uint8_t  *)(0x0005C828 + SPI0_BASE)) /* Packet Address Mask 1, non-blocking */
#define AX5043_PKTADDRMASK0NB        (*(__IO uint8_t  *)(0x0005C82C + SPI0_BASE)) /* Packet Address Mask 0, non-blocking */
#define AX5043_MATCH0PATNB           (*(__IO uint32_t *)(0x020DC840 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern, non-blocking */
#define AX5043_MATCH0PAT3NB          (*(__IO uint8_t  *)(0x0005C840 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern 3, non-blocking */
#define AX5043_MATCH0PAT2NB          (*(__IO uint8_t  *)(0x0005C844 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern 2, non-blocking */
#define AX5043_MATCH0PAT1NB          (*(__IO uint8_t  *)(0x0005C848 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern 1, non-blocking */
#define AX5043_MATCH0PAT0NB          (*(__IO uint8_t  *)(0x0005C84C + SPI0_BASE)) /* Pattern Match Unit 0, Pattern 0, non-blocking */
#define AX5043_MATCH0LENNB           (*(__IO uint8_t  *)(0x0005C850 + SPI0_BASE)) /* Pattern Match Unit 0, Pattern Length, non-blocking */
#define AX5043_MATCH0MINNB           (*(__IO uint8_t  *)(0x0005C854 + SPI0_BASE)) /* Pattern Match Unit 0, Minimum Match, non-blocking */
#define AX5043_MATCH0MAXNB           (*(__IO uint8_t  *)(0x0005C858 + SPI0_BASE)) /* Pattern Match Unit 0, Maximum Match, non-blocking */
#define AX5043_MATCH1PATNB           (*(__IO uint16_t *)(0x000DC860 + SPI0_BASE)) /* Pattern Match Unit 1, Pattern, non-blocking */
#define AX5043_MATCH1PAT1NB          (*(__IO uint8_t  *)(0x0005C860 + SPI0_BASE)) /* Pattern Match Unit 1, Pattern 1, non-blocking */
#define AX5043_MATCH1PAT0NB          (*(__IO uint8_t  *)(0x0005C864 + SPI0_BASE)) /* Pattern Match Unit 1, Pattern 0, non-blocking */
#define AX5043_MATCH1LENNB           (*(__IO uint8_t  *)(0x0005C870 + SPI0_BASE)) /* Pattern Match Unit 1, Pattern Length, non-blocking */
#define AX5043_MATCH1MINNB           (*(__IO uint8_t  *)(0x0005C874 + SPI0_BASE)) /* Pattern Match Unit 1, Minimum Match, non-blocking */
#define AX5043_MATCH1MAXNB           (*(__IO uint8_t  *)(0x0005C878 + SPI0_BASE)) /* Pattern Match Unit 1, Maximum Match, non-blocking */
#define AX5043_TMGTXBOOSTNB          (*(__IO uint8_t  *)(0x0005C880 + SPI0_BASE)) /* Transmit PLL Boost Time, non-blocking */
#define AX5043_TMGTXSETTLENB         (*(__IO uint8_t  *)(0x0005C884 + SPI0_BASE)) /* Transmit PLL (post Boost) Settling Time, non-blocking */
#define AX5043_TMGRXBOOSTNB          (*(__IO uint8_t  *)(0x0005C88C + SPI0_BASE)) /* Receive PLL Boost Time, non-blocking */
#define AX5043_TMGRXSETTLENB         (*(__IO uint8_t  *)(0x0005C890 + SPI0_BASE)) /* Receive PLL (post Boost) Settling Time, non-blocking */
#define AX5043_TMGRXOFFSACQNB        (*(__IO uint8_t  *)(0x0005C894 + SPI0_BASE)) /* Receive Baseband DC Offset Acquisition Time, non-blocking */
#define AX5043_TMGRXCOARSEAGCNB      (*(__IO uint8_t  *)(0x0005C898 + SPI0_BASE)) /* Receive Coarse AGC Time, non-blocking */
#define AX5043_TMGRXAGCNB            (*(__IO uint8_t  *)(0x0005C89C + SPI0_BASE)) /* Receiver AGC Settling Time, non-blocking */
#define AX5043_TMGRXRSSINB           (*(__IO uint8_t  *)(0x0005C8A0 + SPI0_BASE)) /* Receiver RSSI Settling Time, non-blocking */
#define AX5043_TMGRXPREAMBLE1NB      (*(__IO uint8_t  *)(0x0005C8A4 + SPI0_BASE)) /* Receiver Preamble 1 Timeout, non-blocking */
#define AX5043_TMGRXPREAMBLE2NB      (*(__IO uint8_t  *)(0x0005C8A8 + SPI0_BASE)) /* Receiver Preamble 2 Timeout, non-blocking */
#define AX5043_TMGRXPREAMBLE3NB      (*(__IO uint8_t  *)(0x0005C8AC + SPI0_BASE)) /* Receiver Preamble 3 Timeout, non-blocking */
#define AX5043_RSSIREFERENCENB       (*(__IO uint8_t  *)(0x0005C8B0 + SPI0_BASE)) /* RSSI Offset, non-blocking */
#define AX5043_RSSIABSTHRNB          (*(__IO uint8_t  *)(0x0005C8B4 + SPI0_BASE)) /* RSSI Absolute Threshold, non-blocking */
#define AX5043_BGNDRSSIGAINNB        (*(__IO uint8_t  *)(0x0005C8B8 + SPI0_BASE)) /* Background RSSI Averaging Time Constant, non-blocking */
#define AX5043_BGNDRSSITHRNB         (*(__IO uint8_t  *)(0x0005C8BC + SPI0_BASE)) /* Background RSSI Relative Threshold, non-blocking */
#define AX5043_PKTCHUNKSIZENB        (*(__IO uint8_t  *)(0x0005C8C0 + SPI0_BASE)) /* Packet Chunk Size, non-blocking */
#define AX5043_PKTMISCFLAGSNB        (*(__IO uint8_t  *)(0x0005C8C4 + SPI0_BASE)) /* Packet Controller Miscellaneous Flags, non-blocking */
#define AX5043_PKTSTOREFLAGSNB       (*(__IO uint8_t  *)(0x0005C8C8 + SPI0_BASE)) /* Packet Controller Store Flags, non-blocking */
#define AX5043_PKTACCEPTFLAGSNB      (*(__IO uint8_t  *)(0x0005C8CC + SPI0_BASE)) /* Packet Controller Accept Flags, non-blocking */
#define AX5043_GPADCCTRLNB           (*(__IO uint8_t  *)(0x0005CC00 + SPI0_BASE)) /* General Purpose ADC Control, non-blocking */
#define AX5043_GPADCPERIODNB         (*(__IO uint8_t  *)(0x0005CC04 + SPI0_BASE)) /* GPADC Sampling Period, non-blocking */
#define AX5043_GPADC13VALUENB        (*(__I  uint16_t *)(0x000DCC20 + SPI0_BASE)) /* GPADC13 Value, non-blocking */
#define AX5043_GPADC13VALUE1NB       (*(__I  uint8_t  *)(0x0005CC20 + SPI0_BASE)) /* GPADC13 Value 1, non-blocking */
#define AX5043_GPADC13VALUE0NB       (*(__I  uint8_t  *)(0x0005CC24 + SPI0_BASE)) /* GPADC13 Value 0, non-blocking */
#define AX5043_LPOSCCONFIGNB         (*(__IO uint8_t  *)(0x0005CC40 + SPI0_BASE)) /* Low Power Oscillator Calibration Configuration, non-blocking */
#define AX5043_LPOSCSTATUSNB         (*(__I  uint8_t  *)(0x0005CC44 + SPI0_BASE)) /* Low Power Oscillator Calibration Status, non-blocking */
#define AX5043_LPOSCKFILTNB          (*(__IO uint16_t *)(0x000DCC48 + SPI0_BASE))
#define AX5043_LPOSCKFILT1NB         (*(__IO uint8_t  *)(0x0005CC48 + SPI0_BASE)) /* Low Power Oscillator Calibration Filter Constant High Byte, non-blocking */
#define AX5043_LPOSCKFILT0NB         (*(__IO uint8_t  *)(0x0005CC4C + SPI0_BASE)) /* Low Power Oscillator Calibration Filter Constant Low Byte, non-blocking */
#define AX5043_LPOSCREFNB            (*(__IO uint16_t *)(0x000DCC50 + SPI0_BASE))
#define AX5043_LPOSCREF1NB           (*(__IO uint8_t  *)(0x0005CC50 + SPI0_BASE)) /* Low Power Oscillator Reference Frequency High Byte, non-blocking */
#define AX5043_LPOSCREF0NB           (*(__IO uint8_t  *)(0x0005CC54 + SPI0_BASE)) /* Low Power Oscillator Reference Frequency Low Byte, non-blocking */
#define AX5043_LPOSCFREQNB           (*(__IO uint16_t *)(0x000DCC58 + SPI0_BASE))
#define AX5043_LPOSCFREQ1NB          (*(__IO uint8_t  *)(0x0005CC58 + SPI0_BASE)) /* Low Power Oscillator Frequency Tuning High Byte, non-blocking */
#define AX5043_LPOSCFREQ0NB          (*(__IO uint8_t  *)(0x0005CC5C + SPI0_BASE)) /* Low Power Oscillator Frequency Tuning Low Byte, non-blocking */
#define AX5043_LPOSCPERNB            (*(__IO uint16_t *)(0x000DCC60 + SPI0_BASE))
#define AX5043_LPOSCPER1NB           (*(__IO uint8_t  *)(0x0005CC60 + SPI0_BASE)) /* Low Power Oscillator Period High Byte, non-blocking */
#define AX5043_LPOSCPER0NB           (*(__IO uint8_t  *)(0x0005CC64 + SPI0_BASE)) /* Low Power Oscillator Period Low Byte, non-blocking */
#define AX5043_DACVALUENB            (*(__IO uint16_t *)(0x000DCCC0 + SPI0_BASE)) /* DAC Value, non-blocking */
#define AX5043_DACVALUE1NB           (*(__IO uint8_t  *)(0x0005CCC0 + SPI0_BASE)) /* DAC Value 1, non-blocking */
#define AX5043_DACVALUE0NB           (*(__IO uint8_t  *)(0x0005CCC4 + SPI0_BASE)) /* DAC Value 0, non-blocking */
#define AX5043_DACCONFIGNB           (*(__IO uint8_t  *)(0x0005CCC8 + SPI0_BASE)) /* DAC Configuration, non-blocking */
#define AX5043_0xF00NB               (*(__IO uint8_t  *)(0x0005FC00 + SPI0_BASE))
#define AX5043_POWCTRL1NB            (*(__IO uint8_t  *)(0x0005FC20 + SPI0_BASE)) /* Power Control 1, non-blocking */
#define AX5043_0xF0CNB               (*(__IO uint8_t  *)(0x0005FC30 + SPI0_BASE))
#define AX5043_REFNB                 (*(__IO uint8_t  *)(0x0005FC34 + SPI0_BASE)) /* Reference, non-blocking */
#define AX5043_XTALOSCNB             (*(__IO uint8_t  *)(0x0005FC40 + SPI0_BASE)) /* Crystal Oscillator Control, non-blocking */
#define AX5043_XTALAMPLNB            (*(__IO uint8_t  *)(0x0005FC44 + SPI0_BASE)) /* Crystal Oscillator Amplitude Control, non-blocking */
#define AX5043_0xF18NB               (*(__IO uint8_t  *)(0x0005FC60 + SPI0_BASE))
#define AX5043_0xF1CNB               (*(__IO uint8_t  *)(0x0005FC70 + SPI0_BASE))
#define AX5043_0xF21NB               (*(__IO uint8_t  *)(0x0005FC84 + SPI0_BASE))
#define AX5043_0xF22NB               (*(__IO uint8_t  *)(0x0005FC88 + SPI0_BASE))
#define AX5043_0xF23NB               (*(__IO uint8_t  *)(0x0005FC8C + SPI0_BASE))
#define AX5043_0xF26NB               (*(__IO uint8_t  *)(0x0005FC98 + SPI0_BASE))
#define AX5043_0xF30NB               (*(__IO uint8_t  *)(0x0005FCC0 + SPI0_BASE))
#define AX5043_0xF31NB               (*(__IO uint8_t  *)(0x0005FCC4 + SPI0_BASE))
#define AX5043_0xF32NB               (*(__IO uint8_t  *)(0x0005FCC8 + SPI0_BASE))
#define AX5043_0xF33NB               (*(__IO uint8_t  *)(0x0005FCCC + SPI0_BASE))
#define AX5043_0xF34NB               (*(__IO uint8_t  *)(0x0005FCD0 + SPI0_BASE))
#define AX5043_0xF35NB               (*(__IO uint8_t  *)(0x0005FCD4 + SPI0_BASE))
#define AX5043_0xF44NB               (*(__IO uint8_t  *)(0x0005FD10 + SPI0_BASE))
#define AX5043_MODCFGPNB             (*(__IO uint8_t  *)(0x0005FD7C + SPI0_BASE)) /* Modulator Configuration P, non-blocking */

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

#endif /* AXM0F143_H */
