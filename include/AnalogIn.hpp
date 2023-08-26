#pragma once

#include <Arduino.h>

struct AnalogIn {
    int pin;

    void setup();
    int read();
};