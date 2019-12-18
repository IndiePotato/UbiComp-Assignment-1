#include <LiquidCrystal.h>
#include <Arduino.h>

LiquidCrystal lcdScreen(D12, D13, D0, D1, D2, D3);

class DisplayHandler {
  private:
    float thresholdPercentage;
    float moisturePercentage;
 
  public:
    DisplayHandler(float threshold, float moisture){
       lcdScreen.begin(16, 2);
       thresholdPercentage = threshold;
       moisturePercentage = moisture;
    }

    void displayOutput() {
      lcdScreen.setCursor(0, 0);
      lcdScreen.print("Moisture ");
      lcdScreen.print(moisturePercentage);
      lcdScreen.print("%");
      lcdScreen.setCursor(0, 1);
      lcdScreen.print("Threshold ");
      lcdScreen.print(thresholdPercentage);
      lcdScreen.print("%");
    }
};
