#pragma once
#include "Car.h"
class BMW: public Car
{
	private:
		int capac = 50;
		int consum = 10;
		int vr = 500;
		int vsu = 100;
		int vsn = 50;
	public:
		BMW();
		virtual const char* getName();
		int calculateTime(double circuitLength, Weather weather);
};

