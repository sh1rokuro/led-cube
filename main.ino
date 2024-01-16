#include "MyDiceLibrary.h"

// Pin des Tasters
int button = 2;

// LED for dice
int bottomLeft = 8;
int middleLeft = 7;
int upperLeft = 6;
int middle = 5;
int bottomRight = 4;
int middleRight = 3;
int upperRight = 12;

int state = 0;
long randNumber;

volatile bool buttonPressed = false;  // Flag für Tastendruck

bool initialAnimationDone = false;

void setup() {
  pinMode(bottomLeft, OUTPUT);
  pinMode(middleLeft, OUTPUT);
  pinMode(upperLeft, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(bottomRight, OUTPUT);
  pinMode(middleRight, OUTPUT);
  pinMode(upperRight, OUTPUT);

  // Button
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), buttonInterrupt, FALLING);  // Interrupt bei fallender Flanke

  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  if (!initialAnimationDone) {
    MyDiceLibrary::simpleAnimation();
    initialAnimationDone = true;
  }

  if (digitalRead(button) == LOW && state == 0) {
    state = 1;
    randNumber = random(1, 7);
    delay(1000);
    Serial.println(randNumber);

    MyDiceLibrary::clear();
    MyDiceLibrary::RollingDiceAnimation();
    MyDiceLibrary::clear();

    if (randNumber == 6) {
      MyDiceLibrary::six();
    } else if (randNumber == 5) {
      MyDiceLibrary::five();
    } else if (randNumber == 4) {
      MyDiceLibrary::four();
    } else if (randNumber == 3) {
      MyDiceLibrary::three();
    } else if (randNumber == 2) {
      MyDiceLibrary::two();
    } else if (randNumber == 1) {
      MyDiceLibrary::one();
    }

    delay(1000);
    MyDiceLibrary::clear();
    state = 0;
  } else if (!buttonPressed) {
    MyDiceLibrary::enterSleepMode();
  } else {
    buttonPressed = false;
  }
}

void buttonInterrupt() {
  buttonPressed = true;
}
