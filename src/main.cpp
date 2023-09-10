#include <Arduino.h>
#include <PS4Controller.h>
#include "MachineMoving.hpp"
#include "Arm.hpp"
#include "AnimalArm.hpp"

void setup() {
    Serial.begin(9600);
    PS4.begin("b8:d6:1a:bc:e6:a2");
    Serial.println("Ready.");
    machineMovingSetup();
    armSetup();
    animalArmSetup();
}

void loop() {   //割り込みをしていないので複数の動作を同時にできない（例）アームを開閉しながら移動をする
    if (PS4.isConnected()) {
        machineMoving();
        arm();
        animalArm();
    }
}
