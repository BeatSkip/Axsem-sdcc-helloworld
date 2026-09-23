/**
 * @file spi.h
 * @brief Minimal hardware SPI master driver for the AX8052 (AX8052F143)
 *
 * Uses the AX8052's built-in SPI master/slave controller in master mode,
 * SPI mode 0 (CPOL=0, CPHA=0), MSB first - the same configuration the
 * vendor LibMF SDK uses to drive SPI displays (see libraries/libmf/source/
 * lcdinit.c), and exactly what the IL0373 e-paper controller expects.
 *
 * Pin assignments (see board.h and documentation/signal-list.md):
 *   PC1 = SCK, PC2 = MOSI, PC3 = MISO
 *   chip selects: PA1 = EPD, PB1 = NFC, PC0 = FLASH (all active low)
 *
 * Register semantics (verified against vendor SDK usage):
 *   SPCLKSRC  bits[2:0] = clock source (same values as the CLKSRC_* enum
 *             in libmftypes.h: 6 = SYSCLK, 7 = OFF); upper bits = prescaler.
 *             Proven settings: 0x07 = SPI off, 0x06 = SYSCLK/1 (board.h),
 *             0xD8 = vendor display clock (LibMF lcdinit.c).
 *   SPMODE    0x01 = master, mode 0, MSB first. Bit 3 = hardware busy flag.
 *   SPSHREG   write = start one 8-bit transfer, read = last received byte
 *   SPSTATUS  bit 0 = transfer complete (RX data valid), cleared by reading
 *             SPSHREG. bit 2 = TX done.
 */

#ifndef SPI_H
#define SPI_H

#include <ax8052f143.h>
#include <libmftypes.h>

/* SPI clock source byte (see header comment). Change the #define to tune. */
#define SPI_CLKSRC_BYTE  0xD8    /* vendor display clock (LibMF lcdinit.c) - slow and display-safe */
// #define SPI_CLKSRC_BYTE 0x06  /* SYSCLK, prescaler 1 (too fast for the e-paper panel) */

/* Devices on the shared SPI bus */
typedef enum {
    SPI_DEV_FLASH = 0,  /* CS on PC0 */
    SPI_DEV_NFC,        /* CS on PB1 */
    SPI_DEV_EPD         /* CS on PA1 */
} spi_dev_t;

/* Enable the SPI unit as master (mode 0, MSB first) and configure the
 * SCK/MOSI/MISO pins and all chip selects. Idempotent; all CS idle high. */
void spi_init(void);

/* Pull a device's chip select low / high (active low CS). */
void spi_select(spi_dev_t dev);
void spi_deselect(spi_dev_t dev);

/* Full-duplex transfer of one byte; returns the byte shifted in. */
uint8_t spi_transfer(uint8_t byte);

/* Write len bytes (received data is discarded). */
void spi_write(const uint8_t *buf, uint16_t len);

/* Read len bytes, sending 0x00 on MOSI. */
void spi_read(uint8_t *buf, uint16_t len);

#endif /* SPI_H */
