#ifndef _SHARP_H
#define _SHARP_H

#include <SharpIR.h>
#include <arduino.h>
#include "bluetooth.h"

class Sharp {
private:
  // Portas dos sharps
  static const int SHARP_FRONT = A3;
  static const int MODEL = 1080;

  SharpIR sharpFront;

  Bluetooth bluetooth;

public:
  Sharp()
    : sharpFront(SHARP_FRONT, MODEL) {}

  int getDistance() {
    return sharpFront.distance();
  }
};

#endif