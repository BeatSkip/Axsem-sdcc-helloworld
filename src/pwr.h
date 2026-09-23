/**
 * @file pwr.h
 * @brief Control of the transistor-driven lines PA2 (U5) and PA5 (U4)
 *
 * These two pins switch transistors whose loads are not identified yet
 * (documentation/signal-list.md). Configure below which of the two are
 * driven, with what polarity, then use pwr_on()/pwr_off() (or the pulse
 * mode) to exercise them.
 */

#ifndef PWR_DRIVER_H
#define PWR_DRIVER_H

#include <ax8052f143.h>
#include <libmftypes.h>

/* Which transistors to drive: 1 = drive, 0 = leave the pin untouched */
#define PWR_USE_U4  1       /* PA5, transistor U4 */
#define PWR_USE_U5  0       /* PA2, transistor U5 */

/* Polarity: 1 = the pin is driven HIGH to switch the transistor "on",
 * 0 = driven LOW for "on". If the load behaves inverted, flip these. */
#define PWR_U4_ACTIVE_HIGH  0
#define PWR_U5_ACTIVE_HIGH  1

/* Configure the selected pins as outputs, driving their OFF state. */
void pwr_init(void);

/* Switch all selected transistors on / off. */
void pwr_on(void);
void pwr_off(void);

/* Pulse mode: toggle the selected pins on/off with the given timing.
 * cycles = number of full on+off periods; 0 = run forever (blocks). */
void pwr_pulse(uint16_t on_ms, uint16_t off_ms, uint16_t cycles);

#endif /* PWR_DRIVER_H */
