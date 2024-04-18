#include "BMW.h"

BMW::BMW() {
    capac = 50.0;
    consum = 15.0;
    vsu = 120.0;
    vr = 100.0;
    vsn = 90.0;
}

int BMW::calculateTime(double circuitLength, Weather weather)
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
    if (fuelConsumed > capac)
        return 1;
    return time;
}

const char* BMW::getName()
{
    return "BMW";
}