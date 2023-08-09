#include <PS4Operation.hpp>

void PS4Operation() {
  if (PS4.isConnected()) {
    double PS4LStickDistance = sqrt(pow(PS4.LStickX(), 2) + pow(PS4.LStickY(), 2));
    double degree = atan2(PS4.LStickY(), PS4.LStickX());
    if (PS4LStickDistance > 70) {
      double degree = atan2(PS4.LStickY(), PS4.LStickX());
      Serial.printf("%lf\n", degree);
    }
  }
}
