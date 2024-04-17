#pragma once
class Number
{
	char* numar;
	int baza;
	int nrcif;

public:
	Number(const char* value, int base); // where base is between 2 and 16

	Number(const Number& d);
	Number(Number&& d);

	~Number();

	// add operators and copy/move constructor

	Number& operator = (const Number& d);
	Number& operator = (int d);
	Number& operator=(const char* number);

	void Add(const Number& other);
	friend Number operator+(const Number& n1, const Number& n2);
	friend void operator+=(Number& n1, const Number& n2);

	void Subtract(const Number& other);
	friend Number operator-(const Number& n1, const Number& n2);
	friend void operator-=(Number& n1, const Number& n2);

	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);

	char operator[] (int d);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

