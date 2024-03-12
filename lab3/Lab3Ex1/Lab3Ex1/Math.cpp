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

int Math::Add(double x, double y)
{
	double z;
	z = x + y;
	return z;
}

int Math::Add(double x, double y, double z)
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

int Math::Mul(double x, double y)
{
	double z;
	z = x * y;
	return z;
}

int Math::Mul(double x, double y, double z)
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

	int lungime = strlen(sir1) + strlen(sir2) + 1;
	char* result = new char[lungime];

	strcpy_s(result, lungime, sir1);
	strcat_s(result, lungime, sir2);

	return result;
}