// 200_assign5.cpp
#include <iostream>
#include <iomanip>
#include "Jay_Chong_FuelGauge.h"
#include "Jay_Chong_Odometer.h"

// to run these programs do g++ .\Jay_Chong_200_assign5.cpp Jay_Chong_FuelGauge.cpp Jay_Chong_Odometer.cpp -o carSimulation

// comment #12: the main function creates a FuelGauge object and an Odoeter object, and then runs a loop that fills up the fuel tank until it is full, and then drives the car until it runs out of fuel
int main() {
    FuelGauge fuelGauge;
    Odometer odometer(0, fuelGauge);

    
    for (int i = 0; i < 15; ++i) {
        fuelGauge.FuelUp();
    }

    
    while (fuelGauge.getFuel() > 0) {
        odometer.MileageUp();
        std::cout << "Mileage: " << std::setw(2) << odometer.getMileage()
                  << "\nFuel level: " << fuelGauge.getFuel() << " gallons"
                  << "\n---------------------------\n";
    }

    std::cout << "The car has run out of fuel." << std::endl;

    return 0;
}
