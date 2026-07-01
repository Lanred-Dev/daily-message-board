#pragma once

#include "ui/components/Instance.h"
#include <cstdint>
#include "core/Display.h"
#include "Color.h"

class Container : public Instance
{
    public:
    uint16_t color;
    int32_t cornerRadius = 0;

    Container(const Vector2 &position, const Vector2 &size, int zIndex, uint16_t color = Color::CONTAINER_BACKGROUND, int32_t cornerRadius = 0) : Instance(position, size, zIndex), color(color), cornerRadius(cornerRadius) {}

    void draw() override;
};