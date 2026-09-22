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

LIBMFCRYPTOOBJ	:= aessbox.rel aesrcon.rel aeskey.rel aeskey128.rel aeskey192.rel aeskey256.rel \
		   desdec.rel desenc.rel desencdec.rel deskey.rel dessbox.rel \
		   ax8052cryptoregs.rel

BINARIES	:=

all:				libmfcrypto.lib libmfcryptolarge.lib $(BINARIES) $(patsubst %.omf,%.cdb,$(BINARIES)) $(patsubst %.omf,%.ihx,$(BINARIES))

clean:
				rm -rf *.lnk libmfcrypto.lib libmfcrypto libmfcryptolarge.lib libmfcryptolarge libmfcryptobinsdcc.tar.gz libmfcryptosrc.tar.gz

tar:				libmfcryptobinsdcc.tar.gz libmfcryptosrc.tar.gz

libmfcryptobinsdcc.tar.gz:	libmfcrypto.lib libmfcryptolarge.lib
				tar -c -v -z -f $@ libmfcrypto.lib libmfcryptolarge.lib

libmfcryptosrc.tar.gz:
				cd .. ; \
				tar -c -v -z -f buildsdcc/$@ build*/Makefile source/*.c source/*.h doc/*.pdf COPYING

ifeq ($(LIBSUFFIX),)
libmfcryptolarge.lib:
				make TARGET_MODEL=--model-large LIBSUFFIX=large
endif

libmfcrypto$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.rel %.omf %.ihx %.cdb

%.rel:				../%.c
				($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

%.omf %.ihx %.cdb:		%.rel libmfcrypto$(LIBSUFFIX).lib
				(libdir=`pwd`; dn=`dirname $<`/; fn=`basename $< .rel`; cd $${dn}; $(TARGET_LD) -V $(TARGET_LNKFLAGS) -L$${libdir} -llibmfcrypto$(LIBSUFFIX) $${fn}.rel; x=$$?; mv $${fn} $${fn}.omf; exit $${x})

libmfcrypto$(LIBSUFFIX)/%.rel:		../source/%.c | libmfcrypto$(LIBSUFFIX)
					($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

libmfcrypto$(LIBSUFFIX).lib:		$(patsubst %.rel,libmfcrypto$(LIBSUFFIX)/%.rel,$(LIBMFCRYPTOOBJ)) | libmfcrypto$(LIBSUFFIX)
					$(TARGET_AR) -a $@ $(patsubst %.rel,libmfcrypto$(LIBSUFFIX)/%.rel,$(LIBMFCRYPTOOBJ))

libmfcrypto$(LIBSUFFIX)/aessbox.rel:	../source/aessbox.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aesrcon.rel:	../source/aesrcon.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey.rel:	../source/aeskey.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey128.rel:	../source/aeskey128.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey192.rel:	../source/aeskey192.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey256.rel:	../source/aeskey256.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desdec.rel:	../source/desdec.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desenc.rel:	../source/desenc.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desencdec.rel:	../source/desencdec.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/deskey.rel:	../source/deskey.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/dessbox.rel:	../source/dessbox.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/ax8052cryptoregs.rel:	../source/ax8052cryptoregs.c ../source/ax8052crypto.h | libmfcrypto$(LIBSUFFIX)
