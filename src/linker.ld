SECTIONS
{
    .text.boot : { *(.text.boot) }  /* Bagian ini untuk menyatukan dan memasukkan semua bagian kode yang memiliki label .text.boot.*/
    .text : { *(.text) }  /* Bagian ini untuk menyatukan dan memasukkan semua bagian kode yang memiliki label .text.*/
    .rodata : { *(.rodata) }  /* Bagian ini untuk menyatukan dan memasukkan semua bagian data yang bersifat read-only (rodata).*/
    .data : { *(.data) }  /* Bagian ini untuk menyatukan dan memasukkan semua bagian data.*/
    . = ALIGN(0x8);  /* Posisi saat ini diatur dengan batas aligmen 0x8 (dalam hal ini 8 bytes).*/
    bss_begin = .;  /* Menandakan awal dari bagian BSS.*/
    .bss : { *(.bss*) }  /* Bagian ini untuk menyatukan dan memasukkan semua bagian BSS (Block Started by Symbol).*/
    bss_end = .;  /* Menandakan akhir dari bagian BSS.*/
}
