/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// #include "pico/stdlib.h"
// #include <stdio.h>
// // #include <string.h>
// #include "bsp/board.h"
// #include "tusb.h"

#include <stdio.h>
#include "pico/stdlib.h"
// #include "hardware/gpio.h"
// #include "pico/binary_info.h"

#include "bsp/board.h"
#include "tusb.h"

void midi_task(void);

int main() {
    // stdio_init_all();
    board_init();
    tusb_init();
    // #ifndef PICO_DEFAULT_LED_PIN
    // #warning blink example requires a board with a regular LED
    // #else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (1)
    {
      tud_task(); // tinyusb device task
      midi_task();
      // busy_wait_us_32(250);
      gpio_put(LED_PIN, 1);
      busy_wait_us_32(250);
      gpio_put(LED_PIN, 0);
      busy_wait_us_32(250);
      // printf("Cicle completed");
    }
}


void midi_task(void){

  uint8_t const cable_num = 0; // MIDI jack associated with USB endpoint
  uint8_t const channel   = 0; // 0 for channel 1

  // uint32_t len = tud_midi_n_available(0,cable_num);
  // uint32_t len = 100;

  uint8_t packet[10];

  while (tud_midi_available())
  {
    tud_midi_stream_read(packet,10);
  }

  if (packet[0] < 0x80) return;

  uint32_t mess_len = 13;
  uint8_t mess[mess_len];

  mess[0] = 0xF0;
  mess[1] = 0x7D;

  for (int i = 0; i < mess_len-3; i++)
  {
    mess[i+2] = packet[i]%0x80;
  }

  mess[mess_len-1] = 0xF7;
  

  // uint8_t mess[13] = {0xF0,0x7D,packet[0]%0x80,packet[1]%0x80,packet[2]%0x80,packet[3]%0x80,packet[4]%0x80,packet[5]%0x80,packet[6]%0x80,packet[7]%0x80,packet[8]%0x80,packet[9]%0x80,0xF7};

  tud_midi_stream_write(cable_num,mess,mess_len);

}