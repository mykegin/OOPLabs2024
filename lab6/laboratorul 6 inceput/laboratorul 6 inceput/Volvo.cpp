#include "Volvo.h"

Volvo::Volvo()
{
    fuelCapacity = 50.0;
    fuelConsumption = 15.0;
    avgSpeedSunny = 120.0;
    avgSpeedRain = 100.0;
    avgSpeedSnow = 90.0;
}

double Volvo::calculateTime(double circuitLength, Weather weather)
{
    double speed;
    if (weather == Weather::Rain)
        speed = avgSpeedRain;
    else if (weather == Weather::Sunny)
        speed = avgSpeedSunny;
    else
        speed = avgSpeedSnow;
    double time = circuitLength / speed * 60 * 60;
    double fuelConsumed = fuelConsumption * circuitLength / 100;
    if (fuelConsumed > fuelCapacity)
        return -1.0;
    return time;
}

const char* Volvo::getName()
{
    return "Volvo";
}