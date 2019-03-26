#include "WString.h"
#include "Arduino.h"

#include "PinLayout.h"

#include "Buttons.h"

// The body of the Buttons library

Buttons::Buttons()
{
  PinLayout pinLayout;
  pinLayout.setup();
}

String Buttons::getPressed() {
  
// Returns a string indicating the button pressed.

  if (digitalRead(buttonBack) return "Back";
  if (digitalRead(buttonSelect) return "Select";
  if (digitalRead(buttonUp) return "Up";
  if (digitalRead(buttonDown) return "Down";
  
}

void Buttons::debounce() {
  

// Delay reaing of next input to avoid debounce.

  delay(100);
  
}
