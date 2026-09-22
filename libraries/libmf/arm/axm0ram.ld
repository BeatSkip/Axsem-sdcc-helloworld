/* Linker script to configure memory regions. */
OUTPUT_FORMAT ("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 0x0000FFFC /* 64K - 4 bytes(DEBUG_LOCK) TODO */
  RAM2K (rwx) : ORIGIN = 0x20001800, LENGTH = 0x800      /* 2K RAM; */
  RAM6K (rwx) : ORIGIN = 0x20000000, LENGTH = 0x1800     /* 6K RAM; */
  RAM (rwx)   : ORIGIN = 0x20000000, LENGTH = 0x00002000 /* 8K RAM ; 0x20001800-0x20002000 can be used for MTB */
}

/* Library configurations */
/*GROUP(libgcc.a libc.a libm.a libnosys.a)*/

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions FLASH and RAM.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 *
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __copy_table_start__
 *   __copy_table_end__
 *   __zero_table_start__
 *   __zero_table_end__
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapBase
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 *   __Vectors_End
 *   __Vectors_Size
 */
ENTRY(Reset_Handler)

SECTIONS
{
	.text :
	{
		KEEP(*(.vectors))
		__Vectors_End = .;
		__Vectors_Size = __Vectors_End - __Vectors;
		__end__ = .;

		*(.text*)

		KEEP(*(.init))
		KEEP(*(.fini))

		/* .ctors */
		*crtbegin.o(.ctors)
		*crtbegin?.o(.ctors)
		*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
		*(SORT(.ctors.*))
		*(.ctors)

		/* .dtors */
 		*crtbegin.o(.dtors)
 		*crtbegin?.o(.dtors)
 		*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
 		*(SORT(.dtors.*))
 		*(.dtors)

		*(.rodata*)

		KEEP(*(.eh_frame*))
	} > RAM

	.ARM.extab :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > RAM

	__exidx_start = .;
	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} > RAM
	__exidx_end = .;

	/* To copy multiple ROM to RAM sections,
	 * uncomment .copy.table section and,
	 * define __STARTUP_COPY_MULTIPLE in startup_ARMCMx.S */
	/*
	.copy.table :
	{
		. = ALIGN(4);
		__copy_table_start__ = .;
		LONG (__etext)
		LONG (__data_start__)
		LONG (__data_end__ - __data_start__)
		LONG (__etext2)
		LONG (__data2_start__)
		LONG (__data2_end__ - __data2_start__)
		__copy_table_end__ = .;
	} > RAM
	*/

	/* To clear multiple BSS sections,
	 * uncomment .zero.table section and,
	 * define __STARTUP_CLEAR_BSS_MULTIPLE in startup_ARMCMx.S */
	/*
	.zero.table :
	{
		. = ALIGN(4);
		__zero_table_start__ = .;
		LONG (__bss_start__)
		LONG (__bss_end__ - __bss_start__)
		LONG (__bss2_start__)
		LONG (__bss2_end__ - __bss2_start__)
		__zero_table_end__ = .;
	} > RAM
	*/

	.data :
	{
		__etext = .;
		__data_start__ = .;
		*(vtable)
		*(.data*)

		. = ALIGN(4);
		/* preinit data */
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP(*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);

		. = ALIGN(4);
		/* init data */
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE_HIDDEN (__init_array_end = .);


		. = ALIGN(4);
		/* finit data */
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		PROVIDE_HIDDEN (__fini_array_end = .);

		KEEP(*(.jcr*))
		. = ALIGN(4);
		/* All data end */
		__data_end__ = .;

	} > RAM

	.bss :
	{
		. = ALIGN(4);
		__bss_start__ = .;
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
	} > RAM

	.axuninit :
	{
		. = ALIGN(4);
		__axuninit_start__ = .;
		*(.axuninit*)
		. = ALIGN(4);
		__axuninit_end__ = .;
	} > RAM

	.heap (COPY):
	{
		__HeapBase = .;
		__end__ = .;
		end = __end__;
		KEEP(*(.heap*))
		__HeapLimit = .;
	} > RAM

	/* .stack_dummy section doesn't contains any symbols. It is only
	 * used for linker to calculate size of stack sections, and assign
	 * values to stack symbols later */
	.stack_dummy (COPY):
	{
		KEEP(*(.stack*))
	} > RAM

	/* Set stack top to end of RAM, and stack limit move down by
	 * size of stack_dummy section */
	__StackTop = ORIGIN(RAM) + LENGTH(RAM);
	__StackLimit = __StackTop - SIZEOF(.stack_dummy);
	PROVIDE(__stack = __StackTop);

	/* Check if data + heap + stack exceeds RAM limit */
	ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")
}
/* Provide RAM starting addresses */
PROVIDE(RAM2KADDR = ORIGIN(RAM2K));
PROVIDE(RAM6KADDR = ORIGIN(RAM6K));

/* peripheral registers */
/* x40000000	x4XXX??00	GPIO */
PROVIDE(GPIO_DATA                    = 0x40000000);
PROVIDE(GPIO_DATAOUT                 = 0x40000004);
PROVIDE(GPIO_OUT_EN                  = 0x40000008);
PROVIDE(GPIO_INT_EN                  = 0x4000000C);
PROVIDE(GPIO_INT_POL                 = 0x40000010);
PROVIDE(GPIO_INT_TYP                 = 0x40000014);
PROVIDE(GPIO_DMA_EN                  = 0x40000018);
PROVIDE(GPIO_INT_STATUS              = 0x4000001C);

PROVIDE(GPIO_DATAOUT_AND             = 0x44000004);
PROVIDE(GPIO_OUT_EN_AND              = 0x44000008);
PROVIDE(GPIO_DATAOUT_OR              = 0x48000004);
PROVIDE(GPIO_OUT_EN_OR               = 0x48000008);
PROVIDE(GPIO_DATAOUT_XOR             = 0x4C000004);
PROVIDE(GPIO_OUT_EN_XOR              = 0x4C000008);

/* x40100000	x401XXX??	Wakeup Timer */
PROVIDE(WTCFG                        = 0x40100000);
PROVIDE(WTSTAT                       = 0x40100004);
PROVIDE(WTCNT                        = 0x40100008);
PROVIDE(WTEVT                        = 0x4010000C);

/* x40200000	x402FFFFF	RESERVED */
/* x40300000	x403XXX??	Clock and System Configuration */
PROVIDE(CLOCK_CONFIG                 = 0x40300000);
PROVIDE(CLOCK_STATUS                 = 0x40300004);
PROVIDE(ADC_CLK_DIV                  = 0x40300008);
PROVIDE(EXT_CLK_DIV                  = 0x4030000C);
PROVIDE(PCLK_GATE                    = 0x40300010);
PROVIDE(LPOSCCONFIG                  = 0x40300014);
PROVIDE(LPOSCKFILT                   = 0x40300018);
PROVIDE(LPOSCREF                     = 0x4030001C);
PROVIDE(LPOSCFREQ                    = 0x40300020);
PROVIDE(LPOSCPER                     = 0x40300024);
PROVIDE(FRCOSCCONFIG                 = 0x40300028);
PROVIDE(FRCOSCKFILT                  = 0x4030002C);
PROVIDE(FRCOSCREF                    = 0x40300030);
PROVIDE(FRCOSCFREQ                   = 0x40300034);
PROVIDE(FRCOSCLFREQ                  = 0x40300038);
PROVIDE(FRCOSCPER                    = 0x4030003C);
/*PROVIDE(CLOCK_RESERVED               = 0x40300040); */ /* Reserved Spec V1.2 */
PROVIDE(OSCREADY                     = 0x40300044);
PROVIDE(OSCINT                       = 0x40300048);
PROVIDE(LPXOSCGM                     = 0x4030004C);
/*PROVIDE(CLOCK_RESERVED2              = 0x40300050);*/ /* Reserved Spec V1.2 */
PROVIDE(XTALOSC                      = 0x40300054);
PROVIDE(XTALAMPL                     = 0x40300058);
PROVIDE(XTALREADY                    = 0x4030005C);
PROVIDE(AO_SCRATCH                   = 0x40300060);
PROVIDE(IRQLATENCY                   = 0x40300064);

/* x40400000	x404XXX??	PMU */
PROVIDE(POWER_MODE                   = 0x40400000);
PROVIDE(POWER_DOWN                   = 0x40400004);
PROVIDE(POWER_STATUS				 = 0x40400008);

/* x40500000	x405XXX??	XBAR */
PROVIDE(PIO_ANA_ENABLE               = 0x40500000);
PROVIDE(PIO_DRIVE_TYPE               = 0x40500004);
PROVIDE(PIO_PULLUP_EN                = 0x40500008);
PROVIDE(PIO_PULLDOWN_EN              = 0x4050000C);
PROVIDE(PIO_A_CFG                    = 0x40500010);
PROVIDE(PIO_B_CFG                    = 0x40500014);
PROVIDE(PIO_C_CFG                    = 0x40500018);
PROVIDE(PIO_R_CFG                    = 0x4050001C);
PROVIDE(PIO_UART0                    = 0x40500020);
PROVIDE(PIO_UART1                    = 0x40500024);
PROVIDE(PIO_MS_SPI                   = 0x40500028);
PROVIDE(PIO_M_SPI                    = 0x4050002C);
PROVIDE(DMA_TRIG_SEL                 = 0x40500030);
PROVIDE(ADC_TRIG_SEL                 = 0x40500034);
PROVIDE(TIMER0_COUNT_IN              = 0x40500038);
PROVIDE(TIMER1_COUNT_IN              = 0x4050003C);
PROVIDE(TIMER2_COUNT_IN              = 0x40500040);
PROVIDE(CAPTURE0_IN                  = 0x40500044);
PROVIDE(CAPTURE1_IN                  = 0x40500048);
PROVIDE(CAPTURE2_IN                  = 0x4050004C);
PROVIDE(CAPTURE3_IN                  = 0x40500050);
PROVIDE(CLK_IN_SEL                   = 0x40500054);
PROVIDE(IOTEST_EN                    = 0x40500058);
PROVIDE(MTRACE_CTL                   = 0x4050005C);


/* x40600000	x406XXX??	Analog Comparator */
PROVIDE(ANA_CMP_OUT                  = 0x40600000);
PROVIDE(ANA_CMP_CTRL                 = 0x40600004); 
PROVIDE(ANA_CMP_INT_ENABLE           = 0x40600008);
PROVIDE(ANA_CMP_INT_STATUS           = 0x4060000C);


/* x40700000	x407XXX??	ADC */
PROVIDE(ADC_DATA                     = 0x40700000);
PROVIDE(ADC_CFG                      = 0x40700004);
PROVIDE(ADC_CTRL                     = 0x40700008);
PROVIDE(ADC_CALIBRATE                = 0x4070000C);
PROVIDE(ADC_INT_ENABLE               = 0x40700010);
PROVIDE(ADC_INT_STATUS               = 0x40700014);
PROVIDE(ADC_TEST                     = 0x40700018);
PROVIDE(ADC_CHANNEL                  = 0x4070001C);
PROVIDE(ADC_STS                      = 0x40700020);

/* x40800000	x408FFFFF	DMA */
PROVIDE(DMA_STATUS                   = 0x40800000);
PROVIDE(DMA_CFG                      = 0x40800004);
PROVIDE(CTRL_BASE_PTR                = 0x40800008);
PROVIDE(ALT_CTRL_BASE_PTR            = 0x4080000C);
PROVIDE(DMA_WAITONREQ_STATUS         = 0x40800010);
PROVIDE(CHNL_SW_REQUEST              = 0x40800014);
PROVIDE(CHNL_USEBURST_SET            = 0x40800018);
PROVIDE(CHNL_USEBURST_CLR            = 0x4080001C);
PROVIDE(CHNL_REQ_MASK_SET            = 0x40800020);
PROVIDE(CHNL_REQ_MASK_CLR            = 0x40800024);
PROVIDE(CHNL_ENABLE_SET              = 0x40800028);
PROVIDE(CHNL_ENABLE_CLR              = 0x4080002C);
PROVIDE(CHNL_PRI_ALT_SET             = 0x40800030);
PROVIDE(CHNL_PRI_ALT_CLR             = 0x40800034);
PROVIDE(CHNL_PRIORITY_SET            = 0x40800038);
PROVIDE(CHNL_PRIORITY_CLR            = 0x4080003C);
PROVIDE(ERR_CLR                      = 0x4080004C); /* 0x40800040 to 0x40800048 Reserved Spec V1.2 */
PROVIDE(INT_EN                       = 0x40800050);
PROVIDE(INT_STAT                     = 0x40800054);


/* x40900000	x409XXX??	AES */
PROVIDE(AESCTL                       = 0x40900000);
PROVIDE(AESDIN                       = 0x40900004);
PROVIDE(AESDOUT                      = 0x40900008);

/* x40A00000	x40AXXX??	TRNG */
PROVIDE(TRNGCONFIG                   = 0x40A00000);
PROVIDE(TRNGBYTE                     = 0x40A00004);

/* x40B00000	x40BFFFFF	RESERVED */
/* x40C00000	x40CXXX??	FLASH */
PROVIDE(FLSHCNTL                     = 0x40C00000);
PROVIDE(FLSHADDR                     = 0x40C00004);
PROVIDE(FLSHDATA                     = 0x40C00008);
PROVIDE(INT_EN                       = 0x40C0000C);
/*PROVIDE(INT_CLEAR                    = 0x40C00010); */ /* Reserved according to spec V1.2 */
PROVIDE(INT_STAT                     = 0x40C00014);
PROVIDE(PAGE_PROT0                   = 0x40C00018);
PROVIDE(PAGE_PROT1                   = 0x40C0001C);
PROVIDE(PAGE_PROT2                   = 0x40C00020);
PROVIDE(PAGE_PROT3                   = 0x40C00024);
PROVIDE(DMA_ENABLE                   = 0x40C00028);

/* x40D00000	x40DXXX??	CRC */
PROVIDE(CRC_DATA                     = 0x40D00000);
PROVIDE(CRC_INPUT                    = 0x40D00004);

/* x40E00000	x40EFFFFF	RESERVED */
/* x40F00000	x40FXXX??	Watchdog */
PROVIDE(WDOGLOAD                     = 0x40F00000);
PROVIDE(WDOGVALUE                    = 0x40F00004);
PROVIDE(WDOGCONTROL                  = 0x40F00008);
/*PROVIDE(WDOGINTCLR                   = 0x40F0000C);*/ /* Reserved Spec V1.2 */
PROVIDE(WDOGRIS                      = 0x40F00010);
PROVIDE(WDOGMIS                      = 0x40F00014);
PROVIDE(WDOGGLOCK                    = 0x40F00C00);
PROVIDE(WDOGITCR                     = 0x40F00F00);
PROVIDE(WDOGITOP                     = 0x40F00F04);

/* x41000000	x41XXX??0	Ticker Timer */
PROVIDE(TTCFG                        = 0x41000000);
PROVIDE(TTSTAT                       = 0x41000004);
PROVIDE(TTCNT                        = 0x41000008);
PROVIDE(TTEVT                        = 0x4100000C);

/* x41100000	x411XXX??	TIMER0 */
PROVIDE(T0CNT                        = 0x41100000);
PROVIDE(T0PERIOD                     = 0x41100004);
PROVIDE(T0CONFIG                     = 0x41100008);
PROVIDE(T0STATUS                     = 0x4110000C);

/* x41200000	x412XXX??	TIMER1 */
PROVIDE(T1CNT                        = 0x41100000);
PROVIDE(T1PERIOD                     = 0x41100004);
PROVIDE(T1CONFIG                     = 0x41100008);
PROVIDE(T1STATUS                     = 0x4110000C);

/* x41300000	x413XXX??	TIMER2 */
PROVIDE(T2CNT                        = 0x41100000);
PROVIDE(T2PERIOD                     = 0x41100004);
PROVIDE(T2CONFIG                     = 0x41100008);
PROVIDE(T2STATUS                     = 0x4110000C);

/* x41400000	x414XXX??	CC_PWM0 */
PROVIDE(CP0MODE                      = 0x41400000);
PROVIDE(CP0STAT                      = 0x41400004);
PROVIDE(CP0DATA                      = 0x41400008);

/* x41500000	x415XXX??	CC_PWM1 */
PROVIDE(CP1MODE                      = 0x41400000);
PROVIDE(CP1STAT                      = 0x41400004);
PROVIDE(CP1DATA                      = 0x41400008);

/* x41600000	x416XXX??	CC_PWM2 */
PROVIDE(CP2MODE                      = 0x41400000);
PROVIDE(CP2STAT                      = 0x41400004);
PROVIDE(CP2DATA                      = 0x41400008);

/* x41700000	x417XXX??	CC_PWM3 */
PROVIDE(CP3MODE                      = 0x41400000);
PROVIDE(CP3STAT                      = 0x41400004);
PROVIDE(CP3DATA                      = 0x41400008);

/* x41800000	x418FFFFF	Reserved */
/* x41900000	x419FFFFF	SPI0 */
PROVIDE(SPI0DATA                     = 0x419FFFF0);
PROVIDE(SPI0ADDR                     = 0x419FFFF4);
PROVIDE(SPI0CONFIG                   = 0x419FFFF8);
PROVIDE(SPI0STAT                     = 0x419FFFFC);

/* x41A00000	x41AXXX??	SPI1 */
PROVIDE(SPI1SHREG                    = 0x41A00000);
PROVIDE(SPI1CONFIG                   = 0x41A00004);
PROVIDE(SPI1STATUS                   = 0x41A00008);

