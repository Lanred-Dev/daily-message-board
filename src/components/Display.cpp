#include "Display.h"
#include <Arduino.h>
#include <sstream>
#include <vector>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <LittleFS.h>

Adafruit_SSD1306 Display::display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &SPI, DISPLAY_DC, DISPLAY_RESET, DISPLAY_CS);

BootStatus Display::setup()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC))
        return {"SSD1306 allocation failed", false};

    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    Display::clear();

    return {"Display initialized successfully", true};
}

void Display::clear()
{
    display.clearDisplay();
    display.display();
}

void Display::drawImage(std::array<uint8_t, IMAGE_SIZE_BYTES> &bitmapBuffer)
{
    display.clearDisplay();

    display.drawBitmap(0, 0, bitmapBuffer.data(), DISPLAY_WIDTH, DISPLAY_HEIGHT, SSD1306_WHITE);
    display.display();

    Serial.println("Display: Displaying new image");
}

void Display::print(const char *message)
{
    display.clearDisplay();

    std::vector<std::string> words;
    std::stringstream stream(message);
    std::string word;

    while (stream >> word)
        words.push_back(word);

    std::vector<std::string> lines;
    std::string currentLine = "";

    const int16_t MAX_WIDTH = DISPLAY_WIDTH - 4;

    for (const auto &word : words)
    {
        std::string testLine = currentLine.empty() ? word : currentLine + " " + word;

        int16_t xB, yB;
        uint16_t textWidth, textHeight;
        display.getTextBounds(testLine.c_str(), 0, 0, &xB, &yB, &textWidth, &textHeight);

        if (textWidth > MAX_WIDTH)
        {
            if (!currentLine.empty())
                lines.push_back(currentLine);

            currentLine = word;
        }
        else
        {
            currentLine = testLine;
        }
    }

    if (!currentLine.empty())
        lines.push_back(currentLine);

    int16_t dummyX, dummyY;
    uint16_t dummyWidth, singleLineHeight;

    display.getTextBounds("A", 0, 0, &dummyX, &dummyY, &dummyWidth, &singleLineHeight);

    int lineSpacing = 3;
    int totalParagraphHeight = (lines.size() * singleLineHeight) + ((lines.size() - 1) * lineSpacing);
    int startY = (DISPLAY_HEIGHT - totalParagraphHeight) / 2;

    for (size_t index = 0; index < lines.size(); index++)
    {
        int16_t xBoundary, yBoundary;
        uint16_t textWidth, textHeight;

        display.getTextBounds(lines[index].c_str(), 0, 0, &xBoundary, &yBoundary, &textWidth, &textHeight);

        int x_pos = ((DISPLAY_WIDTH - textWidth) / 2) - xBoundary;
        int y_pos = startY + (index * (singleLineHeight + lineSpacing)) - yBoundary;

        display.setCursor(x_pos, y_pos);
        display.print(lines[index].c_str());
    }

    display.display();

    Serial.print("Display: Displaying message: ");
    Serial.println(message);
}