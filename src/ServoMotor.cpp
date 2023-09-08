#include "ServoMotor.hpp"

Servo servo;

void ServoMotor::setup() {
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    servo.setPeriodHertz(50);
    servo.attach(pin, 500, 2400);
}

void ServoMotor::servoWrite(int p) {
    servo.write(p);
}