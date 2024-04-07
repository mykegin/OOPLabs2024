#pragma once
#include "Car.h"

class Volvo : public Car {
private:
    double fuelCapacity = 50.0;
    double fuelConsumption = 10.0;
    double avgSpeedSunny = 100.0;
    double avgSpeedRain = 500.0;
    double avgSpeedSnow = 50.0;
public:
    Volvo();
    virtual const char* getName();
    virtual double calculateTime(double circuitLength, Weather weather);
};