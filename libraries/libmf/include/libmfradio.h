/**
******************************************************************************
* @file libmfradio.h
* @brief Radio APIs declaration
* @internal
* @author   Thomas Sailer, Pradeep Kumar GR
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
* @ingroup RADIO
*
* @details
*/

#ifndef LIBMFRADIO_H
#define LIBMFRADIO_H

#include "libmftypes.h"

#if defined(SDCC)
#pragma callee_saves radio_read8,radio_read16,radio_read24,radio_read32,radio_write8,radio_write16,radio_write24,radio_write32
#endif

#if defined __ARMEL__ || defined __ARMEB__
extern __reentrantb uint8_t _radio_read8(uint32_t addr) __reentrant;
extern __reentrantb uint16_t _radio_read16(uint32_t addr) __reentrant;
extern __reentrantb uint32_t _radio_read24(uint32_t addr) __reentrant;
extern __reentrantb uint32_t _radio_read32(uint32_t addr) __reentrant;
extern __reentrantb void _radio_write8(uint32_t addr, uint8_t d) __reentrant;
extern __reentrantb void _radio_write16(uint32_t addr, uint16_t d) __reentrant;
extern __reentrantb void _radio_write24(uint32_t addr, uint32_t d) __reentrant;
extern __reentrantb void _radio_write32(uint32_t addr, uint32_t d) __reentrant;

#if defined AXM0_H && defined __GNUC__

static inline __attribute__((always_inline)) __reentrantb volatile uint32_t *_radio_addr(uint32_t addr, uint32_t sizemask)
{
	if (!(addr & 0xC0000000)) {
		addr &= 0xFFFF;
		addr ^= 0x8000;
		addr <<= 2;
	} else {
		addr &= 0x1FFFC;
	}
	addr |= sizemask | SPI0_BASE;
	return (volatile uint32_t *)addr;
}

static inline __attribute__((always_inline)) __reentrantb uint8_t radio_read8(uint32_t addr) __reentrant
{
	if (__builtin_constant_p(addr))
		return *_radio_addr(addr, 0);
	return _radio_read8(addr);
}

static inline __attribute__((always_inline)) __reentrantb uint16_t radio_read16(uint32_t addr) __reentrant
{
	if (__builtin_constant_p(addr))
		return *_radio_addr(addr, 0x00080000);
	return _radio_read16(addr);
}

static inline __attribute__((always_inline)) __reentrantb uint32_t radio_read24(uint32_t addr) __reentrant
{
	if (__builtin_constant_p(addr))
		return (*_radio_addr(addr, 0x02000000)) & 0xFFFFFF;
	return _radio_read24(addr);
}

static inline __attribute__((always_inline)) __reentrantb uint32_t radio_read32(uint32_t addr) __reentrant
{
	if (__builtin_constant_p(addr))
		return *_radio_addr(addr, 0x02080000);
	return _radio_read32(addr);
}

static inline __attribute__((always_inline)) __reentrantb void radio_write8(uint32_t addr, uint8_t d) __reentrant
{
	if (__builtin_constant_p(addr))
		*_radio_addr(addr, 0) = d;
	else
		_radio_write8(addr, d);
}

static inline __attribute__((always_inline)) __reentrantb void radio_write16(uint32_t addr, uint16_t d) __reentrant
{
	if (__builtin_constant_p(addr))
		*_radio_addr(addr, 0x00080000) = d;
	else
		_radio_write16(addr, d);
}

static inline __attribute__((always_inline)) __reentrantb void radio_write24(uint32_t addr, uint32_t d) __reentrant
{
	if (__builtin_constant_p(addr))
		*_radio_addr(addr, 0x02000000) = d;
	else
		_radio_write24(addr, d);
}

static inline __attribute__((always_inline)) __reentrantb void radio_write32(uint32_t addr, uint32_t d) __reentrant
{
	if (__builtin_constant_p(addr))
		*_radio_addr(addr, 0x02080000) = d;
	else
		_radio_write32(addr, d);
}

static inline __attribute__((always_inline)) __reentrantb void radio_write8nb(uint32_t addr, uint8_t d) __reentrant
{
	if (__builtin_constant_p(addr))
		*_radio_addr(addr, 0x00040000) = d;
	else
		_radio_write8(addr, d);
}

static inline __attribute__((always_inline)) __reentrantb void radio_write16nb(uint32_t addr, uint8_t d) __reentrant
{
	if (__builtin_constant_p(addr))
		*_radio_addr(addr, 0x000C0000) = d;
	else
		_radio_write16(addr, d);
}

static inline __attribute__((always_inline)) __reentrantb void radio_write24nb(uint32_t addr, uint8_t d) __reentrant
{
	if (__builtin_constant_p(addr))
		*_radio_addr(addr, 0x02040000) = d;
	else
		_radio_write24(addr, d);
}

