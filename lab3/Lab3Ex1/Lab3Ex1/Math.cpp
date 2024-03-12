#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
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

/*
char* Math::Add(const char*, const char*)
{

}
*/