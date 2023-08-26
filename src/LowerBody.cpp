#include "LowerBody.hpp"

void LowerBody::lowerBodySetup() {
    motor1.motorWrapperSetup();
    motor2.motorWrapperSetup();
    motor3.motorWrapperSetup();
}

void LowerBody::move(int v1, int v2, int v3) {
    motor1.motorRun(v1);
    motor2.motorRun(v2);
    motor3.motorRun(v3);
}