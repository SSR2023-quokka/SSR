#include <AnalogOut.hpp>

void AnalogOut::setup() {
    pinMode(pin, OUTPUT);
    ledcSetup(pin, freq, resol_bits);
    ledcAttachPin(pin, ch);
}