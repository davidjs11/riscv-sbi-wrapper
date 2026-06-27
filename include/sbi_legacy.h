/*   sbi_legacy.h   */

/* Legacy Extension. - SBI Spec. ver 3.0, Section 5. */

#pragma once

#include <sbi.h>

static inline long sbi_set_timer(uint64_t stime_value)
{
    return _legacy_sbi_call1(0x0, stime_value);
}

static inline long sbi_console_putchar(int ch)
{
    return _legacy_sbi_call1(0x1, (uintptr_t)ch);
}

static inline long sbi_console_getchar(void)
{
    return _legacy_sbi_call0(0x2);
}

static inline long sbi_clear_ipi(void)
{
    return _legacy_sbi_call0(0x3);
}

static inline long sbi_send_ipi(uintptr_t hart_mask)
{
    return _legacy_sbi_call1(0x4, hart_mask);
}

static inline long sbi_remote_fence_i(uintptr_t hart_mask)
{
    return _legacy_sbi_call1(0x5, hart_mask);
}

static inline long sbi_remote_sfence_vma(uintptr_t hart_mask,
                                         uintptr_t start,
                                         uintptr_t size)
{
    return _legacy_sbi_call3(0x6, hart_mask, start, size);
}

static inline long sbi_remote_sfence_vma_asid(uintptr_t hart_mask,
                                              uintptr_t start,
                                              uintptr_t size,
                                              uintptr_t asid)
{
    return _legacy_sbi_call4(0x7, hart_mask, start, size, asid);
}

static inline void sbi_shutdown(void)
{
    _legacy_sbi_call0(0x8);
}
