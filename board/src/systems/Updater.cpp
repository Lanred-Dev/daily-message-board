#include "Updater.h"
#include "config.h"
#include <Arduino.h>
#include "core/Internet.h"
#include "core/Storage.h"

void Updater::loop()
{
    unsigned long now = millis();

    if (now - lastUpdateAt >= UPDATE_CHECK_INTERVAL)
    {
        lastUpdateAt = now;
        checkForUpdates();
    }
}

void Updater::checkForUpdates()
{
    std::string timeResponse = Internet::fetch(TIME_UPDATE_URL);
    std::string savedTime = Storage::readTxt("/lastUpdatedAt.txt");

    if (timeResponse == savedTime)
        return;

    Storage::writeTxt("/lastUpdatedAt.txt", timeResponse.c_str());

    std::string messageResponse = Internet::fetch(MESSAGE_UPDATE_URL);
    std::string imageResponse = Internet::fetch(IMAGE_UPDATE_URL);
    std::string calendarResponse = Internet::fetch(CALENDAR_UPDATE_URL);
}