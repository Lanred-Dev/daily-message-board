#include "config.h"
#include <Arduino.h>
#include "core/Internet.h"
#include "core/NTP.h"
#include "core/Storage.h"
#include "systems/Updater.h"
#include "core/Display.h"

void attemptSetup(const char *moduleName, BootStatus (*setupFunction)())
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

  attemptSetup("Storage", Storage::setup);
  attemptSetup("Display", Display::setup);
  attemptSetup("Internet", Internet::setup);
  attemptSetup("NTP", NTP::setup);
}

void loop()
{
  Updater::loop();
}