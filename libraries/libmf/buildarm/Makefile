TARGET_MODEL	:=
TARGET_DEFINES	:=
ifeq ($(OS),Windows_NT)
TARGET_ASM	:= arm-none-eabi-as.exe
TARGET_LD	:= arm-none-eabi-ld.exe
TARGET_CC	:= arm-none-eabi-gcc.exe
TARGET_AR	:= arm-none-eabi-ar.exe
TARGET_RANLIB	:= arm-none-eabi-ranlib.exe
else
TARGET_INSTDIR	:= /usr
TARGET_ASM	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-as
TARGET_LD	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-ld
TARGET_CC	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-gcc
TARGET_AR	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-ar
TARGET_RANLIB	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-ranlib
endif

TARGET_ASMFLAGS	:= -mcpu=cortex-m0plus -mthumb
TARGET_LNKFLAGS	:=
TARGET_ARFLAGS	:= --target=elf32-littlearm
TARGET_CFLAGS	:= -mcpu=cortex-m0plus -mthumb -fno-common -Os -g -Wall $(LIBDEFINES) -D__STACK_SIZE=0x400 -D__HEAP_SIZE=0x100 -D__START=main -D__STARTUP_CLEAR_BSS -I../source -I../source/CMSIS_5/CMSIS/Core/Include -I../source/CMSIS_5/Device/ARM/ARMCM0plus/Include

LIBMFOBJ	:= startup_ARMCM0plus.o stackheap.o system_ARMCM0plus.o axm0$(LIBSUFFIX)vectors.o \
		   dbglnktx.o dbglnkrx.o dbglnkwrhexu16.o dbglnkwrhexu32.o dbglnkwrstr.o \
		   dbglnkwru16.o dbglnkwru32.o dbglnkwrnum16.o dbglnkwrnum32.o dbglnkwrhex16.o dbglnkwrhex32.o \
		   crc8ccitt.o crc8onewire.o crc8tccitt.o crc8tccittmsb.o crc8tonewire.o crc8tonewiremsb.o \
		   crc8ccittb.o crc8ccittmsbb.o crc8onewireb.o crc8onewiremsbb.o \
		   crc8ccitttable.o crc8onewiretable.o crc8ccittmsbtable.o crc8onewiremsbtable.o \
		   crcccitt.o crcccittmsb.o crc16ansi.o crc16ansimsb.o crc16dnp.o crc16dnpmsb.o crc32ansi.o crc32ansimsb.o \
		   crcccittb.o crcccittmsbb.o crc16ansib.o crc16ansimsbb.o crc16dnpb.o crc16dnpmsbb.o crc32ansib.o crc32ansimsbb.o \
		   crcccitttable.o crc16table.o crc16dnptable.o crcccittmsbtable.o crc16msbtable.o \
		   crc16dnpmsbtable.o crc32table.o crc32msbtable.o pn9.o pn9table.o pn9bit.o pn9bits.o pn9byte.o pn9buf.o \
		   pn15advtable.o pn15outtable.o pn15adv.o pn15out.o \
		   rev8.o hweight8.o hweight16.o hweight32.o signext12.o signext16.o signext20.o signext24.o \
		   chksgnlim16.o sgnlim16.o chksgnlim32.o sgnlim32.o grayenc8.o graydec8.o \
		   delay.o random.o startcause.o sleep.o sleepcont.o deepsleep.o deepsleepcont.o standby.o resetcpu.o critical.o \
		   memcpygx.o memcpyx.o memcpyxg.o memsetx.o \
		   bch3121dec.o bch3121decp.o bch3121enc.o bch3121encp.o bch3121stab.o bch3121syn.o \
		   wrnum16.o wrnum32.o \
		   radiord8.o radiord16.o radiord24.o radiord32.o radiowr8.o radiowr8nb.o radiowr16.o radiowr24.o radiowr32.o \
		   wtimer.o wtrem.o wtcbadd.o wtcbrem.o wt0setcfg.o wt1setcfg.o wtstdby.o \
		   wt0adda.o wt1adda.o wt0addr.o wt1addr.o wt0curt.o wt1curt.o wt0rem.o wt1rem.o wt01rem.o \
		   axm0$(LIBSUFFIX)_$(PIN).o axm0_uart.o axm0_uart0.o axm0_uart1.o \
		   uarttimer0.o uarttimer1.o uarttimer2.o uart0init.o uart1init.o uart0stop.o uart1stop.o \
		   uart0txbuf.o uart1txbuf.o uart0rxbuf.o uart1rxbuf.o \
		   uart0tx.o uart1tx.o uart0rx.o uart1rx.o uart0wrhexu16.o uart1wrhexu16.o uart0wrhexu32.o uart1wrhexu32.o \
		   uart0wrstr.o uart1wrstr.o uart0wru16.o uart1wru16.o uart0wru32.o uart1wru32.o \
		   uart0wrnum16.o uart0wrnum32.o uart0wrhex16.o uart0wrhex32.o \
		   uart1wrnum16.o uart1wrnum32.o uart1wrhex16.o uart1wrhex32.o \
		   radiodswakecore.o \
		   ax5043rdfifo.o ax5043wrfifo.o \
		   ax5043rclkena.o ax5043rclkwait.o ax5043rclkdis.o ax5043reset.o ax5043comminit.o ax5043commslpexit.o ax5043reset.o ax5043deepsleep.o \
		   flashunlock.o flashlock.o flashwait.o flashpgerase.o flashwrite.o flashread.o \
		   setupcal.o \
		   ax5031comminit.o ax5031commslpexit.o ax5031reset.o ax5031deepsleep.o ax5031rclkena.o ax5031rclkdis.o \
		   ax5031rdfifo.o ax5031wrfifo.o \
		   ax5042comminit.o ax5042commslpexit.o ax5042reset.o ax5042deepsleep.o ax5042rclkena.o ax5042rclkdis.o \
		   ax5042rdfifo.o ax5042wrfifo.o \
		   ax5051comminit.o ax5051commslpexit.o ax5051reset.o ax5051deepsleep.o ax5051rclkena.o ax5051rclkdis.o \
		   ax5051rdfifo.o ax5051wrfifo.o \
		   adctemp.o \
		   i2c0.o i2c1.o i2cm.o \
		   spi0.o spi.o \
		   adc.o \
		   pwm.o
		   #flashcal.o
		   #adccal.o adccalg.o adccalt.o adcuncal.o adcseoffs00.o adcseoffs01.o adcseoffs10.o \
		   #offxosc.o offlpxosc.o setuplpxosc.o setupxosc.o \
		   #calsect.o


