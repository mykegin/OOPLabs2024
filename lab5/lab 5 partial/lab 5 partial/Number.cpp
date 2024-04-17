#include "Number.h"
#include <stdio.h>

Number::Number(const char* value, int base)
{
	this->baza = base;
	int i = 0;
	while (value[i] != '\0')
		i++;
	nrcif = i;
	this->numar = new char[i + 1];
	for (i = 0; i < nrcif; i++)
		this->numar[i] = value[i];
	this->numar[this->nrcif] = '\0';
}

Number::Number(const Number& d)
{
	this->nrcif = d.nrcif;
	this->baza = d.baza;
	this->numar = new char[this->nrcif + 1];
	for (int i = 0; i < this->nrcif; i++)
		this->numar[i] = d.numar[i];
	this->numar[nrcif] = '\0';
}

Number::Number(Number&& d)
{
	this->nrcif = d.nrcif;
	this->baza = d.baza;
	char* temp = d.numar;
	this->numar = temp;
	d.numar = nullptr;
	d.nrcif = d.baza = 0;
}

Number::~Number()
{
	delete[] this->numar;
	this->numar = nullptr;
	this->nrcif = 0;
	this->baza = 0;
}

int value(char c)
{
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return c - '0';
}

char convert(int i)
{
	if (i <= 9)
		return i + '0';
	return i - 10 + 'A';
}

char Number::operator[](int d)
{
	return this->numar[d];
}

void Number::SwitchBase(int newBase)
{
	int i, n, val = 0, p = 1, cval;
	n = this->nrcif;
	for (i = n - 1; i >= 0; i--)
	{
		val = val + value(this->numar[i]) * p;
		p = p * this->baza;
	}
	n = 0;
	cval = val;
	if (cval == 0)
		n = 1;
	while (cval)
	{
		cval = cval / newBase;
		n++;
	}
	this->nrcif = n;
	this->baza = newBase;
	delete[] this->numar;
	this->numar = new char[n + 1];
	for (i = 0; i < n; i++)
	{
		this->numar[n - i - 1] = convert(val % newBase);
		val = val / newBase;
	}
	this->numar[n] = '\0';
}

Number& Number::operator=(const Number& d)
{
	this->nrcif = d.nrcif;
	this->baza = d.baza;
	delete[] this->numar;
	this->numar = new char[this->nrcif + 1];
	for (int i = 0; i < this->nrcif; i++)
		this->numar[i] = d.numar[i];
	this->numar[nrcif] = '\0';

	return (*this);
}

Number& Number::operator=(int d)
{
	int bs = this->baza;
	this->baza = 10;
	int k, copy = d;
	k = 0;
	if (copy == 0)
		k = 1;
	while (copy)
	{
		k++;
		copy /= 10;
	}
	this->nrcif = k;
	delete[] this->numar;
	this->numar = new char[k + 1];
	for (int i = k - 1; i >= 0; i--)
	{
		this->numar[i] = d % 10 + '0';
		d /= 10;
	}
	this->numar[k] = '\0';
	this->SwitchBase(bs);
	return(*this);
}

Number& Number::operator=(const char* number)
{
	int bs = this->baza;
	this->baza = 10;
	int i;
	i = 0;
	while (number[i] != '\0')
		i++;
	this->nrcif = i;
	delete[] this->numar;
	this->numar = new char[i + 1];
	while (i >= 0)
	{
		this->numar[i] = number[i];
		i--;
	}
	this->SwitchBase(bs);
	return (*this);
}

void Number::Add(const Number& other)
{
	int n, i, val, c, ok;
	char* str;
	Number aux = other;
	if (this->baza < other.baza)
		this->SwitchBase(other.baza);
	else if (this->baza > aux.baza)
		aux.SwitchBase(this->baza);
	if (this->nrcif > aux.nrcif)
	{
		n = this->nrcif;
		ok = 1;
	}
	else
	{
		n = aux.nrcif;
		ok = 2;
	}
	str = new char[n + 1];
	val = 0; c = 0;
	for (i = 1; i <= n; i++)
	{
		if (ok == 1)
		{
			val = value(this->numar[n - i]) + c;
			if (i <= aux.nrcif)
				val += value(aux.numar[aux.nrcif - i]);
		}
		else
		{
			val = value(aux.numar[n - i]) + c;
			if (i <= this->nrcif)
				val += value(this->numar[this->nrcif - i]);
		}
		c = val / this->baza;
		str[n + 1 - i] = convert(val % this->baza);
	}
	str[0] = c + '0';
	if (c != 0)
		n++;
	this->nrcif = n;
	delete[] this->numar;
	this->numar = new char[n + 1];
	for (i = 0; i < n; i++)
		this->numar[i] = str[i + 1 - c];
	this->numar[n] = '\0';
	delete[] str;
}

