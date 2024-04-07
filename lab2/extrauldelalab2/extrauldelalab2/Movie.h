#pragma once
class Movie
{
	char nume[256];
	int anlansare;
	double IMDB;
	int lungime;

public:
	void set_name(const char* x);
	const char* get_name() const;
	void set_year(int an);
	int get_year() const;
	void set_score(int x);
	int get_score() const;
	void set_length(int x);
	int get_length() const;

};

