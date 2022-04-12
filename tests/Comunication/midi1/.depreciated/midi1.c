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
    // while (true)
    // {
      
    //   tud_task();
    //   midi_task();
    //   uint32_t to = time_us_32();
    //   // printf("Entering to onoff mode");
    //   while ((time_us_32() - to) < 5000000) {
    //     gpio_put(LED_PIN, 1);
    //     busy_wait_us_32(250);
    //     gpio_put(LED_PIN, 0);
    //     busy_wait_us_32(250);
    //   }
    //   // printf("Entering to on only mode");
    //   while ((time_us_32() - to) < 10000000)
    //   {
    //     gpio_put(LED_PIN,1);
    //   }
      // #endif
    // }
}

// Invoked when device is mounted
void tud_mount_cb(void)
{
  // blink_interval_ms = 250;
}

// Invoked when device is unmounted
void tud_umount_cb(void)
{
  // blink_interval_ms = BLINK_NOT_MOUNTED;
}

// Invoked when usb bus is suspended
// remote_wakeup_en : if host allow us  to perform remote wakeup
// Within 7ms, device must draw an average of current less than 2.5 mA from bus
void tud_suspend_cb(bool remote_wakeup_en)
{
  (void) remote_wakeup_en;
  // blink_interval_ms = BLINK_SUSPENDED;
}

// Invoked when usb bus is resumed
void tud_resume_cb(void)
{
  // blink_interval_ms = BLINK_MOUNTED;
}

// Variable that holds the current position in the sequence.
// uint32_t note_pos = 0;

// // Store example melody as an array of note values
// uint8_t note_sequence[] =
// {
//   74,78,81,86,90,93,98,102,57,61,66,69,73,78,81,85,88,92,97,100,97,92,88,85,81,78,
//   74,69,66,62,57,62,66,69,74,78,81,86,90,93,97,102,97,93,90,85,81,78,73,68,64,61,
//   56,61,64,68,74,78,81,86,90,93,98,102
// };

