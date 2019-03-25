// ELEC 3907: Header file to get data from SD card to audio amplifier
// Seth Thompson: 101031310

#ifndef SD_To_Audio_h
#define SD_To_Audio_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define Plinko_Win_Location "Insert filepath here"
#define Plinko_Lose_Location "Insert filepath here"
#define Start_Plinko_Location  "Insert filepath here"
#define End_Plinko_Location  "Insert filepath here"
#define Button_Press_Location  "Insert filepath here"
#define Dispensing_Drink_Location  "Insert filepath here"
#define Drink_Dispensed_Location  "Insert filepath here" 

class SDToAudio
{
  public:
  SDToAudio();

  // The methods
  void setup();
  void Plinko_Win_Sound();
  void Plinko_Lose_Sound();
  void Start_Plinko_Sound();
  void End_Plinko_Sound();
  void Button_Press_Sound();
  void Dispensing_Drink_Sound();
  void Drink_Dispensed_Sound();
  
  // Private Variables
  private:
  
};
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SD.h>
#include "Arduino.h"
#include "SD_To_Audio.h"

// ELEC 3907: cpp file to get data from SD card and output it to audio amplifier
// Seth Thompson: 101031310

SDToAudio::SDToAudio() 
{
  // Note that all defined variables contatin the filepaths to each .wav or .mp3 or .whatever file.
} 

void SDToAudio::setup()
{
  SD.begin();
}

void SDToAudio::Plinko_Win_Sound()
{
  SD.open(Plinko_Win_Location,FILE_READ);
}

void SDToAudio::Plinko_Lose_Sound()
{
  SD.open(Plinko_Lose_Location,FILE_READ);
}

void SDToAudio::Start_Plinko_Sound()
{
  SD.open(Start_Plinko_Location,FILE_READ);
}

void SDToAudio::End_Plinko_Sound()
{
  SD.open(End_Plinko_Location,FILE_READ);
}

void SDToAudio::Button_Press_Sound()
{
  SD.open(Button_Press_Location,FILE_READ);
}

void SDToAudio::Dispensing_Drink_Sound()
{
  SD.open(Dispensing_Drink_Location,FILE_READ);
}

void SDToAudio::Drink_Dispensed_Sound()
{
  SD.open(Drink_Dispensed_Location,FILE_READ);
}