static inline __attribute__((always_inline)) __reentrantb void radio_write32nb(uint32_t addr, uint8_t d) __reentrant
{
	if (__builtin_constant_p(addr))
		*_radio_addr(addr, 0x020C0000) = d;
	else
		_radio_write32(addr, d);
}

#else

#define radio_read8(addr) _radio_read8(addr)
#define radio_read16(addr) _radio_read16(addr)
#define radio_read24(addr) _radio_read24(addr)
#define radio_read32(addr) _radio_read32(addr)
#define radio_write8(addr,d) _radio_write8(addr,d)
#define radio_write16(addr,d) _radio_write16(addr,d)
#define radio_write24(addr,d) _radio_write24(addr,d)
#define radio_write32(addr,d) _radio_write32(addr,d)

#define radio_write8nb(addr,d) _radio_write8(addr,d)
#define radio_write16nb(addr,d) _radio_write16(addr,d)
#define radio_write24nb(addr,d) _radio_write24(addr,d)
#define radio_write32nb(addr,d) _radio_write32(addr,d)

#endif

#else /* Other than arm */

#if defined(SDCC)

#if (SDCC < 380) /* SDCC version < 3.8.0 use macro version */

#define radio_read8(addr) *(volatile uint8_t __xdata *)(((addr) & 0xFFF) | 0x4000)
#define radio_write8(addr, d)   do { *(volatile uint8_t __xdata *)(((addr) & 0xFFF) | 0x4000) = (d); } while(0)
#define radio_write8nb(addr, d) do { *(volatile uint8_t __xdata *)(((addr) & 0xFFF) | 0x5000) = (d); } while(0)

#if 0
#if defined(__SDCC_MODEL_LARGE) /* If sdcc version < 3.8.0 AND Model is LARGE use extern function */

extern __reentrantb uint8_t radio_read8(uint16_t addr) __reentrant;
extern __reentrantb void radio_write8(uint16_t addr, uint8_t d) __reentrant;
extern __reentrantb void radio_write8nb(uint16_t addr, uint8_t d) __reentrant;

#endif /* __SDCC_MODEL_LARGE */
#endif /* 0 */

#else /* SDCC version >= 3.8.0 use in-line version */

inline uint8_t radio_read8(uint16_t addr)
{
	return *(volatile uint8_t __xdata *)((addr & 0xFFF) | 0x4000);
}

inline void radio_write8(uint16_t addr, uint8_t d)
{
	*(volatile uint8_t __xdata *)((addr & 0xFFF) | 0x4000) = d;
}

inline void radio_write8nb(uint16_t addr, uint8_t d)
{
	*(volatile uint8_t __xdata *)((addr & 0xFFF) | 0x5000) = d;
}

#endif /* SDCC < 380 */

#define radio_write16nb(a,d) radio_write16(a,d)
#define radio_write24nb(a,d) radio_write24(a,d)
#define radio_write32nb(a,d) radio_write32(a,d)

#elif defined(__ICC8051__)

inline __reentrantb uint8_t radio_read8(uint16_t addr) __reentrant
{
	return *(volatile uint8_t __xdata *)((addr & 0xFFF) | 0x4000);
}

inline __reentrantb void radio_write8(uint16_t addr, uint8_t d) __reentrant
{
	*(volatile uint8_t __xdata *)((addr & 0xFFF) | 0x4000) = d;
}

inline __reentrantb void radio_write8nb(uint16_t addr, uint8_t d) __reentrant
{
	*(volatile uint8_t __xdata *)((addr & 0xFFF) | 0x5000) = d;
}

#define radio_write16nb(a,d) radio_write16(a,d)
#define radio_write24nb(a,d) radio_write24(a,d)
#define radio_write32nb(a,d) radio_write32(a,d)

#else /* Other than ARM/SDCC/__ICC8051__*/

extern __reentrantb uint8_t radio_read8(uint16_t addr) __reentrant;
extern __reentrantb void radio_write8(uint16_t addr, uint8_t d) __reentrant;
#define radio_write8nb(a,d) radio_write8(a,d)
#define radio_write16nb(a,d) radio_write16(a,d)
#define radio_write24nb(a,d) radio_write24(a,d)
#define radio_write32nb(a,d) radio_write32(a,d)

#endif

extern __reentrantb uint16_t radio_read16(uint16_t addr) __reentrant;
extern __reentrantb uint32_t radio_read24(uint16_t addr) __reentrant;
extern __reentrantb uint32_t radio_read32(uint16_t addr) __reentrant;
extern __reentrantb void radio_write16(uint16_t addr, uint16_t d) __reentrant;
extern __reentrantb void radio_write24(uint16_t addr, uint32_t d) __reentrant;
extern __reentrantb void radio_write32(uint16_t addr, uint32_t d) __reentrant;

