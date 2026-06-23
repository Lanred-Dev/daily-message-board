#include "DisplayViewSwitch.h"
#include <Arduino.h>
#include "config.h"

BootStatus DisplayViewSwitch::setup()
{
    pinMode(DISPLAY_BUTTON_VIEW_SWITCH_PIN, INPUT_PULLUP);
    return {"DisplayViewSwitch initialized successfully", true};
}

bool DisplayViewSwitch::isOpen()
{
    return digitalRead(DISPLAY_BUTTON_VIEW_SWITCH_PIN) == LOW;
}