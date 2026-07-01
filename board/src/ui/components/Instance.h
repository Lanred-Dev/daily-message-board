#pragma once

#include "math/Vector2.h"

class Instance
{
public:
    Vector2 position;
    Vector2 size;
    bool isVisible = true;
    int zIndex = 0;

    Instance(const Vector2 &newPosition, const Vector2 &newSize) : position(newPosition), size(newSize) {}
    virtual ~Instance() = default;

    virtual void draw() = 0;
};