const uint8_t cable_num = 0; // MIDI jack associated with USB endpoint

const uint greenLedPin = PICO_DEFAULT_LED_PIN;
const uint whiteLedPin = 9;
const uint pushBtnInPin = 12;
gpio_init(greenLedPin);
gpio_init(whiteLedPin);
gpio_init(pushBtnInPin);

gpio_set_dir(greenLedPin,GPIO_OUT);
gpio_set_dir(whiteLedPin,GPIO_OUT);
gpio_set_dir(pushBtnInPin,GPIO_IN);

// gpio_pull_up(pushBtnInPin);


uint8_t clock_tics = 0;

bool read_push_btn();
void read_midi();
void write_midi();