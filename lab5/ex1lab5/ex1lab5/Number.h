#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
class Number
{
	char* nrcurent;
	char* rezfinal;
	int primabaza;
	int bazacurenta;
	int nrcif = 0;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();//done

	// add operators and copy/move constructor

	void SwitchBase(int newBase); //done
	void Print(); //done 
	int  GetDigitsCount(); // done
	int  GetBase(); // done
};

