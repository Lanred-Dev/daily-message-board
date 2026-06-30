#pragma once

namespace Updater
{
    inline static unsigned long lastUpdateAt = 0;
    
    void loop();
    void checkForUpdates();
}