void Number::Subtract(const Number& other)
{
	int n, i, val, c, ok;
	char* str;
	Number aux = other;
	if (this->baza < other.baza)
		this->SwitchBase(other.baza);
	else if (this->baza > aux.baza)
		aux.SwitchBase(this->baza);
	n = this->nrcif;
	str = new char[n];
	val = 0; c = 0;
	for (i = 1; i <= n; i++)
	{
		val = value(this->numar[n - i]) - c;
		if (i <= aux.nrcif)
			val -= value(aux.numar[aux.nrcif - i]);
		if (val >= 0)
		{
			c = 0;
		}
		else
		{
			c = 1;
			val = this->baza - val;
		}
		str[n - i] = convert(val);
	}
	c = 0;
	if (str[0] == '0')
	{
		n--;
		c = 1;
	}
	this->nrcif = n;
	delete[] this->numar;
	this->numar = new char[n + 1];
	for (i = 0; i < n; i++)
		this->numar[i] = str[i + c];
	this->numar[n] = '\0';
	delete[] str;
}

bool Number::operator>(const Number& other)
{
	Number temp = other;
	if (this->baza != temp.baza)
		temp.SwitchBase(this->baza);
	if (this->nrcif > temp.nrcif)
		return true;
	else if (this->nrcif < temp.nrcif)
		return false;
	for (int i = 0; i < this->nrcif; i++)
		if (value(this->numar[i]) > value(temp.numar[i]))
			return true;
	return false;
}

bool Number::operator<(const Number& other)
{
	Number temp = other;
	if (this->baza != temp.baza)
		temp.SwitchBase(this->baza);
	if (this->nrcif < temp.nrcif)
		return true;
	else if (this->nrcif > temp.nrcif)
		return false;
	for (int i = 0; i < this->nrcif; i++)
		if (value(this->numar[i]) < value(temp.numar[i]))
			return true;
	return false;
}

bool Number::operator>=(const Number& other)
{
	Number temp = other;
	if (this->baza != temp.baza)
		temp.SwitchBase(this->baza);
	if (this->nrcif >= temp.nrcif)
		return true;
	else if (this->nrcif <= temp.nrcif)
		return false;
	for (int i = 0; i < this->nrcif; i++)
		if (value(this->numar[i]) >= value(temp.numar[i]))
			return true;
	return false;
}

bool Number::operator<=(const Number& other)
{
	Number temp = other;
	if (this->baza != temp.baza)
		temp.SwitchBase(this->baza);
	if (this->nrcif <= temp.nrcif)
		return true;
	else if (this->nrcif >= temp.nrcif)
		return false;
	for (int i = 0; i < this->nrcif; i++)
		if (value(this->numar[i]) <= value(temp.numar[i]))
			return true;
	return false;
}

bool Number::operator==(const Number& other)
{
	Number temp = other;
	if (this->baza != temp.baza)
		temp.SwitchBase(this->baza);
	if (this->nrcif == temp.nrcif)
		return true;
	else if (this->nrcif != temp.nrcif)
		return false;
	for (int i = 0; i < this->nrcif; i++)
		if (value(this->numar[i]) == value(temp.numar[i]))
			return true;
	return false;
}

bool Number::operator!=(const Number& other)
{
	Number temp = other;
	if (this->baza != temp.baza)
		temp.SwitchBase(this->baza);
	if (this->nrcif != temp.nrcif)
		return true;
	else if (this->nrcif == temp.nrcif)
		return false;
	for (int i = 0; i < this->nrcif; i++)
		if (value(this->numar[i]) != value(temp.numar[i]))
			return true;
	return false;
}

void Number::Print()
{
	printf("%s \n", this->numar);
}

int Number::GetDigitsCount()
{
	return this->nrcif;
}

int Number::GetBase()
{
	return this->baza;
}

Number operator+(const Number& n1, const Number& n2)
{
	Number temp = n1;
	temp.Add(n2);
	return (temp);
}

void operator+=(Number& n1, const Number& n2)
{
	n1 = n1 + n2;
}

Number operator-(const Number& n1, const Number& n2)
{
	Number temp= n1;
	temp.Subtract(n2);
	return temp;
}

void operator-=(Number& n1, const Number& n2)
{
	n1 = n1 - n2;
}
