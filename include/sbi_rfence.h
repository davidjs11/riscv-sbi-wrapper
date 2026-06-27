/*   sbi_rfence.h   */

#pragma once

#include <sbi.h>

#define SBI_EXT_RFENCE_EID                         0x52464e43
#define SBI_EXT_RFENCE_REMOTE_FENCE_I_FID          0x0
#define SBI_EXT_RFENCE_REMOTE_SFENCE_VMA_FID       0x1
#define SBI_EXT_RFENCE_REMOTE_SFENCE_VMA_ASID_FID  0x2
#define SBI_EXT_RFENCE_REMOTE_HFENCE_GVMA_VMID_FID 0x3
#define SBI_EXT_RFENCE_REMOTE_HFENCE_GVMA_FID      0x4
#define SBI_EXT_RFENCE_REMOTE_HFENCE_VVMA_ASID_FID 0x5
#define SBI_EXT_RFENCE_REMOTE_HFENCE_VVMA_FID      0x6

static inline struct sbiret sbi_remote_fence_i(unsigned long hart_mask,
                                               unsigned long hart_mask_base)
{
    return _sbi_call2(
        SBI_EXT_RFENCE_EID,
        SBI_EXT_RFENCE_REMOTE_FENCE_I_FID,
        hart_mask,
        hart_mask_base
    );
}

static inline struct sbiret sbi_remote_sfence_vma(unsigned long hart_mask,
                                                  unsigned long hart_mask_base,
                                                  unsigned long start_addr,
                                                  unsigned long size)
{
    return _sbi_call4(
        SBI_EXT_RFENCE_EID,
        SBI_EXT_RFENCE_REMOTE_SFENCE_VMA_FID,
        hart_mask,
        hart_mask_base,
        start_addr,
        size
    );
}

static inline struct sbiret sbi_remote_sfence_vma_asid(unsigned long hart_mask,
                                                       unsigned long hart_mask_base,
                                                       unsigned long start_addr,
                                                       unsigned long size,
                                                       unsigned long asid)
{
    return _sbi_call5(
        SBI_EXT_RFENCE_EID,
        SBI_EXT_RFENCE_REMOTE_SFENCE_VMA_ASID_FID,
        hart_mask,
        hart_mask_base,
        start_addr,
        size,
        asid
    );
}

static inline
struct sbiret sbi_remote_hfence_gvma_vmid(unsigned long hart_mask,
                                          unsigned long hart_mask_base,
                                          unsigned long start_addr,
                                          unsigned long size,
                                          unsigned long vmid)
{
    return _sbi_call5(
        SBI_EXT_RFENCE_EID,
        SBI_EXT_RFENCE_REMOTE_HFENCE_GVMA_VMID_FID,
        hart_mask,
        hart_mask_base,
        start_addr,
        size,
        vmid
    );
}

static inline struct sbiret sbi_remote_hfence_gvma(unsigned long hart_mask,
                                                   unsigned long hart_mask_base,
                                                   unsigned long start_addr,
                                                   unsigned long size)
{
    return _sbi_call4(
        SBI_EXT_RFENCE_EID,
        SBI_EXT_RFENCE_REMOTE_HFENCE_GVMA_FID,
        hart_mask,
        hart_mask_base,
        start_addr,
        size
    );
}

static inline
struct sbiret sbi_remote_hfence_vvma_asid(unsigned long hart_mask,
                                          unsigned long hart_mask_base,
                                          unsigned long start_addr,
                                          unsigned long size,
                                          unsigned long asid)
{
    return _sbi_call5(
        SBI_EXT_RFENCE_EID,
        SBI_EXT_RFENCE_REMOTE_HFENCE_VVMA_ASID_FID,
        hart_mask,
        hart_mask_base,
        start_addr,
        size,
        asid
    );
}

static inline struct sbiret sbi_remote_hfence_vvma(unsigned long hart_mask,
                                                   unsigned long hart_mask_base,
                                                   unsigned long start_addr,
                                                   unsigned long size)
{

    return _sbi_call4(
        SBI_EXT_RFENCE_EID,
        SBI_EXT_RFENCE_REMOTE_HFENCE_VVMA_FID,
        hart_mask,
        hart_mask_base,
        start_addr,
        size
    );
}
