#include "Arduino.h"
#include "gameControl.h"
#include "PinLayout.h"

// ELEC 3907: Function definitions to get the plinko to output the correct
// Seth Thompson: 101031310

GameControl::GameControl()
{
  PinLayout pinLayout;
  pinLayout.setup();
}

int GameControl::playGame()
{
  // Variable for polling the user 
  bool polling = true;
  // Variable to store the result of the game
  int result;
  // add in delay counter, let's say needs 10 counts of high
  digitalWrite(plinkoEnable,HIGH);
  
  while(polling == true)
  {
    if(digitalRead(plinkoBin1) == LOW)
    {
      result = 1;
      polling = false;
    }

    if(digitalRead(plinkoBin2) == LOW)
    {
      result = 2;
      polling = false;
    }

    if(digitalRead(plinkoBin3) == LOW)
    {
      result = 3;
      polling = false;
    }

    if(digitalRead(plinkoBin4) == LOW)
    {
      result = 4;
      polling = false;
    }

    if(digitalRead(plinkoBin5) == LOW)
    {
      result = 5;
      polling = false;
    }

    if(digitalRead(plinkoBin6) == LOW)
    {
      result = 6;
      polling = false;
    }

    if(digitalRead(plinkoBin7) == LOW)
    {
      result = 7;
      polling = false;
    }
  }

  digitalWrite(plinkoEnable,LOW);

  // Returning result
  return result;
  
}