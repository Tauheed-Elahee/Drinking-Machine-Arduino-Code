// ELEC 3907 Group 2H Arduino Code
// Seth Thompson | 101031310
// Rishi Sharma | 101011443
// Tauheed Elahee | 101040312
// Rabeya Khan | 101020419

/*
    STYLING
    ------------------
    For every new LCD state, software should be in a seperate state
*/

#include <Chrono.h> // Including input statement for Chrono Library, Have on each individual computer.
#include <LiquidCrystal.h> // Library is input for easy use of the LCD display
#include <EEPROM.h> // Here for non-volatile memory, recipie saving?
#include "pump_Control.h" // Library made for outputting signals to pumps :D
#include "game_Control.h" // Library made for playing the game.

const int plinkoBin1 = 22;
const int plinkoBin2 = 23;
const int plinkoBin3 = 24;
const int plinkoBin4 = 25;
const int plinkoBin5 = 26;
const int plinkoBin6 = 27;
const int plinkoBin7 = 29;

const int buttonBack = 30;
const int buttonDown = 31;
const int buttonUp = 32;
const int buttonSelect = 33;

const int motor1L = 40;
const int motor1R = 41;
const int motor2L = 42;
const int motor2R = 43;

const int inputdelay = 500;
const int timeout = 30000;

const int buttonblank5 = LOW;

enum stateMachine
{
  START_MANUAL_OR_BLUETOOTH,
  MANUAL_SELECT_OR_GAME,
  MANUAL_SELECT_DRINK,
  GAME_READY_STATE,
  BLUETOOTH_SELECT_OR_GAME,
  BLUETOOTH_SELECT_DRINK,
  GAME_RESULT
};

enum stateMachine currentState = START_MANUAL_OR_BLUETOOTH;

/*
    Both the game and bluetooth variables will be used to signify wether or not the game
    option has been selected or not, and wheter or not someone is using the bluetooth app
    or not, respectively.

    The 'state' variable will be used to determine which state were at on the drink selecting / game
    process, and will allow us to easily path our code

    The 'timeout' variable will be used to determine if no input has been input for an X anount of
    time, and thus will make he state machine go back to 0. Time interval is currently set to 30s.

*/

