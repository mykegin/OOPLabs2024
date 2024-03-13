#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
#include <cstring>
int Math::Add(int x, int y)
{
	int z;
	z = x + y;
	return z;
}

int Math::Add(int x, int y, int z)
{
	int t;
	t =z + x + y;
	return t;
}

double Math::Add(double x, double y)
{
	double z;
	z = x + y;
	return z;
}

double Math::Add(double x, double y, double z)
{
	z = z + x + y;
	return z;
}

int Math::Mul(int x, int y)
{
	double z;
	z = x * y;
	return z;
}

int Math::Mul(int x, int y, int z)
{
	double t;
	t = z * x * y;
	return t;
}

double Math::Mul(double x, double y)
{
	double z;
	z = x * y;
	return z;
}

double Math::Mul(double x, double y, double z)
{
	z = z * x * y;
	return z;
}


int Math::Add(int count, ...)
{
	int i;
	double val=0;
	va_list vl;
	va_start(vl, count);
	for (i = 0; i < count; i++)
	{
		val += va_arg(vl, int);
	}
	va_end(vl);
	return val;
}

char* Math::Add(const char* sir1, const char* sir2)
{
	if (sir1 == nullptr || sir2 == nullptr)
		return nullptr;

	int lungime;
	int nr, cifra, surplus;
	
	if (strlen(sir1) > strlen(sir2))
	{
		lungime = strlen(sir1) + 1;
		int diferenta = strlen(sir1) - strlen(sir2);
		char* nivelare= new char [diferenta];
		for (int i = 0; i < diferenta; i++)
			nivelare[i] = '0';
		nivelare[diferenta] = '\0';
		strcat(nivelare, sir2);

		char* resultat = new char[lungime];

		for (int i = lungime - 1; i >= 0; i--)
		{
			int j = i - 1;
			nr = 0;
			cifra = 0;
			surplus = 0;
			resultat[i] = resultat[i - 1] = '0';
			nr = ((sir1[j] - '0') + (nivelare[j] - '0'));
			cifra = nr % 10;
			resultat[i] = resultat[i] + cifra;
			printf("cifra este: %c\n", resultat[i]);
			if (surplus)
			{
				cifra = nr % 10;
				resultat[i] = resultat[i] + nr / 10 + '0';
			}
			if (nr / 10 > 0)
				surplus = 1;
			resultat[lungime] = '\0';
		}
		return resultat;
	}
	/*else
	{
		lungime = strlen(sir2) + 1;
		int diferenta = strlen(sir1) - strlen(sir2);
		char* nivelare = new char[diferenta];
		for (int i = 0; i < diferenta; i++)
			nivelare[i] = '0';
		printf("diferenta este: %d\n", diferenta);
	}*/
}