#include "MotorWrapper.hpp"

void MotorWrapper::motorWrapperSetup() {
    motor.setup();
}

void MotorWrapper::motorRun(int p) {
    // motor.motorRun(FT.filterPower(p));　//フィルターパワーいらないかもね
    motor.run(p);
}