/* x41B00000	x41BXXX??	UART0 */
PROVIDE(U0SHREG                      = 0x41B00000);
PROVIDE(U0CONFIG                     = 0x41B00004);
PROVIDE(U0STATUS                     = 0x41B00008);

/* x41C00000	x41CXXX??	UART1 */
PROVIDE(U1SHREG                      = 0x41C00000);
PROVIDE(U1CONFIG                     = 0x41C00004);
PROVIDE(U1STATUS                     = 0x41C00008);

/* x41D00000	x41DXXX??	I2C */
PROVIDE(I2CCTRL0                     = 0x41D00000);
PROVIDE(I2CCTRL1                     = 0x41D00004);
PROVIDE(I2CDATA                      = 0x41D00008);
PROVIDE(I2CDATA_M                    = 0x41D0000C);
PROVIDE(I2CADDR_START                = 0x41D00010);
PROVIDE(I2CSTATUS                    = 0x41D00014);
PROVIDE(I2C_INTERRUPT_STATUS         = 0X41D00018);

/* x41E00000	x41EFFFFF	RESERVED */
/* x41F00000	x41FXXX??	TEST */
PROVIDE(TEST_MODE                    = 0x41F00008);
PROVIDE(BIST_CTL                     = 0x41F0000C);
PROVIDE(BIST_DIAG                    = 0x41F00010);
PROVIDE(BIST0_COMP                   = 0x41F00014);
PROVIDE(BIST0_ADDR                   = 0x41F00018);
PROVIDE(BIST0_DATA                   = 0x41F0001C);
PROVIDE(BIST1_COMP                   = 0x41F00020);
PROVIDE(BIST1_ADDR                   = 0x41F00024);
PROVIDE(BIST1_DATA                   = 0x41F00028);
PROVIDE(SCAN_MODE                    = 0x41F00030);
PROVIDE(SCRATCH                      = 0x41F00044);
PROVIDE(TRIM                         = 0x41F00048);
PROVIDE(REV_ID                       = 0x41F00050);
PROVIDE(LOCK_OVER                    = 0x41F00060);
PROVIDE(ANA_TEST                     = 0x41F00068);

/* AX5031 */
PROVIDE(AX5031_SILICONREVISION       = 0x41820000); /* Silicon Revision */
PROVIDE(AX5031_SCRATCH               = 0x41820004); /* Scratch */
PROVIDE(AX5031_PWRMODE               = 0x41820008); /* Power Mode */
PROVIDE(AX5031_XTALOSC               = 0x4182000C); /* Crystal Oscillator Control */
PROVIDE(AX5031_FIFOCONTROL           = 0x41820010); /* FIFO Control */
PROVIDE(AX5031_FIFODATA              = 0x41820014); /* FIFO Data */
PROVIDE(AX5031_IRQMASK               = 0x41820018); /* IRQ Mask */
PROVIDE(AX5031_IRQREQUEST            = 0x4182001C); /* IRQ Request */
PROVIDE(AX5031_IFMODE                = 0x41820020); /* Interface Mode */
PROVIDE(AX5031_PINCFG1               = 0x41820030); /* Pin Configuration 1 */
PROVIDE(AX5031_PINCFG2               = 0x41820034); /* Pin Configuration 2 */
PROVIDE(AX5031_PINCFG3               = 0x41820038); /* Pin Configuration 3 */
PROVIDE(AX5031_IRQINVERSION          = 0x4182003C); /* IRQ Inversion */
PROVIDE(AX5031_MODULATION            = 0x41820040); /* Modulation */
PROVIDE(AX5031_ENCODING              = 0x41820044); /* Encoding */
PROVIDE(AX5031_FRAMING               = 0x41820048); /* Framing Mode */
PROVIDE(AX5031_CRCINIT               = 0x419A0050); /* CRC Initial Value */
PROVIDE(AX5031_CRCINIT3              = 0x41820050); /* CRC Initial Value 3 */
PROVIDE(AX5031_CRCINIT2              = 0x41820054); /* CRC Initial Value 2 */
PROVIDE(AX5031_CRCINIT1              = 0x41820058); /* CRC Initial Value 1 */
PROVIDE(AX5031_CRCINIT0              = 0x4182005C); /* CRC Initial Value 0 */
PROVIDE(AX5031_FEC                   = 0x41820060); /* Forward Error Correction */
PROVIDE(AX5031_VREG                  = 0x4182006C); /* Voltage Regulator */
PROVIDE(AX5031_FREQB                 = 0x419A0070); /* Frequency B */
PROVIDE(AX5031_FREQB3                = 0x41820070); /* Frequency B 3 */
PROVIDE(AX5031_FREQB2                = 0x41820074); /* Frequency B 2 */
PROVIDE(AX5031_FREQB1                = 0x41820078); /* Frequency B 1 */
PROVIDE(AX5031_FREQB0                = 0x4182007C); /* Frequency B 0 */
PROVIDE(AX5031_FREQA                 = 0x419A0080); /* Frequency A */
PROVIDE(AX5031_FREQA3                = 0x41820080); /* Frequency A 3 */
PROVIDE(AX5031_FREQA2                = 0x41820084); /* Frequency A 2 */
PROVIDE(AX5031_FREQA1                = 0x41820088); /* Frequency A 1 */
PROVIDE(AX5031_FREQA0                = 0x4182008C); /* Frequency A 0 */
PROVIDE(AX5031_FSKDEV                = 0x41920094); /* FSK Deviation */
PROVIDE(AX5031_FSKDEV2               = 0x41820094); /* FSK Deviation 2 */
PROVIDE(AX5031_FSKDEV1               = 0x41820098); /* FSK Deviation 1 */
PROVIDE(AX5031_FSKDEV0               = 0x4182009C); /* FSK Deviation 0 */
PROVIDE(AX5031_PLLLOOP               = 0x418200B0); /* PLL Loop Filter */
PROVIDE(AX5031_PLLRANGING            = 0x418200B4); /* PLL Autoranging Control */
PROVIDE(AX5031_PLLRNGCLK             = 0x418200B8); /* PLL Autoranging Clock */
PROVIDE(AX5031_TXPWR                 = 0x418200C0); /* Transmit Power */
PROVIDE(AX5031_TXBITRATEHI           = 0x418200C4); /* Transmitter Bitrate High */
PROVIDE(AX5031_TXBITRATEMID          = 0x418200C8); /* Transmitter Bitrate Middle */
PROVIDE(AX5031_TXBITRATELO           = 0x418200CC); /* Transmitter Bitrate Low */
PROVIDE(AX5031_MODULATORMISC         = 0x418200D0); /* Modulator Miscellaneous Control */
PROVIDE(AX5031_FIFOCOUNT             = 0x418200D4); /* FIFO Count */
PROVIDE(AX5031_FIFOTHRESH            = 0x418200D8); /* FIFO Threshold */
PROVIDE(AX5031_FIFOCONTROL2          = 0x418200DC); /* FIFO Control 2 */
PROVIDE(AX5031_XTALCAP               = 0x4182013C); /* Crystal Oscillator Load Capacitance */
PROVIDE(AX5031_FOURFSK               = 0x41820140); /* 4-FSK Control */
PROVIDE(AX5031_XTALOSCCFG            = 0x41820144); /* Crystal Oscillator Mode Configuration */
PROVIDE(AX5031_SILICONREVISIONNB     = 0x41860000); /* Silicon Revision, non-blocking */
PROVIDE(AX5031_SCRATCHNB             = 0x41860004); /* Scratch, non-blocking */
PROVIDE(AX5031_PWRMODENB             = 0x41860008); /* Power Mode, non-blocking */
PROVIDE(AX5031_XTALOSCNB             = 0x4186000C); /* Crystal Oscillator Control, non-blocking */
PROVIDE(AX5031_FIFOCONTROLNB         = 0x41860010); /* FIFO Control, non-blocking */
PROVIDE(AX5031_FIFODATANB            = 0x41860014); /* FIFO Data, non-blocking */
PROVIDE(AX5031_IRQMASKNB             = 0x41860018); /* IRQ Mask, non-blocking */
PROVIDE(AX5031_IRQREQUESTNB          = 0x4186001C); /* IRQ Request, non-blocking */
PROVIDE(AX5031_IFMODENB              = 0x41860020); /* Interface Mode, non-blocking */
PROVIDE(AX5031_PINCFG1NB             = 0x41860030); /* Pin Configuration 1, non-blocking */
PROVIDE(AX5031_PINCFG2NB             = 0x41860034); /* Pin Configuration 2, non-blocking */
PROVIDE(AX5031_PINCFG3NB             = 0x41860038); /* Pin Configuration 3, non-blocking */
PROVIDE(AX5031_IRQINVERSIONNB        = 0x4186003C); /* IRQ Inversion, non-blocking */
PROVIDE(AX5031_MODULATIONNB          = 0x41860040); /* Modulation, non-blocking */
PROVIDE(AX5031_ENCODINGNB            = 0x41860044); /* Encoding, non-blocking */
PROVIDE(AX5031_FRAMINGNB             = 0x41860048); /* Framing Mode, non-blocking */
PROVIDE(AX5031_CRCINITNB             = 0x419E0050); /* CRC Initial Value, non-blocking */
PROVIDE(AX5031_CRCINIT3NB            = 0x41860050); /* CRC Initial Value 3, non-blocking */
PROVIDE(AX5031_CRCINIT2NB            = 0x41860054); /* CRC Initial Value 2, non-blocking */
PROVIDE(AX5031_CRCINIT1NB            = 0x41860058); /* CRC Initial Value 1, non-blocking */
PROVIDE(AX5031_CRCINIT0NB            = 0x4186005C); /* CRC Initial Value 0, non-blocking */
PROVIDE(AX5031_FECNB                 = 0x41860060); /* Forward Error Correction, non-blocking */
PROVIDE(AX5031_VREGNB                = 0x4186006C); /* Voltage Regulator, non-blocking */
PROVIDE(AX5031_FREQBNB               = 0x419E0070); /* Frequency B, non-blocking */
PROVIDE(AX5031_FREQB3NB              = 0x41860070); /* Frequency B 3, non-blocking */
PROVIDE(AX5031_FREQB2NB              = 0x41860074); /* Frequency B 2, non-blocking */
PROVIDE(AX5031_FREQB1NB              = 0x41860078); /* Frequency B 1, non-blocking */
PROVIDE(AX5031_FREQB0NB              = 0x4186007C); /* Frequency B 0, non-blocking */
PROVIDE(AX5031_FREQANB               = 0x419E0080); /* Frequency A, non-blocking */
PROVIDE(AX5031_FREQA3NB              = 0x41860080); /* Frequency A 3, non-blocking */
PROVIDE(AX5031_FREQA2NB              = 0x41860084); /* Frequency A 2, non-blocking */
PROVIDE(AX5031_FREQA1NB              = 0x41860088); /* Frequency A 1, non-blocking */
PROVIDE(AX5031_FREQA0NB              = 0x4186008C); /* Frequency A 0, non-blocking */
PROVIDE(AX5031_FSKDEVNB              = 0x41960094); /* FSK Deviation, non-blocking */
PROVIDE(AX5031_FSKDEV2NB             = 0x41860094); /* FSK Deviation 2, non-blocking */
PROVIDE(AX5031_FSKDEV1NB             = 0x41860098); /* FSK Deviation 1, non-blocking */
PROVIDE(AX5031_FSKDEV0NB             = 0x4186009C); /* FSK Deviation 0, non-blocking */
PROVIDE(AX5031_PLLLOOPNB             = 0x418600B0); /* PLL Loop Filter, non-blocking */
PROVIDE(AX5031_PLLRANGINGNB          = 0x418600B4); /* PLL Autoranging Control, non-blocking */
PROVIDE(AX5031_PLLRNGCLKNB           = 0x418600B8); /* PLL Autoranging Clock, non-blocking */
PROVIDE(AX5031_TXPWRNB               = 0x418600C0); /* Transmit Power, non-blocking */
PROVIDE(AX5031_TXBITRATEHINB         = 0x418600C4); /* Transmitter Bitrate High, non-blocking */
PROVIDE(AX5031_TXBITRATEMIDNB        = 0x418600C8); /* Transmitter Bitrate Middle, non-blocking */
PROVIDE(AX5031_TXBITRATELONB         = 0x418600CC); /* Transmitter Bitrate Low, non-blocking */
PROVIDE(AX5031_MODULATORMISCNB       = 0x418600D0); /* Modulator Miscellaneous Control, non-blocking */
PROVIDE(AX5031_FIFOCOUNTNB           = 0x418600D4); /* FIFO Count, non-blocking */
PROVIDE(AX5031_FIFOTHRESHNB          = 0x418600D8); /* FIFO Threshold, non-blocking */
PROVIDE(AX5031_FIFOCONTROL2NB        = 0x418600DC); /* FIFO Control 2, non-blocking */
PROVIDE(AX5031_XTALCAPNB             = 0x4186013C); /* Crystal Oscillator Load Capacitance, non-blocking */
PROVIDE(AX5031_FOURFSKNB             = 0x41860140); /* 4-FSK Control, non-blocking */
PROVIDE(AX5031_XTALOSCCFGNB          = 0x41860144); /* Crystal Oscillator Mode Configuration, non-blocking */

