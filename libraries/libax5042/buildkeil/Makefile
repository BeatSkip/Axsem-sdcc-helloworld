TARGET_MODEL	:= SMALL
LIBSUFFIX	:=
KEILPATH	:= C:/EDA/Keil
C51INC		:= $(KEILPATH)/C51/INC
C51LIB		:= $(KEILPATH)/C51/LIB
C51FLAGS	:= OBJECTEXTEND $(TARGET_MODEL) DEBUG INCDIR "($(shell cygpath -w ../source),$(shell cygpath -w ../../libmf/source))"
A51OPT		:= "SET ($(TARGET_MODEL))" EP DEBUG
L51OPT		:= "RAMSIZE(256) XDATA(0x0-0x1FFF) CODE(0x0-0xFFFF)"
CPU_TYPE	:= 8052AH
CPU_VENDOR	:= Intel
CPU_XTAL	:= 0x01312D00

LIBAX5042OBJ        := pllrange.obj

BINARIES	:=

comma		:= ,
empty		:=
space		:= $(empty) $(empty)

all:				libax5042.lib libax5042large.lib $(BINARIES) $(patsubst %.omf,%.hex,$(BINARIES))

clean:
				rm -rf LIBAX5042.LIB libax5042.lib libax5042 LIBAX5042LARGE.LIB libax5042large.lib libax5042large libax5042binkeil.tar.gz

tar:				libax5042binkeil.tar.gz

libax5042binkeil.tar.gz:
				[ -f LIBAX5042.LIB ] && mv LIBAX5042.LIB libax5042.lib ; \
				[ -f LIBAX5042LARGE.LIB ] && mv LIBAX5042LARGE.LIB libax5042large.lib ; \
				tar -c -v -z -f $@ libax5042.lib libax5042large.lib

ifeq ($(LIBSUFFIX),)
libax5042large.lib:
				make TARGET_MODEL=LARGE LIBSUFFIX=large
endif

libax5042$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.src %.obj %.omf

%.obj:				%.src
				$(KEILPATH)/C51/BIN/A51.EXE "$(shell cygpath -w $<)" "PR($(shell cygpath -w $(patsubst %.obj,%.ls1,$@)))" $(A51OPT)

%.src:				%.src1
				./fixmodname.pl $@ < $< > $@

%.omf:				%.obj libax5042$(LIBSUFFIX).lib $(shell cygpath -u $(C51LIB)/C51S.LIB)
				($(KEILPATH)/C51/BIN/BL51.EXE "$(subst $(space),$(comma),$(foreach fn,$^,$(shell cygpath -w $(fn))))" TO "$(shell cygpath -w $@)" $(L51OPT); x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

%.hex:				%.omf
				$(KEILPATH)/C51/BIN/OH51.EXE "$(shell cygpath -w $<)" HEXFILE "($(shell cygpath -w $@))"

libax5042$(LIBSUFFIX)/%.src:			../source/%.c | libax5042$(LIBSUFFIX)
						($(KEILPATH)/C51/BIN/C51.EXE "$(shell cygpath -w $<)" $(C51FLAGS) SRC "($(shell cygpath -w $@))" PR "($(shell cygpath -w $(patsubst %.src,%.lst,$@)))"; x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

libax5042$(LIBSUFFIX).lib:			$(patsubst %.obj,libax5042$(LIBSUFFIX)/%.obj,$(LIBAX5042OBJ)) | libax5042$(LIBSUFFIX)
						$(KEILPATH)/C51/BIN/LIB51.EXE TRANSFER "$(subst $(space),$(comma),$(foreach fn,$(patsubst %.obj,libax5042$(LIBSUFFIX)/%.obj,$(LIBAX5042OBJ)),$(shell cygpath -w $(fn))))" TO $@

libax5042$(LIBSUFFIX)/pllrange.src:		../source/pllrange.c ../source/libax5042.h | libax5042$(LIBSUFFIX)
