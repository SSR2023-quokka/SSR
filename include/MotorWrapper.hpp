#pragma once

#include <Arduino.h>
#include "Motor.hpp"
#include "FilterPower.hpp"

struct MotorWrapper {
    Motor motor;
    FilterPower FT;

    void motorWrapperSetup();
    void motorRun(int power);
};
