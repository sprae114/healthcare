#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OledDisplayDriver {
  Adafruit_SSD1306 display;
public:
  OledDisplayDriver() : display(128, 64, &Wire, -1) {}

  void begin() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
      while (true);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
  }

  void displayText(const String& text) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(text);
    display.display();
  }
};
