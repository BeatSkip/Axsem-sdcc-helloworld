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
#include "libaxlcd.h"

#if defined __ARMEL__ || defined __ARMEB__

void lcd_waitlong(void)
{
	unsigned int x = 0x4000;
	while (--x)
		nop();
}

void lcd_waitshort(void)
{
	unsigned int x = 0x100;
	while (--x)
		nop();
}

#ifdef __AXM0

void lcd_write(uint8_t v)
{
	SPI1->DATA = v;
	for (;;) {
		uint8_t __autodata st = SPI1->STS;
		if (st & 0x01)
			break;
	}
	v = SPI1->DATA;
}

void lcd_portoff(void)
{
	CMU_AND->PCLK_CFG = ~CMU_PCLK_CFG_SPI1_EN_Msk | CMU_PCLK_CFG_XBAR_EN_Msk;
	XBAR->IN_SPI1_CFG_b.IN = XBAR_IN_SPI1_CFG_IN_SEL_1;
	XBAR->PC_CFG_b.PC0 = 0;
	XBAR->PC_CFG_b.PC1 = 0;
	XBAR->PC_CFG_b.PC2 = 0;
	CMU_AND->PCLK_CFG = ~CMU_PCLK_CFG_XBAR_EN_Msk;
	SPI1->CFG = 0x00000000;
}

void lcd_portinit(void)
{
	/*
	 * PB0: RS
	 * PB1: RST
	 * PC0: SEL
	 * PC1: SCK
	 * PC2: MOSI
	 */
	uint8_t __autodata x;
	GPIO_OR->OUT_EN = 0x00070300;
	GPIO_AND->DATA_OUT = ~0x00040100;
	GPIO_OR->DATA_OUT = 0x00030200;
	CMU_OR->PCLK_CFG = CMU_PCLK_CFG_SPI1_EN_Msk | CMU_PCLK_CFG_XBAR_EN_Msk;
	XBAR->IN_SPI1_CFG_b.IN = XBAR_IN_SPI1_CFG_IN_SEL_PB2;
	XBAR->PC_CFG_b.PC0 = 1;
	XBAR->PC_CFG_b.PC1 = 1;
	XBAR->PC_CFG_b.PC2 = 1;
	CMU_AND->PCLK_CFG = ~CMU_PCLK_CFG_XBAR_EN_Msk;
	SPI1->CFG = 0x0000D802;
	x = SPI1->DATA;
}

#endif

#ifdef __AXM0F2

void lcd_write(uint8_t v)
{
	SCB0->TX_FIFO_WR = v;
	for (;;) {
		uint32_t __autodata st = SCB0->INTR_RX;
		if (st & 0x00000004)
			break;
	}
	SCB0->INTR_RX = 0x00000004;
	v = SCB0->RX_FIFO_RD;
}

void lcd_portoff(void)
{
	SCB0->CTRL = 0x0000000;
	GPIO_PRT0->PC &= ~0x00000007;
	GPIO_PRT1->PC &= ~0x000001C7;
	GPIO_PRT4->PC &= ~0x00000FC0;
	HSIOM->PORT_SEL0 &= ~0x0000000F;
	HSIOM->PORT_SEL1 &= ~0x00000F0F;
}

