/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>
// #include <string.h>
#include "EncoderClass.cpp"

// void read(int a, int b, int la, int lb);

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
    
    gpio_pull_down(13);
    gpio_pull_down(14);

    gpio_put(15,1);
    gpio_put(12,0);

    Encoder a(13,14,15,1);
    Encoder b(13,14,12,2);
    Encoder c(13,14,11,3);
    Encoder d(13,14,10,4);
    Encoder e(13,14,9,5);
    Encoder f(13,14,8,6);

    
    Encoder encoders[6] = {a,b,c,d,e,f};


    while (1)
    {
        for (uint8_t i = 0; i < 7; i++)
        {
            encoders[i].read();
        }
    }

    
}
