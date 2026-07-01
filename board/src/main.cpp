#include "config.h"
#include <Arduino.h>
#include "core/Internet.h"
#include "core/NTP.h"
#include "core/Storage.h"
#include "systems/Updater.h"
#include "systems/Message.h"
#include "systems/UI.h"
#include "core/Display.h"
#include "config.h"

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

void initSharedHardware()
{
    pinMode(TFT_CS, OUTPUT);
    pinMode(TOUCH_CS, OUTPUT);
    pinMode(SD_CS, OUTPUT);
    
    digitalWrite(TFT_CS, HIGH);   
    digitalWrite(TOUCH_CS, HIGH); 
    digitalWrite(SD_CS, HIGH); 

    delay(50);

    SPI.begin(BUS_SCK, BUS_MISO, BUS_MOSI);
}

void setup()
{
  Serial.begin(BAUD_RATE);

  initSharedHardware();

  attemptSetup("Storage", Storage::setup);
  attemptSetup("Display", Display::setup);
  attemptSetup("Internet", Internet::setup);
  attemptSetup("NTP", NTP::setup);
  attemptSetup("Updater", Updater::setup);
  attemptSetup("Message", MessageSystem::setup);
  attemptSetup("UI", UI::setup);
}

void loop()
{
  Updater::loop();
  Display::loop();
}