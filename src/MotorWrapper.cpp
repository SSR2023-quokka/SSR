#include "MotorWrapper.hpp"

void MotorWrapper::motorWrapperSetup() {
    motor.setup();
}

int MotorWrapper::filterPower(int p) {
    //ここでパワーが急激に変化しないようにする
    return p;
}

void MotorWrapper::motorRun(int p) {
    motor.motorRun(filterPower(p));
}