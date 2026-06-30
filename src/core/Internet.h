#pragma once

#include <WiFiManager.h>
#include <string>
#include "classes/BootStatus.h"

namespace Internet {
    inline static WiFiManager manager;

    BootStatus setup();
    std::string fetch(const char *url);
}