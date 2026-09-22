# GDEW026Z39 (296x152 BWR, IL0373) init sequence — research notes

Verified against three independent GDEW026Z39-specific implementations that agree byte-for-byte:

1. **andrei-tatar/imagotag-hack** — `firmware/src/display/epd.c` — working 8051 (CC2510) driver for the SES-Imagotag Vusion 2.6" BWR tag, panel GDEW026Z39:
   https://github.com/andrei-tatar/imagotag-hack/blob/master/firmware/src/display/epd.c
2. **angrymew/firmware-cc2510** — `src/display/epd.c` — identical sequence (same hardware family):
   https://github.com/angrymew/firmware-cc2510/blob/master/src/display/epd.c
3. **michaelkamprath/ePaperDriverLib** — Arduino lib with GDEW026Z39-specific config:
   - `src/ePaperSettings_GoodDisplay.h` (init bytes)
   - `src/ePaperSettings.h` (refresh/sleep sequence)
   - `src/ePaperDriver.cpp` (busy polarity, reset, SPI)
   - `src/ePaperDeviceConfigurations.cpp` (dimensions, bit inversion, busy level)
   https://github.com/michaelkamprath/ePaperDriverLib

The official Good Display zip (`A8266-GDEW026Z39-191120` ESP8266 / `GDEW026Z39_Arduino_20191016` / `CODE-GDEW026Z39-20191025-bcm2835-R`) exists on good-display.com / e-paper-display.com but those sites reject automated fetching and the zips are not in the Wayback Machine. The three sources above were written against the Good Display reference and agree exactly, so they are treated as the reference values. Datasheets: `doc/GDEW026Z39.pdf` and `doc/IL0373.pdf` in andrei-tatar/imagotag-hack.

## 1. Complete init sequence (all values verbatim)

andrei-tatar / angrymew (8051, proven on real hardware):

```c
PWR_ON;                 // panel power pin enabled
delay_ms(1000);
RESET_ON;  delay_ms(100);   // RESET low 100 ms
RESET_OFF; delay_ms(100);   // then high, wait 100 ms

sendCommand(0x06);          // BTST booster soft start
sendData(0x17); sendData(0x17); sendData(0x17);

sendCommand(0x04);          // PON power on
epd_waitBusy();             // poll BUSY

sendCommand(0x00);          // PSR panel setting
sendData(0x0F);             // <- LUT from OTP (BWR-OTP)
sendData(0x0D);             // (kamprath lib sends only 0x0F, no 2nd byte)

sendCommand(0x61);          // TRES resolution
sendData(0x98);             // HRES = 152
sendData(0x01);             // VRES[15:8] = 0x01
sendData(0x28);             // VRES[7:0]  = 296
                            // NOTE: only 3 bytes, not 4 (leading 0x00 omitted)

sendCommand(0x50);          // CDI VCOM and data interval
sendData(0x77);

// then clear + refresh (see §3)
```

michaelkamprath `deviceConfiguration_GDEW026Z39[]` (identical, encoded as cmd/data pairs):

```
0x06 | 0x17 0x17 0x17
0x04 | (wait busy)
0x00 | 0x0F
0x61 | 0x98 0x01 0x28
0x50 | 0x77
```

**What is NOT in the GDEW026Z39 sequence** (important — your guesses came from other panels):
- **No PWR 0x01** — absent in all three references (panel runs on IL0373 power defaults).
- **No PLL 0x30** — absent.
- **No VCM_DC 0x82** — absent.
- **No TCON 0x60** — absent.
For contrast, in the same settings file the sibling IL0373 panels DO use those commands, e.g. GDEW027C44: `0x01 | 0x03 0x00 0x2B 0x2B 0x09`, `0x30 | 0x3A`, `0x82 | 0x12`, `0x50 | 0x87`. Those are NOT Z39 values.

## 2. LUT: OTP, no upload

PSR = **0x0F** (not 0x8F). All three references use the OTP LUT; **no** 0x20/0x21/0x22/0x23/0x24 LUT upload exists for Z39. (The 4-gray panels in the same lib upload a 42-byte LUT per command 0x20–0x25, but that code path is not used for Z39.) The 0x8F value you remembered is from Good Display's GDEW029Z10 2.9" BWR code — different panel.

## 3. Refresh / display sequence

