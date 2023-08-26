#pragma once

#include <Arduino.h>
#include "Motor.hpp"

struct MotorWrapper {
    Motor motor;

    void motorWrapperSetup();
    int filterPower(int p);
    void motorRun(int p);
};
