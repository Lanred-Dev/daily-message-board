#include "Circle.h"
#include "core/Display.h"

void Circle::draw()
{
    if (radius != lastRadius)
    {
        size.x = radius * 2;
        size.y = radius * 2;
        lastRadius = radius;
    }

    Display::canvas.fillCircle(position.x + radius, position.y + radius, radius, color);
}