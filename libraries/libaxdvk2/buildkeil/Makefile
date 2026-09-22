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

LIBAXDVK2OBJ        := lcdinit.obj lcdsetpos.obj lcdwrstr.obj lcdclear.obj lcdclrdisp.obj lcdwru16.obj lcdwru32.obj \
		   lcdwrhexu16.obj lcdwrhexu32.obj lcduwrnum16.obj lcduwrnum32.obj lcduwrhex16.obj lcduwrhex32.obj \
		   lcd2init.obj lcd2txbuf.obj lcd2wrstr.obj lcd2clrdisp.obj lcd2setpos.obj lcd2clear.obj lcd2txcmds.obj lcd2txcmdl.obj \
		   lcd2utx.obj lcd2uwrnum16.obj lcd2uwrnum32.obj lcd2uwrhex16.obj lcd2uwrhex32.obj

BINARIES	:=

comma		:= ,
empty		:=
space		:= $(empty) $(empty)

all:				libaxdvk2.lib libaxdvk2large.lib $(BINARIES) $(patsubst %.omf,%.hex,$(BINARIES))

clean:
				rm -rf LIBAXDVK2.LIB libaxdvk2.lib libaxdvk2 LIBAXDVK2LARGE.LIB libaxdvk2large.lib libaxdvk2large libaxdvk2binkeil.tar.gz

tar:				libaxdvk2binkeil.tar.gz

libaxdvk2binkeil.tar.gz:
				[ -f LIBAXDVK2.LIB ] && mv LIBAXDVK2.LIB libaxdvk2.lib ; \
				[ -f LIBAXDVK2LARGE.LIB ] && mv LIBAXDVK2LARGE.LIB libaxdvk2large.lib ; \
				tar -c -v -z -f $@ libaxdvk2.lib libaxdvk2large.lib

ifeq ($(LIBSUFFIX),)
libaxdvk2large.lib:
				make TARGET_MODEL=LARGE LIBSUFFIX=large
endif

libaxdvk2$(LIBSUFFIX):
				[ ! -d $@ ] && mkdir -p $@

.PRECIOUS:			%.src %.obj %.omf

%.obj:				%.src
				$(KEILPATH)/C51/BIN/A51.EXE "$(shell cygpath -w $<)" "PR($(shell cygpath -w $(patsubst %.obj,%.ls1,$@)))" $(A51OPT)

%.src:				%.src1
				./fixmodname.pl $@ < $< > $@

%.omf:				%.obj libaxdvk2$(LIBSUFFIX).lib $(shell cygpath -u $(C51LIB)/C51S.LIB)
				($(KEILPATH)/C51/BIN/BL51.EXE "$(subst $(space),$(comma),$(foreach fn,$^,$(shell cygpath -w $(fn))))" TO "$(shell cygpath -w $@)" $(L51OPT); x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

%.hex:				%.omf
				$(KEILPATH)/C51/BIN/OH51.EXE "$(shell cygpath -w $<)" HEXFILE "($(shell cygpath -w $@))"

libaxdvk2$(LIBSUFFIX)/%.src:		../source/%.c | libaxdvk2$(LIBSUFFIX)
					($(KEILPATH)/C51/BIN/C51.EXE "$(shell cygpath -w $<)" $(C51FLAGS) SRC "($(shell cygpath -w $@))" PR "($(shell cygpath -w $(patsubst %.src,%.lst,$@)))"; x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

libaxdvk2$(LIBSUFFIX)/%.src:		libaxdvk2$(LIBSUFFIX)/%.c | libaxdvk2$(LIBSUFFIX)
					($(KEILPATH)/C51/BIN/C51.EXE "$(shell cygpath -w $<)" $(C51FLAGS) SRC "($(shell cygpath -w $@))" PR "($(shell cygpath -w $(patsubst %.src,%.lst,$@)))"; x=$$?; if [ $${x} -lt 2 ]; then x=0; fi; exit $${x})

libaxdvk2$(LIBSUFFIX).lib:		$(patsubst %.obj,libaxdvk2$(LIBSUFFIX)/%.obj,$(LIBAXDVK2OBJ)) | libaxdvk2$(LIBSUFFIX)
					$(KEILPATH)/C51/BIN/LIB51.EXE TRANSFER "$(subst $(space),$(comma),$(foreach fn,$(patsubst %.obj,libaxdvk2$(LIBSUFFIX)/%.obj,$(LIBAXDVK2OBJ)),$(shell cygpath -w $(fn))))" TO $@

libaxdvk2$(LIBSUFFIX)/lcdu%.c:		../source/io%.c
					(unifdef -DUART=3 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdvk2$(LIBSUFFIX)/lcd2u%.c:		../source/io%.c
					(unifdef -DUART=4 -o $@ $<; x=$$?; if [ $${x} -lt 2 ] ; then x=0; fi; exit $${x})

libaxdvk2$(LIBSUFFIX)/lcdinit.src:	../source/lcdinit.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdsetpos.src:	../source/lcdsetpos.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwrstr.src:	../source/lcdwrstr.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdclear.src:	../source/lcdclear.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdclrdisp.src:	../source/lcdclrdisp.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwru16.src:	../source/lcdwru16.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwru32.src:	../source/lcdwru32.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwrhexu16.src:	../source/lcdwrhexu16.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcdwrhexu32.src:	../source/lcdwrhexu32.c ../source/libaxlcd.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrnum16.src:	libaxdvk2$(LIBSUFFIX)/lcduwrnum16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrnum32.src:	libaxdvk2$(LIBSUFFIX)/lcduwrnum32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrhex16.src:	libaxdvk2$(LIBSUFFIX)/lcduwrhex16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcduwrhex32.src:	libaxdvk2$(LIBSUFFIX)/lcduwrhex32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2init.src:	../source/lcd2init.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2txbuf.src:	../source/lcd2txbuf.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2wrstr.src:	../source/lcd2wrstr.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2clrdisp.src:	../source/lcd2clrdisp.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2setpos.src:	../source/lcd2setpos.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2clear.src:	../source/lcd2clear.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2txcmds.src:	../source/lcd2txcmds.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2txcmdl.src:	../source/lcd2txcmdl.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2utx.src:	libaxdvk2$(LIBSUFFIX)/lcd2utx.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2urx.src:	libaxdvk2$(LIBSUFFIX)/lcd2urx.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu16.src:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu16.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu32.src:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhexu32.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwru16.src:	libaxdvk2$(LIBSUFFIX)/lcd2uwru16.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwru32.src:	libaxdvk2$(LIBSUFFIX)/lcd2uwru32.c ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrnum16.src:	libaxdvk2$(LIBSUFFIX)/lcd2uwrnum16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrnum32.src:	libaxdvk2$(LIBSUFFIX)/lcd2uwrnum32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhex16.src:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhex16.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
libaxdvk2$(LIBSUFFIX)/lcd2uwrhex32.src:	libaxdvk2$(LIBSUFFIX)/lcd2uwrhex32.c ../source/libaxlcd.h ../source/libaxlcd2.h | libaxdvk2$(LIBSUFFIX)
