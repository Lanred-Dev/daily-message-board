#pragma once

#include "classes/BootStatus.h"

namespace Updater
{
    inline unsigned long lastUpdateAt = 0;
    
    BootStatus setup();
    void loop();
    void checkForUpdates();
}