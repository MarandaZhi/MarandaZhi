#include <OneButton.h>
#define BUTTON_PIN 8
OneButton btn = OneButton(
                  BUTTON_PIN,  // Input pin for the button
                  false,       // Button is active high
                  false        // Disable internal pull-up resistor
                );
void setup()
{
  Serial.begin(115200);
  btn.attachClick([]() {
    Serial.print("Click");
  });
}

void loop()
{
  btn.tick();
}
