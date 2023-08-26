#include <PS4Controller.h>
#include "LowerBody.hpp"
#include "LineTracer.hpp"

LowerBody lowerBody {19, 0, 20000, 8,
                     17, 1, 20000, 8,
                      4, 2, 20000, 8,};

LineTracer lineTracer {39};
LineTracer lineTracerRight {34};
LineTracer lineTracerLeft {35};

int i = 64;
int j = 0;
int k = 0;

void setup() {
    Serial.begin(9600);
    PS4.begin("b8:d6:1a:bc:e6:a2");
    Serial.println("Ready.");
    lowerBody.lowerBodySetup();
    lineTracer.lineTracerSetup();
    lineTracerRight.lineTracerSetup();
    lineTracerLeft.lineTracerSetup();
}

void loop() {
    if (PS4.isConnected()) {
        float degree = atan2(PS4.LStickY(), PS4.LStickX());
        float vx = cos(degree) * i;
        float vy = sin(degree) * i;
        int v1 = -vx / 2 + vy * sqrt(3) / 2;
        int v2 = -vx / 2 - vy * sqrt(3) / 2;
        int v3 = vx;

        float PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));
        if (PS4LStickDistance > 70) {
            Serial.printf("v1 = %4d, v2 = %4d, v3 = %4d\n", v1, v2, v3);
            lowerBody.move(v1, v2, v3);
        } else {
            lowerBody.move(0, 0, 0);
        }

        if (PS4.Circle()) j = 1;    //〇ボタンを押したら自立モード
        while (j == 1) {
            if (lineTracerRight.calcDirFromSensor()) {
                lowerBody.move(50, -59, 8);     //少し右に進む
            } else if (lineTracerLeft.calcDirFromSensor()) {
                lowerBody.move(59, -50, -8);    //少し左に進む
            } else {
                lowerBody.move(55, -55, 0);     //直進
            }
            if (lineTracer.calcDirFromSensor()) k = 1;
            while (k == 1) {
                //右に旋回するなんか
                lowerBody.move(-64, -64, -64);
                delay(1000);    //調整する
                k = 0;
            }
            if (PS4.Cross()) j = 0; //×ボタン押したら自立モード終了
        }
    }
}
 