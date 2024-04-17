#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <cmath>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>  
#include <cstring>

void swap(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}

Sort::Sort(int mini, int maxi, int nrelem)
{
	srand(time(0));
	this->count = nrelem;
	this->vec = new int[nrelem + 1];
	for (int i = 0; i < nrelem; i++)
		this->vec[i] = rand() % (maxi - mini + 1) + mini;
}

Sort::Sort() : vec(new int[10] {96, 43, 21, 35, 33, 12, 78, 54, 67, 89}), count(10) {}

Sort::Sort(int nrelem, int v[])
{
	this->vec = new int[nrelem+1];
	this->count = nrelem;
	for (int i = 0; i < nrelem; i++)
		this->vec[i] = v[i];
}

Sort::Sort(int nrelem, ...)
{
	this->count = nrelem;
	this->vec = new int[this->count+1];

	va_list args;
	va_start(args, nrelem);
	for (int i = 0; i < count; i++)
		this->vec[i] = va_arg(args, int);
	va_end(args);
}

Sort::Sort(char* nr)
{
	if (nr == nullptr)
	{
		printf("Pointer is NULL!!\n");
		return;
	}

	this->count = 0;
	for (int i = 0; i < strlen(nr); i++) {
		if (nr[i] == ',')
			this->count++;
	}
	this->count++;
	this->vec = new int[this->count+1] {};

	int j = 0;
	for (int i = 0; i < strlen(nr); i++)
	{
		if (nr[i] == ',')
			j++;
		else
			this->vec[j] = this->vec[j] * 10 + (nr[i] - '0');
	}
}



void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	if (ascendent == false)
	{
		for (i = 0; i < this->count; i++)
		{
			key = this->vec[i];
			j = i - 1;
			while (j >= 0 && this->vec[j] > key) {
				this->vec[j + 1] = this->vec[j];
				j = j - 1;
			}
			this->vec[j + 1] = key;
		}
	}
}

void SortareRapida(int v[], int st, int dr)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		SortareRapida(v, st, i - 1);
		SortareRapida(v, i + 1, dr);
	}

}

void Sort::QuickSort(bool ascendent)
{
	SortareRapida(this->vec, 0, this->count - 1);
}

void Sort::BubbleSort(bool ascendent)
{
	int i, j, aux;
	bool swapped;
	for (i = 0; i < this->count - 1; i++)
	{
		swapped = false;
		for (j = 0; j < this->count - i - 1; j++)
		{
			if (this->vec[j] > this->vec[j + 1])
			{
				aux = this->vec[j];
				this->vec[j] = this->vec[j + 1];
				this->vec[j + 1] = aux;
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d ", this->vec[i]);
	printf("\n");
}

int Sort::GetElementsCount()
{
	return this->count;
}

int Sort::GetElementFromIndex(int index)
{
	if (index < this->count)
		return this->vec[index];
	else
		return -1;
}
