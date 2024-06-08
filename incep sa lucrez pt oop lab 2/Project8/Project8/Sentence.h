#pragma once
#include <string>
#include <vector>
#include "Procesor.h"
using namespace std;
class Sentence
{
	vector <Procesor*> procesator;
	string name;

public:
	Sentence(string s);
	void RunAll();
	void ListAll();
	void Run(string s);
	Sentence& operator +=(Procesor* x);
};

