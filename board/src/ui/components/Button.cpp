#include "Button.h"

void Button::draw()
{
    Display::canvas.fillRoundRect(position.x, position.y, size.x, size.y, cornerRadius, backgroundColor);
    label.draw();

    if (Display::isTouched)
    {
        isPressed();
    }
    else
        lastPressedState = false;
}

bool Button::isPressed()
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