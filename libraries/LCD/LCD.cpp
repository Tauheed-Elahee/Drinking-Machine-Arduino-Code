#include "Arduino.h"
#include "LiquidCrystal.h"
#include "PinLayout.h"
#include "LCD.h"

// The body of the LCD library

LCD::LCD() : lcd(lcdReset, lcdEnable, lcdDataLine4, lcdDataLine5, lcdDataLine6, lcdDataLine7)
{
  PinLayout pinLayout;
  pinLayout.setup();
  lcd.begin(20, 4);
  twoChoiceCurrentOption = 1;
}

void LCD::printWelcomeScreen() {
  lcd.clear();
  lcd.setCursor(4, 0);
  // TBD every loop put in another line
  lcd.print("Drink anyone?");
  lcd.setCursor(5, 1);
  lcd.print("<< START >>");
  lcd.setCursor(0, 3);
  lcd.print("Hit Select / Use App");
}

void LCD::printDispensing(int a, int b) {
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("DISPENSING DRINK");
  lcd.setCursor(3,1);
  lcd.print(a);
  lcd.print(" Part(s) A");
  lcd.setCursor(3,2);
  lcd.print(b);
  lcd.print(" Part(s) B");
}

void LCD::printHomeScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Welcome Patron");
  lcd.setCursor(0, 1);
  lcd.print("  Get a drink");
  lcd.setCursor(0, 2);
  lcd.print("  Play Plinko!");
  twoChoiceCurrentOption = 1;
  updateTwoChoiceSelection();
}

void LCD::moveTwoChoiceSelection(char direction) {
  if (direction == 'd') {
    if (twoChoiceCurrentOption == 2) {
      twoChoiceCurrentOption = 1;
    } else {
      twoChoiceCurrentOption++;
    }
  } else if (direction == 'u') {
    if (twoChoiceCurrentOption == 1) {
      twoChoiceCurrentOption = 2;
    } else {
      twoChoiceCurrentOption--;
    }
  }
  updateTwoChoiceSelection();
}

void LCD::moveThreeChoiceSelection(char direction) {
  if (direction == 'd') {
    if (threeChoiceCurrentOption == 3) {
      threeChoiceCurrentOption = 1;
    } else {
      threeChoiceCurrentOption++;
    }
  } else if (direction == 'u') {
    if (threeChoiceCurrentOption == 1) {
      threeChoiceCurrentOption = 3;
    } else {
      threeChoiceCurrentOption--;
    }
  }
  updateThreeChoiceSelection();
}

void LCD::updateTwoChoiceSelection() {
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, twoChoiceCurrentOption);
  lcd.print(">");
}

void LCD::updateThreeChoiceSelection() {
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  lcd.setCursor(0, threeChoiceCurrentOption);
  lcd.print(">");
}

int LCD::getTwoChoiceSelection() {
  return twoChoiceCurrentOption;
}

int LCD::getThreeChoiceSelection() {
  return threeChoiceCurrentOption;
}

void LCD::printDrinkSelectScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  On Tap");
  lcd.setCursor(0, 1);
  lcd.print("  Standard mix");
  lcd.setCursor(0, 2);
  lcd.print("  Go custom");
  twoChoiceCurrentOption = 1;
  updateTwoChoiceSelection();
}

void LCD::printDrinkPremixedScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Drink Ratio");
  lcd.setCursor(0, 1);
  lcd.print("A  4 0 2 3 1");
  lcd.setCursor(0, 2);
  lcd.print("B  0 4 2 1 3");
  premixedCurrentOption = 1;
  updatePremixedSelection();
}

void LCD::movePremixedSelection(char direction) {
  if (direction == 'd') {
    if (premixedCurrentOption == 5) {
      premixedCurrentOption = 1;
    } else {
      premixedCurrentOption++;
    }
  } else if (direction == 'u') {
    if (premixedCurrentOption == 1) {
      premixedCurrentOption = 5;
    } else {
      premixedCurrentOption--;
    }
  }
  updatePremixedSelection();
}

void LCD::updatePremixedSelection() {
  lcd.setCursor(0, 3);
  lcd.print("            ");
  lcd.setCursor(3+2*(premixedCurrentOption-1), 3);
  lcd.print("X");
}

int LCD::getPremixSelection() {
  return premixedCurrentOption;
}

void LCD::printDrinkCustomScreen() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Custom Creator");
  lcd.setCursor(2,1);
  lcd.print("  Units of A: 0");
  lcd.setCursor(2,2);
  lcd.print("  Units of B: 0");
  lcd.setCursor(2,3);
  lcd.print("  Enter Order");
  
  threeChoiceCurrentOption = 1;
  updateThreeChoiceSelection();
  
  unitsOfA = 0;
  unitsOfB = 0;
}
void LCD::getCustomDrinkParams(int &a, int &b){
  a = unitsOfA;
  b = unitsOfB;
}
void LCD::incrementDrinkCounter(char drink){
  if (drink == 'a') {
    unitsOfA++;
    if (unitsOfA > 4) {
      unitsOfA = 0;
    }
    lcd.setCursor(16,1);
    lcd.print(unitsOfA);
  }
  else if (drink == 'b') {
    unitsOfB++;
    if (unitsOfB > 4) {
      unitsOfB = 0;
    }
    lcd.setCursor(16,2);
    lcd.print(unitsOfB);
  }
}

void LCD::printBluetoothScreen() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Hijacked by Androids");
  lcd.setCursor(2, 2);
  lcd.print("<< USING APP >>");
}

void LCD::printGameScreen() {  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" Welcome to Plinko ");
  lcd.setCursor(0, 2);
  lcd.print(" Please Insert Coin"); 
}

void LCD::printGameOutcomeScreen(int result) {
  switch(result) {
    case 0:  printGameOutcomeWin(100, 0); //  A = 100 and B = 0
        break;
    case 1:  printGameOutcomeWin(75, 25); //  A = 25 and B = 75
        break;
    case 2:  printGameOutcomeLose();      //  A = 0 and B = 0
        break;
    case 3:  printGameOutcomeWin(50, 50); //  A = 50 and B = 50
        break;
    case 4:  printGameOutcomeLose();      //  A = 0 and B = 0
        break;
    case 5:  printGameOutcomeWin(25, 75); //  A = 75 and B = 25
        break;
    case 6:  printGameOutcomeWin(0, 100); //  A = 0 and B = 100
        break;
  }
}

void LCD::printGameOutcomeWin( int A, int B) {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("WINNER/GAGNANT");
  lcd.setCursor(4, 1);
  lcd.print("%");
  lcd.print(A);
  lcd.setCursor(8, 1);
  lcd.print(" of A");
  lcd.setCursor(4, 2);
  lcd.print("%");
  lcd.print(B);
  lcd.setCursor(8, 2);
  lcd.print(" of B");
}

void LCD::printGameOutcomeLose() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("You Get Nothing");
  lcd.setCursor(6, 1);
  lcd.print("You Lose");
  lcd.setCursor(4, 2);
  lcd.print("Good Day Sir!");
}

void LCD::printTimeoutPlaceholder () {
  lcd.setCursor(9,3);
  lcd.print("      T= 60");
}

void LCD::updateTimeout(int counter) {
  lcd.setCursor(18,3);
  if (counter > 9) {
    lcd.print(counter);
  }
  else {
    lcd.print(" ");
    lcd.print(counter);
  }
}

void LCD::printTimeoutOccurred() {
  lcd.clear();
  lcd.setCursor(7,1);
  lcd.print("TIMEOUT");
}