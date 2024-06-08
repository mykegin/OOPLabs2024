#include "CountLetter.h"

CountLetter::CountLetter(string s, function<bool(char)> x)
{
	this->x = x;
	this->s = s;
}

string CountLetter::GetName()
{
	return this->s;
}

int CountLetter::Compute(string s)
{
	int count = 0, i;
	for (i = 0; i < s.size(); i++)
	{
		if (x(s[i]))
			count++;
	}
	return count;
}
