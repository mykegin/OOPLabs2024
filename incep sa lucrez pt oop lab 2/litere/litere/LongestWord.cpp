#include "LongestWord.h"
#include <vector>
LongestWord::LongestWord(string x)
{
	this->s = x;
}

string LongestWord::GetName()
{
	return this->s;
}

int LongestWord::Compute(string s)
{
	int lengthMax = -1;
	int length = 0;
	int i;
	for (i = 0; i < s.size(); i++)
		if (s[i] == ' ')
		{
			if (length > lengthMax)
			{
				lengthMax = length;
			}
			length = 0;
		}
		else
			length++;
	return lengthMax;
}
