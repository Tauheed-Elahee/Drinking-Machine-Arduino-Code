#ifndef LCD_h
#define LCD_h

#include "../arduino/hardware/arduino/cores/arduino/WString.h"
#include "../arduino/hardware/arduino/cores/arduino/Arduino.h"

#include "../arduino/libraries/LiquidCrystal/LiquidCrystal.h"

#include "../PinLayout/PinLayout.h"


// Define the LCD class

// Add a function that returns the selected option back to the main arduino file

class LCD {
  public:
   LCD();
  
   void printWelcomeScreen();
   void printBluetoothScreen();
   void printHomeScreen();
   void printCustomScreen(int amountOfA);
   void printRecipieScreen();
   void printGameScreen();
   void printGameOutcomeScreen(int result);
   void moveSelection(String direction);
  
  private:
   void updateSelectionToOption(int currentOption);
   void printGameOutcomeWin(int A, int B);
   void printGameOutcomeLose();

   LiquidCrystal lcd;
   int currentOption;
};

#endif
