
#include "../PinLayout/PinLayout.h"
#include "../LiquidCrystal/LiquidCrystal.h"
#include "LCD.h"

// The body of the LCD library

LCD::LCD()
{
  PinLayout pinLayout;
  pinLayout.setup();
  
  this->lcd = LiquidCrystal(lcdReset, lcdEnable, lcdDataLine4, lcdDataLine4, lcdDataLine4, lcdDataLine4);
  lcd.begin(20, 4);
  
  currentOption = 1;
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
  lcd.print(amountOfA);
  
}

void LCD::printRecipieScreen() {

}

void LCD::printGameScreen() {

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
    
    int test = A;
    
    char testC = test.toChar();
    
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
