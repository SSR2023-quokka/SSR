#include "Motor.hpp"

void Motor::setup() {
    dir.setup();
}

void Motor::motorRun(int v) {
    int i = 128 - v;
    dir.write(i);   
}