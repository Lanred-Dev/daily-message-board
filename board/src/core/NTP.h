#pragma once

#include "classes/BootStatus.h"

namespace NTP {
    BootStatus setup();
    unsigned long getTime();
}