#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
class Number
{
	// add data members
private:
	char* nrcurent;
	int primabaza;
	int bazacurenta;
	int nrcif = 0;

public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int nr);
	Number(const char* numarc);

	~Number();

	Number(const Number& d);
	Number(Number&& e);

	// add operators and copy/move constructor

	/*Number& operator=(const Number& altu);
	Number& operator=(int nr);
	Number& operator=(char* numaras);*/

	Number& operator=(const Number& other);
	Number& operator=(Number&& e);
	Number& operator=(int nr);
	Number& operator=(const char* numar);

	void Add(const Number& other);
	friend Number operator+(const Number& other, int nr);
	friend Number operator+(int nr, const Number& other);
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator+(const char* nr, const Number& other);

	char operator[](int index);
	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);
	void operator--();
	void operator--(int nr);

	void SwitchBase(int newBase);///done
	void Print();///done
	int  GetDigitsCount(); ///done
	int  GetBase(); ///done
	char* GetNumber();
};
