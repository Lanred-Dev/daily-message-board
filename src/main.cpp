#include <Arduino.h>
#include <LittleFS.h>
#include "config.h"
#include "classes/BootStatus.h"
#include "components/RTC.h"
#include "components/Buzzer.h"
#include "components/Display.h"
#include "components/MessageChangeButton.h"
#include "components/DisplayViewSwitch.h"
#include "systems/Message.h"
#include "systems/Routine.h"

void attemptModuleSetup(const char *moduleName, BootStatus (*setupFunction)())
{
  BootStatus status = setupFunction();

  if (!status.success)
  {
    Serial.print("Error initializing ");
    Serial.print(moduleName);
    Serial.print(": ");
    Serial.println(status.message);

    Serial.println("Boot failed... halting execution");

    while (true)
      delay(10);
  }

  Serial.print(moduleName);
  Serial.print(": ");
  Serial.println(status.message);
}

void setup()
{
  Serial.begin(BAUD_RATE);

  while (!Serial)
  {
    Serial.println("Waiting for Serial...");
    delay(10);
  }

  if (!LittleFS.begin(true))
  {
    Serial.println("Error initializing LittleFS. Boot failed... halting execution");
    return;
  }

  Serial.println("LittleFS Mounted successfully");

  attemptModuleSetup("RTC", RTC::setup);
  attemptModuleSetup("Buzzer", Buzzer::setup);
  attemptModuleSetup("Display", Display::setup);
  attemptModuleSetup("MessageChangeButton", MessageChangeButton::setup);
  attemptModuleSetup("DisplayViewSwitch", DisplayViewSwitch::setup);

  MessageSystem::newMessage();
}

void loop()
{
  if (MessageChangeButton::isPressed())
    MessageSystem::requestNewMessage();

  MessageSystem::setImageViewActive(DisplayViewSwitch::isOpen());
  Routine::loop();
  MessageSystem::loop();
}