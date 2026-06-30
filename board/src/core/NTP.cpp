#include "NTP.h"
#include "config.h"
#include <Arduino.h>

BootStatus NTP::setup()
{
    configTime(TIMEZONE_OFFSET, DAYLIGHT_SAVINGS_OFFSET, NTP_SERVER);

    if (!getTime())
        return {"Failed to get time from NTP server.", false};

    return {"NTP setup successful.", true};
}

unsigned long NTP::getTime()
{
    return time(nullptr);
}