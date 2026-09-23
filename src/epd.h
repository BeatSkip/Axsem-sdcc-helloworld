/**
 * @file epd.h
 * @brief Minimal driver for the SES-Imagotag e-paper display
 *
 * Display: Good Display GDEW026Z39 (2.6", native 296x152, black/white/red)
 * with the IL0373 controller, driven **rotated** as 152 wide x 296 tall -
 * exactly how the stock imagotag firmware drives the tag.
 * (GDEW0213Z16 2.13" panels: change EPD_W/EPD_H and the epd_init() TRES
 * bytes accordingly.)
 *
 * Wiring (this board, see documentation/signal-list.md):
 *   PA0 = CS       (active low)
 *   PA1 = D/C      (0 = command, 1 = data)
 *   PB2 = BUSY     (input; LOW = busy on these tags - see epd.c)
 *   PB5 = RST      (active low; NOTE: shared with the UART RX function -
 *                   UART0 must be off while the panel is driven)
 *   SPI: PC1 = SCK, PC2 = MOSI (see spi.h)
 *
 * Framebuffer format (BWR, one bit per pixel per plane):
 *   black/white plane: 0 = black ink, 1 = white
 *   red plane:         0 = red ink,   1 = white
 *   one byte holds 8 horizontal pixels, MSB = leftmost pixel:
 *   byte index = (y * EPD_W + x) / 8, bit = 0x80 >> (x & 7)
 *
 * Sizes: 5624 bytes per plane. Both planes together (11.2 KB) exceed the
 * 8 KB XRAM, so stream the frame in two steps with epd_upload() (see
 * epd_display()); a static image can live in CODE (const) memory instead.
 */

#ifndef EPD_DRIVER_H
#define EPD_DRIVER_H

#include <ax8052f143.h>
#include <libmftypes.h>

/* ── Panel selection ──────────────────────────────────────────────────── */
#define EPD_W   152     /* portrait: 152 wide ...            */
#define EPD_H   296     /* ... x 296 tall (rotated 296x152)  */

/* Bytes per monochrome plane: round up (W*H/8). 32-bit math: W*H does
 * not fit SDCC's 16-bit int. */
#define EPD_PLANE_BYTES  ((uint16_t)(((uint32_t)EPD_W * EPD_H + 7u) / 8u))

/* ── API ──────────────────────────────────────────────────────────────── */
/* Reset the panel, run the full IL0373 init sequence (OTP LUT), clear to
 * white. Requires spi_init() to have been called first. */
void epd_init(void);

/* Put the panel into deep sleep (minimal power). */
void epd_sleep(void);

/* Fill the whole screen with constant plane values and refresh.
 * 0x00 = ink, 0xFF = white, so epd_clear(0xFF, 0xFF) = all white.
 * No framebuffer needed. */
void epd_clear(uint8_t bw_byte, uint8_t red_byte);

/* Send one data command (IL0373 0x10 = black/white plane, 0x13 = red
 * plane) followed by len image bytes. CS is handled internally. Use this
 * to stream a frame in two halves while reusing one buffer:
 *
 *   fill buf with black/white data;  epd_upload(0x10, buf, EPD_PLANE_BYTES);
 *   refill buf with red data;       epd_upload(0x13, buf, EPD_PLANE_BYTES);
 *   epd_refresh();
 */
void epd_upload(uint8_t cmd, const uint8_t *plane, uint16_t len);

/* Start a screen refresh (IL0373 0x12) and wait for BUSY to clear. */
void epd_refresh(void);

/* Convenience: upload both planes and refresh. Both buffers must exist
 * at the same time - on this panel use epd_upload() twice instead. */
void epd_display(const uint8_t *bw_plane, const uint8_t *red_plane);

/* ── Pixel helpers (operate on a plane buffer) ────────────────────────── */
/* Mark a pixel with ink (black in the BW plane, red in the red plane). */
static inline void epd_plane_ink(uint8_t *plane, uint16_t x, uint16_t y)
{
    plane[((uint16_t)y * EPD_W + x) >> 3] &= (uint8_t)~(0x80 >> (x & 7));
}

/* Clear a pixel to white. */
static inline void epd_plane_white(uint8_t *plane, uint16_t x, uint16_t y)
{
    plane[((uint16_t)y * EPD_W + x) >> 3] |= (uint8_t)(0x80 >> (x & 7));
}

/* Returns 1 if the pixel is ink, 0 if white. */
static inline uint8_t epd_plane_get(const uint8_t *plane, uint16_t x, uint16_t y)
{
    return (plane[((uint16_t)y * EPD_W + x) >> 3] & (uint8_t)(0x80 >> (x & 7))) ? 0 : 1;
}

#endif /* EPD_DRIVER_H */
