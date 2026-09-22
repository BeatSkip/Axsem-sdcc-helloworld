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
TARGET_CFLAGS	:= -mcpu=cortex-m0plus -mthumb -fno-common -Os -g -Wall $(LIBDEFINES) -I../source -I../../libmf/source -I../../libmf/source/CMSIS_5/CMSIS/Core/Include -I../../libmf/source/CMSIS_5/Device/ARM/ARMCM0plus/Include

LIBAXDVK2OBJ	:= lcdinit.o lcdsetpos.o lcdwrstr.o lcdclear.o lcdclrdisp.o lcdwru16.o lcdwru32.o \
		   lcdwrhexu16.o lcdwrhexu32.o lcduwrnum16.o lcduwrnum32.o lcduwrhex16.o lcduwrhex32.o \
		   lcd2init.o lcd2txbuf.o lcd2wrstr.o lcd2clrdisp.o lcd2setpos.o lcd2clear.o lcd2txcmds.o lcd2txcmdl.o \
		   lcd2utx.o lcd2uwrnum16.o lcd2uwrnum32.o lcd2uwrhex16.o lcd2uwrhex32.o

LIBBINARIES	:= libaxdvk2.a libaxdvk2f2.a


ifeq ($(LIBBINARY),)
all:					$(LIBBINARIES)

.PHONY:					libaxdvk2.a
.PHONY:					libaxdvk2f2.a

libaxdvk2.a:
					make LIBBINARY="$@" LIBSUFFIX="" LIBDEFINES="-D__AXM0=1"

libaxdvk2f2.a:
					make LIBBINARY="$@" LIBSUFFIX="f2" LIBDEFINES="-D__AXM0F2=1"
else
all:					$(LIBBINARY)
endif

clean:
					rm -rf libaxdvk2 libaxdvk2f2 $(LIBBINARIES) $(patsubst %.o,%,$(LIBBINARIES)) libaxdvk2binarm.tar.gz

tar:					libaxdvk2binarm.tar.gz

libaxdvk2binarm.tar.gz:			$(LIBBINARIES)
					tar -c -v -z -f $@ $(LIBBINARIES)

libaxdvk2$(LIBSUFFIX):
					[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:				%.o

%.o:					../%.c
					$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<

%.S:					../%.c
					$(TARGET_CC) $(TARGET_CFLAGS) -S -o $@ $<

libaxdvk2$(LIBSUFFIX)/%.o:		../source/%.c | libaxdvk2$(LIBSUFFIX)
					$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<

libaxdvk2$(LIBSUFFIX)/%.o:		libaxdvk2$(LIBSUFFIX)/%.c | libaxdvk2$(LIBSUFFIX)
					$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<
ifneq ($(LIBBINARY),)
$(LIBBINARY):				$(patsubst %.o,libaxdvk2$(LIBSUFFIX)/%.o,$(LIBAXDVK2OBJ)) | libaxdvk2$(LIBSUFFIX)
					$(TARGET_AR) -r $@ $(patsubst %.o,libaxdvk2$(LIBSUFFIX)/%.o,$(LIBAXDVK2OBJ))
					$(TARGET_RANLIB) $@
endif

libaxdvk2$(LIBSUFFIX)/lcdu%.c:		../source/io%.c
					(unifdef -DUART=3 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdvk2$(LIBSUFFIX)/lcd2u%.c:		../source/io%.c
					(unifdef -DUART=4 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdvk2$(LIBSUFFIX)/lcdinit.o:	../source/lcdinit.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdsetpos.o:	../source/lcdsetpos.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwrstr.o:	../source/lcdwrstr.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdclear.o:	../source/lcdclear.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdclrdisp.o:	../source/lcdclrdisp.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwru16.o:	../source/lcdwru16.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwru32.o:	../source/lcdwru32.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwrhexu16.o:	../source/lcdwrhexu16.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwrhexu32.o:	../source/lcdwrhexu32.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrnum16.o:	libaxdvk2$(LIBSUFFIX)/lcduwrnum16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrnum32.o:	libaxdvk2$(LIBSUFFIX)/lcduwrnum32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrhex16.o:	libaxdvk2$(LIBSUFFIX)/lcduwrhex16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrhex32.o:	libaxdvk2$(LIBSUFFIX)/lcduwrhex32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2init.o:	../source/lcd2init.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2txbuf.o:	../source/lcd2txbuf.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2wrstr.o:	../source/lcd2wrstr.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2clrdisp.o:	../source/lcd2clrdisp.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2setpos.o:	../source/lcd2setpos.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2clear.o:	../source/lcd2clear.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2txcmds.o:	../source/lcd2txcmds.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2txcmdl.o:	../source/lcd2txcmdl.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2utx.o:	libaxdvk2$(LIBSUFFIX)/lcd2utx.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2urx.o:	libaxdvk2$(LIBSUFFIX)/lcd2urx.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu16.o:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu16.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu32.o:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu32.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwru16.o:	libaxdvk2$(LIBSUFFIX)/lcd2uwru16.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwru32.o:	libaxdvk2$(LIBSUFFIX)/lcd2uwru32.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrnum16.o:	libaxdvk2$(LIBSUFFIX)/lcd2uwrnum16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrnum32.o:	libaxdvk2$(LIBSUFFIX)/lcd2uwrnum32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhex16.o:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhex16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhex32.o:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhex32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
