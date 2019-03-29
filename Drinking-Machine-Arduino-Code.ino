#include "LCD.h"
#include "PumpControl.h"
#include "GameControl.h"
#include "TimeControl.h"

#define butBack digitalRead(30)
#define butDown digitalRead(31)
#define butUp digitalRead(32)
#define butSelect digitalRead(33)


LCD lcd;
GameControl game;
PumpControl pumps;
TimeControl timeControl;

enum stateMachine {
  START_STATE,
  MANUAL_SELECT_PRIMARY_MENU,
  MANUAL_SELECT_DRINK_MENU,
  GAME_STATE,
  BLUETOOTH_SELECT_PRIMARY_MENU,
  BLUETOOTH_SELECT_DRINK_MENU,
  BLUETOOTH_RECIPE_STATE
};

enum stateMachine currentState;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  currentState = START_STATE;
}

enum stateMachine startState () {
  delay(1000);
  lcd.printWelcomeScreen();
  flushSerial1();
  // the "select" button will initiate manual mode
  while (true) {
    if (digitalRead(33)) {
      return MANUAL_SELECT_PRIMARY_MENU;
    }
    if (Serial1.available() > 0) {
      if (Serial1.read() == 's') {
        flushSerial1();
        return BLUETOOTH_SELECT_PRIMARY_MENU;
      }
     flushSerial1();
    } 
  }
}

enum stateMachine manualSelectPrimaryMenu () {
  lcd.printHomeScreen();
  timeControl.updateRefTime(millis());
  lcd.printTimeoutPlaceholder();
  // forces select button to be cleared
  int currentButton = 33;
  boolean debounce = false;
  while (timeControl.getCounter()) {
    if (timeControl.oneSecondTick()) {
      timeControl.decrementCounter();
      timeControl.updateRefTime(millis());
      lcd.updateTimeout(timeControl.getCounter());
    }
    // check for debounce
    if (!digitalRead(currentButton)) {
      debounce = true;
      delay(5);
    }
    if (debounce) {
      if (butDown) {
      lcd.moveSelection("Down");
        currentButton = 31;
        debounce = false;
      }
      else if (butUp) {
        lcd.moveSelection("Up");
        currentButton = 32;
        debounce = false;
      }
      else if (butBack) {
        return START_STATE;
      }
      else if (butSelect) {
        break;
      }
    }
  }
  if (!timeControl.getCounter()) {
      lcd.printTimeoutOccurred();
      delay(2000);
      return START_STATE;
  }
  switch (lcd.getSelection()) {
    case 1: return MANUAL_SELECT_DRINK_MENU;
    case 2: return GAME_STATE;
    default: return START_STATE;
  }
}

enum stateMachine manualSelectDrinkMenu () {
  
}

enum stateMachine bluetoothSelectPrimaryMenu () {
  lcd.printBluetoothScreen();
  // millisecond timeout
  char t;
  timeControl.updateRefTime(millis());
  lcd.printTimeoutPlaceholder();
  while (timeControl.getCounter()) {
    if (timeControl.oneSecondTick()) {
      timeControl.decrementCounter();
      timeControl.updateRefTime(millis());
      lcd.updateTimeout(timeControl.getCounter());
    }
    if (Serial1.available() > 0) {
      t = Serial1.read();
      if (t == 'a'){
        return BLUETOOTH_SELECT_DRINK_MENU;
      }
      if (t == 'b') {
        return GAME_STATE;
      }
      if (t == 'c') {
        return BLUETOOTH_RECIPE_STATE;
      }
      if (t == 'e') {
        return START_STATE;
      }
      flushSerial1();
    }
  }
  lcd.printTimeoutOccurred();
  delay(2000);
  return START_STATE;
}

enum stateMachine bluetoothSelectDrinkMenu () {
}

enum stateMachine bluetoothRecipeSaveState () {
  
}

enum stateMachine gameState () {
  lcd.printGameScreen();
  timeControl.updateRefTime(millis());
  lcd.printTimeoutPlaceholder();
  game.enable();
  while (timeControl.getCounter()) {
    if (timeControl.oneSecondTick()) {
      timeControl.decrementCounter();
      timeControl.updateRefTime(millis());
      lcd.updateTimeout(timeControl.getCounter());
    }
    if (game.checkPlinko()) {
      game.disable();
      int unitsOfA;
      int unitsOfB;
      game.returnGameResult(unitsOfA, unitsOfB);
      lcd.printGameOutcomeScreen(game.getBin());
      delay(4000);
      // print dispensing drink
      pumps.dispense(unitsOfA, unitsOfB);
      return START_STATE;
    }
  }
  game.disable();
  lcd.printTimeoutOccurred();
  delay(2000);
  return START_STATE;
}

void loop() {
  timeControl.resetCounter();
  switch (currentState) {
    case START_STATE:
      currentState = startState();
      break;
    case MANUAL_SELECT_PRIMARY_MENU:
      currentState = manualSelectPrimaryMenu();
      break;
    case MANUAL_SELECT_DRINK_MENU:
      currentState = manualSelectDrinkMenu();
      break;
    case BLUETOOTH_SELECT_PRIMARY_MENU:
      currentState = bluetoothSelectPrimaryMenu();
      break;
    case BLUETOOTH_SELECT_DRINK_MENU:
      currentState = bluetoothSelectDrinkMenu();
      break;
    case BLUETOOTH_RECIPE_STATE:
      currentState = bluetoothRecipeSaveState();
      break;
    case GAME_STATE:
      currentState = gameState();
      break;
    default:
      currentState = startState();
      break;
  }
}

void flushSerial1() {
  char t;
  while (Serial1.available() > 0 ) {
   t = Serial1.read();
  }
}
