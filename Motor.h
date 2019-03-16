#ifndef Motor_h
#define Motor_h

#include "pinLayout.h"

#include "Motor.h"

// Define the Motor class

class Motor{
 public:
  Motor();

  void pour(int amountOfA, int amountOfB); // Mixing and pouring drinks should be seperate functions

private:
  void dispense(string option, int amountOfA);
  void clear(string option);
};

Motor::Motor()
{
}


// Test

#endif
