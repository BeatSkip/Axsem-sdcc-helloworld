TARGET_ASM	:= sdcc-asx8051
TARGET_LD	:= sdcc-sdcc
TARGET_CC	:= sdcc-sdcc
TARGET_AR	:= sdcc-sdcclib
TARGET_MODEL	:= --model-small
TARGET_ASMFLAGS	:= -xlosg
TARGET_LNKFLAGS	:= -mmcs51 --debug --code-loc 0x0000 --code-size 0x2000 --xram-loc 0x0000 --xram-size 0x100 $(TARGET_MODEL) --data-loc 0x08
TARGET_CFLAGS	:= --debug -I../source -I../../libmf/source $(TARGET_LNKFLAGS)
LIBSUFFIX	:=

LIBAX5042OBJ	:= pllrange.rel

BINARIES	:=

all:				libax5042.lib libax5042large.lib $(BINARIES) $(patsubst %.omf,%.cdb,$(BINARIES)) $(patsubst %.omf,%.ihx,$(BINARIES))

clean:
				rm -rf *.lnk libax5042.lib libax5042 libax5042large.lib libax5042large libax5042binsdcc.tar.gz libax5042src.tar.gz

tar:				libax5042binsdcc.tar.gz libax5042src.tar.gz

libax5042binsdcc.tar.gz:	libax5042.lib libax5042large.lib
				tar -c -v -z -f $@ libax5042.lib libax5042large.lib

libax5042src.tar.gz:
				cd .. ; \
				tar -c -v -z -f buildsdcc/$@ build*/Makefile source/*.c source/*.h doc/LibAX5042.pdf

ifeq ($(LIBSUFFIX),)
libax5042large.lib:
				make TARGET_MODEL=--model-large LIBSUFFIX=large
endif

libax5042$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.rel %.omf %.ihx %.cdb

%.rel:				../%.c
				($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

%.omf %.ihx %.cdb:		%.rel libax5042$(LIBSUFFIX).lib
				(libdir=`pwd`; dn=`dirname $<`/; fn=`basename $< .rel`; cd $${dn}; $(TARGET_LD) -V $(TARGET_LNKFLAGS) -L$${libdir} -llibax5042$(LIBSUFFIX) $${fn}.rel; x=$$?; mv $${fn} $${fn}.omf; exit $${x})

libax5042$(LIBSUFFIX)/%.rel:			../source/%.c | libax5042$(LIBSUFFIX)
						($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

libax5042$(LIBSUFFIX).lib:			$(patsubst %.rel,libax5042$(LIBSUFFIX)/%.rel,$(LIBAX5042OBJ)) | libax5042$(LIBSUFFIX)
						$(TARGET_AR) -a $@ $(patsubst %.rel,libax5042$(LIBSUFFIX)/%.rel,$(LIBAX5042OBJ))

libax5042$(LIBSUFFIX)/pllrange.rel:		../source/pllrange.c ../source/libax5042.h | libax5042$(LIBSUFFIX)
