#include <PS4Controller.h>
#include <MoterRun.hpp>

MoterRun moterRun;

void setup() {
  Serial.begin(9600);
  PS4.begin("b8:d6:1a:bc:e6:a2");
  Serial.println("Ready.");
  moterRun.setup();
}

void loop() {
if (PS4.isConnected()) {

    double degree = atan2(PS4.LStickY(), PS4.LStickX());
    double vx = cos(degree) * 32;
    double vy = sin(degree) * 32;
    int v1 = -vx / 2 + vy * sqrt(3) / 2;
    int v2 = -vx / 2 - vy * sqrt(3) / 2;
    int v3 = vx;
    double PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));
    if (PS4LStickDistance > 70) {
      printf("v1 = %d, v2 = %d, v3 = %d\n", v1, v2, v3);
      moterRun.moterRun(1, v1);
      moterRun.moterRun(2, v2);
      moterRun.moterRun(3, v3);
    } else {
      moterRun.moterRun(1, 0);
      moterRun.moterRun(2, 0);
      moterRun.moterRun(3, 0);
    }
  }
}
