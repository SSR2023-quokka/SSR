#include <PS4Operation.hpp>

void PS4Operation() {
  if (PS4.isConnected()) {
    double PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));
    if (PS4LStickDistance > 70) Serial.printf("ON\n");
  }
}
