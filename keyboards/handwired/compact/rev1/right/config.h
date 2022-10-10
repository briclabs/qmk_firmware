/* Copyright 2020 BricLabs <@briclabs>
 * Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Drashna Jael're  <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
// clang-format off
#define VENDOR_ID       0x424C /* BL */
#define PRODUCT_ID      0x434C /* 1 */
#define DEVICE_VER      0x3031 /* 1 */
#define MANUFACTURER    BricLabs
#define PRODUCT         Compact Right
// clang-format on

/**
 *  boot magic key def
 *  used while booting
 * mapped to NUM/FN key
 */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/**
 *   qmk escape key def
 * used to exit bootloader
 *  mapped to NUM/FN key
 */
#define QMK_ESC_OUTPUT A2
#define QMK_ESC_INPUT B14

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 9

/*  PCB default pin-out */

/*                         0   1   2   3   4   5 */
#define MATRIX_ROW_PINS { A2, A1, A0, B2, B1, B0 }                      /* outputs/cathode */

/*                          0    1    2    3    4    5   6   7   8 */
#define MATRIX_COL_PINS { B13, B14, B15, B10, B11, B12, A6, A7, A8 }    /* inputs/anode */

#define UNUSED_PINS { B8, B9, A3, C15, C14, A14, A13, A9, A10, B5, B4, B3, A4, A5, A15 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define LED_DRIVER_ADDR_1 0b1110100
#define LED_DRIVER_ADDR_2 0b1110101

#define LED_DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 37 /* RED Matrix */
#define DRIVER_2_LED_TOTAL 74 /* GREEN + BLUE Matrices */
#define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL
#define LED_DRIVER_LED_COUNT DRIVER_LED_TOTAL
#define DRIVER_LED_PER_MATRIX 37
#define LED_MATRIX_MAXIMUM_BRIGHTNESS 255
#define BACKLIGHT_LEVELS 10
#define LED_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended

// Slow the I2C communication frequency, because the
// ISSI IS31FL3731 LED driver can't handle the
// STM32F303 Proton C's native frequency of 400kHz
// without additional pullups.
// This runs at 8 MHz clock, 100 kHz I2C.
// CREDIT TO SIGPROF FOR THIS PORTION!!! THANK YOU!!
#define I2C1_TIMINGR_PRESC 1U
#define I2C1_TIMINGR_SCLDEL 4U
#define I2C1_TIMINGR_SDADEL 2U
#define I2C1_TIMINGR_SCLH 0x0FU
#define I2C1_TIMINGR_SCLL 0x13U
