#pragma once  // Menggunakan directive pragma once untuk memastikan file header hanya di-include sekali.

#include "peripherals/gpio.h"  // Meng-include file header "gpio.h" dari direktori "peripherals".

typedef enum _GpioFunc {
    GFInput = 0,    // Mendefinisikan GpioFunc GFInput dengan nilai 0, menandakan mode input pada pin GPIO.
    GFOutput = 1,   // Mendefinisikan GpioFunc GFOutput dengan nilai 1, menandakan mode output pada pin GPIO.
    GFAlt0 = 4,     // Mendefinisikan GpioFunc GFAlt0 dengan nilai 4, menandakan mode fungsi alternatif 0 pada pin GPIO.
    GFAlt1 = 5,     // Mendefinisikan GpioFunc GFAlt1 dengan nilai 5, menandakan mode fungsi alternatif 1 pada pin GPIO.
    GFAlt2 = 6,     // Mendefinisikan GpioFunc GFAlt2 dengan nilai 6, menandakan mode fungsi alternatif 2 pada pin GPIO.
    GFAlt3 = 7,     // Mendefinisikan GpioFunc GFAlt3 dengan nilai 7, menandakan mode fungsi alternatif 3 pada pin GPIO.
    GFAlt4 = 3,     // Mendefinisikan GpioFunc GFAlt4 dengan nilai 3, menandakan mode fungsi alternatif 4 pada pin GPIO.
    GFAlt5 = 2      // Mendefinisikan GpioFunc GFAlt5 dengan nilai 2, menandakan mode fungsi alternatif 5 pada pin GPIO.
} GpioFunc;  // Mendefinisikan enum GpioFunc untuk menentukan fungsi pin GPIO.

void gpio_pin_set_func(u8 pinNumber, GpioFunc func);  // Mendefinisikan fungsi untuk mengatur fungsi pin GPIO sesuai GpioFunc.

void gpio_pin_enable(u8 pinNumber);  // Mendefinisikan fungsi untuk mengaktifkan pin GPIO.
