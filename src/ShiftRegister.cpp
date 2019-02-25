#include <Arduino.h>
#include "ShiftRegister.h"

bool ShiftRegister::isCorrectPin(unsigned int pin) {
  return pin < length;
}

ShiftRegister::ShiftRegister(unsigned int data, unsigned int clk, unsigned int latch) :
  dataPin(data),
  clockPin(clk),
  latchPin(latch),
  autoUpdate(false),
  length(8) {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  regArray = (bool *) calloc(length, sizeof(bool));
};

ShiftRegister::~ShiftRegister() {
  free(regArray);
}

void ShiftRegister::update() {
  digitalWrite(latchPin, false); 
  for(int i = length-1; i >= 0; i--){
    digitalWrite(clockPin, false);
    digitalWrite(dataPin, regArray[i]);
    digitalWrite(clockPin, true); 
  }
  digitalWrite(latchPin, true);
}

void ShiftRegister::clear() {
  for(int i = 0; i < length; i++) {
    regArray[i] = false;
  }

  if(autoUpdate) update();
}

void ShiftRegister::push(bool bit) {
  for(int i = length-1; i > 0; i--) {
    regArray[i] = regArray[i - 1];
  }
  regArray[0] = bit;
  
  if(autoUpdate) update();
}

void ShiftRegister::invert() {
  for(int i = 0; i < length; i++) {
    regArray[i] = !regArray[i];
  }
  
  if(autoUpdate) update();
}

void ShiftRegister::reverse() {
  for(int i = 0; i < length/2; i++) {
    bool temp = regArray[i];
    regArray[i] = regArray[length - 1 - i];
    regArray[length - 1 - i] = temp;
  }
  
  if(autoUpdate) update();
}

void ShiftRegister::setAutoUpdate(bool mode) {
  autoUpdate = mode;
}

void ShiftRegister::setLength(unsigned int newLength) {
  if(newLength <= 0 || newLength == length) return;
  
  free(regArray);
  
  length = newLength;
  regArray = (bool *) calloc(length, sizeof(bool));
  
  if(autoUpdate) update();
}

unsigned int ShiftRegister::getLength() {
  return length;
}

void ShiftRegister::setPin(unsigned int pin, bool value) {
  if(!isCorrectPin(pin)) return;
   
  regArray[pin] = value;
  
  if(autoUpdate) update();
}

bool ShiftRegister::getPin(unsigned int pin) {
  if(!isCorrectPin(pin)) return false;
  
  return regArray[pin];
}

void ShiftRegister::invertPin(unsigned int pin) {
  if(!isCorrectPin(pin)) return; 
     
  regArray[pin] = !regArray[pin];
  
  if(autoUpdate) update();
}

void ShiftRegister::loadData(unsigned int data) {
  for (int i = 0; i < length; i++) {
    regArray[i] = ((data >> i) & 1) == 1;
  }
  
  if(autoUpdate) update();
}

void ShiftRegister::loadData(bool * data, unsigned int length) {
  int size = min(length, this->length);
  for(int i = 0; i < size; i++) {
    regArray[size - 1 - i] = data[i];
  }
  
  if(autoUpdate) update();
}
