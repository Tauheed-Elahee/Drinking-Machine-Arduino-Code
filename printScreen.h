#ifndef LCD_h
#define LCD_h
 
#if ARDUINO >= 100
  #include "Arduino.h"
  #include "LiquidCrystal.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
  #include "LiquidCrystal.h"
#endif

// Define the LCD class

class LCD {
  public:
    LCD();
  
    void printWelcome();
    void printBluetooth();
    void printHome();
    void printCustom();
    void printRecipie(int amountOfA);
    void printGame();
    void changeOption();
    void printGameOutcome(int result);
  
  private:
    const int rs = 12;
    const int en = 11;
    const int d4 = 5;
    const int d5 = 4;
    const int d6 = 3;
    const int d7 = 2;
  
    LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
    void printGameOutcomeWin(int A, int B);
    void printGameOutcomeLose();
};
    
// The body of the LCD library

#include "LCD.h"

LCD::LCD()
{
}

void LCD::printWelcome() {
  
// Print the first screen of the DDED to welcome the user.

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to DDED");
  lcd.setCursor(0, 2);
  lcd.print("   use Bluetooth");
  lcd.setCursor(0, 3);
  lcd.print("   use Buttons");
  
}

void LCD::printBluetooth() {
  

// Print a screen telling the user that the DDED is in bluetooth mode.

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("   BLUETOOTH MODE   ");
  lcd.setCursor(0, 2);
  lcd.print("    **********     ");
  
}

void LCD::printHome() {

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
  
}

void LCD::printCustom(int amountOfA) {

// Print the custom screen
  
  lcd.clear();
  
  for (int i=0; i<amountOfA; i++) {
    lcd.setCursor(i, 1);
    lcd.print("-");
  }
  
  lcd.setCursor(0, 2);
  lcd.print(amountofA);
  
}

void LCD::printRecipie() {

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



void LCD::changeOption(&int currentOption) {
  
  lcd.setCursor(1, 1);
  lcd.print("");
  lcd.setCursor(1, 2);
  lcd.print("");
  lcd.setCursor(1, 3);
  lcd.print("");
  lcd.setCursor(1, currentOption);
  lcd.print("X");

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LCD::printGameOutcome(int result) {
  
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
  lcd.print(A);
  lcd.setCursor(8, 2);
  lcd.print("part A");
  lcd.setCursor(3, 3);
  lcd.print(B);
  lcd.setCursor(8, 3);
  lcd.print("part B");
  
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
