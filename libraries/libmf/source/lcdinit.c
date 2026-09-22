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

#include "cpu.h"
#include "libmflcd.h"

void lcd_waitlong(void)
{
	uint8_t __autodata a = 0x40;
	do {
		uint8_t __autodata b = 0;
		do {
			--b;
		} while (b);
		--a;
	} while (a);
}

void lcd_waitshort(void)
{
	uint8_t __autodata a = 0;
	do {
		--a;
	} while (a);
}

void lcd_write(uint8_t v)
{
	PORTC_0 = 0;
        SPSHREG = v;
	for (;;) {
		uint8_t __autodata st = SPSTATUS;
		if (st & 0x01)
			break;
	}
	v = SPSHREG;
        PORTC_0 = 1;
}

void lcd_writecmd(uint8_t cmd)
{
	PORTB_0 = 0;
	lcd_write(cmd);
}

void lcd_writedata(uint8_t d)
{
	PORTB_0 = 1;
	lcd_write(d);
}

void lcd_portoff(void)
{
        SPCLKSRC = 0x07;
	SPMODE = 0x00;
}

void lcd_portinit(void)
{
	uint8_t __autodata x;
	DIRB |= 0x03;
	PORTB &= (uint8_t)~0x01;
	PORTB_1 = 1;
	DIRC |= 0x07;
	PORTC |= 0x03;
	PORTC &= (uint8_t)~0x04;
        SPCLKSRC = 0xD8;
	SPMODE = 0x01;
        x = SPSHREG;
}

void lcd_init(void)
{
	uint8_t __autodata x;
	DIRB |= 0x03;
	PORTB &= (uint8_t)~0x03;
	DIRC |= 0x07;
	PORTC |= 0x03;
	PORTC &= (uint8_t)~0x04;
        SPCLKSRC = 0xD8;
	SPMODE = 0x01;
        x = SPSHREG;
	PORTB_1 = 0;
	lcd_waitlong();
	PORTB_1 = 1;
	// Init Display
	lcd_waitlong();
	// wake-up
	lcd_writecmd(0x30);
	lcd_waitlong();
	// wake-up
	lcd_writecmd(0x30);
	lcd_waitshort();
	// wake-up
	lcd_writecmd(0x30);
	lcd_waitshort();
	// function set
	lcd_writecmd(0x39);
	lcd_waitshort();
	// internal osc frequency
	lcd_writecmd(0x14);
	lcd_waitshort();
	// power control
	lcd_writecmd(0x56);
	lcd_waitshort();
	// follower control
	lcd_writecmd(0x6d);
	lcd_waitshort();
	// contrast
	lcd_writecmd(0x78);
	lcd_waitshort();
	// display on
	lcd_writecmd(0x0c);
	lcd_waitshort();
	// entry mode
	lcd_writecmd(0x06);
	lcd_waitshort();
	// clear display
	lcd_writecmd(0x01);
	lcd_waitlong();
	// display on; cursor on
	//lcd_writecmd(0x0f);
	//lcd_waitshort();
}
