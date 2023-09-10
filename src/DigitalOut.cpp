#include "DigitalOut.hpp"

void DigitalOut::setup() {
    pinMode(pin, OUTPUT);
}

void DigitalOut::write(int value) {
    digitalWrite(pin, value);
}