#pragma once

#include "math/Vector2.h"

class Instance
{
public:
    Vector2 position;
    Vector2 size;
    bool isVisible;
    int zIndex;

    Instance(const Vector2 &position, const Vector2 &size, int zIndex) : position(position), size(size), isVisible(true), zIndex(zIndex) {}

    virtual ~Instance() = default;

    virtual void draw() = 0;
};