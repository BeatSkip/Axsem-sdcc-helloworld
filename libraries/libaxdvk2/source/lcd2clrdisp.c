#include "libaxlcd2.h"

__reentrantb void lcd2_cleardisplay(void) __reentrant
{
	lcd2_txcmdlong(0x01);
}
