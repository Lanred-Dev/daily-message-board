#include <Arduino.h>
#include "MessageChangeButton.h"
#include "config.h"

unsigned long lastPressTime = millis() - BUTTON_PRESS_DEBOUNCE_TIME;
bool lastButtonState = HIGH;

BootStatus MessageChangeButton::setup()
{
    pinMode(MESSAGE_CHANGE_BUTTON_PIN, INPUT_PULLUP);
    return {"MessageChangeButton initialized successfully", true};
}

bool MessageChangeButton::isPressed()
{
    bool currentState = digitalRead(MESSAGE_CHANGE_BUTTON_PIN);
    bool triggered = false;
    unsigned long now = millis();

    if (currentState != lastButtonState && (now - lastPressTime) > BUTTON_PRESS_DEBOUNCE_TIME)
    {
        if (currentState == LOW)
        {
            triggered = true;
        }

        lastButtonState = currentState;
        lastPressTime = now;
    }

    return triggered;
}