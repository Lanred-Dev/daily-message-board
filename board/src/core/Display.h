#pragma once

#include "classes/BootStatus.h"
#include "classes/LGFX_E32R28T.h"
#include "math/Vector2.h"
#include <optional>

namespace Display
{
    inline LGFX_E32R28T lcd;
    inline LGFX_Sprite canvas(&lcd);
    inline Vector2 touchPosition;
    inline bool isTouched = false;

    struct Color
    {
        static constexpr uint16_t BLACK = 0x0000;
        static constexpr uint16_t CONTAINER_BACKGROUND = 0x18C3;
        static constexpr uint16_t WHITE = 0xFFFF;
        static constexpr uint16_t RED = 0xF800;
        static constexpr uint16_t GREEN = 0x07E0;
        static constexpr uint16_t BLUE = 0x001F;
        static constexpr uint16_t YELLOW = 0xFFE0;
        static constexpr uint16_t ORANGE = 0xFD20;
    };

    BootStatus setup();
    void clear(const uint16_t color = Color::BLACK);
    void loop();
    void updateTouch();
    std::optional<Vector2> getTouchPosition();
}
