#include <PS4Controller.h>
#include<PS4Operation.hpp>

void setup() {
  Serial.begin(9600);
  PS4.begin("b8:d6:1a:bc:e6:a2");
  Serial.println("Ready.");
}

void loop() {
  PS4Operation();
  delay(1000);
}
