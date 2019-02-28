# D.D.E.D Contributers Guide
## Subsystems
* Menu interface - LCD / Button
* Audio Playback - SD Card / Speaker 
* Bluetooth to App - HC-05
* Motor Signal
## Specifications
Refer to the [Design Spec](https://github.com/Tauheed-Elahee/Drinking-Machine-Arduino-Code/tree/master/Design%20Spec), these include:
* Arduino pin allocation
* Edge cases - Please add to this list!
* State machine to act as a structural guide for the code
## Contributing Styleguide
Please use well-named camalCase variables, for example:
`stateRunGame` instead of: `staterungame`
* Try and limit the use of global variables
* Keep functions as short as possible and easy to read
## Libraries
### EEPROM
* Required for saving non-volatile data on the Arduino
* [Reference](https://www.arduino.cc/en/Reference/EEPROM)
### LiquidCrystal
* Standard libary to help manage LCD states
* Our panel is 4x20 pixel
* [Reference](https://www.arduino.cc/en/Reference/LiquidCrystal)
### Chrono
* Timing library that will be primarily used for user-input timeouts
* [Reference](https://github.com/SofaPirate/Chrono)
### Bluetooth
* Not really a library, but refer to [this](https://create.arduino.cc/projecthub/mayooghgirish/arduino-bluetooth-basic-tutorial-d8b737) tutorial to implement bluetooth using a serial connection
## Issues
* Code filesize may be too large for the Mega
* Edgecases may not be covered in production
* Too much current drawn from the Mega
