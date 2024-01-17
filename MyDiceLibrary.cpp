#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include "Arduino.h"
#include "MyDiceLibrary.h"


int MyDiceLibrary::bottomLeft = 8;
int MyDiceLibrary::middleLeft = 7;
int MyDiceLibrary::upperLeft = 6;
int MyDiceLibrary::middle = 5;
int MyDiceLibrary::bottomRight = 4;
int MyDiceLibrary::middleRight = 3;
int MyDiceLibrary::upperRight = 12;


void MyDiceLibrary::enterSleepMode() {
  Serial.println("Entering Sleep Mode");
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
  sleep_disable();
}

void MyDiceLibrary::setupWatchdog(int time) {
  cli();  // Deaktiviere Interrupts während der Konfiguration
  wdt_reset();  // Watchdog-Timer zurücksetzen
  MCUSR &= ~(1 << WDRF);  // Watchdog-Reset-Flag löschen
  WDTCSR |= (1 << WDCE) | (1 << WDE);  // Zugriff auf die Watchdog-Einstellungen ermöglichen
  WDTCSR = (1 << WDIE) | getWDTControl(time);  // Interrupt-Modus und konfigurierten Timer
  sei();  // Interrupts aktivieren
}

byte MyDiceLibrary::getWDTControl(int time) {
  byte wdtControl;

  if (time <= 16) {
    wdtControl = (1 << WDIE) | (1 << WDP3) | (1 << WDP0);  // Interrupt-Modus und 16 Sekunden Timer
  } else if (time <= 32) {
    wdtControl = (1 << WDIE) | (1 << WDP3) | (1 << WDP1);  // Interrupt-Modus und 32 Sekunden Timer
  } else if (time <= 64) {
    wdtControl = (1 << WDIE) | (1 << WDP3) | (1 << WDP2);  // Interrupt-Modus und 64 Sekunden Timer
  } else if (time <= 128) {
    wdtControl = (1 << WDIE) | (1 << WDP3) | (1 << WDP2) | (1 << WDP0);  // Interrupt-Modus und 128 Sekunden Timer
  } else {
    // Standard ist 8 Sekunden
    wdtControl = (1 << WDIE) | (1 << WDP3) | (1 << WDP0);  // Interrupt-Modus und 8 Sekunden Timer
  }

  return wdtControl;
}

void MyDiceLibrary::clear() {
  digitalWrite(bottomLeft, LOW);
  digitalWrite(middleLeft, LOW);
  digitalWrite(upperLeft, LOW);
  digitalWrite(middle, LOW);
  digitalWrite(bottomRight, LOW);
  digitalWrite(middleRight, LOW);
  digitalWrite(upperRight, LOW);
}

void MyDiceLibrary::one() {
  digitalWrite(middle, HIGH);
}

void MyDiceLibrary::two() {
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(upperRight, HIGH);
}

void MyDiceLibrary::three() {
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(upperRight, HIGH);
}

void MyDiceLibrary::four() {
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(upperRight, HIGH);
}

void MyDiceLibrary::five() {
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(upperRight, HIGH);
}

void MyDiceLibrary::six() {
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middleLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middleRight, HIGH);
  digitalWrite(upperRight, HIGH);
}

void MyDiceLibrary::simpleAnimation() {
  digitalWrite(bottomLeft, HIGH);
  delay(200);
  digitalWrite(bottomLeft, LOW);

  digitalWrite(middleLeft, HIGH);
  delay(200);
  digitalWrite(middleLeft, LOW);

  digitalWrite(upperLeft, HIGH);
  delay(200);
  digitalWrite(upperLeft, LOW);

  digitalWrite(middle, HIGH);
  delay(200);
  digitalWrite(middle, LOW);

  digitalWrite(bottomRight, HIGH);
  delay(200);
  digitalWrite(bottomRight, LOW);

  digitalWrite(middleRight, HIGH);
  delay(200);
  digitalWrite(middleRight, LOW);

  digitalWrite(upperRight, HIGH);
  delay(200);
  digitalWrite(upperRight, LOW);

  digitalWrite(middleRight, HIGH);
  delay(200);
  digitalWrite(middleRight, LOW);

  digitalWrite(bottomRight, HIGH);
  delay(200);
  digitalWrite(bottomRight, LOW);

  digitalWrite(middle, HIGH);
  delay(200);
  digitalWrite(middle, LOW);

  digitalWrite(upperLeft, HIGH);
  delay(200);
  digitalWrite(upperLeft, LOW);

  digitalWrite(middleLeft, HIGH);
  delay(200);
  digitalWrite(middleLeft, LOW);

  digitalWrite(bottomLeft, HIGH);
  delay(200);
  digitalWrite(bottomLeft, LOW);
  delay(200);
}

void MyDiceLibrary::RollingDiceAnimation() {
  for (int repeat = 0; repeat < 3; ++repeat) {
    digitalWrite(bottomLeft, HIGH);
    digitalWrite(bottomRight, HIGH);
    delay(200);
    clear();

    digitalWrite(middleLeft, HIGH);
    digitalWrite(middleRight, HIGH);
    delay(200);
    clear();

    digitalWrite(upperLeft, HIGH);
    digitalWrite(upperRight, HIGH);
    delay(200);
    clear();

    //Wiederholung soll schneller werden
    delay(200 * (3 - repeat));
  }
}