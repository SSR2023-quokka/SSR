#include "MotorWrapper.hpp"

void MotorWrapper::motorWrapperSetup() {
    motor.setup();
}

void MotorWrapper::motorRun(int power) {
    // motor.motorRun(FT.filterPower(p));　//フィルターパワーいらないかもね
    motor.run(power);
}