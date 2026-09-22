#include "libaxlcd2.h"

__reentrantb void lcd2_clear(uint8_t pos, uint8_t len) __reentrant
{
	uint8_t x, l = len;
	lcd2_setpos(pos);
	if (!l)
		return;
	x = pos & 0x3f;
	if (x >= 0x10)
		return;
	x = 0x10 - x;
	if (l > x)
		l = x;
	do {
		lcd2_tx(' ');
	} while (--l);
}
