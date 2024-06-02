#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Sentence.h"
#include <stdio.h>
using namespace std;
class Procesor
{

private:

	string prop;


	public:

		virtual string GetName()=0;
		virtual int Compute(string p)=0;
};

