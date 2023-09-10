#include "Arm.hpp"

ServoMotor servoMotor1{32};

int pos1 = 0;
int l = 0;

void armSetup() {
	servoMotor1.setup();
}

void arm() {
	if (l == 0 && PS4.Triangle()) {
    	for (pos1 = 0; pos1 <= 60; pos1 += 1) {
			servoMotor1.write(pos1);
			Serial.printf("arm position = %d\n", pos1);
	    	delay(30);
		}
		l = 1;
	}
	else if (l == 1 && PS4.Triangle()) {
		for (pos1 = 60; pos1 >= 0; pos1 -= 1) {
			servoMotor1.write(pos1);
			Serial.printf("arm position = %d\n", pos1);
			delay(30);
		}
		l = 0;
	}
}