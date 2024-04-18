#pragma once
class Fractie
{
private:
	int numarator;
	int numitor;

public:

	Fractie(int x, int y);
	Fractie(const char* x);

	Fractie& operator- (const Fractie& x);
	Fractie& operator+ (const Fractie& x);
	Fractie& operator* (const Fractie& x);
	bool operator== (const Fractie& x);
	int operator[] (const char* value);
	void print();
};

