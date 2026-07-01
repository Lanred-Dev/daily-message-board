#include "Message.h"
#include "ui/components/TextLabel.h"
#include "systems/Message.h"
#include "config.h"
#include "Color.h"

void MessagePage::setup()
{
    TextLabel *messageLabel = new TextLabel(Vector2(10, 10), Vector2(DISPLAY_WIDTH - 20, DISPLAY_HEIGHT - 20), 1, std::get<0>(MessageSystem::getCurrentMessage()), Color::TEXT_MAIN, 1.2f);
    addInstance(messageLabel);
}