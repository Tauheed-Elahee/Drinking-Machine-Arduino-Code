
#include "Arduino.h"
#include "PinLayout.h"


PinLayout::PinLayout()
{
}

void PinLayout::setup()
{
	// LCD
	pinMode(lcdReset, OUTPUT);
	pinMode(lcdEnable, OUTPUT);
	pinMode(lcdDataLine4, OUTPUT);
	pinMode(lcdDataLine5, OUTPUT);
	pinMode(lcdDataLine6, OUTPUT);
	pinMode(lcdDataLine7, OUTPUT);
	// SOUND CONTROL
	pinMode(speakerOutput, OUTPUT);
	// PUMP CONTROL
	pinMode(motorSetAFor, OUTPUT);
	pinMode(motorSetABack, OUTPUT);
	pinMode(motorSetBFor, OUTPUT);
	pinMode(motorSetBBack, OUTPUT);
	// PLINKO
	pinMode(plinkoEnable, INPUT);
	pinMode(plinkoBin1, INPUT);
	pinMode(plinkoBin2, INPUT);
	pinMode(plinkoBin3, INPUT);
	pinMode(plinkoBin4, INPUT);
	pinMode(plinkoBin5, INPUT);
	pinMode(plinkoBin6, INPUT);
	pinMode(plinkoBin7, INPUT);
}
