#ifndef pump_Control_h
#define pump_Control_h

// these constants MUST be updated !!!!

#define FLOW_TOTAL_LENGTH_TIME_A 1000
#define FLOW_TOTAL_LENGTH_TIME_B 1000
#define UNIT_OF_LIQUID_A 12500UL
#define UNIT_OF_LIQUID_B 18518UL // MUST BE AT LEAST LONG ELSE OVERFLOW

class PumpControl
{
  public:
  PumpControl();

  // The methods
  void primeA();
  void primeB();
  void clearA();
  void clearB();
  void dispense(int unitsOfA, int unitsOfB);
};
#endif