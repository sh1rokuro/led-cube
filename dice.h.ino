#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class dice
{
  public:
    dice(int pin);
    void begin();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void clear();
    void animation();
  private:
  int _button;
  int _bottomLeft;
  int _middleLeft;
  int _upperLeft;
  int _middle;
  int _bottomRight;
  int _middleRight;
  int _upperRight;

};

#endif
