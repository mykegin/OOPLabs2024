#pragma once
#include "Article.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Apple: public Article
{
private:

	int pret;
	int cantitate;
	string provenienta;


public:

	Apple(int price, int quantity, string country);

	virtual string GetType();
	virtual int GetQuantity();
	virtual int GetPrice();
	virtual void Print();
};

