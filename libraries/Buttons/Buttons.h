#ifndef Buttons_h
#define Buttons_h

#include "WString.h"
#include "Arduino.h"

#include "PinLayout.h"


// Define the LCD class

// Add a function that returns the selected option back to the main arduino file

class Buttons {
  public:
   Buttons();
  
   String getPressed();
   void debounce();
  
  private:
};

#endif
