#include "DigitalOut.hpp"

void DigitalOut::setup() {
    pinMode(pin, OUTPUT);
}