#pragma once
class Number
{
	const char* nrcurent;
	char* rezfinal;
	int primabaza;
	int bazacurenta;
	int nrcif = 0;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	///~Number();

	// add operators and copy/move constructor

	void SwitchBase(int newBase);
	void Print(); ///done cred
	int  GetDigitsCount(); // done
	int  GetBase(); // returns the current base
};

