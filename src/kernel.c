#include "common.h"  // Meng-include file header "common.h" yang mungkin berisi definisi atau deklarasi yang diperlukan.
#include "mini_uart.h"  // Meng-include file header "mini_uart.h" yang mungkin berisi definisi atau deklarasi yang diperlukan.
#include "printf.h"  // Meng-include file header "printf.h" yang mungkin berisi definisi atau deklarasi yang diperlukan.
#include "irq.h"

void putc(void *p, char c) {
    if (c == '\n') {
        uart_send('\r');  // Mengirim karakter carriage return ('\r') jika karakter adalah newline ('\n').
    }
    uart_send(c);  // Mengirim karakter ke UART.
}

u32 get_el();  // Deklarasi fungsi get_el yang akan mendapatkan Exception Level.

void kernel_main() {
    uart_init();  // Menginisialisasi UART.
    init_printf(0, putc);  // Menginisialisasi printf untuk menggunakan fungsi putc untuk output.
    printf("\nRaspberry PI Bare Metal OS Initializing...\n");  // Mencetak pesan inisialisasi.

    irq_init_vectors();
    enable_interrupt_controller();
    irq_enable();

#if RPI_VERSION == 1
    printf("\tBoard: Raspberry PI Zero\n");  // Cetak pesan jika versi Raspberry Pi adalah 1.
#endif

#if RPI_VERSION == 3
    printf("\tBoard: Raspberry PI 3\n");  // Cetak pesan jika versi Raspberry Pi adalah 3.
#endif

#if RPI_VERSION == 4
    printf("\tBoard: Raspberry PI 4\n");  // Cetak pesan jika versi Raspberry Pi adalah 4.
#endif

    printf("\nException Level: %d\n", get_el());  // Mencetak Exception Level.

    while(1) {
        //uart_send(uart_recv());  // Mengirim karakter yang diterima melalui UART.
    }
}
