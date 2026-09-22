TARGET_MODEL	:= --calling_convention=data_overlay --data_model=small --place_constants=code
TARGET_DEFINES	:= -D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=0
LIBSUFFIX	:=
#TARGET_INSTDIR	:= C:/EDA/IAR\ Systems/Embedded\ Workbench\ 6.0\ Kickstart/8051
#TARGET_INSTDIR	:= C:/EDA/IAR\ Systems/Embedded\ Workbench\ 6.5/8051
#TARGET_INSTDIR	:= C:/Program\ Files\ \(x86\)/IAR\ Systems/Embedded\ Workbench\ 6.5/8051
TARGET_INSTDIR	:= C:/Program\ Files\ \(x86\)/IAR\ Systems/Embedded\ Workbench\ 7.3/8051
TARGET_ASM	:= $(TARGET_INSTDIR)/bin/a8051.exe
TARGET_LD	:= $(TARGET_INSTDIR)/bin/xlink.exe
TARGET_CC	:= $(TARGET_INSTDIR)/bin/icc8051.exe
TARGET_AR	:= $(TARGET_INSTDIR)/bin/xar.exe
TARGET_ASMFLAGS	:= -v0 -D__CORE__=1 -D__CODE_MODEL__=1 -D__NUMBER_OF_DPTRS__=1 $(TARGET_DEFINES) -s+ -M"<>" -r -w+ -I$(TARGET_INSTDIR)/src/lib
TARGET_LNKFLAGS	:= -D_NR_OF_BANKS=0 -D_CODEBANK_END=0 -D_CODEBANK_START=0 -I$(TARGET_INSTDIR)/config -e_small_write=_formatted_write -e_medium_read=_formatted_read -Faomf8051 -Y0 -I$(TARGET_INSTDIR)/lib -f $(TARGET_INSTDIR)/config/devices/_generic/lnk51ew_plain.xcl -D?DPMASK=0x01 -D_NR_OF_VIRTUAL_REGISTERS=8 -D?DPS=0x85 -D?PBANK=0xD9 -D?DPL1=0x84 -D?DPH1=0x85 -s __program_start $(TARGET_INSTDIR)/LIB/CLIB/cl-pli-nsdc-2e16inc.r51 -D_IDATA_STACK_SIZE=0x40 -D_EXTENDED_STACK_START=0x00 -D_EXTENDED_STACK_SIZE=0x00 -D_PDATA_STACK_SIZE=0x80 -D_XDATA_STACK_SIZE=0xEFF -D_XDATA_HEAP_SIZE=0xFF -D_FAR_HEAP_SIZE=0xFFF -D_HUGE_HEAP_SIZE=0xFFF -D_FAR22_HEAP_SIZE=0xFFF 
TARGET_CFLAGS	:= -e --no_unroll --no_inline --no_tbaa --debug --core=plain --dptr=16,1,separate,xor $(TARGET_MODEL) --code_model=near --nr_virtual_regs 8 -Om --library_module --diag_suppress=Pa050 -I../source -I../../libmf/source

LIBMFCRYPTOOBJ	:= aessbox.r51 aesrcon.r51 aeskey.r51 aeskey128.r51 aeskey192.r51 aeskey256.r51 \
		   desdec.r51 desenc.r51 desencdec.r51 deskey.r51 dessbox.r51 \
		   ax8052cryptoregs.r51

BINARIES	:=
LIBBINARIES	:= libmfcrypto.r51 libmfcryptolarge.r51 \
		   libmfcrypto-pli-nlpc-1e16x01.r51 libmfcrypto-pli-nlpd-1e16x01.r51 libmfcrypto-pli-nlxc-1e16x01.r51 libmfcrypto-pli-nlxd-1e16x01.r51 \
		   libmfcrypto-pli-nsdc-1e16x01.r51 libmfcrypto-pli-nsdd-1e16x01.r51 libmfcrypto-pli-nsic-1e16x01.r51 libmfcrypto-pli-nsid-1e16x01.r51 libmfcrypto-pli-nsoc-1e16x01.r51 libmfcrypto-pli-nsod-1e16x01.r51 \
		   libmfcrypto-pli-ntdc-1e16x01.r51 libmfcrypto-pli-ntdd-1e16x01.r51 libmfcrypto-pli-ntic-1e16x01.r51 libmfcrypto-pli-ntid-1e16x01.r51 libmfcrypto-pli-ntoc-1e16x01.r51 libmfcrypto-pli-ntod-1e16x01.r51

