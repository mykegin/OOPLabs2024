#pragma once
#include "Animal.h"
using namespace std;
class Shark : public Animal
{
	string GetName() override
	{
		return "Shark";
	};
	bool IsAFish() override
	{
		return true;
	};
	bool IsABird() override
	{
		return false;
	};
	bool IsAMammal() override
	{
		return false;
	};
};

