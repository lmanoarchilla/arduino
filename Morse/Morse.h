/*
  Morse.h - Library for flashing Morse code 
      and send to serial the signal created with a button.
      
  Created by Laura Maño Archilla, september 25, 2018.
  Based in  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
 
*/
#ifndef Morse_h
#define Morse_h
 
#include "Arduino.h"
 
class Morse
{
  public:
    Morse(int pin, int button);
    void dot();
    void dash();
    int button();
  private:
    int _pin;
    int _button;
};
 
#endif