#include "AnimalArm.hpp"

ServoMotor servoMotor2{33};

int pos2 = 0;
int m = 0;

void animalArmSetup() {
    servoMotor2.setup();
}

void animalArm() {
	if (m == 0 && PS4.Square()) {
    	for (pos2 = 0; pos2 <= 90; pos2 += 1) {
			servoMotor2.write(pos2);
			Serial.printf("animal arm position = %d\n", pos2);
	    	delay(30);
		}
		m = 1;
	}
	else if (m == 1 && PS4.Square()) {
		for (pos2 = 90; pos2 >= 0; pos2 -= 1) {
			servoMotor2.write(pos2);
			Serial.printf("animal arm position = %d\n", pos2);
			delay(30);
		}
		m = 0;
	}
    //　ここから下にステッピングのを書く
}
