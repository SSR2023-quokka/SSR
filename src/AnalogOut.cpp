#include <AnalogOut.hpp>

void AnalogOut::setup() {
    pinMode(pin, OUTPUT);
    ledcSetup(ch, freq, resol_bits);
    ledcAttachPin(pin, ch);
}