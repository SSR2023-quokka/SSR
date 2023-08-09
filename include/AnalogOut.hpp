#pragma once

#include <Arduino.h>

struct AnalogOut {
    int pin;
    int ch;
    int freq;
    int resol_bits;

    void setup();
};