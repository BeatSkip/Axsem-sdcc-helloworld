#!/usr/bin/env python3
"""png2epd.py - convert a color PNG into C arrays for the imagotag e-paper.

Target: GDEW026Z39 driven as 152 (wide) x 296 (tall), IL0373, two 1-bit planes:
  0x10 plane = black/white  (bit 0 = black ink)
  0x13 plane = red          (bit 0 = red ink)
Row-major, MSB of each byte = leftmost pixel, 1 = white.

The panel is mounted rotated, so landscape images need --rotate 90 (default):
the source image's LEFT edge becomes the top of the displayed frame.

Usage:
  python tools/png2epd.py polyform-eink.png [--rotate 90] [--dither] [--out-dir src]

Output: <out-dir>/epd_image.c and <out-dir>/epd_image.h
"""

import argparse
import os
import sys

try:
    from PIL import Image
except ImportError:
    sys.exit("Pillow is required:  pip install pillow")

PALETTE = {"white": (255, 255, 255), "black": (0, 0, 0), "red": (255, 0, 0)}


def classify(r, g, b):
    """Nearest palette color in RGB space (works for the dithered case too)."""
    d = {k: (r - cr) ** 2 + (g - cg) ** 2 + (b - cb) ** 2
         for k, (cr, cg, cb) in PALETTE.items()}
    return min(d, key=d.get)


def to_planes(img, dither):
    """Return (bw, red) bytearrays, MSB-first rows, 0 = ink."""
    w, h = img.size
    px = img.load()

    if not dither:
        out_bw = bytearray([0xFF]) * (w * h // 8)
        out_red = bytearray([0xFF]) * (w * h // 8)
        for y in range(h):
            for x in range(w):
                r, g, b, a = px[x, y]
                # composite over the white substrate
                if a < 255:
                    r = (r * a + 255 * (255 - a)) // 255
                    g = (g * a + 255 * (255 - a)) // 255
                    b = (b * a + 255 * (255 - a)) // 255
                lum = (3 * r + 6 * g + b) // 10
                if r > 110 and r > g + 40 and r > b + 40:
                    kind = "red"
                elif lum < 110:
                    kind = "black"
                else:
                    kind = "white"
                if kind != "white":
                    idx = (y * w + x) >> 3
                    mask = 0x80 >> (x & 7)
                    if kind == "red":
                        out_red[idx] &= ~mask
                    else:
                        out_bw[idx] &= ~mask
        return out_bw, out_red

    # Floyd-Steinberg error diffusion to the 3-color palette
    rbuf = bytearray(w * h)
    gbuf = bytearray(w * h)
    bbuf = bytearray(w * h)
    out_bw = bytearray([0xFF]) * (w * h // 8)
    out_red = bytearray([0xFF]) * (w * h // 8)
    for y in range(h):
        for x in range(w):
            r, g, b, a = px[x, y]
            if a < 255:
                r = (r * a + 255 * (255 - a)) // 255
                g = (g * a + 255 * (255 - a)) // 255
                b = (b * a + 255 * (255 - a)) // 255
            i = y * w + x
            r, g, b = min(255, max(0, r + rbuf[i])), min(255, max(0, g + gbuf[i])), min(255, max(0, b + bbuf[i]))
            kind = classify(r, g, b)
            pr, pg, pb = PALETTE[kind]
            er, eg, eb = r - pr, g - pg, b - pb
            for dx, dy, wgt in ((1, 0, 7), (-1, 1, 3), (0, 1, 5), (1, 1, 1)):
                nx, ny = x + dx, y + dy
                if 0 <= nx < w and 0 <= ny < h:
                    ni = ny * w + nx
                    rbuf[ni] = min(255, max(0, rbuf[ni] + er * wgt // 16))
                    gbuf[ni] = min(255, max(0, gbuf[ni] + eg * wgt // 16))
                    bbuf[ni] = min(255, max(0, bbuf[ni] + eb * wgt // 16))
            if kind != "white":
                idx = i >> 3
                mask = 0x80 >> (x & 7)
                if kind == "red":
                    out_red[idx] &= ~mask
                else:
                    out_bw[idx] &= ~mask
    return out_bw, out_red


def c_array(name, data):
    lines = [f"const unsigned char {name}[EPD_PLANE_BYTES] = {{"]
    for i in range(0, len(data), 16):
        chunk = ", ".join(f"0x{b:02X}" for b in data[i:i + 16])
        lines.append(f"    {chunk},")
    lines.append("};")
    return "\n".join(lines)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("png")
    ap.add_argument("--rotate", type=int, default=90, choices=[0, 90, 180, 270],
                    help="rotation applied BEFORE conversion (90 = source left edge on top)")
    ap.add_argument("--dither", action="store_true",
                    help="Floyd-Steinberg dithering to white/black/red (nicer gradients)")
    ap.add_argument("--out-dir", default="src")
    args = ap.parse_args()

    img = Image.open(args.png).convert("RGBA")
    print(f"source: {args.png} {img.size[0]}x{img.size[1]}")
    if args.rotate:
        # PIL rotates counterclockwise; ROTATE_270 = 90 deg clockwise,
        # which puts the source LEFT edge at the top of the result.
        ccw = (360 - args.rotate) % 360
        img = img.rotate(ccw, expand=True)
        print(f"rotated {args.rotate} deg -> {img.size[0]}x{img.size[1]}")
    if img.size != (152, 296):
        print(f"warning: rotated size {img.size[0]}x{img.size[1]} != 152x296 "
              f"(EPD_W x EPD_H in src/epd.h); resize the source accordingly")

    bw, red = to_planes(img, args.dither)

    def count_ink(data):
        n = 0
        for b in data:
            for bit in range(8):
                if not ((b >> (7 - bit)) & 1):
                    n += 1
        return n

    ink_bw = count_ink(bw)
    ink_red = count_ink(red)
    print(f"black ink pixels: {ink_bw} ({100*ink_bw//(152*296)}%), red ink pixels: {ink_red} ({100*ink_red//(152*296)}%)")

    c_path = os.path.join(args.out_dir, "epd_image.c")
    h_path = os.path.join(args.out_dir, "epd_image.h")
    with open(c_path, "w") as f:
        f.write("/* Generated by tools/png2epd.py from %s (rotate=%d, dither=%s) - do not edit */\n"
                % (os.path.basename(args.png), args.rotate, "on" if args.dither else "off"))
        f.write('#include "epd_image.h"\n\n')
        f.write(c_array("epd_image_bw", bw) + "\n\n")
        f.write(c_array("epd_image_red", red) + "\n")
    with open(h_path, "w") as f:
        f.write("/* Generated by tools/png2epd.py - do not edit */\n")
        f.write("#ifndef EPD_IMAGE_H\n#define EPD_IMAGE_H\n\n")
        f.write('#include "epd.h"\n\n')
        f.write("/* Black/white plane and red plane, EPD_PLANE_BYTES each.\n")
        f.write("   0 = ink, 1 = white; pass to epd_upload(0x10/0x13, ...). */\n")
        f.write("extern const unsigned char epd_image_bw[EPD_PLANE_BYTES];\n")
        f.write("extern const unsigned char epd_image_red[EPD_PLANE_BYTES];\n\n")
        f.write("#endif /* EPD_IMAGE_H */\n")
    print(f"wrote {c_path} and {h_path}")


if __name__ == "__main__":
    main()
