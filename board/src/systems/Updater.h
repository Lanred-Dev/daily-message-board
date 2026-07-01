#pragma once

namespace Updater
{
    inline unsigned long lastUpdateAt = 0;
    
    void loop();
    void checkForUpdates();
}