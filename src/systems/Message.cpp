#include "Message.h"
#include "components/Display.h"
#include "systems/Music.h"
#include <LittleFS.h>

int recentlyUsedMessages[5] = {-1, -1, -1, -1, -1};
unsigned long lastChangeRequestTime = millis() - MESSAGE_CHANGE_BUTTON_DEBOUNCE_TIME;
bool isImageViewActive = false;
bool wasLastRenderImageView = false;
bool shouldRerenderCurrentView = false;
std::string MessageSystem::currentMessage = "";
int MessageSystem::currentImageIndex = 0;
std::array<uint8_t, IMAGE_SIZE_BYTES> MessageSystem::currentImageBitmapBuffer{};

void addRecentlyUsed(int newIndex)
{
    for (int index = 4; index > 0; index--)
    {
        recentlyUsedMessages[index] = recentlyUsedMessages[index - 1];
    }

    recentlyUsedMessages[0] = newIndex;
}

std::string getMessageFromFilesystem()
{
    File file = LittleFS.open(MESSAGES_FILE_PATH, "r");

    if (!file)
    {
        Serial.println("MessageSystem: Failed to open messages.txt");
        return "";
    }

    std::string lineBuffer = "";
    int currentIndex = 0;
    int targetIndex = random(0, MESSAGE_COUNT);

    while (file.available())
    {
        char character = file.read();

        if (character == '\n')
        {
            if (currentIndex == targetIndex)
            {
                file.close();
                lineBuffer.erase(0, lineBuffer.find_first_not_of(" \t"));
                lineBuffer.erase(lineBuffer.find_last_not_of(" \t") + 1);
                return lineBuffer;
            }

            lineBuffer = "";
            currentIndex++;
        }
        else
        {
            lineBuffer += character;
        }
    }

    file.close();
    return "";
}

std::array<uint8_t, IMAGE_SIZE_BYTES> getImageFromFilesystem()
{
    File masterBin = LittleFS.open("/images.bin", "r");
    std::array<uint8_t, IMAGE_SIZE_BYTES> bitmapBuffer{};

    if (!masterBin)
    {
        Serial.println("MessageSystem: Could not open images.bin");
        return bitmapBuffer;
    }

    int index = random(0, TOTAL_IMAGES_IN_BIN);

    size_t byteOffset = index * IMAGE_SIZE_BYTES;
    masterBin.seek(byteOffset);
    masterBin.read(bitmapBuffer.data(), IMAGE_SIZE_BYTES);
    masterBin.close();
    return bitmapBuffer;
}

void MessageSystem::newMessage()
{
    Serial.println("MessageSystem: Getting new message...");

    Display::clear();

    currentMessage = getMessageFromFilesystem();
    currentImageBitmapBuffer = getImageFromFilesystem();

    shouldRerenderCurrentView = true;
}

void MessageSystem::requestNewMessage()
{
    Serial.println("MessageSystem: Requesting new message...");

    unsigned long now = millis();

    if (now - lastChangeRequestTime > MESSAGE_CHANGE_BUTTON_DEBOUNCE_TIME)
    {
        lastChangeRequestTime = now;
        newMessage();
        Music::newMessageNotification();
    }
    else
    {
        Serial.println("MessageSystem: Change request ignored due to debounce time");
        Music::errorNotification();
    }
}

void MessageSystem::setImageViewActive(bool isActive)
{
    isImageViewActive = isActive;
}

void MessageSystem::loop()
{
    if (isImageViewActive && (!wasLastRenderImageView || shouldRerenderCurrentView))
    {
        Display::drawImage(currentImageBitmapBuffer);
        wasLastRenderImageView = true;
    }
    else if (!isImageViewActive && (wasLastRenderImageView || shouldRerenderCurrentView))
    {
        Display::print(currentMessage.c_str());
        wasLastRenderImageView = false;
    }

    shouldRerenderCurrentView = false;
}