// ELEC 3907: Code to controlthe plinko system
// Seth Thompson: 101031310

#ifndef game_Control_h
#define game_Control_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define plinkoEnable 22
#define bin1 23
#define bin2 24
#define bin3 25
#define bin4 26
#define bin5 27
#define bin6 28
#define bin7 29

class gameControl
{
  public:
  gameControl();

  // The methods
  int Play_Game();

  private:
  
};
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Arduino.h"
#include "game_Control.h"

// ELEC 3907: Function definitions to get the plinko to output the correct
// Seth Thompson: 101031310

gameControl::gameControl()
{
  
}

int gameControl::Play_Game()
{
  // Variable for polling the user 
  bool polling = true;
  // Variable to store the result of the game
  int result;

  digitalWrite(plinkoEnable,HIGH);
  
  while(polling == true)
  {
    if(digitalRead(bin1) == LOW)
    {
      result = 1;
      polling = false;
    }

    if(digitalRead(bin2) == LOW)
    {
      result = 2;
      polling = false;
    }

    if(digitalRead(bin3) == LOW)
    {
      result = 3;
      polling = false;
    }

    if(digitalRead(bin4) == LOW)
    {
      result = 4;
      polling = false;
    }

    if(digitalRead(bin5) == LOW)
    {
      result = 5;
      polling = false;
    }

    if(digitalRead(bin6) == LOW)
    {
      result = 6;
      polling = false;
    }

    if(digitalRead(bin7) == LOW)
    {
      result = 7;
      polling = false;
    }
  }

  digitalWrite(plinkoEnable,LOW);

  // Returning result
  return result;
  
}
