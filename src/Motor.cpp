#include "Motor.hpp"

void Motor::setup() {
    AnalogOut analogMotor{dir, dirch, 20000, 8};
    DigitalOut digitalMotor{pwm};
    analogMotor.setup();
    digitalMotor.setup();
}

void Motor::motorRun(int v) {
    int i = 128 - v;
    digitalWrite(pwm, HIGH);
    ledcWrite(dirch, i);
}