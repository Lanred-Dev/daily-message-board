#include "Container.h"

void Container::draw()
{
    Display::canvas.fillRoundRect(position.x, position.y, size.x, size.y, cornerRadius, color);
}