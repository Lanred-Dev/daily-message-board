#include "Message.h"
#include "ui/components/TextLabel.h"
#include "systems/Message.h"
#include "config.h"

void MessagePage::setup()
{
    TextLabel *messageLabel = new TextLabel(Vector2(10, 10), Vector2(DISPLAY_WIDTH - 20, DISPLAY_HEIGHT - 20), std::get<0>(MessageSystem::getCurrentMessage()), Display::Color::WHITE, 1.2f);
    addInstance(messageLabel);
}