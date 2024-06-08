#include "StringData.h"
#include <iostream>

StringData::StringData(string name, string value) : Entry(name), value(value) {}

void StringData::Add(string d)
{
	value += ";" + d;
}

bool StringData::Substract(int d)
{
	return false;
}

void StringData::Print()
{
	cout << this->name << " = " << this->value << ";";
}

string StringData::GetName()
{
	return this -> name;
}
