# imagotag-reverse

Firmware for a **SES-imagotag electronic shelf label** built around the **Axsem AX8052F143**
(a 2.4 GHz RF-enabled 8052 microcontroller) running at **26 MHz**.

Originally developed with the IAR EW8051 compiler, this project has been ported to build
with the open-source **[SDCC](https://sdcc.sourceforge.net/)** toolchain through the
**[SDCC-MDF](https://marketplace.visualstudio.com/items?itemName=dzantemir.sdcc-mdf)**
extension for Visual Studio Code.

Current firmware: a **LED blink test** — it initializes the GPIOs, the hardware SPI unit and
UART0 (115200 baud @ 26 MHz XOSC), then toggles the blue LED (`PORTB.7`) forever.

---

## Repository layout

| Path               | Purpose |
|--------------------|---------|
| `src/`             | Application sources: `main.c`, `board.c`, `board.h`, `hal.h` |
| `include/`         | Project-local headers (currently empty, kept for future headers) |
| `lib/`             | Prebuilt **SDCC-format** libraries (`sdcclib` archives) from the Axsem LibMF SDK: `libmf`, `libaxdvk2`, `libaxdsp`, `libmfcrypto` |
| `libraries/`       | Full Axsem LibMF / LibAXDSP / LibAXDVK2 / LibAX5042 SDK sources with per-compiler build Makefiles (IAR / Keil / SDCC / ARM) and public headers |
| `documentation/`   | AX8052F100 / AX8052F131 / AX8052F143 datasheets |
| `components/`      | Source-component libraries (SDCC-MDF ESP-IDF pattern; empty for now) |
| `.sdcc/boards/`    | Project-scoped board definition for the SDCC-MDF extension |
| `.vscode/`         | VS Code tasks, launch, IntelliSense and workspace settings |
| `sdcc-project.json`| SDCC-MDF project configuration (sources, includes, libraries, board) |
| `build/`           | Build output (`firmware.ihx/.hex/.bin`, `.map`, `.mem`, objects) — **gitignored** |

## Hardware / pin map

| Function    | Pin         | Notes                              |
|-------------|-------------|------------------------------------|
| LED white   | `PORTB.0`   | Active low                         |
| LED blue    | `PORTB.7`   | Active low                         |
| LED green   | `PORTB.6`   | Active low                         |
| LED red     | `PORTC.4`   | Active low                         |
| UART RX/TX  | `PORTB.4` / `PORTB.5` | UART0, 115200 8N1, Timer 0 baud |
| SPI SCK/MISO/MOSI | `PORTC.1` / `PORTC.3` / `PORTC.2` | Hardware SPI unit (`SPSHREG`) |
| CS flash    | `PORTC.0`   |                                    |
| CS NFC      | `PORTB.1`   |                                    |
| CS EPD      | `PORTA.1`   |                                    |
| EPD DC/RST/BUSY | `PORTA.0` / `PORTB.5` / `PORTB.2` | e-paper display control |
| NFC FD      | `PORTB.3`   | NFC field detect                  |

## Prerequisites

- **[SDCC](https://sdcc.sourceforge.net/) 3.6.0 or newer** — tested with 3.6.0.
  On Windows the installer default (`C:\Program Files\SDCC`) is picked up automatically.
- **Visual Studio Code** with the **[SDCC-MDF extension](https://marketplace.visualstudio.com/items?itemName=dzantemir.sdcc-mdf)**
  (tested with v0.29.11).
- Git (only if you want to clone/work with this as a repository).

## Building

### With VS Code (recommended)

1. Open the repository folder in VS Code.
2. Make sure the SDCC-MDF extension is installed and SDCC is detected
   (Command Palette → *SDCC-MDF: Select Toolchain* if not).
3. Press **`Ctrl+Shift+B`** (or run the *SDCC: Build* task).

Output appears in the `SDCC › Build` terminal and in the SDCC-MDF output channel:

```
build/firmware.ihx   ← linker output
build/firmware.hex   ← Intel HEX (packihx)
build/firmware.bin   ← raw binary (makebin)
```

The `SDCC: Clean` and `SDCC: Flash` tasks are also defined; **flashing is not configured yet**
(the upload section of `sdcc-project.json` is a placeholder).

### From the command line

The exact commands the extension runs (from the repository root). In PowerShell,
remember the `&` call operator:

```powershell
$flags = @('-mmcs51','--model-small','--iram-size','256','--xram-size','8192','--code-size','59389')

& 'C:\Program Files\SDCC\bin\sdcc.exe' -c @flags '-Iinclude' '-Ilibraries/libmf/include' 'src/main.c'  -o 'build/obj/src/main.rel'
& 'C:\Program Files\SDCC\bin\sdcc.exe' -c @flags '-Iinclude' '-Ilibraries/libmf/include' 'src/board.c' -o 'build/obj/src/board.rel'

& 'C:\Program Files\SDCC\bin\sdcc.exe' @flags '-Iinclude' '-Ilibraries/libmf/include' `
    'build/obj/src/main.rel' 'build/obj/src/board.rel' `
    'lib/libaxdsp.lib' 'lib/libaxdvk2.lib' 'lib/libmf.lib' 'lib/libmfcrypto.lib' `
    -o 'build/firmware.ihx'

& 'C:\Program Files\SDCC\bin\packihx.exe' 'build\firmware.ihx' > 'build\firmware.hex'
```

## SPI & e-paper drivers

`src/spi.c` / `src/spi.h` — minimal hardware SPI master driver for the AX8052 SPI unit
(mode 0, MSB first; SCK=PC1, MOSI=PC2, MISO=PC3). Provides `spi_init()`, `spi_transfer()`,
block `spi_write()`/`spi_read()`, and chip-select helpers for the three devices on the
shared bus: EPD (PA1), NFC (PB1), FLASH (PC0).

`src/epd.c` / `src/epd.h` — driver for the IL0373-based e-paper display
(GDEW026Z39, driven as 152×296 BWR like the stock tag firmware). Uses the panel's
OTP LUT (no LUT tables), full-frame updates only. Pixel bits: **0 = ink, 1 = white**
in both planes (red plane bit 0 = red).

```c
#include "spi.h"
#include "epd.h"

/* one monochrome plane: 1 px = 1 bit, MSB = leftmost pixel */
uint8_t __xdata bw[EPD_PLANE_BYTES];    /* 0 = black */
uint8_t __xdata red[EPD_PLANE_BYTES];   /* 0 = red   */
memset(bw, 0xFF, sizeof bw);            /* start all white */
memset(red, 0xFF, sizeof red);

spi_init();                             /* after periph_init() */
epd_init();                             /* resets + clears to white */

epd_plane_ink(bw, 10, 10);              /* draw some pixels… */
epd_upload(0x10, bw, EPD_PLANE_BYTES);  /* stream B/W plane      */
epd_upload(0x13, red, EPD_PLANE_BYTES); /* stream red plane      */
epd_refresh();                          /* refresh + wait BUSY   */
epd_sleep();                            /* deep sleep when done  */
```

The two planes together (11.2 KB) exceed the 8 KB XRAM, so stream them in two
`epd_upload()` calls while reusing one buffer (as above); static images can live in
`const` (CODE/flash) memory and be passed straight to `epd_upload()`. `epd_clear(0xFF, 0xFF)`
paints the whole screen white without any buffer, `epd_clear(0x00, 0x00)` all black.

Caveats:

- **BUSY polarity:** these tags drive BUSY **active-low** (the bare Good Display module
  is active-high; the tag inverts the line). `epd.c` defaults to low; flip
  `EPD_BUSY_ACTIVE_HIGH` if `epd_init()` hangs or refreshes corrupt.
- **RST shares PB5 with the UART TX function** (per `board.h`) — don't pulse the e-paper
  reset while the UART is mid-transmission.
- Init values are pinned down in `GDEW026Z39-init-reference.md` (three independent
  implementations of the exact Z39 sequence).

## Build configuration

- **MCU:** Axsem AX8052F143 — board definition in `.sdcc/boards/sdcc-mdf-boards-*/axsem-8051.json`
  (project-scoped, travels with the repo).
- **Target / memory model:** `mcs51`, `--model-small`.
- **Memory:** IRAM 256 B · XRAM 8192 B · CODE 59 389 B (the top of the 64 KB flash
  is reserved, matching the original IAR linker setup).
- **F_CPU:** 26 MHz.
- Current firmware usage (LED test + SPI/EPD drivers linked): **≈5 KB flash, ≈0.4 KB XRAM,
  206 B stack** — plenty of headroom.

### Notes & gotchas

- **PowerShell build-terminal bug:** SDCC-MDF v0.29.11 does not prefix the PowerShell
  call operator (`&`) before quoted tool paths, so with a PowerShell terminal every build
  fails with `Unexpected token '-mmcs' …`. This repository therefore sets
  `"sdcc.shellPath": "cmd.exe"` in `.vscode/settings.json` (workspace-scoped, affects only
  this project). After changing it, *Reload Window* before rebuilding — the extension
  reuses its existing build terminal.
- **Board edits need a reload:** the extension caches board definitions in memory;
  after editing `axsem-8051.json`, reload the VS Code window.
- The four `lib/*.lib` files are SDCC-format archives (`sdcclib`) compiled from the
  `libraries/` sources with the vendor's `buildsdcc` Makefiles. They link fine
  cross-platform. Only `libmf` is actually used by the current firmware; the others are
  available for future drivers.

## Flashing / debugging

Not wired up yet. The AX8052F143 is programmed over its debug link; when a programmer
is chosen, add an `upload` recipe to `sdcc-project.json` (SDCC-MDF supports custom flash
tools, avrdude/stm8flash-style, and the AX8052 simulator).

## License

No license is currently declared for the application code in `src/`. The files under
`libraries/` and `lib/` are the Axsem LibMF SDK and retain their original licenses
(GPL with a linking exception for the compiler-agnostic headers, vendor terms for the
rest) — see the headers themselves.
