/*
  ShiftRegister.h - Library for operating ShiftRegister (eg. 74HC595)
  Created with love by M. Kucharskov (https://kucharskov.pl)
*/
 
#ifndef ShiftRegister_h
#define ShiftRegister_h
 
#include <Arduino.h>

class ShiftRegister {
  private:
    //Pins
    unsigned int latchPin;
    unsigned int dataPin;
    unsigned int clockPin;

    //Additional stuff
    bool autoUpdate;

    //Array things
    unsigned int length;
    bool * regArray;

    //Security check
    bool isCorrectPin(unsigned int pin);

  public:
    ShiftRegister(unsigned int data, unsigned int clk, unsigned int latch);
    ~ShiftRegister();
   
    void update();
    void clear();
    void push(bool bit);
    void invert();
    void reverse();

    void setAutoUpdate(bool mode);
    void setLength(unsigned int newLength);
    unsigned int getLength();
    
    void setPin(unsigned int pin, bool value);
    bool getPin(unsigned int pin);
    void invertPin(unsigned int pin);
    
    void loadData(unsigned int data);
    void loadData(bool * data, unsigned int length);
};

#endif

//Digispark Fix
//void * operator new[] (size_t size) { return malloc(size); }
//void operator delete[] (void * ptr) { free (ptr); }
