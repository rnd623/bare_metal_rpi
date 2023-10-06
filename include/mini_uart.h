#pragma once  // Menggunakan directive pragma once untuk memastikan file header hanya di-include sekali.

void uart_init();  // Deklarasi fungsi uart_init yang akan menginisialisasi UART.
char uart_recv();  // Deklarasi fungsi uart_recv yang akan membaca karakter dari UART.
void uart_send(char c);  // Deklarasi fungsi uart_send yang akan mengirimkan karakter melalui UART.
void uart_send_string(char *str);  // Deklarasi fungsi uart_send_string yang akan mengirimkan string melalui UART.
