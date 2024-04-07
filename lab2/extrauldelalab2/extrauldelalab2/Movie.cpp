#include "Movie.h"

int GetLength(const char* string)
{
	int length = 0;
	for (int i = 0; string[i] != '\0'; i++)
		length++;
	return length;
}

void Movie::set_name(const char* x)
{
	int n = GetLength(x);
	for (int i = 0; i <= GetLength(x); i++)
		this->nume[i] = x[i];
	nume[GetLength(x)] = '\0';
}

const char* Movie::get_name() const
{
	return this->nume;
}

void Movie::set_year(int an)
{
	this->anlansare = an;
}

int Movie::get_year() const
{
	return this->anlansare;
}

void Movie::set_score(int x)
{
	this->IMDB = x;
}

int Movie::get_score() const
{
	return this->IMDB;
}

void Movie::set_length(int x)
{
	this->lungime = x;
}

int Movie::get_length() const
{
	return this->lungime;
}
