// This is a necessary part to go along with the
// config.h settings to slow the I2C frequency.
// CREDIT TO SIGPROF FOR THIS PORTION!!! THANK YOU!!

#pragma once

#include_next <mcuconf.h>

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

#undef STM32_I2C1SW
#define STM32_I2C1SW STM32_I2C1SW_HSI
