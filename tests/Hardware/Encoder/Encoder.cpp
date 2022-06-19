/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>
// #include <string.h>
// #include "EncoderClass.cpp"

int main() {
    stdio_init_all();

    printf("waiting for usb host");
    while (!stdio_usb_connected()) {
      printf(".");
      sleep_ms(500);
    }

    printf("Serial connected");

    gpio_init(13);
    gpio_init(14);
    gpio_init(15);

    gpio_init(25);

    gpio_init(12);
    gpio_init(11);
    gpio_init(10);
    gpio_init(9);
    gpio_init(8);
    gpio_init(7);

    gpio_set_dir(13, GPIO_IN);
    gpio_set_dir(14, GPIO_IN);
    gpio_set_dir(15, GPIO_OUT);

    gpio_set_dir(25, GPIO_OUT);

    gpio_set_dir(12,GPIO_OUT);
    gpio_set_dir(11,GPIO_OUT);
    gpio_set_dir(10,GPIO_OUT);
    gpio_set_dir(9,GPIO_OUT);
    gpio_set_dir(8,GPIO_OUT);
    gpio_set_dir(7,GPIO_OUT);
    
    gpio_pull_up(13);
    gpio_pull_up(14);

    gpio_put(15,1);
    gpio_put(12,1);

    int count = 0;
    bool A_last = 0;
    bool B_last = 0;

    bool change;
    bool dir;

    while (1)
    {
        gpio_put(15,0);
        change = gpio_get(13);
        dir = gpio_get(14);

        if (A_last != change)
        {
            A_last = change;
            if (dir != change)
            {
                count += 1;
                printf("<---\n");
            }
            else
            {
                count -= 1;
                printf("--->\n");
            }
            
        }    
        gpio_put(15,1);


        gpio_put(12,0);
        change = gpio_get(14);
        dir = gpio_get(13);
        if (A_last != change)
        {
            A_last = change;
            if (dir != change)
            {
                count += 1;
                printf("<---\n");
            }
            else
            {
                count -= 1;
                printf("--->\n");
            }
            
        }  
        gpio_put(12,1);
        // sleep_ms(10);
    }
    
}