#include "CountLetter.h"

CountLetter::CountLetter(string p, function <bool(char)> predicate)
{
	this->cuv = p;
	this->predicat = predicate;
}

string CountLetter::GetName()
{
	return cuv;
}

int CountLetter::Compute(string p)
{
	return 696;
}
