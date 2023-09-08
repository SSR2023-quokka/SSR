#include "Motor.hpp"

void Motor::setup() {
    dir.setup();
    pwm.setup();
    pwm.write(HIGH);
}

void Motor::run(int p) {
    int i = 128 - p;
    dir.write(i);
}