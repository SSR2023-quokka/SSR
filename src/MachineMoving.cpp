#include "MachineMoving.hpp"

LowerBody lowerBody{    //pwmch を0,1,2にするとうまく動かない...
    19,2,20000,8,18,0,
    17,3,20000,8,16,0,
     4,4,20000,8, 0,0,
};

LineTracer lineTracer{39};
LineTracer lineTracerRight{34};
LineTracer lineTracerLeft{35};

int i = 96; // 0 <= i <= 128
bool j = false;
bool k = false;
float v_theta = 0;

void machineMovingSetup() {
    lowerBody.lowerBodySetup();
    lineTracer.lineTracerSetup();
    lineTracerRight.lineTracerSetup();
    lineTracerLeft.lineTracerSetup();
}

void machineMoving() {
    float degree = atan2(PS4.LStickY(), PS4.LStickX());
    float v_x = cos(degree) * i;
    float v_y = sin(degree) * i;
    int v1 = -v_x / 2 + v_y * sqrt(3) / 2 + v_theta;
    int v2 = -v_x / 2 - v_y * sqrt(3) / 2 + v_theta;
    int v3 = v_x + v_theta;

    if (PS4.R1() && PS4.L1()) v_theta = 0;
    else if (PS4.L1()) v_theta = 32;
    else if (PS4.R1()) v_theta = -32;
    else v_theta = 0;

    float PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));
    if (PS4LStickDistance > 70) {
        Serial.printf("v1 = %4d, v2 = %4d, v3 = %4d\n", v1, v2, v3);
        lowerBody.move(v1, v2, v3);
    } else {   
        lowerBody.move(v_theta, v_theta, v_theta);
    }

    if (PS4.Circle()) j = true; // 〇ボタンを押したら自立モード
    while (j == true) {
        if (lineTracerRight.detectLine()) {
            lowerBody.move(50, -59, 8); // 少し右に進む
        } else if (lineTracerLeft.detectLine()) {
            lowerBody.move(59, -50, -8); // 少し左に進む
        } else {
            lowerBody.move(55, -55, 0); // 直進
        }
        if (lineTracer.detectLine()) k = true;
        while (k == true) {
            lowerBody.move(-64, -64, -64); // 右回転
            delay(1000);                   // 調整する
            k = false;
        }
        if (PS4.Cross()) j = false; // ×ボタン押したら自立モード終了
    }
}