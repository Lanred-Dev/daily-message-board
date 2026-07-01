#pragma once

#include <string>
#include <vector>
#include <tuple>
#include "classes/BootStatus.h"

namespace MessageSystem
{
    inline int currentMessageIndex = 0;
    inline std::string currentMessageContent = "";
    inline unsigned long currentMessageTimestamp = 0;

    BootStatus setup();
    std::vector<std::string> readMessagesFile();
    std::tuple<std::string, unsigned long>  getMessageAtIndex(int index);
    std::tuple<std::string, unsigned long> getCurrentMessage();
    void cycleToNextMessage();
    void cycleToPreviousMessage();
    void setCurrentMessageToMostRecent();
    void addMessage(const std::string &newMessage);
}