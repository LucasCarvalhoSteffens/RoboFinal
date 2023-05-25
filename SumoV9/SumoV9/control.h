// Não é necessário incluir "bluetooth.h" aqui, pois é incluído posteriormente

#ifndef _CONTROL_H
#define _CONTROL_H

#include <arduino.h>
#include "qtr.h"
#include "motor.h"
#include "sharp.h"
#include "sumo.h"

class Control {
private:
  Qtr qtr;
  Motor motor;
  Sharp sharp;
  Sumo sumo;

public:
  void setup() {
    // Coloque seu código de configuração aqui, para ser executado apenas uma vez:
    Serial.begin(9600);
  }

  void loop() {
    sumo.sumo();
  }

  void advancedOption(char option) {
    // Função para controlar as opções avançadas
    switch (option) {
      case '0':
      case '2':
      case '4':
      case '6':
      case '8':
        motor.motorOption(option, 255, 255);
        break;

      case 'b':
        qtr.readFloor();
        break;
      case 'c':
        sharp.getDistance();
        break;
      case 'x':
        sumo.sumo();
        break;
    }
  }
};

#endif