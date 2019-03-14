// ELEC 3907: 
// Seth Thompson: 101031310

#ifndef game_Control_h
#define game_Control_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class gameControl
{
  public:
  gameControl();

  // The methods
  int Play_Game();

  private:
  int Bin1;
  int Bin2;
  int Bin3;
  int Bin4;
  int Bin5;
  int Bin6;
  int Bin7;
};
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ELEC 3907: Function definitions to get the plinko to output the correct
// Seth Thompson: 101031310

#include "Arduino.h"
#include "game_Control.h"

gameControl::gameControl()
{
  Bin1 = 22;
  Bin2 = 23;
  Bin3 = 24;
  Bin4 = 25;
  Bin5 = 26;
  Bin6 = 27;
  Bin7 = 28;
}

int gameControl::Play_Game()
{
  // Variable for polling the user 
  bool polling = true;
  // Variable to store the result of the game
  int result;

  
  while(polling == true)
  {
    if(digitalRead(Bin1) == LOW)
    {
      result = 1;
      polling = false;
    }

    if(digitalRead(Bin2) == LOW)
    {
      result = 2;
      polling = false;
    }

    if(digitalRead(Bin3) == LOW)
    {
      result = 3;
      polling = false;
    }

    if(digitalRead(Bin4) == LOW)
    {
      result = 4;
      polling = false;
    }

    if(digitalRead(Bin5) == LOW)
    {
      result = 5;
      polling = false;
    }

    if(digitalRead(Bin6) == LOW)
    {
      result = 6;
      polling = false;
    }

    if(digitalRead(Bin7) == LOW)
    {
      result = 7;
      polling = false;
    }
  }

  // Returning result
  return result;
  
}
