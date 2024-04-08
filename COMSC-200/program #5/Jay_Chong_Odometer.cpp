// Odometer.cpp
#include "Jay_Chong_Odometer.h"

// comment #5: the constructor initializes the mileage and fuelGauge member variables with the values passed in as arguments
Odometer::Odometer(int mileage, FuelGauge& fuelGauge) : mileage(mileage), fuelGauge(fuelGauge) {}
// comment #6: returns the current mileage
int Odometer::getMileage() const {
    return mileage;
}

//  comment #7: increnents the mileage by 1, and if the mileage is a multiple of 24, then the fuel level is decreased by 1
void Odometer::MileageUp() {
    if (mileage < 9999) {
        ++mileage;
    } else {
        mileage = 0;
    }

    if (mileage % 24 == 0) {
        fuelGauge.FuelDown();
    }
}
