#ifndef LIBDVK2LEDS_H
#define LIBDVK2LEDS_H

#include "libmftypes.h"

#if defined __ARMEL__ || defined __ARMEB__

#ifdef AXM0_H

#define led0_toggle() do { GPIO_XOR->DATA_OUT = 0x00080000; } while (0)
#define led0_set(x)   do { GPIO_XOR->DATA_OUT = (GPIO_XOR->DATA_OUT ^ -!!(x)) & 0x00080000; } while (0)
#define led0_on()     do { GPIO_OR->DATA_OUT = 0x00080000; } while (0)
#define led0_off()    do { GPIO_AND->DATA_OUT = ~0x00080000; } while (0)

#define led1_toggle() do { GPIO_XOR->DATA_OUT = 0x00000001; } while (0)
#define led1_set(x)   do { GPIO_XOR->DATA_OUT = (GPIO_XOR->DATA_OUT ^ -!!(x)) & 0x00000001; } while (0)
#define led1_on()     do { GPIO_OR->DATA_OUT = 0x00000001; } while (0)
#define led1_off()    do { GPIO_AND->DATA_OUT = ~0x00000001; } while (0)

#define led2_toggle() do { GPIO_XOR->DATA_OUT = 0x00000004; } while (0)
#define led2_set(x)   do { GPIO_XOR->DATA_OUT = (GPIO_XOR->DATA_OUT ^ -!!(x)) & 0x00000004; } while (0)
#define led2_on()     do { GPIO_OR->DATA_OUT = 0x00000004; } while (0)
#define led2_off()    do { GPIO_AND->DATA_OUT = ~0x00000004; } while (0)

#define led3_toggle() do { GPIO_XOR->DATA_OUT = 0x00000020; } while (0)
#define led3_set(x)   do { GPIO_XOR->DATA_OUT = (GPIO_XOR->DATA_OUT ^ -!!(x)) & 0x00000020; } while (0)
#define led3_on()     do { GPIO_OR->DATA_OUT = 0x00000020; } while (0)
#define led3_off()    do { GPIO_AND->DATA_OUT = ~0x00000020; } while (0)

#endif

#ifdef AXM0F2_H

#define led0_toggle() do { GPIO_PRT4->DR_INV = 0x00000001; } while (0)
#define led0_set(x)   do { GPIO_PRT4->DR_INV = (GPIO_PRT4->DR ^ -!!(x)) & 0x00000001; } while (0)
#define led0_on()     do { GPIO_PRT4->DR_SET = 0x00000001; } while (0)
#define led0_off()    do { GPIO_PRT4->DR_CLR = 0x00000001; } while (0)

#define led1_toggle() do { GPIO_PRT1->DR_INV = 0x00000002; } while (0)
#define led1_set(x)   do { GPIO_PRT1->DR_INV = (GPIO_PRT1->DR ^ -!!(x)) & 0x00000002; } while (0)
#define led1_on()     do { GPIO_PRT1->DR_SET = 0x00000002; } while (0)
#define led1_off()    do { GPIO_PRT1->DR_CLR = 0x00000002; } while (0)

#define led2_toggle() do { GPIO_PRT1->DR_INV = 0x00000020; } while (0)
#define led2_set(x)   do { GPIO_PRT1->DR_INV = (GPIO_PRT1->DR ^ -!!(x)) & 0x00000020; } while (0)
#define led2_on()     do { GPIO_PRT1->DR_SET = 0x00000020; } while (0)
#define led2_off()    do { GPIO_PRT1->DR_CLR = 0x00000020; } while (0)

#define led3_toggle() do { GPIO_PRT1->DR_INV = 0x00000008; } while (0)
#define led3_set(x)   do { GPIO_PRT1->DR_INV = (GPIO_PRT1->DR ^ -!!(x)) & 0x00000008; } while (0)
#define led3_on()     do { GPIO_PRT1->DR_SET = 0x00000008; } while (0)
#define led3_off()    do { GPIO_PRT1->DR_CLR = 0x00000008; } while (0)

#endif

#else

#define led0_toggle() do { PORTC ^= 0x08; } while (0)
#define led0_set(x)   do { PORTC_3 = (x); } while (0)
#define led0_on()     do { led0_set(1); } while (0)
#define led0_off()    do { led0_set(0); } while (0)

#define led1_toggle() do { PORTA ^= 0x01; } while (0)
#define led1_set(x)   do { PORTA_0 = (x); } while (0)
#define led1_on()     do { led1_set(1); } while (0)
#define led1_off()    do { led1_set(0); } while (0)

#define led2_toggle() do { PORTA ^= 0x04; } while (0)
#define led2_set(x)   do { PORTA_2 = (x); } while (0)
#define led2_on()     do { led2_set(1); } while (0)
#define led2_off()    do { led2_set(0); } while (0)

#define led3_toggle() do { PORTA ^= 0x20; } while (0)
#define led3_set(x)   do { PORTA_5 = (x); } while (0)
#define led3_on()     do { led3_set(1); } while (0)
#define led3_off()    do { led3_set(0); } while (0)

#endif

#endif /* LIBDVK2LEDS_H */
