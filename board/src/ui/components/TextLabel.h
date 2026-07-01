#pragma once

#include "ui/components/Instance.h"
#include "core/Display.h"
#include <string>
#include "Color.h"

class TextLabel : public Instance
{
public:
    std::string text;
    uint16_t color;
    float textSize;

    TextLabel(const Vector2 &position, const Vector2 &size, int zIndex,
              const std::string &label, uint16_t color = Color::TEXT_MAIN, float textSize = 1) : Instance(position, size, zIndex), text(label), color(color), textSize(textSize) {}

    void draw() override;
};