void midi_task(void){
  static uint32_t start_ms = 0;

  uint8_t const cable_num = 0; // MIDI jack associated with USB endpoint
  uint8_t const channel   = 0; // 0 for channel 1

  // The MIDI interface always creates input and output port/jack descriptors
  // regardless of these being used or not. Therefore incoming traffic should be read
  // (possibly just discarded) to avoid the sender blocking in IO
  uint8_t packet[10];
  uint8_t recibe[4] = {0xF0,0x7D,packet[0],0xF7};
  // uint whiteled = 9;
  // gpio_set_dir(whiteled, GPIO_OUT);

  // while ( tud_midi_available() ) {
  //   // uint8_t message = tud_midi_packet_read(packet);
  //   // uint8_t note_off[3] = { 0x80 | channel, message, 0};
  //   // tud_midi_stream_write(cable_num, note_off, 3);
  //   gpio_put(whiteled, 1);
  //   tud_midi_packet_read(packet);
  //   uint8_t note_on[3] = { 0x90 | channel, packet[1], 127 };
  //   // uint8_t note_off[3] = { 0x80 | channel, packet[1], 0};
  //   tud_midi_stream_write(cable_num, note_on, 3);
  //   // tud_midi_stream_write(cable_num, note_off, 3);

  // }

  // while ( tud_midi_available() ) tud_midi_stream_read(packet,4);


// uint32_t len = tud_midi_n_available(cable_num,cable_num);

while (tud_midi_available())
{
  tud_midi_stream_read(packet,10);
}


  

  // tud_midi_stream_read()
  // tud_midi_receive

  // gpio_put(whiteled, 1);
  // tud_midi_packet_read(packet);

  // for (int i = 0; i < 100; i++)
  // {
  //   if (packet[i] == 0xF0){
    
  //   int8_t mess[3] = {0xA0,100,i};
  //   tud_midi_stream_write(cable_num,mess,3);

  //   }
  // }
  

  // if (packet[1] == 0) return;
  // if (packet[1] < 0x80) return;
  if (packet[0] < 0x80) return;

  // uint8_t no1[4] = {0xD0,0,0,0};
  // uint8_t no2[4] = {0,0,0,0xD0};
  // uint8_t at0[4];
  // at0[0] = 0xD0;
  // at0[1] = 0;
  // uint8_t at0[4] = {0x00,0x00,0x00,0xD0};

  // if (packet[0] == 0x00 && packet[1] == 0x00 && packet[2] == 0x00 && packet[3] == 0xD0) return;
  // if (packet[0] == 0x0C && packet[1] == 0x00 && packet[2] == 0x00 && packet[3] == 0x00) return;
  // if (packet == {0x0C,0x00,0x00,0x00}) return;
  // if (packet == no1) return;
  // if (packet == no2) return;
  // if (board_millis() - start_ms < 1500) return; // not enough time
  // start_ms += 286;
  // recibe[2] = packet[0];
  // tud_midi_stream_write(cable_num, recibe, 4);
  // recibe[2] = packet[1];
  // tud_midi_stream_write(cable_num, recibe, 4);
  // recibe[2] = packet[2];
  // tud_midi_stream_write(cable_num, recibe, 4);
  // recibe[2] = packet[3];
  // tud_midi_stream_write(cable_num, recibe, 4);

  // tud_midi_stream_write(cable_num,packet,3);

  // uint8_t part1[4] = {0xF0,0x7D,packet[1],packet[1]};
  // uint8_t part2[4] = {packet[2],packet[3],0xF7,0x00};

  uint8_t mess[13] = {0xF0,0x7D,packet[0]%0x80,packet[1]%0x80,packet[2]%0x80,packet[3]%0x80,packet[4]%0x80,packet[5]%0x80,packet[6]%0x80,packet[7]%0x80,packet[8]%0x80,packet[9]%0x80,0xF7};

  tud_midi_stream_write(cable_num,mess,13);
  // tud_midi_stream_write(cable_num,part2,3);
  
  // uint8_t note_on[3] = { 0x90 | channel, packet[5], 127 };
  // uint8_t note_off[3] = { 0x80 | channel, packet[1], 0};
  // tud_midi_stream_write(cable_num, note_on, 3);

  // if (packet[1] == )

  // if (packet[1] == 0xF0){
  //   uint recibe[100]
  //   for (int i = 0; i < 100; i++)
  //   {
  //     /* code */
  //   }
    
  // }

  // uint8_t recibe[99];
  // int len;
  
  

  // if (0x7F < packet[1] < 0x90){
    // uint8_t recibe[3] = {packet[1],packet[2],packet[3]};
  // if (packet[1] == 0xF0){
  //   // for (int i = 0; i < 99; i++)
  //   // {
  //   //   recibe[i] = packet[i+1];
  //   //   if (packet[i+1] == 0xF7){
  //   //     len = i;
  //   //     break;
  //   //   }
  //   // }
  //   // tud_midi_stream_write(cable_num, recibe, len);
  //   int8_t mess[3] = {0xB0,100,100};
  //   tud_midi_stream_write(cable_num,mess,3);
  // }
  // else
  // {


    // for (int i =0; i < 4; i++){
    //   recibe[i] = packet[i+1];
    // }
    // tud_midi_stream_write(cable_num, recibe, 3); //-----------------------------------------------------------------------------


  // }
  
    
  // }

  // if (0x8F < packet[1] < 0xA0){
  //   uint8_t note_on[3] = {packet[1],packet[2],packet[3]};
  //   tud_midi_stream_write(cable_num, note_on, 3);
  // }



  // // send note periodically
  // if (board_millis() - start_ms < 286) return; // not enough time
  // start_ms += 286;

  // // Previous positions in the note sequence.
  // int previous = note_pos - 1;

  // // If we currently are at position 0, set the
  // // previous position to the last note in the sequence.
  // if (previous < 0) previous = sizeof(note_sequence) - 1;

  // // Send Note On for current position at full velocity (127) on channel 1.
  // uint8_t note_on[3] = { 0x90 | channel, note_sequence[note_pos], 127 };
  // tud_midi_stream_write(cable_num, note_on, 3);

  // // Send Note Off for previous note.
  // uint8_t note_off[3] = { 0x80 | channel, note_sequence[previous], 0};
  // tud_midi_stream_write(cable_num, note_off, 3);

  // // Increment position
  // note_pos++;

  // // If we are at the end of the sequence, start over.
  // if (note_pos >= sizeof(note_sequence)) note_pos = 0;
}