/* AX5042 */
PROVIDE(AX5042_SILICONREVISION       = 0x41820000); /* Silicon Revision */
PROVIDE(AX5042_SCRATCH               = 0x41820004); /* Scratch */
PROVIDE(AX5042_PWRMODE               = 0x41820008); /* Power Mode */
PROVIDE(AX5042_XTALOSC               = 0x4182000C); /* Crystal Oscillator Control */
PROVIDE(AX5042_FIFOCONTROL           = 0x41820010); /* FIFO Control */
PROVIDE(AX5042_FIFODATA              = 0x41820014); /* FIFO Data */
PROVIDE(AX5042_IRQMASK               = 0x41820018); /* IRQ Mask */
PROVIDE(AX5042_IRQREQUEST            = 0x4182001C); /* IRQ Request */
PROVIDE(AX5042_IFMODE                = 0x41820020); /* Interface Mode */
PROVIDE(AX5042_DSPMODE               = 0x41820024); /* DSP Mode Interface Control */
PROVIDE(AX5042_TXDSPMODE             = 0x41820028); /* Transmit DSP Mode */
PROVIDE(AX5042_PINCFG1               = 0x41820030); /* Pin Configuration 1 */
PROVIDE(AX5042_PINCFG2               = 0x41820034); /* Pin Configuration 2 */
PROVIDE(AX5042_PINCFG3               = 0x41820038); /* Pin Configuration 3 */
PROVIDE(AX5042_IRQINVERSION          = 0x4182003C); /* IRQ Inversion */
PROVIDE(AX5042_MODULATION            = 0x41820040); /* Modulation */
PROVIDE(AX5042_ENCODING              = 0x41820044); /* Encoding */
PROVIDE(AX5042_FRAMING               = 0x41820048); /* Framing Mode */
PROVIDE(AX5042_CRCINIT               = 0x419A0050); /* CRC Initial Value */
PROVIDE(AX5042_CRCINIT3              = 0x41820050); /* CRC Initial Value 3 */
PROVIDE(AX5042_CRCINIT2              = 0x41820054); /* CRC Initial Value 2 */
PROVIDE(AX5042_CRCINIT1              = 0x41820058); /* CRC Initial Value 1 */
PROVIDE(AX5042_CRCINIT0              = 0x4182005C); /* CRC Initial Value 0 */
PROVIDE(AX5042_FEC                   = 0x41820060); /* Forward Error Correction */
PROVIDE(AX5042_FECSYNC               = 0x41820064); /* Forward Error Correction Sync Threshold */
PROVIDE(AX5042_FECSTATUS             = 0x41820068); /* Forward Error Correction Status */
PROVIDE(AX5042_FREQ                  = 0x419A0080); /* Frequency */
PROVIDE(AX5042_FREQ3                 = 0x41820080); /* Frequency 3 */
PROVIDE(AX5042_FREQ2                 = 0x41820084); /* Frequency 2 */
PROVIDE(AX5042_FREQ1                 = 0x41820088); /* Frequency 1 */
PROVIDE(AX5042_FREQ0                 = 0x4182008C); /* Frequency 0 */
PROVIDE(AX5042_FSKDEV                = 0x41920094); /* FSK Deviation */
PROVIDE(AX5042_FSKDEV2               = 0x41820094); /* FSK Deviation 2 */
PROVIDE(AX5042_FSKDEV1               = 0x41820098); /* FSK Deviation 1 */
PROVIDE(AX5042_FSKDEV0               = 0x4182009C); /* FSK Deviation 0 */
PROVIDE(AX5042_IFFREQHI              = 0x418200A0); /* IF Frequency Low */
PROVIDE(AX5042_IFFREQLO              = 0x418200A4); /* IF Frequency High */
PROVIDE(AX5042_PLLLOOP               = 0x418200B0); /* PLL Loop Filter */
PROVIDE(AX5042_PLLRANGING            = 0x418200B4); /* PLL Autoranging Control */
PROVIDE(AX5042_PLLRNGCLK             = 0x418200B8); /* PLL Autoranging Clock */
PROVIDE(AX5042_TXPWR                 = 0x418200C0); /* Transmit Power */
PROVIDE(AX5042_TXBITRATEHI           = 0x418200C4); /* Transmitter Bitrate High */
PROVIDE(AX5042_TXBITRATEMID          = 0x418200C8); /* Transmitter Bitrate Middle */
PROVIDE(AX5042_TXBITRATELO           = 0x418200CC); /* Transmitter Bitrate Low */
PROVIDE(AX5042_MODULATORMISC         = 0x418200D0); /* Modulator Miscellaneous Control */
PROVIDE(AX5042_ADCMISC               = 0x418200E0); /* ADC Miscellaneous Control */
PROVIDE(AX5042_AGCTARGET             = 0x418200E4); /* AGC Target Value */
PROVIDE(AX5042_AGCATTACK             = 0x418200E8); /* AGC Attack Speed */
PROVIDE(AX5042_AGCDECAY              = 0x418200EC); /* AGC Decay Speed */
PROVIDE(AX5042_AGCCOUNTER            = 0x418200F0); /* AGC Counter */
PROVIDE(AX5042_CICSHIFT              = 0x418200F4); /* Decimation Filter Attenuation */
PROVIDE(AX5042_CICDECHI              = 0x418200F8); /* Decimation Factor High */
PROVIDE(AX5042_CICDECLO              = 0x418200FC); /* Decimation Factor Low */
PROVIDE(AX5042_DATARATEHI            = 0x41820100); /* Datarate High */
PROVIDE(AX5042_DATARATELO            = 0x41820104); /* Datarate Low */
PROVIDE(AX5042_TIMINGGAINHI          = 0x41820108); /* Timing Estimator Bandwidth High */
PROVIDE(AX5042_TIMINGGAINLO          = 0x4182010C); /* Timing Estimator Bandwidth Low */
PROVIDE(AX5042_PHASEGAIN             = 0x41820110); /* Phase Estimator Bandwidth */
PROVIDE(AX5042_FREQUENCYGAIN         = 0x41820114); /* Frequency Estimator Bandwidth */
PROVIDE(AX5042_FREQUENCYGAIN2        = 0x41820118); /* Frequency Estimator Bandwidth 2 */
PROVIDE(AX5042_AMPLITUDEGAIN         = 0x4182011C); /* Amplitude Estimator Bandwidth */
PROVIDE(AX5042_TRKAMPLITUDEHI        = 0x41820120); /* Amplitude Tracking High */
PROVIDE(AX5042_TRKAMPLITUDELO        = 0x41820124); /* Amplitude Tracking Low */
PROVIDE(AX5042_TRKPHASEHI            = 0x41820128); /* Phase Tracking High */
PROVIDE(AX5042_TRKPHASELO            = 0x4182012C); /* Phase Tracking Low */
PROVIDE(AX5042_TRKFREQHI             = 0x41820130); /* Frequency Tracking High */
PROVIDE(AX5042_TRKFREQLO             = 0x41820134); /* Frequency Tracking Low */
PROVIDE(AX5042_APEOVERRIDE           = 0x418201C0); /* APE Override */
PROVIDE(AX5042_PLLVCOI               = 0x418201C8); /* PLL VCO Current */
PROVIDE(AX5042_PLLRNGMISC            = 0x418201D0); /* PLL Autoranging Miscellaneous */
PROVIDE(AX5042_REF                   = 0x418201F0); /* Reference */
PROVIDE(AX5042_RXMISC                = 0x418201F4); /* Receiver Miscellaneous Control */
PROVIDE(AX5042_SILICONREVISIONNB     = 0x41860000); /* Silicon Revision, non-blocking */
PROVIDE(AX5042_SCRATCHNB             = 0x41860004); /* Scratch, non-blocking */
PROVIDE(AX5042_PWRMODENB             = 0x41860008); /* Power Mode, non-blocking */
PROVIDE(AX5042_XTALOSCNB             = 0x4186000C); /* Crystal Oscillator Control, non-blocking */
PROVIDE(AX5042_FIFOCONTROLNB         = 0x41860010); /* FIFO Control, non-blocking */
PROVIDE(AX5042_FIFODATANB            = 0x41860014); /* FIFO Data, non-blocking */
PROVIDE(AX5042_IRQMASKNB             = 0x41860018); /* IRQ Mask, non-blocking */
PROVIDE(AX5042_IRQREQUESTNB          = 0x4186001C); /* IRQ Request, non-blocking */
PROVIDE(AX5042_IFMODENB              = 0x41860020); /* Interface Mode, non-blocking */
PROVIDE(AX5042_DSPMODENB             = 0x41860024); /* DSP Mode Interface Control, non-blocking */
PROVIDE(AX5042_TXDSPMODENB           = 0x41860028); /* Transmit DSP Mode, non-blocking */
PROVIDE(AX5042_PINCFG1NB             = 0x41860030); /* Pin Configuration 1, non-blocking */
PROVIDE(AX5042_PINCFG2NB             = 0x41860034); /* Pin Configuration 2, non-blocking */
PROVIDE(AX5042_PINCFG3NB             = 0x41860038); /* Pin Configuration 3, non-blocking */
PROVIDE(AX5042_IRQINVERSIONNB        = 0x4186003C); /* IRQ Inversion, non-blocking */
PROVIDE(AX5042_MODULATIONNB          = 0x41860040); /* Modulation, non-blocking */
PROVIDE(AX5042_ENCODINGNB            = 0x41860044); /* Encoding, non-blocking */
PROVIDE(AX5042_FRAMINGNB             = 0x41860048); /* Framing Mode, non-blocking */
PROVIDE(AX5042_CRCINITNB             = 0x419E0050); /* CRC Initial Value, non-blocking */
PROVIDE(AX5042_CRCINIT3NB            = 0x41860050); /* CRC Initial Value 3, non-blocking */
PROVIDE(AX5042_CRCINIT2NB            = 0x41860054); /* CRC Initial Value 2, non-blocking */
PROVIDE(AX5042_CRCINIT1NB            = 0x41860058); /* CRC Initial Value 1, non-blocking */
PROVIDE(AX5042_CRCINIT0NB            = 0x4186005C); /* CRC Initial Value 0, non-blocking */
PROVIDE(AX5042_FECNB                 = 0x41860060); /* Forward Error Correction, non-blocking */
PROVIDE(AX5042_FECSYNCNB             = 0x41860064); /* Forward Error Correction Sync Threshold, non-blocking */
PROVIDE(AX5042_FECSTATUSNB           = 0x41860068); /* Forward Error Correction Status, non-blocking */
PROVIDE(AX5042_FREQNB                = 0x419E0080); /* Frequency, non-blocking */
PROVIDE(AX5042_FREQ3NB               = 0x41860080); /* Frequency 3, non-blocking */
PROVIDE(AX5042_FREQ2NB               = 0x41860084); /* Frequency 2, non-blocking */
PROVIDE(AX5042_FREQ1NB               = 0x41860088); /* Frequency 1, non-blocking */
PROVIDE(AX5042_FREQ0NB               = 0x4186008C); /* Frequency 0, non-blocking */
PROVIDE(AX5042_FSKDEVNB              = 0x41960094); /* FSK Deviation, non-blocking */
PROVIDE(AX5042_FSKDEV2NB             = 0x41860094); /* FSK Deviation 2, non-blocking */
PROVIDE(AX5042_FSKDEV1NB             = 0x41860098); /* FSK Deviation 1, non-blocking */
PROVIDE(AX5042_FSKDEV0NB             = 0x4186009C); /* FSK Deviation 0, non-blocking */
PROVIDE(AX5042_IFFREQHINB            = 0x418600A0); /* IF Frequency Low, non-blocking */
PROVIDE(AX5042_IFFREQLONB            = 0x418600A4); /* IF Frequency High, non-blocking */
PROVIDE(AX5042_PLLLOOPNB             = 0x418600B0); /* PLL Loop Filter, non-blocking */
PROVIDE(AX5042_PLLRANGINGNB          = 0x418600B4); /* PLL Autoranging Control, non-blocking */
PROVIDE(AX5042_PLLRNGCLKNB           = 0x418600B8); /* PLL Autoranging Clock, non-blocking */
PROVIDE(AX5042_TXPWRNB               = 0x418600C0); /* Transmit Power, non-blocking */
PROVIDE(AX5042_TXBITRATEHINB         = 0x418600C4); /* Transmitter Bitrate High, non-blocking */
PROVIDE(AX5042_TXBITRATEMIDNB        = 0x418600C8); /* Transmitter Bitrate Middle, non-blocking */
PROVIDE(AX5042_TXBITRATELONB         = 0x418600CC); /* Transmitter Bitrate Low, non-blocking */
PROVIDE(AX5042_MODULATORMISCNB       = 0x418600D0); /* Modulator Miscellaneous Control, non-blocking */
PROVIDE(AX5042_ADCMISCNB             = 0x418600E0); /* ADC Miscellaneous Control, non-blocking */
PROVIDE(AX5042_AGCTARGETNB           = 0x418600E4); /* AGC Target Value, non-blocking */
PROVIDE(AX5042_AGCATTACKNB           = 0x418600E8); /* AGC Attack Speed, non-blocking */
PROVIDE(AX5042_AGCDECAYNB            = 0x418600EC); /* AGC Decay Speed, non-blocking */
PROVIDE(AX5042_AGCCOUNTERNB          = 0x418600F0); /* AGC Counter, non-blocking */
PROVIDE(AX5042_CICSHIFTNB            = 0x418600F4); /* Decimation Filter Attenuation, non-blocking */
PROVIDE(AX5042_CICDECHINB            = 0x418600F8); /* Decimation Factor High, non-blocking */
PROVIDE(AX5042_CICDECLONB            = 0x418600FC); /* Decimation Factor Low, non-blocking */
PROVIDE(AX5042_DATARATEHINB          = 0x41860100); /* Datarate High, non-blocking */
PROVIDE(AX5042_DATARATELONB          = 0x41860104); /* Datarate Low, non-blocking */
PROVIDE(AX5042_TIMINGGAINHINB        = 0x41860108); /* Timing Estimator Bandwidth High, non-blocking */
PROVIDE(AX5042_TIMINGGAINLONB        = 0x4186010C); /* Timing Estimator Bandwidth Low, non-blocking */
PROVIDE(AX5042_PHASEGAINNB           = 0x41860110); /* Phase Estimator Bandwidth, non-blocking */
PROVIDE(AX5042_FREQUENCYGAINNB       = 0x41860114); /* Frequency Estimator Bandwidth, non-blocking */
PROVIDE(AX5042_FREQUENCYGAIN2NB      = 0x41860118); /* Frequency Estimator Bandwidth 2, non-blocking */
PROVIDE(AX5042_AMPLITUDEGAINNB       = 0x4186011C); /* Amplitude Estimator Bandwidth, non-blocking */
PROVIDE(AX5042_TRKAMPLITUDEHINB      = 0x41860120); /* Amplitude Tracking High, non-blocking */
PROVIDE(AX5042_TRKAMPLITUDELONB      = 0x41860124); /* Amplitude Tracking Low, non-blocking */
PROVIDE(AX5042_TRKPHASEHINB          = 0x41860128); /* Phase Tracking High, non-blocking */
PROVIDE(AX5042_TRKPHASELONB          = 0x4186012C); /* Phase Tracking Low, non-blocking */
PROVIDE(AX5042_TRKFREQHINB           = 0x41860130); /* Frequency Tracking High, non-blocking */
PROVIDE(AX5042_TRKFREQLONB           = 0x41860134); /* Frequency Tracking Low, non-blocking */
PROVIDE(AX5042_APEOVERRIDENB         = 0x418601C0); /* APE Override, non-blocking */
PROVIDE(AX5042_PLLVCOINB             = 0x418601C8); /* PLL VCO Current, non-blocking */
PROVIDE(AX5042_PLLRNGMISCNB          = 0x418601D0); /* PLL Autoranging Miscellaneous, non-blocking */
PROVIDE(AX5042_REFNB                 = 0x418601F0); /* Reference, non-blocking */
PROVIDE(AX5042_RXMISCNB              = 0x418601F4); /* Receiver Miscellaneous Control, non-blocking */

