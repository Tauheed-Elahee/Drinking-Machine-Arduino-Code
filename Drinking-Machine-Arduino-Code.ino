// ELEC 3907 Group 2H Arduino Code
// Seth Thompson | 101031310
// Rishi Sharma | 101011443
// Tauheed Elahee | 101040312
// Rabeya Khan | 101020419

#include <Chrono.h> // Including input statement for Chrono Library, Have on each individual computer.

/*
    Difference between Metro and Chrono Library is that metro repeats on a set interval, and
    Chrono simply starts counting as soon as the instance is created. Look up each library for
    syntax as needed.
*/

#include <LiquidCrystal.h> // Library is input for easy use of the LCD display
#include <EEPROM.h> // Here for non-volatile memory, recipie saving?

//Begin all instances here, ex: Metro serialMetro = Metro(250);

bool game = false;
bool bluetooth = false;
const int buttonblank1 = 0;
const int buttonblank2 = 0;
const int buttonblank3 = 0;
const int buttonblank4 = 0;
const int buttonblank5 = 0;
const int buttonblank6 = 0;
int inputdelay = 500;
int timeout = 30000;

enum stateMachine
{
  START,
  MANUAL_POLLING,
  MANUAL_SELECTION,
  MANUAL_GAME,
  BLUETOOTH_POLLING,
  BLUETOOTH_SELECTION,
  BLUETOOTH_GAME,
};

enum stateMachine currentState = START;

// Defining stuff for the lcd variable
//int rs = , enable = , d4 = , d5 = , d6 = , d7 = ;
//LiquidCrystal lcd(rs,enable,d4,d5,d6,d7);

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

  //lcd.begin(20, 4);
}

/*int stateExpectFirstUserInput() {
  polling = true;
  Chrono timer;
  timer.reset();
  while(true) {
    input = whatevertheinputisthatguyputs;
    if (input == 'enter') break;
    if (timer.haspassed(30000)) break;
  }
  }*/

// In all case functions, Tauheed will add the code for the UI. Seth is Dataflow (me :D).


// BluetoothorManual() is used as the initial 
enum stateMachine BluetoothORManual()
{
  bool polling;
  enum stateMachine nextState;
  
  // Somehow obtain wheter or not buttons or bluetooth are being used...
  //while(polling)
  //{
    //if (!bluetooth)
    //{
    //  nextState = MANUAL_POLLING;
    //  polling = false;
    //}
    //else
    //{
    //  nextState = BLUETOOTH_POLLING;
    //  polling = false;
    //}
  //}

  return nextState;
};

//Initial polling to see if they want to play a game. (button interface)
enum stateMachine InitialPollingManual()
{
  bool polling = true;
  enum stateMachine nextState;
  Chrono timer;

  while (polling == true)
  {
    //person selects no
    if (digitalRead(buttonblank1) == HIGH && timer.hasPassed(inputdelay))
    {
      nextState = MANUAL_SELECTION;
      polling = false;
    }
    //person selects yes
    if (digitalRead(buttonblank2) == HIGH && timer.hasPassed(inputdelay))
    {
      nextState = MANUAL_GAME;
      polling = false;
    }
    //person selects the 'reset' button
    if ((digitalRead(buttonblank3) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      nextState = START;
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
  Chrono timer;

  while (polling == true)
  {
    //person selects drink A
    if (digitalRead(buttonblank4) == HIGH && timer.hasPassed(inputdelay))
    {
      //Code to put signal to correct pumps
      nextState = START;
      polling = false;
    }
    //person selects drink B
    if (digitalRead(buttonblank5) == HIGH && timer.hasPassed(inputdelay))
    {
      //Code to put signal to correct pumps
      nextState = START;
      polling = false;
    }
    //person selects the 'go back' button or timeout occurs
    if ((digitalRead(buttonblank6) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      nextState = START;
      polling = false;
    }
  }
  return nextState;
}

// Case in which someone did pick to play a game (button interface)
enum stateMachine GameManual()
{
  enum stateMachine nextState;
  bool polling = true;
  Chrono timer;

  while (polling == true)
  {
    // Add logic to get game going... most likely more pin inputs

    //person selects the 'go back' button
    if ((digitalRead(buttonblank6) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      nextState = START;
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
    if (digitalRead(buttonblank1) == HIGH && timer.hasPassed(inputdelay))
    {
      nextState = BLUETOOTH_SELECTION;
      polling = false;
    }
    //person selects yes
    if (digitalRead(buttonblank2) == HIGH && timer.hasPassed(inputdelay))
    {
      nextState = BLUETOOTH_GAME;
      polling = false;
    }
    //person selects the 'go back' button
    if ((digitalRead(buttonblank3) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      nextState = START;
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
  Chrono timer;

  while (polling == true)
  {
    //person selects drink A
    if (digitalRead(buttonblank4) == HIGH && timer.hasPassed(inputdelay))
    {
      //Code to put signal to correct pumps
      nextState = START;
      polling = false;
    }
    //person selects drink B
    if (digitalRead(buttonblank5) == HIGH && timer.hasPassed(inputdelay))
    {
      //Code to put signal to correct pumps
      nextState = START;
      polling = false;
    }
    //person selects the 'go back' button or timeout occurs
    if ((digitalRead(buttonblank6) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      nextState = START;
      polling = false;
    }
  }
  return nextState;
}

// Case in which someone did pick to play a game (bluetooth interface)
enum stateMachine GameBluetooth()
{
  enum stateMachine nextState;
  bool polling = true;
  Chrono timer;

  while (polling == true)
  {
    // Add logic to get game going... most likely more pin inputs
    
    //person selects the 'go back' button
    if ((digitalRead(buttonblank6) == HIGH && timer.hasPassed(inputdelay)) || timer.hasPassed(timeout))
    {
      nextState = START;
      polling = false;
    }
  }
  return nextState;
}

void loop() {

  // Using switch case statements to allow for proper outputs at each state. More efficent than one giant elseif.
  
  switch (currentState)
  { 
    case START:
      currentState = BluetoothORManual();
      break;
      
    case MANUAL_POLLING:
      currentState = InitialPollingManual();
      break;

    case MANUAL_SELECTION:
      currentState = DrinkSelectionManual();
      break;

    case MANUAL_GAME:
      currentState = GameManual();
      break;

    case BLUETOOTH_POLLING:
      currentState = InitialPollingBluetooth();
      break;

    case BLUETOOTH_SELECTION:
      currentState = DrinkSelectionBluetooth();
      break;

    case BLUETOOTH_GAME:
      currentState = GameBluetooth();
      break;
  }

}
