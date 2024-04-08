// FuelGauge.cpp
#include "Jay_Chong_FuelGauge.h"

// comment #8: the constructor initializes the fuel member variable with the value passed in as an argument
FuelGauge::FuelGauge(int fuel) : fuel(fuel) {}

// comment #9: returns the current fel level
int FuelGauge::getFuel() const {
    return fuel;
}

// comment #10: increments the fuel level by 1
void FuelGauge::FuelUp() {
    if (fuel < 15) {
        ++fuel;
    }
}

//  comment #11: decrements the fuel level by 1
void FuelGauge::FuelDown() {
    if (fuel > 0) {
        --fuel;
    }
}
