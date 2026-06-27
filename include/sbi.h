/*   sbi.h   */

#pragma once

#include <stdint.h>

typedef struct sbiret {
    long error;
    union {
        long value;
        unsigned long uvalue;
    };
} sbiret_t;

static inline struct sbiret _sbi_call0(uintptr_t eid, uintptr_t fid)
{
    register uintptr_t a0 __asm__("a0");
    register uintptr_t a1 __asm__("a1");
    register uintptr_t a6 __asm__("a6") = fid;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "=r" (a0), "=r" (a1)
        : "r" (a6), "r" (a7)
        : "memory"
    );

    return (struct sbiret) { .error = a0, .value = a1 };
}

static inline struct sbiret _sbi_call1(
        uintptr_t eid,
        uintptr_t fid,
        uintptr_t arg0)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1");
    register uintptr_t a6 __asm__("a6") = fid;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0), "=r" (a1)
        : "r" (a6), "r" (a7)
        : "memory"
    );

    return (struct sbiret) { .error = a0, .value = a1 };
}

static inline struct sbiret _sbi_call2(
        uintptr_t eid,
        uintptr_t fid,
        uintptr_t arg0,
        uintptr_t arg1)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a6 __asm__("a6") = fid;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0), "+r" (a1)
        : "r" (a6), "r" (a7)
        : "memory"
    );

    return (struct sbiret) { .error = a0, .value = a1 };
}

static inline struct sbiret _sbi_call3(
        uintptr_t eid,
        uintptr_t fid,
        uintptr_t arg0,
        uintptr_t arg1,
        uintptr_t arg2)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a2 __asm__("a2") = arg2;
    register uintptr_t a6 __asm__("a6") = fid;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0), "+r" (a1)
        : "r" (a6), "r" (a7), "r" (a2)
        : "memory"
    );

    return (struct sbiret) { .error = a0, .value = a1 };
}

static inline struct sbiret _sbi_call4(
        uintptr_t eid,
        uintptr_t fid,
        uintptr_t arg0,
        uintptr_t arg1,
        uintptr_t arg2,
        uintptr_t arg3)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a2 __asm__("a2") = arg2;
    register uintptr_t a3 __asm__("a3") = arg3;
    register uintptr_t a6 __asm__("a6") = fid;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0), "+r" (a1)
        : "r" (a6), "r" (a7), "r" (a2), "r" (a3)
        : "memory"
    );

    return (struct sbiret) { .error = a0, .value = a1 };
}

static inline struct sbiret _sbi_call5(
        uintptr_t eid,
        uintptr_t fid,
        uintptr_t arg0,
        uintptr_t arg1,
        uintptr_t arg2,
        uintptr_t arg3,
        uintptr_t arg4)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a2 __asm__("a2") = arg2;
    register uintptr_t a3 __asm__("a3") = arg3;
    register uintptr_t a4 __asm__("a4") = arg4;
    register uintptr_t a6 __asm__("a6") = fid;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0), "+r" (a1)
        : "r" (a6), "r" (a7), "r" (a2), "r" (a3), "r" (a4)
        : "memory"
    );

    return (struct sbiret) { .error = a0, .value = a1 };
}

static inline struct sbiret _sbi_call6(
        uintptr_t eid,
        uintptr_t fid,
        uintptr_t arg0,
        uintptr_t arg1,
        uintptr_t arg2,
        uintptr_t arg3,
        uintptr_t arg4,
        uintptr_t arg5)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a2 __asm__("a2") = arg2;
    register uintptr_t a3 __asm__("a3") = arg3;
    register uintptr_t a4 __asm__("a4") = arg4;
    register uintptr_t a5 __asm__("a5") = arg5;
    register uintptr_t a6 __asm__("a6") = fid;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0), "+r" (a1)
        : "r" (a6), "r" (a7), "r" (a2), "r" (a3), "r" (a4), "r" (a5)
        : "memory"
    );

    return (struct sbiret) { .error = a0, .value = a1 };
}

static inline uintptr_t _legacy_sbi_call0(uintptr_t eid)
{
    register uintptr_t a0 __asm__("a0");
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0)
        : "r" (a7)
        : "memory"
    );

    return a0;
}

static inline uintptr_t _legacy_sbi_call1(
        uintptr_t eid,
        uintptr_t arg0)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0)
        : "r" (a7)
        : "memory"
    );

    return a0;
}

static inline uintptr_t _legacy_sbi_call2(
        uintptr_t eid,
        uintptr_t arg0,
        uintptr_t arg1)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0)
        : "r" (a7), "r" (a1)
        : "memory"
    );

    return a0;
}

static inline uintptr_t _legacy_sbi_call3(
        uintptr_t eid,
        uintptr_t arg0,
        uintptr_t arg1,
        uintptr_t arg2)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a2 __asm__("a2") = arg2;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0)
        : "r" (a7), "r" (a1), "r" (a2)
        : "memory"
    );

    return a0;
}

static inline uintptr_t _legacy_sbi_call4(
        uintptr_t eid,
        uintptr_t arg0,
        uintptr_t arg1,
        uintptr_t arg2,
        uintptr_t arg3)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a2 __asm__("a2") = arg2;
    register uintptr_t a3 __asm__("a3") = arg3;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0)
        : "r" (a7), "r" (a1), "r" (a2), "r" (a3)
        : "memory"
    );

    return a0;
}

static inline uintptr_t _legacy_sbi_call5(
        uintptr_t eid,
        uintptr_t arg0,
        uintptr_t arg1,
        uintptr_t arg2,
        uintptr_t arg3,
        uintptr_t arg4)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a2 __asm__("a2") = arg2;
    register uintptr_t a3 __asm__("a3") = arg3;
    register uintptr_t a4 __asm__("a4") = arg4;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0)
        : "r" (a7), "r" (a1), "r" (a2), "r" (a3), "r" (a4)
        : "memory"
    );

    return a0;
}

static inline uintptr_t _legacy_sbi_call6(
        uintptr_t eid,
        uintptr_t arg0,
        uintptr_t arg1,
        uintptr_t arg2,
        uintptr_t arg3,
        uintptr_t arg4,
        uintptr_t arg5)
{
    register uintptr_t a0 __asm__("a0") = arg0;
    register uintptr_t a1 __asm__("a1") = arg1;
    register uintptr_t a2 __asm__("a2") = arg2;
    register uintptr_t a3 __asm__("a3") = arg3;
    register uintptr_t a4 __asm__("a4") = arg4;
    register uintptr_t a5 __asm__("a5") = arg5;
    register uintptr_t a7 __asm__("a7") = eid;

    __asm__ volatile (
        "ecall"
        : "+r" (a0)
        : "r" (a7), "r" (a1), "r" (a2), "r" (a3), "r" (a4), "r" (a5)
        : "memory"
    );

    return a0;
}

#define SBI_SUCCESS                0
#define SBI_ERR_FAILED            -1
#define SBI_ERR_NOT_SUPPORTED     -2
#define SBI_ERR_INVALID_PARAM     -3
#define SBI_ERR_DENIED            -4
#define SBI_ERR_INVALID_ADDRESS   -5
#define SBI_ERR_ALREADY_AVAILABLE -6
#define SBI_ERR_ALREADY_STARTED   -7
#define SBI_ERR_ALREADY_STOPPED   -8
#define SBI_ERR_NO_SHMEM          -9
#define SBI_ERR_INVALID_STATE     -10
#define SBI_ERR_BAD_RANGE         -11
#define SBI_ERR_TIMEOUT           -12
#define SBI_ERR_IO                -13
#define SBI_ERR_DENIED_LOCKED     -14
