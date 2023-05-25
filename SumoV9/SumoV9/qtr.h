#ifndef _QTR_H
#define _QTR_H

#include <arduino.h>
#include "bluetooth.h"

// Portas sensor QTR
#define QTR_LEFT A2
#define QTR_RIGHT A1
class Qtr {
private:


  Bluetooth bluetooth;

public:
  void readFloor(void) {
    // Função para leitura do chão
    bluetooth.clearSerial();
    Serial.print("QTR_LEFT: ");
    Serial.print(analogRead(QTR_LEFT));
    Serial.print("; ");
    Serial.print("QTR_RIGHT: ");
    Serial.print(analogRead(QTR_RIGHT));
    Serial.print("; ");
  }
};

#endif