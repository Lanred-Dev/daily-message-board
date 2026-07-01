#pragma once

#include "classes/BootStatus.h"
#include "classes/LGFX_E32R28T.h"
#include "math/Vector2.h"
#include <optional>
#include "Color.h"

namespace Display
{
    inline LGFX_E32R28T lcd;
    inline LGFX_Sprite canvas(&lcd);
    inline Vector2 touchPosition;
    inline bool isTouched = false;

    BootStatus setup();
    void clear(const uint16_t color = Color::BLACK);
    void loop();
    void updateTouch();
    std::optional<Vector2> getTouchPosition();
}
