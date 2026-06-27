/*   sbi_ipi.h   */

/* IPI Extension. - SBI Spec. ver 3.0, Section 7. */

#pragma once

#include <sbi.h>

static inline struct sbiret sbi_send_ipi(unsigned long hart_mask,
                                         unsigned long hart_mask_base)
{
    return _sbi_call2(0x735049, 0x0, hart_mask, hart_mask_base);
}
