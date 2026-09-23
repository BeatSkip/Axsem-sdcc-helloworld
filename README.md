# imagotag-reverse

Firmware and tooling for the **SES-imagotag Vusion 2.6" BWR shelf label** (UU340 variant).
The tag is built around an **Axsem AX8052F143** — a 2.4 GHz radio transceiver with an 8051
core — running from a 26 MHz crystal. It drives a Good Display **GDEW026Z39** e-paper panel
(296×152, black/white/red, IL0373 controller), an NFC chip and a serial flash.

The original firmware was built with IAR EW8051. This repository builds it with **SDCC**
instead, using the **SDCC-MDF** extension for VS Code.

## Current status

- The project **builds cleanly with SDCC**; roughly 18 KB of the ~58 KB usable flash is used.
- `main.c` is a **flash dump tool**: it boots, powers the transistor lines, brings up UART0
  (38400 8N1 — the AXSEM bootloader rate) and the SPI unit, then streams the whole SPI flash
  over UART as a hexdump (JEDEC ID first), then blinks the blue LED. Reset the tag to dump
  again; `tools/flashdump.py` automates the reset (boot pin via DTR, reset via RTS) and
  saves the dump to a file.
- **SPI and e-paper drivers are implemented but not yet verified on hardware.** The e-paper
  init sequence was transcribed from three independent drivers for this exact panel, but
  `main.c` no longer calls it; the BUSY polarity question is still open (see below).
- **Flashing is not configured.** The `upload` section of `sdcc-project.json` is a
  placeholder. The AX8052F143 is programmed over its debug link, which no tool in this repo
  drives yet.
- The NFC chip has chip-select support in the SPI driver, but no device driver. The
  transistor-driven lines on PA2/PA5 are driven by `pwr.c` (config in `pwr.h`), their loads
  still unidentified.

## Repository layout

| Path | Contents |
|---|---|
| `src/` | Application code: `main.c` (flash dumper), `board.c/h`, `hal.h`, drivers `spi.c/h`, `epd.c/h`, `flash.c/h`, `pwr.c/h`, and the generated boot image `epd_image.c/h` |
| `tools/` | Helper scripts: `png2epd.py` converts a PNG into e-paper plane data |
| `include/` | Project-local headers (currently empty) |
| `lib/` | Prebuilt Axsem LibMF SDK libraries as SDCC archives: `libmf`, `libaxdvk2`, `libaxdsp`, `libmfcrypto` |
| `libraries/` | Full Axsem SDK source tree (IAR/Keil/SDCC/ARM build makefiles and headers) |
| `documentation/` | AX8052F100/F131/F143 datasheets |
| `.sdcc/boards/` | Board definition for the SDCC-MDF extension (project-scoped, travels with the repo) |
| `.vscode/` | Build tasks, IntelliSense config, workspace settings |
| `sdcc-project.json` | SDCC-MDF project configuration |
| `GDEW026Z39-init-reference.md` | Notes on the e-paper init sequence and the sources of each byte |

## Pin map

Full authoritative mapping: `documentation/signal-list.md`.

| Function | Pin | Notes |
|---|---|---|
| LED white / blue / green | `PB0` / `PB7` / `PB6` | active low |
| LED red | `PC4` | active low |
| UART0 TX / RX | `PB4` / `PB5` | 38400 8N1, timer 0 baud (off while the e-paper is driven) |
| SPI SCK / MOSI / MISO | `PC1` / `PC2` / `PC3` | hardware SPI unit |
| CS flash / NFC / EPD | `PC0` / `PB1` / `PA0` | active low |
| EPD D/C, RST, BUSY | `PA1`, `PB5`, `PB2` | D/C: 0 = command, 1 = data |
| NFC field detect / boot | `PB3` | |
| Transistor U4 / U5 | `PA5` / `PA2` | function not identified yet |

One conflict worth knowing about: **EPD reset shares PB5 with the UART RX function.**
Enabling UART0 hands the pin to the UART, so the boot demo leaves UART0 off — if a future
firmware needs UART, it must release PB5 (or reset the panel) before driving the display.

## Building