ifeq ($(LIBSUFFIX),)
all:				$(LIBBINARIES) $(BINARIES) $(patsubst %.omf,%.cdb,$(BINARIES)) $(patsubst %.omf,%.ihx,$(BINARIES))
else
all:				libmfcrypto$(LIBSUFFIX).r51
endif

clean:
				rm -rf *.lnk $(LIBBINARIES) $(patsubst %.r51,%,$(LIBBINARIES)) libmfcryptobiniar.tar.gz

tar:				libmfcryptobiniar.tar.gz

libmfcryptobiniar.tar.gz:	$(LIBBINARIES)
				tar -c -v -z -f $@ $(LIBBINARIES)

ifeq ($(LIBSUFFIX),)
.PHONY: libmfcryptolarge.r51
.PHONY: libmfcrypto-pli-nlpc-1e16x01.r51
.PHONY: libmfcrypto-pli-nlpd-1e16x01.r51
.PHONY: libmfcrypto-pli-nlxc-1e16x01.r51
.PHONY: libmfcrypto-pli-nlxd-1e16x01.r51
.PHONY: libmfcrypto-pli-nsdc-1e16x01.r51
.PHONY: libmfcrypto-pli-nsdd-1e16x01.r51
.PHONY: libmfcrypto-pli-nsic-1e16x01.r51
.PHONY: libmfcrypto-pli-nsid-1e16x01.r51
.PHONY: libmfcrypto-pli-nsoc-1e16x01.r51
.PHONY: libmfcrypto-pli-nsod-1e16x01.r51
.PHONY: libmfcrypto-pli-ntdc-1e16x01.r51
.PHONY: libmfcrypto-pli-ntdd-1e16x01.r51
.PHONY: libmfcrypto-pli-ntic-1e16x01.r51
.PHONY: libmfcrypto-pli-ntid-1e16x01.r51
.PHONY: libmfcrypto-pli-ntoc-1e16x01.r51
.PHONY: libmfcrypto-pli-ntod-1e16x01.r51

libmfcryptolarge.r51:
				make TARGET_MODEL="--calling_convention=pdata_reentrant --data_model=large --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=2 -D__CALLING_CONVENTION__=3" LIBSUFFIX=large

# name format: -pli-n(1)(2)(3)-1e16x01
# page 152
# (1): data model
#   t - --data_model=tiny         -D__DATA_MODEL__=0
#   s - --data_model=small        -D__DATA_MODEL__=1
#   l - --data_model=large        -D__DATA_MODEL__=2
#   g - --data_model=generic      -D__DATA_MODEL__=3
#   j - --data_model=far_generic  -D__DATA_MODEL__=5
#   f - --data_model=far          -D__DATA_MODEL__=4
# (2): calling convention
#   d - --calling_convention=data_overlay         -D__CALLING_CONVENTION__=0
#   o - --calling_convention=idata_overlay        -D__CALLING_CONVENTION__=1
#   i - --calling_convention=idata_reentrant      -D__CALLING_CONVENTION__=2
#   p - --calling_convention=pdata_reentrant      -D__CALLING_CONVENTION__=3
#   x - --calling_convention=xdata_reentrant      -D__CALLING_CONVENTION__=4
#   e - --calling_convention=ext_stack_reentrant  -D__CALLING_CONVENTION__=5
# (3): constant location
#   c -  --place_constants=code
#   d -  --place_constants=data

libmfcrypto-pli-nlpc-1e16x01.r51:
	make TARGET_MODEL="--data_model=large --calling_convention=pdata_reentrant --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=2 -D__CALLING_CONVENTION__=3" LIBSUFFIX=-pli-nlpc-1e16x01

libmfcrypto-pli-nlpd-1e16x01.r51:
	make TARGET_MODEL="--data_model=large --calling_convention=pdata_reentrant --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=2 -D__CALLING_CONVENTION__=3" LIBSUFFIX=-pli-nlpd-1e16x01

libmfcrypto-pli-nlxc-1e16x01.r51:
	make TARGET_MODEL="--data_model=large --calling_convention=xdata_reentrant --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=2 -D__CALLING_CONVENTION__=4" LIBSUFFIX=-pli-nlxc-1e16x01

