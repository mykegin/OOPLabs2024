#include "NumberList.h"
void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	this->numbers[this->count++] = x;
	if (this->count > 9)
		return false;
}
void NumberList::Sort()
{
	int i, j, aux;
	for (i = 0; i < this->count - 1; i++)
		for (j = i + 1; j <= this->count - 1; j++)
			if (this->numbers[i] > this->numbers[j])
			{
				aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
}

void NumberList::Print()
{
	int i;
	for (i = 0; i < this->count; i++)
		printf("%d ", this->numbers[i]);
}
