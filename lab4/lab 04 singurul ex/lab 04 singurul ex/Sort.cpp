#include "Sort.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

Sort::Sort(int nrelem, int mini, int maxi)
{
    srand(time(NULL));
	this->nr = nrelem;
	this->lista = new int[nrelem];
	for (int i = 0; i < this->nr; i++)
		this->lista[i] = rand() % (maxi-mini) + mini;
}

Sort::Sort() : lista(new int[8] {96, 43, 21, 35, 33, 12, 78, 64}) 
{
	this->nr = 8;
}

Sort::Sort(int vectoras[], int nrelem)
{
	this->nr = nrelem;
	this->lista = new int[nrelem];
	for (int i = 0; i < this->nr; i++)
		this->lista[i] = this->vectorsort3[i];
}

Sort::Sort(int count, ...)
{
	this->lista = new int[count];
	this->nr = count;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		this-> lista[i] = va_arg(vl, int);
	}
	va_end(vl);
}

Sort::Sort(const char* c)
{
	int i=0;
	int n=0;
	this->nr = 0;
	this->lista = new int[strlen(c)];
	while (c[i] != NULL)
	{
		if (c[i] >= '0' && c[i] <= '9')
			n = n * 10 + (c[i] - '0');
		else
		{
			this->lista[this->nr] = n;
			this->nr++;
			n = 0;
		}
		i++;
	}
	printf("%s \n", c);
	for (i = 0; i < this->nr; i++)
		printf("%d ", this -> lista[i]);
	printf("\n");
}

int Sort::GetElementsCount()
{
	return this->nr;
}

int Sort::GetElementFromIndex(int index)
{
	if (index < this->nr)
		return this->lista[index];
	else
		return -1;
}

void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	if (ascendent == false)
	{
		for (i = 0; i < this->nr; i++)
		{
			key = this->lista[i];
			j = i - 1;
			while (j >= 0 && this->lista[j] > key) {
				this->lista[j + 1] = this->lista[j];
				j = j - 1;
			}
			this->lista[j + 1] = key;
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
	SortareRapida(this->lista, 0, this->nr - 1);
}


void Sort::BubbleSort(bool ascendent)
{
	int i, j, aux;
	bool swapped;
	for (i = 0; i < this->nr - 1; i++) 
	{
		swapped = false;
		for (j = 0; j < this->nr - i - 1; j++) 
		{
			if (this->lista[j] > this->lista[j + 1]) 
			{
				aux = this->lista[j];
				this->lista[j] = this -> lista[j+1];
				this->lista[j+1] = aux;
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->nr; i++)
		printf("%d ", this->lista[i]);
	printf("\n");
}