#pragma once  // Menggunakan directive pragma once untuk memastikan file header hanya di-include sekali.

#define PAGE_SHIFT 12  // Mendefinisikan pergeseran (shift) untuk ukuran halaman (page) dalam satuan bit (shift amount).
#define TABLE_SHIFT 9   // Mendefinisikan pergeseran (shift) untuk ukuran tabel dalam satuan bit (shift amount).
#define SECTION_SHIFT (PAGE_SHIFT + TABLE_SHIFT)  // Mendefinisikan pergeseran (shift) untuk ukuran sektion dalam satuan bit (shift amount) berdasarkan ukuran halaman dan tabel.
#define PAGE_SIZE (1 << PAGE_SHIFT)  // Mendefinisikan ukuran halaman dalam satuan byte (size of a page in bytes) berdasarkan pergeseran halaman (page shift).
#define SECTION_SIZE (1 << SECTION_SHIFT)  // Mendefinisikan ukuran sektion dalam satuan byte (size of a section in bytes) berdasarkan pergeseran sektion (section shift).

#define LOW_MEMORY (2 * SECTION_SIZE)  // Mendefinisikan batas bawah untuk memori (low memory boundary) dalam satuan byte.

#ifndef __ASSEMBLER__  // Menentukan bahwa kode di bawah ini tidak untuk mode assembler.

void memzero(unsigned long src, unsigned int n);  // Deklarasi fungsi 'memzero' yang akan mengisi n byte dari 'src' dengan nilai 0.

#endif  // Akhir dari ifndef __ASSEMBLER__.
