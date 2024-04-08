#ifndef ODOMETER_H
#define ODOMETER_H

#include "Jay_Chong_FuelGauge.h"

class Odometer {
    // comment #3: this class is a simple class that keeps track of the mileage of a car
private:
    int mileage;
    FuelGauge& fuelGauge;
public:
// comment #4: constructor that intializes the mileage to 0 by default 
    Odometer(int mileage, FuelGauge& fuelGauge);
    int getMileage() const;
    void MileageUp();
};

#endif
