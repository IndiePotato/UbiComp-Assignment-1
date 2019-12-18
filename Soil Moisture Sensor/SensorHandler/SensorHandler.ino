/*
Author: Oliver Nock, s4910334
Level 6 Ubiquitous Computing Assignment - Soil Moisture Feedback System

Setup:
  * LCD RS Pin to RedBear D12
  * LCD RW Pin to Redbear GND
  * LCD EN Pin to RedBear D13
  * LCD DB4 Pin to ReadBear D0
  * LCD DB5 Pin to RedBear D1
  * LCD DB6 Pin to RedBear D2
  * LCD DB7 Pin to RedBear D3
*/

#include <LiquidCrystal.h>
#include "DisplayHandler.h"
#include "LedHandler.h"

#if defined(ARDUINO)
SYSTEM_MODE(MANUAL);
#endif

const int moisturePin = A7;
const int thresholdPin = A0;
const int ledPin = D7;

unsigned int moistureValue = 0;
unsigned int thresholdValue = 0;
const float total = 4096.0;
float difference;

void setup() {}

void loop() {
  // Read Moisture and Threshold Value
  moistureValue = analogRead(moisturePin); // Get Moisture Value
  thresholdValue = analogRead(thresholdPin); // Get Threshold Value

  // Calculate Moisture and Threshold Percentages
  float moisturePercentage = moistureValue / total * 100.0; // Get Moisture Percentage
  float thresholdPercentage = thresholdValue / total * 100.0; // Get Threshold Value

  // Display Output
  DisplayHandler screen(thresholdPercentage, moisturePercentage);
  screen.displayOutput();

  // Calculate Difference
  difference = moisturePercentage - thresholdPercentage;

  // Set RGB LED Appropriate Colour
  LedHandler led;
  led.updateLed(difference);
  
  delay(1000); // Delay 1 second. Too fast feedback is nonsensical to a user.
}
