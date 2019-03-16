/*

This file includes all the constants mapped to the Arduino Pins

 */


#ifndef pinLayout_h
#define pinLayout_h

#include "pinLayout.h"



// For Bluetooth
#define bluetoothRecieving 0;
#define bluetoothTransmitting 1;



// For Liquid Crystal Display
#define rs 12; // Reset
#define en 11; // Enable
#define d4 5;  // Data pin 4
#define d5 4;  // Data pin 5
#define d6 3;  // Data pin 6
#define d7 2;  // Data pin 7



// Speaker
#define speakerOut 13;

// Plinko Bin Detection
#define plinkoBin1 22;
#define plinkoBin2 23;
#define plinkoBin3 24;
#define plinkoBin4 25;
#define plinkoBin5 26;
#define plinkoBin6 27;
#define plinkoBin7 28;



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
#define miso 50;
#define mosi 51;
#define clk 52;
#define cs 53;



// Ultra Sonic Sensor
#define echo 0;
#define trigger 1;

#endif


// Testing.
