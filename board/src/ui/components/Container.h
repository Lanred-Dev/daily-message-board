#pragma once

#include "ui/components/Instance.h"
#include <cstdint>
#include "core/Display.h"

class Container : public Instance
{
    public:
    uint16_t color;
    int32_t cornerRadius = 0;

    Container(const Vector2 &position, const Vector2 &size, uint16_t color = Display::Color::BLACK, int32_t cornerRadius = 0) : Instance(position, size), color(color), cornerRadius(cornerRadius) {}

    void draw() override;
};