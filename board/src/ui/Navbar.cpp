#include "Navbar.h"
#include "ui/components/Container.h"
#include "ui/components/Button.h"
#include "ui/components/TextLabel.h"
#include "systems/UI.h"
#include "config.h"

const int NAVBAR_HEIGHT = 40;
const int NAVBAR_WIDTH = DISPLAY_WIDTH / 2;

void Navbar::setup()
{
    Container *background = new Container(Vector2(DISPLAY_WIDTH / 2 - NAVBAR_WIDTH / 2, 10), Vector2(NAVBAR_WIDTH, NAVBAR_HEIGHT), Display::Color::CONTAINER_BACKGROUND, 8);
    UI::addInstance(background);
}