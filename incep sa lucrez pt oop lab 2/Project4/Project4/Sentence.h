#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "Procesor.h"
using namespace std;

class Sentence
{
private:
	vector<Procesor*> procesators;
	string name;

public:

	Sentence(const string& nume);
	void RunAll();
	void ListAll();
	void Run(const string& nume);
	void operator +=( Procesor* p);
};