/* AX5043 */
PROVIDE(AX5043_SILICONREVISION       = 0x41820000); /* Silicon Revision */
PROVIDE(AX5043_SCRATCH               = 0x41820004); /* Scratch */
PROVIDE(AX5043_PWRMODE               = 0x41820008); /* Power Mode */
PROVIDE(AX5043_POWSTAT               = 0x4182000C); /* Power Management Status */
PROVIDE(AX5043_POWSTICKYSTAT         = 0x41820010); /* Power Management Sticky Status */
PROVIDE(AX5043_POWIRQMASK            = 0x41820014); /* Power Management Interrupt Mask */
PROVIDE(AX5043_IRQMASK               = 0x418A0018); /* IRQ Mask */
PROVIDE(AX5043_IRQMASK1              = 0x41820018); /* IRQ Mask 1 */
PROVIDE(AX5043_IRQMASK0              = 0x4182001C); /* IRQ Mask 0 */
PROVIDE(AX5043_RADIOEVENTMASK        = 0x418A0020); /* Radio Event Mask */
PROVIDE(AX5043_RADIOEVENTMASK1       = 0x41820020); /* Radio Event Mask 1 */
PROVIDE(AX5043_RADIOEVENTMASK0       = 0x41820024); /* Radio Event Mask 0 */
PROVIDE(AX5043_IRQINVERSION          = 0x418A0028); /* IRQ Inversion */
PROVIDE(AX5043_IRQINVERSION1         = 0x41820028); /* IRQ Inversion 1 */
PROVIDE(AX5043_IRQINVERSION0         = 0x4182002C); /* IRQ Inversion 0 */
PROVIDE(AX5043_IRQREQUEST            = 0x418A0030); /* IRQ Request */
PROVIDE(AX5043_IRQREQUEST1           = 0x41820030); /* IRQ Request 1 */
PROVIDE(AX5043_IRQREQUEST0           = 0x41820034); /* IRQ Request 0 */
PROVIDE(AX5043_RADIOEVENTREQ         = 0x418A0038); /* Radio Event Request */
PROVIDE(AX5043_RADIOEVENTREQ1        = 0x41820038); /* Radio Event Request 1 */
PROVIDE(AX5043_RADIOEVENTREQ0        = 0x4182003C); /* Radio Event Request 0 */
PROVIDE(AX5043_MODULATION            = 0x41820040); /* Modulation */
PROVIDE(AX5043_ENCODING              = 0x41820044); /* Encoding */
PROVIDE(AX5043_FRAMING               = 0x41820048); /* Framing Mode */
PROVIDE(AX5043_CRCINIT               = 0x419A0050); /* CRC Initial Value */
PROVIDE(AX5043_CRCINIT3              = 0x41820050); /* CRC Initial Value 3 */
PROVIDE(AX5043_CRCINIT2              = 0x41820054); /* CRC Initial Value 2 */
PROVIDE(AX5043_CRCINIT1              = 0x41820058); /* CRC Initial Value 1 */
PROVIDE(AX5043_CRCINIT0              = 0x4182005C); /* CRC Initial Value 0 */
PROVIDE(AX5043_FEC                   = 0x41820060); /* Forward Error Correction */
PROVIDE(AX5043_FECSYNC               = 0x41820064); /* Forward Error Correction Sync Threshold */
PROVIDE(AX5043_FECSTATUS             = 0x41820068); /* Forward Error Correction Status */
PROVIDE(AX5043_RADIOSTATE            = 0x41820070); /* Radio Controller State */
PROVIDE(AX5043_XTALSTATUS            = 0x41820074); /* Crystal Oscillator Status */
PROVIDE(AX5043_PINSTATE              = 0x41820080); /* Pin State */
PROVIDE(AX5043_PINFUNCSYSCLK         = 0x41820084); /* Pin Function SYSCLK */
PROVIDE(AX5043_PINFUNCDCLK           = 0x41820088); /* Pin Function DCLK */
PROVIDE(AX5043_PINFUNCDATA           = 0x4182008C); /* Pin Function DATA */
PROVIDE(AX5043_PINFUNCIRQ            = 0x41820090); /* Pin Function IRQ */
PROVIDE(AX5043_PINFUNCANTSEL         = 0x41820094); /* Pin Function ANTSEL */
PROVIDE(AX5043_PINFUNCPWRAMP         = 0x41820098); /* Pin Function PWRAMP */
PROVIDE(AX5043_PWRAMP                = 0x4182009C); /* PWRAMP Control */
PROVIDE(AX5043_FIFOSTAT              = 0x418200A0); /* FIFO Control */
PROVIDE(AX5043_FIFODATA              = 0x418200A4); /* FIFO Data */
PROVIDE(AX5043_FIFOCOUNT             = 0x418A00A8); /* Number of Words currently in FIFO */
PROVIDE(AX5043_FIFOCOUNT1            = 0x418200A8); /* Number of Words currently in FIFO 1 */
PROVIDE(AX5043_FIFOCOUNT0            = 0x418200AC); /* Number of Words currently in FIFO 0 */
PROVIDE(AX5043_FIFOFREE              = 0x418A00B0); /* Number of Words that can be written to FIFO */
PROVIDE(AX5043_FIFOFREE1             = 0x418200B0); /* Number of Words that can be written to FIFO 1 */
PROVIDE(AX5043_FIFOFREE0             = 0x418200B4); /* Number of Words that can be written to FIFO 0 */
PROVIDE(AX5043_FIFOTHRESH            = 0x418A00B8); /* FIFO Threshold */
PROVIDE(AX5043_FIFOTHRESH1           = 0x418200B8); /* FIFO Threshold 1 */
PROVIDE(AX5043_FIFOTHRESH0           = 0x418200BC); /* FIFO Threshold 0 */
PROVIDE(AX5043_PLLLOOP               = 0x418200C0); /* PLL Loop Filter Settings */
PROVIDE(AX5043_PLLCPI                = 0x418200C4); /* PLL Charge Pump Current */
PROVIDE(AX5043_PLLVCODIV             = 0x418200C8); /* PLL Divider Settings */
PROVIDE(AX5043_PLLRANGINGA           = 0x418200CC); /* PLL Autoranging A */
PROVIDE(AX5043_FREQA                 = 0x419A00D0); /* Frequency A */
PROVIDE(AX5043_FREQA3                = 0x418200D0); /* Frequency A 3 */
PROVIDE(AX5043_FREQA2                = 0x418200D4); /* Frequency A 2 */
PROVIDE(AX5043_FREQA1                = 0x418200D8); /* Frequency A 1 */
PROVIDE(AX5043_FREQA0                = 0x418200DC); /* Frequency A 0 */
PROVIDE(AX5043_PLLLOOPBOOST          = 0x418200E0); /* PLL Loop Filter Settings (Boosted) */
PROVIDE(AX5043_PLLCPIBOOST           = 0x418200E4); /* PLL Charge Pump Current (Boosted) */
PROVIDE(AX5043_PLLRANGINGB           = 0x418200EC); /* PLL Autoranging B */
PROVIDE(AX5043_FREQB                 = 0x419A00F0); /* Frequency B */
PROVIDE(AX5043_FREQB3                = 0x418200F0); /* Frequency B 3 */
PROVIDE(AX5043_FREQB2                = 0x418200F4); /* Frequency B 2 */
PROVIDE(AX5043_FREQB1                = 0x418200F8); /* Frequency B 1 */
PROVIDE(AX5043_FREQB0                = 0x418200FC); /* Frequency B 0 */
PROVIDE(AX5043_RSSI                  = 0x41820100); /* Received Signal Strength Indicator */
PROVIDE(AX5043_BGNDRSSI              = 0x41820104); /* Background RSSI */
PROVIDE(AX5043_DIVERSITY             = 0x41820108); /* Antenna Diversity Configuration */
PROVIDE(AX5043_AGCCOUNTER            = 0x4182010C); /* AGC Counter */
PROVIDE(AX5043_TRKDATARATE           = 0x41920114); /* Datarate Tracking */
PROVIDE(AX5043_TRKDATARATE2          = 0x41820114); /* Datarate Tracking 2 */
PROVIDE(AX5043_TRKDATARATE1          = 0x41820118); /* Datarate Tracking 1 */
PROVIDE(AX5043_TRKDATARATE0          = 0x4182011C); /* Datarate Tracking 0 */
PROVIDE(AX5043_TRKAMPLITUDE          = 0x418A0120); /* Amplitude Tracking */
PROVIDE(AX5043_TRKAMPLITUDE1         = 0x41820120); /* Amplitude Tracking 1 */
PROVIDE(AX5043_TRKAMPLITUDE0         = 0x41820124); /* Amplitude Tracking 0 */
PROVIDE(AX5043_TRKPHASE              = 0x418A0128); /* Phase Tracking */
PROVIDE(AX5043_TRKPHASE1             = 0x41820128); /* Phase Tracking 1 */
PROVIDE(AX5043_TRKPHASE0             = 0x4182012C); /* Phase Tracking 0 */
PROVIDE(AX5043_TRKRFFREQ             = 0x41920134); /* RF Frequency Tracking */
PROVIDE(AX5043_TRKRFFREQ2            = 0x41820134); /* RF Frequency Tracking 2 */
PROVIDE(AX5043_TRKRFFREQ1            = 0x41820138); /* RF Frequency Tracking 1 */
PROVIDE(AX5043_TRKRFFREQ0            = 0x4182013C); /* RF Frequency Tracking 0 */
PROVIDE(AX5043_TRKFREQ               = 0x418A0140); /* Frequency Tracking */
PROVIDE(AX5043_TRKFREQ1              = 0x41820140); /* Frequency Tracking 1 */
PROVIDE(AX5043_TRKFREQ0              = 0x41820144); /* Frequency Tracking 0 */
PROVIDE(AX5043_TRKFSKDEMOD           = 0x418A0148); /* FSK Demodulator Tracking */
PROVIDE(AX5043_TRKFSKDEMOD1          = 0x41820148); /* FSK Demodulator Tracking 1 */
PROVIDE(AX5043_TRKFSKDEMOD0          = 0x4182014C); /* FSK Demodulator Tracking 0 */
PROVIDE(AX5043_TRKAFSKDEMOD          = 0x418A0150); /* AFSK Demodulator Tracking */
PROVIDE(AX5043_TRKAFSKDEMOD1         = 0x41820150); /* AFSK Demodulator Tracking 1 */
PROVIDE(AX5043_TRKAFSKDEMOD0         = 0x41820154); /* AFSK Demodulator Tracking 0 */
PROVIDE(AX5043_TIMER                 = 0x41920164); /* 1MHz Timer */
PROVIDE(AX5043_TIMER2                = 0x41820164); /* 1MHz Timer 2 */
PROVIDE(AX5043_TIMER1                = 0x41820168); /* 1MHz Timer 1 */
PROVIDE(AX5043_TIMER0                = 0x4182016C); /* 1MHz Timer 0 */
PROVIDE(AX5043_WAKEUPTIMER           = 0x418A01A0); /* Wakeup Timer */
PROVIDE(AX5043_WAKEUPTIMER1          = 0x418201A0); /* Wakeup Timer 1 */
PROVIDE(AX5043_WAKEUPTIMER0          = 0x418201A4); /* Wakeup Timer 0 */
PROVIDE(AX5043_WAKEUP                = 0x418A01A8); /* Wakeup Time */
PROVIDE(AX5043_WAKEUP1               = 0x418201A8); /* Wakeup Time 1 */
PROVIDE(AX5043_WAKEUP0               = 0x418201AC); /* Wakeup Time 0 */
PROVIDE(AX5043_WAKEUPFREQ            = 0x418A01B0); /* Wakeup Frequency */
PROVIDE(AX5043_WAKEUPFREQ1           = 0x418201B0); /* Wakeup Frequency 1 */
PROVIDE(AX5043_WAKEUPFREQ0           = 0x418201B4); /* Wakeup Frequency 0 */
PROVIDE(AX5043_WAKEUPXOEARLY         = 0x418201B8); /* Wakeup Crystal Oscillator Early */
PROVIDE(AX5043_IFFREQ                = 0x4189C400); /* 2nd LO / IF Frequency */
PROVIDE(AX5043_IFFREQ1               = 0x4181C400); /* 2nd LO / IF Frequency 1 */
PROVIDE(AX5043_IFFREQ0               = 0x4181C404); /* 2nd LO / IF Frequency 0 */
PROVIDE(AX5043_DECIMATION            = 0x4181C408); /* Decimation Factor */
PROVIDE(AX5043_RXDATARATE            = 0x4191C40C); /* Receiver Datarate */
PROVIDE(AX5043_RXDATARATE2           = 0x4181C40C); /* Receiver Datarate 2 */
PROVIDE(AX5043_RXDATARATE1           = 0x4181C410); /* Receiver Datarate 1 */
PROVIDE(AX5043_RXDATARATE0           = 0x4181C414); /* Receiver Datarate 0 */
PROVIDE(AX5043_MAXDROFFSET           = 0x4191C418); /* Maximum Receiver Datarate Offset */
PROVIDE(AX5043_MAXDROFFSET2          = 0x4181C418); /* Maximum Receiver Datarate Offset 2 */
PROVIDE(AX5043_MAXDROFFSET1          = 0x4181C41C); /* Maximum Receiver Datarate Offset 1 */
PROVIDE(AX5043_MAXDROFFSET0          = 0x4181C420); /* Maximum Receiver Datarate Offset 0 */
PROVIDE(AX5043_MAXRFOFFSET           = 0x4191C424); /* Maximum Receiver RF Offset */
PROVIDE(AX5043_MAXRFOFFSET2          = 0x4181C424); /* Maximum Receiver RF Offset 2 */
PROVIDE(AX5043_MAXRFOFFSET1          = 0x4181C428); /* Maximum Receiver RF Offset 1 */
PROVIDE(AX5043_MAXRFOFFSET0          = 0x4181C42C); /* Maximum Receiver RF Offset 0 */
PROVIDE(AX5043_FSKDMAX               = 0x4189C430); /* Four FSK Rx Maximum Deviation */
PROVIDE(AX5043_FSKDMAX1              = 0x4181C430); /* Four FSK Rx Maximum Deviation 1 */
PROVIDE(AX5043_FSKDMAX0              = 0x4181C434); /* Four FSK Rx Maximum Deviation 0 */
PROVIDE(AX5043_FSKDMIN               = 0x4189C438); /* Four FSK Rx Minimum Deviation */
PROVIDE(AX5043_FSKDMIN1              = 0x4181C438); /* Four FSK Rx Minimum Deviation 1 */
PROVIDE(AX5043_FSKDMIN0              = 0x4181C43C); /* Four FSK Rx Minimum Deviation 0 */
PROVIDE(AX5043_AFSKSPACE             = 0x4189C440); /* AFSK Space (0) Frequency */
PROVIDE(AX5043_AFSKSPACE1            = 0x4181C440); /* AFSK Space (0) Frequency 1 */
PROVIDE(AX5043_AFSKSPACE0            = 0x4181C444); /* AFSK Space (0) Frequency 0 */
PROVIDE(AX5043_AFSKMARK              = 0x4189C448); /* AFSK Mark (1) Frequency */
PROVIDE(AX5043_AFSKMARK1             = 0x4181C448); /* AFSK Mark (1) Frequency 1 */
PROVIDE(AX5043_AFSKMARK0             = 0x4181C44C); /* AFSK Mark (1) Frequency 0 */
PROVIDE(AX5043_AFSKCTRL              = 0x4181C450); /* AFSK Control */
PROVIDE(AX5043_AMPLFILTER            = 0x4181C454); /* Amplitude Filter */
PROVIDE(AX5043_FREQUENCYLEAK         = 0x4181C458); /* Baseband Frequency Recovery Loop Leakiness */
PROVIDE(AX5043_RXPARAMSETS           = 0x4181C45C); /* Receiver Parameter Set Indirection */
PROVIDE(AX5043_RXPARAMCURSET         = 0x4181C460); /* Receiver Parameter Current Set */
PROVIDE(AX5043_AGCGAIN0              = 0x4181C480); /* AGC Speed */
PROVIDE(AX5043_AGCTARGET0            = 0x4181C484); /* AGC Target */
PROVIDE(AX5043_AGCAHYST0             = 0x4181C488); /* AGC Analog Hysteresis */
PROVIDE(AX5043_AGCMINMAX0            = 0x4181C48C); /* AGC Analog Update Behaviour */
PROVIDE(AX5043_TIMEGAIN0             = 0x4181C490); /* Time Estimator Bandwidth */
PROVIDE(AX5043_DRGAIN0               = 0x4181C494); /* Data Rate Estimator Bandwidth */
PROVIDE(AX5043_PHASEGAIN0            = 0x4181C498); /* Phase Estimator Bandwidth */
PROVIDE(AX5043_FREQUENCYGAINA0       = 0x4181C49C); /* Frequency Estimator Bandwidth A */
PROVIDE(AX5043_FREQUENCYGAINB0       = 0x4181C4A0); /* Frequency Estimator Bandwidth B */
PROVIDE(AX5043_FREQUENCYGAINC0       = 0x4181C4A4); /* Frequency Estimator Bandwidth C */
PROVIDE(AX5043_FREQUENCYGAIND0       = 0x4181C4A8); /* Frequency Estimator Bandwidth D */
PROVIDE(AX5043_AMPLITUDEGAIN0        = 0x4181C4AC); /* Amplitude Estimator Bandwidth */
PROVIDE(AX5043_FREQDEV10             = 0x4181C4B0); /* Receiver Frequency Deviation 1 */
PROVIDE(AX5043_FREQDEV00             = 0x4181C4B4); /* Receiver Frequency Deviation 0 */
PROVIDE(AX5043_FOURFSK0              = 0x4181C4B8); /* Four FSK Control */
PROVIDE(AX5043_BBOFFSRES0            = 0x4181C4BC); /* Baseband Offset Compensation Resistors */
PROVIDE(AX5043_AGCGAIN1              = 0x4181C4C0); /* AGC Speed */
PROVIDE(AX5043_AGCTARGET1            = 0x4181C4C4); /* AGC Target */
PROVIDE(AX5043_AGCAHYST1             = 0x4181C4C8); /* AGC Analog Hysteresis */
PROVIDE(AX5043_AGCMINMAX1            = 0x4181C4CC); /* AGC Analog Update Behaviour */
PROVIDE(AX5043_TIMEGAIN1             = 0x4181C4D0); /* Time Estimator Bandwidth */
PROVIDE(AX5043_DRGAIN1               = 0x4181C4D4); /* Data Rate Estimator Bandwidth */
PROVIDE(AX5043_PHASEGAIN1            = 0x4181C4D8); /* Phase Estimator Bandwidth */
PROVIDE(AX5043_FREQUENCYGAINA1       = 0x4181C4DC); /* Frequency Estimator Bandwidth A */
PROVIDE(AX5043_FREQUENCYGAINB1       = 0x4181C4E0); /* Frequency Estimator Bandwidth B */
PROVIDE(AX5043_FREQUENCYGAINC1       = 0x4181C4E4); /* Frequency Estimator Bandwidth C */
PROVIDE(AX5043_FREQUENCYGAIND1       = 0x4181C4E8); /* Frequency Estimator Bandwidth D */
PROVIDE(AX5043_AMPLITUDEGAIN1        = 0x4181C4EC); /* Amplitude Estimator Bandwidth */
PROVIDE(AX5043_FREQDEV11             = 0x4181C4F0); /* Receiver Frequency Deviation 1 */
PROVIDE(AX5043_FREQDEV01             = 0x4181C4F4); /* Receiver Frequency Deviation 0 */
PROVIDE(AX5043_FOURFSK1              = 0x4181C4F8); /* Four FSK Control */
PROVIDE(AX5043_BBOFFSRES1            = 0x4181C4FC); /* Baseband Offset Compensation Resistors */
PROVIDE(AX5043_AGCGAIN2              = 0x4181C500); /* AGC Speed */
PROVIDE(AX5043_AGCTARGET2            = 0x4181C504); /* AGC Target */
PROVIDE(AX5043_AGCAHYST2             = 0x4181C508); /* AGC Analog Hysteresis */
PROVIDE(AX5043_AGCMINMAX2            = 0x4181C50C); /* AGC Analog Update Behaviour */
PROVIDE(AX5043_TIMEGAIN2             = 0x4181C510); /* Time Estimator Bandwidth */
PROVIDE(AX5043_DRGAIN2               = 0x4181C514); /* Data Rate Estimator Bandwidth */
PROVIDE(AX5043_PHASEGAIN2            = 0x4181C518); /* Phase Estimator Bandwidth */
PROVIDE(AX5043_FREQUENCYGAINA2       = 0x4181C51C); /* Frequency Estimator Bandwidth A */
PROVIDE(AX5043_FREQUENCYGAINB2       = 0x4181C520); /* Frequency Estimator Bandwidth B */
PROVIDE(AX5043_FREQUENCYGAINC2       = 0x4181C524); /* Frequency Estimator Bandwidth C */
PROVIDE(AX5043_FREQUENCYGAIND2       = 0x4181C528); /* Frequency Estimator Bandwidth D */
PROVIDE(AX5043_AMPLITUDEGAIN2        = 0x4181C52C); /* Amplitude Estimator Bandwidth */
PROVIDE(AX5043_FREQDEV12             = 0x4181C530); /* Receiver Frequency Deviation 1 */
PROVIDE(AX5043_FREQDEV02             = 0x4181C534); /* Receiver Frequency Deviation 0 */
PROVIDE(AX5043_FOURFSK2              = 0x4181C538); /* Four FSK Control */
PROVIDE(AX5043_BBOFFSRES2            = 0x4181C53C); /* Baseband Offset Compensation Resistors */
PROVIDE(AX5043_AGCGAIN3              = 0x4181C540); /* AGC Speed */
PROVIDE(AX5043_AGCTARGET3            = 0x4181C544); /* AGC Target */
PROVIDE(AX5043_AGCAHYST3             = 0x4181C548); /* AGC Analog Hysteresis */
PROVIDE(AX5043_AGCMINMAX3            = 0x4181C54C); /* AGC Analog Update Behaviour */
PROVIDE(AX5043_TIMEGAIN3             = 0x4181C550); /* Time Estimator Bandwidth */
PROVIDE(AX5043_DRGAIN3               = 0x4181C554); /* Data Rate Estimator Bandwidth */
PROVIDE(AX5043_PHASEGAIN3            = 0x4181C558); /* Phase Estimator Bandwidth */
PROVIDE(AX5043_FREQUENCYGAINA3       = 0x4181C55C); /* Frequency Estimator Bandwidth A */
PROVIDE(AX5043_FREQUENCYGAINB3       = 0x4181C560); /* Frequency Estimator Bandwidth B */
PROVIDE(AX5043_FREQUENCYGAINC3       = 0x4181C564); /* Frequency Estimator Bandwidth C */
PROVIDE(AX5043_FREQUENCYGAIND3       = 0x4181C568); /* Frequency Estimator Bandwidth D */
PROVIDE(AX5043_AMPLITUDEGAIN3        = 0x4181C56C); /* Amplitude Estimator Bandwidth */
PROVIDE(AX5043_FREQDEV13             = 0x4181C570); /* Receiver Frequency Deviation 1 */
PROVIDE(AX5043_FREQDEV03             = 0x4181C574); /* Receiver Frequency Deviation 0 */
PROVIDE(AX5043_FOURFSK3              = 0x4181C578); /* Four FSK Control */
PROVIDE(AX5043_BBOFFSRES3            = 0x4181C57C); /* Baseband Offset Compensation Resistors */
PROVIDE(AX5043_MODCFGF               = 0x4181C580); /* Modulator Configuration F */
PROVIDE(AX5043_FSKDEV                = 0x4191C584); /* FSK Deviation */
PROVIDE(AX5043_FSKDEV2               = 0x4181C584); /* FSK Deviation 2 */
PROVIDE(AX5043_FSKDEV1               = 0x4181C588); /* FSK Deviation 1 */
PROVIDE(AX5043_FSKDEV0               = 0x4181C58C); /* FSK Deviation 0 */
PROVIDE(AX5043_MODCFGA               = 0x4181C590); /* Modulator Configuration A */
PROVIDE(AX5043_TXRATE                = 0x4191C594); /* Transmitter Bitrate */
PROVIDE(AX5043_TXRATE2               = 0x4181C594); /* Transmitter Bitrate 2 */
PROVIDE(AX5043_TXRATE1               = 0x4181C598); /* Transmitter Bitrate 1 */
PROVIDE(AX5043_TXRATE0               = 0x4181C59C); /* Transmitter Bitrate 0 */
PROVIDE(AX5043_TXPWRCOEFFA           = 0x4189C5A0); /* Transmitter Predistortion Coefficient A */
PROVIDE(AX5043_TXPWRCOEFFA1          = 0x4181C5A0); /* Transmitter Predistortion Coefficient A 1 */
PROVIDE(AX5043_TXPWRCOEFFA0          = 0x4181C5A4); /* Transmitter Predistortion Coefficient A 0 */
PROVIDE(AX5043_TXPWRCOEFFB           = 0x4189C5A8); /* Transmitter Predistortion Coefficient B */
PROVIDE(AX5043_TXPWRCOEFFB1          = 0x4181C5A8); /* Transmitter Predistortion Coefficient B 1 */
PROVIDE(AX5043_TXPWRCOEFFB0          = 0x4181C5AC); /* Transmitter Predistortion Coefficient B 0 */
PROVIDE(AX5043_TXPWRCOEFFC           = 0x4189C5B0); /* Transmitter Predistortion Coefficient C */
PROVIDE(AX5043_TXPWRCOEFFC1          = 0x4181C5B0); /* Transmitter Predistortion Coefficient C 1 */
PROVIDE(AX5043_TXPWRCOEFFC0          = 0x4181C5B4); /* Transmitter Predistortion Coefficient C 0 */
PROVIDE(AX5043_TXPWRCOEFFD           = 0x4189C5B8); /* Transmitter Predistortion Coefficient D */
PROVIDE(AX5043_TXPWRCOEFFD1          = 0x4181C5B8); /* Transmitter Predistortion Coefficient D 1 */
PROVIDE(AX5043_TXPWRCOEFFD0          = 0x4181C5BC); /* Transmitter Predistortion Coefficient D 0 */
PROVIDE(AX5043_TXPWRCOEFFE           = 0x4189C5C0); /* Transmitter Predistortion Coefficient E */
PROVIDE(AX5043_TXPWRCOEFFE1          = 0x4181C5C0); /* Transmitter Predistortion Coefficient E 1 */
PROVIDE(AX5043_TXPWRCOEFFE0          = 0x4181C5C4); /* Transmitter Predistortion Coefficient E 0 */
PROVIDE(AX5043_PLLVCOI               = 0x4181C600); /* PLL VCO Current */
PROVIDE(AX5043_PLLVCOIR              = 0x4181C604); /* PLL VCO Current Readback */
PROVIDE(AX5043_PLLLOCKDET            = 0x4181C608); /* PLL Lock Detect Delay */
PROVIDE(AX5043_PLLRNGCLK             = 0x4181C60C); /* PLL Autoranging Clock */
PROVIDE(AX5043_XTALCAP               = 0x4181C610); /* Crystal Oscillator Load Capacitance */
PROVIDE(AX5043_BBTUNE                = 0x4181C620); /* Baseband Tuning */
PROVIDE(AX5043_BBOFFSCAP             = 0x4181C624); /* Baseband Offset Compensation Capacitors */
PROVIDE(AX5043_PKTADDRCFG            = 0x4181C800); /* Packet Address Config */
PROVIDE(AX5043_PKTLENCFG             = 0x4181C804); /* Packet Length Configuration */
PROVIDE(AX5043_PKTLENOFFSET          = 0x4181C808); /* Packet Length Offset */
PROVIDE(AX5043_PKTMAXLEN             = 0x4181C80C); /* Packet Maximum Length */
PROVIDE(AX5043_PKTADDR               = 0x4199C810); /* Packet Address */
PROVIDE(AX5043_PKTADDR3              = 0x4181C810); /* Packet Address 3 */
PROVIDE(AX5043_PKTADDR2              = 0x4181C814); /* Packet Address 2 */
PROVIDE(AX5043_PKTADDR1              = 0x4181C818); /* Packet Address 1 */
PROVIDE(AX5043_PKTADDR0              = 0x4181C81C); /* Packet Address 0 */
PROVIDE(AX5043_PKTADDRMASK           = 0x4199C820); /* Packet Address Mask */
PROVIDE(AX5043_PKTADDRMASK3          = 0x4181C820); /* Packet Address Mask 3 */
PROVIDE(AX5043_PKTADDRMASK2          = 0x4181C824); /* Packet Address Mask 2 */
PROVIDE(AX5043_PKTADDRMASK1          = 0x4181C828); /* Packet Address Mask 1 */
PROVIDE(AX5043_PKTADDRMASK0          = 0x4181C82C); /* Packet Address Mask 0 */
PROVIDE(AX5043_MATCH0PAT             = 0x4199C840); /* Pattern Match Unit 0, Pattern */
PROVIDE(AX5043_MATCH0PAT3            = 0x4181C840); /* Pattern Match Unit 0, Pattern 3 */
PROVIDE(AX5043_MATCH0PAT2            = 0x4181C844); /* Pattern Match Unit 0, Pattern 2 */
PROVIDE(AX5043_MATCH0PAT1            = 0x4181C848); /* Pattern Match Unit 0, Pattern 1 */
PROVIDE(AX5043_MATCH0PAT0            = 0x4181C84C); /* Pattern Match Unit 0, Pattern 0 */
PROVIDE(AX5043_MATCH0LEN             = 0x4181C850); /* Pattern Match Unit 0, Pattern Length */
PROVIDE(AX5043_MATCH0MIN             = 0x4181C854); /* Pattern Match Unit 0, Minimum Match */
PROVIDE(AX5043_MATCH0MAX             = 0x4181C858); /* Pattern Match Unit 0, Maximum Match */
PROVIDE(AX5043_MATCH1PAT             = 0x4189C860); /* Pattern Match Unit 1, Pattern */
PROVIDE(AX5043_MATCH1PAT1            = 0x4181C860); /* Pattern Match Unit 1, Pattern 1 */
PROVIDE(AX5043_MATCH1PAT0            = 0x4181C864); /* Pattern Match Unit 1, Pattern 0 */
PROVIDE(AX5043_MATCH1LEN             = 0x4181C870); /* Pattern Match Unit 1, Pattern Length */
PROVIDE(AX5043_MATCH1MIN             = 0x4181C874); /* Pattern Match Unit 1, Minimum Match */
PROVIDE(AX5043_MATCH1MAX             = 0x4181C878); /* Pattern Match Unit 1, Maximum Match */
PROVIDE(AX5043_TMGTXBOOST            = 0x4181C880); /* Transmit PLL Boost Time */
PROVIDE(AX5043_TMGTXSETTLE           = 0x4181C884); /* Transmit PLL (post Boost) Settling Time */
PROVIDE(AX5043_TMGRXBOOST            = 0x4181C88C); /* Receive PLL Boost Time */
PROVIDE(AX5043_TMGRXSETTLE           = 0x4181C890); /* Receive PLL (post Boost) Settling Time */
PROVIDE(AX5043_TMGRXOFFSACQ          = 0x4181C894); /* Receive Baseband DC Offset Acquisition Time */
PROVIDE(AX5043_TMGRXCOARSEAGC        = 0x4181C898); /* Receive Coarse AGC Time */
PROVIDE(AX5043_TMGRXAGC              = 0x4181C89C); /* Receiver AGC Settling Time */
PROVIDE(AX5043_TMGRXRSSI             = 0x4181C8A0); /* Receiver RSSI Settling Time */
PROVIDE(AX5043_TMGRXPREAMBLE1        = 0x4181C8A4); /* Receiver Preamble 1 Timeout */
PROVIDE(AX5043_TMGRXPREAMBLE2        = 0x4181C8A8); /* Receiver Preamble 2 Timeout */
PROVIDE(AX5043_TMGRXPREAMBLE3        = 0x4181C8AC); /* Receiver Preamble 3 Timeout */
PROVIDE(AX5043_RSSIREFERENCE         = 0x4181C8B0); /* RSSI Offset */
PROVIDE(AX5043_RSSIABSTHR            = 0x4181C8B4); /* RSSI Absolute Threshold */
PROVIDE(AX5043_BGNDRSSIGAIN          = 0x4181C8B8); /* Background RSSI Averaging Time Constant */
PROVIDE(AX5043_BGNDRSSITHR           = 0x4181C8BC); /* Background RSSI Relative Threshold */
PROVIDE(AX5043_PKTCHUNKSIZE          = 0x4181C8C0); /* Packet Chunk Size */
PROVIDE(AX5043_PKTMISCFLAGS          = 0x4181C8C4); /* Packet Controller Miscellaneous Flags */
PROVIDE(AX5043_PKTSTOREFLAGS         = 0x4181C8C8); /* Packet Controller Store Flags */
PROVIDE(AX5043_PKTACCEPTFLAGS        = 0x4181C8CC); /* Packet Controller Accept Flags */
PROVIDE(AX5043_GPADCCTRL             = 0x4181CC00); /* General Purpose ADC Control */
PROVIDE(AX5043_GPADCPERIOD           = 0x4181CC04); /* GPADC Sampling Period */
PROVIDE(AX5043_GPADC13VALUE          = 0x4189CC20); /* GPADC13 Value */
PROVIDE(AX5043_GPADC13VALUE1         = 0x4181CC20); /* GPADC13 Value 1 */
PROVIDE(AX5043_GPADC13VALUE0         = 0x4181CC24); /* GPADC13 Value 0 */
PROVIDE(AX5043_LPOSCCONFIG           = 0x4181CC40); /* Low Power Oscillator Calibration Configuration */
PROVIDE(AX5043_LPOSCSTATUS           = 0x4181CC44); /* Low Power Oscillator Calibration Status */
PROVIDE(AX5043_LPOSCKFILT            = 0x4189CC48);
PROVIDE(AX5043_LPOSCKFILT1           = 0x4181CC48); /* Low Power Oscillator Calibration Filter Constant High Byte */
PROVIDE(AX5043_LPOSCKFILT0           = 0x4181CC4C); /* Low Power Oscillator Calibration Filter Constant Low Byte */
PROVIDE(AX5043_LPOSCREF              = 0x4189CC50);
PROVIDE(AX5043_LPOSCREF1             = 0x4181CC50); /* Low Power Oscillator Reference Frequency High Byte */
PROVIDE(AX5043_LPOSCREF0             = 0x4181CC54); /* Low Power Oscillator Reference Frequency Low Byte */
PROVIDE(AX5043_LPOSCFREQ             = 0x4189CC58);
PROVIDE(AX5043_LPOSCFREQ1            = 0x4181CC58); /* Low Power Oscillator Frequency Tuning High Byte */
PROVIDE(AX5043_LPOSCFREQ0            = 0x4181CC5C); /* Low Power Oscillator Frequency Tuning Low Byte */
PROVIDE(AX5043_LPOSCPER              = 0x4189CC60);
PROVIDE(AX5043_LPOSCPER1             = 0x4181CC60); /* Low Power Oscillator Period High Byte */
PROVIDE(AX5043_LPOSCPER0             = 0x4181CC64); /* Low Power Oscillator Period Low Byte */
PROVIDE(AX5043_DACVALUE              = 0x4189CCC0); /* DAC Value */
PROVIDE(AX5043_DACVALUE1             = 0x4181CCC0); /* DAC Value 1 */
PROVIDE(AX5043_DACVALUE0             = 0x4181CCC4); /* DAC Value 0 */
PROVIDE(AX5043_DACCONFIG             = 0x4181CCC8); /* DAC Configuration */
PROVIDE(AX5043_POWCTRL1              = 0x4181FC20); /* Power Control 1 */
PROVIDE(AX5043_REF                   = 0x4181FC34); /* Reference */
PROVIDE(AX5043_XTALOSC               = 0x4181FC40); /* Crystal Oscillator Control */
PROVIDE(AX5043_XTALAMPL              = 0x4181FC44); /* Crystal Oscillator Amplitude Control */
PROVIDE(AX5043_SILICONREVISIONNB     = 0x41860000); /* Silicon Revision, non-blocking */
PROVIDE(AX5043_SCRATCHNB             = 0x41860004); /* Scratch, non-blocking */
PROVIDE(AX5043_PWRMODENB             = 0x41860008); /* Power Mode, non-blocking */
PROVIDE(AX5043_POWSTATNB             = 0x4186000C); /* Power Management Status, non-blocking */
PROVIDE(AX5043_POWSTICKYSTATNB       = 0x41860010); /* Power Management Sticky Status, non-blocking */
PROVIDE(AX5043_POWIRQMASKNB          = 0x41860014); /* Power Management Interrupt Mask, non-blocking */
PROVIDE(AX5043_IRQMASKNB             = 0x418E0018); /* IRQ Mask, non-blocking */
PROVIDE(AX5043_IRQMASK1NB            = 0x41860018); /* IRQ Mask 1, non-blocking */
PROVIDE(AX5043_IRQMASK0NB            = 0x4186001C); /* IRQ Mask 0, non-blocking */
PROVIDE(AX5043_RADIOEVENTMASKNB      = 0x418E0020); /* Radio Event Mask, non-blocking */
PROVIDE(AX5043_RADIOEVENTMASK1NB     = 0x41860020); /* Radio Event Mask 1, non-blocking */
PROVIDE(AX5043_RADIOEVENTMASK0NB     = 0x41860024); /* Radio Event Mask 0, non-blocking */
PROVIDE(AX5043_IRQINVERSIONNB        = 0x418E0028); /* IRQ Inversion, non-blocking */
PROVIDE(AX5043_IRQINVERSION1NB       = 0x41860028); /* IRQ Inversion 1, non-blocking */
PROVIDE(AX5043_IRQINVERSION0NB       = 0x4186002C); /* IRQ Inversion 0, non-blocking */
PROVIDE(AX5043_IRQREQUESTNB          = 0x418E0030); /* IRQ Request, non-blocking */
PROVIDE(AX5043_IRQREQUEST1NB         = 0x41860030); /* IRQ Request 1, non-blocking */
PROVIDE(AX5043_IRQREQUEST0NB         = 0x41860034); /* IRQ Request 0, non-blocking */
PROVIDE(AX5043_RADIOEVENTREQNB       = 0x418E0038); /* Radio Event Request, non-blocking */
PROVIDE(AX5043_RADIOEVENTREQ1NB      = 0x41860038); /* Radio Event Request 1, non-blocking */
PROVIDE(AX5043_RADIOEVENTREQ0NB      = 0x4186003C); /* Radio Event Request 0, non-blocking */
PROVIDE(AX5043_MODULATIONNB          = 0x41860040); /* Modulation, non-blocking */
PROVIDE(AX5043_ENCODINGNB            = 0x41860044); /* Encoding, non-blocking */
PROVIDE(AX5043_FRAMINGNB             = 0x41860048); /* Framing Mode, non-blocking */
PROVIDE(AX5043_CRCINITNB             = 0x419E0050); /* CRC Initial Value, non-blocking */
PROVIDE(AX5043_CRCINIT3NB            = 0x41860050); /* CRC Initial Value 3, non-blocking */
PROVIDE(AX5043_CRCINIT2NB            = 0x41860054); /* CRC Initial Value 2, non-blocking */
PROVIDE(AX5043_CRCINIT1NB            = 0x41860058); /* CRC Initial Value 1, non-blocking */
PROVIDE(AX5043_CRCINIT0NB            = 0x4186005C); /* CRC Initial Value 0, non-blocking */
PROVIDE(AX5043_FECNB                 = 0x41860060); /* Forward Error Correction, non-blocking */
PROVIDE(AX5043_FECSYNCNB             = 0x41860064); /* Forward Error Correction Sync Threshold, non-blocking */
PROVIDE(AX5043_FECSTATUSNB           = 0x41860068); /* Forward Error Correction Status, non-blocking */
PROVIDE(AX5043_RADIOSTATENB          = 0x41860070); /* Radio Controller State, non-blocking */
PROVIDE(AX5043_XTALSTATUSNB          = 0x41860074); /* Crystal Oscillator Status, non-blocking */
PROVIDE(AX5043_PINSTATENB            = 0x41860080); /* Pin State, non-blocking */
PROVIDE(AX5043_PINFUNCSYSCLKNB       = 0x41860084); /* Pin Function SYSCLK, non-blocking */
PROVIDE(AX5043_PINFUNCDCLKNB         = 0x41860088); /* Pin Function DCLK, non-blocking */
PROVIDE(AX5043_PINFUNCDATANB         = 0x4186008C); /* Pin Function DATA, non-blocking */
PROVIDE(AX5043_PINFUNCIRQNB          = 0x41860090); /* Pin Function IRQ, non-blocking */
PROVIDE(AX5043_PINFUNCANTSELNB       = 0x41860094); /* Pin Function ANTSEL, non-blocking */
PROVIDE(AX5043_PINFUNCPWRAMPNB       = 0x41860098); /* Pin Function PWRAMP, non-blocking */
PROVIDE(AX5043_PWRAMPNB              = 0x4186009C); /* PWRAMP Control, non-blocking */
PROVIDE(AX5043_FIFOSTATNB            = 0x418600A0); /* FIFO Control, non-blocking */
PROVIDE(AX5043_FIFODATANB            = 0x418600A4); /* FIFO Data, non-blocking */
PROVIDE(AX5043_FIFOCOUNTNB           = 0x418E00A8); /* Number of Words currently in FIFO, non-blocking */
PROVIDE(AX5043_FIFOCOUNT1NB          = 0x418600A8); /* Number of Words currently in FIFO 1, non-blocking */
PROVIDE(AX5043_FIFOCOUNT0NB          = 0x418600AC); /* Number of Words currently in FIFO 0, non-blocking */
PROVIDE(AX5043_FIFOFREENB            = 0x418E00B0); /* Number of Words that can be written to FIFO, non-blocking */
PROVIDE(AX5043_FIFOFREE1NB           = 0x418600B0); /* Number of Words that can be written to FIFO 1, non-blocking */
PROVIDE(AX5043_FIFOFREE0NB           = 0x418600B4); /* Number of Words that can be written to FIFO 0, non-blocking */
PROVIDE(AX5043_FIFOTHRESHNB          = 0x418E00B8); /* FIFO Threshold, non-blocking */
PROVIDE(AX5043_FIFOTHRESH1NB         = 0x418600B8); /* FIFO Threshold 1, non-blocking */
PROVIDE(AX5043_FIFOTHRESH0NB         = 0x418600BC); /* FIFO Threshold 0, non-blocking */
PROVIDE(AX5043_PLLLOOPNB             = 0x418600C0); /* PLL Loop Filter Settings, non-blocking */
PROVIDE(AX5043_PLLCPINB              = 0x418600C4); /* PLL Charge Pump Current, non-blocking */
PROVIDE(AX5043_PLLVCODIVNB           = 0x418600C8); /* PLL Divider Settings, non-blocking */
PROVIDE(AX5043_PLLRANGINGANB         = 0x418600CC); /* PLL Autoranging A, non-blocking */
PROVIDE(AX5043_FREQANB               = 0x419E00D0); /* Frequency A, non-blocking */
PROVIDE(AX5043_FREQA3NB              = 0x418600D0); /* Frequency A 3, non-blocking */
PROVIDE(AX5043_FREQA2NB              = 0x418600D4); /* Frequency A 2, non-blocking */
PROVIDE(AX5043_FREQA1NB              = 0x418600D8); /* Frequency A 1, non-blocking */
PROVIDE(AX5043_FREQA0NB              = 0x418600DC); /* Frequency A 0, non-blocking */
PROVIDE(AX5043_PLLLOOPBOOSTNB        = 0x418600E0); /* PLL Loop Filter Settings (Boosted), non-blocking */
PROVIDE(AX5043_PLLCPIBOOSTNB         = 0x418600E4); /* PLL Charge Pump Current (Boosted), non-blocking */
PROVIDE(AX5043_PLLRANGINGBNB         = 0x418600EC); /* PLL Autoranging B, non-blocking */
PROVIDE(AX5043_FREQBNB               = 0x419E00F0); /* Frequency B, non-blocking */
PROVIDE(AX5043_FREQB3NB              = 0x418600F0); /* Frequency B 3, non-blocking */
PROVIDE(AX5043_FREQB2NB              = 0x418600F4); /* Frequency B 2, non-blocking */
PROVIDE(AX5043_FREQB1NB              = 0x418600F8); /* Frequency B 1, non-blocking */
PROVIDE(AX5043_FREQB0NB              = 0x418600FC); /* Frequency B 0, non-blocking */
PROVIDE(AX5043_RSSINB                = 0x41860100); /* Received Signal Strength Indicator, non-blocking */
PROVIDE(AX5043_BGNDRSSINB            = 0x41860104); /* Background RSSI, non-blocking */
PROVIDE(AX5043_DIVERSITYNB           = 0x41860108); /* Antenna Diversity Configuration, non-blocking */
PROVIDE(AX5043_AGCCOUNTERNB          = 0x4186010C); /* AGC Counter, non-blocking */
PROVIDE(AX5043_TRKDATARATENB         = 0x41960114); /* Datarate Tracking, non-blocking */
PROVIDE(AX5043_TRKDATARATE2NB        = 0x41860114); /* Datarate Tracking 2, non-blocking */
PROVIDE(AX5043_TRKDATARATE1NB        = 0x41860118); /* Datarate Tracking 1, non-blocking */
PROVIDE(AX5043_TRKDATARATE0NB        = 0x4186011C); /* Datarate Tracking 0, non-blocking */
PROVIDE(AX5043_TRKAMPLITUDENB        = 0x418E0120); /* Amplitude Tracking, non-blocking */
PROVIDE(AX5043_TRKAMPLITUDE1NB       = 0x41860120); /* Amplitude Tracking 1, non-blocking */
PROVIDE(AX5043_TRKAMPLITUDE0NB       = 0x41860124); /* Amplitude Tracking 0, non-blocking */
PROVIDE(AX5043_TRKPHASENB            = 0x418E0128); /* Phase Tracking, non-blocking */
PROVIDE(AX5043_TRKPHASE1NB           = 0x41860128); /* Phase Tracking 1, non-blocking */
PROVIDE(AX5043_TRKPHASE0NB           = 0x4186012C); /* Phase Tracking 0, non-blocking */
PROVIDE(AX5043_TRKRFFREQNB           = 0x41960134); /* RF Frequency Tracking, non-blocking */
PROVIDE(AX5043_TRKRFFREQ2NB          = 0x41860134); /* RF Frequency Tracking 2, non-blocking */
PROVIDE(AX5043_TRKRFFREQ1NB          = 0x41860138); /* RF Frequency Tracking 1, non-blocking */
PROVIDE(AX5043_TRKRFFREQ0NB          = 0x4186013C); /* RF Frequency Tracking 0, non-blocking */
PROVIDE(AX5043_TRKFREQNB             = 0x418E0140); /* Frequency Tracking, non-blocking */
PROVIDE(AX5043_TRKFREQ1NB            = 0x41860140); /* Frequency Tracking 1, non-blocking */
PROVIDE(AX5043_TRKFREQ0NB            = 0x41860144); /* Frequency Tracking 0, non-blocking */
PROVIDE(AX5043_TRKFSKDEMODNB         = 0x418E0148); /* FSK Demodulator Tracking, non-blocking */
PROVIDE(AX5043_TRKFSKDEMOD1NB        = 0x41860148); /* FSK Demodulator Tracking 1, non-blocking */
PROVIDE(AX5043_TRKFSKDEMOD0NB        = 0x4186014C); /* FSK Demodulator Tracking 0, non-blocking */
PROVIDE(AX5043_TRKAFSKDEMODNB        = 0x418E0150); /* AFSK Demodulator Tracking, non-blocking */
PROVIDE(AX5043_TRKAFSKDEMOD1NB       = 0x41860150); /* AFSK Demodulator Tracking 1, non-blocking */
PROVIDE(AX5043_TRKAFSKDEMOD0NB       = 0x41860154); /* AFSK Demodulator Tracking 0, non-blocking */
PROVIDE(AX5043_TIMERNB               = 0x41960164); /* 1MHz Timer, non-blocking */
PROVIDE(AX5043_TIMER2NB              = 0x41860164); /* 1MHz Timer 2, non-blocking */
PROVIDE(AX5043_TIMER1NB              = 0x41860168); /* 1MHz Timer 1, non-blocking */
PROVIDE(AX5043_TIMER0NB              = 0x4186016C); /* 1MHz Timer 0, non-blocking */
PROVIDE(AX5043_WAKEUPTIMERNB         = 0x418E01A0); /* Wakeup Timer, non-blocking */
PROVIDE(AX5043_WAKEUPTIMER1NB        = 0x418601A0); /* Wakeup Timer 1, non-blocking */
PROVIDE(AX5043_WAKEUPTIMER0NB        = 0x418601A4); /* Wakeup Timer 0, non-blocking */
PROVIDE(AX5043_WAKEUPNB              = 0x418E01A8); /* Wakeup Time, non-blocking */
PROVIDE(AX5043_WAKEUP1NB             = 0x418601A8); /* Wakeup Time 1, non-blocking */
PROVIDE(AX5043_WAKEUP0NB             = 0x418601AC); /* Wakeup Time 0, non-blocking */
PROVIDE(AX5043_WAKEUPFREQNB          = 0x418E01B0); /* Wakeup Frequency, non-blocking */
PROVIDE(AX5043_WAKEUPFREQ1NB         = 0x418601B0); /* Wakeup Frequency 1, non-blocking */
PROVIDE(AX5043_WAKEUPFREQ0NB         = 0x418601B4); /* Wakeup Frequency 0, non-blocking */
PROVIDE(AX5043_WAKEUPXOEARLYNB       = 0x418601B8); /* Wakeup Crystal Oscillator Early, non-blocking */
PROVIDE(AX5043_IFFREQNB              = 0x418DC400); /* 2nd LO / IF Frequency, non-blocking */
PROVIDE(AX5043_IFFREQ1NB             = 0x4185C400); /* 2nd LO / IF Frequency 1, non-blocking */
PROVIDE(AX5043_IFFREQ0NB             = 0x4185C404); /* 2nd LO / IF Frequency 0, non-blocking */
PROVIDE(AX5043_DECIMATIONNB          = 0x4185C408); /* Decimation Factor, non-blocking */
PROVIDE(AX5043_RXDATARATENB          = 0x4195C40C); /* Receiver Datarate, non-blocking */
PROVIDE(AX5043_RXDATARATE2NB         = 0x4185C40C); /* Receiver Datarate 2, non-blocking */
PROVIDE(AX5043_RXDATARATE1NB         = 0x4185C410); /* Receiver Datarate 1, non-blocking */
PROVIDE(AX5043_RXDATARATE0NB         = 0x4185C414); /* Receiver Datarate 0, non-blocking */
PROVIDE(AX5043_MAXDROFFSETNB         = 0x4195C418); /* Maximum Receiver Datarate Offset, non-blocking */
PROVIDE(AX5043_MAXDROFFSET2NB        = 0x4185C418); /* Maximum Receiver Datarate Offset 2, non-blocking */
PROVIDE(AX5043_MAXDROFFSET1NB        = 0x4185C41C); /* Maximum Receiver Datarate Offset 1, non-blocking */
PROVIDE(AX5043_MAXDROFFSET0NB        = 0x4185C420); /* Maximum Receiver Datarate Offset 0, non-blocking */
PROVIDE(AX5043_MAXRFOFFSETNB         = 0x4195C424); /* Maximum Receiver RF Offset, non-blocking */
PROVIDE(AX5043_MAXRFOFFSET2NB        = 0x4185C424); /* Maximum Receiver RF Offset 2, non-blocking */
PROVIDE(AX5043_MAXRFOFFSET1NB        = 0x4185C428); /* Maximum Receiver RF Offset 1, non-blocking */
PROVIDE(AX5043_MAXRFOFFSET0NB        = 0x4185C42C); /* Maximum Receiver RF Offset 0, non-blocking */
PROVIDE(AX5043_FSKDMAXNB             = 0x418DC430); /* Four FSK Rx Maximum Deviation, non-blocking */
PROVIDE(AX5043_FSKDMAX1NB            = 0x4185C430); /* Four FSK Rx Maximum Deviation 1, non-blocking */
PROVIDE(AX5043_FSKDMAX0NB            = 0x4185C434); /* Four FSK Rx Maximum Deviation 0, non-blocking */
PROVIDE(AX5043_FSKDMINNB             = 0x418DC438); /* Four FSK Rx Minimum Deviation, non-blocking */
PROVIDE(AX5043_FSKDMIN1NB            = 0x4185C438); /* Four FSK Rx Minimum Deviation 1, non-blocking */
PROVIDE(AX5043_FSKDMIN0NB            = 0x4185C43C); /* Four FSK Rx Minimum Deviation 0, non-blocking */
PROVIDE(AX5043_AFSKSPACENB           = 0x418DC440); /* AFSK Space (0) Frequency, non-blocking */
PROVIDE(AX5043_AFSKSPACE1NB          = 0x4185C440); /* AFSK Space (0) Frequency 1, non-blocking */
PROVIDE(AX5043_AFSKSPACE0NB          = 0x4185C444); /* AFSK Space (0) Frequency 0, non-blocking */
PROVIDE(AX5043_AFSKMARKNB            = 0x418DC448); /* AFSK Mark (1) Frequency, non-blocking */
PROVIDE(AX5043_AFSKMARK1NB           = 0x4185C448); /* AFSK Mark (1) Frequency 1, non-blocking */
PROVIDE(AX5043_AFSKMARK0NB           = 0x4185C44C); /* AFSK Mark (1) Frequency 0, non-blocking */
PROVIDE(AX5043_AFSKCTRLNB            = 0x4185C450); /* AFSK Control, non-blocking */
PROVIDE(AX5043_AMPLFILTERNB          = 0x4185C454); /* Amplitude Filter, non-blocking */
PROVIDE(AX5043_FREQUENCYLEAKNB       = 0x4185C458); /* Baseband Frequency Recovery Loop Leakiness, non-blocking */
PROVIDE(AX5043_RXPARAMSETSNB         = 0x4185C45C); /* Receiver Parameter Set Indirection, non-blocking */
PROVIDE(AX5043_RXPARAMCURSETNB       = 0x4185C460); /* Receiver Parameter Current Set, non-blocking */
PROVIDE(AX5043_AGCGAIN0NB            = 0x4185C480); /* AGC Speed, non-blocking */
PROVIDE(AX5043_AGCTARGET0NB          = 0x4185C484); /* AGC Target, non-blocking */
PROVIDE(AX5043_AGCAHYST0NB           = 0x4185C488); /* AGC Analog Hysteresis, non-blocking */
PROVIDE(AX5043_AGCMINMAX0NB          = 0x4185C48C); /* AGC Analog Update Behaviour, non-blocking */
PROVIDE(AX5043_TIMEGAIN0NB           = 0x4185C490); /* Time Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_DRGAIN0NB             = 0x4185C494); /* Data Rate Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_PHASEGAIN0NB          = 0x4185C498); /* Phase Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINA0NB     = 0x4185C49C); /* Frequency Estimator Bandwidth A, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINB0NB     = 0x4185C4A0); /* Frequency Estimator Bandwidth B, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINC0NB     = 0x4185C4A4); /* Frequency Estimator Bandwidth C, non-blocking */
PROVIDE(AX5043_FREQUENCYGAIND0NB     = 0x4185C4A8); /* Frequency Estimator Bandwidth D, non-blocking */
PROVIDE(AX5043_AMPLITUDEGAIN0NB      = 0x4185C4AC); /* Amplitude Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_FREQDEV10NB           = 0x4185C4B0); /* Receiver Frequency Deviation 1, non-blocking */
PROVIDE(AX5043_FREQDEV00NB           = 0x4185C4B4); /* Receiver Frequency Deviation 0, non-blocking */
PROVIDE(AX5043_FOURFSK0NB            = 0x4185C4B8); /* Four FSK Control, non-blocking */
PROVIDE(AX5043_BBOFFSRES0NB          = 0x4185C4BC); /* Baseband Offset Compensation Resistors, non-blocking */
PROVIDE(AX5043_AGCGAIN1NB            = 0x4185C4C0); /* AGC Speed, non-blocking */
PROVIDE(AX5043_AGCTARGET1NB          = 0x4185C4C4); /* AGC Target, non-blocking */
PROVIDE(AX5043_AGCAHYST1NB           = 0x4185C4C8); /* AGC Analog Hysteresis, non-blocking */
PROVIDE(AX5043_AGCMINMAX1NB          = 0x4185C4CC); /* AGC Analog Update Behaviour, non-blocking */
PROVIDE(AX5043_TIMEGAIN1NB           = 0x4185C4D0); /* Time Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_DRGAIN1NB             = 0x4185C4D4); /* Data Rate Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_PHASEGAIN1NB          = 0x4185C4D8); /* Phase Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINA1NB     = 0x4185C4DC); /* Frequency Estimator Bandwidth A, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINB1NB     = 0x4185C4E0); /* Frequency Estimator Bandwidth B, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINC1NB     = 0x4185C4E4); /* Frequency Estimator Bandwidth C, non-blocking */
PROVIDE(AX5043_FREQUENCYGAIND1NB     = 0x4185C4E8); /* Frequency Estimator Bandwidth D, non-blocking */
PROVIDE(AX5043_AMPLITUDEGAIN1NB      = 0x4185C4EC); /* Amplitude Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_FREQDEV11NB           = 0x4185C4F0); /* Receiver Frequency Deviation 1, non-blocking */
PROVIDE(AX5043_FREQDEV01NB           = 0x4185C4F4); /* Receiver Frequency Deviation 0, non-blocking */
PROVIDE(AX5043_FOURFSK1NB            = 0x4185C4F8); /* Four FSK Control, non-blocking */
PROVIDE(AX5043_BBOFFSRES1NB          = 0x4185C4FC); /* Baseband Offset Compensation Resistors, non-blocking */
PROVIDE(AX5043_AGCGAIN2NB            = 0x4185C500); /* AGC Speed, non-blocking */
PROVIDE(AX5043_AGCTARGET2NB          = 0x4185C504); /* AGC Target, non-blocking */
PROVIDE(AX5043_AGCAHYST2NB           = 0x4185C508); /* AGC Analog Hysteresis, non-blocking */
PROVIDE(AX5043_AGCMINMAX2NB          = 0x4185C50C); /* AGC Analog Update Behaviour, non-blocking */
PROVIDE(AX5043_TIMEGAIN2NB           = 0x4185C510); /* Time Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_DRGAIN2NB             = 0x4185C514); /* Data Rate Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_PHASEGAIN2NB          = 0x4185C518); /* Phase Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINA2NB     = 0x4185C51C); /* Frequency Estimator Bandwidth A, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINB2NB     = 0x4185C520); /* Frequency Estimator Bandwidth B, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINC2NB     = 0x4185C524); /* Frequency Estimator Bandwidth C, non-blocking */
PROVIDE(AX5043_FREQUENCYGAIND2NB     = 0x4185C528); /* Frequency Estimator Bandwidth D, non-blocking */
PROVIDE(AX5043_AMPLITUDEGAIN2NB      = 0x4185C52C); /* Amplitude Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_FREQDEV12NB           = 0x4185C530); /* Receiver Frequency Deviation 1, non-blocking */
PROVIDE(AX5043_FREQDEV02NB           = 0x4185C534); /* Receiver Frequency Deviation 0, non-blocking */
PROVIDE(AX5043_FOURFSK2NB            = 0x4185C538); /* Four FSK Control, non-blocking */
PROVIDE(AX5043_BBOFFSRES2NB          = 0x4185C53C); /* Baseband Offset Compensation Resistors, non-blocking */
PROVIDE(AX5043_AGCGAIN3NB            = 0x4185C540); /* AGC Speed, non-blocking */
PROVIDE(AX5043_AGCTARGET3NB          = 0x4185C544); /* AGC Target, non-blocking */
PROVIDE(AX5043_AGCAHYST3NB           = 0x4185C548); /* AGC Analog Hysteresis, non-blocking */
PROVIDE(AX5043_AGCMINMAX3NB          = 0x4185C54C); /* AGC Analog Update Behaviour, non-blocking */
PROVIDE(AX5043_TIMEGAIN3NB           = 0x4185C550); /* Time Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_DRGAIN3NB             = 0x4185C554); /* Data Rate Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_PHASEGAIN3NB          = 0x4185C558); /* Phase Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINA3NB     = 0x4185C55C); /* Frequency Estimator Bandwidth A, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINB3NB     = 0x4185C560); /* Frequency Estimator Bandwidth B, non-blocking */
PROVIDE(AX5043_FREQUENCYGAINC3NB     = 0x4185C564); /* Frequency Estimator Bandwidth C, non-blocking */
PROVIDE(AX5043_FREQUENCYGAIND3NB     = 0x4185C568); /* Frequency Estimator Bandwidth D, non-blocking */
PROVIDE(AX5043_AMPLITUDEGAIN3NB      = 0x4185C56C); /* Amplitude Estimator Bandwidth, non-blocking */
PROVIDE(AX5043_FREQDEV13NB           = 0x4185C570); /* Receiver Frequency Deviation 1, non-blocking */
PROVIDE(AX5043_FREQDEV03NB           = 0x4185C574); /* Receiver Frequency Deviation 0, non-blocking */
PROVIDE(AX5043_FOURFSK3NB            = 0x4185C578); /* Four FSK Control, non-blocking */
PROVIDE(AX5043_BBOFFSRES3NB          = 0x4185C57C); /* Baseband Offset Compensation Resistors, non-blocking */
PROVIDE(AX5043_MODCFGFNB             = 0x4185C580); /* Modulator Configuration F, non-blocking */
PROVIDE(AX5043_FSKDEVNB              = 0x4195C584); /* FSK Deviation, non-blocking */
PROVIDE(AX5043_FSKDEV2NB             = 0x4185C584); /* FSK Deviation 2, non-blocking */
PROVIDE(AX5043_FSKDEV1NB             = 0x4185C588); /* FSK Deviation 1, non-blocking */
PROVIDE(AX5043_FSKDEV0NB             = 0x4185C58C); /* FSK Deviation 0, non-blocking */
PROVIDE(AX5043_MODCFGANB             = 0x4185C590); /* Modulator Configuration A, non-blocking */
PROVIDE(AX5043_TXRATENB              = 0x4195C594); /* Transmitter Bitrate, non-blocking */
PROVIDE(AX5043_TXRATE2NB             = 0x4185C594); /* Transmitter Bitrate 2, non-blocking */
PROVIDE(AX5043_TXRATE1NB             = 0x4185C598); /* Transmitter Bitrate 1, non-blocking */
PROVIDE(AX5043_TXRATE0NB             = 0x4185C59C); /* Transmitter Bitrate 0, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFANB         = 0x418DC5A0); /* Transmitter Predistortion Coefficient A, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFA1NB        = 0x4185C5A0); /* Transmitter Predistortion Coefficient A 1, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFA0NB        = 0x4185C5A4); /* Transmitter Predistortion Coefficient A 0, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFBNB         = 0x418DC5A8); /* Transmitter Predistortion Coefficient B, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFB1NB        = 0x4185C5A8); /* Transmitter Predistortion Coefficient B 1, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFB0NB        = 0x4185C5AC); /* Transmitter Predistortion Coefficient B 0, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFCNB         = 0x418DC5B0); /* Transmitter Predistortion Coefficient C, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFC1NB        = 0x4185C5B0); /* Transmitter Predistortion Coefficient C 1, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFC0NB        = 0x4185C5B4); /* Transmitter Predistortion Coefficient C 0, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFDNB         = 0x418DC5B8); /* Transmitter Predistortion Coefficient D, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFD1NB        = 0x4185C5B8); /* Transmitter Predistortion Coefficient D 1, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFD0NB        = 0x4185C5BC); /* Transmitter Predistortion Coefficient D 0, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFENB         = 0x418DC5C0); /* Transmitter Predistortion Coefficient E, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFE1NB        = 0x4185C5C0); /* Transmitter Predistortion Coefficient E 1, non-blocking */
PROVIDE(AX5043_TXPWRCOEFFE0NB        = 0x4185C5C4); /* Transmitter Predistortion Coefficient E 0, non-blocking */
PROVIDE(AX5043_PLLVCOINB             = 0x4185C600); /* PLL VCO Current, non-blocking */
PROVIDE(AX5043_PLLVCOIRNB            = 0x4185C604); /* PLL VCO Current Readback, non-blocking */
PROVIDE(AX5043_PLLLOCKDETNB          = 0x4185C608); /* PLL Lock Detect Delay, non-blocking */
PROVIDE(AX5043_PLLRNGCLKNB           = 0x4185C60C); /* PLL Autoranging Clock, non-blocking */
PROVIDE(AX5043_XTALCAPNB             = 0x4185C610); /* Crystal Oscillator Load Capacitance, non-blocking */
PROVIDE(AX5043_BBTUNENB              = 0x4185C620); /* Baseband Tuning, non-blocking */
PROVIDE(AX5043_BBOFFSCAPNB           = 0x4185C624); /* Baseband Offset Compensation Capacitors, non-blocking */
PROVIDE(AX5043_PKTADDRCFGNB          = 0x4185C800); /* Packet Address Config, non-blocking */
PROVIDE(AX5043_PKTLENCFGNB           = 0x4185C804); /* Packet Length Configuration, non-blocking */
PROVIDE(AX5043_PKTLENOFFSETNB        = 0x4185C808); /* Packet Length Offset, non-blocking */
PROVIDE(AX5043_PKTMAXLENNB           = 0x4185C80C); /* Packet Maximum Length, non-blocking */
PROVIDE(AX5043_PKTADDRNB             = 0x419DC810); /* Packet Address, non-blocking */
PROVIDE(AX5043_PKTADDR3NB            = 0x4185C810); /* Packet Address 3, non-blocking */
PROVIDE(AX5043_PKTADDR2NB            = 0x4185C814); /* Packet Address 2, non-blocking */
PROVIDE(AX5043_PKTADDR1NB            = 0x4185C818); /* Packet Address 1, non-blocking */
PROVIDE(AX5043_PKTADDR0NB            = 0x4185C81C); /* Packet Address 0, non-blocking */
PROVIDE(AX5043_PKTADDRMASKNB         = 0x419DC820); /* Packet Address Mask, non-blocking */
PROVIDE(AX5043_PKTADDRMASK3NB        = 0x4185C820); /* Packet Address Mask 3, non-blocking */
PROVIDE(AX5043_PKTADDRMASK2NB        = 0x4185C824); /* Packet Address Mask 2, non-blocking */
PROVIDE(AX5043_PKTADDRMASK1NB        = 0x4185C828); /* Packet Address Mask 1, non-blocking */
PROVIDE(AX5043_PKTADDRMASK0NB        = 0x4185C82C); /* Packet Address Mask 0, non-blocking */
PROVIDE(AX5043_MATCH0PATNB           = 0x419DC840); /* Pattern Match Unit 0, Pattern, non-blocking */
PROVIDE(AX5043_MATCH0PAT3NB          = 0x4185C840); /* Pattern Match Unit 0, Pattern 3, non-blocking */
PROVIDE(AX5043_MATCH0PAT2NB          = 0x4185C844); /* Pattern Match Unit 0, Pattern 2, non-blocking */
PROVIDE(AX5043_MATCH0PAT1NB          = 0x4185C848); /* Pattern Match Unit 0, Pattern 1, non-blocking */
PROVIDE(AX5043_MATCH0PAT0NB          = 0x4185C84C); /* Pattern Match Unit 0, Pattern 0, non-blocking */
PROVIDE(AX5043_MATCH0LENNB           = 0x4185C850); /* Pattern Match Unit 0, Pattern Length, non-blocking */
PROVIDE(AX5043_MATCH0MINNB           = 0x4185C854); /* Pattern Match Unit 0, Minimum Match, non-blocking */
PROVIDE(AX5043_MATCH0MAXNB           = 0x4185C858); /* Pattern Match Unit 0, Maximum Match, non-blocking */
PROVIDE(AX5043_MATCH1PATNB           = 0x418DC860); /* Pattern Match Unit 1, Pattern, non-blocking */
PROVIDE(AX5043_MATCH1PAT1NB          = 0x4185C860); /* Pattern Match Unit 1, Pattern 1, non-blocking */
PROVIDE(AX5043_MATCH1PAT0NB          = 0x4185C864); /* Pattern Match Unit 1, Pattern 0, non-blocking */
PROVIDE(AX5043_MATCH1LENNB           = 0x4185C870); /* Pattern Match Unit 1, Pattern Length, non-blocking */
PROVIDE(AX5043_MATCH1MINNB           = 0x4185C874); /* Pattern Match Unit 1, Minimum Match, non-blocking */
PROVIDE(AX5043_MATCH1MAXNB           = 0x4185C878); /* Pattern Match Unit 1, Maximum Match, non-blocking */
PROVIDE(AX5043_TMGTXBOOSTNB          = 0x4185C880); /* Transmit PLL Boost Time, non-blocking */
PROVIDE(AX5043_TMGTXSETTLENB         = 0x4185C884); /* Transmit PLL (post Boost) Settling Time, non-blocking */
PROVIDE(AX5043_TMGRXBOOSTNB          = 0x4185C88C); /* Receive PLL Boost Time, non-blocking */
PROVIDE(AX5043_TMGRXSETTLENB         = 0x4185C890); /* Receive PLL (post Boost) Settling Time, non-blocking */
PROVIDE(AX5043_TMGRXOFFSACQNB        = 0x4185C894); /* Receive Baseband DC Offset Acquisition Time, non-blocking */
PROVIDE(AX5043_TMGRXCOARSEAGCNB      = 0x4185C898); /* Receive Coarse AGC Time, non-blocking */
PROVIDE(AX5043_TMGRXAGCNB            = 0x4185C89C); /* Receiver AGC Settling Time, non-blocking */
PROVIDE(AX5043_TMGRXRSSINB           = 0x4185C8A0); /* Receiver RSSI Settling Time, non-blocking */
PROVIDE(AX5043_TMGRXPREAMBLE1NB      = 0x4185C8A4); /* Receiver Preamble 1 Timeout, non-blocking */
PROVIDE(AX5043_TMGRXPREAMBLE2NB      = 0x4185C8A8); /* Receiver Preamble 2 Timeout, non-blocking */
PROVIDE(AX5043_TMGRXPREAMBLE3NB      = 0x4185C8AC); /* Receiver Preamble 3 Timeout, non-blocking */
PROVIDE(AX5043_RSSIREFERENCENB       = 0x4185C8B0); /* RSSI Offset, non-blocking */
PROVIDE(AX5043_RSSIABSTHRNB          = 0x4185C8B4); /* RSSI Absolute Threshold, non-blocking */
PROVIDE(AX5043_BGNDRSSIGAINNB        = 0x4185C8B8); /* Background RSSI Averaging Time Constant, non-blocking */
PROVIDE(AX5043_BGNDRSSITHRNB         = 0x4185C8BC); /* Background RSSI Relative Threshold, non-blocking */
PROVIDE(AX5043_PKTCHUNKSIZENB        = 0x4185C8C0); /* Packet Chunk Size, non-blocking */
PROVIDE(AX5043_PKTMISCFLAGSNB        = 0x4185C8C4); /* Packet Controller Miscellaneous Flags, non-blocking */
PROVIDE(AX5043_PKTSTOREFLAGSNB       = 0x4185C8C8); /* Packet Controller Store Flags, non-blocking */
PROVIDE(AX5043_PKTACCEPTFLAGSNB      = 0x4185C8CC); /* Packet Controller Accept Flags, non-blocking */
PROVIDE(AX5043_GPADCCTRLNB           = 0x4185CC00); /* General Purpose ADC Control, non-blocking */
PROVIDE(AX5043_GPADCPERIODNB         = 0x4185CC04); /* GPADC Sampling Period, non-blocking */
PROVIDE(AX5043_GPADC13VALUENB        = 0x418DCC20); /* GPADC13 Value, non-blocking */
PROVIDE(AX5043_GPADC13VALUE1NB       = 0x4185CC20); /* GPADC13 Value 1, non-blocking */
PROVIDE(AX5043_GPADC13VALUE0NB       = 0x4185CC24); /* GPADC13 Value 0, non-blocking */
PROVIDE(AX5043_LPOSCCONFIGNB         = 0x4185CC40); /* Low Power Oscillator Calibration Configuration, non-blocking */
PROVIDE(AX5043_LPOSCSTATUSNB         = 0x4185CC44); /* Low Power Oscillator Calibration Status, non-blocking */
PROVIDE(AX5043_LPOSCKFILTNB          = 0x418DCC48);
PROVIDE(AX5043_LPOSCKFILT1NB         = 0x4185CC48); /* Low Power Oscillator Calibration Filter Constant High Byte, non-blocking */
PROVIDE(AX5043_LPOSCKFILT0NB         = 0x4185CC4C); /* Low Power Oscillator Calibration Filter Constant Low Byte, non-blocking */
PROVIDE(AX5043_LPOSCREFNB            = 0x418DCC50);
PROVIDE(AX5043_LPOSCREF1NB           = 0x4185CC50); /* Low Power Oscillator Reference Frequency High Byte, non-blocking */
PROVIDE(AX5043_LPOSCREF0NB           = 0x4185CC54); /* Low Power Oscillator Reference Frequency Low Byte, non-blocking */
PROVIDE(AX5043_LPOSCFREQNB           = 0x418DCC58);
PROVIDE(AX5043_LPOSCFREQ1NB          = 0x4185CC58); /* Low Power Oscillator Frequency Tuning High Byte, non-blocking */
PROVIDE(AX5043_LPOSCFREQ0NB          = 0x4185CC5C); /* Low Power Oscillator Frequency Tuning Low Byte, non-blocking */
PROVIDE(AX5043_LPOSCPERNB            = 0x418DCC60);
PROVIDE(AX5043_LPOSCPER1NB           = 0x4185CC60); /* Low Power Oscillator Period High Byte, non-blocking */
PROVIDE(AX5043_LPOSCPER0NB           = 0x4185CC64); /* Low Power Oscillator Period Low Byte, non-blocking */
PROVIDE(AX5043_DACVALUENB            = 0x418DCCC0); /* DAC Value, non-blocking */
PROVIDE(AX5043_DACVALUE1NB           = 0x4185CCC0); /* DAC Value 1, non-blocking */
PROVIDE(AX5043_DACVALUE0NB           = 0x4185CCC4); /* DAC Value 0, non-blocking */
PROVIDE(AX5043_DACCONFIGNB           = 0x4185CCC8); /* DAC Configuration, non-blocking */
PROVIDE(AX5043_POWCTRL1NB            = 0x4185FC20); /* Power Control 1, non-blocking */
PROVIDE(AX5043_REFNB                 = 0x4185FC34); /* Reference, non-blocking */
PROVIDE(AX5043_XTALOSCNB             = 0x4185FC40); /* Crystal Oscillator Control, non-blocking */
PROVIDE(AX5043_XTALAMPLNB            = 0x4185FC44); /* Crystal Oscillator Amplitude Control, non-blocking */

