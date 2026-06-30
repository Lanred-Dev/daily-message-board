#include "Display.h"

BootStatus Display::setup()
{
    lcd.init();
    lcd.setRotation(1);
    
    clear();

    return {"Display initialized successfully.", true};
}

void Display::clear(const uint16_t color)
{
    lcd.fillScreen(color);
}