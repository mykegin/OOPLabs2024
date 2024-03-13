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
	int nr, cifra, surplus=0;
	
	if (strlen(sir1) >= strlen(sir2))
	{
		lungime = strlen(sir1) + 1;
		char* sirr1 = new char[lungime];
		sirr1[0] = '0';
		for (int i = 1; i < lungime; i++)
			sirr1[i] = sir1[i - 1];
		sirr1[lungime] = '\0';
		
		int diferenta = strlen(sir1) - strlen(sir2)+1;
		char* nivelare= new char [diferenta];
		for (int i = 0; i < diferenta; i++)
			nivelare[i] = '0';
		nivelare[diferenta] = '\0';
		strcat(nivelare, sir2);

		char* resultat = new char[lungime];

		surplus = 0;
		for (int i = lungime - 1; i >= 0; i--)
			resultat[i] = '0';

		for (int i = lungime - 1; i >= 0; i--)
		{
			nr = ((sirr1[i] - '0') + (nivelare[i] - '0') + (resultat[i]-'0'));
			cifra = nr % 10;
			if (nr > 9)
				surplus = 1;
			if (surplus)
			{
				resultat[i-1] = '1';
			}
			surplus = 0;

			printf("\n");
			printf("cifra char este: %c\n", resultat[i]);
			resultat[i] = '0';
			resultat[i] = resultat[i] + cifra;

			printf("numarul este: %d\n", nr);
			printf("cifra este: %d\n", cifra);
			printf("cifra char actuala este: %c\n", resultat[i]);
			printf("cifra char la urmatorul este: %c\n", resultat[i-1]);
			printf("\n");

			if (i == 0 && resultat[0] == '0')
			{
				for (int j = 0; j <= lungime - 1; j++)
					resultat[j] = resultat[j + 1];
				lungime--;
			}

			resultat[lungime] = '\0';
		}
		return resultat;
	}
	else
	{
		lungime = strlen(sir2) + 1;
		char* sirr2 = new char[lungime];
		sirr2[0] = '0';
		for (int i = 1; i < lungime; i++)
			sirr2[i] = sir2[i - 1];
		sirr2[lungime] = '\0';

		int diferenta = strlen(sir2) - strlen(sir1) + 1;
		char* nivelare = new char[diferenta];
		for (int i = 0; i < diferenta; i++)
			nivelare[i] = '0';
		nivelare[diferenta] = '\0';
		strcat(nivelare, sir1);

		char* resultat = new char[lungime];

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

			printf("\n");
			printf("cifra char este: %c\n", resultat[i]);
			resultat[i] = '0';
			resultat[i] = resultat[i] + cifra;

			printf("numarul este: %d\n", nr);
			printf("cifra este: %d\n", cifra);
			printf("cifra char actuala este: %c\n", resultat[i]);
			printf("cifra char la urmatorul este: %c\n", resultat[i - 1]);
			printf("\n");

			if (i == 0 && resultat[0] == '0')
			{
				for (int j = 0; j <= lungime - 1; j++)
					resultat[j] = resultat[j + 1];
				lungime--;
			}

			resultat[lungime] = '\0';
		}
		return resultat;
	}
}