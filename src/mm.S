.globl memzero    // Mendefinisikan simbol 'memzero' sebagai simbol global agar dapat diakses dari luar modul.

memzero:    // Label 'memzero', titik awal dari fungsi 'memzero'.

    str xzr, [x0], #8    // Menyimpan nilai nol (xzr) ke alamat yang ditunjukkan oleh x0, kemudian menambahkan 8 pada x0.
                         // Efek samping: x0 akan bertambah sebanyak 8.

    subs x1, x1, #8     // Mengurangi x1 dengan 8 dan menyimpan hasilnya di x1.
                         // Efek samping: x1 akan berkurang sebanyak 8.

    b.gt memzero         // Melakukan lompatan ke label 'memzero' jika x1 masih lebih besar dari 8 (gt = greater than).
                         // Jika x1 tidak lebih besar dari 8, maka tidak melakukan lompatan dan melanjutkan ke instruksi berikutnya.

    ret                  // Kembali dari fungsi 'memzero'.

