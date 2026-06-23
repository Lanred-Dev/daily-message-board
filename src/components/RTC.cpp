#include "RTC.h"
#include <Arduino.h>
#include "config.h"

BootStatus RTC::setup()
{
    if (!rtc.begin()) return { "Could not find RTC module", false };
    if (rtc.lostPower()) return { "RTC lost power, please reset time", false };

    return { "RTC initialized successfully", true };
}

DateTime RTC::getTime()
{
    return rtc.now();
}