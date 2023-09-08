#include "FilterPower.hpp"

int FilterPower::filterPower(int v) {
    int distance = abs(v - x);
    if (distance < 100){
        x = v;
    } else {
        if (v > x) {
            x = x + distance / 10;
        } else {
            x = x - distance / 10;
        }
    }
    Serial.printf("%d\n",x);
    return x;
}