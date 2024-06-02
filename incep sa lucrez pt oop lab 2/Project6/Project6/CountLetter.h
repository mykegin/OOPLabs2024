#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Sentence.h"
#include <stdio.h>
#include <functional>
using namespace std;
class CountLetter : public Procesor
{

private:

	string cuv;
	function <bool(char)> predicat;


public:

	CountLetter(string p, function <bool(char)> predicate);
	string GetName();
	int Compute(string p);
};

