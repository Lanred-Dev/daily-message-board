#pragma once

#include "classes/BootStatus.h"

namespace Buzzer {
    BootStatus setup();
    void beep(int frequency, int duration = 100);
}