#inculde <PinLayout.h>
#include <LCD.h>

//Global Variables
LCD lcd;

void setup() {
  // put your setup code here, to run once:
  pinLayout pin;
  pin.setupPins();
  LCD lcd;

}

void loop() {
  // put your main code here, to run repeatedly:
    lcd.printHomeScreen();
}
