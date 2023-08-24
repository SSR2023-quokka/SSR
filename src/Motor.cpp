#include "Motor.hpp"

void Motor::setup() {
    dir.setup();
}

void Motor::motorRun(int p) {
    int i = 128 - p;
    dir.write(i);
}