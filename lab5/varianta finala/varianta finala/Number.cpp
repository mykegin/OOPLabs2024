#include "Number.h"
#include "stdio.h"
Number::Number(const char* value, int base)
{
	int i;
	i = 0;
	while (value[i] != '\0')
		i++;
	this->nrdig = i;
	this->nr = new char[i + 1];
	while (i >= 0)
	{
		this->nr[i] = value[i];
		i--;
	}
	this->base = base;
}

Number::Number(int number)
{
	this->base = 10;
	int k, copy = number;
	k = 0;
	if (copy == 0)
		k = 1;
	while (copy)
	{
		k++;
		copy /= 10;
	}
	this->nrdig = k;
	this->nr = new char[k + 1];
	for (int i = k - 1; i >= 0; i--)
	{
		this->nr[i] = number % 10 + '0';
		number /= 10;
	}
	this->nr[k] = '\0';
}

Number::Number(const char* value)
{
	this->base = 10;
	int i;
	i = 0;
	while (value[i] != '\0')
		i++;
	this->nrdig = i;
	this->nr = new char[i + 1];
	while (i >= 0)
	{
		this->nr[i] = value[i];
		i--;
	}
}

Number::~Number()
{
	delete[] nr;
	this->nr = nullptr;
	this->base = this->nrdig = 0;
}

Number::Number(const Number& d)
{
	this->nrdig = d.nrdig;
	this->base = d.base;
	this->nr = new char[this->nrdig + 1];
	for (int i = 0; i <= this->nrdig; i++)
		this->nr[i] = d.nr[i];
}

Number::Number(Number&& d)
{
	this->nrdig = d.nrdig;
	this->base = d.base;
	this->nr = new char[this->nrdig + 1];
	for (int i = 0; i <= this->nrdig; i++)
		this->nr[i] = d.nr[i];
	delete[] d.nr;
	d.nr = nullptr;
	d.nrdig = d.base = 0;
}

Number& Number::operator=(const Number& other)
{
	this->nrdig = other.nrdig;
	this->base = other.base;
	delete[] this->nr;
	this->nr = new char[this->nrdig + 1];
	for (int i = 0; i <= this->nrdig; i++)
		this->nr[i] = other.nr[i];
	return(*this);
}

Number& Number::operator=(Number&& d)
{
	this->nrdig = d.nrdig;
	this->base = d.base;
	delete[] this->nr;
	this->nr = new char[this->nrdig + 1];
	for (int i = 0; i <= this->nrdig; i++)
		this->nr[i] = d.nr[i];
	delete[] d.nr;
	d.nr = nullptr;
	d.nrdig = d.base = 0;
	return (*this);
}

Number& Number::operator=(int number)
{
	int bs = this->base;
	this->base = 10;
	int k, copy = number;
	k = 0;
	if (copy == 0)
		k = 1;
	while (copy)
	{
		k++;
		copy /= 10;
	}
	this->nrdig = k;
	delete[] this->nr;
	this->nr = new char[k + 1];
	for (int i = k - 1; i >= 0; i--)
	{
		this->nr[i] = number % 10 + '0';
		number /= 10;
	}
	this->nr[k] = '\0';
	this->SwitchBase(bs);
	return(*this);
}

