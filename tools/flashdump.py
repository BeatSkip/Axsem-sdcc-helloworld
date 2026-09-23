#!/usr/bin/env python3
"""flashdump.py - reset the imagotag and capture its serial flash dump.

Boot setup mirrors tools/axsem-flasher.py: DTR drives the BOOT pin,
RTS drives RESET. The boot pin selects the boot mode (PB3 on the tag):

    boot pin released (DTR low)  + reset pulse  -> application (default)
    boot pin held     (DTR high) + reset pulse  -> AX8052 serial bootloader

The dump firmware boots into the application and prints the flash
hexdump once, ending with "*** end of dump ***". Everything runs at
38400 baud, the bootloader's native rate.

Usage:
    python tools/flashdump.py COM7
    python tools/flashdump.py COM7 -o dump1.txt
    python tools/flashdump.py COM7 --bootloader            # show bootloader banner
    python tools/flashdump.py COM7 --bootloader --run      # banner, then R + capture
    python tools/flashdump.py COM7 --reset none            # you reset by hand
    python tools/flashdump.py --list
"""

import argparse
import datetime
import sys
import time

try:
    import serial
    from serial.tools import list_ports
except ImportError:
    sys.exit("pyserial is required:  pip install pyserial")

END_MARKER = b"*** end of dump ***"
DEFAULT_BAUD = 38400


class Tag:
    """Serial hookup to the tag, same line roles as axsem-flasher.py."""

    def __init__(self, port, baud=DEFAULT_BAUD):
        self.serial = serial.Serial(
            port=port,
            baudrate=baud,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=0.2,
            xonxoff=False,
            rtscts=False,
            dsrdtr=False,
        )

    def close(self):
        if self.serial.is_open:
            self.serial.close()

    def set_boot_pin(self, state):
        self.serial.dtr = state

    def set_reset_pin(self, state):
        self.serial.rts = state

    def reset_into(self, bootloader=False):
        """Pulse reset with the boot pin held for the chosen mode.

        Sequence copied from axsem-flasher.py's enter_boot_mode();
        for the application mode the boot pin simply stays released.
        """
        mode = "bootloader" if bootloader else "application"
        print(f"Resetting into {mode}...")
        self.set_reset_pin(False)
        self.set_boot_pin(bootloader)
        # toggle reset
        self.set_reset_pin(True)
        time.sleep(0.1)
        self.set_reset_pin(False)
        time.sleep(0.1)
        # release boot pin
        self.set_boot_pin(False)

    def get_banner(self):
        self.serial.write(b"?")
        time.sleep(0.1)
        return self.serial.readline().decode("utf-8", errors="ignore").strip()

    def run_application(self):
        self.serial.write(b"R")
        time.sleep(0.1)


def capture(ser, outfile, timeout):
    """Stream serial input to console + file until END_MARKER or timeout."""
    print(f"Capturing to {outfile} (ends at {END_MARKER.decode()!r})...\n")
    buf = bytearray()
    marker = bytearray()
    start = time.time()

    with open(outfile, "w", encoding="latin-1", newline="") as f:
        while True:
            chunk = ser.read(4096)
            if chunk:
                buf += chunk
                f.write(chunk.decode("latin-1"))
                f.flush()
                sys.stdout.write(chunk.decode("latin-1", errors="replace"))
                sys.stdout.flush()
                marker += chunk
                if len(marker) > len(END_MARKER) * 2:
                    del marker[:len(END_MARKER)]
                if END_MARKER in marker:
                    break
            if time.time() - start > timeout:
                print(f"\nTIMEOUT after {timeout:.0f}s - dump incomplete?")
                break

    return len(buf), time.time() - start


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("port", nargs="?", help="serial port (e.g. COM7 or /dev/ttyUSB0)")
    ap.add_argument("-b", "--baud", type=int, default=DEFAULT_BAUD,
                    help=f"baud rate (default: {DEFAULT_BAUD})")
    ap.add_argument("-o", "--output", default=None,
                    help="output file (default: flashdump_<timestamp>.txt)")
    ap.add_argument("--bootloader", action="store_true",
                    help="reset into the serial bootloader instead of the application")
    ap.add_argument("--run", action="store_true",
                    help="with --bootloader: send 'R' after the banner and capture the dump")
    ap.add_argument("--reset", choices=["auto", "none"], default="auto",
                    help="'none' skips the reset pulse (reset the board by hand)")
    ap.add_argument("--timeout", type=float, default=180.0,
                    help="seconds to wait for the dump before giving up")
    ap.add_argument("--list", action="store_true", help="list serial ports and exit")
    args = ap.parse_args()

    if args.list:
        ports = list_ports.comports()
        if not ports:
            print("no serial ports found")
        for p in ports:
            print(f"{p.device:12s}  {p.description}")
        return

    if not args.port:
        ap.error("a serial port is required (use --list to see what's available)")

    if args.run and not args.bootloader:
        ap.error("--run only makes sense together with --bootloader")

    outfile = args.output or "flashdump_" + datetime.datetime.now().strftime("%Y%m%d_%H%M%S") + ".txt"

    tag = Tag(args.port, args.baud)
    tag.serial.reset_input_buffer()

    if args.reset == "auto":
        tag.reset_into(bootloader=args.bootloader)
    else:
        print("Reset the board now (power cycle or reset button)...")

    if args.bootloader:
        banner = tag.get_banner()
        print(f"Banner: {banner}")
        if not args.run:
            tag.close()
            return
        tag.run_application()
        time.sleep(0.5)                 # app boots before it starts printing

    nbytes, elapsed = capture(tag.serial, outfile, args.timeout)
    tag.close()
    print(f"\nDone: {nbytes} bytes in {elapsed:.1f}s -> {outfile}")


if __name__ == "__main__":
    main()
