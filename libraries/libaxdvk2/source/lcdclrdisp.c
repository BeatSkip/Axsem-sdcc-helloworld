#include "libaxlcd.h"

void lcd_cleardisplay(void)
{
	lcd_writecmd(0x01);
}
