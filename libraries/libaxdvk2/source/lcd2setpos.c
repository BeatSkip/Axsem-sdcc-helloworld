#include "libaxlcd2.h"

__reentrantb void lcd2_setpos(uint8_t v) __reentrant
{
	lcd2_txcmdshort(0x80 | v);
}
