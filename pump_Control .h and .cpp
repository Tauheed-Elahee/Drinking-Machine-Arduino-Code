// ELEC 3907: Header file to get pumps going in skeleton
// Seth Thompson: 101031310

#ifndef pump_Control_h
#define pump_Control_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

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
  int motoroutA;
  int motorinA;
  int motoroutB;
  int motorinB;
  int flow_out;
  int flow_in;
  int flow_quarter_small;
  int flow_quarter_big;
  int flow_half;
  int delaytime;
};
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ELEC 3907: cpp file to get pumps going in skeleton
// Seth Thompson: 101031310

#include "Arduino.h"
#include "pump_Control.h"

pumpControl::pumpControl(int MotorOutA, int MotorInA, int MotorOutB, int MotorInB) 
{
  motoroutA = MotorOutA;
  motorinA = MotorInA;
  motoroutB = MotorOutB;
  motorinB = MotorInB;
  flow_out = 10000;
  flow_in = 500;
  flow_quarter_small = 2500;
  flow_quarter_big = 7500;
  flow_half = 5000;
  delaytime = 100;
}

void pumpControl::Dispense_Drink_A()
{
  // Add code once flow rate is determined
  digitalWrite(motoroutA,HIGH);
  delay(flow_out);
  digitalWrite(motoroutA,LOW);
  delay(delaytime);
  digitalWrite(motorinA,HIGH);
  delay(flow_in);
  digitalWrite(motorinA,LOW);
}

void pumpControl::Dispense_Drink_B()
{
  // Add code once flow rate is determined
  digitalWrite(motoroutB,HIGH);
  delay(flow_out);
  digitalWrite(motoroutB,LOW);
  delay(delaytime);
  digitalWrite(motorinB,HIGH);
  delay(flow_in);
  digitalWrite(motorinB,LOW);
}

void pumpControl::Dispense_1_To_4()
{
  //1/4 A, 3/4 B
  digitalWrite(motoroutA,HIGH);
  delay(flow_quarter_small);
  digitalWrite(motoroutA,LOW);
  delay(delaytime);
  digitalWrite(motorinA,HIGH);
  delay(flow_in);
  digitalWrite(motorinA,LOW);

  digitalWrite(motoroutB,HIGH);
  delay(flow_quarter_big);
  digitalWrite(motoroutB,LOW);
  delay(delaytime);
  digitalWrite(motorinB,HIGH);
  delay(flow_in);
  digitalWrite(motorinB,LOW);
}

void pumpControl::Dispense_4_To_1()
{
  //3/4 A, 1/4 B
  digitalWrite(motoroutA,HIGH);
  delay(flow_quarter_big);
  digitalWrite(motoroutA,LOW);
  delay(delaytime);
  digitalWrite(motorinA,HIGH);
  delay(flow_in);
  digitalWrite(motorinA,LOW);

  digitalWrite(motoroutB,HIGH);
  delay(flow_quarter_small);
  digitalWrite(motoroutB,LOW);
  delay(delaytime);
  digitalWrite(motorinB,HIGH);
  delay(flow_in);
  digitalWrite(motorinB,LOW);
}

void pumpControl::Dispense_Half_And_Half()
{
  //1/2 A, 1/2 B
  digitalWrite(motoroutA,HIGH);
  delay(flow_half);
  digitalWrite(motoroutA,LOW);
  delay(delaytime);
  digitalWrite(motorinA,HIGH);
  delay(flow_in);
  digitalWrite(motorinA,LOW);

  digitalWrite(motoroutB,HIGH);
  delay(flow_half);
  digitalWrite(motoroutB,LOW);
  delay(delaytime);
  digitalWrite(motorinB,HIGH);
  delay(flow_in);
  digitalWrite(motorinB,LOW);
}

void pumpControl::Dispense_Nothing()
{
  // No Liquid should be output here, just have a delay so the LCD output is there for a bit
  delay(flow_out);
}
