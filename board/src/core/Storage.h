#pragma once

#include "classes/BootStatus.h"
#include <string>

namespace Storage {
    BootStatus setup();
    bool writeTxt(const char *path, const char *content);
    std::string readTxt(const char *path);
}