/*

This file includes all the constants mapped to the Arduino Pins

*/


#ifndef PinLayout_h
#define PinLayout_h

#include "WString.h"
#include "Arduino.h"


// For Bluetooth
#define bluetoothRecieving 18
#define bluetoothTransmitting 19



// For Liquid Crystal Display
#define lcdReset 7 // Reset
#define lcdEnable 6 // Enable
#define lcdDataLine4 5  // Data pin 4
#define lcdDataLine5 4  // Data pin 5
#define lcdDataLine6 3  // Data pin 6
#define lcdDataLine7 2  // Data pin 7



// Speaker
#define speakerOutput 11

// Plinko Bin Detection
#define plinkoEnable 22
#define plinkoBin1 23
#define plinkoBin2 24
#define plinkoBin3 25
#define plinkoBin4 26
#define plinkoBin5 27
#define plinkoBin6 28
#define plinkoBin7 29



// Buttons
#define buttonBack 30
#define buttonDown 31
#define buttonUp 32
#define buttonSelect 33



// Motors

// Motor 1
#define motorSetAFor 40
#define motorSetABack 41

// Motor 2
#define motorSetBFor 42
#define motorSetBBack 43



// SD Card
#define sdCardMISO 50
#define sdCardMOSI 51
#define sdCardCLK 52
#define sdCardCS 53



// Ultra Sonic Sensor
#define echo 0
#define trigger 1


class PinLayout {
	public:
		PinLayout();
		void setup();
	private:
};

#endif