void setup() {
  // Examlpe to output to serial: Serial.begin(115200); All code here is executed only once

  // setting all digital pins to either INPUT or OUTPUT
  pinMode(buttonBack, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(buttonUp, INPUT);
  pinMode(buttonSelect, INPUT);
  pinMode(plinkoBin1, INPUT);
  pinMode(plinkoBin2, INPUT);
  pinMode(plinkoBin3, INPUT);
  pinMode(plinkoBin4, INPUT);
  pinMode(plinkoBin5, INPUT);
  pinMode(plinkoBin6, INPUT);
  pinMode(plinkoBin7, INPUT);
  pinMode(motor1L, OUTPUT);
  pinMode(motor1R, OUTPUT);
  pinMode(motor2L, OUTPUT);
  pinMode(motor2R, OUTPUT);
}

// In all case functions, Tauheed will add the code for the UI. Seth is Dataflow (me :D).


// BluetoothORManual() is used as the initial state to determine wheter the user is using the manual or bluetooth input
enum stateMachine BluetoothORManual()
{
  // Add code here Rishi
};

//Initial polling to see if they want to play a game. (button interface)
enum stateMachine InitialPollingManual()
{
  bool polling = true;
  enum stateMachine nextState;
  int selectionNumber = 0;
  Chrono timer;

  while (polling == true)
  {
    //person selects "up"
    if (digitalRead(buttonUp) == HIGH && timer.hasPassed(inputdelay) && selectionNumber != 1)
    {
      selectionNumber++;
    }

    //person selects "down"
    if (digitalRead(buttonDown) == HIGH && timer.hasPassed(inputdelay) && selectionNumber != 0)
    {
      selectionNumber--;
    }

    //person selects no
    if (digitalRead(buttonSelect) == HIGH && timer.hasPassed(inputdelay) && selectionNumber == 0)
    {
      //go back to start, and polling done
      nextState = MANUAL_SELECT_DRINK;
      polling = false;
    }
    //person selects yes
    if (digitalRead(buttonSelect) == HIGH && timer.hasPassed(inputdelay) && selectionNumber == 1)
    {
      //go back to start, and polling done
      nextState = GAME_READY_STATE;
      polling = false;
    }
    //person selects the 'reset' button OR timeout has occured
    if ((digitalRead(buttonBack) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      nextState = START_MANUAL_OR_BLUETOOTH;
      polling = false;
    }
  }
  return nextState;
}

//Initial polling to see if they want to play a game. (bluetooth interface)
enum stateMachine InitialPollingBluetooth()
{
  enum stateMachine nextState;
  bool polling = true;
  Chrono timer;

  while (polling == true)
  {
    //person selects no
    if (digitalRead(buttonblank5) == HIGH && timer.hasPassed(inputdelay))
    {

      //go back to start, and polling done
      nextState = BLUETOOTH_SELECT_DRINK;
      polling = false;
    }
    //person selects yes
    if (digitalRead(buttonblank5) == HIGH && timer.hasPassed(inputdelay))
    {

      //go back to start, and polling done
      nextState = GAME_READY_STATE;
      polling = false;
    }
    //person selects the 'go back' button
    if ((digitalRead(buttonblank5) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      nextState = START_MANUAL_OR_BLUETOOTH;
      polling = false;
    }
  }
  return nextState;
}

// Case to select which drink they want from the button input.
enum stateMachine DrinkSelectionManual()
{
  enum stateMachine nextState;
  bool polling = true;
  bool drinkA = true;
  int selectionNumber = 0;
  pumpControl pump(motor1R, motor1L, motor2R, motor2L);
  Chrono timer;

  while (polling == true)
  {
    //person selects "up"
    if (digitalRead(buttonUp) == HIGH && timer.hasPassed(inputdelay) && selectionNumber != 1)
    {
      selectionNumber++;
    }

    //person selects "down"
    if (digitalRead(buttonDown) == HIGH && timer.hasPassed(inputdelay) && selectionNumber != 0)
    {
      selectionNumber--;
    }
    //person selects drink A
    if (digitalRead(buttonSelect) == HIGH && timer.hasPassed(inputdelay) && selectionNumber == 0)
    {
      pump.Dispense_Drink_A();
      nextState = START_MANUAL_OR_BLUETOOTH;
      polling = false;
    }
    //person selects drink B
    if (digitalRead(buttonSelect) == HIGH && timer.hasPassed(inputdelay) && selectionNumber == 1)
    {
      pump.Dispense_Drink_B();
      nextState = START_MANUAL_OR_BLUETOOTH;
      polling = false;
    }
    //person selects the 'go back' button or timeout occurs
    if ((digitalRead(buttonBack) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      nextState = START_MANUAL_OR_BLUETOOTH;
      polling = false;
    }
  }
  return nextState;
}

// Case to select which drink they want from the bluetooth input.
enum stateMachine DrinkSelectionBluetooth()
{
  enum stateMachine nextState;
  bool polling = true;
  pumpControl pump(motor1R, motor1L, motor2R, motor2L);
  Chrono timer;

  while (polling == true)
  {
    //person selects drink A
    if (digitalRead(buttonblank5) == HIGH && timer.hasPassed(inputdelay))
    {
      pump.Dispense_Drink_A();
      nextState = START_MANUAL_OR_BLUETOOTH;
      polling = false;
    }
    //person selects drink B
    if (digitalRead(buttonblank5) == HIGH && timer.hasPassed(inputdelay))
    {
      pump.Dispense_Drink_B();
      nextState = START_MANUAL_OR_BLUETOOTH;
      polling = false;
    }
    //person selects the 'go back' button or timeout occurs
    if ((digitalRead(buttonblank5) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      //Code to put signal to correct pumps

      //go back to start, and polling done
      nextState = START_MANUAL_OR_BLUETOOTH;
      polling = false;
    }
  }
  return nextState;
}

// Case in which someone did pick to play a game (button interface)
enum stateMachine Game()
{
  enum stateMachine nextState;
  bool polling = true;
  gameControl game;
  pumpControl pump(motor1R, motor1L, motor2R, motor2L);
  int result;
  Chrono timer;

  result = game.Play_Game();

  // Looking at the result of the game 
  switch (result)
  {
    case 1:
      pump.Dispense_Drink_A();
      break;

    case 2:
      pump.Dispense_1_To_4();
      break;

    case 3:
      pump.Dispense_Nothing();
      break;

    case 4:
      pump.Dispense_Half_And_Half();
      break;

    case 5:
      pump.Dispense_Nothing();
      break;

    case 6:
      pump.Dispense_4_To_1();
      break;

    case 7:
      pump.Dispense_Drink_B();
      break;
  }

  //person selects the 'go back' button
  if ((digitalRead(buttonBack) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
  {
    nextState = START_MANUAL_OR_BLUETOOTH;
    polling = false;
  }

  return nextState;
}

enum stateMachine Game_Result()
{
  enum stateMachine nextState;
  bool polling = true;
  Chrono timer;

  return nextState;
}

void loop() {

  // Using switch case statements to allow for proper outputs at each state. More efficent than one giant elseif.

  switch (currentState)
  {
    case START_MANUAL_OR_BLUETOOTH:
      currentState = BluetoothORManual();
      break;

    case MANUAL_SELECT_OR_GAME:
      currentState = InitialPollingManual();
      break;

    case BLUETOOTH_SELECT_OR_GAME:
      currentState = InitialPollingBluetooth();
      break;

    case MANUAL_SELECT_DRINK:
      currentState = DrinkSelectionManual();
      break;

    case BLUETOOTH_SELECT_DRINK:
      currentState = DrinkSelectionBluetooth();
      break;

    case GAME_READY_STATE:
      currentState = Game();
      break;

    case GAME_RESULT:
      currentState = Game_Result();
      break;
  }

}
