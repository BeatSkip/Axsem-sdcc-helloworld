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

LIBAXDSPOBJ	:= cordic16vec2.r51 cordic16vec3.r51 cordic16vec4.r51 cordic16vec5.r51 cordic16vec6.r51 cordic16vec7.r51 \
		   cordic16vec8.r51 cordic16vec9.r51 cordic16vec10.r51 cordic16vec11.r51 cordic16vec12.r51 cordic16vec13.r51 \
		   cordic16vec14.r51 cordic16vec15.r51 \
		   cordic16corevec2.r51 cordic16corevec3.r51 cordic16corevec4.r51 cordic16corevec5.r51 cordic16corevec6.r51 cordic16corevec7.r51 \
		   cordic16corevec8.r51 cordic16corevec9.r51 cordic16corevec10.r51 cordic16corevec11.r51 cordic16corevec12.r51 cordic16corevec13.r51 \
		   cordic16corevec14.r51 cordic16corevec15.r51 \
		   cordic16rot2.r51 cordic16rot3.r51 cordic16rot4.r51 cordic16rot5.r51 cordic16rot6.r51 cordic16rot7.r51 \
		   cordic16rot8.r51 cordic16rot9.r51 cordic16rot10.r51 cordic16rot11.r51 cordic16rot12.r51 cordic16rot13.r51 \
		   cordic16rot14.r51 cordic16rot15.r51 \
		   cordic16corerot2.r51 cordic16corerot3.r51 cordic16corerot4.r51 cordic16corerot5.r51 cordic16corerot6.r51 cordic16corerot7.r51 \
		   cordic16corerot8.r51 cordic16corerot9.r51 cordic16corerot10.r51 cordic16corerot11.r51 cordic16corerot12.r51 cordic16corerot13.r51 \
		   cordic16corerot14.r51 cordic16corerot15.r51 \
		   firxi16xi16.r51 firxi16ci16.r51

BINARIES	:=
LIBBINARIES	:= libaxdsp.r51 libaxdsplarge.r51 \
		   libaxdsp-pli-nlpc-1e16x01.r51 libaxdsp-pli-nlpd-1e16x01.r51 libaxdsp-pli-nlxc-1e16x01.r51 libaxdsp-pli-nlxd-1e16x01.r51 \
		   libaxdsp-pli-nsdc-1e16x01.r51 libaxdsp-pli-nsdd-1e16x01.r51 libaxdsp-pli-nsic-1e16x01.r51 libaxdsp-pli-nsid-1e16x01.r51 libaxdsp-pli-nsoc-1e16x01.r51 libaxdsp-pli-nsod-1e16x01.r51 \
		   libaxdsp-pli-ntdc-1e16x01.r51 libaxdsp-pli-ntdd-1e16x01.r51 libaxdsp-pli-ntic-1e16x01.r51 libaxdsp-pli-ntid-1e16x01.r51 libaxdsp-pli-ntoc-1e16x01.r51 libaxdsp-pli-ntod-1e16x01.r51

ifeq ($(LIBSUFFIX),)
all:				$(LIBBINARIES) $(BINARIES) $(patsubst %.omf,%.cdb,$(BINARIES)) $(patsubst %.omf,%.ihx,$(BINARIES))
else
all:				libaxdsp$(LIBSUFFIX).r51
endif

clean:
				rm -rf *.lnk $(LIBBINARIES) $(patsubst %.r51,%,$(LIBBINARIES)) libaxdspbiniar.tar.gz

tar:				libaxdspbiniar.tar.gz

libaxdspbiniar.tar.gz:		$(LIBBINARIES)
				tar -c -v -z -f $@ $(LIBBINARIES)

ifeq ($(LIBSUFFIX),)
.PHONY: libaxdsplarge.r51
.PHONY: libaxdsp-pli-nlpc-1e16x01.r51
.PHONY: libaxdsp-pli-nlpd-1e16x01.r51
.PHONY: libaxdsp-pli-nlxc-1e16x01.r51
.PHONY: libaxdsp-pli-nlxd-1e16x01.r51
.PHONY: libaxdsp-pli-nsdc-1e16x01.r51
.PHONY: libaxdsp-pli-nsdd-1e16x01.r51
.PHONY: libaxdsp-pli-nsic-1e16x01.r51
.PHONY: libaxdsp-pli-nsid-1e16x01.r51
.PHONY: libaxdsp-pli-nsoc-1e16x01.r51
.PHONY: libaxdsp-pli-nsod-1e16x01.r51
.PHONY: libaxdsp-pli-ntdc-1e16x01.r51
.PHONY: libaxdsp-pli-ntdd-1e16x01.r51
.PHONY: libaxdsp-pli-ntic-1e16x01.r51
.PHONY: libaxdsp-pli-ntid-1e16x01.r51
.PHONY: libaxdsp-pli-ntoc-1e16x01.r51
.PHONY: libaxdsp-pli-ntod-1e16x01.r51

libaxdsplarge.r51:
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

libaxdsp-pli-nlpc-1e16x01.r51:
	make TARGET_MODEL="--data_model=large --calling_convention=pdata_reentrant --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=2 -D__CALLING_CONVENTION__=3" LIBSUFFIX=-pli-nlpc-1e16x01

libaxdsp-pli-nlpd-1e16x01.r51:
	make TARGET_MODEL="--data_model=large --calling_convention=pdata_reentrant --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=2 -D__CALLING_CONVENTION__=3" LIBSUFFIX=-pli-nlpd-1e16x01

