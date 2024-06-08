#pragma once
#include "Animal.h"
using namespace std;
class Feline : public Animal
{
public:
	virtual int GetSpeed() =0;
};

