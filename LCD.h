#ifndef LCD_h
#define LCD_h

#include <string>

#include "pinLayout.h"
#include "LiquidCrystal.h"

#include "LCD.h"

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
    
// The body of the LCD library

LCD::LCD()
{
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // put this into constructor
  lcd.begin(20, 4);
}

void LCD::printWelcomeScreen() {
  
// Print the first screen of the DDED to welcome the user.

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to DDED");
  lcd.setCursor(0, 2);
  lcd.print("   use Bluetooth");
  lcd.setCursor(0, 3);
  lcd.print("   use Buttons");
  
}

void LCD::printBluetoothScreen() {
  

// Print a screen telling the user that the DDED is in bluetooth mode.

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("   BLUETOOTH MODE   ");
  lcd.setCursor(0, 2);
  lcd.print("    **********     ");
  
}

void LCD::printHomeScreen() {

// Print the Home screen
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to DDED!");
  lcd.setCursor(0, 1);
  lcd.print("   Custom");
  lcd.setCursor(0, 2);
  lcd.print("   Recipie");
  lcd.setCursor(0, 3);
  lcd.print("   Game");
 
  lcd.updateSelectionToOption(1);
  
}

void LCD::printCustomScreen(int amountOfA) {

// Print the custom screen
  
  lcd.clear();
  
  for (int i=0; i<amountOfA; i++) {
    lcd.setCursor(i, 1);
    lcd.print("-");
  }
  
  lcd.setCursor(0, 2);
  lcd.print(amountofA);
  
}

void LCD::printRecipieScreen() {

}

void LCD::printGame() {

// Print Game Screen
  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" Welcome to Plinko ");
  lcd.setCursor(0, 2);
  lcd.print("   Please Insert Coin   ");
  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


LCD::moveSelection(String direction) {

  if (direction == "Down") {
    if (currentOption == 3) {
      currentOption == 1;
    } else {
      curretnOption++;
    }
  } else if (direction == "Up") {
    if (currentOption == 1) {
      currentOption == 3;
    } else {
      curretnOption--;
    }
  }

  updateSelectionToOption(currentOption);

}


void LCD::updateSelectionToOption(int currentOption) {
  
  lcd.setCursor(1, 1);
  lcd.print(" ");
  lcd.setCursor(1, 2);
  lcd.print(" ");
  lcd.setCursor(1, 3);
  lcd.print(" ");
  lcd.setCursor(1, currentOption);
  lcd.print("X");

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LCD::printGameOutcomeScreen(int result) {
  
  case(result) {
    1:  printGameOutcomeWin(100, 0); //  A = 100 and B = 0
        break;
    2:  printGameOutcomeWin(25, 75); //  A = 25 and B = 75
        break;
    3:  printGameOutcomeLose();      //  A = 0 and B = 0
        break;
    4:  printGameOutcomeWin(75, 25); //  A = 50 and B = 50
        break;
    5:  printGameOutcomeLose();      //  A = 0 and B = 0
        break;
    6:  printGameOutcomeWin(75, 25); //  A = 75 and B = 25
        break;
    7:  printGameOutcomeWin(0, 100); //  A = 0 and B = 100
        break;
  }
  
}


void LCD::printGameOutcomeWin( int A, int B) {
  
// Print the win game screen with the correct amount for drink A and drink B
  
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Game Result");
  lcd.setCursor(4, 1);
  lcd.print("You Win");
  lcd.setCursor(3, 2);
  lcd.print(A.toChar() + " part A");
  lcd.setCursor(3, 3);
  lcd.print(B.toChar() + " part B");
  
}

void LCD::printGameOutcomeLose() {
  
//  Print the lose screen
  
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("You Lose!");
  lcd.setCursor(7, 2);
  lcd.print("Try Again!");
}

#endif
