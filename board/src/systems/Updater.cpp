#include "Updater.h"
#include "config.h"
#include <Arduino.h>
#include "core/Internet.h"
#include "core/Storage.h"
#include "systems/Message.h"

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
    std::string lastUpdateTime = Internet::fetch(LAST_UPDATE_TIME_URL);
    std::string savedTime = Storage::readTxt("/last-updated-at.txt");

    if (lastUpdateTime == savedTime)
        return;

    Storage::writeTxt("/last-updated-at.txt", lastUpdateTime.c_str());

    std::string messageResponse = Internet::fetch(GET_MESSAGE_UPDATE_URL);

    if (!messageResponse.empty() && messageResponse != MessageSystem::currentMessageContent)
    {
        MessageSystem::addMessage(messageResponse);
        MessageSystem::currentMessageIndex = MessageSystem::readMessagesFile().size() - 1;
    }

    std::string imageResponse = Internet::fetch(GET_IMAGE_UPDATE_URL);
    std::string calendarResponse = Internet::fetch(GET_CALENDAR_UPDATE_URL);
}