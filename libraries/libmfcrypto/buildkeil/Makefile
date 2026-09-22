TARGET_MODEL	:= SMALL
LIBSUFFIX	:=
KEILPATH	:= C:/EDA/Keil
C51INC		:= $(KEILPATH)/C51/INC
C51LIB		:= $(KEILPATH)/C51/LIB
C51FLAGS	:= OBJECTEXTEND $(TARGET_MODEL) DEBUG INCDIR "($(shell cygpath -w ../source);$(shell cygpath -w ../../libmf/source))"
A51OPT		:= "SET ($(TARGET_MODEL))" EP DEBUG
L51OPT		:= "RAMSIZE(256) XDATA(0x0-0x1FFF) CODE(0x0-0xFFFF)"
CPU_TYPE	:= 8052AH
CPU_VENDOR	:= Intel
CPU_XTAL	:= 0x01312D00

LIBMFCRYPTOOBJ	:= aessbox.obj aesrcon.obj aeskey.obj aeskey128.obj aeskey192.obj aeskey256.obj \
		   desdec.obj desenc.obj desencdec.obj deskey.obj dessbox.obj \
		   ax8052cryptoregs.obj

BINARIES	:=

comma		:= ,
empty		:=
space		:= $(empty) $(empty)

all:				libmfcrypto.lib libmfcryptolarge.lib $(BINARIES) $(patsubst %.omf,%.hex,$(BINARIES))

clean:
				rm -rf LIBMFCRYPTO.LIB libmfcrypto.lib libmfcrypto LIBMFCRYPTOLARGE.LIB libmfcryptolarge.lib libmfcryptolarge libmfcryptobinkeil.tar.gz

tar:				libmfcryptobinkeil.tar.gz

libmfcryptobinkeil.tar.gz:
				[ -f LIBMFCRYPTO.LIB ] && mv LIBMFCRYPTO.LIB libmfcrypto.lib ; \
				[ -f LIBMFCRYPTOLARGE.LIB ] && mv LIBMFCRYPTOLARGE.LIB libmfcryptolarge.lib ; \
				tar -c -v -z -f $@ libmfcrypto.lib libmfcryptolarge.lib

ifeq ($(LIBSUFFIX),)
libmfcryptolarge.lib:
				make TARGET_MODEL=LARGE LIBSUFFIX=large
endif

libmfcrypto$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.src %.obj %.omf

%.obj:				%.src
				$(KEILPATH)/C51/BIN/A51.EXE "$(shell cygpath -w $<)" "PR($(shell cygpath -w $(patsubst %.obj,%.ls1,$@)))" $(A51OPT)

%.src:				%.src1
				./fixmodname.pl $@ < $< > $@

%.omf:				%.obj libmfcrypto$(LIBSUFFIX).lib $(shell cygpath -u $(C51LIB)/C51S.LIB)
				($(KEILPATH)/C51/BIN/BL51.EXE "$(subst $(space),$(comma),$(foreach fn,$^,$(shell cygpath -w $(fn))))" TO "$(shell cygpath -w $@)" $(L51OPT); x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

%.hex:				%.omf
				$(KEILPATH)/C51/BIN/OH51.EXE "$(shell cygpath -w $<)" HEXFILE "($(shell cygpath -w $@))"

libmfcrypto$(LIBSUFFIX)/%.src:		../source/%.c | libmfcrypto$(LIBSUFFIX)
					($(KEILPATH)/C51/BIN/C51.EXE "$(shell cygpath -w $<)" $(C51FLAGS) SRC "($(shell cygpath -w $@))" PR "($(shell cygpath -w $(patsubst %.src,%.lst,$@)))"; x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

libmfcrypto$(LIBSUFFIX).lib:		$(patsubst %.obj,libmfcrypto$(LIBSUFFIX)/%.obj,$(LIBMFCRYPTOOBJ)) | libmfcrypto$(LIBSUFFIX)
					$(KEILPATH)/C51/BIN/LIB51.EXE TRANSFER "$(subst $(space),$(comma),$(foreach fn,$(patsubst %.obj,libmfcrypto$(LIBSUFFIX)/%.obj,$(LIBMFCRYPTOOBJ)),$(shell cygpath -w $(fn))))" TO $@

libmfcrypto$(LIBSUFFIX)/aessbox.src:	../source/aessbox.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aesrcon.src:	../source/aesrcon.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey.src:	../source/aeskey.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey128.src:	../source/aeskey128.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey192.src:	../source/aeskey192.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey256.src:	../source/aeskey256.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desdec.src:	../source/desdec.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desenc.src:	../source/desenc.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desencdec.src:	../source/desencdec.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/deskey.src:	../source/deskey.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/dessbox.src:	../source/dessbox.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/ax8052cryptoregs.src:	../source/ax8052cryptoregs.c ../source/ax8052crypto.h | libmfcrypto$(LIBSUFFIX)
