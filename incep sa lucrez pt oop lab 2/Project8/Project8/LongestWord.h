#pragma once
#include "Procesor.h"
#include <string>
using namespace std;
class LongestWord :public Procesor
{

private:

	string se;

public:
	LongestWord(string se);
	string GetName();
	int Compute(string s);
};

