#pragma once

#include <Arduino.h>
#include <PS4Controller.h>
#include "ESP32Servo.h"

struct ServoMotor{
    int pin;

    void setup();
    void servoWrite(int p);
};