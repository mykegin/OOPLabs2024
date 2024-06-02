#pragma once
#include <string>

class Procesor
{
public:
	Procesor(const string& nume)
	{
		name = nume;
	}
	string GetName() const
	{
		return name;
	}
	int Compute(const string& nume) = 0;
};

