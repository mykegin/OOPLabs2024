#pragma once
#include "Car.h"

class Volvo: public Car
{
private: 
	int capac=50;
	int consum=10;
	int vr=500;
	int vsu=100;
	int vsn=50;
public:
	Volvo();
	virtual const char* getName();
	int calculateTime(double circuitLength, Weather weather);
};

