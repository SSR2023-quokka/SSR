#include "AnalogIn.hpp"

void AnalogIn::setup() {
    pinMode(pin, INPUT);
}

void AnalogIn::read() {
    analogRead(pin);
}