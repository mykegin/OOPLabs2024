#ifndef NUMBER_H
#define NUMBER_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Number
{
private:
    char* value;
    int base;
    int digitsCount;

public:
    Number(const char* value, int base);
    Number(int value);
    Number(const Number& other);
    Number(Number&& other);
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other);

    friend Number operator+(const Number& num1, const Number& num2);
    friend Number operator-(const Number& num1, const Number& num2);
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;

    char& operator[](int index);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();

    Number& operator--();     // Prefix decrement
    Number operator--(int);   // Postfix decrement
};

#endif