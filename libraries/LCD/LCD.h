#ifndef LCD_h
#define LCD_h
#include "Arduino.h"
#include "LiquidCrystal.h"

class LCD {
   private:
   
   void updateTwoChoiceSelection();
   void updateThreeChoiceSelection();
   void updatePremixedSelection();
   
   void printGameOutcomeWin(int A, int B);
   void printGameOutcomeLose();
   
   LiquidCrystal lcd;
   int twoChoiceCurrentOption;
   int premixedCurrentOption;
   int threeChoiceCurrentOption;
   int unitsOfA;
   int unitsOfB;
   
  public:
   // needs recipe interface, bluetooth interface etc
   LCD();
   void printWelcomeScreen();
   
   void printDispensing(int a, int b);
   
   void printHomeScreen();
   
   void moveTwoChoiceSelection(char direction);
   int	getTwoChoiceSelection();
   
   void moveThreeChoiceSelection(char direction);
   int getThreeChoiceSelection();
   
   void printDrinkSelectScreen();
   
   void printDrinkPremixedScreen();
   void movePremixedSelection(char direction);
   int getPremixSelection();
   
   void printDrinkCustomScreen();
   void getCustomDrinkParams(int &a, int &b);
   void incrementDrinkCounter(char drink);
   
   void printBluetoothScreen();
   
   void printGameScreen();
   void printGameOutcomeScreen(int result);
   
   void printTimeoutPlaceholder();
   void updateTimeout(int counter);
   void printTimeoutOccurred();
};

#endif
