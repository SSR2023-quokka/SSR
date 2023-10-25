#include "AnimalArm.hpp"

Servo servoMotor2;

int pos2 = 0;
int m = 0;


#define PIN1 26  // 赤
#define PIN2 12  // 青
#define PIN3 27  // 黄
#define PIN4 25  // オレンジ

#define STEP 200
Stepper stepper1(STEP, PIN1, PIN3, PIN2, PIN4);  // オブジェクトを生成

void animalArmSetup() {

	stepper1.setSpeed( 30 );  // 1分間当たりの回転数を設定(rpm)
    pinMode(PIN1, OUTPUT);    // デジタルピンを出力に設定
    pinMode(PIN2, OUTPUT);
    pinMode(PIN3, OUTPUT);
    pinMode(PIN4, OUTPUT);

	ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    servoMotor2.setPeriodHertz(50);
    servoMotor2.attach(33, 500, 2400);
}

void animalArm() {
	if (m == 0 && PS4.Square()) {
    	for (pos2 = 0; pos2 <= 120; pos2 += 1) {
			servoMotor2.write(pos2);
			Serial.printf("animal arm position = %d\n", pos2);
	    	delay(30);
		}
		m = 1;
	}
	else if (m == 1 && PS4.Square()) {
		for (pos2 = 120; pos2 >= 0; pos2 -= 1) {
			servoMotor2.write(pos2);
			Serial.printf("animal arm position = %d\n", pos2);
			delay(30);
		}
		m = 0;
	}

	while (PS4.Up()) {
		stepper1.step(50);
	}
	while (PS4.Down()) {
		stepper1.step(-50);
	}
	digitalWrite(PIN1, LOW);
	digitalWrite(PIN2, LOW);
	digitalWrite(PIN3, LOW);
	digitalWrite(PIN4, LOW);

}
