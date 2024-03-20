#include "Sorti.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

Sorti::Sorti(int nrelem, int mini, int maxi)
{
    srand(time(NULL));
	this->nr = nrelem;
	this->lista = new int[nrelem];
	for (int i = 0; i < this->nr; i++)
		this->lista[i] = rand() % (maxi-mini) + mini;
}

void Sorti::InsertSort(bool ascendent)
{
	int i, key, j;
    for (i = 0; i < this->nr; i++) 
    {
        key = this->lista[i];
        j = i - 1;
        while (j >= 0 && this->lista[j] > key) {
            this->lista[j+1] = this->lista[j];
            j = j - 1;
        }
        this->lista[j+1] = key;
    }
}

/*
void::QuickSort(bool ascendent)
{
	int st = 0, dr = (this->nr) - 1;
	if (st < dr)
	{
		//pivotul este ini?ial v[st]
		int m = (st + dr) / 2;
		int aux = this->lista[st];
		this -> lista[st] = this -> lista[m];
		this -> lista[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (this -> lista[i] > this -> lista[j])
			{
				aux = this->lista[i];
				this->lista[i] = this->lista[j];
				this->lista[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(this->lista, st, i - 1);
		QuickSort(this->lista, i + 1, dr);
	}
}
*/

void Sorti::BubbleSort(bool ascendent)
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

void Sorti::Print()
{
	for (int i = 0; i < this->nr; i++)
		printf("%d ", this->lista[i]);
}