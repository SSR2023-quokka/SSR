#pragma once

#include <Arduino.h>
#include <PS4Controller.h>
#include "AnalogIn.hpp"

struct LineTracer {
    AnalogIn pin;
    
    void lineTracerSetup();
    bool detectLine();
};
