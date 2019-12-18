#include <LiquidCrystal.h>
#include <Arduino.h>

class LedHandler {
  
  public:
    LedHandler() {
      RGB.control(true);
    }

    void updateLed(float difference) {
      if (difference > 0.0 and difference <=5.0) {
        // Set RGB to Blue
        RGB.color(0, 255, 0);
      }
      else if (difference > 5.0) {
        // Set RGB to Blue
        RGB.color(0, 0, 255);
      }
      else if (difference <= 0.0 and difference >= -4.0) {
        // Set RGB to Yellow
        RGB.color(255, 255, 0);
      }
      else if (difference < -4.0 and difference > -10.0) {
        // Set RGB to Orange
        RGB.color(255, 69, 0);
      }
      else if (difference <= 10.0) {
        // Set RGB to Red
        RGB.color(25, 0, 0);
      }
    }
};
