/**
 * @file main.c
 * @brief Flash dump over UART
 *
 * Boots, powers the transistor lines, brings up UART0 (38400 8N1 on
 * PB4=TX / PB5=RX) and the SPI unit, then streams the whole SPI flash
 * as a hexdump:
 *
 *   000000: FF FF 00 11 ...  |................|
 *
 * 38400 baud = the AXSEM serial bootloader's rate, so the same hookup
 * works for bootloader and dump (see tools/flashdump.py).
 * Capture it with any serial terminal; reset the tag to dump again.
 */

#include <ax8052f143.h>
#include <libmf.h>
#include <libmftypes.h>
#include <libmfuart.h>
#include <libmfuart0.h>
#include "hal.h"
#include "board.h"
#include "pwr.h"
#include "spi.h"
#include "flash.h"

/* ── UART output ────────────────────────────────────────────────────────
 * The prebuilt libmf.lib has broken UART FIFO size tables in this link
 * (the TX buffer-size table reads 0x75 instead of 0x40), which wedges
 * libmf's uart0_tx()/uart0_writestr() after a few bytes. So TX goes
 * straight to the UART registers instead - the same hardware sequence
 * the vendor's iocore performs, minus the buffer machinery:
 *
 *   while (!(U0STATUS & 0x04));   // wait for TX empty (U0TXEMPTY)
 *   U0SHREG = c;                  // start transmitting
 *   U0CTRL |= 0x08;               // arm the TX-done flag, like iocore
 */

static void uart_putc(uint8_t c)
{
    while (!(U0STATUS & 0x04))
        ;
    U0SHREG = c;
    U0CTRL |= 0x08;
}

static void uart_puts(const char *s)
{
    while (*s)
        uart_putc((uint8_t)*s++);
}

/* Wait until everything has left the shift register (U0TXEMPTY and
 * U0TXIDLE both set - the same test the bootloader's 'R' uses). */
static void uart_flush(void)
{
    while (0x44 & (uint8_t)~U0STATUS)
        ;
}

static void uart_puthex8(uint8_t v)
{
    static const char hex[] = "0123456789ABCDEF";
    uart_putc(hex[v >> 4]);
    uart_putc(hex[v & 0x0F]);
}

static void uart_puthex24(uint32_t v)
{
    uart_puthex8((uint8_t)(v >> 16));
    uart_puthex8((uint8_t)(v >> 8));
    uart_puthex8((uint8_t)v);
}

void main()
{
    uint32_t addr;
    uint8_t i;
    uint8_t buf[16];
    uint8_t id[3];

    periph_init();

    /* Power rails via the PA2/PA5 transistor lines (see pwr.h) - the
     * flash needs its supply before anything else happens. */
    pwr_init();
    pwr_on();

    /* Debug marker: two short LED blinks = reached main, before UART. */
    PIN_SET_LOW(LEDB_PORT, LEDB_PIN);
    delay(25000);
    PIN_SET_HIGH(LEDB_PORT, LEDB_PIN);
    delay(25000);
    PIN_SET_LOW(LEDB_PORT, LEDB_PIN);
    delay(25000);
    PIN_SET_HIGH(LEDB_PORT, LEDB_PIN);
    delay(25000);

    /* UART0 on PB4(TX) / PB5(RX) - the SAME pins the AXSEM serial
     * bootloader uses (PALTB = 0x10, PB4 output, PB5 input) and the
     * only UART pins wired to the serial converter on this tag. The
     * dump only transmits; PB5 stays configured as the bootloader
     * leaves it (U0RX input via the PINSEL reset default). */
    PALTB |= 0x10;                  /* PB4 -> U0TX alternate function */
    DIRB  |= 0x10;                  /* PB4 = output */
    DIRB  &= (uint8_t)~0x20;        /* PB5 = input (U0RX) */
    PORTB |= 0x30;                  /* TX idle high, RX latch high */

    /* Start the 20 MHz FRC oscillator and slave it to the 32 kHz LPX
     * crystal - byte-for-byte the sequence the AXSEM serial bootloader
     * runs on this tag. Without it the FRC runs free at ~10 MHz +/-10%
     * and the UART baud rate is wrong. */
    FRCOSCREF = 19531;
    FRCOSCKFILT = 2800;
    LPXOSCGM = 0x90;
    OSCFORCERUN |= 0x04;                        /* force the FRC to run */
    FRCOSCCONFIG = (6 << 3) | CLKSRC_LPXOSC;    /* FRC slaved to LPXOSC, x2 = ~20 MHz */
    WTCFGB = (1 << 3) | CLKSRC_LPXOSC;
    {
        uint8_t i = 128;
        OSCCALIB = 0x01;
        IE_5 = 1;                               /* clock-management IRQ wakes standby */
        do {
            while (!(OSCCALIB & 0x40))
                enter_standby();
            (void)FRCOSCFREQ1;                  /* feed the calibration filter */
        } while (--i);
        IE_5 = 0;
        OSCCALIB = 0x00;
    }

    uart_timer0_baud(CLKSRC_FRCOSC, 38400, 20000000);
    uart0_init(0, 8, 1);        /* enables the UART hardware; TX is driven
                                 * directly via uart_putc() (EA stays off) */

    uart_puts("\r\n*** imagotag flash dump ***\r\n");

    spi_init();
    extflash_release_powerdown();
    extflash_read_jedec_id(id);
    uart_puts("JEDEC ID: ");
    uart_puthex8(id[0]);
    uart_putc(' ');
    uart_puthex8(id[1]);
    uart_putc(' ');
    uart_puthex8(id[2]);
    uart_puts("\r\n");

    for (addr = 0; addr < FLASH_SIZE; addr += 16)
    {
        extflash_read(addr, buf, 16);
        uart_puthex24(addr);
        uart_puts(": ");
        for (i = 0; i < 16; i++)
        {
            uart_puthex8(buf[i]);
            uart_putc(' ');
        }
        uart_puts(" |");
        for (i = 0; i < 16; i++)
        {
            uint8_t c = buf[i];
            uart_putc((c >= 32 && c <= 126) ? c : '.');
        }
        uart_puts("|\r\n");
    }

    uart_puts("*** end of dump ***\r\n");
    uart_flush();

    while (1)
    {
        PIN_SET_LOW(LEDB_PORT, LEDB_PIN);
        delay(25000);
        PIN_SET_HIGH(LEDB_PORT, LEDB_PIN);
        delay(25000);
    }
}
