#include "Message.h"
#include "core/Storage.h"

BootStatus MessageSystem::setup()
{
    setCurrentMessageToMostRecent();
    return {"Message system initialized successfully.", true};
}

std::vector<std::string> MessageSystem::readMessagesFile()
{
    std::string rawMessages = Storage::readTxt("/messages.txt");
    std::vector<std::string> messages;

    size_t position = 0;
    while ((position = rawMessages.find('\n')) != std::string::npos)
    {
        messages.push_back(rawMessages.substr(0, position));
        rawMessages.erase(0, position + 1);
    }

    if (!messages.empty())
        messages.push_back(rawMessages);

    return messages;
}

std::tuple<std::string, unsigned long> MessageSystem::getMessageAtIndex(int index)
{
    std::vector<std::string> messages = readMessagesFile();

    if (index < 0 || index >= messages.size())
        return std::make_tuple("", 0);

    std::string message = messages[index];
    size_t position = message.find(' ');

    if (position == std::string::npos)
        return std::make_tuple(message, 0);

    std::string content = message.substr(0, position);
    unsigned long timestamp = std::stoul(message.substr(position + 1));
    return std::make_tuple(content, timestamp);
}

std::tuple<std::string, unsigned long> MessageSystem::getCurrentMessage()
{
    std::tuple<std::string, unsigned long> message = getMessageAtIndex(currentMessageIndex);
    currentMessageContent = std::get<0>(message);
    currentMessageTimestamp = std::get<1>(message);
    return message;
}

void MessageSystem::cycleToNextMessage()
{
    currentMessageIndex++;
    std::vector<std::string> messages = readMessagesFile();

    if (currentMessageIndex >= messages.size())
        currentMessageIndex = 0;

    getCurrentMessage();
}

void MessageSystem::cycleToPreviousMessage()
{
    currentMessageIndex--;
    std::vector<std::string> messages = readMessagesFile();

    if (currentMessageIndex < 0)
        currentMessageIndex = messages.size() - 1;

    getCurrentMessage();
}

void MessageSystem::setCurrentMessageToMostRecent()
{
    std::vector<std::string> messages = readMessagesFile();
    currentMessageIndex = messages.size() - 1;
    getCurrentMessage();
}

void MessageSystem::addMessage(const std::string &newMessage)
{
    std::vector<std::string> messages = readMessagesFile();
    messages.push_back(newMessage);

    std::string newMessages;
    for (const auto &message : messages)
    {
        newMessages += message + "\n";
    }

    Storage::writeTxt("/messages.txt", newMessages.c_str());
}