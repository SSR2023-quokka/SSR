#include <PS4Controller.h>
#include <PS4Operation.hpp>
#include <AnalogOut.hpp>
#include <DigitalOut.hpp>

int dir1;
int pwm1;
int pwmch1 = 0;
int dir2; 
int pwm2;
int pwmch2 = 1;
int dir3 = 4;
int pwm3 = 0;
int pwmch3 = 2;


AnalogOut Amoter1{pwm1, pwmch1, 20000, 8};
AnalogOut Amoter2{pwm2, pwmch2, 20000, 8};
AnalogOut Amoter3{dir3, pwmch3, 20000, 8};
DigitalOut Dmoter1{dir1};
DigitalOut Dmoter2{dir2};
DigitalOut Dmoter3{pwm3};

void moterRun1(int v);
void moterRun2(int v);
void moterRun3(int v);

void setup() {
  Serial.begin(9600);
  PS4.begin("b8:d6:1a:bc:e6:a2");
  Serial.println("Ready.");

  Amoter1.setup();
  Amoter2.setup();
  Amoter3.setup();
  Dmoter1.setup();
  Dmoter2.setup();
  Dmoter3.setup();
}

void loop() {
if (PS4.isConnected()) {
    double PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));
    double degree = atan2(PS4.LStickY(), PS4.LStickX());
    double vx = cos(degree) * 32;
    double vy = sin(degree) * 32;
    int v1 = -vx / 2 + vy * sqrt(3) / 2;
    int v2 = -vx / 2 - vy * sqrt(3) / 2;
    int v3 = vx;
    if (PS4LStickDistance > 70) {
      printf("v1 = %d, v2 = %d, v3 = %d\n", v1, v2, v3);

      moterRun1(v1);
      moterRun2(v2);
      moterRun3(v3);
    } else {
      moterRun1(0);
      moterRun2(0);
      moterRun3(0);
    }
  }
}

void moterRun1(int v) {
  int i = 128 - v;
  digitalWrite(pwm3, HIGH);
  ledcWrite(pwmch3, i);
}

void moterRun2(int v) {
  int i = 128 - v;
  digitalWrite(pwm3, HIGH);
  ledcWrite(pwmch3, i);
}

void moterRun3(int v) {
  int i = 128 - v;
  digitalWrite(pwm3, HIGH);
  ledcWrite(pwmch3, i);
}
