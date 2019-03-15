
#ifndef LCD_h
#define LCD_h

#include <string>

#include "PinLayout.h"
#include "LiquidCrystal.h"

// Define the LCD class

// Add a function that returns the selected option back to the main arduino file

class LCD {
  public:
   LCD();
  
   void printWelcomeScreen();
   void printBluetoothScreen();
   void printHomeScreen();
   void printCustomScreen();
   void printRecipieScreen(int amountOfA);
   void printGameScreen();
   void printGameOutcomeScreen(int result);
   void moveSelection(string direction);
  
  private:
   void updateSelectionToOption(int currentOption);
   void printGameOutcomeWin(int A, int B);
   void printGameOutcomeLose();

   LiquidCrystal lcd(int rs, int en, int d4, int d5, int d6, int d7);
   int currentOption;
};

#endif