LIBBINARIES					:= libmf.a libmff2.a


ifeq ($(LIBBINARY),)
all:						$(LIBBINARIES)

.PHONY:						libmf.a
.PHONY:						libmff2.a

libmf.a:
						make LIBBINARY="$@" PIN="xbar" LIBSUFFIX="" LIBDEFINES="-D__AXM0=1" LIBCPUHDR="../source/axm0.h" LIBRADIOHDR="../source/axm0f131.h ../source/axm0f142.h ../source/axm0f143.h ../source/axm0f151.h"

libmff2.a:
						make LIBBINARY="$@" PIN="pin" LIBSUFFIX="f2" LIBDEFINES="-D__AXM0F2=1" LIBCPUHDR="../source/axm0f2.h" LIBRADIOHDR="../source/axm0f243.h"

else
all:						$(LIBBINARY)
endif

clean:
						rm -rf ./libmf/*.o ./libmf/*.c ./libmff2/*.o ./libmff2/*.c $(LIBBINARIES) $(patsubst %.o,%,$(LIBBINARIES)) mflibbinarm.tar.gz
						test ! -d ./libmf || rmdir ./libmf
						test ! -d ./libmff2 || rmdir ./libmff2

tar:						mflibbinarm.tar.gz

mflibbinarm.tar.gz:				$(LIBBINARIES)
						tar -c -v -z -f $@ $(LIBBINARIES)


libmf$(LIBSUFFIX):
						[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:					%.o

%.o:						../%.c
						$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<

%.S:						../%.c
						$(TARGET_CC) $(TARGET_CFLAGS) -S -o $@ $<

libmf$(LIBSUFFIX)/%.o:				../source/CMSIS_5/Device/ARM/ARMCM0plus/Source/%.c | libmf$(LIBSUFFIX)
						$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<

libmf$(LIBSUFFIX)/%.o:				../source/%.c | libmf$(LIBSUFFIX)
						$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<

libmf$(LIBSUFFIX)/%.S:				../source/%.c | libmf$(LIBSUFFIX)
						$(TARGET_CC) $(TARGET_CFLAGS) -S -o $@ $<

libmf$(LIBSUFFIX)/%.o:				../source/%.S | libmf$(LIBSUFFIX)
						$(TARGET_CC) $(TARGET_CFLAGS) -o $@ $<

libmf$(LIBSUFFIX)/%.o:				libmf$(LIBSUFFIX)/%.c | libmf$(LIBSUFFIX)
						$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<

libmf$(LIBSUFFIX)/%.S:				libmf$(LIBSUFFIX)/%.c | libmf$(LIBSUFFIX)
						$(TARGET_CC) $(TARGET_CFLAGS) -S -o $@ $<

libmf$(LIBSUFFIX)/%.o:				%.S | libmf$(LIBSUFFIX)
						$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<

libmf$(LIBSUFFIX)/%_ram.o:			%.S | libmf$(LIBSUFFIX)
						$(TARGET_CC) $(TARGET_CFLAGS) -D__RAM=1 -c -o $@ $<

ifneq ($(LIBBINARY),)
$(LIBBINARY):					$(patsubst %.o,libmf$(LIBSUFFIX)/%.o,$(LIBMFOBJ)) | libmf$(LIBSUFFIX)
						$(TARGET_AR) $(TARGET_ARFLAGS) -r $@ $(patsubst %.o,libmf$(LIBSUFFIX)/%.o,$(LIBMFOBJ))
						$(TARGET_RANLIB) $@
endif

libmf$(LIBSUFFIX)/uarttimer0.c:			../source/uarttimer.c
						(unifdef -DTIMER=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/uarttimer1.c:			../source/uarttimer.c
						(unifdef -DTIMER=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/uarttimer2.c:			../source/uarttimer.c
						(unifdef -DTIMER=2 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/uart0init.c:			../source/uartinit.c
						(unifdef -DUART=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/uart0stop.c:			../source/uartstop.c
						(unifdef -DUART=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/uart1init.c:			../source/uartinit.c
						(unifdef -DUART=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/uart1stop.c:			../source/uartstop.c
						(unifdef -DUART=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/uart0%.c:			../source/io%.c
						(unifdef -DUART=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/uart1%.c:			../source/io%.c
						(unifdef -DUART=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/dbglnk%.c:			../source/io%.c
						(unifdef -DUART=2 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/ax5031%.c:			../source/radio%.c
						(unifdef -DRADIO=5031 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/ax5042%.c:			../source/radio%.c
						(unifdef -DRADIO=5042 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/ax5043%.c:			../source/radio%.c
						(unifdef -DRADIO=5043 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/ax5051%.c:			../source/radio%.c
						(unifdef -DRADIO=5051 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc8tccitt.c:			../source/crc8.c
						(unifdef -DCRCMODE=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})
libmf$(LIBSUFFIX)/crc8tccittmsb.c:		../source/crc8msb.c
						(unifdef -DCRCMODE=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc8tonewire.c:		../source/crc8.c
						(unifdef -DCRCMODE=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc8tonewiremsb.c:		../source/crc8msb.c
						(unifdef -DCRCMODE=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc16ansi.c:			../source/crc16.c
						(unifdef -DCRCMODE=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc16ansimsb.c:		../source/crc16msb.c
						(unifdef -DCRCMODE=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc16dnp.c:			../source/crc16.c
						(unifdef -DCRCMODE=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc16dnpmsb.c:		../source/crc16msb.c
						(unifdef -DCRCMODE=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crcccitt.c:			../source/crc16.c
						(unifdef -DCRCMODE=2 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crcccittmsb.c:		../source/crc16msb.c
						(unifdef -DCRCMODE=2 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc32ansi.c:			../source/crc32.c
						(unifdef -DCRCMODE=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc32ansimsb.c:		../source/crc32msb.c
						(unifdef -DCRCMODE=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc8ccittb.c:			../source/crc8b.c
						(unifdef -DCRCMODE=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc8ccittmsbb.c:		../source/crc8b.c
						(unifdef -DCRCMODE=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc8onewireb.c:		../source/crc8b.c
						(unifdef -DCRCMODE=2 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc8onewiremsbb.c:		../source/crc8b.c
						(unifdef -DCRCMODE=3 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc16ansib.c:			../source/crc16b.c
						(unifdef -DCRCMODE=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc16ansimsbb.c:		../source/crc16b.c
						(unifdef -DCRCMODE=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc16dnpb.c:			../source/crc16b.c
						(unifdef -DCRCMODE=2 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc16dnpmsbb.c:		../source/crc16b.c
						(unifdef -DCRCMODE=3 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crcccittb.c:			../source/crc16b.c
						(unifdef -DCRCMODE=4 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crcccittmsbb.c:		../source/crc16b.c
						(unifdef -DCRCMODE=5 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc32ansib.c:			../source/crc32b.c
						(unifdef -DCRCMODE=0 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/crc32ansimsbb.c:		../source/crc32b.c
						(unifdef -DCRCMODE=1 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libmf$(LIBSUFFIX)/delay.o:			../source/delay.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/random.o:			../source/random.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8ccitt.o:			../source/crc8ccitt.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8onewire.o:		../source/crc8onewire.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8ccitttable.o:		../source/crc8ccitttable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8onewiretable.o:		../source/crc8onewiretable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8ccittmsbtable.o:		../source/crc8ccittmsbtable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8onewiremsbtable.o:	../source/crc8onewiremsbtable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crcccitttable.o:		../source/crcccitttable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16table.o:			../source/crc16table.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16dnptable.o:		../source/crc16dnptable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crcccittmsbtable.o:		../source/crcccittmsbtable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16msbtable.o:		../source/crc16msbtable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16dnpmsbtable.o:		../source/crc16dnpmsbtable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc32table.o:			../source/crc32table.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc32msbtable.o:		../source/crc32msbtable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8tccitt.o:			libmf$(LIBSUFFIX)/crc8tccitt.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8tccittmsb.o:		libmf$(LIBSUFFIX)/crc8tccittmsb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8tonewire.o:		libmf$(LIBSUFFIX)/crc8tonewire.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8tonewiremsb.o:		libmf$(LIBSUFFIX)/crc8tonewiremsb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16ansi.o:			libmf$(LIBSUFFIX)/crc16ansi.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16ansimsb.o:		libmf$(LIBSUFFIX)/crc16ansimsb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16dnp.o:			libmf$(LIBSUFFIX)/crc16dnp.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16dnpmsb.o:		libmf$(LIBSUFFIX)/crc16dnpmsb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crcccitt.o:			libmf$(LIBSUFFIX)/crcccitt.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crcccittmsb.o:		libmf$(LIBSUFFIX)/crcccittmsb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc32ansi.o:			libmf$(LIBSUFFIX)/crc32ansi.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc32ansimsb.o:		libmf$(LIBSUFFIX)/crc32ansimsb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8ccittb.o:			libmf$(LIBSUFFIX)/crc8ccittb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8ccittmsbb.o:		libmf$(LIBSUFFIX)/crc8ccittmsbb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8onewireb.o:		libmf$(LIBSUFFIX)/crc8onewireb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc8onewiremsbb.o:		libmf$(LIBSUFFIX)/crc8onewiremsbb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16ansib.o:			libmf$(LIBSUFFIX)/crc16ansib.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16ansimsbb.o:		libmf$(LIBSUFFIX)/crc16ansimsbb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16dnpb.o:			libmf$(LIBSUFFIX)/crc16dnpb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc16dnpmsbb.o:		libmf$(LIBSUFFIX)/crc16dnpmsbb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crcccittb.o:			libmf$(LIBSUFFIX)/crcccittb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crcccittmsbb.o:		libmf$(LIBSUFFIX)/crcccittmsbb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc32ansib.o:			libmf$(LIBSUFFIX)/crc32ansib.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/crc32ansimsbb.o:		libmf$(LIBSUFFIX)/crc32ansimsbb.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn9.o:			../source/pn9.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn9table.o:			../source/pn9table.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn9bit.o:			../source/pn9bit.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn9bits.o:			../source/pn9bits.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn9byte.o:			../source/pn9byte.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn9buf.o:			../source/pn9buf.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn15advtable.o:		../source/pn15advtable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn15outtable.o:		../source/pn15outtable.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn15adv.o:			../source/pn15adv.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pn15out.o:			../source/pn15out.c ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/rev8.o:			../source/rev8.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/hweight8.o:			../source/hweight8.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/hweight16.o:			../source/hweight16.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/hweight32.o:			../source/hweight32.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/signext12.o:			../source/signext12.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/signext16.o:			../source/signext16.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/signext20.o:			../source/signext20.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/signext24.o:			../source/signext24.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/chksgnlim16.o:		../source/chksgnlim16.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/sgnlim16.o:			../source/sgnlim16.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/chksgnlim32.o:		../source/chksgnlim32.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/sgnlim32.o:			../source/sgnlim32.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/grayenc8.o:			../source/grayenc8.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/graydec8.o:			../source/graydec8.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/fmemset.o:			../source/fmemset.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/fmemcpy.o:			../source/fmemcpy.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/fmemsetiar.o:			../source/fmemsetiar.s51 | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/fmemcpyiar.o:			../source/fmemcpyiar.s51 | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/startcause.o:			../source/startcause.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/standby.o:			../source/standby.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/sleep.o:			../source/sleep.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/sleepcont.o:			../source/sleepcont.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/deepsleep.o:			../source/deepsleep.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/deepsleepcont.o:		../source/deepsleepcont.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/resetcpu.o:			../source/resetcpu.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/critical.o:			../source/critical.c | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/memcpygx.o:			../source/memcpygx.c ../source/libmfstring.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/memcpyx.o:			../source/memcpyx.c ../source/libmfstring.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/memcpyxg.o:			../source/memcpyxg.c ../source/libmfstring.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/memsetx.o:			../source/memsetx.c ../source/libmfstring.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/flashunlock.o:		../source/flashunlock.c ../source/libmfflash.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/flashlock.o:			../source/flashlock.c ../source/libmfflash.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/flashwait.o:			../source/flashwait.c ../source/libmfflash.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/flashpgerase.o:		../source/flashpgerase.c ../source/libmfflash.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/flashwrite.o:			../source/flashwrite.c ../source/libmfflash.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/flashread.o:			../source/flashread.c ../source/libmfflash.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/flashcal.o:			../source/flashcal.c ../source/libmfcalsector.h ../source/libmfflash.h ../source/libmfcrc.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0init.o:			libmf$(LIBSUFFIX)/uart0init.c ../source/libmfuart0.h ../source/libmfuart.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1init.o:			libmf$(LIBSUFFIX)/uart1init.c ../source/libmfuart1.h ../source/libmfuart.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0stop.o:			libmf$(LIBSUFFIX)/uart0stop.c ../source/libmfuart0.h ../source/libmfuart.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1stop.o:			libmf$(LIBSUFFIX)/uart1stop.c ../source/libmfuart1.h ../source/libmfuart.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0txbuf.o:			libmf$(LIBSUFFIX)/uart0txbuf.c ../source/libmfuart0.h ../source/libmfuart.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1txbuf.o:			libmf$(LIBSUFFIX)/uart1txbuf.c ../source/libmfuart1.h ../source/libmfuart.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0rxbuf.o:			libmf$(LIBSUFFIX)/uart0rxbuf.c ../source/libmfuart0.h ../source/libmfuart.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1rxbuf.o:			libmf$(LIBSUFFIX)/uart1rxbuf.c ../source/libmfuart1.h ../source/libmfuart.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0tx.o:			libmf$(LIBSUFFIX)/uart0tx.c ../source/libmfuart0.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1tx.o:			libmf$(LIBSUFFIX)/uart1tx.c ../source/libmfuart1.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0rx.o:			libmf$(LIBSUFFIX)/uart0rx.c ../source/libmfuart0.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1rx.o:			libmf$(LIBSUFFIX)/uart1rx.c ../source/libmfuart1.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0wrhexu16.o:		libmf$(LIBSUFFIX)/uart0wrhexu16.c ../source/libmfuart0.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1wrhexu16.o:		libmf$(LIBSUFFIX)/uart1wrhexu16.c ../source/libmfuart1.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0wrhexu32.o:		libmf$(LIBSUFFIX)/uart0wrhexu32.c ../source/libmfuart0.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1wrhexu32.o:		libmf$(LIBSUFFIX)/uart1wrhexu32.c ../source/libmfuart1.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0wrstr.o:			libmf$(LIBSUFFIX)/uart0wrstr.c ../source/libmfuart0.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1wrstr.o:			libmf$(LIBSUFFIX)/uart1wrstr.c ../source/libmfuart1.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0wru16.o:			libmf$(LIBSUFFIX)/uart0wru16.c ../source/libmfuart0.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1wru16.o:			libmf$(LIBSUFFIX)/uart1wru16.c ../source/libmfuart1.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0wru32.o:			libmf$(LIBSUFFIX)/uart0wru32.c ../source/libmfuart0.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1wru32.o:			libmf$(LIBSUFFIX)/uart1wru32.c ../source/libmfuart1.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0wrnum16.o:		libmf$(LIBSUFFIX)/uart0wrnum16.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1wrnum16.o:		libmf$(LIBSUFFIX)/uart1wrnum16.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0wrnum32.o:		libmf$(LIBSUFFIX)/uart0wrnum32.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1wrnum32.o:		libmf$(LIBSUFFIX)/uart1wrnum32.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0wrhex16.o:		libmf$(LIBSUFFIX)/uart0wrhex16.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1wrhex16.o:		libmf$(LIBSUFFIX)/uart1wrhex16.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart0wrhex32.o:		libmf$(LIBSUFFIX)/uart0wrhex32.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/uart1wrhex32.o:		libmf$(LIBSUFFIX)/uart1wrhex32.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglink.o:			../source/dbglink.c ../source/libmfdbglink.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnktxbuf.o:		libmf$(LIBSUFFIX)/dbglnktxbuf.c ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkrxbuf.o:		libmf$(LIBSUFFIX)/dbglnkrxbuf.c ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnktx.o:			libmf$(LIBSUFFIX)/dbglnktx.c ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkrx.o:			libmf$(LIBSUFFIX)/dbglnkrx.c ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkwrhexu16.o:		libmf$(LIBSUFFIX)/dbglnkwrhexu16.c ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkwrhexu32.o:		libmf$(LIBSUFFIX)/dbglnkwrhexu32.c ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkwrstr.o:		libmf$(LIBSUFFIX)/dbglnkwrstr.c ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkwru16.o:		libmf$(LIBSUFFIX)/dbglnkwru16.c ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkwru32.o:		libmf$(LIBSUFFIX)/dbglnkwru32.c ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkwrnum16.o:		libmf$(LIBSUFFIX)/dbglnkwrnum16.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkwrnum32.o:		libmf$(LIBSUFFIX)/dbglnkwrnum32.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkwrhex16.o:		libmf$(LIBSUFFIX)/dbglnkwrhex16.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/dbglnkwrhex32.o:		libmf$(LIBSUFFIX)/dbglnkwrhex32.c ../source/wrnum.h ../source/libmfuart0.h ../source/libmfuart1.h ../source/libmfdbglink.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/adctemp.o:			../source/adctemp.c ../source/libmfadc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/i2cm.o:			../source/i2cm.c ../source/libmfi2cm.h ../source/i2c.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/i2c0.o:			../source/i2c0.c ../source/libmfi2cm.h ../source/i2c.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/i2c1.o:			../source/i2c1.c ../source/libmfi2cm.h ../source/i2c.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/adc.o:			../source/adc.c ../source/libmfadc.h ../source/adc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/pwm.o:			../source/pwm.c ../source/libmfpwm.h ../source/pwm.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/adccal.o:			../source/adccal.c ../source/libmfadc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/adccalg.o:			../source/adccalg.c ../source/libmfadc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/adccalt.o:			../source/adccalt.c ../source/libmfadc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/adcuncal.o:			../source/adcuncal.c ../source/libmfadc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/adcseoffs00.o:		../source/adcseoffs00.c ../source/libmfadc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/adcseoffs01.o:		../source/adcseoffs01.c ../source/libmfadc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/adcseoffs10.o:		../source/adcseoffs10.c ../source/libmfadc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/bch3121dec.o:			../source/bch3121dec.c ../source/libmfbch.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/bch3121decp.o:		../source/bch3121decp.c ../source/libmfbch.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/bch3121enc.o:			../source/bch3121enc.c ../source/libmfbch.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/bch3121encp.o:		../source/bch3121encp.c ../source/libmfbch.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/bch3121stab.o:		../source/bch3121stab.c ../source/libmfbch.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/bch3121syn.o:			../source/bch3121syn.c ../source/libmfbch.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wrnum16.o:			../source/wrnum16.c ../source/wrnum.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wrnum32.o:			../source/wrnum32.c ../source/wrnum.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/offxosc.o:			../source/offxosc.c ../source/libmfosc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/offlpxosc.o:			../source/offlpxosc.c ../source/libmfosc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/setuplpxosc.o:		../source/setuplpxosc.c ../source/libmfosc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/setupxosc.o:			../source/setupxosc.c ../source/libmfosc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/setupcal.o:			../source/setupcal.c ../source/libmfosc.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wtimer.o:			../source/wtimer.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wtrem.o:			../source/wtrem.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wtcbadd.o:			../source/wtcbadd.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wtcbrem.o:			../source/wtcbrem.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt0setcfg.o:			../source/wt0setcfg.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt1setcfg.o:			../source/wt1setcfg.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wtstdby.o:			../source/wtstdby.c ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt0adda.o:			../source/wt0adda.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt1adda.o:			../source/wt1adda.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt0addr.o:			../source/wt0addr.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt1addr.o:			../source/wt1addr.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt0curt.o:			../source/wt0curt.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt1curt.o:			../source/wt1curt.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt0rem.o:			../source/wt0rem.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt1rem.o:			../source/wt1rem.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/wt01rem.o:			../source/wt01rem.c ../source/wtimer.h ../source/libmfwtimer.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiord8.o:			../source/radiord8.c ../source/libmfradio.h ../source/libmftypes.h ../source/radioutil.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiord16.o:			../source/radiord16.c ../source/libmfradio.h ../source/libmftypes.h ../source/radioutil.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiord24.o:			../source/radiord24.c ../source/libmfradio.h ../source/libmftypes.h ../source/radioutil.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiord32.o:			../source/radiord32.c ../source/libmfradio.h ../source/libmftypes.h ../source/radioutil.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiowr8.o:			../source/radiowr8.c ../source/libmfradio.h ../source/libmftypes.h ../source/radioutil.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiowr8nb.o:			../source/radiowr8nb.c ../source/libmfradio.h ../source/libmftypes.h ../source/radioutil.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiowr16.o:			../source/radiowr16.c ../source/libmfradio.h ../source/libmftypes.h ../source/radioutil.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiowr24.o:			../source/radiowr24.c ../source/libmfradio.h ../source/libmftypes.h ../source/radioutil.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiowr32.o:			../source/radiowr32.c ../source/libmfradio.h ../source/libmftypes.h ../source/radioutil.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiodswakecore.o:		../source/radiodswakecore.c ../source/radiodefs.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5031comminit.o:		libmf$(LIBSUFFIX)/ax5031comminit.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5031commslpexit.o:		libmf$(LIBSUFFIX)/ax5031commslpexit.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5031reset.o:		libmf$(LIBSUFFIX)/ax5031reset.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5031deepsleep.o:		libmf$(LIBSUFFIX)/ax5031deepsleep.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5031rclkena.o:		../source/ax5031rclkena.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5031rclkdis.o:		../source/ax5031rclkdis.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5031rdfifo.o:		libmf$(LIBSUFFIX)/ax5031rdfifo.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5031wrfifo.o:		libmf$(LIBSUFFIX)/ax5031wrfifo.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5042comminit.o:		libmf$(LIBSUFFIX)/ax5042comminit.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5042commslpexit.o:		libmf$(LIBSUFFIX)/ax5042commslpexit.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5042reset.o:		libmf$(LIBSUFFIX)/ax5042reset.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5042deepsleep.o:		libmf$(LIBSUFFIX)/ax5042deepsleep.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5042rclkena.o:		../source/ax5042rclkena.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5042rclkdis.o:		../source/ax5042rclkdis.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5042rdfifo.o:		libmf$(LIBSUFFIX)/ax5042rdfifo.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5042wrfifo.o:		libmf$(LIBSUFFIX)/ax5042wrfifo.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5043comminit.o:		libmf$(LIBSUFFIX)/ax5043comminit.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5043commslpexit.o:		libmf$(LIBSUFFIX)/ax5043commslpexit.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5043reset.o:		libmf$(LIBSUFFIX)/ax5043reset.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5043deepsleep.o:		libmf$(LIBSUFFIX)/ax5043deepsleep.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5043rclkena.o:		../source/ax5043rclkena.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5043rclkwait.o:		../source/ax5043rclkwait.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5043rclkdis.o:		../source/ax5043rclkdis.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5043rdfifo.o:		libmf$(LIBSUFFIX)/ax5043rdfifo.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5043wrfifo.o:		libmf$(LIBSUFFIX)/ax5043wrfifo.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5051comminit.o:		libmf$(LIBSUFFIX)/ax5051comminit.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5051commslpexit.o:		libmf$(LIBSUFFIX)/ax5051commslpexit.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5051reset.o:		libmf$(LIBSUFFIX)/ax5051reset.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5051deepsleep.o:		libmf$(LIBSUFFIX)/ax5051deepsleep.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5051rclkena.o:		../source/ax5051rclkena.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5051rclkdis.o:		../source/ax5051rclkdis.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5051rdfifo.o:		libmf$(LIBSUFFIX)/ax5051rdfifo.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/ax5051wrfifo.o:		libmf$(LIBSUFFIX)/ax5051wrfifo.c ../source/radiodefs.h ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) $(LIBRADIOHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/calsect.o:			../source/calsect.c ../source/libmfcalsector.h ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/armmemcpy.o:			../source/armmemcpy.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/armmemset.o:			../source/armmemset.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/armraise.o:			../source/armraise.c ../source/libmftypes.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/axm0$(LIBSUFFIX)_uart.o:	../source/axm0$(LIBSUFFIX)_uart.c ../source/axm0$(LIBSUFFIX)_uart.h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/axm0$(LIBSUFFIX)_$(PIN).o:	../source/axm0$(LIBSUFFIX)_$(PIN).c ../source/axm0$(LIBSUFFIX)_$(PIN).h | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/radiordfifo.o:		../source/radiordfifo.c ../source/libmfradio.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/spi.o:			../source/spi.c ../source/libmfspi.h ../source/spi.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
libmf$(LIBSUFFIX)/spi0.o:			../source/spi0.c ../source/libmfspi.h ../source/spi.h ../source/libmftypes.h $(LIBCPUHDR) | libmf$(LIBSUFFIX)