void lcd_portinit(void)
{
	/*
	 * P0[0] SEL   scb[0].select1
	 * P1[0] MOSI  scb[0].mosi
	 * P1[2] SCK   scb[0].sck
	 * P4[2] RS
	 * P4[3] RST
	 */
	GPIO_PRT0->PC = (GPIO_PRT0->PC & ~0x00000007) | 0x00000006;
	GPIO_PRT1->PC = (GPIO_PRT1->PC & ~0x000001C7) | 0x00000186;
	GPIO_PRT4->PC = (GPIO_PRT4->PC & ~0x00000FC0) | 0x00000D80;
	GPIO_PRT4->DR_CLR = 0x00000004;
	GPIO_PRT4->DR_SET = 0x00000008;
	GPIO_PRT0->DR_SET = 0x00000001;
	GPIO_PRT1->DR_SET = 0x00000004;
	GPIO_PRT1->DR_CLR = 0x00000001;
	HSIOM->PORT_SEL0 |= 0x0000000F;
	HSIOM->PORT_SEL1 |= 0x00000F0F;
	HSIOM->PORT_SEL4 &= ~0x0000FF00;

	PERI->PCLK_CTL0     = 0x00000045;

	/* Configure LCD - SPI interface */
	SCB0->CTRL = (16 - 1) /* oversampling - 3 MHz clock speed */ | 0x01000800;
	SCB0->SPI_CTRL = 0x8400000D;

	/* Configure RX direction */
	SCB0->RX_CTRL = 0x80000107;
	SCB0->RX_FIFO_CTRL = 0x00010007;
	SCB0->RX_FIFO_CTRL = 0x00000007;

	/* Configure TX direction */
	SCB0->TX_CTRL = 0x80000107;
	SCB0->TX_FIFO_CTRL = 0x00010000;
	SCB0->TX_FIFO_CTRL = 0x00000000;

	/* Configure interrupt sources */
	SCB0->INTR_I2C_EC_MASK = 0;
	SCB0->INTR_SPI_EC_MASK = 0;
	SCB0->INTR_S_MASK = 0;
	SCB0->INTR_M_MASK = 0;
	SCB0->INTR_RX_MASK = 0;
	SCB0->INTR_TX_MASK = 0;

	/* Enable */
	SCB0->CTRL |= 0x80000000;
}

#endif

#else

void lcd_waitlong(void)
{
	uint8_t __autodata a = 0x40;
	do {
		uint8_t __autodata b = 0;
		do {
			--b;
		} while (b);
		--a;
	} while (a);
}

void lcd_waitshort(void)
{
	uint8_t __autodata a = 0;
	do {
		--a;
	} while (a);
}

void lcd_write(uint8_t v)
{
	PORTC_0 = 0;
        SPSHREG = v;
	for (;;) {
		uint8_t __autodata st = SPSTATUS;
		if (st & 0x01)
			break;
	}
	v = SPSHREG;
        PORTC_0 = 1;
}

void lcd_portoff(void)
{
        SPCLKSRC = 0x07;
	SPMODE = 0x00;
}

void lcd_portinit(void)
{
	uint8_t __autodata x;
	DIRB |= 0x03;
	PORTB &= (uint8_t)~0x01;
	PORTB_1 = 1;
	DIRC |= 0x07;
	PORTC |= 0x03;
	PORTC &= (uint8_t)~0x04;
        SPCLKSRC = 0xD8;
	SPMODE = 0x01;
        x = SPSHREG;
}

#endif

void lcd_writecmd(uint8_t cmd)
{
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
	GPIO_AND->DATA_OUT = ~0x00000100;
#endif
#ifdef __AXM0F2
	GPIO_PRT4->DR_CLR = 0x00000004;
#endif
#else
	PORTB_0 = 0;
#endif
	lcd_write(cmd);
}

void lcd_writedata(uint8_t d)
{
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
	GPIO_OR->DATA_OUT = 0x00000100;
#endif
#ifdef __AXM0F2
	GPIO_PRT4->DR_SET = 0x00000004;
#endif
#else
	PORTB_0 = 1;
#endif
	lcd_write(d);
}

