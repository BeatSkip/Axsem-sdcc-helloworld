#include "libaxdsp.h"

#if 0 && defined(SDCC)

__reentrantb void fft_radix2dif(int16_t __xdata *data, uint8_t stages, const int16_t __code *sintab) __reentrant
{
	__asm
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	a,sp
	add	a,#-4
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	
	__endasm;
}

#else

__reentrantb void fft_radix2dif(int16_t __xdata *data, uint8_t stages, const int16_t __code *sintab) __reentrant
{
	uint8_t nrinc = 1;
	for (; stages; nrinc <<= 1) {
		uint8_t x, y;
		int16_t __xdata *dp0 = data;
		--stages;
		x = 1 << stages;
		for (y = 0; y != x; ++y) {
			int16_t __xdata *dp1 = dp0 + (x << 1);
			const int16_t __code *wtab = sintab;
			uint8_t z = x;
			do {
				// butterfly
				{
					int16_t t0;
					t0 = dp0[0] - dp1[0];
					dp0[0] += dp1[0];
					dp1[0] = a;
					t0 = dp0[1] - dp1[1];
					dp0[1] += dp1[1];
					dp1[1] = a;
				}
				// multiplication
				{
					int32_t tm = dp1[0] * (int32_t)wtab[0] - dp1[1] * (int32_t)wtab[1];
					int16_t t0 = tm >> 14;
					tm = dp1[1] * (int32_t)wtab[0] + dp1[0] * (int32_t)wtab[1];
					dp1[1] = tm >> 14;
					dp1[0] = t0;
				}
				// index update
				wtab += nrinc << 1;
				dp0 += 2;
				dp1 += 2;
			} while (--z);
			dp0 = dp1;
		}
	}
}

#endif
