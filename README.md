# imagotag-reverse

Firmware and tooling for the **SES-imagotag Vusion 2.6" BWR shelf label** (UU340 variant).
The tag is built around an **Axsem AX8052F143** — a 2.4 GHz radio transceiver with an 8051
core — running from a 26 MHz crystal. It drives a Good Display **GDEW026Z39** e-paper panel
(296×152, black/white/red, IL0373 controller), an NFC chip and a serial flash.

The original firmware was built with IAR EW8051. This repository builds it with **SDCC**
instead, using the **SDCC-MDF** extension for VS Code.

## Current status

- The project **builds cleanly with SDCC**; roughly 5 KB of the ~58 KB usable flash is used.
- `main.c` is still the original **LED blink test** — it brings up the GPIOs, UART0 and the
  SPI unit, then toggles the blue LED.
- **SPI and e-paper drivers are implemented but not yet verified on hardware.** The init
  sequence was transcribed from three independent drivers for this exact panel, so it is
  close to correct, but the BUSY polarity in particular needs a real-device check (see below).
- **Flashing is not configured.** The `upload` section of `sdcc-project.json` is a
  placeholder. The AX8052F143 is programmed over its debug link, which no tool in this repo
  drives yet.
- The NFC chip and serial flash have chip-select support in the SPI driver, but no device
  drivers. The transistor-driven lines on PA2/PA5 are not yet identified.

## Repository layout

| Path | Contents |
|---|---|
| `src/` | Application code: `main.c`, `board.c/h`, `hal.h`, and the SPI/EPD drivers `spi.c/h`, `epd.c/h` |
| `include/` | Project-local headers (currently empty) |
| `lib/` | Prebuilt Axsem LibMF SDK libraries as SDCC archives: `libmf`, `libaxdvk2`, `libaxdsp`, `libmfcrypto` |
| `libraries/` | Full Axsem SDK source tree (IAR/Keil/SDCC/ARM build makefiles and headers) |
| `documentation/` | AX8052F100/F131/F143 datasheets |
| `.sdcc/boards/` | Board definition for the SDCC-MDF extension (project-scoped, travels with the repo) |
| `.vscode/` | Build tasks, IntelliSense config, workspace settings |
| `sdcc-project.json` | SDCC-MDF project configuration |
| `GDEW026Z39-init-reference.md` | Notes on the e-paper init sequence and the sources of each byte |

## Pin map

| Function | Pin | Notes |
|---|---|---|
| LED white / blue / green | `PB0` / `PB7` / `PB6` | active low |
| LED red | `PC4` | active low |
| UART0 RX / TX | `PB4` / `PB5` | 115200 8N1, timer 0 baud |
| SPI SCK / MOSI / MISO | `PC1` / `PC2` / `PC3` | hardware SPI unit |
| CS flash / NFC / EPD | `PC0` / `PB1` / `PA1` | active low |
| EPD D/C, RST, BUSY | `PA0`, `PB5`, `PB2` | D/C: 0 = command, 1 = data |
| NFC field detect | `PB3` | |

One conflict worth knowing about: **EPD reset shares PB5 with the UART TX function.**
Resetting the panel mid-transmission will corrupt the byte in flight.

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

### SPI — `src/spi.h`

A thin wrapper over the AX8052's built-in SPI unit, mode 0, MSB first — the same
configuration the vendor's own LCD code uses. Provides `spi_init()`, `spi_transfer()`,
`spi_write()`/`spi_read()`, and chip-select helpers for the three slaves on the bus
(EPD, NFC, flash). The SPI clock source is a `#define` at the top of the header; the default
(0xD8) is the LibMF LCD driver's setting, and 0x06 (SYSCLK) also works.

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

Two hardware notes that will matter on first bring-up:

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
