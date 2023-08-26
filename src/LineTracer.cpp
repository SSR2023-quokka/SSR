#include "LineTracer.hpp"

float LineTracer::calcDirFromSensor() {
        //ここらへんが分からない
        if (pin.read() > 800) {
            return 1.0f;
        } else {
            return -1.0f;
        }
}
