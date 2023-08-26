#include "FilterPower.hpp"

int FilterPower::filterPower(int v) {
    if (v > x) {
        x++;
    } else if (v < x) {
        x--;
    }
    return x;
}