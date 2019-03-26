#ifndef LCD_h
#define LCD_h

#include "WString.h"
#include "Arduino.h"

#include "LiquidCrystal.h"

#include "PinLayout.h"

// Define the LCD class

// Add a function that returns the selected option back to the main arduino file

class LCD {
   private:
   
   void updateSelectionToOption(int currentOption);
   void printGameOutcomeWin(int A, int B);
   void printGameOutcomeLose();
   
   LiquidCrystal lcd;
   int currentOption;
   
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
   int	getSelection();
  
  private:
   void updateSelectionToOption(int currentOption);
   void printGameOutcomeWin(int A, int B);
   void printGameOutcomeLose();

   LiquidCrystal lcd;
   int currentOption;
};

#endif
