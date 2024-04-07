#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"


int Movie::movie_compare_name(Movie* f1, Movie* f2)
{
	return 0;
}

int Movie::movie_compare_year(Movie* f1, Movie* f2)
{
	return 0;
}

int Movie::movie_compare_score(Movie* f1, Movie* f2)
{
	return 0;
}

int Movie::movie_compare_length(Movie* f1, Movie* f2)
{
	return 0;
}

int Movie::movie_compare_passed_years(Movie* f1, Movie* f2)
{
	return 0;
}

void Movie::set_name(const char* movie_name)
{
	strcpy(this->name, movie_name);
	this->name[strlen(movie_name)] = '\0';
}

char* Movie::get_name()
{
	return this->name;
}

void Movie::set_year(int movie_year)
{
	this->releaseyear = movie_year;
}

int Movie::get_year()
{
	return this->releaseyear;
}

void Movie::set_score(double movie_score)
{
	this->IMDB = movie_score;
}

double Movie::get_score()
{
	return this->IMDB;
}

void Movie::set_length(int movie_length)
{
	this->length = movie_length;
}

int Movie::get_length()
{
	return this->length;
}

int Movie::get_passed_years()
{
	return 2024-this->releaseyear;
}









