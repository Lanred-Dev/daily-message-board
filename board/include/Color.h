#pragma once

#include <cstdint>

struct Color
    {
        static constexpr uint16_t BLACK                = 0x0000; 
        static constexpr uint16_t WHITE                = 0xFFFF; 

        static constexpr uint16_t CONTAINER_BACKGROUND = 0x296B;
        
        static constexpr uint16_t PRIMARY_BUTTON       = 0x1B9F;
        static constexpr uint16_t LIGHT_BUTTON         = 0x3A59;
        
        static constexpr uint16_t TEXT_MAIN            = 0xEFFE;
        static constexpr uint16_t TEXT_MUTED           = 0x7BF2;

        static constexpr uint16_t RED                  = 0xF800;
        static constexpr uint16_t GREEN                = 0x07E0;
        static constexpr uint16_t BLUE                 = 0x001F;
        static constexpr uint16_t YELLOW               = 0xFFE0;
        static constexpr uint16_t ORANGE               = 0xFD20;
    };