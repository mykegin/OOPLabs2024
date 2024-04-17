#include "MovieSeries.h"
#include <stdio.h>
int MovieSeries::init()
{
	this->count = 0;
	return 0;
}

void MovieSeries::add(Movie* y)
{
	if (this->count > 16)
		return;

	Movie* temp = new Movie[count + 1];
	for (int i = 0; i < count; i++)
		temp[i] = this->film[i];
	this->film[count++] = *y;

	delete[] this->film;
	this->film = nullptr;

	this->film = temp;
}

void MovieSeries::print()
{
	int i;
	printf("%d \n", this->film[1].get_length());
	for (i = 0; i < count; i++)
		printf("%s: %d %d %d \n", this->film[i].get_name(), this->film[i].get_year(), this->film[i].get_score(), this->film[i].get_length());
}

void MovieSeries::sort()
{
	int i, j;
	for(i=0;i< this->count -1;i++)
		for (j = i + 1; j < this->count; j++)
		{
			if (2024 - this->film[i].get_year() < 2024 - this->film[j].get_year())
			{
				Movie aux=this->film[i];
				this->film[i] = this->film[j];
				this->film[j] = aux;
			}
		}
}
