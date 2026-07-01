#include "Navbar.h"
#include "ui/components/Container.h"
#include "ui/components/CircleButton.h"
#include "ui/components/TextLabel.h"
#include "systems/UI.h"
#include "config.h"
#include "Color.h"

const int NAVBAR_HEIGHT = 30;
const int NAVBAR_WIDTH = DISPLAY_WIDTH / 2;
const Vector2 NAVBAR_POSITION(DISPLAY_WIDTH / 2 - NAVBAR_WIDTH / 2, DISPLAY_HEIGHT - NAVBAR_HEIGHT - 10);

void Navbar::setup()
{
    const int buttonRadius = 15;
    const int buttonDiameter = buttonRadius * 2;
    const int buttonSpacing = 6;
    const int totalButtons = 3;

    const int totalRowWidth = (totalButtons * buttonDiameter) + ((totalButtons - 1) * buttonSpacing);
    const int startX = NAVBAR_POSITION.x + (NAVBAR_WIDTH / 2) - (totalRowWidth / 2) + buttonRadius;
    const int centerY = NAVBAR_POSITION.y + (NAVBAR_HEIGHT / 2);

    CircleButton *messagePageButton = new CircleButton(Vector2(startX, centerY), buttonRadius, 10, Color::LIGHT_BUTTON);
    messagePageButton->onPress.connect([]() { UI::setCurrentPage(0); });
    UI::addInstance(messagePageButton);

    CircleButton *imagePageButton = new CircleButton(Vector2(startX + buttonDiameter + buttonSpacing, centerY), buttonRadius, 10, Color::LIGHT_BUTTON);
    imagePageButton->onPress.connect([]() { UI::setCurrentPage(1); });
    UI::addInstance(imagePageButton);

    CircleButton *calendarPageButton = new CircleButton(Vector2(startX + 2 * (buttonDiameter + buttonSpacing), centerY), buttonRadius, 10, Color::LIGHT_BUTTON);
    calendarPageButton->onPress.connect([]() { UI::setCurrentPage(2); });
    UI::addInstance(calendarPageButton);
}