#pragma once
#include "Animal.h"
using namespace std;
class Eagle : public Animal
{
	string GetName() override
	{
		return "Eagle";
	};
	bool IsAFish() override
	{
		return false;
	};
	bool IsABird() override
	{
		return true;
	};
	bool IsAMammal() override
	{
		return false;
	};
};

