/*

This file includes all the constants mapped to the Arduino Pins

 */


#ifndef pinLayout_h
#define pinLayout_h

#include "pinLayout.h"



// For Bluetooth
#define bluetoothRecieving = 0;
#define bluetoothTransmitting = 1;



// For Liquid Crystal Display
#define rs = 12; // Reset
#define en = 11; // Enable
#define d4 = 5;  // Data pin 4
#define d5 = 4;  // Data pin 5
#define d6 = 3;  // Data pin 6
#define d7 = 2;  // Data pin 7



// Speaker
#define speakerOut = 13;

// Plinko Bin Detection
#define plinkoBin1 = 22;
#define plinkoBin2 = 23;
#define plinkoBin3 = 24;
#define plinkoBin4 = 25;
#define plinkoBin5 = 26;
#define plinkoBin6 = 27;
#define plinkoBin7 = 28;



// Buttons
#define buttonBack = 30;
#define buttonDown = 31;
#define buttonUp = 32;
#define buttonSelect = 33;



// Motors

// Motor 1
#define motor1TurnRight = 40;
#define motor1TurnLeft = 41;

// Motor 2
#define motor2TurnRight = 42;
#define motor2TurnLeft = 43;



// SD Card
#define miso = 50;
#define mosi = 51;
#define clk = 52;
#define cs = 53;



// Ultra Sonic Sensor
#define echo = 0;
#define trigger = 1;



// Define the pinLayout class

class pinLayout {
	public:
	pinLayout();
	setup();
	
	private:
}

// Body of the pinLayout class

void pinLayout::pinLayout()
{
}

void pinLayout::setup()
{
	
	// unknown for bluetooth
	
	pinMode(rs, OUTPUT);
	pinMode(en, OUTPUT);
	pinMode(d4, OUTPUT);
	pinMode(d5, OUTPUT);
	pinMode(d6, OUTPUT);
	pinMode(d7, OUTPUT);
	
	pinMode(speakerOut, OUTPUT);
	
	pinMode(plinkoBin1, INPUT);
	pinMode(plinkoBin2, INPUT);
	pinMode(plinkoBin3, INPUT);
	pinMode(plinkoBin4, INPUT);
	pinMode(plinkoBin5, INPUT);
	pinMode(plinkoBin6, INPUT);
	pinMode(plinkoBin7, INPUT);
	
	pinMode(buttonBack, INPUT);
	pinMode(buttonDown, INPUT);
	pinMode(buttonUp, INPUT);
	pinMode(buttonSelect, INPUT);
	
	pinMode(motor1TurnLeft, OUTPUT);
	pinMode(motor1TurnRight, OUTPUT);
	pinMode(motor2TurnLeft, OUTPUT);
	pinMode(motor2TurnRight, OUTPUT);
	
	// SD card pins are set by the SD header file
	
}

#endif