#endif

/*
 * AX5031
 */
extern __reentrantb void ax5031_comminit(void) __reentrant;
extern __reentrantb void ax5031_commsleepexit(void) __reentrant;
extern __reentrantb uint8_t ax5031_reset(void) __reentrant;
extern __reentrantb void ax5031_rclk_enable(uint8_t div) __reentrant;
extern __reentrantb void ax5031_rclk_disable(void) __reentrant;
extern __reentrantb void ax5031_readfifo(uint8_t __genericaddr *ptr, uint8_t len) __reentrant;
extern __reentrantb void ax5031_writefifo(const uint8_t __genericaddr *ptr, uint8_t len) __reentrant;

/*
 * AX5042
 */
extern __reentrantb void ax5042_comminit(void) __reentrant;
extern __reentrantb void ax5042_commsleepexit(void) __reentrant;
extern __reentrantb uint8_t ax5042_reset(void) __reentrant;
extern __reentrantb void ax5042_rclk_enable(uint8_t div) __reentrant;
extern __reentrantb void ax5042_rclk_disable(void) __reentrant;
extern __reentrantb void ax5042_readfifo(uint8_t __genericaddr *ptr, uint8_t len) __reentrant;
extern __reentrantb void ax5042_writefifo(const uint8_t __genericaddr *ptr, uint8_t len) __reentrant;

/*
 * AX5043
 */
extern __reentrantb void ax5043_comminit(void) __reentrant;
extern __reentrantb void ax5043_commsleepexit(void) __reentrant;
extern __reentrantb uint8_t ax5043_reset(void) __reentrant;
extern __reentrantb void ax5043_enter_deepsleep(void) __reentrant;
extern __reentrantb uint8_t ax5043_wakeup_deepsleep(void) __reentrant;
extern __reentrantb void ax5043_rclk_enable(uint8_t div) __reentrant;
extern __reentrantb void ax5043_rclk_disable(void) __reentrant;
extern __reentrantb void ax5043_rclk_wait_stable(uint8_t wtflag) __reentrant;
extern __reentrantb void ax5043_readfifo(uint8_t __genericaddr *ptr, uint8_t len) __reentrant;
extern __reentrantb void ax5043_writefifo(const uint8_t __genericaddr *ptr, uint8_t len) __reentrant;
extern __reentrantb void ax5043_set_pwramp_pin(uint8_t config_pin) __reentrant;
extern __reentrantb uint8_t ax5043_get_pwramp_pin() __reentrant;
extern __reentrantb void ax5043_set_antsel_pin(uint8_t config_pin) __reentrant;
extern __reentrantb uint8_t ax5043_get_antsel_pin() __reentrant;
/*
 * AX5044_45 // or 5045
 */
extern __reentrantb void ax5044_45_comminit(void) __reentrant;
extern __reentrantb void ax5044_45_commsleepexit(void) __reentrant;
extern __reentrantb uint8_t ax5044_45_reset(void) __reentrant;
extern __reentrantb void ax5044_45_enter_deepsleep(void) __reentrant;
extern __reentrantb uint8_t ax5044_45_wakeup_deepsleep(void) __reentrant;
extern __reentrantb void ax5044_45_rclk_enable(uint8_t div) __reentrant;
extern __reentrantb void ax5044_45_rclk_disable(void) __reentrant;
extern __reentrantb void ax5044_45_rclk_wait_stable(uint8_t wtflag) __reentrant;
extern __reentrantb void ax5044_45_readfifo(uint8_t __genericaddr *ptr, uint8_t len) __reentrant;
extern __reentrantb void ax5044_45_writefifo(const uint8_t __genericaddr *ptr, uint8_t len) __reentrant;
extern __reentrantb void ax5044_45_set_pwramp_pin(uint8_t config_pin) __reentrant;
extern __reentrantb uint8_t ax5044_45_get_pwramp_pin() __reentrant;
extern __reentrantb void ax5044_45_set_antsel_pin(uint8_t config_pin) __reentrant;
extern __reentrantb uint8_t ax5044_45_get_antsel_pin() __reentrant;
/*
 * AX5051
 */
extern __reentrantb void ax5051_comminit(void) __reentrant;
extern __reentrantb void ax5051_commsleepexit(void) __reentrant;
extern __reentrantb uint8_t ax5051_reset(void) __reentrant;
extern __reentrantb void ax5051_rclk_enable(uint8_t div) __reentrant;
extern __reentrantb void ax5051_rclk_disable(void) __reentrant;
extern __reentrantb void ax5051_readfifo(uint8_t __genericaddr *ptr, uint8_t len) __reentrant;
extern __reentrantb void ax5051_writefifo(const uint8_t __genericaddr *ptr, uint8_t len) __reentrant;

#endif /* LIBMFRADIO_H */
