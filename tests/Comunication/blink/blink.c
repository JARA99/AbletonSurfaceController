/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    // #ifndef PICO_DEFAULT_LED_PIN
    // #warning blink example requires a board with a regular LED
    // #else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true)
    {
        uint32_t to = time_us_32();
        printf("Entering to onoff mode");
        while ((time_us_32() - to) < 5000000) {
            gpio_put(LED_PIN, 1);
            busy_wait_us_32(250);
            gpio_put(LED_PIN, 0);
            busy_wait_us_32(250);
        }
        printf("Entering to on only mode");
        while ((time_us_32() - to) < 10000000)
        {
            gpio_put(LED_PIN,1);
        }
        // #endif
    }
}
