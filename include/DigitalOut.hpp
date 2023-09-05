#pragma once

#include <Arduino.h>

struct DigitalOut {
    int pin;

    void setup();
    void write(int i);
};