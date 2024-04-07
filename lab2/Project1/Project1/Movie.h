#include <iostream>
#include <stdlib.h>
#include <cmath>

#pragma once
class Movie
{
	char name[256];
	double IMDB;
	int length;
	const int actualyear = 2024;
	int releaseyear;

public:

	void set_name(const char* movie_name);
	char* get_name();
	void set_year(int movie_year);
	int get_year();
	void set_score(double movie_score);
	double get_score();
	void set_length(int movie_length);
	int get_length();
	int get_passed_years();

	int movie_compare_name(Movie* f1, Movie* f2);
	int movie_compare_year(Movie* f1, Movie* f2);
	int movie_compare_score(Movie* f1, Movie* f2);
	int movie_compare_length(Movie* f1, Movie* f2);
	int movie_compare_passed_years(Movie* f1, Movie* f2);
};

