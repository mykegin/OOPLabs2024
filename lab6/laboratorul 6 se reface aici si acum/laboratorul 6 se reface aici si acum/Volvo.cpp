#include "Volvo.h"
#include "Car.h"

Volvo::Volvo()
{
    capac = 50.0;
    consum = 15.0;
    vsu = 120.0;
    vr = 100.0;
    vsn = 90.0;
}

int Volvo::calculateTime(double circuitLength, Weather weather)
{
    double speed;
    if (weather == Weather::Rain)
        speed = vr;
    else if (weather == Weather::Sunny)
        speed = vsu;
    else
        speed = vsn;
    double time = circuitLength / speed * 60 * 60;
    double fuelConsumed = consum * circuitLength / 100;
    if (consum > capac)
        return -1;
    return time;
}

const char* Volvo::getName()
{
    return "Volvo";
}