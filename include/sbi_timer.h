/*   sbi_timer.h   */

/* Timer Extension. - SBI Spec. ver 3.0, Section 6. */

#pragma once

#include <sbi.h>

#define SBI_EXT_TIMER_EID           0x54494d45
#define SBI_EXT_TIMER_SET_TIMER_FID 0x0

static inline struct sbiret sbi_set_timer(uint64_t stime_value)
{
    return _sbi_call1(
        SBI_EXT_TIMER_EID,
        SBI_EXT_TIMER_SET_TIMER_FID,
        stime_value);
}