imagotag (proven):

```c
sendCommand(0x10);              // DTM1 "old data" = BLACK/WHITE plane
for (i=0; i<5624; i++) sendData(bw_plane[i]);
sendCommand(0x13);              // DTM2 "new data" = RED plane
for (i=0; i<5624; i++) sendData(red_plane[i]);
sendCommand(0x12);              // DRF display refresh
delay(100); epd_waitBusy();
```

kamprath `setImage_CMD_3color[]` (same, plus post-refresh housekeeping):

```
0x10 | <5624 B/W bytes>
0x13 | <5624 red bytes>
0x12 | delay 5 ms | wait busy
0x50 | 0xF7          <- CDI re-written to 0xF7 AFTER refresh (only this lib; init uses 0x77)
0x02 | wait busy     <- POF power off
0x07 | 0xA5          <- DSLP deep sleep
```

## 4. BWR data format

- Two independent 1-bit planes (NOT 2bpp packed): 296*152/8 = **5624 bytes per plane**, 11248 bytes total per frame.
- **0x10 = black/white plane; 0x13 = red plane.** (DTM1 = old data = B/W, DTM2 = new data = red.)
- Bit value: **0 = ink, 1 = white** in both planes → 0 in BW plane = black, **0 in red plane = red**. NOT "1 = red". All clears send 0xFF to both planes. kamprath lib stores 1=ink and inverts (`deviceUsesInvertedBlackBits=true`, `deviceUsesInvertedColorBits=true` for Z39).
- Byte/bit order: MSB first — SPI shifts MSB first; bit7 of the first byte of a row = leftmost pixel; each row = 19 bytes (152/8).
- Orientation: driven **rotated**, 152 wide × 296 tall (HRES=0x98=152, VRES=0x0128=296), even though the datasheet calls the panel 296×152.

## 5. Reset timing (as coded, not datasheet)

- imagotag/angrymew: panel power on → 1000 ms → RESET low 100 ms → high → wait 100 ms.
- kamprath: RESET low 200 ms → high → wait 200 ms.
- (Datasheet GDEW026Z39 spec gives min values; the code values above are what proven drivers use.)

## 6. SPI

- **Mode 0** (CPOL=0, CPHA=0): kamprath `SPISettings(2000000, MSBFIRST, SPI_MODE0)`; CC2510 code sets "SCK-low idle, DATA-1st clock edge, MSB first" = mode 0.
- Reference code runs **2 MHz**. (IL0373 datasheet allows up to ~20 MHz, 50 ns min SCLK period — parent has the datasheet; verify.)
- **D/C**: 0 = command, 1 = data.
- **CS**: pulled low around each transferred byte (per-byte toggling works fine; a whole-transaction low also works).
- Data clocked on rising edge (mode 0), MSB first. 4-wire SPI (SCLK/MOSI/CS/DC); BUSY and RES# are separate GPIOs.

## 7. VCOM (CDI 0x50)

- Init: **0x50, 0x77** (all three references).
- After each refresh, kamprath's lib re-sends **0x50, 0xF7** (imagotag does not).
- **No 0x82 (VCM_DC) command at all** for Z39.

## 8. Busy polarity — verified discrepancy, check your hardware

- **All three GDEW026Z39 references poll BUSY == LOW while busy**: imagotag comment "B_BUSY 3 // P1_3 - low busy", `while (EPD_BUSY == 0)`; kamprath `deviceBusyValue(GDEW026Z39) = LOW`, `while (busyValue == digitalRead(pin))`.
- Generic Good Display IL0373 modules (e.g. 2.9" BWR GDEW029Z10 code) poll BUSY == HIGH while busy, and the IL0373 datasheet describes BUSY high = busy.
- So: for the Z39 on the Imagotag ESL board it is empirically **busy-LOW**. For a bare Good Display module, verify with a meter — do not assume. (The tag board may invert the line.)

## 9. Deep sleep

Proven sequence (both 8051 refs and kamprath):

```
0x02 (POF, power off) -> wait busy -> 0x07, 0xA5 (DSLP deep sleep)
```

`0x10, 0x01` (the form you mentioned) is used by Good Display samples for *other* IL0373 panels; it appears in **no** GDEW026Z39 reference. Wake from deep sleep = hardware reset pulse, then re-run init.
