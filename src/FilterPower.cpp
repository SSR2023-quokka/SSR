#include "FilterPower.hpp"

int FilterPower::filterPower(int value) {   //vの値へと近づけていく
    int distance = abs(value - result);
    if (distance < 100){
        result = value;
    } else {
        if (value > result) {
            result = result + distance / 10;
        } else {
            result = result - distance / 10;
        }
    }
    return result;
}