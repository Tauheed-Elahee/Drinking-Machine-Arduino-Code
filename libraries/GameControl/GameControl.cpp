#include "Arduino.h"
#include "gameControl.h"
#include "PinLayout.h"

GameControl::GameControl()
{
  PinLayout pinLayout;
  pinLayout.setup();
}

bool GameControl::checkPlinko() {
	for (int i = 0; i < 7; i++) {
	  if(digitalRead(plinkoBin1 + i)) {
      delay(5);
      if(digitalRead(plinkoBin1 + i)) {
        readAsLowBin = i;
        return true;
      }
    }
  }
  return false;
}
void GameControl::returnGameResult(int &a, int &b) {
  switch (readAsLowBin) {
    case 0: a=4;b=0;break;
    case 1: a=3;b=1;break;
    case 2: a=0;b=0;break;
    case 3: a=2;b=2;break;
    case 4: a=1;b=3;break;
    case 5: a=0;b=0;break;
    case 6: a=0;b=4;break;
    default: a=0;b=0;break;
  }
}
int GameControl::getBin() {
  return readAsLowBin;
}
void GameControl::enable() {
  digitalWrite(plinkoEnable, HIGH);
}
void GameControl::disable(){
  digitalWrite(plinkoEnable, LOW);
}