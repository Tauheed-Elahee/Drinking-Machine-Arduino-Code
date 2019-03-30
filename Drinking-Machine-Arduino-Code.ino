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
  MANUAL_SELECT_PREMIXED_MENU,
  MANUAL_SELECT_CUSTOM_MENU,
  GAME_STATE,
  BLUETOOTH_SELECT_PRIMARY_MENU,
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
  lcd.printTimeoutPlaceholder();
  // forces select button to be cleared
  int currentButton = 33;
  boolean debounce = false;
  timeControl.updateRefTime(millis());
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
      lcd.moveTwoChoiceSelection('d');
        currentButton = 31;
        debounce = false;
      }
      else if (butUp) {
        lcd.moveTwoChoiceSelection('u');
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
  switch (lcd.getTwoChoiceSelection()) {
    case 1: return MANUAL_SELECT_DRINK_MENU;
    case 2: return GAME_STATE;
    default: return START_STATE;
  }
}

enum stateMachine manualSelectDrinkMenu () {
  lcd.printDrinkSelectScreen();
  lcd.printTimeoutPlaceholder();
  // forces select button to be cleared
  int currentButton = 33;
  boolean debounce = false;
  timeControl.updateRefTime(millis());
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
      lcd.moveTwoChoiceSelection('d');
        currentButton = 31;
        debounce = false;
      }
      else if (butUp) {
        lcd.moveTwoChoiceSelection('u');
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
  switch (lcd.getTwoChoiceSelection()) {
    case 1: return MANUAL_SELECT_PREMIXED_MENU;
    case 2: return MANUAL_SELECT_CUSTOM_MENU;
    default: return START_STATE;
  }
}

enum stateMachine manualSelectPremixedMenu() {
  lcd.printDrinkPremixedScreen();
  lcd.printTimeoutPlaceholder();
  // forces select button to be cleared
  int currentButton = 33;
  boolean debounce = false;
  timeControl.updateRefTime(millis());
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
      lcd.movePremixedSelection('d');
        currentButton = 31;
        debounce = false;
      }
      else if (butUp) {
        lcd.movePremixedSelection('u');
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
  switch (lcd.getPremixSelection()) {
    case 1: lcd.printDispensing(4,0); pumps.dispense(4,0); break;
    case 2: lcd.printDispensing(0,4); pumps.dispense(0,4); break;
    case 3: lcd.printDispensing(2,2); pumps.dispense(2,2); break;
    case 4: lcd.printDispensing(3,1); pumps.dispense(3,1); break;
    case 5: lcd.printDispensing(1,3); pumps.dispense(1,3); break;
    default: return START_STATE;
  }
  return START_STATE;
}

enum stateMachine manualSelectCustomMenu() {
  lcd.printDrinkCustomScreen();
  lcd.printTimeoutPlaceholder();
  // forces select button to be cleared
  int currentButton = 33;
  boolean debounce = false;
  timeControl.updateRefTime(millis());
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
      lcd.moveThreeChoiceSelection('d');
        currentButton = 31;
        debounce = false;
      }
      else if (butUp) {
        lcd.moveThreeChoiceSelection('u');
        currentButton = 32;
        debounce = false;
      }
      else if (butBack) {
        return START_STATE;
      }
      else if (butSelect) {
        currentButton = 33;
        debounce = false;
        switch(lcd.getThreeChoiceSelection()){
          case 1: lcd.incrementDrinkCounter('a'); break;
          case 2: lcd.incrementDrinkCounter('b'); break;
          case 3: {
            int unitsOfA;
            int unitsOfB;
            lcd.getCustomDrinkParams(unitsOfA,unitsOfB);
            if (unitsOfA || unitsOfB) {
              lcd.printDispensing(unitsOfA,unitsOfB);
              pumps.dispense(unitsOfA,unitsOfB);
            }
            return START_STATE;
          }
          default: return START_STATE;
        }
      }
    }
  }
  if (!timeControl.getCounter()) {
      lcd.printTimeoutOccurred();
      delay(2000);
      return START_STATE;
  }
  return START_STATE;
}

enum stateMachine bluetoothSelectPrimaryMenu () {
  lcd.printBluetoothScreen();
  lcd.printTimeoutPlaceholder();
  char t;
  timeControl.updateRefTime(millis());
  while (timeControl.getCounter()) {
    if (timeControl.oneSecondTick()) {
      timeControl.decrementCounter();
      timeControl.updateRefTime(millis());
      lcd.updateTimeout(timeControl.getCounter());
    }
    if (Serial1.available() > 0) {
      t = Serial1.read();
      if (t == 'a'){
//        return BLUETOOTH_SELECT_DRINK_MENU;
      }
      if (t == 'b') {
        return GAME_STATE;
      }
      if (t == 'c') {
//        return BLUETOOTH_RECIPE_STATE;
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

enum stateMachine gameState () {
  lcd.printGameScreen();
  lcd.printTimeoutPlaceholder();
  game.enable();
  timeControl.updateRefTime(millis());
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
      if (unitsOfA || unitsOfB) {
        lcd.printDispensing(unitsOfA,unitsOfA);
        pumps.dispense(unitsOfA, unitsOfB);
      }
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
    case MANUAL_SELECT_PREMIXED_MENU:
      currentState = manualSelectPremixedMenu();
      break;
    case MANUAL_SELECT_CUSTOM_MENU:
      currentState = manualSelectCustomMenu();
      break;

    // might squash all the bluetooth stuff into one
    case BLUETOOTH_SELECT_PRIMARY_MENU:
      currentState = bluetoothSelectPrimaryMenu();
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
