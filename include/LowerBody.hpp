#pragma once

#include <Arduino.h>
#include <PS4Controller.h>
#include "MotorWrapper.hpp"

struct LowerBody {
    MotorWrapper motor1, motor2, motor3;
    
    void lowerBodySetup();
    void move(int v1, int v2, int v3);
};
