#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14
#define BUTTON_PIN 25

const uint8_t LED_PINS[] = {RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN, BLUE_LED_PIN};
const uint8_t LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

int pressCounter = 0;
bool previousButtonState = false;

/****************************************************/
void applyLedPattern(int count)
{
    for (uint8_t i = 0; i < LED_COUNT; ++i)
    {
        bool isOn = i < count;
        digitalWrite(LED_PINS[i], isOn ? HIGH : LOW);
    }
}

/****************************************************/
void setup(void)
{
    Serial.begin(115200);

    pinMode(BUTTON_PIN, INPUT);

    for (uint8_t i = 0; i < LED_COUNT; ++i)
    {
        pinMode(LED_PINS[i], OUTPUT);
        digitalWrite(LED_PINS[i], LOW);
    }

    applyLedPattern(pressCounter);
}

/****************************************************/
void loop(void)
{
    bool currentButtonState = (digitalRead(BUTTON_PIN) == HIGH);

    if (currentButtonState && !previousButtonState)
    {
        pressCounter = (pressCounter + 1) % 5;
        applyLedPattern(pressCounter);
        Serial.print("count=");
        Serial.println(pressCounter);
    }

    previousButtonState = currentButtonState;
}
