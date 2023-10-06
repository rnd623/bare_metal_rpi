#pragma once  // Menggunakan directive pragma once untuk memastikan file header hanya di-include sekali.

#include "common.h"  // Meng-include file header "common.h".

#include "peripherals/base.h"  // Meng-include file header "base.h" dari direktori "peripherals".

struct GpioPinData {
    reg32 reserved;  // Struktur untuk merepresentasikan data pin GPIO dengan bagian yang tidak terpakai (reserved).
    reg32 data[2];   // Array untuk merepresentasikan data pin GPIO dengan dua elemen (32-bit) yang mewakili data pada pin GPIO.
};

struct GpioRegs {
    reg32 func_select[6];  // Array untuk merepresentasikan register fungsi pemilihan GPIO (6 register).
    struct GpioPinData output_set;  // Struktur untuk merepresentasikan data pengaturan output pada pin GPIO.
    struct GpioPinData output_clear;  // Struktur untuk merepresentasikan data pengaturan output yang direset pada pin GPIO.
    struct GpioPinData level;  // Struktur untuk merepresentasikan data level pada pin GPIO.
    struct GpioPinData ev_detect_status;  // Struktur untuk merepresentasikan data status deteksi event pada pin GPIO.
    struct GpioPinData re_detect_enable;  // Struktur untuk merepresentasikan data enable deteksi edge rising pada pin GPIO.
    struct GpioPinData fe_detect_enable;  // Struktur untuk merepresentasikan data enable deteksi edge falling pada pin GPIO.
    struct GpioPinData hi_detect_enable;  // Struktur untuk merepresentasikan data enable deteksi edge high pada pin GPIO.
    struct GpioPinData lo_detect_enable;  // Struktur untuk merepresentasikan data enable deteksi edge low pada pin GPIO.
    struct GpioPinData async_re_detect;  // Struktur untuk merepresentasikan data async enable deteksi edge rising pada pin GPIO.
    struct GpioPinData async_fe_detect;  // Struktur untuk merepresentasikan data async enable deteksi edge falling pada pin GPIO.
    reg32 reserved;  // Struktur untuk merepresentasikan bagian yang tidak terpakai (reserved).
    reg32 pupd_enable;  // Struktur untuk merepresentasikan enable pull-up/pull-down pada pin GPIO.
    reg32 pupd_enable_clocks[2];  // Array untuk merepresentasikan register enable clock untuk pull-up/pull-down pada pin GPIO (2 register).
};

#define REGS_GPIO ((struct GpioRegs *)(PBASE + 0x00200000))  // Mendefinisikan alamat base register GPIO dengan menggunakan PBASE dan offset 0x00200000.
