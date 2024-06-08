#include "Entry.h"

Entry::Entry(string nume)
{
	this->name = nume;
}

string Entry::GetName()
{
	return this->name;
}
