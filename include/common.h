#pragma once  // Menggunakan directive pragma once untuk memastikan file header hanya di-include sekali.

#include <stdint.h>  // Meng-include file header "stdint.h" yang mendefinisikan tipe data integer.

typedef uint8_t u8;   // Mendefinisikan tipe data u8 sebagai unsigned 8-bit integer (1 byte).
typedef uint16_t u16;  // Mendefinisikan tipe data u16 sebagai unsigned 16-bit integer (2 byte).
typedef uint32_t u32;  // Mendefinisikan tipe data u32 sebagai unsigned 32-bit integer (4 byte).
typedef uint64_t u64;  // Mendefinisikan tipe data u64 sebagai unsigned 64-bit integer (8 byte).

typedef volatile u32 reg32;  // Mendefinisikan tipe data reg32 sebagai unsigned 32-bit integer yang bersifat volatile, artinya dapat berubah secara tiba-tiba.
