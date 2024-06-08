#pragma once
#include "Entry.h"
#include <string>
#include <iostream>
class StringData :
    public Entry
{
private:
	string value;

public:
	StringData(string name, string value);
	void Add(string d) override;
	bool Substract(int d) override;
	void Print() override;
	string GetName() override;
};