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

	this->primabaza=this->bazacurenta=this->nrcif = 0;
}

/*
Number::Number(const Number& d)
{
	this->primabaza = d.primabaza;
	this->bazacurenta = d.bazacurenta;
	this->nrcif = d.nrcif;
	this->nrcurent = new char[d.nrcif];
	this->nrcurent = d.nrcurent;
}

Number::Number(Number&& e)
{
	char* temp = e.nrcurent;
	e.nrcurent = nullptr;
	this->nrcurent = temp;
}*/

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
	char* cuvsup = new char[this->nrcif];
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

	printf("% s \n", this->nrcurent);
}

void transformarebaza10(char* x, int baza)
{
	char* cuvsup = new char[strlen(x)];
	cuvsup = x;
	int lungime = strlen(x);
	int numar = 0;
	int p = 1;

	for (int i = lungime - 1; i >= 0; i--)
	{
		numar += val(cuvsup[i]) * p;
		p = p * baza;
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
	x = new char[nrimp];
	x = cuvsup;
	
	printf("s-a ajuns pana aici\n");
	///this->nrcif = nrimp;
	//printf("% s \n", this->nrcurent);
}

bool Number::operator > (const Number& other)
{
	Number nr1(*this), nr2(other);
	//printf("%s \n", *this);
	//printf("%s \n", other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	//printf("%s \n", *this);
	//printf("%s \n", other);
	return nr1.nrcurent > nr2.nrcurent;
}

/*bool Number::operator > (const Number& x)
{
	int bazap, bazad, bazamaimare;
	bazap = bazacurenta;
	bazad = x.bazacurenta;
	if (bazacurenta > x.bazacurenta)
		bazamaimare = bazacurenta;
	else
		bazamaimare = x.bazacurenta;

	///SwitchBase(bazamaimare);

	transformarebaza10(this->nrcurent, bazacurenta);
	transformarebaza10(x.nrcurent, x.bazacurenta);
	for (int i = 0; i < strlen(this->nrcurent); i++)
		if (this->nrcurent[i] >x.nrcurent[i])
			return true;
		else
			return false;

	return false;
}

bool Number::operator < (const Number& x)
{
	int bazap, bazad, bazamaimare;
	bazap = bazacurenta;
	bazad = x.bazacurenta;
	if (bazacurenta > x.bazacurenta)
		bazamaimare = bazacurenta;
	else
		bazamaimare = x.bazacurenta;

	///SwitchBase(bazamaimare);

	transformarebaza10(this->nrcurent, bazacurenta);
	transformarebaza10(x.nrcurent, x.bazacurenta);
	for (int i = 0; i < strlen(this->nrcurent); i++)
		if (this->nrcurent[i] < x.nrcurent[i])
			return true;
		else
			return false;

	return false;
}

bool Number::operator >= (const Number& x)
{
	int bazap, bazad, bazamaimare;
	bazap = this->bazacurenta;
	bazad = x.bazacurenta;
	if (this->bazacurenta > x.bazacurenta)
		bazamaimare = this->bazacurenta;
	else
		bazamaimare = x.bazacurenta;

	///SwitchBase(bazamaimare);

	transformarebaza10(this->nrcurent, this->bazacurenta);
	transformarebaza10(x.nrcurent, x.bazacurenta);
	for (int i = 0; i < strlen(this->nrcurent); i++)
		if (this->nrcurent[i] >= x.nrcurent[i])
			return true;
		else
			return false;

	return false;
}

bool Number::operator <= (const Number& x)
{
	Number nr1(*this), nr2(x);
	printf("%s \n", nr1);
	printf("%s \n", nr2);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	printf("%s \n", nr1);
	printf("%s \n", nr2);
	return nr1.nrcurent <= nr2.nrcurent;
}*/

/*bool Number::operator <= (const Number& x)
{
	int bazap, bazad, bazamaimare;
	Number nr1(*this), nr2(x);
	bazap = bazacurenta;
	bazad = x.bazacurenta;
	if (bazacurenta > x.bazacurenta)
		bazamaimare = bazacurenta;
	else
		bazamaimare = x.bazacurenta;

	///SwitchBase(bazamaimare);

	nr1.SwitchBase(10);

	for (int i = 0; i < strlen(this->nrcurent); i++)
		if (this->nrcurent[i] <= x.nrcurent[i])
			return true;
		else
			return false;

	return false;
}*/

/*
bool Number::operator == (const Number& x)
{
	int bazap, bazad, bazamaimare;
	bazap = bazacurenta;
	bazad = x.bazacurenta;
	if (bazacurenta > x.bazacurenta)
		bazamaimare = bazacurenta;
	else
		bazamaimare = x.bazacurenta;

	///SwitchBase(bazamaimare);

	printf("%s \n", x.nrcurent);
	printf("%s \n", this->nrcurent);

	transformarebaza10(this->nrcurent, bazacurenta);
	transformarebaza10(x.nrcurent, x.bazacurenta);

	printf("%s \n", x.nrcurent);
	printf("%s \n", this->nrcurent);
	for (int i = 0; i < strlen(this->nrcurent); i++)
		if (this->nrcurent[i] == x.nrcurent[i])
			return true;
		else
		{
			printf("%s \n", x.nrcurent[i]);
			return false;
		}

	return false;
}
*/