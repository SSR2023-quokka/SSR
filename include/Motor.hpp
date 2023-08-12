#include <Arduino.h>
#include <AnalogOut.hpp>
#include <DigitalOut.hpp>

struct Motor {
    int pwm;
    int dir;
    int dirch;

    void setup();
    void motorRun(int v);
};