TARGET_ASM	:= sdcc-asx8051
TARGET_LD	:= sdcc-sdcc
TARGET_CC	:= sdcc-sdcc
TARGET_AR	:= sdcc-sdcclib
TARGET_MODEL	:= --model-small
TARGET_ASMFLAGS	:= -xlosg
TARGET_LNKFLAGS	:= -mmcs51 --debug --code-loc 0x0000 --code-size 0x2000 --xram-loc 0x0000 --xram-size 0x100 $(TARGET_MODEL) --data-loc 0x08
TARGET_CFLAGS	:= --debug -I../source -I../../libmf/source $(TARGET_LNKFLAGS)
LIBSUFFIX	:=

LIBAXDSPOBJ	:= cordic16vec2.rel cordic16vec3.rel cordic16vec4.rel cordic16vec5.rel cordic16vec6.rel cordic16vec7.rel \
		   cordic16vec8.rel cordic16vec9.rel cordic16vec10.rel cordic16vec11.rel cordic16vec12.rel cordic16vec13.rel \
		   cordic16vec14.rel cordic16vec15.rel \
		   cordic16corevec2.rel cordic16corevec3.rel cordic16corevec4.rel cordic16corevec5.rel cordic16corevec6.rel cordic16corevec7.rel \
		   cordic16corevec8.rel cordic16corevec9.rel cordic16corevec10.rel cordic16corevec11.rel cordic16corevec12.rel cordic16corevec13.rel \
		   cordic16corevec14.rel cordic16corevec15.rel \
		   cordic16rot2.rel cordic16rot3.rel cordic16rot4.rel cordic16rot5.rel cordic16rot6.rel cordic16rot7.rel \
		   cordic16rot8.rel cordic16rot9.rel cordic16rot10.rel cordic16rot11.rel cordic16rot12.rel cordic16rot13.rel \
		   cordic16rot14.rel cordic16rot15.rel \
		   cordic16corerot2.rel cordic16corerot3.rel cordic16corerot4.rel cordic16corerot5.rel cordic16corerot6.rel cordic16corerot7.rel \
		   cordic16corerot8.rel cordic16corerot9.rel cordic16corerot10.rel cordic16corerot11.rel cordic16corerot12.rel cordic16corerot13.rel \
		   cordic16corerot14.rel cordic16corerot15.rel \
		   firxi16xi16.rel firxi16ci16.rel

BINARIES	:=

all:				libaxdsp.lib libaxdsplarge.lib $(BINARIES) $(patsubst %.omf,%.cdb,$(BINARIES)) $(patsubst %.omf,%.ihx,$(BINARIES))

clean:
				rm -rf *.lnk libaxdsp.lib libaxdsp libaxdsplarge.lib libaxdsplarge libaxdspbinsdcc.tar.gz libaxdspsrc.tar.gz

tar:				libaxdspbinsdcc.tar.gz libaxdspsrc.tar.gz

libaxdspbinsdcc.tar.gz:		libaxdsp.lib libaxdsplarge.lib
				tar -c -v -z -f $@ libaxdsp.lib libaxdsplarge.lib

libaxdspsrc.tar.gz:
				cd .. ; \
				tar -c -v -z -f buildsdcc/$@ build*/Makefile source/*.c source/*.h doc/LibAXDSP.pdf

ifeq ($(LIBSUFFIX),)
libaxdsplarge.lib:
				make TARGET_MODEL=--model-large LIBSUFFIX=large
endif

libaxdsp$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.rel %.omf %.ihx %.cdb

%.rel:				../%.c
				($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

%.omf %.ihx %.cdb:		%.rel libaxdsp$(LIBSUFFIX).lib
				(libdir=`pwd`; dn=`dirname $<`/; fn=`basename $< .rel`; cd $${dn}; $(TARGET_LD) -V $(TARGET_LNKFLAGS) -L$${libdir} -llibaxdsp$(LIBSUFFIX) $${fn}.rel; x=$$?; mv $${fn} $${fn}.omf; exit $${x})

libaxdsp$(LIBSUFFIX)/%.rel:			../source/%.c | libaxdsp$(LIBSUFFIX)
						($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

libaxdsp$(LIBSUFFIX)/%.rel:			libaxdsp$(LIBSUFFIX)/%.c | libaxdsp$(LIBSUFFIX)
						($(TARGET_CC) -c $(TARGET_CFLAGS) -o $@ $<; x=$$?; dn=`dirname $<`/; fn=`basename $< .c`; rm -f $${dn}$${fn}.asm ; exit $${x})

libaxdsp$(LIBSUFFIX).lib:			$(patsubst %.rel,libaxdsp$(LIBSUFFIX)/%.rel,$(LIBAXDSPOBJ)) | libaxdsp$(LIBSUFFIX)
						$(TARGET_AR) -a $@ $(patsubst %.rel,libaxdsp$(LIBSUFFIX)/%.rel,$(LIBAXDSPOBJ))

libaxdsp$(LIBSUFFIX)/cordic16vec%.c:		../source/cordic16vec.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16corevec%.c:	../source/cordic16corevec.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16rot%.c:		../source/cordic16rot.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16corerot%.c:	../source/cordic16corerot.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16vec2.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec3.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec4.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec5.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec6.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec7.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec8.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec9.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec10.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec11.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec12.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec13.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec14.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec15.rel:		libaxdsp$(LIBSUFFIX)/cordic16vec15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec2.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec3.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec4.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec5.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec6.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec7.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec8.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec9.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec10.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec11.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec12.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec13.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec14.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec15.rel:	libaxdsp$(LIBSUFFIX)/cordic16corevec15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot2.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot3.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot4.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot5.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot6.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot7.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot8.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot9.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot10.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot11.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot12.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot13.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot14.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot15.rel:		libaxdsp$(LIBSUFFIX)/cordic16rot15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot2.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot3.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot4.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot5.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot6.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot7.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot8.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot9.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot10.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot11.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot12.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot13.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot14.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot15.rel:	libaxdsp$(LIBSUFFIX)/cordic16corerot15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)

libaxdsp$(LIBSUFFIX)/firxi16xi16.rel:		../source/firxi16xi16.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/firxi16ci16.rel:		../source/firxi16ci16.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
