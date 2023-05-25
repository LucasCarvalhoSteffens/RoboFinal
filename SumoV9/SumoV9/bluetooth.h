#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H

#include <arduino.h>
#include <SoftwareSerial.h>

class Bluetooth {
private:
  // Portas bluetooth
  static const int BLUETOOTH_RX = 12;
  static const int BLUETOOTH_TX = 8;

  SoftwareSerial Serial;

public:
  Bluetooth()
    : Serial(BLUETOOTH_RX, BLUETOOTH_TX) {}

  void clearSerial(void) {
    // Função para limpar a serial do controle
    for (int i = 0; i < 7; i++) {
      Serial.print(";");
    }
    Serial.println();
  }
};

#endif