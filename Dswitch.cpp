#include "Arduino.h"
#include "Dswitch.h"

Dswitch::Dswitch(int pin)
{
  pinMode(pin,OUTPUT);
  _pin = pin;
}

int Dswitch::state()
{
  _buttonValue = digitalRead(_pin);
  _out = (_buttonValue == LOW && _preState == HIGH) ?  HIGH : LOW;
  _preState = _buttonValue;
  return _out;
}
int Dswitch::call(){
  return _preState;
}
