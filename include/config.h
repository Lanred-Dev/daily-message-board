#pragma once

#define BAUD_RATE 115200

#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 240

#define WIFI_AP_NAME "Message Board Config"

#define NTP_SERVER "pool.ntp.org"
#define TIMEZONE_OFFSET -21600       // CST
#define DAYLIGHT_SAVINGS_OFFSET 3600 // 1 hour

#define SD_CS_PIN 5
#define SD_MOSI 23
#define SD_MISO 19
#define SD_SCLK 18

#define UPDATE_CHECK_INTERVAL 300000 // 5 minutes
#define IMAGE_UPDATE_URL "https://pearl.landonr.me/mb/updates/image"
#define MESSAGE_UPDATE_URL "https://pearl.landonr.me/mb/updates/message"
#define CALENDAR_UPDATE_URL "https://pearl.landonr.me/mb/updates/calendar"
#define TIME_UPDATE_URL "https://pearl.landonr.me/mb/updates/time"