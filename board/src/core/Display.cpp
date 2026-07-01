#include "Display.h"
#include "config.h"
#include "systems/UI.h"

BootStatus Display::setup()
{
    lcd.init();
    lcd.setRotation(1);

    canvas.setColorDepth(8);

    if (canvas.createSprite(DISPLAY_WIDTH, DISPLAY_HEIGHT) == nullptr) return {"Failed to create display canvas sprite.", false};

    clear();

    return {"Display initialized successfully.", true};
}

void Display::clear(const uint16_t color)
{
    canvas.fillScreen(color);
}

void Display::loop()
{
    Display::updateTouch();
    UI::draw();
    canvas.pushSprite(0, 0);
    delay(16);
}

void Display::updateTouch() {
    int16_t touchX = 0;
    int16_t touchY = 0;

    if (lcd.getTouch(&touchX, &touchY)) {
        touchPosition.x = touchX;
        touchPosition.y = touchY;
        isTouched = true;
    } else {
        isTouched = false;
    }
}

std::optional<Vector2> Display::getTouchPosition() {
    if (!isTouched) {
        return std::nullopt;
    }

    return touchPosition;
}