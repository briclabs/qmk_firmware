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

#include "right.h"

keyboard_config_t keyboard_config;

bool is_launching = false;

#ifdef LED_MATRIX_ENABLE
    #include "is31fl3731-simple.h"

    // clang-format off
    const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    /* Refer to IS31 manual for these locations.
     * FYI - pay attention to Pin B matrix references.
     * They do NOT read as a mirror in the spec sheet.
     * They are in the exact locations. Ignore where
     * their power lines are drawn on that matrix
     * diagram. Totally confusing.
     * Don't do it backwards.
    *   SYNTAX:
    * {driverIndex, address}
    *
    *        k01, k02, k03, k04, k05, k06, k07, k08,
    *             k11, k13, k14, k15, k16, k17, k18,
    *   k20, k21, k22, k23, k24, k25, k26, k27, k28,
    *             k32, k33, k34, k35, k36, k37, k38,
    *   k40, k41, k42,
    *   k50, k51, k52
    *
    */
        /* RED */
        /*              0           1           2           3           4           5           6           7 */
                    {1, C5_6},  {1, C5_5},  {1, C4_6},  {1, C4_5},  {1, C3_5},  {1, C3_4},  {1, C2_4},  {1, C1_4},
        /*                          8           9           10          11          12          13          14 */
                                {1, C6_6},  {1, C5_4},  {1, C4_4},  {1, C4_3},  {1, C3_3},  {1, C2_3},  {1, C1_3},
        /*  15          16          17          18          19          20          21          22          23 */
        {1, C6_5},  {1, C6_4},  {1, C6_3},  {1, C5_3},  {1, C5_2},  {1, C4_2},  {1, C3_2},  {1, C2_2},  {1, C1_2},
        /*                          24          25          26          27          28          29          30 */
                                {1, C6_2},  {1, C6_1},  {1, C5_1},  {1, C4_1},  {1, C3_1},  {1, C2_1},  {1, C1_1},
        /*  31          32          33 */
        {1, C7_3},  {1, C7_2},  {1, C7_1},
        /*  34          35          36 */
        {1, C7_6},  {1, C7_5},  {1, C7_4},
        /* BLUE */
        /*              37          38          39          40          41          42          43          44 */
                    {0, C5_6},  {0, C5_5},  {0, C4_6},  {0, C4_5},  {0, C3_5},  {0, C3_4},  {0, C2_4},  {0, C1_4},
        /*                          45          46          47          48          49          50          51 */
                                {0, C6_6},  {0, C5_4},  {0, C4_4},  {0, C4_3},  {0, C3_3},  {0, C2_3},  {0, C1_3},
        /*  52          53          54          55          56          57          58          59          60 */
        {0, C6_5},  {0, C6_4},  {0, C6_3},  {0, C5_3},  {0, C5_2},  {0, C4_2},  {0, C3_2},  {0, C2_2},  {0, C1_2},
        /*                          61          62          63          64          65          66          67 */
                                {0, C6_2},  {0, C6_1},  {0, C5_1},  {0, C4_1},  {0, C3_1},  {0, C2_1},  {0, C1_1},
        /*  68          69          70 */
        {0, C7_3},  {0, C7_2},  {0, C7_1},
        /*  71          72          73 */
        {0, C7_6},  {0, C7_5},  {0, C7_4},
        /* GREEN */
        /*              74          75          76          77          78          79          80          81 */
                    {0, C5_14}, {0, C5_13}, {0, C4_14}, {0, C4_13}, {0, C3_13}, {0, C3_12}, {0, C2_12}, {0, C1_12},
        /*                          82          83          84          85          86          87          88 */
                                {0, C6_14}, {0, C5_12}, {0, C4_12}, {0, C4_11}, {0, C3_11}, {0, C2_11}, {0, C1_11},
        /*  89          90          91          92          93          94          95          96          97 */
        {0, C6_13}, {0, C6_12}, {0, C6_11}, {0, C5_11}, {0, C5_10}, {0, C4_10}, {0, C3_10}, {0, C2_10}, {0, C1_10},
        /*                          98          99          100         101         102         103         104 */
                                {0, C6_10}, {0, C6_9},  {0, C5_9},  {0, C4_9},  {0, C3_9},  {0, C2_9},  {0, C1_9},
        /*  105         106         107 */
        {0, C7_11}, {0, C7_10}, {0, C7_9},
        /*  108         109         110 */
        {0, C7_14}, {0, C7_13}, {0, C7_12}
    };

    /**
    * The syntax for these is RED, BLUE, GREEN. See left.h typedef struct for led_module_t for confirmation.
    */
    const led_module_t led_modules[DRIVER_LED_PER_MATRIX] = {
        /*                   0               1               2               3               4               5               6               7  */
                        {0, 37, 74},    {1, 38, 75},    {2, 39, 76},    {3, 40, 77},    {4, 41, 78},    {5, 42, 79},    {6, 43, 80},    {7, 44, 81},
        /*                                   8               9               10              11              12              13              14 */
                                        {8, 45, 82},    {9, 46, 83},    {10, 47, 84},   {11, 48, 85},   {12, 49, 86},   {13, 50, 87},   {14, 51, 88},
        /*   15              16              17              18              19              20              21              22              23 */
        {15, 52, 89},   {16, 53, 90},   {17, 54, 91},   {18, 55, 92},   {19, 56, 93},   {20, 57, 94},   {21, 58, 95},   {22, 59, 96},   {23, 60, 97},
        /*                                   24              25              26              27              28              29              30 */
                                        {24, 61, 98},   {25, 62, 99},   {26, 63, 100},  {27, 64, 101},  {28, 65, 102},  {29, 66, 103},  {30, 67, 104},
        /*   31              32              33 */
        {31, 68, 105},  {32, 69, 106},  {33, 70, 107},
        /*   34              35              36 */
        {34, 71, 108},  {35, 72, 109},  {36, 73, 110}
    };

    led_config_t g_led_config = { {
        // Key Matrix Location to LED Index (index numbers here are consecutively sequential and not based on anything other than the order in which they appear).
        {NO_LED,      0,      1,      2,      3,      4,      5,      6,      7},
        {NO_LED,      8, NO_LED,      9,     10,     11,     12,     13,     14},
        {    15,     16,     17,     18,     19,     20,     21,     22,     23},
        {NO_LED, NO_LED,     24,     25,     26,     27,     28,     29,     30},
        {    31,     32,     33, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {    34,     35,     36, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
    }, {
        // LED Index to Position
        // x = 224 / 8 * COL_POSITION       28.0 * COL_POSITION
        // y =  64 / 5 * ROW_POSITION       12.8 * ROW_POSITION
        //  0               1             2              3              4              5              6              7              8
                       {  28, 0    }, {  56, 0    }, {  84, 0    }, { 112, 0    }, { 140, 0    }, { 168, 0    }, { 196, 0    }, { 224, 0    },   // 0
                                      {  56, 12.8 }, {  84, 12.8 }, { 112, 12.8 }, { 140, 12.8 }, { 168, 12.8 }, { 196, 12.8 }, { 224, 12.8 },   // 1
        {   0, 25.6 }, {  28, 25.6 }, {  56, 25.6 }, {  84, 25.6 }, { 112, 25.6 }, { 140, 25.6 }, { 168, 25.6 }, { 196, 25.6 }, { 224, 25.6 },   // 2
                                      {  56, 38.4 }, {  84, 38.4 }, { 112, 38.4 }, { 140, 38.4 }, { 168, 38.4 }, { 196, 38.4 }, { 224, 38.4 },   // 3
        {   0, 51.2 }, {  28, 51.2 }, {  56, 51.2 },                                                                                             // 4
        {   0, 64.0 }, {  28, 64.0 }, {  56, 64.0 }                                                                                              // 5
    }, {
        // LED Index to Flag
                  4 ,    4 ,    4 ,    4 ,    4 ,    4 ,    4 ,    4 ,
                         3 ,    3 ,    3 ,    3 ,    3 ,    3 ,    3 ,
           2 ,    2 ,    2 ,    3 ,    3 ,    3 ,    3 ,    3 ,    3 ,
                         2 ,    3 ,    3 ,    3 ,    3 ,    3 ,    3 ,
           3 ,    3 ,    3 ,
           3 ,    3 ,    3

    } };
    // clang-format on

    void suspend_power_down_kb(void) {
        dprint("Powering down.\n");
        led_matrix_set_suspend_state(true);
        suspend_power_down_user();
    }

    void suspend_wakeup_init_kb(void) {
        dprint("Waking up.\n");
        led_matrix_set_suspend_state(false);
        suspend_wakeup_init_user();
    }

    /**
    * Allows setting the RGB values of each LED on a given LED module, without having to supply the index of each individual LED.
    * You just need to supply the index of its module, as defined by the led_modules const.
    * This is a workaround for the RGB matrix system not allowing individual LEDs to be controlled by different drivers.
    */
    void set_led_value(led_module_t led_module, uint8_t red_value, uint8_t green_value, uint8_t blue_value) {
        uint8_t red_index = led_module.red_index;
        uint8_t green_index = led_module.green_index;
        uint8_t blue_index = led_module.blue_index;

        if (red_index >= 0 && red_index < DRIVER_LED_PER_MATRIX && red_value >= 0 && red_value <= LED_MATRIX_MAXIMUM_BRIGHTNESS) {
//             dprintf("Set red[%u] to [%u].\n", red_index, red_value);
            led_matrix_set_value(red_index, red_value);
        }

        if (blue_index >= 0 && blue_index < (DRIVER_LED_PER_MATRIX * 2) && blue_value >= 0 && blue_value <= LED_MATRIX_MAXIMUM_BRIGHTNESS) {
//             dprintf("Set blue[%u] to [%u].\n", blue_index, blue_value);
            led_matrix_set_value(blue_index, blue_value);
        }

        if (green_index >= 0 && green_index < DRIVER_LED_TOTAL && green_value >= 0 && green_value <= LED_MATRIX_MAXIMUM_BRIGHTNESS) {
//             dprintf("Set green[%u] to [%u].\n", green_index, green_value);
            led_matrix_set_value(green_index, green_value);
        }
    }

    void set_top_row_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value) {
        for (uint8_t i = 0; i <= 7; i++) {
            led_module_t led_module = led_modules[i];
            set_led_value(led_module, red_value, green_value, blue_value);
        }
//         dprintf("Set top row to [%u] [%u] [%u].\n", red_value, green_value, blue_value);
    }

    void set_side_cluster_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value) {
        set_led_value(led_modules[8], red_value, green_value, blue_value);
        set_led_value(led_modules[15], red_value, green_value, blue_value);
        set_led_value(led_modules[16], red_value, green_value, blue_value);
        set_led_value(led_modules[17], red_value, green_value, blue_value);
        set_led_value(led_modules[24], red_value, green_value, blue_value);
    }

    void set_main_cluster_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value) {
        for (uint8_t i = 9; i <= 14; i++) {
            set_led_value(led_modules[i], red_value, green_value, blue_value);
        }
        for (uint8_t i = 18; i <= 23; i++) {
            set_led_value(led_modules[i], red_value, green_value, blue_value);
        }
        for (uint8_t i = 25; i <= 30; i++) {
            set_led_value(led_modules[i], red_value, green_value, blue_value);
        }
    }

    void set_bottom_cluster_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value) {
        for (uint8_t i = 31; i <= 36; i++) {
            set_led_value(led_modules[i], red_value, green_value, blue_value);
        }
    }

    void set_numpad_keys(uint8_t red_value, uint8_t green_value, uint8_t blue_value) {
        set_led_value(led_modules[9], red_value, green_value, blue_value);
        set_led_value(led_modules[10], red_value, green_value, blue_value);
        set_led_value(led_modules[11], red_value, green_value, blue_value);
        set_led_value(led_modules[12], red_value, green_value, blue_value);
        set_led_value(led_modules[13], red_value, green_value, blue_value);
        set_led_value(led_modules[18], red_value, green_value, blue_value);
        set_led_value(led_modules[19], red_value, green_value, blue_value);
        set_led_value(led_modules[20], red_value, green_value, blue_value);
        set_led_value(led_modules[21], red_value, green_value, blue_value);
        set_led_value(led_modules[22], red_value, green_value, blue_value);
        set_led_value(led_modules[25], red_value, green_value, blue_value);
        set_led_value(led_modules[26], red_value, green_value, blue_value);
        set_led_value(led_modules[27], red_value, green_value, blue_value);
        set_led_value(led_modules[28], red_value, green_value, blue_value);
        set_led_value(led_modules[29], red_value, green_value, blue_value);
    }

    void set_all_led(uint8_t red_value, uint8_t green_value, uint8_t blue_value) {
        for (uint8_t i = 0; i < DRIVER_LED_PER_MATRIX; i++) {
            set_led_value(led_modules[i], red_value, green_value, blue_value);
        }
    }

    void set_led_theme(void) {
//         dprint("Setting LED theme.\n");
//         set_all_led(255, 255, 255); // TST - ALL ON.
//         set_all_led(255,   0,   0); // TST - RED.
//         set_all_led(  0, 255,   0); // TST - GREEN.
//         set_all_led(  0,   0, 255); // TST - BLUE.
        // dprint("Set all led: light blue.");
        set_all_led(11, 69, 205);              // EVERYTHING IS BLUE
        // dprint("Set main led cluster: blue.");
        set_main_cluster_led(103, 61, 255);    // EXCEPT THE MAIN CLUSTER, WHICH IS LIGHT VIOLET
//          dprint("Led theme setup done.\n");
    }

#endif

void keyboard_post_init_kb(void) {
    debug_enable=true;
    dprint("Post init user begin.\n");
    keyboard_post_init_user();
    dprint("Post init user complete.\n");
}

void matrix_init_kb(void) {
    dprint("Init keyboard eeprom.\n");
    keyboard_config.raw = eeconfig_read_kb();
    dprint("Matrix init complete.\n");
}

void keyboard_post_init_user(void) {
    dprint("Resetting EEPROM.\n");
    led_matrix_set_val_noeeprom(128);
    led_matrix_enable_noeeprom();
    set_led_theme();
}
