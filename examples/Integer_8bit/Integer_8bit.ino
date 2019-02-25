//Example: Integer in binary (8 bit)
#include <ShiftRegister.h>

//Declare register with pins:
// 2 - Data
// 3 - Clock
// 4 - Latch
ShiftRegister sRegister(2, 3, 4);

//Counter to show
int counter = 0;

void setup() {
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
