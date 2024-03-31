#include "Number.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

Number::Number(const char* val, int base)
{
	this->nrcurent = new char[strlen(val) + 1];
	strcpy((this->nrcurent), val);
	this->primabaza = base;
	this->bazacurenta = base;
}

Number::Number(int nr)
{
	int l = 0, n, i, cnr;
	cnr = nr;
	while (cnr)
	{
		l++;
		cnr /= 10;
	}
	cnr = nr;
	this->nrcurent = new char[l + 1];
	for (i = l - 1; l >= 0; l--)
	{
		this->nrcurent[i] = cnr % 10;
		cnr /= 10;
	}
	this->nrcurent[l] = '\0';
	this->primabaza = 10;
	this->bazacurenta = 10;
	this->nrcif = l;
}

Number::Number(const char* numarc)
{
	this->nrcurent = new char[strlen(numarc) + 1];
	strcpy((this->nrcurent), numarc);
	this->primabaza = 10;
	this->bazacurenta = 10;
}

Number::~Number()
{
	delete[] this->nrcurent;
	this->nrcurent = nullptr;

	this->primabaza = this->bazacurenta = this->nrcif = 0;
}

Number::Number(const Number& d)///dau ca parametru un alt obiect
{

	this->bazacurenta = d.bazacurenta;
	this->nrcif = d.nrcif;
	this->nrcurent = new char[strlen(d.nrcurent) + 1];
	strcpy(this->nrcurent, d.nrcurent);

}

Number::Number(Number&& e)///dau un referinta(pointer constant) drept parametru
{
	this->bazacurenta = e.bazacurenta;
	this->nrcurent = new char[strlen(e.nrcurent) + 1];
	char* copie = e.nrcurent;
	this->nrcurent = copie;
	delete[] e.nrcurent;
	e.nrcurent = nullptr;
	e.bazacurenta = 0;
	e.nrcif = 0;
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
	GetDigitsCount();
	char* cuvsup = new char[this->nrcif + 1];
	cuvsup = this->nrcurent;
	int lungime = this->nrcif;
	int numar = 0;
	int p = 1;


	for (int i = lungime - 1; i >= 0; i--)
	{
		numar += val(cuvsup[i]) * p;
		p = p * this->bazacurenta;
	}


	int nrimp = 0, cn = numar;
	while (cn)
	{
		cn /= 10;
		nrimp++;
	}

	cuvsup = new char[nrimp + 1];

	for (int i = 1; i <= nrimp; i++)
	{
		cuvsup[i - 1] = reVal(numar % 10);
		numar /= 10;
	}

	for (int i = 0; i < nrimp / 2; i++)
	{
		char aux;
		aux = cuvsup[i];
		cuvsup[i] = cuvsup[nrimp - 1 - i];
		cuvsup[nrimp - 1 - i] = aux;
	}


	cuvsup[nrimp] = '\0';

	this->nrcurent = new char[nrimp + 1];
	this->nrcurent = cuvsup;

	this->nrcif = nrimp;





	if (newBase != 10)
	{

		cuvsup = new char[this->nrcif + 1];
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

		cuvsup = new char[nrimp + 1];

		for (int i = 1; i <= nrimp; i++)
		{
			cuvsup[i - 1] = reVal(numar % newBase);
			numar /= newBase;
		}


		for (int i = 0; i < nrimp / 2; i++)
		{
			char aux;
			aux = cuvsup[i];
			cuvsup[i] = cuvsup[nrimp - 1 - i];
			cuvsup[nrimp - 1 - i] = aux;
		}

		cuvsup[nrimp] = '\0';

		this->nrcurent = new char[nrimp + 1];
		this->nrcurent = cuvsup;

	}

	this->nrcif = nrimp;
	GetDigitsCount();
	this->bazacurenta = newBase;
}

bool Number::operator>(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.nrcurent > nr2.nrcurent;
}

bool Number::operator<(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.nrcurent < nr2.nrcurent;
}

bool Number::operator>=(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.nrcurent >= nr2.nrcurent;
}

bool Number::operator<=(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.nrcurent <= nr2.nrcurent;
}

bool Number::operator==(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.nrcurent == nr2.nrcurent;
}

bool Number::operator!=(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.nrcurent != nr2.nrcurent;
}

void Number::operator--()
{
	char* temp;
	temp = new char[this->nrcif + 1];
	strcpy(temp, this->nrcurent);

	delete[] this->nrcurent;
	this->nrcurent = nullptr;

	this->nrcurent = new char[this->nrcif];
	this->nrcif--;
	for (int i = 1; i <= this->nrcif; i++)
		this->nrcurent[i - 1] = temp[i];

	this->nrcurent[this->nrcif] = '\0';

	delete[] temp;
}