/* AX5051 */
PROVIDE(AX5051_SILICONREVISION       = 0x41820000); /* Silicon Revision */
PROVIDE(AX5051_SCRATCH               = 0x41820004); /* Scratch */
PROVIDE(AX5051_PWRMODE               = 0x41820008); /* Power Mode */
PROVIDE(AX5051_XTALOSC               = 0x4182000C); /* Crystal Oscillator Control */
PROVIDE(AX5051_FIFOCONTROL           = 0x41820010); /* FIFO Control */
PROVIDE(AX5051_FIFODATA              = 0x41820014); /* FIFO Data */
PROVIDE(AX5051_IRQMASK               = 0x41820018); /* IRQ Mask */
PROVIDE(AX5051_IRQREQUEST            = 0x4182001C); /* IRQ Request */
PROVIDE(AX5051_IFMODE                = 0x41820020); /* Interface Mode */
PROVIDE(AX5051_DSPMODE               = 0x41820024); /* DSP Mode Interface Control */
PROVIDE(AX5051_TXDSPMODE             = 0x41820028); /* Transmit DSP Mode */
PROVIDE(AX5051_PINCFG1               = 0x41820030); /* Pin Configuration 1 */
PROVIDE(AX5051_PINCFG2               = 0x41820034); /* Pin Configuration 2 */
PROVIDE(AX5051_PINCFG3               = 0x41820038); /* Pin Configuration 3 */
PROVIDE(AX5051_IRQINVERSION          = 0x4182003C); /* IRQ Inversion */
PROVIDE(AX5051_MODULATION            = 0x41820040); /* Modulation */
PROVIDE(AX5051_ENCODING              = 0x41820044); /* Encoding */
PROVIDE(AX5051_FRAMING               = 0x41820048); /* Framing Mode */
PROVIDE(AX5051_CRCINIT               = 0x419A0050); /* CRC Initial Value */
PROVIDE(AX5051_CRCINIT3              = 0x41820050); /* CRC Initial Value 3 */
PROVIDE(AX5051_CRCINIT2              = 0x41820054); /* CRC Initial Value 2 */
PROVIDE(AX5051_CRCINIT1              = 0x41820058); /* CRC Initial Value 1 */
PROVIDE(AX5051_CRCINIT0              = 0x4182005C); /* CRC Initial Value 0 */
PROVIDE(AX5051_FEC                   = 0x41820060); /* Forward Error Correction */
PROVIDE(AX5051_FECSYNC               = 0x41820064); /* Forward Error Correction Sync Threshold */
PROVIDE(AX5051_FECSTATUS             = 0x41820068); /* Forward Error Correction Status */
PROVIDE(AX5051_VREG                  = 0x4182006C); /* Voltage Regulator */
PROVIDE(AX5051_FREQ                  = 0x419A0080); /* Frequency */
PROVIDE(AX5051_FREQ3                 = 0x41820080); /* Frequency 3 */
PROVIDE(AX5051_FREQA                 = 0x419A0080); /* Frequency */
PROVIDE(AX5051_FREQA3                = 0x41820080); /* Frequency 3 */
PROVIDE(AX5051_FREQ2                 = 0x41820084); /* Frequency 2 */
PROVIDE(AX5051_FREQA2                = 0x41820084); /* Frequency 2 */
PROVIDE(AX5051_FREQ1                 = 0x41820088); /* Frequency 1 */
PROVIDE(AX5051_FREQA1                = 0x41820088); /* Frequency 1 */
PROVIDE(AX5051_FREQ0                 = 0x4182008C); /* Frequency 0 */
PROVIDE(AX5051_FREQA0                = 0x4182008C); /* Frequency 0 */
PROVIDE(AX5051_FSKDEV                = 0x41920094); /* FSK Deviation */
PROVIDE(AX5051_FSKDEV2               = 0x41820094); /* FSK Deviation 2 */
PROVIDE(AX5051_FSKDEV1               = 0x41820098); /* FSK Deviation 1 */
PROVIDE(AX5051_FSKDEV0               = 0x4182009C); /* FSK Deviation 0 */
PROVIDE(AX5051_IFFREQHI              = 0x418200A0); /* IF Frequency Low */
PROVIDE(AX5051_IFFREQLO              = 0x418200A4); /* IF Frequency High */
PROVIDE(AX5051_PLLLOOP               = 0x418200B0); /* PLL Loop Filter */
PROVIDE(AX5051_PLLRANGING            = 0x418200B4); /* PLL Autoranging Control */
PROVIDE(AX5051_PLLRNGCLK             = 0x418200B8); /* PLL Autoranging Clock */
PROVIDE(AX5051_TXPWR                 = 0x418200C0); /* Transmit Power */
PROVIDE(AX5051_TXBITRATEHI           = 0x418200C4); /* Transmitter Bitrate High */
PROVIDE(AX5051_TXBITRATEMID          = 0x418200C8); /* Transmitter Bitrate Middle */
PROVIDE(AX5051_TXBITRATELO           = 0x418200CC); /* Transmitter Bitrate Low */
PROVIDE(AX5051_MODULATORMISC         = 0x418200D0); /* Modulator Miscellaneous Control */
PROVIDE(AX5051_FIFOCOUNT             = 0x418200D4); /* FIFO Count */
PROVIDE(AX5051_FIFOTHRESH            = 0x418200D8); /* FIFO Threshold */
PROVIDE(AX5051_FIFOCONTROL2          = 0x418200DC); /* FIFO Control 2 */
PROVIDE(AX5051_ADCMISC               = 0x418200E0); /* ADC Miscellaneous Control */
PROVIDE(AX5051_AGCTARGET             = 0x418200E4); /* AGC Target Value */
PROVIDE(AX5051_AGCATTACK             = 0x418200E8); /* AGC Attack Speed */
PROVIDE(AX5051_AGCDECAY              = 0x418200EC); /* AGC Decay Speed */
PROVIDE(AX5051_AGCCOUNTER            = 0x418200F0); /* AGC Counter */
PROVIDE(AX5051_CICSHIFT              = 0x418200F4); /* Decimation Filter Attenuation */
PROVIDE(AX5051_CICDECHI              = 0x418200F8); /* Decimation Factor High */
PROVIDE(AX5051_CICDECLO              = 0x418200FC); /* Decimation Factor Low */
PROVIDE(AX5051_DATARATEHI            = 0x41820100); /* Datarate High */
PROVIDE(AX5051_DATARATELO            = 0x41820104); /* Datarate Low */
PROVIDE(AX5051_TIMINGGAINHI          = 0x41820108); /* Timing Estimator Bandwidth High */
PROVIDE(AX5051_TIMINGGAINLO          = 0x4182010C); /* Timing Estimator Bandwidth Low */
PROVIDE(AX5051_PHASEGAIN             = 0x41820110); /* Phase Estimator Bandwidth */
PROVIDE(AX5051_FREQUENCYGAIN         = 0x41820114); /* Frequency Estimator Bandwidth */
PROVIDE(AX5051_FREQUENCYGAIN2        = 0x41820118); /* Frequency Estimator Bandwidth 2 */
PROVIDE(AX5051_AMPLITUDEGAIN         = 0x4182011C); /* Amplitude Estimator Bandwidth */
PROVIDE(AX5051_TRKAMPLITUDEHI        = 0x41820120); /* Amplitude Tracking High */
PROVIDE(AX5051_TRKAMPLITUDELO        = 0x41820124); /* Amplitude Tracking Low */
PROVIDE(AX5051_TRKPHASEHI            = 0x41820128); /* Phase Tracking High */
PROVIDE(AX5051_TRKPHASELO            = 0x4182012C); /* Phase Tracking Low */
PROVIDE(AX5051_TRKFREQHI             = 0x41820130); /* Frequency Tracking High */
PROVIDE(AX5051_TRKFREQLO             = 0x41820134); /* Frequency Tracking Low */
PROVIDE(AX5051_XTALCAP               = 0x4182013C); /* Crystal Oscillator Load Capacitance */
PROVIDE(AX5051_FECMEM                = 0x418201BC); /* Forward Error Correction Memory */
PROVIDE(AX5051_PLLVCOI               = 0x418201C8); /* PLL VCO Current */
PROVIDE(AX5051_RFMISC                = 0x418201E8); /* RF Miscellaneous Control */
PROVIDE(AX5051_REF                   = 0x418201F0); /* Reference */
PROVIDE(AX5051_RXMISC                = 0x418201F4); /* Receiver Miscellaneous Control */
PROVIDE(AX5051_SILICONREVISIONNB     = 0x41860000); /* Silicon Revision, non-blocking */
PROVIDE(AX5051_SCRATCHNB             = 0x41860004); /* Scratch, non-blocking */
PROVIDE(AX5051_PWRMODENB             = 0x41860008); /* Power Mode, non-blocking */
PROVIDE(AX5051_XTALOSCNB             = 0x4186000C); /* Crystal Oscillator Control, non-blocking */
PROVIDE(AX5051_FIFOCONTROLNB         = 0x41860010); /* FIFO Control, non-blocking */
PROVIDE(AX5051_FIFODATANB            = 0x41860014); /* FIFO Data, non-blocking */
PROVIDE(AX5051_IRQMASKNB             = 0x41860018); /* IRQ Mask, non-blocking */
PROVIDE(AX5051_IRQREQUESTNB          = 0x4186001C); /* IRQ Request, non-blocking */
PROVIDE(AX5051_IFMODENB              = 0x41860020); /* Interface Mode, non-blocking */
PROVIDE(AX5051_DSPMODENB             = 0x41860024); /* DSP Mode Interface Control, non-blocking */
PROVIDE(AX5051_TXDSPMODENB           = 0x41860028); /* Transmit DSP Mode, non-blocking */
PROVIDE(AX5051_PINCFG1NB             = 0x41860030); /* Pin Configuration 1, non-blocking */
PROVIDE(AX5051_PINCFG2NB             = 0x41860034); /* Pin Configuration 2, non-blocking */
PROVIDE(AX5051_PINCFG3NB             = 0x41860038); /* Pin Configuration 3, non-blocking */
PROVIDE(AX5051_IRQINVERSIONNB        = 0x4186003C); /* IRQ Inversion, non-blocking */
PROVIDE(AX5051_MODULATIONNB          = 0x41860040); /* Modulation, non-blocking */
PROVIDE(AX5051_ENCODINGNB            = 0x41860044); /* Encoding, non-blocking */
PROVIDE(AX5051_FRAMINGNB             = 0x41860048); /* Framing Mode, non-blocking */
PROVIDE(AX5051_CRCINITNB             = 0x419E0050); /* CRC Initial Value, non-blocking */
PROVIDE(AX5051_CRCINIT3NB            = 0x41860050); /* CRC Initial Value 3, non-blocking */
PROVIDE(AX5051_CRCINIT2NB            = 0x41860054); /* CRC Initial Value 2, non-blocking */
PROVIDE(AX5051_CRCINIT1NB            = 0x41860058); /* CRC Initial Value 1, non-blocking */
PROVIDE(AX5051_CRCINIT0NB            = 0x4186005C); /* CRC Initial Value 0, non-blocking */
PROVIDE(AX5051_FECNB                 = 0x41860060); /* Forward Error Correction, non-blocking */
PROVIDE(AX5051_FECSYNCNB             = 0x41860064); /* Forward Error Correction Sync Threshold, non-blocking */
PROVIDE(AX5051_FECSTATUSNB           = 0x41860068); /* Forward Error Correction Status, non-blocking */
PROVIDE(AX5051_VREGNB                = 0x4186006C); /* Voltage Regulator, non-blocking */
PROVIDE(AX5051_FREQNB                = 0x419E0080); /* Frequency, non-blocking */
PROVIDE(AX5051_FREQ3NB               = 0x41860080); /* Frequency 3, non-blocking */
PROVIDE(AX5051_FREQANB               = 0x419E0080); /* Frequency, non-blocking */
PROVIDE(AX5051_FREQA3NB              = 0x41860080); /* Frequency 3, non-blocking */
PROVIDE(AX5051_FREQ2NB               = 0x41860084); /* Frequency 2, non-blocking */
PROVIDE(AX5051_FREQA2NB              = 0x41860084); /* Frequency 2, non-blocking */
PROVIDE(AX5051_FREQ1NB               = 0x41860088); /* Frequency 1, non-blocking */
PROVIDE(AX5051_FREQA1NB              = 0x41860088); /* Frequency 1, non-blocking */
PROVIDE(AX5051_FREQ0NB               = 0x4186008C); /* Frequency 0, non-blocking */
PROVIDE(AX5051_FREQA0NB              = 0x4186008C); /* Frequency 0, non-blocking */
PROVIDE(AX5051_FSKDEVNB              = 0x41960094); /* FSK Deviation, non-blocking */
PROVIDE(AX5051_FSKDEV2NB             = 0x41860094); /* FSK Deviation 2, non-blocking */
PROVIDE(AX5051_FSKDEV1NB             = 0x41860098); /* FSK Deviation 1, non-blocking */
PROVIDE(AX5051_FSKDEV0NB             = 0x4186009C); /* FSK Deviation 0, non-blocking */
PROVIDE(AX5051_IFFREQHINB            = 0x418600A0); /* IF Frequency Low, non-blocking */
PROVIDE(AX5051_IFFREQLONB            = 0x418600A4); /* IF Frequency High, non-blocking */
PROVIDE(AX5051_PLLLOOPNB             = 0x418600B0); /* PLL Loop Filter, non-blocking */
PROVIDE(AX5051_PLLRANGINGNB          = 0x418600B4); /* PLL Autoranging Control, non-blocking */
PROVIDE(AX5051_PLLRNGCLKNB           = 0x418600B8); /* PLL Autoranging Clock, non-blocking */
PROVIDE(AX5051_TXPWRNB               = 0x418600C0); /* Transmit Power, non-blocking */
PROVIDE(AX5051_TXBITRATEHINB         = 0x418600C4); /* Transmitter Bitrate High, non-blocking */
PROVIDE(AX5051_TXBITRATEMIDNB        = 0x418600C8); /* Transmitter Bitrate Middle, non-blocking */
PROVIDE(AX5051_TXBITRATELONB         = 0x418600CC); /* Transmitter Bitrate Low, non-blocking */
PROVIDE(AX5051_MODULATORMISCNB       = 0x418600D0); /* Modulator Miscellaneous Control, non-blocking */
PROVIDE(AX5051_FIFOCOUNTNB           = 0x418600D4); /* FIFO Count, non-blocking */
PROVIDE(AX5051_FIFOTHRESHNB          = 0x418600D8); /* FIFO Threshold, non-blocking */
PROVIDE(AX5051_FIFOCONTROL2NB        = 0x418600DC); /* FIFO Control 2, non-blocking */
PROVIDE(AX5051_ADCMISCNB             = 0x418600E0); /* ADC Miscellaneous Control, non-blocking */
PROVIDE(AX5051_AGCTARGETNB           = 0x418600E4); /* AGC Target Value, non-blocking */
PROVIDE(AX5051_AGCATTACKNB           = 0x418600E8); /* AGC Attack Speed, non-blocking */
PROVIDE(AX5051_AGCDECAYNB            = 0x418600EC); /* AGC Decay Speed, non-blocking */
PROVIDE(AX5051_AGCCOUNTERNB          = 0x418600F0); /* AGC Counter, non-blocking */
PROVIDE(AX5051_CICSHIFTNB            = 0x418600F4); /* Decimation Filter Attenuation, non-blocking */
PROVIDE(AX5051_CICDECHINB            = 0x418600F8); /* Decimation Factor High, non-blocking */
PROVIDE(AX5051_CICDECLONB            = 0x418600FC); /* Decimation Factor Low, non-blocking */
PROVIDE(AX5051_DATARATEHINB          = 0x41860100); /* Datarate High, non-blocking */
PROVIDE(AX5051_DATARATELONB          = 0x41860104); /* Datarate Low, non-blocking */
PROVIDE(AX5051_TIMINGGAINHINB        = 0x41860108); /* Timing Estimator Bandwidth High, non-blocking */
PROVIDE(AX5051_TIMINGGAINLONB        = 0x4186010C); /* Timing Estimator Bandwidth Low, non-blocking */
PROVIDE(AX5051_PHASEGAINNB           = 0x41860110); /* Phase Estimator Bandwidth, non-blocking */
PROVIDE(AX5051_FREQUENCYGAINNB       = 0x41860114); /* Frequency Estimator Bandwidth, non-blocking */
PROVIDE(AX5051_FREQUENCYGAIN2NB      = 0x41860118); /* Frequency Estimator Bandwidth 2, non-blocking */
PROVIDE(AX5051_AMPLITUDEGAINNB       = 0x4186011C); /* Amplitude Estimator Bandwidth, non-blocking */
PROVIDE(AX5051_TRKAMPLITUDEHINB      = 0x41860120); /* Amplitude Tracking High, non-blocking */
PROVIDE(AX5051_TRKAMPLITUDELONB      = 0x41860124); /* Amplitude Tracking Low, non-blocking */
PROVIDE(AX5051_TRKPHASEHINB          = 0x41860128); /* Phase Tracking High, non-blocking */
PROVIDE(AX5051_TRKPHASELONB          = 0x4186012C); /* Phase Tracking Low, non-blocking */
PROVIDE(AX5051_TRKFREQHINB           = 0x41860130); /* Frequency Tracking High, non-blocking */
PROVIDE(AX5051_TRKFREQLONB           = 0x41860134); /* Frequency Tracking Low, non-blocking */
PROVIDE(AX5051_XTALCAPNB             = 0x4186013C); /* Crystal Oscillator Load Capacitance, non-blocking */
PROVIDE(AX5051_FECMEMNB              = 0x418601BC); /* Forward Error Correction Memory, non-blocking */
PROVIDE(AX5051_PLLVCOINB             = 0x418601C8); /* PLL VCO Current, non-blocking */
PROVIDE(AX5051_RFMISCNB              = 0x418601E8); /* RF Miscellaneous Control, non-blocking */
PROVIDE(AX5051_REFNB                 = 0x418601F0); /* Reference, non-blocking */
PROVIDE(AX5051_RXMISCNB              = 0x418601F4); /* Receiver Miscellaneous Control, non-blocking */
