/**
******************************************************************************
* @file axm0f151.h
* @brief Macro definition for AX5051 radio registers
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

#ifndef AXM0F151_H
#define AXM0F151_H

#include <axm0.h>

#define AX5051_SILICONREVISION       (*(__IO uint8_t  *)(0x00020000 + SPI0_BASE)) /* Silicon Revision */
#define AX5051_SCRATCH               (*(__IO uint8_t  *)(0x00020004 + SPI0_BASE)) /* Scratch */
#define AX5051_PWRMODE               (*(__IO uint8_t  *)(0x00020008 + SPI0_BASE)) /* Power Mode */
#define AX5051_XTALOSC               (*(__IO uint8_t  *)(0x0002000C + SPI0_BASE)) /* Crystal Oscillator Control */
#define AX5051_FIFOCONTROL           (*(__IO uint8_t  *)(0x00020010 + SPI0_BASE)) /* FIFO Control */
#define AX5051_FIFODATA              (*(__IO uint8_t  *)(0x00020014 + SPI0_BASE)) /* FIFO Data */
#define AX5051_IRQMASK               (*(__IO uint8_t  *)(0x00020018 + SPI0_BASE)) /* IRQ Mask */
#define AX5051_IRQREQUEST            (*(__IO uint8_t  *)(0x0002001C + SPI0_BASE)) /* IRQ Request */
#define AX5051_IFMODE                (*(__IO uint8_t  *)(0x00020020 + SPI0_BASE)) /* Interface Mode */
#define AX5051_DSPMODE               (*(__IO uint8_t  *)(0x00020024 + SPI0_BASE)) /* DSP Mode Interface Control */
#define AX5051_TXDSPMODE             (*(__IO uint8_t  *)(0x00020028 + SPI0_BASE)) /* Transmit DSP Mode */
#define AX5051_PINCFG1               (*(__IO uint8_t  *)(0x00020030 + SPI0_BASE)) /* Pin Configuration 1 */
#define AX5051_PINCFG2               (*(__IO uint8_t  *)(0x00020034 + SPI0_BASE)) /* Pin Configuration 2 */
#define AX5051_PINCFG3               (*(__IO uint8_t  *)(0x00020038 + SPI0_BASE)) /* Pin Configuration 3 */
#define AX5051_IRQINVERSION          (*(__IO uint8_t  *)(0x0002003C + SPI0_BASE)) /* IRQ Inversion */
#define AX5051_MODULATION            (*(__IO uint8_t  *)(0x00020040 + SPI0_BASE)) /* Modulation */
#define AX5051_ENCODING              (*(__IO uint8_t  *)(0x00020044 + SPI0_BASE)) /* Encoding */
#define AX5051_FRAMING               (*(__IO uint8_t  *)(0x00020048 + SPI0_BASE)) /* Framing Mode */
#define AX5051_CRCINIT               (*(__IO uint32_t *)(0x020A0050 + SPI0_BASE)) /* CRC Initial Value */
#define AX5051_CRCINIT3              (*(__IO uint8_t  *)(0x00020050 + SPI0_BASE)) /* CRC Initial Value 3 */
#define AX5051_CRCINIT2              (*(__IO uint8_t  *)(0x00020054 + SPI0_BASE)) /* CRC Initial Value 2 */
#define AX5051_CRCINIT1              (*(__IO uint8_t  *)(0x00020058 + SPI0_BASE)) /* CRC Initial Value 1 */
#define AX5051_CRCINIT0              (*(__IO uint8_t  *)(0x0002005C + SPI0_BASE)) /* CRC Initial Value 0 */
#define AX5051_FEC                   (*(__IO uint8_t  *)(0x00020060 + SPI0_BASE)) /* Forward Error Correction */
#define AX5051_FECSYNC               (*(__IO uint8_t  *)(0x00020064 + SPI0_BASE)) /* Forward Error Correction Sync Threshold */
#define AX5051_FECSTATUS             (*(__IO uint8_t  *)(0x00020068 + SPI0_BASE)) /* Forward Error Correction Status */
#define AX5051_VREG                  (*(__IO uint8_t  *)(0x0002006C + SPI0_BASE)) /* Voltage Regulator */
#define AX5051_FREQ                  (*(__IO uint32_t *)(0x020A0080 + SPI0_BASE)) /* Frequency */
#define AX5051_FREQ3                 (*(__IO uint8_t  *)(0x00020080 + SPI0_BASE)) /* Frequency 3 */
#define AX5051_FREQA                 (*(__IO uint32_t *)(0x020A0080 + SPI0_BASE)) /* Frequency */
#define AX5051_FREQA3                (*(__IO uint8_t  *)(0x00020080 + SPI0_BASE)) /* Frequency 3 */
#define AX5051_FREQ2                 (*(__IO uint8_t  *)(0x00020084 + SPI0_BASE)) /* Frequency 2 */
#define AX5051_FREQA2                (*(__IO uint8_t  *)(0x00020084 + SPI0_BASE)) /* Frequency 2 */
#define AX5051_FREQ1                 (*(__IO uint8_t  *)(0x00020088 + SPI0_BASE)) /* Frequency 1 */
#define AX5051_FREQA1                (*(__IO uint8_t  *)(0x00020088 + SPI0_BASE)) /* Frequency 1 */
#define AX5051_FREQ0                 (*(__IO uint8_t  *)(0x0002008C + SPI0_BASE)) /* Frequency 0 */
#define AX5051_FREQA0                (*(__IO uint8_t  *)(0x0002008C + SPI0_BASE)) /* Frequency 0 */
#define AX5051_FSKDEV                (*(__IO uint32_t *)(0x02020094 + SPI0_BASE)) /* FSK Deviation */
#define AX5051_FSKDEV2               (*(__IO uint8_t  *)(0x00020094 + SPI0_BASE)) /* FSK Deviation 2 */
#define AX5051_FSKDEV1               (*(__IO uint8_t  *)(0x00020098 + SPI0_BASE)) /* FSK Deviation 1 */
#define AX5051_FSKDEV0               (*(__IO uint8_t  *)(0x0002009C + SPI0_BASE)) /* FSK Deviation 0 */
#define AX5051_IFFREQHI              (*(__IO uint8_t  *)(0x000200A0 + SPI0_BASE)) /* IF Frequency Low */
#define AX5051_IFFREQLO              (*(__IO uint8_t  *)(0x000200A4 + SPI0_BASE)) /* IF Frequency High */
#define AX5051_PLLLOOP               (*(__IO uint8_t  *)(0x000200B0 + SPI0_BASE)) /* PLL Loop Filter */
#define AX5051_PLLRANGING            (*(__IO uint8_t  *)(0x000200B4 + SPI0_BASE)) /* PLL Autoranging Control */
#define AX5051_PLLRNGCLK             (*(__IO uint8_t  *)(0x000200B8 + SPI0_BASE)) /* PLL Autoranging Clock */
#define AX5051_TXPWR                 (*(__IO uint8_t  *)(0x000200C0 + SPI0_BASE)) /* Transmit Power */
#define AX5051_TXBITRATEHI           (*(__IO uint8_t  *)(0x000200C4 + SPI0_BASE)) /* Transmitter Bitrate High */
#define AX5051_TXBITRATEMID          (*(__IO uint8_t  *)(0x000200C8 + SPI0_BASE)) /* Transmitter Bitrate Middle */
#define AX5051_TXBITRATELO           (*(__IO uint8_t  *)(0x000200CC + SPI0_BASE)) /* Transmitter Bitrate Low */
#define AX5051_MODULATORMISC         (*(__IO uint8_t  *)(0x000200D0 + SPI0_BASE)) /* Modulator Miscellaneous Control */
#define AX5051_FIFOCOUNT             (*(__IO uint8_t  *)(0x000200D4 + SPI0_BASE)) /* FIFO Count */
#define AX5051_FIFOTHRESH            (*(__IO uint8_t  *)(0x000200D8 + SPI0_BASE)) /* FIFO Threshold */
#define AX5051_FIFOCONTROL2          (*(__IO uint8_t  *)(0x000200DC + SPI0_BASE)) /* FIFO Control 2 */
#define AX5051_ADCMISC               (*(__IO uint8_t  *)(0x000200E0 + SPI0_BASE)) /* ADC Miscellaneous Control */
#define AX5051_AGCTARGET             (*(__IO uint8_t  *)(0x000200E4 + SPI0_BASE)) /* AGC Target Value */
#define AX5051_AGCATTACK             (*(__IO uint8_t  *)(0x000200E8 + SPI0_BASE)) /* AGC Attack Speed */
#define AX5051_AGCDECAY              (*(__IO uint8_t  *)(0x000200EC + SPI0_BASE)) /* AGC Decay Speed */
#define AX5051_AGCCOUNTER            (*(__IO uint8_t  *)(0x000200F0 + SPI0_BASE)) /* AGC Counter */
#define AX5051_CICSHIFT              (*(__IO uint8_t  *)(0x000200F4 + SPI0_BASE)) /* Decimation Filter Attenuation */
#define AX5051_CICDECHI              (*(__IO uint8_t  *)(0x000200F8 + SPI0_BASE)) /* Decimation Factor High */
#define AX5051_CICDECLO              (*(__IO uint8_t  *)(0x000200FC + SPI0_BASE)) /* Decimation Factor Low */
#define AX5051_DATARATEHI            (*(__IO uint8_t  *)(0x00020100 + SPI0_BASE)) /* Datarate High */
#define AX5051_DATARATELO            (*(__IO uint8_t  *)(0x00020104 + SPI0_BASE)) /* Datarate Low */
#define AX5051_TIMINGGAINHI          (*(__IO uint8_t  *)(0x00020108 + SPI0_BASE)) /* Timing Estimator Bandwidth High */
#define AX5051_TIMINGGAINLO          (*(__IO uint8_t  *)(0x0002010C + SPI0_BASE)) /* Timing Estimator Bandwidth Low */
#define AX5051_PHASEGAIN             (*(__IO uint8_t  *)(0x00020110 + SPI0_BASE)) /* Phase Estimator Bandwidth */
#define AX5051_FREQUENCYGAIN         (*(__IO uint8_t  *)(0x00020114 + SPI0_BASE)) /* Frequency Estimator Bandwidth */
#define AX5051_FREQUENCYGAIN2        (*(__IO uint8_t  *)(0x00020118 + SPI0_BASE)) /* Frequency Estimator Bandwidth 2 */
#define AX5051_AMPLITUDEGAIN         (*(__IO uint8_t  *)(0x0002011C + SPI0_BASE)) /* Amplitude Estimator Bandwidth */
#define AX5051_TRKAMPLITUDEHI        (*(__IO uint8_t  *)(0x00020120 + SPI0_BASE)) /* Amplitude Tracking High */
#define AX5051_TRKAMPLITUDELO        (*(__IO uint8_t  *)(0x00020124 + SPI0_BASE)) /* Amplitude Tracking Low */
#define AX5051_TRKPHASEHI            (*(__IO uint8_t  *)(0x00020128 + SPI0_BASE)) /* Phase Tracking High */
#define AX5051_TRKPHASELO            (*(__IO uint8_t  *)(0x0002012C + SPI0_BASE)) /* Phase Tracking Low */
#define AX5051_TRKFREQHI             (*(__IO uint8_t  *)(0x00020130 + SPI0_BASE)) /* Frequency Tracking High */
#define AX5051_TRKFREQLO             (*(__IO uint8_t  *)(0x00020134 + SPI0_BASE)) /* Frequency Tracking Low */
#define AX5051_XTALCAP               (*(__IO uint8_t  *)(0x0002013C + SPI0_BASE)) /* Crystal Oscillator Load Capacitance */
#define AX5051_FECMEM                (*(__IO uint8_t  *)(0x000201BC + SPI0_BASE)) /* Forward Error Correction Memory */
#define AX5051_PLLVCOI               (*(__IO uint8_t  *)(0x000201C8 + SPI0_BASE)) /* PLL VCO Current */
#define AX5051_RFMISC                (*(__IO uint8_t  *)(0x000201E8 + SPI0_BASE)) /* RF Miscellaneous Control */
#define AX5051_REF                   (*(__IO uint8_t  *)(0x000201F0 + SPI0_BASE)) /* Reference */
#define AX5051_RXMISC                (*(__IO uint8_t  *)(0x000201F4 + SPI0_BASE)) /* Receiver Miscellaneous Control */
#define AX5051_SILICONREVISIONNB     (*(__IO uint8_t  *)(0x00060000 + SPI0_BASE)) /* Silicon Revision, non-blocking */
#define AX5051_SCRATCHNB             (*(__IO uint8_t  *)(0x00060004 + SPI0_BASE)) /* Scratch, non-blocking */
#define AX5051_PWRMODENB             (*(__IO uint8_t  *)(0x00060008 + SPI0_BASE)) /* Power Mode, non-blocking */
#define AX5051_XTALOSCNB             (*(__IO uint8_t  *)(0x0006000C + SPI0_BASE)) /* Crystal Oscillator Control, non-blocking */
#define AX5051_FIFOCONTROLNB         (*(__IO uint8_t  *)(0x00060010 + SPI0_BASE)) /* FIFO Control, non-blocking */
#define AX5051_FIFODATANB            (*(__IO uint8_t  *)(0x00060014 + SPI0_BASE)) /* FIFO Data, non-blocking */
#define AX5051_IRQMASKNB             (*(__IO uint8_t  *)(0x00060018 + SPI0_BASE)) /* IRQ Mask, non-blocking */
#define AX5051_IRQREQUESTNB          (*(__IO uint8_t  *)(0x0006001C + SPI0_BASE)) /* IRQ Request, non-blocking */
#define AX5051_IFMODENB              (*(__IO uint8_t  *)(0x00060020 + SPI0_BASE)) /* Interface Mode, non-blocking */
#define AX5051_DSPMODENB             (*(__IO uint8_t  *)(0x00060024 + SPI0_BASE)) /* DSP Mode Interface Control, non-blocking */
#define AX5051_TXDSPMODENB           (*(__IO uint8_t  *)(0x00060028 + SPI0_BASE)) /* Transmit DSP Mode, non-blocking */
#define AX5051_PINCFG1NB             (*(__IO uint8_t  *)(0x00060030 + SPI0_BASE)) /* Pin Configuration 1, non-blocking */
#define AX5051_PINCFG2NB             (*(__IO uint8_t  *)(0x00060034 + SPI0_BASE)) /* Pin Configuration 2, non-blocking */
#define AX5051_PINCFG3NB             (*(__IO uint8_t  *)(0x00060038 + SPI0_BASE)) /* Pin Configuration 3, non-blocking */
#define AX5051_IRQINVERSIONNB        (*(__IO uint8_t  *)(0x0006003C + SPI0_BASE)) /* IRQ Inversion, non-blocking */
#define AX5051_MODULATIONNB          (*(__IO uint8_t  *)(0x00060040 + SPI0_BASE)) /* Modulation, non-blocking */
#define AX5051_ENCODINGNB            (*(__IO uint8_t  *)(0x00060044 + SPI0_BASE)) /* Encoding, non-blocking */
#define AX5051_FRAMINGNB             (*(__IO uint8_t  *)(0x00060048 + SPI0_BASE)) /* Framing Mode, non-blocking */
#define AX5051_CRCINITNB             (*(__IO uint32_t *)(0x020E0050 + SPI0_BASE)) /* CRC Initial Value, non-blocking */
#define AX5051_CRCINIT3NB            (*(__IO uint8_t  *)(0x00060050 + SPI0_BASE)) /* CRC Initial Value 3, non-blocking */
#define AX5051_CRCINIT2NB            (*(__IO uint8_t  *)(0x00060054 + SPI0_BASE)) /* CRC Initial Value 2, non-blocking */
#define AX5051_CRCINIT1NB            (*(__IO uint8_t  *)(0x00060058 + SPI0_BASE)) /* CRC Initial Value 1, non-blocking */
#define AX5051_CRCINIT0NB            (*(__IO uint8_t  *)(0x0006005C + SPI0_BASE)) /* CRC Initial Value 0, non-blocking */
#define AX5051_FECNB                 (*(__IO uint8_t  *)(0x00060060 + SPI0_BASE)) /* Forward Error Correction, non-blocking */
#define AX5051_FECSYNCNB             (*(__IO uint8_t  *)(0x00060064 + SPI0_BASE)) /* Forward Error Correction Sync Threshold, non-blocking */
#define AX5051_FECSTATUSNB           (*(__IO uint8_t  *)(0x00060068 + SPI0_BASE)) /* Forward Error Correction Status, non-blocking */
#define AX5051_VREGNB                (*(__IO uint8_t  *)(0x0006006C + SPI0_BASE)) /* Voltage Regulator, non-blocking */
#define AX5051_FREQNB                (*(__IO uint32_t *)(0x020E0080 + SPI0_BASE)) /* Frequency, non-blocking */
#define AX5051_FREQ3NB               (*(__IO uint8_t  *)(0x00060080 + SPI0_BASE)) /* Frequency 3, non-blocking */
#define AX5051_FREQANB               (*(__IO uint32_t *)(0x020E0080 + SPI0_BASE)) /* Frequency, non-blocking */
#define AX5051_FREQA3NB              (*(__IO uint8_t  *)(0x00060080 + SPI0_BASE)) /* Frequency 3, non-blocking */
#define AX5051_FREQ2NB               (*(__IO uint8_t  *)(0x00060084 + SPI0_BASE)) /* Frequency 2, non-blocking */
#define AX5051_FREQA2NB              (*(__IO uint8_t  *)(0x00060084 + SPI0_BASE)) /* Frequency 2, non-blocking */
#define AX5051_FREQ1NB               (*(__IO uint8_t  *)(0x00060088 + SPI0_BASE)) /* Frequency 1, non-blocking */
#define AX5051_FREQA1NB              (*(__IO uint8_t  *)(0x00060088 + SPI0_BASE)) /* Frequency 1, non-blocking */
#define AX5051_FREQ0NB               (*(__IO uint8_t  *)(0x0006008C + SPI0_BASE)) /* Frequency 0, non-blocking */
#define AX5051_FREQA0NB              (*(__IO uint8_t  *)(0x0006008C + SPI0_BASE)) /* Frequency 0, non-blocking */
#define AX5051_FSKDEVNB              (*(__IO uint32_t *)(0x02060094 + SPI0_BASE)) /* FSK Deviation, non-blocking */
#define AX5051_FSKDEV2NB             (*(__IO uint8_t  *)(0x00060094 + SPI0_BASE)) /* FSK Deviation 2, non-blocking */
#define AX5051_FSKDEV1NB             (*(__IO uint8_t  *)(0x00060098 + SPI0_BASE)) /* FSK Deviation 1, non-blocking */
#define AX5051_FSKDEV0NB             (*(__IO uint8_t  *)(0x0006009C + SPI0_BASE)) /* FSK Deviation 0, non-blocking */
#define AX5051_IFFREQHINB            (*(__IO uint8_t  *)(0x000600A0 + SPI0_BASE)) /* IF Frequency Low, non-blocking */
#define AX5051_IFFREQLONB            (*(__IO uint8_t  *)(0x000600A4 + SPI0_BASE)) /* IF Frequency High, non-blocking */
#define AX5051_PLLLOOPNB             (*(__IO uint8_t  *)(0x000600B0 + SPI0_BASE)) /* PLL Loop Filter, non-blocking */
#define AX5051_PLLRANGINGNB          (*(__IO uint8_t  *)(0x000600B4 + SPI0_BASE)) /* PLL Autoranging Control, non-blocking */
#define AX5051_PLLRNGCLKNB           (*(__IO uint8_t  *)(0x000600B8 + SPI0_BASE)) /* PLL Autoranging Clock, non-blocking */
#define AX5051_TXPWRNB               (*(__IO uint8_t  *)(0x000600C0 + SPI0_BASE)) /* Transmit Power, non-blocking */
#define AX5051_TXBITRATEHINB         (*(__IO uint8_t  *)(0x000600C4 + SPI0_BASE)) /* Transmitter Bitrate High, non-blocking */
#define AX5051_TXBITRATEMIDNB        (*(__IO uint8_t  *)(0x000600C8 + SPI0_BASE)) /* Transmitter Bitrate Middle, non-blocking */
#define AX5051_TXBITRATELONB         (*(__IO uint8_t  *)(0x000600CC + SPI0_BASE)) /* Transmitter Bitrate Low, non-blocking */
#define AX5051_MODULATORMISCNB       (*(__IO uint8_t  *)(0x000600D0 + SPI0_BASE)) /* Modulator Miscellaneous Control, non-blocking */
#define AX5051_FIFOCOUNTNB           (*(__IO uint8_t  *)(0x000600D4 + SPI0_BASE)) /* FIFO Count, non-blocking */
#define AX5051_FIFOTHRESHNB          (*(__IO uint8_t  *)(0x000600D8 + SPI0_BASE)) /* FIFO Threshold, non-blocking */
#define AX5051_FIFOCONTROL2NB        (*(__IO uint8_t  *)(0x000600DC + SPI0_BASE)) /* FIFO Control 2, non-blocking */
#define AX5051_ADCMISCNB             (*(__IO uint8_t  *)(0x000600E0 + SPI0_BASE)) /* ADC Miscellaneous Control, non-blocking */
#define AX5051_AGCTARGETNB           (*(__IO uint8_t  *)(0x000600E4 + SPI0_BASE)) /* AGC Target Value, non-blocking */
#define AX5051_AGCATTACKNB           (*(__IO uint8_t  *)(0x000600E8 + SPI0_BASE)) /* AGC Attack Speed, non-blocking */
#define AX5051_AGCDECAYNB            (*(__IO uint8_t  *)(0x000600EC + SPI0_BASE)) /* AGC Decay Speed, non-blocking */
#define AX5051_AGCCOUNTERNB          (*(__IO uint8_t  *)(0x000600F0 + SPI0_BASE)) /* AGC Counter, non-blocking */
#define AX5051_CICSHIFTNB            (*(__IO uint8_t  *)(0x000600F4 + SPI0_BASE)) /* Decimation Filter Attenuation, non-blocking */
#define AX5051_CICDECHINB            (*(__IO uint8_t  *)(0x000600F8 + SPI0_BASE)) /* Decimation Factor High, non-blocking */
#define AX5051_CICDECLONB            (*(__IO uint8_t  *)(0x000600FC + SPI0_BASE)) /* Decimation Factor Low, non-blocking */
#define AX5051_DATARATEHINB          (*(__IO uint8_t  *)(0x00060100 + SPI0_BASE)) /* Datarate High, non-blocking */
#define AX5051_DATARATELONB          (*(__IO uint8_t  *)(0x00060104 + SPI0_BASE)) /* Datarate Low, non-blocking */
#define AX5051_TIMINGGAINHINB        (*(__IO uint8_t  *)(0x00060108 + SPI0_BASE)) /* Timing Estimator Bandwidth High, non-blocking */
#define AX5051_TIMINGGAINLONB        (*(__IO uint8_t  *)(0x0006010C + SPI0_BASE)) /* Timing Estimator Bandwidth Low, non-blocking */
#define AX5051_PHASEGAINNB           (*(__IO uint8_t  *)(0x00060110 + SPI0_BASE)) /* Phase Estimator Bandwidth, non-blocking */
#define AX5051_FREQUENCYGAINNB       (*(__IO uint8_t  *)(0x00060114 + SPI0_BASE)) /* Frequency Estimator Bandwidth, non-blocking */
#define AX5051_FREQUENCYGAIN2NB      (*(__IO uint8_t  *)(0x00060118 + SPI0_BASE)) /* Frequency Estimator Bandwidth 2, non-blocking */
#define AX5051_AMPLITUDEGAINNB       (*(__IO uint8_t  *)(0x0006011C + SPI0_BASE)) /* Amplitude Estimator Bandwidth, non-blocking */
#define AX5051_TRKAMPLITUDEHINB      (*(__IO uint8_t  *)(0x00060120 + SPI0_BASE)) /* Amplitude Tracking High, non-blocking */
#define AX5051_TRKAMPLITUDELONB      (*(__IO uint8_t  *)(0x00060124 + SPI0_BASE)) /* Amplitude Tracking Low, non-blocking */
#define AX5051_TRKPHASEHINB          (*(__IO uint8_t  *)(0x00060128 + SPI0_BASE)) /* Phase Tracking High, non-blocking */
#define AX5051_TRKPHASELONB          (*(__IO uint8_t  *)(0x0006012C + SPI0_BASE)) /* Phase Tracking Low, non-blocking */
#define AX5051_TRKFREQHINB           (*(__IO uint8_t  *)(0x00060130 + SPI0_BASE)) /* Frequency Tracking High, non-blocking */
#define AX5051_TRKFREQLONB           (*(__IO uint8_t  *)(0x00060134 + SPI0_BASE)) /* Frequency Tracking Low, non-blocking */
#define AX5051_XTALCAPNB             (*(__IO uint8_t  *)(0x0006013C + SPI0_BASE)) /* Crystal Oscillator Load Capacitance, non-blocking */
#define AX5051_FECMEMNB              (*(__IO uint8_t  *)(0x000601BC + SPI0_BASE)) /* Forward Error Correction Memory, non-blocking */
#define AX5051_PLLVCOINB             (*(__IO uint8_t  *)(0x000601C8 + SPI0_BASE)) /* PLL VCO Current, non-blocking */
#define AX5051_RFMISCNB              (*(__IO uint8_t  *)(0x000601E8 + SPI0_BASE)) /* RF Miscellaneous Control, non-blocking */
#define AX5051_REFNB                 (*(__IO uint8_t  *)(0x000601F0 + SPI0_BASE)) /* Reference, non-blocking */
#define AX5051_RXMISCNB              (*(__IO uint8_t  *)(0x000601F4 + SPI0_BASE)) /* Receiver Miscellaneous Control, non-blocking */

