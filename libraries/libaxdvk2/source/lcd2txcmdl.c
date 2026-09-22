#include "libaxlcd2.h"

#define WAITSHORT     0x01
#define WAITLONG      0x18
#define STATUSCMDSHORT  (0x40 | WAITSHORT)
#define STATUSCMDLONG   (0x40 | WAITLONG)
#define STATUSCMDDATA   (0xC0 | WAITSHORT)

__reentrantb void lcd2_txcmdlong(uint8_t v) __reentrant
{
	lcd2_wait_txfree(1);
        lcd2_txpokecmd(0, v | (STATUSCMDLONG << 8));
        lcd2_txadvance(1);
}