void lcd_init(void)
{
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
	uint8_t __autodata x;
	GPIO_OR->OUT_EN = 0x00070300;
	GPIO_AND->DATA_OUT = ~0x00040300;
	GPIO_OR->DATA_OUT = 0x00030200;
	CMU_OR->PCLK_CFG = CMU_PCLK_CFG_SPI1_EN_Msk | CMU_PCLK_CFG_XBAR_EN_Msk;
	XBAR->IN_SPI1_CFG_b.IN = XBAR_IN_SPI1_CFG_IN_SEL_PC1;
	XBAR->PC_CFG_b.PC0 = 1;
	XBAR->PC_CFG_b.PC1 = 1;
	XBAR->PC_CFG_b.PC2 = 1;
	CMU_AND->PCLK_CFG = ~CMU_PCLK_CFG_XBAR_EN_Msk;
	SPI1->CFG = 0x0000D802;
	x = SPI1->DATA;
	GPIO_AND->DATA_OUT = ~0x00000200;
#endif
#ifdef __AXM0F2
	GPIO_PRT0->PC = (GPIO_PRT0->PC & ~0x00000007) | 0x00000006;
	GPIO_PRT1->PC = (GPIO_PRT1->PC & ~0x000001C7) | 0x00000186;
	GPIO_PRT4->PC = (GPIO_PRT4->PC & ~0x00000FC0) | 0x00000D80;
	GPIO_PRT4->DR_CLR = 0x00000004;
	GPIO_PRT4->DR_SET = 0x00000008;
	GPIO_PRT0->DR_SET = 0x00000001;
	GPIO_PRT1->DR_SET = 0x00000004;
	GPIO_PRT1->DR_CLR = 0x00000001;
	HSIOM->PORT_SEL0 |= 0x0000000F;
	HSIOM->PORT_SEL1 |= 0x00000F0F;
	HSIOM->PORT_SEL4 &= ~0x0000FF00;

	PERI->PCLK_CTL0     = 0x00000045;

	/* Configure LCD - SPI interface */
	SCB0->CTRL = (16 - 1) /* oversampling - 3 MHz clock speed */ | 0x01000800;
	SCB0->SPI_CTRL = 0x8400000D;

	/* Configure RX direction */
	SCB0->RX_CTRL = 0x80000107;
	SCB0->RX_FIFO_CTRL = 0x00010007;
	SCB0->RX_FIFO_CTRL = 0x00000007;

	/* Configure TX direction */
	SCB0->TX_CTRL = 0x80000107;
	SCB0->TX_FIFO_CTRL = 0x00010000;
	SCB0->TX_FIFO_CTRL = 0x00000000;

	/* Configure interrupt sources */
	SCB0->INTR_I2C_EC_MASK = 0;
	SCB0->INTR_SPI_EC_MASK = 0;
	SCB0->INTR_S_MASK = 0;
	SCB0->INTR_M_MASK = 0;
	SCB0->INTR_RX_MASK = 0;
	SCB0->INTR_TX_MASK = 0;

	/* Enable */
	SCB0->CTRL |= 0x80000000;
	GPIO_PRT4->DR_CLR = 0x00000008;
#endif
#else
	uint8_t __autodata x;
	DIRB |= 0x03;
	PORTB &= (uint8_t)~0x03;
	DIRC |= 0x07;
	PORTC |= 0x03;
	PORTC &= (uint8_t)~0x04;
        SPCLKSRC = 0xD8;
	SPMODE = 0x01;
        x = SPSHREG;
	PORTB_1 = 0;
#endif
	lcd_waitlong();
#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
	GPIO_OR->DATA_OUT = 0x00000200;
#endif
#ifdef __AXM0F2
	GPIO_PRT4->DR_SET = 0x00000008;
#endif
#else
	PORTB_1 = 1;
#endif
	// Init Display
	lcd_waitlong();
	// wake-up
	lcd_writecmd(0x30);
	lcd_waitlong();
	// wake-up
	lcd_writecmd(0x30);
	lcd_waitshort();
	// wake-up
	lcd_writecmd(0x30);
	lcd_waitshort();
	// function set
	lcd_writecmd(0x39);
	lcd_waitshort();
	// internal osc frequency
	lcd_writecmd(0x14);
	lcd_waitshort();
	// power control
	lcd_writecmd(0x56);
	lcd_waitshort();
	// follower control
	lcd_writecmd(0x6d);
	lcd_waitshort();
	// contrast
	lcd_writecmd(0x78);
	lcd_waitshort();
	// display on
	lcd_writecmd(0x0c);
	lcd_waitshort();
	// entry mode
	lcd_writecmd(0x06);
	lcd_waitshort();
	// clear display
	lcd_writecmd(0x01);
	lcd_waitlong();
	// display on; cursor on
	//lcd_writecmd(0x0f);
	//lcd_waitshort();
}
