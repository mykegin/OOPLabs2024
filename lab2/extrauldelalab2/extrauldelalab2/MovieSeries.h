#pragma once
#include "Movie.h"
class MovieSeries
{
	Movie* film;
	int count = 0;
public:
	int init();
	void add(Movie* y);
	void print();
	void sort();
};

