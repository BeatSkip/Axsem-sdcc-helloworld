TARGET_MODEL	:= SMALL
LIBSUFFIX	:=
KEILPATH	:= C:/EDA/Keil
C51INC		:= $(KEILPATH)/C51/INC
C51LIB		:= $(KEILPATH)/C51/LIB
C51FLAGS	:= OMF2 OBJECTADVANCED $(TARGET_MODEL) DEBUG INCDIR "($(shell cygpath -w ../source),$(shell cygpath -w ../../libmf/source))"
A51OPT		:= "SET ($(TARGET_MODEL))" EP DEBUG
L51OPT		:= "CLASSES (XDATA (X:0x0-X:0x1FFF), HDATA (X:0x0-X:0x1FFF), CODE (C:0x0-C:0xFFFF), CONST (C:0x0-C:0xFFFF), ECODE (C:0x0-C:0xFFFF), HCONST (C:0x0-C:0xFFFF))"
CPU_TYPE	:= 8052AH
CPU_VENDOR	:= Intel
CPU_XTAL	:= 0x01312D00

LIBAXDSPOBJ	:= cordic16vec2.obj cordic16vec3.obj cordic16vec4.obj cordic16vec5.obj cordic16vec6.obj cordic16vec7.obj \
		   cordic16vec8.obj cordic16vec9.obj cordic16vec10.obj cordic16vec11.obj cordic16vec12.obj cordic16vec13.obj \
		   cordic16vec14.obj cordic16vec15.obj \
		   cordic16corevec2.obj cordic16corevec3.obj cordic16corevec4.obj cordic16corevec5.obj cordic16corevec6.obj cordic16corevec7.obj \
		   cordic16corevec8.obj cordic16corevec9.obj cordic16corevec10.obj cordic16corevec11.obj cordic16corevec12.obj cordic16corevec13.obj \
		   cordic16corevec14.obj cordic16corevec15.obj \
		   cordic16rot2.obj cordic16rot3.obj cordic16rot4.obj cordic16rot5.obj cordic16rot6.obj cordic16rot7.obj \
		   cordic16rot8.obj cordic16rot9.obj cordic16rot10.obj cordic16rot11.obj cordic16rot12.obj cordic16rot13.obj \
		   cordic16rot14.obj cordic16rot15.obj \
		   cordic16corerot2.obj cordic16corerot3.obj cordic16corerot4.obj cordic16corerot5.obj cordic16corerot6.obj cordic16corerot7.obj \
		   cordic16corerot8.obj cordic16corerot9.obj cordic16corerot10.obj cordic16corerot11.obj cordic16corerot12.obj cordic16corerot13.obj \
		   cordic16corerot14.obj cordic16corerot15.obj \
		   firxi16xi16.obj firxi16ci16.obj

BINARIES	:=

comma		:= ,
empty		:=
space		:= $(empty) $(empty)

all:				libaxdsp.lib libaxdsplarge.lib $(BINARIES) $(patsubst %.omf,%.hex,$(BINARIES))

clean:
				rm -rf LIBAXDSP.LIB libaxdsp.lib libaxdsp LIBAXDSPLARGE.LIB libaxdsplarge.lib libaxdsplarge libaxdspbinkeil2.tar.gz

tar:				libaxdspbinkeil2.tar.gz

libaxdspbinkeil2.tar.gz:
				[ -f LIBAXDSP.LIB ] && mv LIBAXDSP.LIB libaxdsp.lib ; \
				[ -f LIBAXDSPLARGE.LIB ] && mv LIBAXDSPLARGE.LIB libaxdsplarge.lib ; \
				tar -c -v -z -f $@ libaxdsp.lib libaxdsplarge.lib

ifeq ($(LIBSUFFIX),)
libaxdsplarge.lib:
				make TARGET_MODEL=LARGE LIBSUFFIX=large
endif

libaxdsp$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.src %.obj %.omf

%.obj:				%.src
				$(KEILPATH)/C51/BIN/AX51.EXE "$(shell cygpath -w $<)" "PR($(shell cygpath -w $(patsubst %.obj,%.ls1,$@)))" $(A51OPT)

%.src:				%.src1
				./fixmodname.pl $@ < $< > $@

