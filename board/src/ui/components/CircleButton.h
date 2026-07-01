#pragma once

#include "ui/components/Instance.h"
#include <cstdint>
#include "classes/Signal.h"

class CircleButton : public Instance
{
private:
    float lastRadius;
    bool lastPressedState;

public:
    float radius;
    uint16_t color;
    Signal<> onPress;

    CircleButton(const Vector2 &position, int zIndex, float radius, uint16_t color) : Instance(position, Vector2(radius * 2, radius * 2), zIndex), radius(radius), color(color) {}

    bool isPressed();
    void draw() override;
};
