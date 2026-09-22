TARGET_MODEL	:= 
TARGET_DEFINES	:= 
ifeq ($(OS),Windows_NT)
TARGET_INSTDIR := "C:/Program Files (x86)/GNU Tools ARM Embedded/5.4 2016q3"
else
TARGET_INSTDIR	:= /usr
endif
TARGET_ASM	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-as
TARGET_LD	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-ld
TARGET_CC	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-gcc
TARGET_AR	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-ar
TARGET_RANLIB	:= $(TARGET_INSTDIR)/bin/arm-none-eabi-ranlib
TARGET_ASMFLAGS	:= -mcpu=cortex-m0plus -mthumb
TARGET_LNKFLAGS	:=
TARGET_ARFLAGS	:= --target=elf32-littlearm 
TARGET_CFLAGS	:= -mcpu=cortex-m0plus -mthumb -fno-common -Os -g -Wall $(LIBDEFINES) -I../source -I../../libmf/source -I../../libmf/source/CMSIS_5/CMSIS/Core/Include -I../../libmf/source/CMSIS_5/Device/ARM/ARMCM0plus/Include

LIBMFCRYPTOOBJ	:= desdec.o desenc.o desencdec.o deskey.o dessbox.o \
		   aessbox.o aesrcon.o aeskey.o aeskey128.o aeskey192.o aeskey256.o 
		   #ax8052cryptoregs.o

LIBBINARIES	:= libmfcrypto.a libmfcryptof2.a

ifeq ($(LIBBINARY),)
all:					$(LIBBINARIES)

.PHONY:					libmfcrypto.a
.PHONY:					libmfcryptof2.a

libmfcrypto.a:
					make LIBBINARY="$@" LIBSUFFIX="" LIBDEFINES="-D__AXM0=1"

libmfcryptof2.a:
					make LIBBINARY="$@" LIBSUFFIX="f2" LIBDEFINES="-D__AXM0F2=1"
else
all:					$(LIBBINARY)
endif

clean:
					rm -rf libmfcrypto libmfcryptof2 $(LIBBINARIES) $(patsubst %.o,%,$(LIBBINARIES)) libmfcryptobinarm.tar.gz

tar:					libmfcryptobinarm.tar.gz

libmfcryptobinarm.tar.gz:		$(LIBBINARIES)
					tar -c -v -z -f $@ $(LIBBINARIES)

libmfcrypto$(LIBSUFFIX):
					[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:				%.o

%.o:					../%.c 
					$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<		

%.S:					../%.c
					$(TARGET_CC) $(TARGET_CFLAGS) -S -o $@ $<

libmfcrypto$(LIBSUFFIX)/%.o:		../source/%.c | libmfcrypto$(LIBSUFFIX)
					$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<

libmfcrypto$(LIBSUFFIX)/%.S:		../source/%.c | libmfcrypto$(LIBSUFFIX)
					$(TARGET_CC) $(TARGET_CFLAGS) -S -o $@ $<

libmfcrypto$(LIBSUFFIX)/%.o:		../source/%.S | libmfcrypto$(LIBSUFFIX)
					$(TARGET_ASM) $(TARGET_ASMFLAGS) -o $@ $<

libmfcrypto$(LIBSUFFIX)/%.o:		libmfcrypto$(LIBSUFFIX)/%.c | libmfcrypto$(LIBSUFFIX)
					$(TARGET_CC) $(TARGET_CFLAGS) -c -o $@ $<

libmfcrypto$(LIBSUFFIX)/%.S:		libmfcrypto$(LIBSUFFIX)/%.c | libmfcrypto$(LIBSUFFIX)
					$(TARGET_CC) $(TARGET_CFLAGS) -S -o $@ $<

libmfcrypto$(LIBSUFFIX)/%.o:		%.S | libmfcrypto$(LIBSUFFIX)
					$(TARGET_ASM) $(TARGET_ASMFLAGS) -o $@ $<

ifneq ($(LIBBINARY),)
$(LIBBINARY):				$(patsubst %.o,libmfcrypto$(LIBSUFFIX)/%.o,$(LIBMFCRYPTOOBJ)) | libmfcrypto$(LIBSUFFIX)
					$(TARGET_AR) $(TARGET_ARFLAGS) -r $@ $(patsubst %.o,libmfcrypto$(LIBSUFFIX)/%.o,$(LIBMFCRYPTOOBJ))
					$(TARGET_RANLIB) $@
endif

libmfcrypto$(LIBSUFFIX)/aessbox.o:	../source/aessbox.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aesrcon.o:	../source/aesrcon.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey.o:	../source/aeskey.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey128.o:	../source/aeskey128.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey192.o:	../source/aeskey192.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey256.o:	../source/aeskey256.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desdec.o:	../source/desdec.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desenc.o:	../source/desenc.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desencdec.o:	../source/desencdec.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/deskey.o:	../source/deskey.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/dessbox.o:	../source/dessbox.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
