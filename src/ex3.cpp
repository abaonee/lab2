#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

const unsigned long ALERT_INTERVAL_MS = 300;
bool alertActive = false;
unsigned long lastSampleTime = 0;

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
}

/****************************************************/
void loop(void)
{
    unsigned long now = millis();

    if (now - lastSampleTime >= ALERT_INTERVAL_MS)
    {
        lastSampleTime = now;

        int lightValue = analogRead(LIGHT_SENSOR_PIN);

        if (lightValue > 3000 && !alertActive)
        {
            alertActive = true;
            Serial.println("ALERT=1");
        }
        else if (lightValue < 2500 && alertActive)
        {
            alertActive = false;
            Serial.println("ALERT=0");
        }
    }
}
