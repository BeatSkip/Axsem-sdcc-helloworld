/**
******************************************************************************
* @file axm0f131.h
* @brief Macro definition for AX5031 radio registers
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

#ifndef AXM0F131_H
#define AXM0F131_H

#include <axm0.h>

#define AX5031_SILICONREVISION       (*(__IO uint8_t  *)(0x00020000 + SPI0_BASE)) /* Silicon Revision */
#define AX5031_SCRATCH               (*(__IO uint8_t  *)(0x00020004 + SPI0_BASE)) /* Scratch */
#define AX5031_PWRMODE               (*(__IO uint8_t  *)(0x00020008 + SPI0_BASE)) /* Power Mode */
#define AX5031_XTALOSC               (*(__IO uint8_t  *)(0x0002000C + SPI0_BASE)) /* Crystal Oscillator Control */
#define AX5031_FIFOCONTROL           (*(__IO uint8_t  *)(0x00020010 + SPI0_BASE)) /* FIFO Control */
#define AX5031_FIFODATA              (*(__IO uint8_t  *)(0x00020014 + SPI0_BASE)) /* FIFO Data */
#define AX5031_IRQMASK               (*(__IO uint8_t  *)(0x00020018 + SPI0_BASE)) /* IRQ Mask */
#define AX5031_IRQREQUEST            (*(__IO uint8_t  *)(0x0002001C + SPI0_BASE)) /* IRQ Request */
#define AX5031_IFMODE                (*(__IO uint8_t  *)(0x00020020 + SPI0_BASE)) /* Interface Mode */
#define AX5031_PINCFG1               (*(__IO uint8_t  *)(0x00020030 + SPI0_BASE)) /* Pin Configuration 1 */
#define AX5031_PINCFG2               (*(__IO uint8_t  *)(0x00020034 + SPI0_BASE)) /* Pin Configuration 2 */
#define AX5031_PINCFG3               (*(__IO uint8_t  *)(0x00020038 + SPI0_BASE)) /* Pin Configuration 3 */
#define AX5031_IRQINVERSION          (*(__IO uint8_t  *)(0x0002003C + SPI0_BASE)) /* IRQ Inversion */
#define AX5031_MODULATION            (*(__IO uint8_t  *)(0x00020040 + SPI0_BASE)) /* Modulation */
#define AX5031_ENCODING              (*(__IO uint8_t  *)(0x00020044 + SPI0_BASE)) /* Encoding */
#define AX5031_FRAMING               (*(__IO uint8_t  *)(0x00020048 + SPI0_BASE)) /* Framing Mode */
#define AX5031_CRCINIT               (*(__IO uint32_t *)(0x020A0050 + SPI0_BASE)) /* CRC Initial Value */
#define AX5031_CRCINIT3              (*(__IO uint8_t  *)(0x00020050 + SPI0_BASE)) /* CRC Initial Value 3 */
#define AX5031_CRCINIT2              (*(__IO uint8_t  *)(0x00020054 + SPI0_BASE)) /* CRC Initial Value 2 */
#define AX5031_CRCINIT1              (*(__IO uint8_t  *)(0x00020058 + SPI0_BASE)) /* CRC Initial Value 1 */
#define AX5031_CRCINIT0              (*(__IO uint8_t  *)(0x0002005C + SPI0_BASE)) /* CRC Initial Value 0 */
#define AX5031_FEC                   (*(__IO uint8_t  *)(0x00020060 + SPI0_BASE)) /* Forward Error Correction */
#define AX5031_VREG                  (*(__IO uint8_t  *)(0x0002006C + SPI0_BASE)) /* Voltage Regulator */
#define AX5031_FREQB                 (*(__IO uint32_t *)(0x020A0070 + SPI0_BASE)) /* Frequency B */
#define AX5031_FREQB3                (*(__IO uint8_t  *)(0x00020070 + SPI0_BASE)) /* Frequency B 3 */
#define AX5031_FREQB2                (*(__IO uint8_t  *)(0x00020074 + SPI0_BASE)) /* Frequency B 2 */
#define AX5031_FREQB1                (*(__IO uint8_t  *)(0x00020078 + SPI0_BASE)) /* Frequency B 1 */
#define AX5031_FREQB0                (*(__IO uint8_t  *)(0x0002007C + SPI0_BASE)) /* Frequency B 0 */
#define AX5031_FREQA                 (*(__IO uint32_t *)(0x020A0080 + SPI0_BASE)) /* Frequency A */
#define AX5031_FREQA3                (*(__IO uint8_t  *)(0x00020080 + SPI0_BASE)) /* Frequency A 3 */
#define AX5031_FREQA2                (*(__IO uint8_t  *)(0x00020084 + SPI0_BASE)) /* Frequency A 2 */
#define AX5031_FREQA1                (*(__IO uint8_t  *)(0x00020088 + SPI0_BASE)) /* Frequency A 1 */
#define AX5031_FREQA0                (*(__IO uint8_t  *)(0x0002008C + SPI0_BASE)) /* Frequency A 0 */
#define AX5031_FSKDEV                (*(__IO uint32_t *)(0x02020094 + SPI0_BASE)) /* FSK Deviation */
#define AX5031_FSKDEV2               (*(__IO uint8_t  *)(0x00020094 + SPI0_BASE)) /* FSK Deviation 2 */
#define AX5031_FSKDEV1               (*(__IO uint8_t  *)(0x00020098 + SPI0_BASE)) /* FSK Deviation 1 */
#define AX5031_FSKDEV0               (*(__IO uint8_t  *)(0x0002009C + SPI0_BASE)) /* FSK Deviation 0 */
#define AX5031_PLLLOOP               (*(__IO uint8_t  *)(0x000200B0 + SPI0_BASE)) /* PLL Loop Filter */
#define AX5031_PLLRANGING            (*(__IO uint8_t  *)(0x000200B4 + SPI0_BASE)) /* PLL Autoranging Control */
#define AX5031_PLLRNGCLK             (*(__IO uint8_t  *)(0x000200B8 + SPI0_BASE)) /* PLL Autoranging Clock */
#define AX5031_TXPWR                 (*(__IO uint8_t  *)(0x000200C0 + SPI0_BASE)) /* Transmit Power */
#define AX5031_TXBITRATEHI           (*(__IO uint8_t  *)(0x000200C4 + SPI0_BASE)) /* Transmitter Bitrate High */
#define AX5031_TXBITRATEMID          (*(__IO uint8_t  *)(0x000200C8 + SPI0_BASE)) /* Transmitter Bitrate Middle */
#define AX5031_TXBITRATELO           (*(__IO uint8_t  *)(0x000200CC + SPI0_BASE)) /* Transmitter Bitrate Low */
#define AX5031_MODULATORMISC         (*(__IO uint8_t  *)(0x000200D0 + SPI0_BASE)) /* Modulator Miscellaneous Control */
#define AX5031_FIFOCOUNT             (*(__IO uint8_t  *)(0x000200D4 + SPI0_BASE)) /* FIFO Count */
#define AX5031_FIFOTHRESH            (*(__IO uint8_t  *)(0x000200D8 + SPI0_BASE)) /* FIFO Threshold */
#define AX5031_FIFOCONTROL2          (*(__IO uint8_t  *)(0x000200DC + SPI0_BASE)) /* FIFO Control 2 */
#define AX5031_XTALCAP               (*(__IO uint8_t  *)(0x0002013C + SPI0_BASE)) /* Crystal Oscillator Load Capacitance */
#define AX5031_FOURFSK               (*(__IO uint8_t  *)(0x00020140 + SPI0_BASE)) /* 4-FSK Control */
#define AX5031_XTALOSCCFG            (*(__IO uint8_t  *)(0x00020144 + SPI0_BASE)) /* Crystal Oscillator Mode Configuration */
#define AX5031_SILICONREVISIONNB     (*(__IO uint8_t  *)(0x00060000 + SPI0_BASE)) /* Silicon Revision, non-blocking */
#define AX5031_SCRATCHNB             (*(__IO uint8_t  *)(0x00060004 + SPI0_BASE)) /* Scratch, non-blocking */
#define AX5031_PWRMODENB             (*(__IO uint8_t  *)(0x00060008 + SPI0_BASE)) /* Power Mode, non-blocking */
#define AX5031_XTALOSCNB             (*(__IO uint8_t  *)(0x0006000C + SPI0_BASE)) /* Crystal Oscillator Control, non-blocking */
#define AX5031_FIFOCONTROLNB         (*(__IO uint8_t  *)(0x00060010 + SPI0_BASE)) /* FIFO Control, non-blocking */
#define AX5031_FIFODATANB            (*(__IO uint8_t  *)(0x00060014 + SPI0_BASE)) /* FIFO Data, non-blocking */
#define AX5031_IRQMASKNB             (*(__IO uint8_t  *)(0x00060018 + SPI0_BASE)) /* IRQ Mask, non-blocking */
#define AX5031_IRQREQUESTNB          (*(__IO uint8_t  *)(0x0006001C + SPI0_BASE)) /* IRQ Request, non-blocking */
#define AX5031_IFMODENB              (*(__IO uint8_t  *)(0x00060020 + SPI0_BASE)) /* Interface Mode, non-blocking */
#define AX5031_PINCFG1NB             (*(__IO uint8_t  *)(0x00060030 + SPI0_BASE)) /* Pin Configuration 1, non-blocking */
#define AX5031_PINCFG2NB             (*(__IO uint8_t  *)(0x00060034 + SPI0_BASE)) /* Pin Configuration 2, non-blocking */
#define AX5031_PINCFG3NB             (*(__IO uint8_t  *)(0x00060038 + SPI0_BASE)) /* Pin Configuration 3, non-blocking */
#define AX5031_IRQINVERSIONNB        (*(__IO uint8_t  *)(0x0006003C + SPI0_BASE)) /* IRQ Inversion, non-blocking */
#define AX5031_MODULATIONNB          (*(__IO uint8_t  *)(0x00060040 + SPI0_BASE)) /* Modulation, non-blocking */
#define AX5031_ENCODINGNB            (*(__IO uint8_t  *)(0x00060044 + SPI0_BASE)) /* Encoding, non-blocking */
#define AX5031_FRAMINGNB             (*(__IO uint8_t  *)(0x00060048 + SPI0_BASE)) /* Framing Mode, non-blocking */
#define AX5031_CRCINITNB             (*(__IO uint32_t *)(0x020E0050 + SPI0_BASE)) /* CRC Initial Value, non-blocking */
#define AX5031_CRCINIT3NB            (*(__IO uint8_t  *)(0x00060050 + SPI0_BASE)) /* CRC Initial Value 3, non-blocking */
#define AX5031_CRCINIT2NB            (*(__IO uint8_t  *)(0x00060054 + SPI0_BASE)) /* CRC Initial Value 2, non-blocking */
#define AX5031_CRCINIT1NB            (*(__IO uint8_t  *)(0x00060058 + SPI0_BASE)) /* CRC Initial Value 1, non-blocking */
#define AX5031_CRCINIT0NB            (*(__IO uint8_t  *)(0x0006005C + SPI0_BASE)) /* CRC Initial Value 0, non-blocking */
#define AX5031_FECNB                 (*(__IO uint8_t  *)(0x00060060 + SPI0_BASE)) /* Forward Error Correction, non-blocking */
#define AX5031_VREGNB                (*(__IO uint8_t  *)(0x0006006C + SPI0_BASE)) /* Voltage Regulator, non-blocking */
#define AX5031_FREQBNB               (*(__IO uint32_t *)(0x020E0070 + SPI0_BASE)) /* Frequency B, non-blocking */
#define AX5031_FREQB3NB              (*(__IO uint8_t  *)(0x00060070 + SPI0_BASE)) /* Frequency B 3, non-blocking */
#define AX5031_FREQB2NB              (*(__IO uint8_t  *)(0x00060074 + SPI0_BASE)) /* Frequency B 2, non-blocking */
#define AX5031_FREQB1NB              (*(__IO uint8_t  *)(0x00060078 + SPI0_BASE)) /* Frequency B 1, non-blocking */
#define AX5031_FREQB0NB              (*(__IO uint8_t  *)(0x0006007C + SPI0_BASE)) /* Frequency B 0, non-blocking */
#define AX5031_FREQANB               (*(__IO uint32_t *)(0x020E0080 + SPI0_BASE)) /* Frequency A, non-blocking */
#define AX5031_FREQA3NB              (*(__IO uint8_t  *)(0x00060080 + SPI0_BASE)) /* Frequency A 3, non-blocking */
#define AX5031_FREQA2NB              (*(__IO uint8_t  *)(0x00060084 + SPI0_BASE)) /* Frequency A 2, non-blocking */
#define AX5031_FREQA1NB              (*(__IO uint8_t  *)(0x00060088 + SPI0_BASE)) /* Frequency A 1, non-blocking */
#define AX5031_FREQA0NB              (*(__IO uint8_t  *)(0x0006008C + SPI0_BASE)) /* Frequency A 0, non-blocking */
#define AX5031_FSKDEVNB              (*(__IO uint32_t *)(0x02060094 + SPI0_BASE)) /* FSK Deviation, non-blocking */
#define AX5031_FSKDEV2NB             (*(__IO uint8_t  *)(0x00060094 + SPI0_BASE)) /* FSK Deviation 2, non-blocking */
#define AX5031_FSKDEV1NB             (*(__IO uint8_t  *)(0x00060098 + SPI0_BASE)) /* FSK Deviation 1, non-blocking */
#define AX5031_FSKDEV0NB             (*(__IO uint8_t  *)(0x0006009C + SPI0_BASE)) /* FSK Deviation 0, non-blocking */
#define AX5031_PLLLOOPNB             (*(__IO uint8_t  *)(0x000600B0 + SPI0_BASE)) /* PLL Loop Filter, non-blocking */
#define AX5031_PLLRANGINGNB          (*(__IO uint8_t  *)(0x000600B4 + SPI0_BASE)) /* PLL Autoranging Control, non-blocking */
#define AX5031_PLLRNGCLKNB           (*(__IO uint8_t  *)(0x000600B8 + SPI0_BASE)) /* PLL Autoranging Clock, non-blocking */
#define AX5031_TXPWRNB               (*(__IO uint8_t  *)(0x000600C0 + SPI0_BASE)) /* Transmit Power, non-blocking */
#define AX5031_TXBITRATEHINB         (*(__IO uint8_t  *)(0x000600C4 + SPI0_BASE)) /* Transmitter Bitrate High, non-blocking */
#define AX5031_TXBITRATEMIDNB        (*(__IO uint8_t  *)(0x000600C8 + SPI0_BASE)) /* Transmitter Bitrate Middle, non-blocking */
#define AX5031_TXBITRATELONB         (*(__IO uint8_t  *)(0x000600CC + SPI0_BASE)) /* Transmitter Bitrate Low, non-blocking */
#define AX5031_MODULATORMISCNB       (*(__IO uint8_t  *)(0x000600D0 + SPI0_BASE)) /* Modulator Miscellaneous Control, non-blocking */
#define AX5031_FIFOCOUNTNB           (*(__IO uint8_t  *)(0x000600D4 + SPI0_BASE)) /* FIFO Count, non-blocking */
#define AX5031_FIFOTHRESHNB          (*(__IO uint8_t  *)(0x000600D8 + SPI0_BASE)) /* FIFO Threshold, non-blocking */
#define AX5031_FIFOCONTROL2NB        (*(__IO uint8_t  *)(0x000600DC + SPI0_BASE)) /* FIFO Control 2, non-blocking */
#define AX5031_XTALCAPNB             (*(__IO uint8_t  *)(0x0006013C + SPI0_BASE)) /* Crystal Oscillator Load Capacitance, non-blocking */
#define AX5031_FOURFSKNB             (*(__IO uint8_t  *)(0x00060140 + SPI0_BASE)) /* 4-FSK Control, non-blocking */
#define AX5031_XTALOSCCFGNB          (*(__IO uint8_t  *)(0x00060144 + SPI0_BASE)) /* Crystal Oscillator Mode Configuration, non-blocking */

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

#endif /* AXM0F131_H */
