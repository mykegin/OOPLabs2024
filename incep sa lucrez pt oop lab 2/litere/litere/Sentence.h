#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Procesor.h"
using namespace std;
class Sentence
{
	vector <Procesor*> procesators;
	string name;

public:
	Sentence(string s);
	Sentence& operator +=(Procesor* p);
	void ListAll();
	void RunAll();
	void Run(string s);

};

