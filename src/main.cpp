#include <PS4Controller.h>
#include "MachineMoving.hpp"
#include "Arm.hpp"

void setup() {
    Serial.begin(9600);
    PS4.begin("b8:d6:1a:bc:e6:a2");
    Serial.println("Ready.");
    machineMovingSetup();
    armSetup();
}

void loop() {
    if (PS4.isConnected()) {
        machineMoving();
        arm();
    }
}
 