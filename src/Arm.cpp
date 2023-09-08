#include "Arm.hpp"

ServoMotor servoMotor1{32};

int pos = 0;
int l = 0;

void armSetup() {
	servoMotor1.setup();
}

void arm() {
	if (l == 0 && PS4.Triangle()) {
    	for (pos = 0; pos <= 60; pos += 1) {
			servoMotor1.servoWrite(pos);
			Serial.printf("%d\n", pos);
	    	delay(30);
		}
		l = 1;
	}
	else if (l == 1 && PS4.Triangle()) {
		for (pos = 60; pos >= 0; pos -= 1) {
			servoMotor1.servoWrite(pos);
			Serial.printf("%d\n", pos);
			delay(30);
		}
		l = 0;
	}
}