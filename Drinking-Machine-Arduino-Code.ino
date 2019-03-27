#include "LCD.h"
#include "PumpControl.h"
#include "GameControl.h"

LCD lcd;
GameControl game;
PumpControl pumps;

unsigned long int refTime;

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
      flushSerial1();
      return BLUETOOTH_SELECT_PRIMARY_MENU;
    }
  }
}

enum stateMachine manualSelectPrimaryMenu () {
}

enum stateMachine manualSelectDrinkMenu () {
  
}

enum stateMachine bluetoothSelectPrimaryMenu () {
  lcd.printBluetoothScreen();
  // millisecond timeout
  char t;
  int counter = 60;
  refTime = millis();
  lcd.printTimeoutPlaceholder();
  while (counter) {
    if (oneSecondTick(refTime)) {
      counter--;
      refTime = millis();
      lcd.updateTimeout(counter);
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
  } return START_STATE;
}

enum stateMachine bluetoothSelectDrinkMenu () {
}

enum stateMachine bluetoothRecipeSaveState () {
  
}

enum stateMachine gameState () {
  
}

void loop() {
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
  }
}

void flushSerial1() {
  char t;
  while (Serial1.available() > 0 ) {
   t = Serial1.read();
  }
}

bool oneSecondTick (unsigned long int &lastCheck){
  return (millis() - lastCheck) > 1000;
}
