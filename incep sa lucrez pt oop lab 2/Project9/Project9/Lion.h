#pragma once
#include "Feline.h"
using namespace std;
class Lion : public Feline 
{
	string GetName() override
	{
		return "Lion";
	};
	bool IsAFish() override
	{
		return false;
	};
	bool IsABird() override
	{
		return false;
	};
	bool IsAMammal() override
	{
		return true;
	};

	int GetSpeed() override
	{
		return 80;
	};
};

