#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14

const uint8_t LED_PINS[] = {
    RED_LED_PIN,
    GREEN_LED_PIN,
    YELLOW_LED_PIN,
    BLUE_LED_PIN,
    YELLOW_LED_PIN,
    GREEN_LED_PIN
};

const char* LED_NAMES[] = {
    "RED",
    "GREEN",
    "YELLOW",
    "BLUE",
    "YELLOW",
    "GREEN"
};

const uint8_t LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
uint8_t chaseStep = 0;

/****************************************************/
void setup(void)
{
    Serial.begin(115200);

    for (uint8_t i = 0; i < LED_COUNT; ++i)
    {
        pinMode(LED_PINS[i], OUTPUT);
        digitalWrite(LED_PINS[i], LOW);
    }
}

/****************************************************/
void loop(void)
{
    for (uint8_t i = 0; i < LED_COUNT; ++i)
    {
        digitalWrite(LED_PINS[i], LOW);
    }

    digitalWrite(LED_PINS[chaseStep], HIGH);
    Serial.print("chase=");
    Serial.println(LED_NAMES[chaseStep]);

    delay(150);
    chaseStep = (chaseStep + 1) % LED_COUNT;
}
