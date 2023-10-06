#pragma once  // Menggunakan directive pragma once untuk memastikan header hanya di-include sekali.

#include "common.h"  // Meng-include file header "common.h".

#include "peripherals/base.h"  // Meng-include file header "base.h" dari direktori "peripherals".

struct AuxRegs {
    reg32 irq_status;  // Struktur untuk merepresentasikan register Aux IRQ status.
    reg32 enables;  // Struktur untuk merepresentasikan register Aux enables.
    reg32 reserved[14];  // Array reserved untuk memberikan padding sebesar 14 * 4 byte.
    reg32 mu_io;  // Struktur untuk merepresentasikan register Aux MU IO.
    reg32 mu_ier;  // Struktur untuk merepresentasikan register Aux MU IER.
    reg32 mu_iir;  // Struktur untuk merepresentasikan register Aux MU IIR.
    reg32 mu_lcr;  // Struktur untuk merepresentasikan register Aux MU LCR.
    reg32 mu_mcr;  // Struktur untuk merepresentasikan register Aux MU MCR.
    reg32 mu_lsr;  // Struktur untuk merepresentasikan register Aux MU LSR.
    reg32 mu_msr;  // Struktur untuk merepresentasikan register Aux MU MSR.
    reg32 mu_scratch;  // Struktur untuk merepresentasikan register Aux MU scratch.
    reg32 mu_control;  // Struktur untuk merepresentasikan register Aux MU control.
    reg32 mu_status;  // Struktur untuk merepresentasikan register Aux MU status.
    reg32 mu_baud_rate;  // Struktur untuk merepresentasikan register Aux MU baud rate.
};

#define REGS_AUX ((struct AuxRegs *)(PBASE + 0x00215000))  // Mendefinisikan alamat base register Aux dengan menggunakan PBASE dan offset 0x00215000.
