// ELEC 3907: Header file to get pumps going in skeleton
// Seth Thompson: 101031310

#ifndef pump_Control_h
#define pump_Control_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define flow_out 10000
#define flow_in 500
#define flow_quarter_small 2500
#define flow_quarter_big 7500
#define flow_half 5000
#define delaytime 100

class pumpControl
{
  public:
  pumpControl(int MotorOutA, int MotorInA, int MotorOutB, int MotorInB);

  // The methods
  void Dispense_Drink_A();
  void Dispense_Drink_B();
  void Dispense_1_To_4();
  void Dispense_4_To_1();
  void Dispense_Half_And_Half();
  void Dispense_Nothing();

  private:
  int motorAOut;
  int motorAIn;
  int motorBOut;
  int motorBIn;
};
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Arduino.h"
#include "pump_Control.h"
// ELEC 3907: cpp file to get pumps going in skeleton
// Seth Thompson: 101031310

pumpControl::pumpControl(int motorAOut, int motorAIn, int motorBOut, int motorBIn) 
{
  motorAOut = motorAOut;
  motorAIn = motorAIn;
  motorBOut = motorBOut;
  motorBIn = motorBIn;
}

void pumpControl::Dispense_Drink_A()
{
  // Add code once flow rate is determined
  digitalWrite(motorAOut,HIGH);
  delay(flow_out);
  digitalWrite(motorAOut,LOW);
  delay(delaytime);
  digitalWrite(motorAIn,HIGH);
  delay(flow_in);
  digitalWrite(motorAIn,LOW);
}

void pumpControl::Dispense_Drink_B()
{
  // Add code once flow rate is determined
  digitalWrite(motorBOut,HIGH);
  delay(flow_out);
  digitalWrite(motorBOut,LOW);
  delay(delaytime);
  digitalWrite(motorBIn,HIGH);
  delay(flow_in);
  digitalWrite(motorBIn,LOW);
}

void pumpControl::Dispense_1_To_4()
{
  //1/4 A, 3/4 B
  digitalWrite(motorAOut,HIGH);
  delay(flow_quarter_small);
  digitalWrite(motorAOut,LOW);
  delay(delaytime);
  digitalWrite(motorAIn,HIGH);
  delay(flow_in);
  digitalWrite(motorAIn,LOW);

  digitalWrite(motorBOut,HIGH);
  delay(flow_quarter_big);
  digitalWrite(motorBOut,LOW);
  delay(delaytime);
  digitalWrite(motorBIn,HIGH);
  delay(flow_in);
  digitalWrite(motorBIn,LOW);
}

void pumpControl::Dispense_4_To_1()
{
  //3/4 A, 1/4 B
  digitalWrite(motorAOut,HIGH);
  delay(flow_quarter_big);
  digitalWrite(motorAOut,LOW);
  delay(delaytime);
  digitalWrite(motorAIn,HIGH);
  delay(flow_in);
  digitalWrite(motorAIn,LOW);

  digitalWrite(motorBOut,HIGH);
  delay(flow_quarter_small);
  digitalWrite(motorBOut,LOW);
  delay(delaytime);
  digitalWrite(motorBIn,HIGH);
  delay(flow_in);
  digitalWrite(motorBIn,LOW);
}

void pumpControl::Dispense_Half_And_Half()
{
  //1/2 A, 1/2 B
  digitalWrite(motorAOut,HIGH);
  delay(flow_half);
  digitalWrite(motorAOut,LOW);
  delay(delaytime);
  digitalWrite(motorAIn,HIGH);
  delay(flow_in);
  digitalWrite(motorAIn,LOW);

  digitalWrite(motorBOut,HIGH);
  delay(flow_half);
  digitalWrite(motorBOut,LOW);
  delay(delaytime);
  digitalWrite(motorBIn,HIGH);
  delay(flow_in);
  digitalWrite(motorBIn,LOW);
}

void pumpControl::Dispense_Nothing()
{
  // No Liquid should be output here, just have a delay so the LCD output is there for a bit
  delay(flow_out);
}
