/*   sbi_timer.h   */

/* System Reset Extension. - SBI Spec. ver 3.0, Section 10. */

#pragma once

#include <sbi.h>

#define SBI_EXT_RESET_EID              0x52464e43
#define SBI_EXT_RESET_SYSTEM_RESET_FID 0x0

static inline struct sbiret sbi_system_reset(uint32_t reset_type,
                                             uint32_t reset_reason)
{
    return _sbi_call2(
        SBI_EXT_RESET_EID,
        SBI_EXT_RESET_SYSTEM_RESET_FID,
        reset_type,
        reset_reason
    );
}
