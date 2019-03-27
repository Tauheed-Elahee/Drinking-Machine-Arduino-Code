#include "Arduino.h"
#include "TimeControl.h"

TimeControl::TimeControl()
{
	counter = 60;
	refTime = 0ul;
}

bool TimeControl::oneSecondTick (){
  return (millis() - refTime) > 1000;
}
int TimeControl::getCounter() {
  return counter;
}
void TimeControl::resetCounter() {
  counter = 60;
}
void TimeControl::updateRefTime(unsigned long int refTimeIn) {
  refTime = refTimeIn;
}
void TimeControl::decrementCounter() {
  counter--;
}