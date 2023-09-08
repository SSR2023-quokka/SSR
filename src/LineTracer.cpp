#include "LineTracer.hpp"

void LineTracer::lineTracerSetup() {
    pin.setup();
}

bool LineTracer::detectLine() {
        if (pin.read() < 800) {     //白
            return true;
        } else {    //白以外
             return false;
        }
}
