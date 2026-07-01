#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "Storage.h"
#include "config.h"

BootStatus Storage::setup()
{
    if (!SD.begin(SD_CS, SPI))
        return {"Failed to initialize SD card.", false};

    if (SD.cardType() == CARD_NONE)
        return {"No SD card detected.", false};

    return {"SD card initialized successfully.", true};
}

bool Storage::writeTxt(const char *path, const char *content)
{
    File file = SD.open(path, FILE_WRITE);

    if (!file)
    {
        Serial.print("Failed to open file for writing: ");
        Serial.println(path);
        return false;
    }

    size_t bytesWritten = file.print(content);

    if (bytesWritten == 0)
    {
        Serial.print("Failed to write to file: ");
        Serial.println(path);
        file.close();
        return false;
    }

    Serial.print("Wrote ");
    Serial.print(bytesWritten);
    Serial.print(" bytes to file: ");
    Serial.println(path);
    file.close();
    return true;
}

std::string Storage::readTxt(const char *path)
{
    File file = SD.open(path, FILE_READ);

    if (!file)
    {
        Serial.print("Failed to open file for reading: ");
        Serial.println(path);
        return "";
    }

    std::string content = "";

    while (file.available())
    {
        content += (char)file.read();
    }

    file.close();
    return content;
}