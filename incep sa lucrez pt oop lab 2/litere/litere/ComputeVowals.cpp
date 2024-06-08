#include "ComputeVowals.h"

ComputeVowals::ComputeVowals(string s)
{
	this->s = s;
}

string ComputeVowals::GetName()
{
	return this->s;
}


int ComputeVowals::Compute(string s)
{
	int count = 0, i=0;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
			count++;
	}
	return count;
}
