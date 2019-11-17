#ifndef game_Control_h
#define game_Control_h

class GameControl
{
  private:
    int readAsLowBin;
  public:
    GameControl();
    bool checkPlinko();
    void returnGameResult(int &unitsOfA, int &unitsOfB);
    int getBin();
    void enable();
    void disable();
};
#endif