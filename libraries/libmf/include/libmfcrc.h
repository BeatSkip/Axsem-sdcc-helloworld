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

#ifndef LIBMFCRC_H
#define LIBMFCRC_H

#include "libmftypes.h"

/*
 * CRC-16 CCITT
 */
extern __reentrantb uint16_t crc_ccitt_byte(uint16_t crc, uint8_t c) __reentrant;
extern __reentrantb uint16_t crc_ccitt_msb_byte(uint16_t crc, uint8_t c) __reentrant;
extern __reentrantb uint16_t crc_ccitt(const uint8_t __genericaddr *buf, uint16_t buflen, uint16_t crc) __reentrant;
extern __reentrantb uint16_t crc_ccitt_msb(const uint8_t __genericaddr *buf, uint16_t buflen, uint16_t crc) __reentrant;
extern const uint16_t __code crc_ccitt_table[256];
extern const uint16_t __code crc_ccitt_msbtable[256];

/*
 * CRC-16
 */
extern __reentrantb uint16_t crc_crc16_byte(uint16_t crc, uint8_t c) __reentrant;
extern __reentrantb uint16_t crc_crc16_msb_byte(uint16_t crc, uint8_t c) __reentrant;
extern __reentrantb uint16_t crc_crc16(const uint8_t __genericaddr *buf, uint16_t buflen, uint16_t crc) __reentrant;
extern __reentrantb uint16_t crc_crc16_msb(const uint8_t __genericaddr *buf, uint16_t buflen, uint16_t crc) __reentrant;
extern const uint16_t __code crc_crc16_table[256];
extern const uint16_t __code crc_crc16_msbtable[256];

/*
 * CRC-16 DNP
 */
extern __reentrantb uint16_t crc_crc16dnp_byte(uint16_t crc, uint8_t c) __reentrant;
extern __reentrantb uint16_t crc_crc16dnp_msb_byte(uint16_t crc, uint8_t c) __reentrant;
extern __reentrantb uint16_t crc_crc16dnp(const uint8_t __genericaddr *buf, uint16_t buflen, uint16_t crc) __reentrant;
extern __reentrantb uint16_t crc_crc16dnp_msb(const uint8_t __genericaddr *buf, uint16_t buflen, uint16_t crc) __reentrant;
extern const uint16_t __code crc_crc16dnp_table[256];
extern const uint16_t __code crc_crc16dnp_msbtable[256];

/*
 * CRC-32
 */
extern __reentrantb uint32_t crc_crc32_byte(uint32_t crc, uint8_t c) __reentrant;
extern __reentrantb uint32_t crc_crc32_msb_byte(uint32_t crc, uint8_t c) __reentrant;
extern __reentrantb uint32_t crc_crc32(const uint8_t __genericaddr *buf, uint16_t buflen, uint32_t crc) __reentrant;
extern __reentrantb uint32_t crc_crc32_msb(const uint8_t __genericaddr *buf, uint16_t buflen, uint32_t crc) __reentrant;
extern const uint32_t __code crc_crc32_table[256];
extern const uint32_t __code crc_crc32_msbtable[256];

/*
 * CRC-8 CCITT
 */

extern __reentrantb uint8_t crc_crc8ccitt_byte(uint8_t crc, uint8_t c) __reentrant;
extern __reentrantb uint8_t crc_crc8ccitt_msb_byte(uint8_t crc, uint8_t c) __reentrant;
extern __reentrantb uint8_t crc_crc8ccitt(const uint8_t __genericaddr *buf, uint16_t buflen, uint8_t crc) __reentrant;
extern __reentrantb uint8_t crc_crc8ccitt_msb(const uint8_t __genericaddr *buf, uint16_t buflen, uint8_t crc) __reentrant;
extern const uint8_t __code crc_crc8ccitt_table[256];
extern const uint8_t __code crc_crc8ccitt_msbtable[256];

/*
 * CRC-8 OneWire
 */

extern __reentrantb uint8_t crc_crc8onewire_byte(uint8_t crc, uint8_t c) __reentrant;
extern __reentrantb uint8_t crc_crc8onewire_msb_byte(uint8_t crc, uint8_t c) __reentrant;
extern __reentrantb uint8_t crc_crc8onewire(const uint8_t __genericaddr *buf, uint16_t buflen, uint8_t crc) __reentrant;
extern __reentrantb uint8_t crc_crc8onewire_msb(const uint8_t __genericaddr *buf, uint16_t buflen, uint8_t crc) __reentrant;
extern const uint8_t __code crc_crc8onewire_table[256];
extern const uint8_t __code crc_crc8onewire_msbtable[256];

/*
 * CRC-8 CCITT, non-table driven routines (slower, but more compact)
 */
extern __reentrantb uint8_t crc8_ccitt_byte(uint8_t crc, uint8_t c) __reentrant;
extern __reentrantb uint8_t crc8_ccitt(const uint8_t __genericaddr *buf, uint8_t len, uint8_t init) __reentrant;

/*
 * CRC-8 OneWire, non-table driven routines (slower, but more compact)
 */
extern __reentrantb uint8_t crc8_onewire_byte(uint8_t crc, uint8_t c) __reentrant;
extern __reentrantb uint8_t crc8_onewire(const uint8_t __genericaddr *buf, uint8_t len, uint8_t init) __reentrant;

/*
 * PN9 Whitening Sequence
 */
extern __reentrantb uint16_t pn9_advance(uint16_t pn9) __reentrant;
extern const uint8_t __code pn9_table[512];
extern __reentrantb uint16_t pn9_advance_bit(uint16_t pn9) __reentrant;
extern __reentrantb uint16_t pn9_advance_bits(uint16_t pn9, uint16_t bits) __reentrant;
extern __reentrantb uint16_t pn9_advance_byte(uint16_t pn9) __reentrant;
extern __reentrantb uint16_t pn9_buffer(uint8_t __genericaddr *buf, uint16_t buflen, uint16_t pn9, uint8_t xor) __reentrant;

/*
 * PN15 Whitening Sequence
 */
extern __reentrantb uint16_t pn15_advance(uint16_t pn15) __reentrant;
extern __reentrantb uint8_t pn15_output(uint16_t pn15) __reentrant;
extern const uint16_t __code pn15_adv_table[256];
extern const uint8_t __code pn15_out_table[256];

#endif /* LIBMFCRC_H */
