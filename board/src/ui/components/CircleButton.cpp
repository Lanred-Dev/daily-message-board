#include "CircleButton.h"
#include "core/Display.h"

void CircleButton::draw()
{
    if (radius != lastRadius)
    {
        size.x = radius * 2;
        size.y = radius * 2;
        lastRadius = radius;
    }

    Display::canvas.fillCircle(position.x, position.y, radius, color);

    if (Display::isTouched)
    {
        isPressed();
    }
    else
        lastPressedState = false;
}

bool CircleButton::isPressed()
{
    if (Display::touchPosition.x >= position.x && Display::touchPosition.x <= (position.x + size.x) && Display::touchPosition.y >= position.y && Display::touchPosition.y <= (position.y + size.y))
    {
        if (!lastPressedState)
        {
            lastPressedState = true;
            onPress.emit();
        }

        return true;
    }

    lastPressedState = false;
    return false;
}