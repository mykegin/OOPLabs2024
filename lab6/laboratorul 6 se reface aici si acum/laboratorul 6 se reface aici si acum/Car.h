#pragma once
#include <iostream>
#include "Weather.h"

class Car
{
private: 
	int capac;
	int consum;
	int vr;
	int vsu;
	int vsn;
	int ft;
	int time;


public:

	virtual int calculateTime(double circuitLength, Weather weather);
	virtual const char* getName() = 0;
	void setFinishTime(double timp)
	{
		time = timp;
	};
	double getFinishTime()
	{
		return time;
	};

};

