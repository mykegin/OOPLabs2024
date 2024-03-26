#include "Number.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

Number::Number(const char* value, int base)
{
	this->nrcurent = value;
	this->primabaza = base;
	this->bazacurenta = base;
}

void Number::SwitchBase(int newBase)
{
	this->bazacurenta = newBase;
}

int Number::GetDigitsCount()
{
	this->nrcif = 0;
	int i = 0;
	while (this->nrcurent[i] != NULL)
	{
		this->nrcif++;
		i++;
	}

	return this->nrcif;
}

int Number::GetBase()
{
	return this->bazacurenta;
}

void Number::Print()
{
	printf("%s \n", this->nrcurent);
}