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
#include "quantum.h"

// clang-format off
#define LAYOUT(                                                      \
              k01,   k02,   k03,   k04,   k05,   k06,   k07,   k08,  \
              k11,          k13,   k14,   k15,   k16,   k17,   k18,  \
       k20,   k21,   k22,   k23,   k24,   k25,   k26,   k27,   k28,  \
                     k32,   k33,   k34,   k35,   k36,   k37,   k38,  \
       k40,   k41,   k42,                                            \
       k50,   k51,   k52                                             \
   ) {                                                               \
    {KC_NO,   k01,   k02,   k03,   k04,   k05,   k06,   k07,   k08}, \
    {KC_NO,   k11, KC_NO,   k13,   k14,   k15,   k16,   k17,   k18}, \
    {  k20,   k21,   k22,   k23,   k24,   k25,   k26,   k27,   k28}, \
    {KC_NO, KC_NO,   k32,   k33,   k34,   k35,   k36,   k37,   k38}, \
    {  k40,   k41,   k42, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO}, \
    {  k50,   k51,   k52, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO}  \
   }
// clang-format on

#define LAYER_BASE_INDEX 0
#define LAYER_NUMROW_INDEX 1
#define LAYER_FNROW_INDEX 2

typedef union {
  uint32_t raw;
  struct {
    bool         disable_layer_led   :1;
    bool         led_matrix_enable   :1;
  };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;


typedef struct {
    uint8_t red_index;
    uint8_t blue_index;
    uint8_t green_index;
} __attribute__((packed)) led_module_t;

extern led_module_t led_module;

extern const led_module_t led_modules[DRIVER_LED_PER_MATRIX];

void set_led_value(led_module_t led_module, uint8_t red_value, uint8_t blue_value, uint8_t green_value);

void set_top_row_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value);

void set_side_cluster_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value);

void set_main_cluster_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value);

void set_bottom_cluster_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value);

void set_all_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value);

void set_led_theme(void);
