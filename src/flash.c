/**
 * @file flash.c
 * @brief Minimal SPI NOR flash driver (25-series command set)
 */

#include "flash.h"
#include "spi.h"

#define CMD_READ        0x03    /* read data, 3-byte address */
#define CMD_JEDEC_ID    0x9F    /* read JEDEC ID */
#define CMD_RELEASE_PD  0xAB    /* release from deep power-down */

void extflash_release_powerdown(void)
{
    spi_select(SPI_DEV_FLASH);
    spi_transfer(CMD_RELEASE_PD);
    spi_deselect(SPI_DEV_FLASH);
}

void extflash_read_jedec_id(uint8_t id[3])
{
    spi_select(SPI_DEV_FLASH);
    spi_transfer(CMD_JEDEC_ID);
    id[0] = spi_transfer(0x00);
    id[1] = spi_transfer(0x00);
    id[2] = spi_transfer(0x00);
    spi_deselect(SPI_DEV_FLASH);
}

void extflash_read(uint32_t addr, uint8_t *buf, uint16_t len)
{
    spi_select(SPI_DEV_FLASH);
    spi_transfer(CMD_READ);
    spi_transfer((uint8_t)(addr >> 16));
    spi_transfer((uint8_t)(addr >> 8));
    spi_transfer((uint8_t)addr);
    spi_read(buf, len);             /* clocks len bytes out of the chip */
    spi_deselect(SPI_DEV_FLASH);
}
