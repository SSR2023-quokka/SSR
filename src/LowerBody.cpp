#include "LowerBody.hpp"
#include "PS4Controller.h"

Motor motor1{19, 0, 20000, 8};
Motor motor2{17, 1, 20000, 8};
Motor motor3{4, 2, 20000, 8};

void lowerBodySetup() {
    motor1.setup();
    motor2.setup();
    motor3.setup();
}

void lowerBody() {
    double degree = atan2(PS4.LStickY(), PS4.LStickX());

    int i = 0;
    if (PS4.Circle()) int i = 16;
    else int i = 32;
    double vx = cos(degree) * i;
    double vy = sin(degree) * i;
    int v1 = -vx / 2 + vy * sqrt(3) / 2;
    int v2 = -vx / 2 - vy * sqrt(3) / 2;
    int v3 = vx;

    double PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));
    if (PS4LStickDistance > 70) {
        printf("v1 = %d, v2 = %d, v3 = %d\n", v1, v2, v3);
        motor1.motorRun(v1);
        motor2.motorRun(v2);
        motor3.motorRun(v3);
    } else {
        motor1.motorRun(0);
        motor2.motorRun(0);
        motor3.motorRun(0);
    }
}