void Number::operator--(int nr)
{
	char* temp;
	temp = new char[this->nrcif + 1];
	strcpy(temp, this->nrcurent);

	delete[] this->nrcurent;
	this->nrcurent = nullptr;

	this->nrcurent = new char[this->nrcif];
	this->nrcif--;
	for (int i = 0; i < this->nrcif; i++)
		this->nrcurent[i] = temp[i];

	this->nrcurent[this->nrcif] = '\0';

	delete[] temp;
}

char* Number::GetNumber()
{
	return this->nrcurent;
}

int convertint(const char* nr)
{
	int n = 0;
	for (int i = 0; i < strlen(nr); i++)
		n = n * 10 + (nr[i] - '0');
	return n;
}

char* convertchar(int x)
{
	int cx = x, l = 0;
	while (cx)
		l++, cx /= 10;

	char* nr = new char[l + 1];
	for (int i = l - 1; i >= 0; i--)
		nr[i] = x % 10 + '0', x /= 10;
	nr[l] = '\0';
	return nr;
}

//Number Number::operator+(const Number& other)
//{
//	Number aux(other);
//	Number xua((*this));
//
//	int bm = aux.bazacurenta;
//	if (bm < xua.bazacurenta)
//		bm = xua.bazacurenta;
//
//	aux.SwitchBase(10);
//	xua.SwitchBase(10);
//
//	int x=convertint(aux.nrcurent);
//	int y = convertint(xua.nrcurent);
//
//	x += y;
//	int cx = x;
//	int l = 0;
//	while (cx)
//	{
//		cx /= 10;
//		l++;
//	}
//
//	delete[] aux.nrcurent;
//	aux.nrcurent = nullptr;
//
//	aux.nrcurent = new char[l + 1];
//	strcpy(aux.nrcurent, convertchar(x));
//
//	aux.SwitchBase(bm);
//
//	return aux;
//}

void Number::Add(const Number& other)
{
	int n, i, vali, c, ok;
	char* str;
	Number aux = other;
	if (this->bazacurenta < other.bazacurenta)
		this->SwitchBase(other.bazacurenta);
	else if (this->bazacurenta > aux.bazacurenta)
		aux.SwitchBase(this->bazacurenta);
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
	vali = 0; c = 0;
	for (i = 1; i <= n; i++)
	{
		if (ok == 1)
		{
			vali = val(this->nrcurent[n - i]) + c;
			if (i <= aux.nrcif)
				vali += val(aux.nrcurent[aux.nrcif - i]);
		}
		else
		{
			vali = val(aux.nrcurent[n - i]) + c;
			if (i <= this->nrcif)
				vali += val(this->nrcurent[this->nrcif - i]);
		}
		c = vali / this->bazacurenta;
		str[n + 1 - i] = reVal(vali % this->bazacurenta);
	}
	str[0] = c + '0';
	if (c != 0)
		n++;
	this->nrcif = n;
	delete[] this->nrcurent;
	this->nrcurent = new char[n + 1];
	for (i = 0; i < n; i++)
		this->nrcurent[i] = str[i + 1 - c];
	this->nrcurent[n] = '\0';
	delete[] str;
}

Number operator+(const Number& n1, const Number& n2)
{
	Number temp = n1;
	temp.Add(n2);
	return (temp);
}

char Number::operator[](int index)
{
	return this->nrcurent[index];
}

Number& Number::operator=(const Number& other)
{

	delete[] nrcurent;
	nrcurent = nullptr;

	bazacurenta = other.bazacurenta;
	nrcif = other.nrcif;
	nrcurent = new char[nrcif + 1];
	strcpy(nrcurent, other.nrcurent);

	return (*this);
}

Number& Number::operator=(int nr)
{
	int cnr = nr;
	int l = 0;
	if (cnr == 0)
		l = 1;

	while (cnr)
	{
		l++;
		cnr /= 10;
	}

	cnr = nr;
	delete[] this->nrcurent;
	this->nrcurent = nullptr;
	this->nrcif = l;
	this->bazacurenta = 10;
	this->nrcurent = new char[l + 1];
	for (int i = l - 1; i >= 0; i--)
	{
		this->nrcurent[i] = cnr % 10 + '0';
		cnr /= 10;
	}

	this->nrcurent[l] = '\0';
	printf("nrcurent este: %s \n \n \n", this->nrcurent);

	return *this;
}

