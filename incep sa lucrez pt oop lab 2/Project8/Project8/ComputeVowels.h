#pragma once
#include "Procesor.h"
#include <string>
using namespace std;
class ComputeVowels :public Procesor
{
	string es;

public:

	ComputeVowels(string s);
	string GetName();
	int Compute(string s);
};

