/**
 * @file main.c
 * @brief E-paper display SPI bring-up test (GDE 2.6" panel)
 *
 * Pure LED-based test, no UART involved (UART0 shares its RX pin with
 * the panel's reset line, so it stays completely off).
 *
 * The panel's only reliable feedback is the BUSY pin, and the tag's
 * BUSY polarity varies between revisions - so the test watches for
 * LEVEL CHANGES (edges) instead of absolute levels, which works with
 * either polarity.
 *
 *   green (PB6) = refresh started and finished  -> SPI link works
 *   red   (PC4) = refresh started but BUSY never returned -> stuck panel
 *   blue  (PB7) = no BUSY reaction at all -> no panel / no SPI link
 *
 * On blue, the red LED (PC4) first flashes the failing phase:
 *   1 flash = no reaction to power-on (0x04) - noted, test continues
 *   2 flashes = no reaction to the refresh command (0x12) - fatal
 */

#include <ax8052f143.h>
#include <libmf.h>
#include <libmftypes.h>
#include "hal.h"
#include "board.h"
#include "pwr.h"
#include "spi.h"
#include "epd.h"        /* EPD_W/EPD_H/EPD_PLANE_BYTES */

/* ── small helpers ────────────────────────────────────────────────────── */

static void ms_delay(uint16_t ms)
{
    while (ms--)
        delay(1000);
}

/* Poll BUSY until it equals target (1 = busy) or timeout_ms elapses.
 * Returns 1 when the target level was reached, 0 on timeout. */
static uint8_t wait_busy_level(uint8_t target, uint16_t timeout_ms)
{
    uint16_t t = timeout_ms;
    while (EPD_BUSY != target) {
        if (!--t)
            return 0;
        delay(1000);
    }
    return 1;
}

/* Poll BUSY until it leaves the given level (an edge either way).
 * Returns 1 when the level changed, 0 on timeout. */
static uint8_t wait_busy_edge(uint8_t level, uint16_t timeout_ms)
{
    uint16_t t = timeout_ms;
    while (EPD_BUSY == level) {
        if (!--t)
            return 0;
        delay(1000);
    }
    return 1;
}

static void epd_write_cmd(uint8_t cmd)
{
    EPD_DC = 0;
    spi_select(SPI_DEV_EPD);
    spi_transfer(cmd);
    spi_deselect(SPI_DEV_EPD);
    EPD_DC = 1;
}

static void epd_write_data(uint8_t data)
{
    spi_select(SPI_DEV_EPD);
    spi_transfer(data);
    spi_deselect(SPI_DEV_EPD);
}

/* Upload one full plane of a constant value (white = 0xFF). */
static void epd_fill_plane(uint8_t cmd, uint8_t value)
{
    uint16_t i;
    epd_write_cmd(cmd);
    spi_select(SPI_DEV_EPD);
    for (i = 0; i < EPD_PLANE_BYTES; i++)
        spi_transfer(value);
    spi_deselect(SPI_DEV_EPD);
}

/* ── result signalling ────────────────────────────────────────────────── */

/* The red LED on this tag lights at logic HIGH (observed: it stays lit
 * while the result LEDs blink their LOW-based patterns). */
#define LEDR_ACTIVE_HIGH 1

static void led_red(uint8_t on)
{
#if LEDR_ACTIVE_HIGH
    if (on)
        PIN_SET_HIGH(LEDR_PORT, LEDR_PIN);
    else
        PIN_SET_LOW(LEDR_PORT, LEDR_PIN);
#else
    if (on)
        PIN_SET_LOW(LEDR_PORT, LEDR_PIN);
    else
        PIN_SET_HIGH(LEDR_PORT, LEDR_PIN);
#endif
}

/* Continuous 500 ms on / 500 ms off in the result colour. A macro
 * because the port argument must be the SFR itself, not its value. */
#define BLINK_FOREVER(port, pin) do {                                   \
        for (;;) {                                                      \
            PIN_SET_LOW(port, pin);                                     \
            ms_delay(500);                                              \
            PIN_SET_HIGH(port, pin);                                    \
            ms_delay(500);                                              \
        }                                                               \
    } while (0)

/* n short flashes on the red LED, then the steady result colour.
 * The red indicator ends in its OFF state before the result blink. */
#define FAIL(phase, port, pin) do {                                     \
        uint8_t __k = (phase);                                          \
        while (__k--) {                                                 \
            led_red(1);                                                 \
            ms_delay(200);                                              \
            led_red(0);                                                 \
            ms_delay(200);                                              \
        }                                                               \
        ms_delay(1000);                                                 \
        BLINK_FOREVER(port, pin);                                       \
    } while (0)

void main()
{
    uint8_t level;

    periph_init();

    /* Power rails via the PA2/PA5 transistor lines (see pwr.h) - the
     * display supply may hang off one of these. */
    pwr_init();
    pwr_on();

    spi_init();

    /* EPD control pins: DC out (PA0), RST out (PB5), BUSY in (PB2).
     * CS (PA1) is set up by spi_init(). No UART is enabled, so PB5
     * belongs to the reset line alone. */
    DIRA |= 0x01;
    DIRB |= 0x20;
    DIRB &= (uint8_t)~0x04;
    EPD_DC = 1;
    EPD_RST = 1;

    /* Hardware reset: 100 ms low, 100 ms settle (the proven reference
     * drivers use 100-200 ms; a short pulse may not reach the panel
     * through the tag's reset circuit). */
    EPD_RST = 0;
    ms_delay(100);
    EPD_RST = 1;
    ms_delay(100);

    /* Booster soft start */
    epd_write_cmd(0x06);
    epd_write_data(0x17);
    epd_write_data(0x17);
    epd_write_data(0x17);

    /* Power on: the panel may pulse BUSY while boosting. If it does
     * not, note it with a single red flash - but keep going: some
     * panels only react to the refresh command, and the DRF check
     * below is the definitive SPI test. */
    level = EPD_BUSY;
    epd_write_cmd(0x04);
    if (!wait_busy_edge(level, 1500)) {
        led_red(1);
        ms_delay(200);
        led_red(0);
        ms_delay(800);
    }

    /* Let the booster pulse settle */
    wait_busy_level(level, 2500);

    /* Panel setting: LUT from OTP, BWR */
    epd_write_cmd(0x00);
    epd_write_data(0x0F);

    /* Resolution from epd.h (152x296 for the GDEW026Z39). 3-byte form. */
    epd_write_cmd(0x61);
    epd_write_data((uint8_t)EPD_W);
    epd_write_data((uint8_t)((uint16_t)EPD_H >> 8));
    epd_write_data((uint8_t)EPD_H);

    /* VCOM and data interval */
    epd_write_cmd(0x50);
    epd_write_data(0x77);

    /* White frame into both planes */
    epd_fill_plane(0x10, 0xFF);
    epd_fill_plane(0x13, 0xFF);

    /* Trigger the refresh; the panel only reacts if the command
     * arrived intact. */
    level = EPD_BUSY;
    epd_write_cmd(0x12);
    if (!wait_busy_edge(level, 3000))
        FAIL(2, LEDB_PORT, LEDB_PIN);       /* blue, 2 flashes: no DRF reaction */

    /* The refresh takes ~2-15 s; wait for BUSY to return. */
    if (!wait_busy_level(level, 25000))
        BLINK_FOREVER(LEDR_PORT, LEDR_PIN); /* red: update never finished */

    epd_write_cmd(0x02);                    /* POF */

    BLINK_FOREVER(LEDG_PORT, LEDG_PIN);     /* green: SPI link works */
}
