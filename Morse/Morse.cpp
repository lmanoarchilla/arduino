/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
 
#include "Arduino.h"
#include "Morse.h"
 
Morse::Morse(int pin, int button)
{
  pinMode(pin, OUTPUT);
  pinMode(button,INPUT);
  _pin = pin;
  _button =button;
}
 
void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}
 
void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}
int Morse::button()
{
  float val;
  
  val = pulseIn(_button,HIGH,100000000);
                  
    if((val/1000000)>0.25){      
      return 1 ;
      }else{        
        return 2;
        }
  
}