libaxdsp-pli-nlxc-1e16x01.r51:
	make TARGET_MODEL="--data_model=large --calling_convention=xdata_reentrant --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=2 -D__CALLING_CONVENTION__=4" LIBSUFFIX=-pli-nlxc-1e16x01

libaxdsp-pli-nlxd-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=large --calling_convention=xdata_reentrant --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=2 -D__CALLING_CONVENTION__=4" LIBSUFFIX=-pli-nlxd-1e16x01

libaxdsp-pli-nsdc-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=data_overlay --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=0" LIBSUFFIX=-pli-nsdc-1e16x01

libaxdsp-pli-nsdd-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=data_overlay --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=0" LIBSUFFIX=-pli-nsdd-1e16x01

libaxdsp-pli-nsic-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=idata_reentrant --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=2" LIBSUFFIX=-pli-nsic-1e16x01

libaxdsp-pli-nsid-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=idata_reentrant --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=2" LIBSUFFIX=-pli-nsid-1e16x01

libaxdsp-pli-nsoc-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=idata_overlay --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=1" LIBSUFFIX=-pli-nsoc-1e16x01

libaxdsp-pli-nsod-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=small --calling_convention=idata_overlay --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=1 -D__CALLING_CONVENTION__=1" LIBSUFFIX=-pli-nsod-1e16x01

libaxdsp-pli-ntdc-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=data_overlay --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=0" LIBSUFFIX=-pli-ntdc-1e16x01

libaxdsp-pli-ntdd-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=data_overlay --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=0" LIBSUFFIX=-pli-ntdd-1e16x01

libaxdsp-pli-ntic-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=idata_reentrant --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=2" LIBSUFFIX=-pli-ntic-1e16x01

libaxdsp-pli-ntid-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=idata_reentrant --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=2" LIBSUFFIX=-pli-ntid-1e16x01

libaxdsp-pli-ntoc-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=idata_overlay --place_constants=code" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=1" LIBSUFFIX=-pli-ntoc-1e16x01

libaxdsp-pli-ntod-1e16x01.r51:		      			      
	make TARGET_MODEL="--data_model=tiny --calling_convention=idata_overlay --place_constants=data" TARGET_DEFINES="-D__DATA_MODEL__=0 -D__CALLING_CONVENTION__=1" LIBSUFFIX=-pli-ntod-1e16x01

endif

libaxdsp$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.r51 %.omf %.ihx %.cdb

%.r51:				../%.c
				$(TARGET_CC) $(TARGET_CFLAGS) -o $@ -lC `basename $@ .r51`.lst $<

%.omf %.ihx %.cdb:		%.r51 libaxdsp$(LIBSUFFIX).r51
				(libdir=`pwd`; dn=`dirname $<`/; fn=`basename $< .r51`; cd $${dn}; $(TARGET_LD) -V $(TARGET_LNKFLAGS) -L$${libdir} -llibaxdsp$(LIBSUFFIX) $${fn}.r51; x=$$?; mv $${fn} $${fn}.omf; exit $${x})

libaxdsp$(LIBSUFFIX)/%.r51:		../source/%.c | libaxdsp$(LIBSUFFIX)
					$(TARGET_CC) $(TARGET_CFLAGS) -o $@ -lC libaxdsp$(LIBSUFFIX)/`basename $@ .r51`.lst $<

libaxdsp$(LIBSUFFIX)/%.r51:		libaxdsp$(LIBSUFFIX)/%.c | libaxdsp$(LIBSUFFIX)
					$(TARGET_CC) $(TARGET_CFLAGS) -o $@ -lC libaxdsp$(LIBSUFFIX)/`basename $@ .r51`.lst $<

libaxdsp$(LIBSUFFIX).r51:		$(patsubst %.r51,libaxdsp$(LIBSUFFIX)/%.r51,$(LIBAXDSPOBJ)) | libaxdsp$(LIBSUFFIX)
					$(TARGET_AR) -o $@ $(patsubst %.r51,libaxdsp$(LIBSUFFIX)/%.r51,$(LIBAXDSPOBJ))

libaxdsp$(LIBSUFFIX)/cordic16vec%.c:		../source/cordic16vec.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16corevec%.c:	../source/cordic16corevec.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16rot%.c:		../source/cordic16rot.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16corerot%.c:	../source/cordic16corerot.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16vec2.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec3.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec4.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec5.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec6.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec7.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec8.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec9.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec10.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec11.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec12.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec13.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec14.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec15.r51:		libaxdsp$(LIBSUFFIX)/cordic16vec15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec2.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec3.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec4.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec5.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec6.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec7.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec8.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec9.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec10.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec11.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec12.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec13.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec14.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec15.r51:	libaxdsp$(LIBSUFFIX)/cordic16corevec15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot2.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot3.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot4.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot5.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot6.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot7.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot8.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot9.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot10.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot11.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot12.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot13.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot14.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot15.r51:		libaxdsp$(LIBSUFFIX)/cordic16rot15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot2.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot3.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot4.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot5.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot6.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot7.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot8.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot9.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot10.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot11.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot12.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot13.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot14.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot15.r51:	libaxdsp$(LIBSUFFIX)/cordic16corerot15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)

libaxdsp$(LIBSUFFIX)/firxi16xi16.r51:		../source/firxi16xi16.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/firxi16ci16.r51:		../source/firxi16ci16.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
