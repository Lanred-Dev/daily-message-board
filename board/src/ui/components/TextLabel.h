#pragma once

#include "ui/components/Instance.h"
#include "core/Display.h"
#include <string>

class TextLabel : public Instance
{
public:
    std::string text;
    uint16_t color;
    float textSize;

    TextLabel(const Vector2 &position, const Vector2 &size,
              const std::string &label, uint16_t color = Display::Color::WHITE, float textSize = 1) : Instance(position, size), text(label), color(color), textSize(textSize) {}

    void draw() override;
};
