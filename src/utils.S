.globl delay
delay:
    subs x0, x0, #1   // Mengurangi nilai dari register x0 sebanyak 1.
    bne delay         // Mengecek apakah nilai register x0 tidak sama dengan 0. Jika tidak, lakukan lompatan ke label 'delay'.
    ret               // Mengembalikan eksekusi ke tempat pemanggilan.

.globl put32
put32:
    str w1, [x0]      // Menyimpan nilai register w1 (32-bit) ke alamat yang ditunjuk oleh register x0.

.globl get32
get32:
    ldr w0, [x0]      // Memuat nilai dari alamat yang ditunjuk oleh register x0 ke register w0.
    ret               // Mengembalikan eksekusi ke tempat pemanggilan.

.globl get_el
get_el:
    mrs x0, CurrentEL
    lsr x0, x0, #2
    ret