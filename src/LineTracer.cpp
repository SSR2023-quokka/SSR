#include "LineTracer.hpp"

void LineTracer::lineTracerSetup() {
    pin.setup();
}

bool LineTracer::calcDirFromSensor() {
        if (pin.read() < 800) {     //白
            return true;
        } else {    //黒
             return false;
        }
}
