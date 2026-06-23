#include "Routine.h"
#include "components/RTC.h"
#include "config.h"
#include "systems/Message.h"
#include "systems/Music.h"

int lastCheckedDay = -1;

void Routine::loop()
{
    DateTime now = RTC::getTime();

    if (now.hour() == ALARM_TIME_HOUR && now.day() != lastCheckedDay)
    {
        lastCheckedDay = now.day();
        MessageSystem::newMessage();
        Music::morningAlarm();
    }
}