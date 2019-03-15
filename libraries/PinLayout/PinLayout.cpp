
#include "Arduino.h"
#include "PinLayout.h"

#include "pinLayout.h"



// For Bluetooth
#define bluetoothRecieving 0;
#define bluetoothTransmitting 1;



// For Liquid Crystal Display
#define lcdReset 12; // Reset
#define lcdEnable 11; // Enable
#define lcdDataLine4 5;  // Data pin 4
#define lcdDataLine5 4;  // Data pin 5
#define lcdDataLine6 3;  // Data pin 6
#define lcdDataLine7 2;  // Data pin 7



// Speaker
#define speakerOutput 13;

// Plinko Bin Detection
#define plinkoEnable 22;
#define plinkoBin1 23;
#define plinkoBin2 24;
#define plinkoBin3 25;
#define plinkoBin4 26;
#define plinkoBin5 27;
#define plinkoBin6 28;
#define plinkoBin7 29;



// Buttons
#define buttonBack 30;
#define buttonDown 31;
#define buttonUp 32;
#define buttonSelect 33;



// Motors

// Motor 1
#define motor1TurnRight 40;
#define motor1TurnLeft 41;

// Motor 2
#define motor2TurnRight 42;
#define motor2TurnLeft 43;



// SD Card
#define sdCardMISO 50;
#define sdCardMOSI 51;
#define sdCardCLK 52;
#define sdCardCS 53;



// Ultra Sonic Sensor
#define echo 0;
#define trigger 1;

PinLayout::PinLayout()
{
}

PinLayout::setup()
{
	pinMode(lcdReset, OUTPUT);
	pinMode(lcdEnable, OUTPUT);
	pinMode(lcdDataLine4, OUTPUT);
	pinMode(lcdDataLine5, OUTPUT);
	pinMode(lcdDataLine6, OUTPUT);
	
	pinMode(speakerOutput, OUTPUT);
}
