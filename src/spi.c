/**
 * @file spi.c
 * @brief Minimal hardware SPI master driver for the AX8052 (AX8052F143)
 *
 * Transfer protocol follows the vendor LibMF SDK's proven LCD driver code
 * (libraries/libmf/source/lcdinit.c):
 *
 *      SPSHREG = byte;                  // start transfer
 *      while (!(SPSTATUS & 0x01)) ;     // wait for completion (RX valid)
 *      byte = SPSHREG;                  // read result, clears the flag
 */

#include "spi.h"
#include "board.h"

void spi_init(void)
{
    /* SPI pins: PC1 = SCK, PC2 = MOSI out; PC3 = MISO in (default) */
    DIRC |= 0x06;
    DIRC &= (uint8_t)~0x08;

    /* All chip selects idle high, as outputs */
    DIRA |= 0x02;                   /* EPD CS on PA1 */
    DIRB |= 0x02;                   /* NFC CS on PB1 */
    DIRC |= 0x01;                   /* FLASH CS on PC0 */
    CS_EPD   = 1;
    CS_NFC   = 1;
    CS_FLASH = 1;

    /* Enable SPI master, mode 0, MSB first */
    SPCLKSRC = SPI_CLKSRC_BYTE;
    SPMODE   = 0x01;
    (void)SPSHREG;                  /* clear any pending flag */
}

void spi_select(spi_dev_t dev)
{
    switch (dev) {
    case SPI_DEV_FLASH: CS_FLASH = 0; break;
    case SPI_DEV_NFC:   CS_NFC   = 0; break;
    case SPI_DEV_EPD:   CS_EPD   = 0; break;
    }
}

void spi_deselect(spi_dev_t dev)
{
    switch (dev) {
    case SPI_DEV_FLASH: CS_FLASH = 1; break;
    case SPI_DEV_NFC:   CS_NFC   = 1; break;
    case SPI_DEV_EPD:   CS_EPD   = 1; break;
    }
}

uint8_t spi_transfer(uint8_t byte)
{
    SPSHREG = byte;
    while (!(SPSTATUS & 0x01))
        ;
    return SPSHREG;
}

void spi_write(const uint8_t *buf, uint16_t len)
{
    while (len--) {
        SPSHREG = *buf++;
        while (!(SPSTATUS & 0x01))
            ;
        (void)SPSHREG;              /* discard received byte, clear flag */
    }
}

void spi_read(uint8_t *buf, uint16_t len)
{
    while (len--) {
        SPSHREG = 0x00;
        while (!(SPSTATUS & 0x01))
            ;
        *buf++ = SPSHREG;
    }
}
