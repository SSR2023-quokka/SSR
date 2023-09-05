#pragma once

#include <Arduino.h>
#include "AnalogOut.hpp"
#include "DigitalOut.hpp"

struct Motor {
    AnalogOut dir;
    DigitalOut pwm;

    void setup();
    void motorRun(int p);
};

