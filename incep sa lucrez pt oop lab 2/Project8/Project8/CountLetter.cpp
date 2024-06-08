#include "CountLetter.h"


CountLetter::CountLetter(string s, function<bool(char)> predicat)
{
	this->se = s;
	this->pr = predicat;
}

string CountLetter::GetName()
{
	return this->se;
}

int CountLetter::Compute(string s)
{
	int i, nr = 0;
	for (i = 0; i < s.size(); i++)
		if (pr(s[i]))
			nr++;
	return nr;
}