Required: [SDCC](https://sdcc.sourceforge.net/) (tested with 3.6.0) and the
[SDCC-MDF extension](https://marketplace.visualstudio.com/items?itemName=dzantemir.sdcc-mdf)
(tested with 0.29.11) in VS Code.

1. Open the repository in VS Code.
2. If the extension does not detect SDCC, set the path via *SDCC-MDF: Select Toolchain*.
3. **Ctrl+Shift+B** (or the *SDCC: Build* task). Output lands in `build/`:
   - `firmware.ihx` — linker output
   - `firmware.hex` — Intel HEX, ready for flashing once flashing is wired up
   - `firmware.map` / `firmware.mem` — placement and usage report

The same build by hand, from the repository root (PowerShell needs `&` before a quoted
executable path):

```powershell
$flags = @('-mmcs51','--model-small','--iram-size','256','--xram-size','8192','--code-size','59389')

& 'C:\Program Files\SDCC\bin\sdcc.exe' -c @flags '-Iinclude' '-Ilibraries/libmf/include' 'src/main.c'  -o 'build/obj/src/main.rel'
& 'C:\Program Files\SDCC\bin\sdcc.exe' -c @flags '-Iinclude' '-Ilibraries/libmf/include' 'src/board.c' -o 'build/obj/src/board.rel'
& 'C:\Program Files\SDCC\bin\sdcc.exe' -c @flags '-Iinclude' '-Ilibraries/libmf/include' 'src/spi.c'   -o 'build/obj/src/spi.rel'
& 'C:\Program Files\SDCC\bin\sdcc.exe' -c @flags '-Iinclude' '-Ilibraries/libmf/include' 'src/epd.c'   -o 'build/obj/src/epd.rel'

& 'C:\Program Files\SDCC\bin\sdcc.exe' @flags '-Iinclude' '-Ilibraries/libmf/include' `
    'build/obj/src/main.rel' 'build/obj/src/board.rel' 'build/obj/src/spi.rel' 'build/obj/src/epd.rel' `
    'lib/libaxdsp.lib' 'lib/libaxdvk2.lib' 'lib/libmf.lib' 'lib/libmfcrypto.lib' `
    -o 'build/firmware.ihx'
```

Memory model is `--model-small`, with 256 B IRAM, 8 KB XRAM and ~58 KB code (the top of the
64 KB flash is reserved, matching the boundary the original IAR linker file used).

## Drivers

### Transistor lines — `src/pwr.h`

Controls the unidentified transistor lines PA2 (U5) and PA5 (U4). Which pins are driven and
their polarity are `#define`s at the top of `pwr.h`:

```c
#define PWR_USE_U4  1       /* PA5 */      #define PWR_USE_U5  1       /* PA2 */
#define PWR_U4_ACTIVE_HIGH  1              #define PWR_U5_ACTIVE_HIGH  1

pwr_init();                /* selected pins become outputs, driven off */
pwr_on();                  /* drive all selected pins to their on level */
pwr_off();
pwr_pulse(100, 100, 0);    /* 100 ms on, 100 ms off, forever */
```

The boot demo calls `pwr_on()` before touching the panel, on the assumption one of the
transistors gates the display supply. If that misbehaves, flip the polarity defines or
disable one pin and rebuild.

### SPI — `src/spi.h`

A thin wrapper over the AX8052's built-in SPI unit, mode 0, MSB first — the same
configuration the vendor's own LCD code uses. Provides `spi_init()`, `spi_transfer()`,
`spi_write()`/`spi_read()`, and chip-select helpers for the three slaves on the bus
(EPD, NFC, flash). The SPI clock source is a `#define` at the top of the header; the default
(0xD8) is the LibMF LCD driver's setting, and 0x06 (SYSCLK) also works.

### Serial flash — `src/flash.h`

Thin 25-series SPI NOR driver: `extflash_release_powerdown()`, `extflash_read_jedec_id()`,
`extflash_read()`. The dump size lives in `FLASH_SIZE` (default 128 KiB for the suspected
1 Mbit chip; the JEDEC capacity byte tells the truth). The boot firmware prints the JEDEC ID
and a full hexdump of the chip on UART0 at 38400 8N1 (TX = PB4); `tools/flashdump.py`
resets the board (boot pin via DTR, reset via RTS, same wiring as `tools/axsem-flasher.py`)
and saves the stream to a file. Use `--bootloader` to reset into the serial bootloader
instead.

### E-paper — `src/epd.h`

Driver for the GDEW026Z39 (IL0373), driven **rotated — 152 wide × 296 tall** — the same
orientation the stock tag firmware uses. It relies on the panel's built-in OTP LUT, so no
waveform tables are needed.

A full frame is two 5624-byte planes (black/white and red), which together exceed the 8 KB
of XRAM. The API therefore streams the frame in two halves, reusing one buffer:

```c
#include "spi.h"
#include "epd.h"

uint8_t __xdata buf[EPD_PLANE_BYTES];   /* 5624 bytes; 0 = ink, 1 = white */

spi_init();                             /* call after periph_init() */
epd_init();                             /* resets the panel, clears it to white */

epd_plane_ink(buf, 10, 10);             /* bit 0 = ink, MSB = leftmost pixel */
epd_upload(0x10, buf, EPD_PLANE_BYTES); /* black/white plane */

/* refill buf with the red plane (bit 0 = red ink) and send it */
epd_upload(0x13, buf, EPD_PLANE_BYTES);

epd_refresh();                          /* starts the update, waits for BUSY */
epd_sleep();                            /* panel deep sleep */
```

`epd_clear(0xFF, 0xFF)` wipes the screen white without any buffer; static images can live in
`const` (flash) and be passed straight to `epd_upload()`.

### Boot image

`main.c` shows `polyform-eink.png` on boot. The image was converted to the two 1-bit
planes in `src/epd_image.c` by:

```
python tools/png2epd.py polyform-eink.png --dither
```

The converter composites transparency over white, quantizes to black/white/red
(optionally with Floyd-Steinberg dithering) and rotates the image to the panel's mounted
orientation. If the logo shows up sideways on the tag, regenerate with a different
`--rotate` (0/90/180/270; 90 = image's left edge on top).

Two hardware notes that will matter on first bring-up:

- **UART0 is off in the demo.** Its RX pin (PB5) doubles as the panel reset line; with the
  UART enabled, the pin belongs to the UART and the reset pulse never reaches the panel.
- **BUSY polarity.** Every driver found for this panel on this tag polls BUSY *low* while
  busy — the tag board inverts the line, although the bare Good Display module is
  active-high. `epd.c` defaults to active-low. If `epd_init()` hangs or updates render
  corrupt, flip `EPD_BUSY_ACTIVE_HIGH` and retry.
- The init bytes and their provenance are written up in `GDEW026Z39-init-reference.md`.

## Known issues and quirks

- **SDCC-MDF vs PowerShell** (extension ≤ 0.29.11): the extension emits single-quoted tool
  paths without the `&` call operator, so with a PowerShell terminal every build fails with
  `Unexpected token '-mmcs' …`. This repo works around it with `"sdcc.shellPath": "cmd.exe"`
  in `.vscode/settings.json` (workspace-scoped). After changing it, reload the VS Code
  window — the extension reuses its existing build terminal.
- **Board definitions are cached** by the extension; after editing `axsem-8051.json`,
  reload the window for the change to take effect.
- The `lib/*.lib` files are SDCC archives built from `libraries/` with the vendor's
  `buildsdcc` makefiles. Only `libmf` is currently linked; the other three are present for
  future drivers.

## Not done yet

- Flash/debug recipe for the AX8052 debug link, so `SDCC: Flash` actually flashes.
- Hardware verification of the e-paper driver (init + first frame), settling the BUSY
  polarity question.
- Identification of the PA2/PA5 transistor lines.
- NFC (FM11NT081DS) and serial flash device drivers — chip selects are in place.
- Repo weight: `libraries/` is ~120 MB, of which only `libraries/libmf/include` is needed
  to build.

## License

The code in `src/` has no license declared yet. The Axsem SDK under `libraries/` and `lib/`
retains its original terms (compiler headers are GPL with a linking exception; the rest is
vendor-licensed) — see the individual files.
