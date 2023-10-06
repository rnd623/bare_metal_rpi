#pragma once  // Menggunakan directive pragma once untuk memastikan file header hanya di-include sekali.

// Menggunakan directive if-else-endif untuk menentukan nilai PBASE berdasarkan nilai RPI_VERSION.

#if RPI_VERSION == 1
#define PBASE 0x20000000  // Jika RPI_VERSION adalah 1, atur PBASE ke alamat base perangkat keras Raspberry Pi versi 1.

#elif RPI_VERSION == 3
#define PBASE 0x3F000000  // Jika RPI_VERSION adalah 3, atur PBASE ke alamat base perangkat keras Raspberry Pi versi 3.

#elif RPI_VERSION == 4
#define PBASE 0xFE000000  // Jika RPI_VERSION adalah 4, atur PBASE ke alamat base perangkat keras Raspberry Pi versi 4.

#else
#define PBASE 0           // Jika RPI_VERSION tidak sesuai dengan kasus di atas, atur PBASE ke 0 dan hasilkan pesan error.

#endif  // Akhir dari directive if-else-endif.
