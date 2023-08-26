#include "AnalogIn.hpp"

void AnalogIn::setup() {
    pinMode(pin, INPUT);
}

int AnalogIn::read() {
    return analogRead(pin);
}