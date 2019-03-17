
#include "../arduino/hardware/arduino/cores/arduino/WString.h"
#include "../arduino/hardware/arduino/cores/arduino/Arduino.h"

#include "../arduino/libraries/LiquidCrystal/LiquidCrystal.h"

#include "../PinLayout/PinLayout.h"

#include "LCD.h"

// The body of the LCD library

LCD::LCD() : lcd(lcdReset, lcdEnable, lcdDataLine4, lcdDataLine5, lcdDataLine6, lcdDataLine7)
{
  PinLayout pinLayout;
  pinLayout.setup();
  
  
  this->lcd.begin(20, 4);
  
  this->currentOption = 1;
}

void LCD::printWelcomeScreen() {
  
// Print the first screen of the DDED to welcome the user.

  this->lcd.clear();
  this->lcd.setCursor(0, 0);
  this->lcd.print("Welcome to DDED");
  this->lcd.setCursor(0, 2);
  this->lcd.print("   use Bluetooth");
  this->lcd.setCursor(0, 3);
  this->lcd.print("   use Buttons");
  
}

void LCD::printBluetoothScreen() {
  

// Print a screen telling the user that the DDED is in bluetooth mode.

  this->lcd.clear();
  this->lcd.setCursor(0, 1);
  this->lcd.print("   BLUETOOTH MODE   ");
  this->lcd.setCursor(0, 2);
  this->lcd.print("    **********     ");
  
}

void LCD::printHomeScreen() {

// Print the Home screen
  
  this->lcd.clear();
  this->lcd.setCursor(0, 0);
  this->lcd.print("Welcome to DDED!");
  this->lcd.setCursor(0, 1);
  this->lcd.print("   Custom");
  this->lcd.setCursor(0, 2);
  this->lcd.print("   Recipie");
  this->lcd.setCursor(0, 3);
  this->lcd.print("   Game");
 
  this->updateSelectionToOption(1);
  
}

void LCD::printCustomScreen(int amountOfA) {

// Print the custom screen
  
  this->lcd.clear();
  
  for (int i=0; i<amountOfA; i++) {
    this->lcd.setCursor(i, 1);
    this->lcd.print("-");
  }
  
  this->lcd.setCursor(0, 2);
  this->lcd.print(amountOfA);
  
}

void LCD::printRecipieScreen() {

}

void LCD::printGameScreen() {

// Print Game Screen
  
  this->lcd.clear();
  this->lcd.setCursor(0, 1);
  this->lcd.print(" Welcome to Plinko ");
  this->lcd.setCursor(0, 2);
  this->lcd.print("   Please Insert Coin   ");
  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void LCD::moveSelection(String direction) {

  if (direction == "Down") {
    if (this->currentOption == 3) {
      this->currentOption = 1;
    } else {
      this->currentOption++;
    }
  } else if (direction == "Up") {
    if (this->currentOption == 1) {
      this->currentOption = 3;
    } else {
      this->currentOption--;
    }
  }

  this->updateSelectionToOption(this->currentOption);

}


void LCD::updateSelectionToOption(int currentOption) {
  
  this->lcd.setCursor(0, 1);
  this->lcd.print(" ");
  this->lcd.setCursor(0, 2);
  this->lcd.print(" ");
  this->lcd.setCursor(0, 3);
  this->lcd.print(" ");
  this->lcd.setCursor(0, currentOption);
  this->lcd.print(">");

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LCD::printGameOutcomeScreen(int result) {
  
  switch(result) {
    case 1:  printGameOutcomeWin(100, 0); //  A = 100 and B = 0
        break;
    case 2:  printGameOutcomeWin(25, 75); //  A = 25 and B = 75
        break;
    case 3:  printGameOutcomeLose();      //  A = 0 and B = 0
        break;
    case 4:  printGameOutcomeWin(75, 25); //  A = 50 and B = 50
        break;
    case 5:  printGameOutcomeLose();      //  A = 0 and B = 0
        break;
    case 6:  printGameOutcomeWin(75, 25); //  A = 75 and B = 25
        break;
    case 7:  printGameOutcomeWin(0, 100); //  A = 0 and B = 100
        break;
  }
  
}


void LCD::printGameOutcomeWin( int A, int B) {
  
// Print the win game screen with the correct amount for drink A and drink B
    
//     char Achar = (char)A;
//     char Astring[12];
//     Astring[0] = Achar;
//     Astring[4, 12] = " part A"; // Fix this
    
    char Bchar = (char)B;
    
  this->lcd.clear();
  this->lcd.setCursor(2, 0);
  this->lcd.print("Game Result");
  this->lcd.setCursor(4, 1);
  this->lcd.print("You Win");
  this->lcd.setCursor(3, 2);
  this->lcd.print(" part A");// need to add variable A
  this->lcd.setCursor(3, 3);
  this->lcd.print(" part B");// need to add variable B
  
}

void LCD::printGameOutcomeLose() {
  
//  Print the lose screen
  
  this->lcd.clear();
  this->lcd.setCursor(7, 1);
  this->lcd.print("You Lose!");
  this->lcd.setCursor(7, 2);
  this->lcd.print("Try Again!");
}