#define AX5051_REG_SILICONREVISION   0x0000 /* Silicon Revision */
#define AX5051_REG_SCRATCH           0x0001 /* Scratch */
#define AX5051_REG_PWRMODE           0x0002 /* Power Mode */
#define AX5051_REG_XTALOSC           0x0003 /* Crystal Oscillator Control */
#define AX5051_REG_FIFOCONTROL       0x0004 /* FIFO Control */
#define AX5051_REG_FIFODATA          0x0005 /* FIFO Data */
#define AX5051_REG_IRQMASK           0x0006 /* IRQ Mask */
#define AX5051_REG_IRQREQUEST        0x0007 /* IRQ Request */
#define AX5051_REG_IFMODE            0x0008 /* Interface Mode */
#define AX5051_REG_DSPMODE           0x0009 /* DSP Mode Interface Control */
#define AX5051_REG_TXDSPMODE         0x000A /* Transmit DSP Mode */
#define AX5051_REG_PINCFG1           0x000C /* Pin Configuration 1 */
#define AX5051_REG_PINCFG2           0x000D /* Pin Configuration 2 */
#define AX5051_REG_PINCFG3           0x000E /* Pin Configuration 3 */
#define AX5051_REG_IRQINVERSION      0x000F /* IRQ Inversion */
#define AX5051_REG_MODULATION        0x0010 /* Modulation */
#define AX5051_REG_ENCODING          0x0011 /* Encoding */
#define AX5051_REG_FRAMING           0x0012 /* Framing Mode */
#define AX5051_REG_CRCINIT3          0x0014 /* CRC Initial Value 3 */
#define AX5051_REG_CRCINIT2          0x0015 /* CRC Initial Value 2 */
#define AX5051_REG_CRCINIT1          0x0016 /* CRC Initial Value 1 */
#define AX5051_REG_CRCINIT0          0x0017 /* CRC Initial Value 0 */
#define AX5051_REG_FEC               0x0018 /* Forward Error Correction */
#define AX5051_REG_FECSYNC           0x0019 /* Forward Error Correction Sync Threshold */
#define AX5051_REG_FECSTATUS         0x001A /* Forward Error Correction Status */
#define AX5051_REG_VREG              0x001B /* Voltage Regulator */
#define AX5051_REG_FREQ3             0x0020 /* Frequency 3 */
#define AX5051_REG_FREQA3            0x0020 /* Frequency 3 */
#define AX5051_REG_FREQ2             0x0021 /* Frequency 2 */
#define AX5051_REG_FREQA2            0x0021 /* Frequency 2 */
#define AX5051_REG_FREQ1             0x0022 /* Frequency 1 */
#define AX5051_REG_FREQA1            0x0022 /* Frequency 1 */
#define AX5051_REG_FREQ0             0x0023 /* Frequency 0 */
#define AX5051_REG_FREQA0            0x0023 /* Frequency 0 */
#define AX5051_REG_FSKDEV2           0x0025 /* FSK Deviation 2 */
#define AX5051_REG_FSKDEV1           0x0026 /* FSK Deviation 1 */
#define AX5051_REG_FSKDEV0           0x0027 /* FSK Deviation 0 */
#define AX5051_REG_IFFREQHI          0x0028 /* IF Frequency Low */
#define AX5051_REG_IFFREQLO          0x0029 /* IF Frequency High */
#define AX5051_REG_PLLLOOP           0x002C /* PLL Loop Filter */
#define AX5051_REG_PLLRANGING        0x002D /* PLL Autoranging Control */
#define AX5051_REG_PLLRNGCLK         0x002E /* PLL Autoranging Clock */
#define AX5051_REG_TXPWR             0x0030 /* Transmit Power */
#define AX5051_REG_TXBITRATEHI       0x0031 /* Transmitter Bitrate High */
#define AX5051_REG_TXBITRATEMID      0x0032 /* Transmitter Bitrate Middle */
#define AX5051_REG_TXBITRATELO       0x0033 /* Transmitter Bitrate Low */
#define AX5051_REG_MODULATORMISC     0x0034 /* Modulator Miscellaneous Control */
#define AX5051_REG_FIFOCOUNT         0x0035 /* FIFO Count */
#define AX5051_REG_FIFOTHRESH        0x0036 /* FIFO Threshold */
#define AX5051_REG_FIFOCONTROL2      0x0037 /* FIFO Control 2 */
#define AX5051_REG_ADCMISC           0x0038 /* ADC Miscellaneous Control */
#define AX5051_REG_AGCTARGET         0x0039 /* AGC Target Value */
#define AX5051_REG_AGCATTACK         0x003A /* AGC Attack Speed */
#define AX5051_REG_AGCDECAY          0x003B /* AGC Decay Speed */
#define AX5051_REG_AGCCOUNTER        0x003C /* AGC Counter */
#define AX5051_REG_CICSHIFT          0x003D /* Decimation Filter Attenuation */
#define AX5051_REG_CICDECHI          0x003E /* Decimation Factor High */
#define AX5051_REG_CICDECLO          0x003F /* Decimation Factor Low */
#define AX5051_REG_DATARATEHI        0x0040 /* Datarate High */
#define AX5051_REG_DATARATELO        0x0041 /* Datarate Low */
#define AX5051_REG_TIMINGGAINHI      0x0042 /* Timing Estimator Bandwidth High */
#define AX5051_REG_TIMINGGAINLO      0x0043 /* Timing Estimator Bandwidth Low */
#define AX5051_REG_PHASEGAIN         0x0044 /* Phase Estimator Bandwidth */
#define AX5051_REG_FREQUENCYGAIN     0x0045 /* Frequency Estimator Bandwidth */
#define AX5051_REG_FREQUENCYGAIN2    0x0046 /* Frequency Estimator Bandwidth 2 */
#define AX5051_REG_AMPLITUDEGAIN     0x0047 /* Amplitude Estimator Bandwidth */
#define AX5051_REG_TRKAMPLITUDEHI    0x0048 /* Amplitude Tracking High */
#define AX5051_REG_TRKAMPLITUDELO    0x0049 /* Amplitude Tracking Low */
#define AX5051_REG_TRKPHASEHI        0x004A /* Phase Tracking High */
#define AX5051_REG_TRKPHASELO        0x004B /* Phase Tracking Low */
#define AX5051_REG_TRKFREQHI         0x004C /* Frequency Tracking High */
#define AX5051_REG_TRKFREQLO         0x004D /* Frequency Tracking Low */
#define AX5051_REG_XTALCAP           0x004F /* Crystal Oscillator Load Capacitance */
#define AX5051_REG_FECMEM            0x006F /* Forward Error Correction Memory */
#define AX5051_REG_PLLVCOI           0x0072 /* PLL VCO Current */
#define AX5051_REG_RFMISC            0x007A /* RF Miscellaneous Control */
#define AX5051_REG_REF               0x007C /* Reference */
#define AX5051_REG_RXMISC            0x007D /* Receiver Miscellaneous Control */

#endif /* AXM0F151_H */
