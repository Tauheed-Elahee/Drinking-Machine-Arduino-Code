#ifndef LCD_h
#define LCD_h
#include "Arduino.h"
#include "LiquidCrystal.h"

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
   void printHomeScreen();
   void moveHomeSelection(char direction);
   int	getHomeSelection();
   void printDrinkSelectScreen();
   void moveDrinkSelection(char direction);
   int getDrinkSelection();
   void printBluetoothScreen();
   void printGameScreen();
   void printGameOutcomeScreen(int result);
   void printTimeoutPlaceholder();
   void updateTimeout(int counter);
   void printTimeoutOccurred();
};

#endif
