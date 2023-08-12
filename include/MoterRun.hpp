#pragma once

#include <Arduino.h>
#include <AnalogOut.hpp>
#include <DigitalOut.hpp>

    int dir1;
    int pwm1;
    int dirch1 = 0;
    int dir2; 
    int pwm2;
    int dirch2 = 1;
    int dir3 = 4;
    int pwm3 = 0;
    int dirch3 = 2;

struct MoterRun {
    void setup();
    void moterRun(int num, int v);
};