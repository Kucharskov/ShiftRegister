//Example: Integer in binary (16 bit - two 8 bit registers in serial)
#include <ShiftRegister.h>

//Declare register with pins:
// 2 - Data
// 3 - Clock
// 4 - Latch
ShiftRegister sRegister(2, 3, 4);

//Counter to show
int counter = 0;

void setup() {
  //Set register length to 16
  sRegister.setLength(16);
	
  //Clear the register array
  sRegister.clear();
}

void loop() {
  //Load integer to register
  sRegister.loadData(counter);

  //Update register
  sRegister.update();
  
  //Some delay to see effects
  delay(500);

  //Increase counter
  counter++;
}
