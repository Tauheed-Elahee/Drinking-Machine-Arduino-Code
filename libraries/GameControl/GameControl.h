// ELEC 3907: Code to controlthe plinko system
// Seth Thompson: 101031310

#ifndef game_Control_h
#define game_Control_h

#define plinkoEnable 22
#define bin1 23
#define bin2 24
#define bin3 25
#define bin4 26
#define bin5 27
#define bin6 28
#define bin7 29

class GameControl
{
  public:
  GameControl();
  int playGame();
};
#endif