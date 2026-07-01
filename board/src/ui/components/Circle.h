#pragma once

#include "ui/components/Instance.h"
#include <cstdint>

class Circle : public Instance
{
private:
    float lastRadius;

public:
    float radius;
    uint16_t color;

    Circle(const Vector2 &position, float radius, uint16_t color) : Instance(position, Vector2(radius * 2, radius * 2)), radius(radius), color(color) {}

    void draw() override;
};
