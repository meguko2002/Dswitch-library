#ifndef Dswitch_h
#define Dswitch_h

#include "Arduino.h"

class Dswitch{
  public:
    Dswitch(int pin);
    int state(void);
    int call();
  private:
    int _pin;
    int _out;
    int _preState;
    int _buttonValue;
};

#endif
