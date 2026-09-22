OS := $(shell uname)
ifeq ($(OS),Linux)
TARGET_PREFIX := sdcc-
else
TARGET_PREFIX := 
endif

TARGET_ASM	:= $(TARGET_PREFIX)asx8051
TARGET_LD	:= $(TARGET_PREFIX)sdcc
TARGET_CC	:= $(TARGET_PREFIX)sdcc
TARGET_AR	:= $(TARGET_PREFIX)sdcclib
TARGET_MODEL	:= --model-small
TARGET_ASMFLAGS	:= -xlosg
TARGET_LNKFLAGS	:= -mmcs51 --debug --code-loc 0x0000 --code-size 0x2000 --xram-loc 0x0000 --xram-size 0x100 $(TARGET_MODEL) --data-loc 0x08
TARGET_CFLAGS	:= --debug -I../source -I../../libmf/source $(TARGET_LNKFLAGS)
LIBSUFFIX	:=

LIBAXDVK2OBJ	:= lcdinit.rel lcdsetpos.rel lcdwrstr.rel lcdclear.rel lcdclrdisp.rel lcdwru16.rel lcdwru32.rel \
		   lcdwrhexu16.rel lcdwrhexu32.rel lcduwrnum16.rel lcduwrnum32.rel lcduwrhex16.rel lcduwrhex32.rel \
		   lcd2init.rel lcd2txbuf.rel lcd2wrstr.rel lcd2clrdisp.rel lcd2setpos.rel lcd2clear.rel lcd2txcmds.rel lcd2txcmdl.rel \
		   lcd2utx.rel lcd2uwrnum16.rel lcd2uwrnum32.rel lcd2uwrhex16.rel lcd2uwrhex32.rel

BINARIES	:=

all:				libaxdvk2.lib libaxdvk2large.lib $(BINARIES) $(patsubst %.omf,%.cdb,$(BINARIES)) $(patsubst %.omf,%.ihx,$(BINARIES))

clean:
				rm -rf *.lnk libaxdvk2.lib libaxdvk2 libaxdvk2large.lib libaxdvk2large libaxdvk2binsdcc.tar.gz libaxdvk2src.tar.gz

tar:				libaxdvk2binsdcc.tar.gz libaxdvk2src.tar.gz

libaxdvk2binsdcc.tar.gz:	libaxdvk2.lib libaxdvk2large.lib
				tar -c -v -z -f $@ libaxdvk2.lib libaxdvk2large.lib

libaxdvk2src.tar.gz:
				cd .. ; \
				tar -c -v -z -f buildsdcc/$@ build*/Makefile source/*.c source/*.h doc/LibAXDVK2.pdf

ifeq ($(LIBSUFFIX),)
libaxdvk2large.lib:
				make TARGET_MODEL=--model-large LIBSUFFIX=large
endif

libaxdvk2$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.rel %.omf %.ihx %.cdb

%.rel:				../%.c
				($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

%.omf %.ihx %.cdb:		%.rel libaxdvk2$(LIBSUFFIX).lib
				(libdir=`pwd`; dn=`dirname $<`/; fn=`basename $< .rel`; cd $${dn}; $(TARGET_LD) -V $(TARGET_LNKFLAGS) -L$${libdir} -llibaxdvk2$(LIBSUFFIX) $${fn}.rel; x=$$?; mv $${fn} $${fn}.omf; exit $${x})

libaxdvk2$(LIBSUFFIX)/%.rel:			../source/%.c | libaxdvk2$(LIBSUFFIX)
						($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

libaxdvk2$(LIBSUFFIX)/%.rel:			libaxdvk2$(LIBSUFFIX)/%.c | libaxdvk2$(LIBSUFFIX)
						($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

libaxdvk2$(LIBSUFFIX).lib:			$(patsubst %.rel,libaxdvk2$(LIBSUFFIX)/%.rel,$(LIBAXDVK2OBJ)) | libaxdvk2$(LIBSUFFIX)
						$(TARGET_AR) -a $@ $(patsubst %.rel,libaxdvk2$(LIBSUFFIX)/%.rel,$(LIBAXDVK2OBJ))

libaxdvk2$(LIBSUFFIX)/lcdu%.c:			../source/io%.c
						(unifdef -DUART=3 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdvk2$(LIBSUFFIX)/lcd2u%.c:			../source/io%.c
						(unifdef -DUART=4 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdvk2$(LIBSUFFIX)/lcdinit.rel:		../source/lcdinit.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdsetpos.rel:		../source/lcdsetpos.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwrstr.rel:		../source/lcdwrstr.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdclear.rel:		../source/lcdclear.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdclrdisp.rel:		../source/lcdclrdisp.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwru16.rel:		../source/lcdwru16.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwru32.rel:		../source/lcdwru32.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwrhexu16.rel:		../source/lcdwrhexu16.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwrhexu32.rel:		../source/lcdwrhexu32.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrnum16.rel:		libaxdvk2$(LIBSUFFIX)/lcduwrnum16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrnum32.rel:		libaxdvk2$(LIBSUFFIX)/lcduwrnum32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrhex16.rel:		libaxdvk2$(LIBSUFFIX)/lcduwrhex16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrhex32.rel:		libaxdvk2$(LIBSUFFIX)/lcduwrhex32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2init.rel:		../source/lcd2init.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2txbuf.rel:		../source/lcd2txbuf.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2wrstr.rel:		../source/lcd2wrstr.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2clrdisp.rel:		../source/lcd2clrdisp.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2setpos.rel:		../source/lcd2setpos.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2clear.rel:		../source/lcd2clear.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2txcmds.rel:		../source/lcd2txcmds.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2txcmdl.rel:		../source/lcd2txcmdl.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2utx.rel:		libaxdvk2$(LIBSUFFIX)/lcd2utx.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2urx.rel:		libaxdvk2$(LIBSUFFIX)/lcd2urx.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu16.rel:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu16.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu32.rel:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu32.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwru16.rel:		libaxdvk2$(LIBSUFFIX)/lcd2uwru16.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwru32.rel:		libaxdvk2$(LIBSUFFIX)/lcd2uwru32.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrnum16.rel:		libaxdvk2$(LIBSUFFIX)/lcd2uwrnum16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrnum32.rel:		libaxdvk2$(LIBSUFFIX)/lcd2uwrnum32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhex16.rel:		libaxdvk2$(LIBSUFFIX)/lcd2uwrhex16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhex32.rel:		libaxdvk2$(LIBSUFFIX)/lcd2uwrhex32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
