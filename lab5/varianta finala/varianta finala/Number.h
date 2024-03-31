#pragma once
class Number
{
	char* nr;
	int base, nrdig;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int number);
	Number(const char* value);
	~Number();
	Number(const Number& d);
	Number(Number&& d);

	Number& operator=(const Number& other);
	Number& operator=(Number&& d);
	Number& operator=(int number);
	Number& operator=(const char* number);

	void Add(const Number& other);
	friend Number operator+(const Number& n1, const Number& n2);
	friend void operator+=(Number& n1, const Number& n2);

	void Subtract(const Number& other);
	friend Number operator-(const Number& n1, const Number& n2);
	friend void operator-=(Number& n1, const Number& n2);

	char operator[](int index);
	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);

	void operator--();
	void operator--(int nr);
	// add operators and copy/move constructor

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};