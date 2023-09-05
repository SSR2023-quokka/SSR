#include "DigitalOut.hpp"

void DigitalOut::setup() {
    pinMode(pin, OUTPUT);
}

void DigitalOut::write(int i) {
    digitalWrite(pin, i);
}