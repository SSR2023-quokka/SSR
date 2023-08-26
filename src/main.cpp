#include <PS4Controller.h>
#include "LowerBody.hpp"
#include "LineTracer.hpp"

LowerBody lowerBody {19, 0, 20000, 8,
                     17, 1, 20000, 8,
                      4, 2, 20000, 8,};

void setup() {
    Serial.begin(9600);
    PS4.begin("b8:d6:1a:bc:e6:a2");
    Serial.println("Ready.");
    lowerBody.lowerBodySetup();
}

void loop() {
    if (PS4.isConnected()) {
        int i = 64;
        float degree = atan2(PS4.LStickY(), PS4.LStickX());
        float vx = cos(degree) * i;
        float vy = sin(degree) * i;
        int v1 = -vx / 2 + vy * sqrt(3) / 2;
        int v2 = -vx / 2 - vy * sqrt(3) / 2;
        int v3 = vx;

        float PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));
        if (PS4LStickDistance > 70) {
            Serial.printf("v1 = %4d, v2 = %4d, v3 = %4d\n", v1, v2, v3);
            lowerBody.move(v1, v2, v3);
        } else {
            lowerBody.move(0, 0, 0);
        }
    }
}
 