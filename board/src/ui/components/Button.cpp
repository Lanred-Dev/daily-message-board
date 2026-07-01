#include "Button.h"

void Button::draw()
{
    Display::canvas.fillRoundRect(position.x, position.y, size.x, size.y, cornerRadius, backgroundColor);
    label.draw();

    if (Display::isTouched)
    {
        isPressed(Display::touchPosition);
    }
    else
        lastPressedState = false;
}

bool Button::isPressed(const Vector2 &touchedAt)
{
    if (touchedAt.x >= position.x && touchedAt.x <= (position.x + size.x) && touchedAt.y >= position.y && touchedAt.y <= (position.y + size.y))
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