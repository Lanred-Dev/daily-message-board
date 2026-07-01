#pragma once

#include "ui/components/Instance.h"
#include "TextLabel.h"
#include "math/Vector2.h"
#include "core/Display.h"
#include "classes/Signal.h"
#include "Color.h"

class Button : public Instance
{
private:
    bool lastPressedState;

public:
    TextLabel label;
    Signal<> onPress;
    uint16_t backgroundColor;
    int32_t cornerRadius = 4;

    Button(const Vector2 &position, const Vector2 &size, int zIndex,
           const std::string &text,
           uint16_t backgroundColor = Color::PRIMARY_BUTTON, uint16_t textColor = Color::TEXT_MAIN, int32_t cornerRadius = 4) : Instance(position, size, zIndex), label(position, size, zIndex + 1, text, textColor), backgroundColor(backgroundColor), cornerRadius(cornerRadius), lastPressedState(false) {};

    bool isPressed();
    void draw() override;
};
