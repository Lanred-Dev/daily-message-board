#pragma once

#include "classes/BootStatus.h"
#include <LovyanGFX.hpp>

class LGFX_E32R28T : public lgfx::LGFX_Device
{
    lgfx::Panel_ILI9341 _panel_instance;
    lgfx::Bus_SPI _bus_instance;
    lgfx::Light_PWM _light_instance;

public:
    LGFX_E32R28T(void)
    {
        {
            auto cfg = _bus_instance.config();
            cfg.spi_host = VSPI_HOST;
            cfg.spi_mode = 0;
            cfg.freq_write = 27000000;
            cfg.freq_read = 16000000;
            cfg.pin_sclk = 14;
            cfg.pin_mosi = 13;
            cfg.pin_miso = 12;
            cfg.pin_dc = 2;
            _bus_instance.config(cfg);
            _panel_instance.setBus(&_bus_instance);
        }
        {
            auto cfg = _panel_instance.config();
            cfg.pin_cs = 15;
            cfg.pin_rst = -1;
            cfg.memory_width = 240;
            cfg.memory_height = 320;
            cfg.panel_width = 240;
            cfg.panel_height = 320;
            cfg.offset_x = 0;
            cfg.offset_y = 0;
            _panel_instance.config(cfg);
        }
        {
            auto cfg = _light_instance.config();
            cfg.pin_bl = 21;
            cfg.freq = 44100;
            cfg.pwm_channel = 7;
            _light_instance.config(cfg);
            _panel_instance.setLight(&_light_instance);
        }
        setPanel(&_panel_instance);
    }
};

namespace Display
{
    inline static LGFX_E32R28T lcd;

    struct Color
    {
        static constexpr uint16_t BLACK = 0x0000;
        static constexpr uint16_t WHITE = 0xFFFF;
        static constexpr uint16_t RED = 0xF800;
        static constexpr uint16_t GREEN = 0x07E0;
        static constexpr uint16_t BLUE = 0x001F;
        static constexpr uint16_t YELLOW = 0xFFE0;
        static constexpr uint16_t ORANGE = 0xFD20;
    };

    BootStatus setup();
    void clear(const uint16_t color = Color::BLACK);
}
