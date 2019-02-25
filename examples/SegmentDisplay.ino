//Example: Register to control 8 display
#include <ShiftRegister.h>

//Declare register with pins:
// 2 - Data
// 3 - Clock
// 4 - Latch
ShiftRegister sRegister(2, 3, 4);

//Array of byte numbers to turn correct number
//Display pin connections
// ===5===
//|0|   |4|
// ===6===
//|1|   |3|
// ===2===  |7| (dot)
byte byte_numbers[10] = {
  0b00111111,
  0b00011000,
  0b01110110,
  0b01111100,
  0b01011001,
  0b01101101,
  0b01101111,
  0b00111000,
  0b01111111,
  0b01111001
};

//Counter to show
int counter = 0;

void setup() {
  //Turn on autoupdate
  sRegister.setAutoUpdate(true);
  
  //Clear the register array
  sRegister.clear();
}

void loop() {
  //Load integer to register
  sRegister.loadData(byte_numbers[counter]);

  //Increase counter
  counter++;
  counter %= 10;
  
  //Some delay to see effects
  delay(500);
}
