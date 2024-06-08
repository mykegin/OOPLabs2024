#pragma once
#include "Feline.h"
using namespace std;
class Tiger : public Feline
{
	string GetName() override
	{
		return "Tiger";
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
		return 200;
	};
};

