#include "Buzzer.h"
#include <Arduino.h>
#include "config.h"

BootStatus Buzzer::setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
    ledcSetup(BUZZER_LEDC_CHANNEL, 2000, 8);
    ledcAttachPin(BUZZER_PIN, BUZZER_LEDC_CHANNEL);
    return {"Buzzer initialized successfully", true};
}

void Buzzer::beep(int frequency, int duration)
{
    ledcWriteTone(BUZZER_LEDC_CHANNEL, frequency);
    delay(duration);
    ledcWriteTone(BUZZER_LEDC_CHANNEL, 0);
}