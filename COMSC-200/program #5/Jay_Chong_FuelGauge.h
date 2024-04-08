#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelGauge {
    // comment #1: this class is a simple class that keeps track of the fuel level of a car
private:
    int fuel;
public:
    // comment #2: constructor that initializes the fuel level to 0 by default 
    FuelGauge(int fuel = 0);
    int getFuel() const;
    void FuelUp();
    void FuelDown();
};

#endif
