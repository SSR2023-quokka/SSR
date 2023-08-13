// #include"LowerBody.hpp"

// Motor motor1{0, 0, 0};  //ピンは適当
// Motor motor2{1, 1, 1};
// Motor motor3{2, 2, 2};

// void lowerBodySetup() {
//     motor1.setup();
//     motor2.setup();
//     motor3.setup();
// }

// void lowerBody() {
//     double degree = atan2(PS4.LStickY(), PS4.LStickX());
//     double vx = cos(degree) * 32;
//     double vy = sin(degree) * 32;
//     int v1 = -vx / 2 + vy * sqrt(3) / 2;
//     int v2 = -vx / 2 - vy * sqrt(3) / 2;
//     int v3 = vx;

//     double PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));
//     if (PS4LStickDistance > 70) {
//         printf("v1 = %d, v2 = %d, v3 = %d\n", v1, v2, v3);
//         motor1.motorRun(v1);
//         motor2.motorRun(v2);
//         motor3.motorRun(v3);
//     } else {
//         motor1.motorRun(0);
//         motor2.motorRun(0);
//         motor3.motorRun(0);
//     }
// }