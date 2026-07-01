#pragma once

#include <cstdint>

struct Vector2
{
    int32_t x;
    int32_t y;

    Vector2(int32_t x = 0, int32_t y = 0) : x(x), y(y) {}
};