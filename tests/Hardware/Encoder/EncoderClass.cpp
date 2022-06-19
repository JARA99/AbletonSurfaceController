#include "pico/stdlib.h"
#include <stdio.h>

class Encoder
{
private:
    uint change_pin;
    uint dir_pin;
    uint column_pin;
    uint name;
    // uint

    bool last = 1;

public:
    
    Encoder(uint change, uint dir, uint column, uint encoder_number){
        change_pin = change;
        dir_pin = dir;
        column_pin = column;
        name = encoder_number;
    }

    ~Encoder(){

    }

    void read(){
        gpio_put(column_pin,1);
        bool change = gpio_get(change_pin);
        bool dir = gpio_get(dir_pin);

        if (last != change)
        {
            last = change;
            if (dir != change)
            {
                // printf(name);
                printf(" direction: <---\n");
                // gpio_put(25,1);
                // sleep_ms(1000);
                // gpio_put(25,0);
                // sleep_ms(1000);
            }
            else
            {
                // printf(name);
                printf(" direction: --->\n");
                // gpio_put(25,1);
                // sleep_ms(500);
                // gpio_put(25,0);
                // sleep_ms(500);
                // gpio_put(25,1);
                // sleep_ms(500);
                // gpio_put(25,0);
                // sleep_ms(1000);
            }
            
        }    

        gpio_put(column_pin,0);
    }
};