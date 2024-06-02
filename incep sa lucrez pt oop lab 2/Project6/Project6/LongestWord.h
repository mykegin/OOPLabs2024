#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Sentence.h"
#include <stdio.h>
using namespace std;
class LongestWord : public Procesor
{

	string cuv;

public:
	LongestWord( string p);
	string GetName();
	int Compute(string p);
};