Number& Number::operator=(const char* number)
{
	int bs = this->base;
	this->base = 10;
	int i;
	i = 0;
	while (number[i] != '\0')
		i++;
	this->nrdig = i;
	delete[] this->nr;
	this->nr = new char[i + 1];
	while (i >= 0)
	{
		this->nr[i] = number[i];
		i--;
	}
	this->SwitchBase(bs);
	return (*this);
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

void Number::SwitchBase(int newBase)
{
	int i, n, val = 0, p = 1, cval;
	n = this->nrdig;
	for (i = n - 1; i >= 0; i--)
	{
		val = val + value(this->nr[i]) * p;
		p = p * this->base;
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
	this->nrdig = n;
	this->base = newBase;
	delete[] this->nr;
	this->nr = new char[n + 1];
	for (i = 0; i < n; i++)
	{
		this->nr[n - i - 1] = convert(val % newBase);
		val = val / newBase;
	}
	this->nr[n] = '\0';
}

void Number::Print()
{
	printf("%s \n", this->nr);
}

int Number::GetDigitsCount()
{
	return this->nrdig;
}

int Number::GetBase()
{
	return this->base;
}

void Number::Add(const Number& other)
{
	int n, i, val, c, ok;
	char* str;
	Number aux = other;
	if (this->base < other.base)
		this->SwitchBase(other.base);
	else if (this->base > aux.base)
		aux.SwitchBase(this->base);
	if (this->nrdig > aux.nrdig)
	{
		n = this->nrdig;
		ok = 1;
	}
	else
	{
		n = aux.nrdig;
		ok = 2;
	}
	str = new char[n + 1];
	val = 0; c = 0;
	for (i = 1; i <= n; i++)
	{
		if (ok == 1)
		{
			val = value(this->nr[n - i]) + c;
			if (i <= aux.nrdig)
				val += value(aux.nr[aux.nrdig - i]);
		}
		else
		{
			val = value(aux.nr[n - i]) + c;
			if (i <= this->nrdig)
				val += value(this->nr[this->nrdig - i]);
		}
		c = val / this->base;
		str[n + 1 - i] = convert(val % this->base);
	}
	str[0] = c + '0';
	if (c != 0)
		n++;
	this->nrdig = n;
	delete[] this->nr;
	this->nr = new char[n + 1];
	for (i = 0; i < n; i++)
		this->nr[i] = str[i + 1 - c];
	this->nr[n] = '\0';
	delete[] str;
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

void Number::Subtract(const Number& other)
{
	int n, i, val, c, ok;
	char* str;
	Number aux = other;
	if (this->base < other.base)
		this->SwitchBase(other.base);
	else if (this->base > aux.base)
		aux.SwitchBase(this->base);
	n = this->nrdig;
	str = new char[n];
	val = 0; c = 0;
	for (i = 1; i <= n; i++)
	{
		val = value(this->nr[n - i]) - c;
		if (i <= aux.nrdig)
			val -= value(aux.nr[aux.nrdig - i]);
		if (val >= 0)
		{
			c = 0;
		}
		else
		{
			c = 1;
			val = this->base - val;
		}
		str[n - i] = convert(val);
	}
	c = 0;
	if (str[0] == '0')
	{
		n--;
		c = 1;
	}
	this->nrdig = n;
	delete[] this->nr;
	this->nr = new char[n + 1];
	for (i = 0; i < n; i++)
		this->nr[i] = str[i + c];
	this->nr[n] = '\0';
	delete[] str;
}

Number operator-(const Number& n1, const Number& n2)
{
	Number temp(n1);
	if (temp < n2)
	{
		printf("ERROR! You tried to subtract a bigger number %s from a smaller one %s, we swapped their places\n", n2.nr, n1.nr);
		temp = n2;
		temp.Subtract(n1);
		return temp;
	}
	temp.Subtract(n2);
	return (temp);
}

void operator-=(Number& n1, const Number& n2)
{
	n1 = n1 - n2;
}

char Number::operator[](int index)
{
	return this->nr[index];
}

bool Number::operator>(const Number& other)
{
	Number temp = other;
	if (this->base != temp.base)
		temp.SwitchBase(this->base);
	if (this->nrdig > temp.nrdig)
		return true;
	else if (this->nrdig < temp.nrdig)
		return false;
	for (int i = 0; i < this->nrdig; i++)
		if (value(this->nr[i]) > value(temp.nr[i]))
			return true;
	return false;
}

bool Number::operator<(const Number& other)
{
	Number temp = other;
	if (this->base != temp.base)
		temp.SwitchBase(this->base);
	if (this->nrdig < temp.nrdig)
		return true;
	else if (this->nrdig > temp.nrdig)
		return false;
	for (int i = 0; i < this->nrdig; i++)
		if (value(this->nr[i]) < value(temp.nr[i]))
			return true;
	return false;
}

bool Number::operator>=(const Number& other)
{
	Number temp = other;
	if (this->base != temp.base)
		temp.SwitchBase(this->base);
	if (this->nrdig > temp.nrdig)
		return true;
	else if (this->nrdig < temp.nrdig)
		return false;
	for (int i = 0; i < this->nrdig; i++)
		if (value(this->nr[i]) < value(temp.nr[i]))
			return false;
	return true;

}

bool Number::operator<=(const Number& other)
{
	Number temp = other;
	if (this->base != temp.base)
		temp.SwitchBase(this->base);
	if (this->nrdig < temp.nrdig)
		return true;
	else if (this->nrdig > temp.nrdig)
		return false;
	for (int i = 0; i < this->nrdig; i++)
		if (value(this->nr[i]) > value(temp.nr[i]))
			return false;
	return true;
}

bool Number::operator==(const Number& other)
{
	Number temp = other;
	if (this->base != temp.base)
		temp.SwitchBase(this->base);
	if (this->nrdig != temp.nrdig)
		return false;
	for (int i = 0; i < this->nrdig; i++)
		if (value(this->nr[i]) != value(temp.nr[i]))
			return false;
	return true;
}

bool Number::operator!=(const Number& other)
{
	Number temp = other;
	if (this->base != temp.base)
		temp.SwitchBase(this->base);
	if (this->nrdig != temp.nrdig)
		return true;
	for (int i = 0; i < this->nrdig; i++)
		if (value(this->nr[i]) != value(temp.nr[i]))
			return true;
	return false;
}

void Number::operator--()
{
	int i;
	char* temp;
	temp = new char[this->nrdig];
	for (i = 0; i < this->nrdig; i++)
		temp[i] = this->nr[i];

	delete[] this->nr;

	this->nr = new char[this->nrdig];
	this->nrdig--;
	for (i = 1; i <= this->nrdig; i++)
		this->nr[i - 1] = temp[i];
	this->nr[this->nrdig] = '\0';
	delete[] temp;
}

void Number::operator--(int nr)
{
	int i;
	char* temp;
	temp = new char[this->nrdig];
	for (i = 0; i < this->nrdig; i++)
		temp[i] = this->nr[i];

	delete[] this->nr;

	this->nr = new char[this->nrdig];
	this->nrdig--;
	for (i = 0; i < this->nrdig; i++)
		this->nr[i] = temp[i];
	this->nr[this->nrdig] = '\0';
	delete[] temp;
}

