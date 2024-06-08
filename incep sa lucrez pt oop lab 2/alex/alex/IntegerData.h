#pragma once
#include "Entry.h"
class IntegerData :
    public Entry
{
private:
    int value;

public:

	IntegerData(string name, string value);
	void Add(string d) override;
	bool Substract(int d) override;
	void Print() override;
	string GetName() override;
};

