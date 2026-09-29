#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

const uint8_t SAMPLE_COUNT = 10;
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

    if (now - lastSampleTime >= 1000)
    {
        lastSampleTime = now;

        int minValue = 4095;
        int maxValue = 0;
        long sum = 0;

        for (uint8_t i = 0; i < SAMPLE_COUNT; ++i)
        {
            int reading = analogRead(LIGHT_SENSOR_PIN);
            if (reading < minValue)
            {
                minValue = reading;
            }
            if (reading > maxValue)
            {
                maxValue = reading;
            }
            sum += reading;
        }

        int avgValue = (int)(sum / SAMPLE_COUNT);

        Serial.print("min=");
        Serial.print(minValue);
        Serial.print(" max=");
        Serial.print(maxValue);
        Serial.print(" avg=");
        Serial.println(avgValue);
    }
}
