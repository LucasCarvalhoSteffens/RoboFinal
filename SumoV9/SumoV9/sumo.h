#ifndef _SUMO_H
#define _SUMO_H
#include <arduino.h>
#include "sharp.h"
#include "motor.h"

int ciclo = 0;

class Sumo {
private:
  static const int DISTANCE = 40;
  static const int COLORFLOOR = 60;
  static const int CURRECT_TIME = 350;
  static const int CURRECT_TIME2 = 300;
  static const int MAXIMUM_SPEED = 255;
  static const int SEARCH_SPEED = 128;
  static const int OPTION_TIME = 50;
  static const int TIME_ATTACK = 500;

  Sharp sharp;
  Motor motor;

  boolean flag = true;
  int option = 0;

  long timeAttackStart, timeAttackNow;

public:
  void sumo(void) {
    motor.motorOption('0', 0, 0);
    long timeStart = millis();

    while (true) {
      ciclo++;

      long timeNow = millis();

      if (testColorFloor()) {
        if (testDistance()) {
          int sharp_front = sharp.getDistance();

          if (ciclo < 10) {
            motor.motorOption('8', SEARCH_SPEED, SEARCH_SPEED);
          }
          if (ciclo > 10) {
            motor.motorOption('6', SEARCH_SPEED, SEARCH_SPEED);
          }
          if (sharp_front < DISTANCE) {
            motor.motorOption('0', 0, 0);
            delay(100);
            if (sharp_front > DISTANCE) {
              motor.motorOption('4', SEARCH_SPEED, SEARCH_SPEED);
              delay(200);
            }
          }
          continue;
        }
      }
    }
  }


private:
  boolean testDistance(void) {
    int sharp_front = sharp.getDistance();
    if (sharp_front < DISTANCE) {
      motor.motorOption('8', MAXIMUM_SPEED, MAXIMUM_SPEED);  // frente 100%
      return false;
    }
    timeAttackStart = 500;
    return true;
  }

  // Sensores do chão
  boolean testColorFloor(void) {
    int qtr_left = analogRead(QTR_LEFT);
    int qtr_right = analogRead(QTR_RIGHT);
    if (qtr_left < COLORFLOOR || qtr_right < COLORFLOOR) {
      if (qtr_left < COLORFLOOR && qtr_right < COLORFLOOR) {
        motor.motorOption('2', MAXIMUM_SPEED, MAXIMUM_SPEED);
        delay(CURRECT_TIME);
        if (flag) {
          flag = false;
          motor.motorOption('4', MAXIMUM_SPEED, MAXIMUM_SPEED);
          delay(CURRECT_TIME2);
        } else {
          flag = true;
          motor.motorOption('6', MAXIMUM_SPEED, MAXIMUM_SPEED);
          delay(CURRECT_TIME2);
        }
      } else if (qtr_left < COLORFLOOR) {
        motor.motorOption('2', MAXIMUM_SPEED, MAXIMUM_SPEED);
        delay(CURRECT_TIME);
        motor.motorOption('4', MAXIMUM_SPEED, MAXIMUM_SPEED);
        delay(CURRECT_TIME2);
        flag = true;
      } else if (qtr_right < COLORFLOOR) {
        motor.motorOption('2', MAXIMUM_SPEED, MAXIMUM_SPEED);
        delay(CURRECT_TIME);
        motor.motorOption('6', MAXIMUM_SPEED, MAXIMUM_SPEED);
        delay(CURRECT_TIME2);
        flag = false;
      }
      return false;
    }
    return true;
  }
};

#endif
