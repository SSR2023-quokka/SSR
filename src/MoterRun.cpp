#include <MoterRun.hpp>

    int dir1 = 0;
    int pwm1 = 0;
    int dirch1 = 0;
    int dir2 = 1; 
    int pwm2 = 1;
    int dirch2 = 1;
    int dir3 = 2;
    int pwm3 = 2;
    int dirch3 = 2;

AnalogOut analogMoter1{dir1, dirch1, 20000, 8};
AnalogOut analogMoter2{dir2, dirch2, 20000, 8};
AnalogOut analogMoter3{dir3, dirch3, 20000, 8};
DigitalOut digitalMoter1{pwm1};
DigitalOut digitalMoter2{pwm2};
DigitalOut digitalMoter3{pwm3};

void MoterRun::setup() {
    analogMoter1.setup();
    analogMoter2.setup();
    analogMoter3.setup();
    digitalMoter1.setup();
    digitalMoter2.setup();
    digitalMoter3.setup();
}

void MoterRun::moterRun(int num, int v) {
    int i = 128 - v;
    if (num = 1) {
        digitalWrite(pwm1, HIGH);
        ledcWrite(dirch1, i);
    } else if (num = 2) {
        digitalWrite(pwm2, HIGH);
        ledcWrite(dirch2, i);
    } else if (num = 3) {
        digitalWrite(pwm3, HIGH);
        ledcWrite(dirch3, i);
    }
}