libmfcrypto-pli-nlxd-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=large --calling_convention=xdata_reentrant --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=2 -D__CALLING_CONVENTION__=4" LIBSUFFIX=-pli-nlxd-1e16x01

libmfcrypto-pli-nsdc-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=data_overlay --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=0" LIBSUFFIX=-pli-nsdc-1e16x01

libmfcrypto-pli-nsdd-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=data_overlay --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=0" LIBSUFFIX=-pli-nsdd-1e16x01

libmfcrypto-pli-nsic-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=idata_reentrant --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=2" LIBSUFFIX=-pli-nsic-1e16x01

libmfcrypto-pli-nsid-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=idata_reentrant --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=2" LIBSUFFIX=-pli-nsid-1e16x01

libmfcrypto-pli-nsoc-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=idata_overlay --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=1" LIBSUFFIX=-pli-nsoc-1e16x01

libmfcrypto-pli-nsod-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=idata_overlay --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=1" LIBSUFFIX=-pli-nsod-1e16x01

libmfcrypto-pli-ntdc-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=data_overlay --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=0" LIBSUFFIX=-pli-ntdc-1e16x01

libmfcrypto-pli-ntdd-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=data_overlay --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=0" LIBSUFFIX=-pli-ntdd-1e16x01

libmfcrypto-pli-ntic-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=idata_reentrant --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=2" LIBSUFFIX=-pli-ntic-1e16x01

libmfcrypto-pli-ntid-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=idata_reentrant --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=2" LIBSUFFIX=-pli-ntid-1e16x01

libmfcrypto-pli-ntoc-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=idata_overlay --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=1" LIBSUFFIX=-pli-ntoc-1e16x01

libmfcrypto-pli-ntod-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=idata_overlay --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=1" LIBSUFFIX=-pli-ntod-1e16x01

endif

libmfcrypto$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.r51 %.omf %.ihx %.cdb

%.r51:				../%.c
				$(TARGET_CC) $(TARGET_CFLAGS) -o $@ -lC `basename $@ .r51`.lst $<

%.omf %.ihx %.cdb:		%.r51 libmfcrypto$(LIBSUFFIX).r51
				(libdir=`pwd`; dn=`dirname $<`/; fn=`basename $< .r51`; cd $${dn}; $(TARGET_LD) -V $(TARGET_LNKFLAGS) -L$${libdir} -llibmfcrypto$(LIBSUFFIX) $${fn}.r51; x=$$?; mv $${fn} $${fn}.omf; exit $${x})

libmfcrypto$(LIBSUFFIX)/%.r51:		../source/%.c | libmfcrypto$(LIBSUFFIX)
					$(TARGET_CC) $(TARGET_CFLAGS) -o $@ -lC libmfcrypto$(LIBSUFFIX)/`basename $@ .r51`.lst $<

libmfcrypto$(LIBSUFFIX).r51:		$(patsubst %.r51,libmfcrypto$(LIBSUFFIX)/%.r51,$(LIBMFCRYPTOOBJ)) | libmfcrypto$(LIBSUFFIX)
					$(TARGET_AR) -o $@ $(patsubst %.r51,libmfcrypto$(LIBSUFFIX)/%.r51,$(LIBMFCRYPTOOBJ))

libmfcrypto$(LIBSUFFIX)/aessbox.r51:	../source/aessbox.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aesrcon.r51:	../source/aesrcon.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey.r51:	../source/aeskey.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey128.r51:	../source/aeskey128.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey192.r51:	../source/aeskey192.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/aeskey256.r51:	../source/aeskey256.c ../source/aes.h ../source/libmfaes.h ../../libmf/source/libmftypes.h ../source/ax8052crypto.h ../../libmf/source/axcompiler.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desdec.r51:	../source/desdec.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desenc.r51:	../source/desenc.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/desencdec.r51:	../source/desencdec.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/deskey.r51:	../source/deskey.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/dessbox.r51:	../source/dessbox.c ../source/des.h ../source/libmfdes.h ../../libmf/source/libmftypes.h | libmfcrypto$(LIBSUFFIX)
libmfcrypto$(LIBSUFFIX)/ax8052cryptoregs.r51:	../source/ax8052cryptoregs.c ../source/ax8052crypto.h | libmfcrypto$(LIBSUFFIX)
