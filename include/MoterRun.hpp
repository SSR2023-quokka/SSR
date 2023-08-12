#pragma once

#include <Arduino.h>
#include <AnalogOut.hpp>
#include <DigitalOut.hpp>


struct MoterRun {
    void setup();
    void moterRun(int num, int v);
};