#ifndef time_control_h
#define time_control_h

class TimeControl
{
  private:
    int counter;
	int unsigned long refTime;

  public:
  
  TimeControl();
  bool oneSecondTick();
  int getCounter();
  void resetCounter();
  void updateRefTime(int unsigned long refTimeIn);
  void decrementCounter();
};
#endif