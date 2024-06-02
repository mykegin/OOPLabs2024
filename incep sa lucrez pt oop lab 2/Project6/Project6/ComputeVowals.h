#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Sentence.h"
#include <stdio.h>
#include <functional>
using namespace std;
class ComputeVowals : public Procesor
{
private:

	string cuv;

public:
	ComputeVowals( string c );
	string GetName();
	int Compute(string p);
};

