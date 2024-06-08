#include "IntegerData.h"

IntegerData::IntegerData(string name, string value) : Entry(name), value(stoi(value)) {}


void IntegerData::Add(string d)
{
	value += stoi(d);
}

bool IntegerData::Substract(int d)
{
	this->value -= d;
	return this->value > 0;
}

void IntegerData::Print()
{
	cout << name << " = " << value << ";";
}

string IntegerData::GetName()
{
	return this->name;
}
