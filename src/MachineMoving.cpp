#include "MachineMoving.hpp"

LowerBody lowerBody{    //pwmch を0,1,2 または 1,2,3 にするとうまく動かない...
    18,5,20000,8,19,0,  //多分、サーボのpwmchに干渉するため、サーボの数だけchをずらす必要がある
    16,6,20000,8,17,0,
     0,7,20000,8, 4,0,
};

// LineTracer lineTracer{39};
// LineTracer lineTracerRight{34};
// LineTracer lineTracerLeft{35};

int i = 48; // 0 <= i <= 128
bool j = false;
int k = 0;
int v_theta = 0;

void machineMovingSetup() {
    lowerBody.lowerBodySetup();
    // lineTracer.setup();
    // lineTracerRight.setup();
    // lineTracerLeft.setup();
}

void machineMoving() {
    float degree = atan2(PS4.LStickY(), PS4.LStickX());
    float v_x = cos(degree) * i;
    float v_y = sin(degree) * i;
    int v1 = -v_x / 2 + v_y * sqrt(3) / 2 + v_theta;
    int v2 = -v_x / 2 - v_y * sqrt(3) / 2 + v_theta;
    int v3 = v_x + v_theta;

    if (PS4.R1() && PS4.L1()) v_theta = 0;  //回転の操作
    else if (PS4.L1()) v_theta = 32;
    else if (PS4.R1()) v_theta = -32;
    else v_theta = 0;

    float PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));  //原点からの距離
    if (PS4LStickDistance > 70) {
        Serial.printf("v1 = %4d, v2 = %4d, v3 = %4d\n", v1, v2, v3);
        lowerBody.move(v1, v2, v3);
    } else {   
        Serial.printf("v1 = %4d, v2 = %4d, v3 = %4d\n", v_theta, v_theta, v_theta);
        lowerBody.move(v_theta, v_theta, v_theta);
    }

    // if (PS4.Circle()) {
    //     j = true; // 〇ボタンを押したら自立モード
    //     Serial.printf("auto on\n");
    // }
    // while (j == true) {
    //     if (lineTracerRight.detectLine()) {
    //         lowerBody.move(25, -29, 4); // 少し右に進む
    //     } else if (lineTracerLeft.detectLine()) {
    //         lowerBody.move(29, -25, -4); // 少し左に進む
    //     } else {
    //         lowerBody.move(27, -27, 0); // 直進
    //     }
    //     if (lineTracer.detectLine()) k = k + 1;
    //     if (k == 2 || k == 3) {
    //         lowerBody.move(-32, -32, -32); // 右回転
    //         delay(2000);                   // 調整する
    //     }
    //     if (PS4.Cross()) {
    //         j = false; // ×ボタン押したら自立モード終了
    //         Serial.printf("auto off\n");
    //     }
    // // }

    // if (PS4.Circle()) {
    //     j = true; // 〇ボタンを押したら自立モード
    //     Serial.printf("auto on\n");
    // }
    // if (j == true) {
    //         lowerBody.move(27, -27, 0); // 直進
    //         delay(2000);
    //         lowerBody.move(-32, -32, -32); // 右回転
    //         delay(2000);                   // 調整する
    //         j = false; // ×ボタン押したら自立モード終了
    // }


}