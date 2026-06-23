#pragma once

#include <Adafruit_SSD1306.h>
#include "config.h"
#include "classes/BootStatus.h"

namespace Display {
    extern Adafruit_SSD1306 display;

    BootStatus setup();
    void clear();
    void drawImage(std::array<uint8_t, IMAGE_SIZE_BYTES> &bitmapBuffer);
    void print(const char* message);
}