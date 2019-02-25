//Example: Blinking pins
#include <ShiftRegister.h>

//Declare register with pins:
// 2 - Data
// 3 - Clock
// 4 - Latch
ShiftRegister sRegister(2, 3, 4);

void setup() {
  //Turn on autoupdate
  sRegister.setAutoUpdate(true);
  
  //Clear the register array
  sRegister.clear();
}

void loop() {
  //For every pin in register
  for(int i = 0; i < sRegister.getLength(); i++) {
    //Three times
    for(int times = 0; times <= 3; times++) {
      //Turn on pin
      sRegister.setPin(i, true);
      delay(50);
      
      //Turn off pin
      sRegister.setPin(i, false);
      //Or: sRegister.invertPin(i);
      delay(50);
    }
  }
}
