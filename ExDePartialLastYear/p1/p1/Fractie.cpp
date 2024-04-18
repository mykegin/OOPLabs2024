#include "Fractie.h"
#include <stdio.h>

Fractie::Fractie(int x, int y)
{
	this->numarator = x;
	this->numitor = y;
}

Fractie::Fractie(const char* x)
{
	this->numarator = 0;
	this->numitor = 0;

	int i = 0; int k = 0;
	int nrm=0, num = 0;
	while (x[i] != '\0')
	{
		if (x[i] >= '0' && x[i] <= '9' && k == 0)
			nrm = nrm * 10 + (x[i] - '0');
		else
			if (x[i] == '/')
				k = 1;
			else
				if (x[i] >= '0' && x[i] <= '9' && k == 1)
					num = num * 10 + (x[i] - '0');
		i++;
	}
	this->numarator = nrm;
	this->numitor = num;

	printf("%d       %d \n", nrm, num);
}


Fractie& Fractie::operator-(const Fractie& x)
{
	Fractie temp(x);
	Fractie temp2(*this);

	int a, b;
	a = this->numitor;
	b = x.numitor;
	temp2.numitor = (temp2.numitor) * b;
	temp2.numarator = (temp2.numarator) * b;
	temp.numitor = temp.numitor * a;
	temp.numarator = temp.numarator * a;

	temp.numarator -= temp2.numarator;

	return temp;

}

Fractie& Fractie::operator+(const Fractie& x)
{
	Fractie temp(x);
	Fractie temp2(*this);

	int a, b;
	a = this->numitor;
	b = x.numitor;
	temp2.numitor = (temp2.numitor) * b;
	temp2.numarator = (temp2.numarator) * b;
	temp.numitor = temp.numitor * a;
	temp.numarator = temp.numarator * a;

	temp.numarator += temp2.numarator;

	return temp;
}

Fractie& Fractie::operator*(const Fractie& x)
{
	Fractie temp(x);
	Fractie temp2(*this);

	int a = temp.numarator * temp2.numarator;
	int b = temp.numitor * temp2.numitor;

	temp.numarator = a;
	temp.numitor = b;

	return temp;

}

bool Fractie::operator==(const Fractie& x)
{
	Fractie temp(x);
	Fractie temp2(*this);

	if (temp.numarator == temp2.numarator && temp.numitor == temp2.numitor)
		return 1;
	else
		return 0;
}

int Fractie::operator[](const char* value)
{
	if (value == "numerator")
	{
		return this->numarator;
	}
	else if (value == "denominator")
	{
		return this->numitor;
	}
	return 0;
}

void Fractie::print()
{
	printf("%d / %d", this->numarator, this->numitor);
}
