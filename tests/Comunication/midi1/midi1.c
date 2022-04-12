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

uint8_t const cable_num = 0; // MIDI jack associated with USB endpoint
uint8_t const channel   = 0; // 0 for channel 1

void midi_task(void);
void simple_send(const uint8_t packet[],const uint32_t len);
void send_w_recive(const uint8_t packet[],const uint32_t len);
void send_w_recive_sysex(const uint8_t packet[],const uint32_t orlen);

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

  uint32_t len = tud_midi_n_available(0,cable_num);
  // uint32_t len = 100;

  uint8_t packet[len];

  while (tud_midi_available())
  {
    tud_midi_stream_read(packet,len);
  }

  if (packet[0] < 0x80) return;

  if (packet[0] == 0xF0){
    send_w_recive_sysex(packet,len);
    // simple_send(packet,len);
  }
  else {
    send_w_recive(packet,len);
  }

}

void simple_send(const uint8_t packet[],const uint32_t len){
  

  uint8_t simp[8];

  simp[0] = 0xF0;
  simp[1] = 0x7D;
  simp[2] = packet[0]%0x80;
  simp[3] = packet[1]%0x80;
  simp[4] = packet[2]%0x80;
  simp[5] = packet[len-2]%0x80;
  simp[6] = packet[len-1]%0x80;
  simp[7] = 0xF7;
  tud_midi_stream_write(cable_num,simp,8);
}

void send_w_recive(const uint8_t packet[],const uint32_t len){
  uint32_t mess_len = len + 4;
  uint8_t mess[mess_len];

  mess[0] = 0xF0;
  mess[1] = 0x7D;

  for (int i = 0; i < len; i++)
  {
    mess[i+2] = packet[i]%0x80;
  }

  mess[mess_len-2] = 0xF7;
  mess[mess_len-1] = 0x00;
  

  // uint8_t mess[13] = {0xF0,0x7D,packet[0]%0x80,packet[1]%0x80,packet[2]%0x80,packet[3]%0x80,packet[4]%0x80,packet[5]%0x80,packet[6]%0x80,packet[7]%0x80,packet[8]%0x80,packet[9]%0x80,0xF7};

  tud_midi_stream_write(cable_num,mess,mess_len);
}


void send_w_recive_sysex(const uint8_t packet[],const uint32_t orlen){

  uint32_t len = orlen;
  uint8_t sysex_len = orlen%0x80;
  bool mssg_end = 0;

  for (int i = 0; i < orlen; i++)
  {
    if (packet[i] == 0xF7)
    {
      len = i+1;
      sysex_len = (i+1)%0x80;
      mssg_end = 1;
    }
    
  }
  
  
  uint8_t simp[9];

  simp[0] = 0xF0;
  simp[1] = 0x7D;
  simp[2] = packet[0]%0x80;
  simp[3] = packet[1]%0x80;
  simp[4] = packet[2]%0x80;
  simp[5] = packet[len-2]%0x80;
  simp[6] = packet[len-1]%0x80;
  simp[7] = sysex_len;
  simp[8] = 0xF7;
  tud_midi_stream_write(cable_num,simp,9);
}
