#include "Arm.hpp"

Servo servoMotor1;

int pos1 = 0;
int l = 0;
int n = 0;

void armSetup() {
	pinMode(21, OUTPUT);
	ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    servoMotor1.setPeriodHertz(50);
    servoMotor1.attach(32, 500, 2400);
}

void arm() {
	if (l == 0 && PS4.Triangle()) {
    	for (pos1 = 0; pos1 <= 60; pos1 += 1) {
			servoMotor1.write(pos1);
			Serial.printf("arm position = %d\n", pos1);
	    	delay(30);
		}
		l = 1;
	} else if (l == 1 && PS4.Triangle()) {
		for (pos1 = 60; pos1 >= 0; pos1 -= 1) {
			servoMotor1.write(pos1);
			Serial.printf("arm position = %d\n", pos1);
			delay(30);
		}
		l = 0;
	}

	if (n == 0 && PS4.Right()) {
		digitalWrite(21, HIGH);
		n = 1;
		Serial.printf("denji gate on");
		delay(1000);
	} else if (n == 1 && PS4.Right()) {
		digitalWrite(21, LOW);
		n = 0;
		Serial.printf("denji gate off");
		delay(1000);
	}
}