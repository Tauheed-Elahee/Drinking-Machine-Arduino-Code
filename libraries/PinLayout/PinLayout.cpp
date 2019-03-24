
#include "WCharacter.h"
#include "WString.h"
#include "Arduino.h"

#include "PinLayout.h"


PinLayout::PinLayout()
{
}

void PinLayout::setup()
{
	pinMode(lcdReset, OUTPUT);
	pinMode(lcdEnable, OUTPUT);
	pinMode(lcdDataLine4, OUTPUT);
	pinMode(lcdDataLine5, OUTPUT);
	pinMode(lcdDataLine6, OUTPUT);
	
	pinMode(speakerOutput, OUTPUT);
}
