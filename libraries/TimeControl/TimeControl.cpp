#include "Arduino.h"
#include "TimeControl.h"

TimeControl::TimeControl()
{
	counter = TIMEOUT_CONST;
	refTime = 0ul;
}

bool TimeControl::oneSecondTick (){
  return (millis() - refTime) > 1000;
}
int TimeControl::getCounter() {
  return counter;
}
void TimeControl::resetCounter() {
  counter = TIMEOUT_CONST;
}
void TimeControl::updateRefTime(unsigned long int refTimeIn) {
  refTime = refTimeIn;
}
void TimeControl::decrementCounter() {
  counter--;
}