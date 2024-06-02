#pragma once
#include "Article.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class Book : public Article
{
private:

	int pret;
	int cantitate;
	string nume;
	string autor;


public:

	Book(int price, int quantity, string name, string author);

	virtual string GetType();
	virtual int GetQuantity();
	virtual int GetPrice();
	virtual void Print();
};

