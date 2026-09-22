#ifndef LIBMINIKITLEDS_H
#define LIBMINIKITLEDS_H

#include "libmftypes.h"

#if defined __ARMEL__ || defined __ARMEB__

#ifdef AXM0_H

#define led0_toggle() do { GPIO_XOR->DATA_OUT = 0x00000200; } while (0)
#define led0_set(x)   do { GPIO_XOR->DATA_OUT = (GPIO_XOR->DATA_OUT ^ -!!(x)) & 0x00000200; } while (0)
#define led0_on()     do { GPIO_OR->DATA_OUT = 0x00000200; } while (0)
#define led0_off()    do { GPIO_AND->DATA_OUT = ~0x00000200; } while (0)

#define led1_toggle() do { } while (0)
#define led1_set(x)   do { } while (0)
#define led1_on()     do { } while (0)
#define led1_off()    do { } while (0)

#define led2_toggle() do { } while (0)
#define led2_set(x)   do { } while (0)
#define led2_on()     do { } while (0)
#define led2_off()    do { } while (0)

#define led3_toggle() do { } while (0)
#define led3_set(x)   do { } while (0)
#define led3_on()     do { } while (0)
#define led3_off()    do { } while (0)

#endif

#ifdef AXM0F2_H

#define led0_toggle() do { GPIO_PRT3->DR_INV = 0x00000080; } while (0)
#define led0_set(x)   do { GPIO_PRT3->DR_INV = (GPIO_PRT3->DR ^ -!!(x)) & 0x00000080; } while (0)
#define led0_on()     do { GPIO_PRT3->DR_SET = 0x00000080; } while (0)
#define led0_off()    do { GPIO_PRT3->DR_CLR = 0x00000080; } while (0)

#define led1_toggle() do { } while (0)
#define led1_set(x)   do { } while (0)
#define led1_on()     do { } while (0)
#define led1_off()    do { } while (0)

#define led2_toggle() do { } while (0)
#define led2_set(x)   do { } while (0)
#define led2_on()     do { } while (0)
#define led2_off()    do { } while (0)

#define led3_toggle() do { } while (0)
#define led3_set(x)   do { } while (0)
#define led3_on()     do { } while (0)
#define led3_off()    do { } while (0)

#endif

#else

#define led0_toggle() do { PORTB ^= 0x02; } while (0)
#define led0_set(x)   do { PORTB_1 = (x); } while (0)
#define led0_on()     do { led0_set(1); } while (0)
#define led0_off()    do { led0_set(0); } while (0)

#define led1_toggle() do { } while (0)
#define led1_set(x)   do { } while (0)
#define led1_on()     do { led1_set(1); } while (0)
#define led1_off()    do { led1_set(0); } while (0)

#define led2_toggle() do { } while (0)
#define led2_set(x)   do { } while (0)
#define led2_on()     do { led2_set(1); } while (0)
#define led2_off()    do { led2_set(0); } while (0)

#define led3_toggle() do { } while (0)
#define led3_set(x)   do { } while (0)
#define led3_on()     do { led3_set(1); } while (0)
#define led3_off()    do { led3_set(0); } while (0)

#endif

#endif /* LIBMINIKITLEDS_H */
