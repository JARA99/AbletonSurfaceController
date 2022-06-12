/*
 * Name: main.c
 * Author: Jorge Alejandro Rodriguez Aldana
 * Date: 2022
 */


// #include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
// #include "tusb.h"
#include "functions.h"

int main() {
  
    // tusb_init();
    
    while (1)
    {
      // tud_task(); // tinyusb device task
      read_push_btn();
    }
}