%.omf:				%.obj libaxdsp$(LIBSUFFIX).lib $(shell cygpath -u $(C51LIB)/C51S.LIB)
				($(KEILPATH)/C51/BIN/LX51.EXE "$(subst $(space),$(comma),$(foreach fn,$^,$(shell cygpath -w $(fn))))" TO "$(shell cygpath -w $@)" CODE "($(shell cygpath -w $(patsubst %.omf,%.cod,$@)))" $(L51OPT); x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

%.hex:				%.omf
				$(KEILPATH)/C51/BIN/OHX51.EXE "$(shell cygpath -w $<)" HEXFILE "($(shell cygpath -w $@))"

libaxdsp$(LIBSUFFIX)/%.src:		../source/%.c | libaxdsp$(LIBSUFFIX)
					($(KEILPATH)/C51/BIN/C51.EXE "$(shell cygpath -w $<)" $(C51FLAGS) DEFINE "(RADIO=5043,AX5043_DISABLE_XSFR,AX5043_DISABLE_NONBLOCKING)" SRC "($(shell cygpath -w $@))" PR "($(shell cygpath -w $(patsubst %.src,%.lst,$@)))"; x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/%.src:		libaxdsp$(LIBSUFFIX)/%.c | libaxdsp$(LIBSUFFIX)
					($(KEILPATH)/C51/BIN/C51.EXE "$(shell cygpath -w $<)" $(C51FLAGS) DEFINE "(RADIO=5043,AX5043_DISABLE_XSFR,AX5043_DISABLE_NONBLOCKING)" SRC "($(shell cygpath -w $@))" PR "($(shell cygpath -w $(patsubst %.src,%.lst,$@)))"; x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX).lib:		$(patsubst %.obj,libaxdsp$(LIBSUFFIX)/%.obj,$(LIBAXDSPOBJ)) | libaxdsp$(LIBSUFFIX)
					$(KEILPATH)/C51/BIN/LIBX51.EXE TRANSFER "$(subst $(space),$(comma),$(foreach fn,$(patsubst %.obj,libaxdsp$(LIBSUFFIX)/%.obj,$(LIBAXDSPOBJ)),$(shell cygpath -w $(fn))))" TO $@

libaxdsp$(LIBSUFFIX)/cordic16vec%.c:		../source/cordic16vec.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16corevec%.c:	../source/cordic16corevec.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16rot%.c:		../source/cordic16rot.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16corerot%.c:	../source/cordic16corerot.c | libaxdsp$(LIBSUFFIX)
						(unifdef -DSTAGES=$* -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdsp$(LIBSUFFIX)/cordic16vec2.src:		libaxdsp$(LIBSUFFIX)/cordic16vec2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec3.src:		libaxdsp$(LIBSUFFIX)/cordic16vec3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec4.src:		libaxdsp$(LIBSUFFIX)/cordic16vec4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec5.src:		libaxdsp$(LIBSUFFIX)/cordic16vec5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec6.src:		libaxdsp$(LIBSUFFIX)/cordic16vec6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec7.src:		libaxdsp$(LIBSUFFIX)/cordic16vec7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec8.src:		libaxdsp$(LIBSUFFIX)/cordic16vec8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec9.src:		libaxdsp$(LIBSUFFIX)/cordic16vec9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec10.src:		libaxdsp$(LIBSUFFIX)/cordic16vec10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec11.src:		libaxdsp$(LIBSUFFIX)/cordic16vec11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec12.src:		libaxdsp$(LIBSUFFIX)/cordic16vec12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec13.src:		libaxdsp$(LIBSUFFIX)/cordic16vec13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec14.src:		libaxdsp$(LIBSUFFIX)/cordic16vec14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16vec15.src:		libaxdsp$(LIBSUFFIX)/cordic16vec15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec2.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec3.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec4.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec5.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec6.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec7.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec8.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec9.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec10.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec11.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec12.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec13.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec14.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corevec15.src:	libaxdsp$(LIBSUFFIX)/cordic16corevec15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot2.src:		libaxdsp$(LIBSUFFIX)/cordic16rot2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot3.src:		libaxdsp$(LIBSUFFIX)/cordic16rot3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot4.src:		libaxdsp$(LIBSUFFIX)/cordic16rot4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot5.src:		libaxdsp$(LIBSUFFIX)/cordic16rot5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot6.src:		libaxdsp$(LIBSUFFIX)/cordic16rot6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot7.src:		libaxdsp$(LIBSUFFIX)/cordic16rot7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot8.src:		libaxdsp$(LIBSUFFIX)/cordic16rot8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot9.src:		libaxdsp$(LIBSUFFIX)/cordic16rot9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot10.src:		libaxdsp$(LIBSUFFIX)/cordic16rot10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot11.src:		libaxdsp$(LIBSUFFIX)/cordic16rot11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot12.src:		libaxdsp$(LIBSUFFIX)/cordic16rot12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot13.src:		libaxdsp$(LIBSUFFIX)/cordic16rot13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot14.src:		libaxdsp$(LIBSUFFIX)/cordic16rot14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16rot15.src:		libaxdsp$(LIBSUFFIX)/cordic16rot15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot2.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot2.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot3.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot3.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot4.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot4.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot5.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot5.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot6.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot6.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot7.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot7.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot8.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot8.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot9.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot9.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot10.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot10.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot11.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot11.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot12.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot12.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot13.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot13.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot14.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot14.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/cordic16corerot15.src:	libaxdsp$(LIBSUFFIX)/cordic16corerot15.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)

libaxdsp$(LIBSUFFIX)/firxi16xi16.src:		../source/firxi16xi16.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
libaxdsp$(LIBSUFFIX)/firxi16ci16.src:		../source/firxi16ci16.c ../source/libaxdsp.h | libaxdsp$(LIBSUFFIX)
