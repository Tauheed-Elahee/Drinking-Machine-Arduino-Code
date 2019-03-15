
#ifndef LCD_h
#define LCD_h

#include <string>

#include "../PinLayout/PinLayout.h"
#include "../LiquidCrystal/LiquidCrystal.h"
#include <string>

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
   void moveSelection(string direction);
  
  private:
   void updateSelectionToOption(int currentOption);
   void printGameOutcomeWin(int A, int B);
   void printGameOutcomeLose();

   LiquidCrystal lcd;
   int currentOption;
};

#endif
