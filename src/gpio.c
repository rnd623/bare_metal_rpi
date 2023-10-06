#include "gpio.h"  // Meng-include file header "gpio.h".
#include "utils.h"  // Meng-include file header "utils.h".

void gpio_pin_set_func(u8 pinNumber, GpioFunc func) {
    // Menghitung bit awal (bitStart) di register func_select untuk pin tertentu.
    u8 bitStart = (pinNumber * 3) % 30;

    // Menghitung nomor register (reg) yang akan digunakan di func_select.
    u8 reg = pinNumber / 10;

    // Mendapatkan nilai selector dari register func_select yang terkait dengan pin dan memodifikasinya.
    u32 selector = REGS_GPIO->func_select[reg];
    selector &= ~(7 << bitStart);  // Menghapus bit sebelumnya yang terkait dengan pin.
    selector |= (func << bitStart);  // Mengatur fungsi baru untuk pin.
    
    REGS_GPIO->func_select[reg] = selector;  // Menyimpan nilai selector kembali ke register func_select.
}

void gpio_pin_enable(u8 pinNumber) {
    // Menonaktifkan internal pull-up/down resistor untuk pin yang akan diatur.
    REGS_GPIO->pupd_enable = 0;
    delay(150);  // Memberikan waktu delay 150 mikrodetik.

    // Mengaktifkan clock untuk memungkinkan akses ke register pudclk.
    REGS_GPIO->pupd_enable_clocks[pinNumber / 32] = 1 << (pinNumber % 32);
    delay(150);  // Memberikan waktu delay 150 mikrodetik.

    // Menonaktifkan kembali internal pull-up/down resistor.
    REGS_GPIO->pupd_enable = 0;
    
    // Menonaktifkan clock untuk menghentikan akses ke register pudclk.
    REGS_GPIO->pupd_enable_clocks[pinNumber / 32] = 0;
}
