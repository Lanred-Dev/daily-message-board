#include "core/Internet.h"
#include "config.h"
#include <HTTPClient.h>

BootStatus Internet::setup()
{
    bool success = manager.autoConnect(WIFI_AP_NAME);

    if (!success)
        return {"Failed to connect to the internet.", success};

    return {"Connected to the internet...", success};
}

std::string Internet::fetch(const char *url)
{
    HTTPClient http;
    http.begin(url);

    if (http.GET() > 0)
    {
        Serial.print("Fetched data from URL: ");
        Serial.println(url);
        
        std::string payload = http.getString().c_str();
        http.end();
        return payload;
    }

    Serial.print("Failed to fetch data from URL: ");
    Serial.println(url);
    http.end();
    return "";
}