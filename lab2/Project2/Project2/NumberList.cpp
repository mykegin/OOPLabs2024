#include <stdio.h>
#include "NumberList.h"

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	this->count++;
	this->numbers[this->count-1] = x;
	if (this->count >= 10)
		return false;
	else
		return true;
}

void NumberList::Sort()
{
	for(int i=0; i<this->count-1; i++)
		for(int j=i+1; j<=this->count-1; j++)
			if (this->numbers[i] > this->numbers[j])
			{
				int aux;
				aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d ", this->numbers[i]);
}
