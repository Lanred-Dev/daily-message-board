#pragma once

#include <string>
#include <array>
#include "config.h"

namespace MessageSystem
{
    extern std::string currentMessage;
    extern int currentImageIndex;
    extern std::array<uint8_t, IMAGE_SIZE_BYTES> currentImageBitmapBuffer;

    void newMessage();
    void requestNewMessage();
    void setImageViewActive(bool isActive);
    void loop();
}