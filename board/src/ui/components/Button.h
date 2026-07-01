#pragma once

#include "ui/components/Instance.h"
#include "TextLabel.h"
#include "math/Vector2.h"
#include "core/Display.h"
#include "classes/Signal.h"

class Button : public Instance
{
private:
    bool lastPressedState;

public:
    TextLabel label;
    Signal<> onPress;
    uint16_t backgroundColor;
    int32_t cornerRadius = 4;

    Button(const Vector2 &position, const Vector2 &size,
           const std::string &text,
           uint16_t backgroundColor = Display::Color::BLUE, uint16_t textColor = Display::Color::WHITE, int32_t cornerRadius = 4) : Instance(position, size), label(position, size, text, textColor), backgroundColor(backgroundColor), cornerRadius(cornerRadius), lastPressedState(false) {};

    bool isPressed(const Vector2 &touchedAt);
    void draw() override;
};
