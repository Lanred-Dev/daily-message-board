# Board

This is the code for the board. It handles displaying messages, images, events and fetching data from the backend.

### Requirements

- ESP32
- Display
- MicroSD Card (and reader)

* Note: For this project I used a 2.8" Cheap Yellow Display

### Configuration

A config.h file should be preset inside the include directory. This file should contain the following:

```c
#pragma once

#define BAUD_RATE 115200

#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 240

#define WIFI_AP_NAME "Message Board Config"

#define NTP_SERVER "pool.ntp.org"
#define TIMEZONE_OFFSET -21600       // CST
#define DAYLIGHT_SAVINGS_OFFSET 3600 // 1 hour

#define SD_SCLK 18
#define SD_MISO 19
#define SD_MOSI 23
#define SD_CS 5

#define UPDATE_CHECK_INTERVAL 300000 // 5 minutes

#define IMAGE_UPDATE_URL "url.to.backend/image"
#define MESSAGE_UPDATE_URL "url.to.backend/message"
#define CALENDAR_UPDATE_URL "url.to.backend/calendar"
#define TIME_UPDATE_URL "url.to.backend/last-update-time"
```