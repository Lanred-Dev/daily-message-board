#include "TextLabel.h"
#include "core/Display.h"

void TextLabel::draw()
{
    Display::canvas.setTextColor(color);
    Display::canvas.setTextDatum(textdatum_t::middle_center);
    Display::canvas.setTextSize(textSize);

    int16_t centerX = position.x + (size.x / 2);
    int16_t centerY = position.y + (size.y / 2);

    Display::canvas.drawString(text.c_str(), centerX, centerY);
}