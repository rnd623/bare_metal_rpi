#include "gpio.h"  // Meng-include file header "gpio.h".
#include "utils.h"  // Meng-include file header "utils.h".
#include "peripherals/aux.h"  // Meng-include file header "aux.h" dari direktori "peripherals".
#include "mini_uart.h"  // Meng-include file header "mini_uart.h".

#define TXD 14  // Mendefinisikan nomor pin TXD.
#define RXD 15  // Mendefinisikan nomor pin RXD.

void uart_init() {
    gpio_pin_set_func(TXD, GFAlt5);  // Mengatur fungsi pin TXD sebagai Alt5.
    gpio_pin_set_func(RXD, GFAlt5);  // Mengatur fungsi pin RXD sebagai Alt5.

    gpio_pin_enable(TXD);  // Mengaktifkan pin TXD.
    gpio_pin_enable(RXD);  // Mengaktifkan pin RXD.

    REGS_AUX->enables = 1;  // Mengaktifkan akses ke mini UART (mu).
    REGS_AUX->mu_control = 0;  // Mematikan mini UART (mu).
    REGS_AUX->mu_ier = 0;  // Menonaktifkan interrupt pada mini UART (mu).
    REGS_AUX->mu_lcr = 3;  // Mengatur mode 8-bit pada mini UART (mu).
    REGS_AUX->mu_mcr = 0;  // Mengatur kontrol mode pada mini UART (mu).

    // Mengatur baud rate sesuai dengan versi Raspberry Pi.
    #if RPI_VERSION == 1
        REGS_AUX->mu_baud_rate = 270; // Baud rate untuk Raspberry Pi 1.
    #elif RPI_VERSION == 3
        REGS_AUX->mu_baud_rate = 270; // Baud rate untuk Raspberry Pi 3.
    #elif RPI_VERSION == 4
        REGS_AUX->mu_baud_rate = 541; // Baud rate untuk Raspberry Pi 4.
    #endif

    REGS_AUX->mu_control = 3;  // Mengaktifkan transmit dan receive pada mini UART (mu).

    uart_send('\r');  // Mengirim karakter carriage return ('\r').
    uart_send('\n');  // Mengirim karakter newline ('\n').
    uart_send('\n');  // Mengirim karakter newline ('\n').
}

void uart_send(char c) {
    while(!(REGS_AUX->mu_lsr & 0x20));  // Menunggu hingga transmit FIFO kosong.

    REGS_AUX->mu_io = c;  // Mengirim karakter ke mini UART (mu).
}

char uart_recv() {
    while(!(REGS_AUX->mu_lsr & 1));  // Menunggu hingga data tersedia di receive FIFO.

    return REGS_AUX->mu_io & 0xFF;  // Membaca karakter dari mini UART (mu).
}

void uart_send_string(char *str) {
    while(*str) {
        if (*str == '\n') {
            uart_send('\r');  // Menggantikan karakter newline dengan carriage return ('\r').
        }

        uart_send(*str);  // Mengirim karakter ke mini UART (mu).
        str++;
    }
}
