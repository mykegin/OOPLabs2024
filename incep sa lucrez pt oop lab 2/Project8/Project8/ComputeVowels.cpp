#include "ComputeVowels.h"

ComputeVowels::ComputeVowels(string s)
{
    this->es = s;
}

string ComputeVowels::GetName()
{
    return es;
}

int ComputeVowels::Compute(string s)
{
	int i, nr = 0;
	for (i = 0; i < s.size(); i++)
		if (strchr("aeiouAEIOU", s[i]) != 0)
			nr++;
	return nr;
}
