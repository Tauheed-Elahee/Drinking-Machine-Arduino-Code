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
  homeMenuCurrentOption = 1;
}

void LCD::printWelcomeScreen() {
  
// Print the first screen of the DDED to welcome the user.

  lcd.clear();
  lcd.setCursor(0, 0);
  // TBD every loop put in another line
  lcd.print("Drink anyone?");
  lcd.setCursor(2, 1);
  lcd.print("<< START >>");
  lcd.setCursor(5, 2);
  lcd.print("Use App or");
  lcd.setCursor(5, 3);
  lcd.print("Hit Select");
  
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
  lcd.print("   Manual Mode!");
  lcd.setCursor(0, 1);
  lcd.print("   Get a drink");
  lcd.setCursor(0, 2);
  lcd.print("   Play Plinko Game");
  homeMenuCurrentOption = 1;
  updateSelectionToOption();
}

void LCD::printGameScreen() {

// Print Game Screen
  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" Welcome to Plinko ");
  lcd.setCursor(0, 2);
  lcd.print("   Please Insert Coin   "); 
}

void LCD::printTimeoutPlaceholder () {
  lcd.setCursor(8,3);
  lcd.print("TIMEOUT= ");
}

void LCD::updateTimeout(int counter) {
  lcd.setCursor(18,3);
  if (counter > 9) {
	  lcd.print(counter);
  }
  else {
	  lcd.print("0" + counter);
  }
}

void LCD::printTimeoutOccurred() {
  lcd.clear();
  lcd.setCursor(7,1);
  lcd.print("TIMEOUT");
}

int	LCD::getSelection()	{
	return homeMenuCurrentOption;
}

void LCD::moveSelection(String direction) {

  if (direction == "Down") {
    if (homeMenuCurrentOption == 2) {
      homeMenuCurrentOption = 1;
    } else {
      homeMenuCurrentOption++;
    }
  } else if (direction == "Up") {
    if (homeMenuCurrentOption == 1) {
      homeMenuCurrentOption = 2;
    } else {
      homeMenuCurrentOption--;
    }
  }
  updateSelectionToOption();
}

void LCD::updateSelectionToOption() {
  
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  lcd.setCursor(0, homeMenuCurrentOption);
  lcd.print(">");

}

void LCD::printGameOutcomeScreen(int result) {
  
  switch(result) {
    case 1:  printGameOutcomeWin(100, 0); //  A = 100 and B = 0
        break;
    case 2:  printGameOutcomeWin(25, 75); //  A = 25 and B = 75
        break;
    case 3:  printGameOutcomeLose();      //  A = 0 and B = 0
        break;
    case 4:  printGameOutcomeWin(50, 50); //  A = 50 and B = 50
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
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Game Result");
  lcd.setCursor(4, 1);
  lcd.print("You Win");
  lcd.setCursor(3, 2);
  lcd.print(" part A");// need to add variable A
  lcd.setCursor(3, 3);
  lcd.print(" part B");// need to add variable B
  
}

void LCD::printGameOutcomeLose() {
  
//  Print the lose screen
  
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("You Lose!");
  lcd.setCursor(7, 2);
  lcd.print("Try Again!");
}
