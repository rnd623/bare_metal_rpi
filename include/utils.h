#pragma once

#include "common.h"

//token git https://github.com/rnd623/bare_metal_rpi.git

void delay(u64 ticks);
void put32(u64 address, u32 value);
u32 get32(u64 address);