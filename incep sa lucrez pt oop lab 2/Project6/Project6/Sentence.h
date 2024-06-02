#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Procesor.h"
#include <stdio.h>
using namespace std;
class Sentence
{

private:

	vector <Procesor*> procesator;
	string name;


public:

	Sentence(string s);
	void RunAll();
	void ListAll();
	void Run(string p);
	Sentence& operator += (Procesor* p);

};

