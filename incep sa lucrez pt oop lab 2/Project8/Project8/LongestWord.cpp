#include "LongestWord.h"

LongestWord::LongestWord(string se)
{
    this->se = se;
}

string LongestWord::GetName()
{
    return this->se;
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
