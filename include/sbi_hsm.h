/*   sbi_hsm.h   */

/* Hart State Management Extension. - SBI Spec. ver 3.0, Section 5.1. */

#pragma once

#include <sbi.h>

#define SBI_EXT_HSM_EID                 0x48534d
#define SBI_EXT_HSM_HART_START_FID      0x0
#define SBI_EXT_HSM_HART_STOP_FID       0x1
#define SBI_EXT_HSM_HART_GET_STATUS_FID 0x2
#define SBI_EXT_HSM_HART_SUSPEND_FID    0x3

static inline struct sbiret sbi_hart_start(unsigned long hartid,
                                           unsigned long start_addr,
                                           unsigned long opaque)
{
    return _sbi_call3(
        SBI_EXT_HSM_EID,
        SBI_EXT_HSM_HART_START_FID,
        hartid,
        start_addr,
        opaque
    );
}

static inline struct sbiret sbi_hart_stop(void)
{
    return _sbi_call0(
        SBI_EXT_HSM_EID,
        SBI_EXT_HSM_HART_STOP_FID
    );
}

static inline struct sbiret sbi_hart_get_status(unsigned long hartid)
{
    return _sbi_call1(
        SBI_EXT_HSM_EID,
        SBI_EXT_HSM_HART_GET_STATUS_FID,
        hartid
    );
}

static inline struct sbiret sbi_hart_suspend(uint32_t suspend_type,
                                             unsigned long resume_addr,
                                             unsigned long opaque)
{
    return _sbi_call3(
        SBI_EXT_HSM_EID,
        SBI_EXT_HSM_HART_SUSPEND_FID,
        suspend_type,
        resume_addr,
        opaque
    );
}

#define SBI_HART_STATE_STARTED         0
#define SBI_HART_STATE_STOPPED         1
#define SBI_HART_STATE_START_PENDING   2
#define SBI_HART_STATE_STOP_PENDING    3
#define SBI_HART_STATE_SUSPENDED       4
#define SBI_HART_STATE_SUSPEND_PENDING 5
#define SBI_HART_STATE_RESUME_PENDING  6

static const char *sbi_hart_state_names[] = {
    [SBI_HART_STATE_STARTED] = "Started",
    [SBI_HART_STATE_STOPPED] = "Stopped",
    [SBI_HART_STATE_START_PENDING] = "Pending to start",
    [SBI_HART_STATE_STOP_PENDING] = "Pending to stop",
    [SBI_HART_STATE_SUSPENDED] = "Suspended",
    [SBI_HART_STATE_SUSPEND_PENDING] = "Pending to suspend",
    [SBI_HART_STATE_RESUME_PENDING] = "Pending to resume"
};

static inline const char *sbi_hart_strstate(long state)
{
    return (0 <= state && state < 7)
        ? sbi_hart_state_names[state]
        : "Unknown state";
}
