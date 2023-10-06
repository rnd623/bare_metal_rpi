#pragma once  // Menggunakan directive pragma once untuk memastikan file header hanya di-include sekali.

// D13.2.113
#define SCTLR_RESERVED (3 << 28) | (3 << 22) | (1 << 20) | (1 << 11)  // Mendefinisikan SCTLR_RESERVED sesuai dengan nilai yang diberikan.
#define SCTLR_EE_LITTLE_ENDIAN (0 << 25)  // Mendefinisikan SCTLR_EE_LITTLE_ENDIAN dengan nilai yang diberikan.
#define SCTLR_EOE_LITTLE_ENDIAN (0 << 24)  // Mendefinisikan SCTLR_EOE_LITTLE_ENDIAN dengan nilai yang diberikan.
#define SCTLR_I_CACHE_DISABLED (0 << 12)  // Mendefinisikan SCTLR_I_CACHE_DISABLED dengan nilai yang diberikan.
#define SCTLR_D_CACHE_DISABLED (0 << 2)  // Mendefinisikan SCTLR_D_CACHE_DISABLED dengan nilai yang diberikan.
#define SCTLR_MMU_DISABLED (0 << 0)  // Mendefinisikan SCTLR_MMU_DISABLED dengan nilai yang diberikan.
#define SCTLR_MMU_ENABLED (1 << 0)  // Mendefinisikan SCTLR_MMU_ENABLED dengan nilai yang diberikan.

#define SCTLR_VALUE_MMU_DISABLED (SCTLR_RESERVED | SCTLR_EE_LITTLE_ENDIAN | SCTLR_I_CACHE_DISABLED | SCTLR_D_CACHE_DISABLED | SCTLR_MMU_DISABLED)  // Menggabungkan nilai-nilai sebelumnya menjadi SCTLR_VALUE_MMU_DISABLED.

// D13.2.47
#define HCR_RW (1 << 31)  // Mendefinisikan HCR_RW dengan nilai yang diberikan.
#define HCR_VALUE HCR_RW  // Menggunakan HCR_RW sebagai nilai HCR_VALUE.

// D13.2.112
#define SCR_RESERVED (3 << 4)  // Mendefinisikan SCR_RESERVED dengan nilai yang diberikan.
#define SCR_RW (1 << 10)  // Mendefinisikan SCR_RW dengan nilai yang diberikan.
#define SCR_NS (1 << 0)  // Mendefinisikan SCR_NS dengan nilai yang diberikan.
#define SCR_VALUE (SCR_RESERVED | SCR_RW | SCR_NS)  // Menggabungkan nilai-nilai sebelumnya menjadi SCR_VALUE.

// C5.2.19
#define SPSR_MASK_ALL (7 << 6)  // Mendefinisikan SPSR_MASK_ALL dengan nilai yang diberikan.
#define SPSR_EL1h (5 << 0)  // Mendefinisikan SPSR_EL1h dengan nilai yang diberikan.
#define SPSR_EL2h (9 << 0)  // Mendefinisikan SPSR_EL2h dengan nilai yang diberikan.
#define SPSR_VALUE (SPSR_MASK_ALL | SPSR_EL1h)  // Menggabungkan nilai-nilai sebelumnya menjadi SPSR_VALUE.
