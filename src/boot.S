#include "mm.h"  // Meng-include file header "mm.h" yang mungkin berisi definisi atau deklarasi yang diperlukan.

.section ".text.boot"  // Mendefinisikan bagian dari kode sebagai ".text.boot".

.globl _start  // Mendefinisikan _start sebagai simbol global agar dapat diakses dari luar modul.

_start:  // Mendefinisikan titik awal dari program (_start).
    mrs x0, mpidr_el1  // Mengambil nilai dari register mpidr_el1 (Multiprocessor Affinity Register, EL1) dan memasukkannya ke dalam x0.
    and x0, x0, #0xFF  // Melakukan operasi bitwise AND antara x0 dan 0xFF (memaksa hanya 8 bit terendah yang relevan).
    cbz x0, master  // Jika hasil operasi cbz adalah 0 (zero), maka lompat ke label master.

master:  // Label master, akan dieksekusi jika cbz x0, master adalah false.
    adr x0, bss_begin  // Mendapatkan alamat dari label bss_begin dan memasukkannya ke dalam x0.
    adr x1, bss_end  // Mendapatkan alamat dari label bss_end dan memasukkannya ke dalam x1.
    sub x1, x1, x0  // Menghitung selisih antara x1 dan x0 dan menyimpannya di x1 (menghitung ukuran bss).
    bl memzero  // Memanggil fungsi memzero untuk mengisi n byte dari x0 dengan nilai 0.

    mov sp, #LOW_MEMORY  // Mengatur nilai stack pointer (sp) dengan nilai LOW_MEMORY.
    bl kernel_main  // Memanggil fungsi kernel_main.
    b proc_hang  // Melakukan lompatan tak bersyarat ke label proc_hang.

proc_hang:  // Label proc_hang, akan terus melakukan wfe (Wait For Event) dan lompatan ke proc_hang.
    wfe  // Menunggu kejadian (Wait For Event).
    b proc_hang  // Lompatan tak bersyarat kembali ke label proc_hang.
