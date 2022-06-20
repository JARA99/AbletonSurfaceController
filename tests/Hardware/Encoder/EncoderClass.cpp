#include "pico/stdlib.h"
#include <stdio.h>

class Encoder
{
private:
    uint change_pin;
    uint dir_pin;
    uint column_pin;
    uint name;

    bool last = 0;
    // int count = 0;

    bool confirm_dir;

public:
    
    Encoder(uint change, uint dir, uint column, uint name_letter){
        change_pin = change;
        dir_pin = dir;
        column_pin = column;
        name = name_letter;
    }

    ~Encoder(){

    }

    void read(){
        uint8_t cycle = 0;
        gpio_put(column_pin,1);

        while (cycle < 250)
        {
            cycle += 1;

            bool change = gpio_get(change_pin);
            bool dir = gpio_get(dir_pin);

            if (last != change)
            {
                last = change;
                if (change == 1)
                {
                    if (dir != change)
                    {
                        confirm_dir = 1;
                    }
                    else
                    {
                        confirm_dir = 0;
                    }
                }
                else
                {
                    if (dir != change & confirm_dir)
                    {
                        printf("%d direction: <---\n",name);
                    }
                    else if(dir == change & !confirm_dir)
                    {
                        printf("%d direction: --->\n",name);
                    }
                }
            
            }
        }
        gpio_put(column_pin,0);
    }
};