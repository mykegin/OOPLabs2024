#include "Number.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

Number::Number(const char* value, int base)
{
	this->nrcurent = new char [strlen (value)];
    strcpy((this->nrcurent), value);
	this->primabaza = base;
	this->bazacurenta = base;
}

Number::~Number()
{
	delete this->nrcurent;
	this->nrcurent = nullptr;
	delete this->rezfinal;
	this->rezfinal = nullptr;

	this->primabaza=this->bazacurenta=this->nrcif = 0;
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

int val(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

void Number::SwitchBase(int newBase)
{
	char* cuvsup= new char[this->nrcif];
	cuvsup = this->nrcurent;
	int lungime = this->nrcif;
	int numar=0;
	int p = 1;

	for (int i = lungime - 1; i >= 0; i--)
	{
		numar += val(cuvsup[i]) * p;
		p = p * this->primabaza;
	}
	
	int nrimp = 0, cn = numar;
	while (cn)
	{
		cn /= 10;
		nrimp++;
	}

	//printf("%d \n", nrimp);

	//delete[] cuvsup;
	cuvsup = new char[nrimp];

	for (int i = 1; i <= nrimp; i++)
	{
		cuvsup[i - 1] = reVal(numar % 10);
		numar /= 10;
		//printf("%c \n", reVal(numar % newBase));
	}

	//printf("%s \n", cuvsup);

	for (int i = 0; i < nrimp / 2; i++)
	{
		char aux;
		aux = cuvsup[i];
		cuvsup[i] = cuvsup[nrimp - 1 - i];
		cuvsup[nrimp - 1 - i] = aux;
	}

	cuvsup[nrimp] = '\0';
	//printf("% s \n", cuvsup);

	///delete[] this->nrcurent;
	this->nrcurent = new char[nrimp];
	this->nrcurent = cuvsup;

	//printf("% s \n", this->nrcurent);
	this->nrcif = nrimp;
	//printf("% s \n", this->nrcurent);








	if (newBase != 10)
	{
		cuvsup = new char[this->nrcif];
		cuvsup = this->nrcurent;
		lungime = this->nrcif;
		numar = 0;
		p = 1;


		for (int i = lungime - 1; i >= 0; i--)
		{
			numar += val(cuvsup[i]) * p;
			p = p * 10;
		}

		nrimp = 0, cn = numar;
		while (cn)
		{
			cn /= newBase;
			nrimp++;
		}

		//printf("%d \n", numar);

		//delete cuvsup;
		cuvsup = new char[nrimp];

		for (int i = 1; i <= nrimp; i++)
		{
			cuvsup[i - 1] = reVal(numar % newBase);
			//printf("%c \n", reVal(numar % newBase));
			numar /= newBase;
		}

		///printf("%s \n", cuvsup);

		for (int i = 0; i < nrimp / 2; i++)
		{
			char aux;
			aux = cuvsup[i];
			cuvsup[i] = cuvsup[nrimp - 1 - i];
			cuvsup[nrimp - 1 - i] = aux;
		}

		cuvsup[nrimp] = '\0';
		//printf("% s \n", cuvsup);

		///delete[] this->nrcurent;
		this->nrcurent = new char[nrimp];
		this->nrcurent = cuvsup;

		//printf("% s \n", this->nrcurent);
	}
	this->nrcif = nrimp;
	this->bazacurenta = newBase;
}