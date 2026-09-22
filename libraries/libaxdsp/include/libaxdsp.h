#ifndef LIBAXDSP_H
#define LIBAXDSP_H

#include "libmftypes.h"

#if defined SDCC
extern __reentrantb uint16_t cordic16_core_vec2(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec3(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec4(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec5(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec6(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec7(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec8(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec9(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec10(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec11(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec12(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec13(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec14(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_vec15(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot2(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot3(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot4(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot5(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot6(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot7(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot8(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot9(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot10(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot11(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot12(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot13(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot14(uint16_t phase) __reentrant;
extern __reentrantb uint16_t cordic16_core_rot15(uint16_t phase) __reentrant;
#endif

struct cordic16 {
	int16_t x;
	int16_t y;
	uint16_t p;
};

extern __reentrantb void cordic16_vec2(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec3(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec4(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec5(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec6(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec7(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec8(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec9(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec10(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec11(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec12(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec13(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec14(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_vec15(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot2(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot3(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot4(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot5(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot6(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot7(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot8(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot9(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot10(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot11(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot12(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot13(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot14(struct cordic16 *c) __reentrant;
extern __reentrantb void cordic16_rot15(struct cordic16 *c) __reentrant;

extern __reentrantb int32_t fir_xi16_xi16(const int16_t __xdata *p0, const int16_t __xdata *p1, uint16_t len) __reentrant;
extern __reentrantb int32_t fir_xi16_ci16(const int16_t __xdata *p0, const int16_t __code *p1, uint16_t len) __reentrant;

#endif /* LIBAXDSP_H */
