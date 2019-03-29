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
   
   void updateHomeSelection();
   void printGameOutcomeWin(int A, int B);
   void printGameOutcomeLose();
   
   LiquidCrystal lcd;
   int homeMenuCurrentOption;
   int drinkMenuCurrentOption;
   
  public:
   // needs recipe interface, bluetooth interface etc
   LCD();
   void printWelcomeScreen();
   void printBluetoothScreen();
   void printHomeScreen();
   void printGameScreen();
   void printGameOutcomeScreen(int result);
   void moveHomeSelection(String direction);
   int	getHomeSelection();
   void printTimeoutPlaceholder();
   void updateTimeout(int counter);
   void printTimeoutOccurred();
};

#endif