Number& Number::operator=(const char* numar)
{
	int l = strlen(numar);
	delete[] this->nrcurent;
	this->nrcurent = nullptr;
	this->nrcif = l;
	this->bazacurenta = 10;
	this->nrcurent = new char[l + 1];
	for (int i = l - 1; i >= 0; i--)
	{
		this->nrcurent[i] = numar[i];
	}

	this->nrcurent[l] = '\0';
	printf("nrcurent este: %s \n \n \n", this->nrcurent);

	return *this;
}

/*void Number::Add(const Number& other)
{
		if (this->nrcurent == nullptr || other.nrcurent == nullptr)
			return;

		int lungime;
		int nr, cifra, surplus = 0;

		if (strlen(this->nrcurent) >= strlen(other.nrcurent))
		{
			lungime = strlen(this->nrcurent) + 1;
			char* sirr1 = new char[lungime+1];
			sirr1[0] = '0';
			for (int i = 1; i < lungime; i++)
				sirr1[i] = this->nrcurent[i - 1];
			sirr1[lungime] = '\0';

			int diferenta = strlen(this->nrcurent) - strlen(other.nrcurent) + 1;
			char* nivelare = new char[diferenta+1];
			for (int i = 0; i < diferenta; i++)
				nivelare[i] = '0';
			nivelare[diferenta] = '\0';
			strcat(nivelare, other.nrcurent);

			char* resultat = new char[lungime+1];

			surplus = 0;
			for (int i = lungime - 1; i >= 0; i--)
				resultat[i] = '0';

			for (int i = lungime - 1; i >= 0; i--)
			{
				nr = ((sirr1[i] - '0') + (nivelare[i] - '0') + (resultat[i] - '0'));
				cifra = nr % 10;
				if (nr > 9)
					surplus = 1;
				if (surplus)
				{
					resultat[i - 1] = '1';
				}
				surplus = 0;
				resultat[i] = '0';
				resultat[i] = resultat[i] + cifra;

				if (i == 0 && resultat[0] == '0')
				{
					for (int j = 0; j <= lungime - 1; j++)
						resultat[j] = resultat[j + 1];
					lungime--;
				}

				resultat[lungime] = '\0';
			}
			delete[] this->nrcurent;
			this->nrcurent = nullptr;
			this->nrcurent = new char[strlen(resultat) + 1];
			this->nrcurent = resultat;
			this->nrcif = lungime;
		}
		else
		{
			lungime = strlen(other.nrcurent) + 1;
			char* sirr2 = new char[lungime+1];
			sirr2[0] = '0';
			for (int i = 1; i < lungime; i++)
				sirr2[i] = other.nrcurent[i - 1];
			sirr2[lungime] = '\0';

			int diferenta = strlen(other.nrcurent) - strlen(this->nrcurent) + 1;
			char* nivelare = new char[diferenta+1];
			for (int i = 0; i < diferenta; i++)
				nivelare[i] = '0';
			nivelare[diferenta] = '\0';
			strcat(nivelare, this->nrcurent);

			char* resultat = new char[lungime+1];

			surplus = 0;
			for (int i = lungime - 1; i >= 0; i--)
				resultat[i] = '0';

			for (int i = lungime - 1; i >= 0; i--)
			{
				nr = ((sirr2[i] - '0') + (nivelare[i] - '0') + (resultat[i] - '0'));
				cifra = nr % 10;
				if (nr > 9)
					surplus = 1;
				if (surplus)
				{
					resultat[i - 1] = '1';
				}
				surplus = 0;
				resultat[i] = '0';
				resultat[i] = resultat[i] + cifra;

				if (i == 0 && resultat[0] == '0')
				{
					for (int j = 0; j <= lungime - 1; j++)
						resultat[j] = resultat[j + 1];
					lungime--;
				}

				resultat[lungime] = '\0';
			}

			delete[] this->nrcurent;
			this->nrcurent = nullptr;
			this->nrcurent = new char[strlen(resultat) + 1];
			this->nrcurent = resultat;
			this->nrcif = lungime;
		}

}
*/

Number& Number::operator=(Number&& e)
{
	this->bazacurenta = e.bazacurenta;
	this->nrcurent = new char[strlen(e.nrcurent) + 1];
	this->nrcif = e.nrcif;
	char* copie = e.nrcurent;
	this->nrcurent = copie;
	delete[] e.nrcurent;
	e.nrcurent = nullptr;
	e.bazacurenta = 0;
	e.nrcif = 0;

	return (*this);
}

/*Number operator+(const Number& other, int nr)
{

	Number var(other);
	int bm = var.bazacurenta;
	if (bm < 10)
		bm = 10;


}*/




/*Number operator+(int nr, const Number& other)
{
	///return Number();
}
*/


