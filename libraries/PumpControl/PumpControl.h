// ELEC 3907: Header file to get pumps going in skeleton
// Seth Thompson: 101031310

#ifndef pump_Control_h
#define pump_Control_h

// these constants MUST be updated !!!!

#define FLOW_TOTAL_LENGTH_TIME_A 1
#define FLOW_TOTAL_LENGTH_TIME_B 1
#define UNIT_OF_LIQUID_A 1
#define UNIT_OF_LIQUID_B 1

class PumpControl
{
  public:
  PumpControl();

  // The methods
  void dispense(int unitsOfA, int unitsOfB);
};
#endif