
#include "LCD.h"
#include "PumpControl.h"
#include "GameControl.h"

enum stateMachine {
  START_STATE,
  MANUAL_SELECT_PRIMARY_MENU,
  MANUAL_SELECT_DRINK_MENU,
  GAME_STATE,
  BLUETOOTH_SELECT_PRIMARY_MENU,
  BLUETOOTH_SELECT_DRINK_MENU,
};

LCD lcd;
GameControl game;

enum stateMachine currentState = START_STATE;


void setup() {
  // put your setup code here, to run once:
}

enum stateMachine startState () {
  
}

enum stateMachine manualSelectPrimaryMenu () {
  
}

enum stateMachine manualSelectDrinkMenu () {
  
}

enum stateMachine bluetoothSelectPrimaryMenu () {
  
}

enum stateMachine bluetoothSelectDrinkMenu () {
  
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
    case GAME_STATE:
      currentState = gameState();
      break;
  }
}
