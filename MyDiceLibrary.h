#ifndef MyDiceLibrary_h
#define MyDiceLibrary_h

#include "Arduino.h"

class MyDiceLibrary {
public:
  static int bottomLeft;
  static int middleLeft;
  static int upperLeft;
  static int middle;
  static int bottomRight;
  static int middleRight;
  static int upperRight;

  static bool initialAnimationDone;

  static void enterSleepMode();
  static void setupWatchdog(int time);


  static void clear();
  static void one();
  static void two();
  static void three();
  static void four();
  static void five();
  static void six();
  static void simpleAnimation();
  static void RollingDiceAnimation();
  
private:
  static byte getWDTControl(int time);
};

#endif
