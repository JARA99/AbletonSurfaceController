#include "pico/stdlib.h"
#include "displayKnobs.h"

#include "ili9341.h"
#include "gfx.h"

void printChar(uint8_t number)
{
    char adsr[4] = {'A','D','S','R'};
    LCD_initDisplay();
    LCD_setRotation(-1);
    GFX_createFramebuf();

    // GFX_setClearColor(0xFF20);
    // GFX_setTextBack(0xFF20);
    GFX_clearScreen();
    GFX_fillScreen(0x0000);
    GFX_setTextColor(0xFFFF);

    GFX_setCursor(10, 10+18);
    // GFX_setFont(&FreeSerifBold18pt7b);
    // GFX_printf("%c",number);
    GFX_flush();
}

void example()
{
    char adsr[4] = {'A','D','S','R'};
    LCD_initDisplay();
    LCD_setRotation(-1);
    GFX_createFramebuf();

    // GFX_setClearColor(0xFF20);
    // GFX_setTextBack(0xFF20);
    GFX_clearScreen();
    GFX_fillScreen(0x9C3F);
    GFX_setTextColor(0x0000);

    GFX_setCursor(10, 10+18);
    // GFX_setFont(&FreeSerifBold18pt7b);
    GFX_printf("Valhalla Superma");

    GFX_setCursor(10, 10+18+28);
    // GFX_setFont(&FreeSerif9pt7b);
    GFX_printf("Misc - Extra");
    
    // GFX_setCursor(185, 120);
    // GFX_setFont(&FreeSerif9pt7b);
    // GFX_printf("Filters");

    // GFX_setFont(&FreeSerifBold12pt7b);
    // GFX_printf("Serif\n");

    // GFX_setFont(&FreeMonoBold12pt7b);
    // GFX_printf("Mono\n");

    // GFX_setFont(&FreeSans12pt7b);
    // GFX_printf("Sans\n");

    // GFX_setFont(&FreeSerif12pt7b);
    // GFX_printf("Serif\n");

    // GFX_setFont(&FreeMono12pt7b);
    // GFX_printf("Mono\n");


    GFX_setTextColor(0x0000);
    // GFX_setFont(&Picopixel);

    for (int i = 0; i < 3; i++)
    {
        GFX_fillCircle(17+24+34*i, 140, 15, 0xFD00);
        // GFX_setCursor(2+24+34*i, 140);
        // GFX_printf("Its: %d",i);
    }

    GFX_fillCircle(160, 140, 18, 0xFC00);

    // GFX_setFont(&TomThumb);

    for (int i = 0; i < 3; i++)
    {
        GFX_fillCircle(320-17-24-34*i, 140, 15, 0xFD1E);
        // GFX_setCursor(320-17-15-24-34*i, 140);
        // GFX_printf("Its: %d",i);
    }

    // GFX_setFont(&FreeSerif9pt7b);

    for (int i = 0; i < 4; i++)
    {
        GFX_fillCircle(24+34*i, 170, 15, 0x901F);
        GFX_setCursor(18+34*i, 175);
        GFX_printf("%c",adsr[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        GFX_fillCircle(320-24-34*i, 170, 15, 0x5800);
    }

    for (int i = 1; i < 7; i++)
    {
        GFX_fillCircle(17+24+34*i, 200, 15, 0x04D2);
    }

    GFX_fillCircle(17+24, 200, 10, 0x08D2);
    GFX_fillCircle(17+24+238, 200, 10, 0x0412);

    GFX_drawCircle(17+24, 140, 17, 0xFD00);

    GFX_flush();
}