#pragma once

#include <Arduino.h>
#include "AnalogOut.hpp"

struct Motor {
    AnalogOut dir;

    void setup();
    void motorRun(int p);
};

