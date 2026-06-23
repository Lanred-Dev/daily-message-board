#pragma once

#include <RTClib.h>
#include "classes/BootStatus.h"

namespace RTC {
    static RTC_DS3231 rtc;

    BootStatus setup();
    DateTime getTime();
}