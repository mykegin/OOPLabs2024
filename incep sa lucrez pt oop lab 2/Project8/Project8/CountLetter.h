#pragma once
#include "Procesor.h"
#include <iostream>
#include <functional>
using namespace std;
class CountLetter :public Procesor
{
private:
	string se;
	function <bool(char)> pr;

public:

	CountLetter(string s, function <bool(char)> predicat);
	string GetName();
	int Compute(string s);
};

