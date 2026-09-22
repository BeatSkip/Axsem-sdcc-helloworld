#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include "axm0.h"
#endif
#ifdef __AXM0F2
#include "axm0f2.h"
#endif
#else
#include "ax8052.h"
#endif

#include "libaxlcd2.h"
#define uart_poll	   lcd2_poll
#define uart_txidle	   lcd2_txidle
#undef uart_txbusy
#define uart_txfree	   lcd2_txfree
#define uart_wait_txdone   lcd2_wait_txdone
#define uart_wait_txfree   lcd2_wait_txfree
#define uart_txpokehex	   lcd2_txpokehex
#define uart_txpoke	   lcd2_txpoke
#define uart_txadvance	   lcd2_txadvance
#define uart_tx            lcd2_tx
#define uart_writestr      lcd2_writestr
#define uart_writehexu16   lcd2_writehexu16
#define uart_writehexu32   lcd2_writehexu32
#define uart_writeu16      lcd2_writeu16
#define uart_writeu32      lcd2_writeu32

__reentrantb void uart_wait_txfree(uint8_t v) __reentrant
{
	for (;;) {
		criticalsection_t crit = enter_critical();
		if (uart_txfree() >= v) {
			exit_critical(crit);
			break;
		}
		if (!uart_poll())
			wtimer_standby();
		exit_critical(crit);
	}
}

#ifdef uart_txbusy

__reentrantb void uart_wait_txdone(void) __reentrant
{
	for (;;) {
		uint8_t b;
		criticalsection_t crit = enter_critical();
		b = uart_txbusy();
		if (!b) {
			exit_critical(crit);
			break;
		}
		if (!uart_poll() && b & 2)
			wtimer_standby();
		exit_critical(crit);
	}
}

#else

__reentrantb void uart_wait_txdone(void) __reentrant
{
	for (;;) {
		criticalsection_t crit = enter_critical();
		if (uart_txidle()) {
			exit_critical(crit);
			break;
		}
		if (!uart_poll())
			wtimer_standby();
		exit_critical(crit);
	}
}

#endif /* uart_txbusy */

__reentrantb void uart_tx(uint8_t v) __reentrant
{
	uart_wait_txfree(1);
	uart_txpoke(0, v);
	uart_txadvance(1);
}
