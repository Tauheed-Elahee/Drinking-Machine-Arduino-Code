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
  updateSelectionToOption(1);
  
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
	  lcd.print(" " + counter);
  }
}

int	LCD::getSelection()	{
	return currentOption;
}

void LCD::moveSelection(String direction) {

  if (direction == "Down") {
    if (currentOption == 3) {
      currentOption = 1;
    } else {
      currentOption++;
    }
  } else if (direction == "Up") {
    if (currentOption == 1) {
      currentOption = 3;
    } else {
      currentOption--;
    }
  }

  updateSelectionToOption(currentOption);
}

void LCD::updateSelectionToOption(int currentOption) {
  
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  lcd.setCursor(0, currentOption);
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
  
// Print the win game screen with the correct amount for drink A and drink B
    
//     char Achar = (char)A;
//     char Astring[12];
//     Astring[0] = Achar;
//     Astring[4, 12] = " part A"; // Fix this
    
    char Bchar = (char)B;
    
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
