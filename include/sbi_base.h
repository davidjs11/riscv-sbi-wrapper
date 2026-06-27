/*   sbi_base.h   */

/* Base Extension. - SBI Spec. ver 3.0, Section 4. */

#pragma once

#include <sbi.h>

static inline struct sbiret sbi_get_spec_version(void)
{
    return _sbi_call0(0x10, 0x0);
}

#define sbi_version_minor_number(version) (version & 0x00FFFFFF)
#define sbi_version_major_number(version) ((version & 0xFF000000) >> 24)

static inline struct sbiret sbi_get_impl_id(void)
{
    return _sbi_call0(0x10, 0x1);
}

static inline struct sbiret sbi_get_impl_version(void)
{
    return _sbi_call0(0x10, 0x2);
}

static inline struct sbiret sbi_probe_extension(long extension_id)
{
    return _sbi_call1(0x10, 0x3, extension_id);
}

static inline struct sbiret sbi_get_mvendorid(void)
{
    return _sbi_call0(0x10, 0x4);
}

static inline struct sbiret sbi_get_marchid(void)
{
    return _sbi_call0(0x10, 0x5);
}

static inline struct sbiret sbi_get_mimpid(void)
{
    return _sbi_call0(0x10, 0x6);
}

static const char *sbi_implementation_names[] = {
    [0] = "Berkley Boot Loader (BBL)",
    [1] = "OpenSBI",
    [2] = "Xvisor",
    [3] = "KVM",
    [4] = "RustSBI",
    [5] = "Diosix",
    [6] = "Coffer",
    [7] = "Xen Project",
    [8] = "PolarFire Hart Software Services",
    [9] = "coreboot",
    [10] = "oreboot",
    [11] = "bhvye",
};
