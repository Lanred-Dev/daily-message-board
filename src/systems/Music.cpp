#include "Music.h"
#include "components/Buzzer.h"
#include <Arduino.h>

void Music::morningAlarm()
{
    Buzzer::beep(E4, 200);
    delay(50);
    Buzzer::beep(GS4, 200);
    delay(50);
    Buzzer::beep(B4, 200);
    delay(50);
    Buzzer::beep(DS5, 200);
    delay(50);
    Buzzer::beep(E5, 200);
    delay(150);
    Buzzer::beep(E5, 600);
    delay(50);
    Buzzer::beep(DS5, 200);
    delay(50);
    Buzzer::beep(B4, 200);
    delay(50);
    Buzzer::beep(E4, 800);
    delay(100);
    Buzzer::beep(GS4, 400);
    delay(100);
    Buzzer::beep(A4, 400);
    delay(100);
    Buzzer::beep(B4, 400);
    delay(100);
    Buzzer::beep(E4, 200);
    delay(50);
    Buzzer::beep(GS4, 200);
    delay(50);
    Buzzer::beep(B4, 200);
    delay(50);
    Buzzer::beep(DS5, 200);
    delay(50);
    Buzzer::beep(E5, 400);
    delay(100);
    Buzzer::beep(E4, 2000);
}

void Music::newMessageNotification()
{
    Buzzer::beep(C5, 80);
    delay(30);
    Buzzer::beep(E5, 80);
    delay(30);
    Buzzer::beep(A5, 650);
}

void Music::errorNotification()
{
    Buzzer::beep(DS4, 250);
    delay(80);
    Buzzer::beep(A3, 600);
}