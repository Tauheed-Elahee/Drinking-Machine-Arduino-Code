#include "Arduino.h"
#include "PumpControl.h"
#include "PinLayout.h"

PumpControl::PumpControl() 
{
  PinLayout pinLayout;
  pinLayout.setup();
}

// 4 UNITS MAKE ONE TOTAL DRINK

void PumpControl::primeA() {
  digitalWrite(motorSetAFor, HIGH);
	delay(FLOW_TOTAL_LENGTH_TIME_A);
	digitalWrite(motorSetAFor, LOW);
}
void PumpControl::primeB() {
  digitalWrite(motorSetBFor, HIGH);
	delay(FLOW_TOTAL_LENGTH_TIME_B);
	digitalWrite(motorSetBFor, LOW);
}
void PumpControl::clearA() {
  digitalWrite(motorSetABack, HIGH);
	delay(FLOW_TOTAL_LENGTH_TIME_A);
	digitalWrite(motorSetABack, LOW);
}
void PumpControl::clearB() {
  digitalWrite(motorSetBBack, HIGH);
	delay(FLOW_TOTAL_LENGTH_TIME_B);
	digitalWrite(motorSetBBack, LOW);
}
void PumpControl::dispense (int unitsOfA, int unitsOfB) {
	if (unitsOfA != 0) {
		digitalWrite(motorSetAFor, HIGH);
		delay(UNIT_OF_LIQUID_A * unitsOfA);
		digitalWrite(motorSetAFor, LOW);
		// can reverse here to clear pipe
	}
	if (unitsOfB != 0) {
		digitalWrite(motorSetBFor, HIGH);
		delay(UNIT_OF_LIQUID_B * unitsOfB);
		digitalWrite(motorSetBFor, LOW);
		// can reverse here to clear pipe
	}
}