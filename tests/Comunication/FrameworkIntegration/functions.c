// #include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "tusb.h"
#include "functions.h"

bool read_push_btn(){
    /* Returns 1 if the button is pushed, 0 if it is not. */
    gpio_put(greenLedPin,1);
    return !(gpio_get(pushBtnInPin));
}