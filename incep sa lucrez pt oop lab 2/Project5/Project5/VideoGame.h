#pragma once
#include "Article.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class VideoGame : public Article
{
private:

	int pret;
	int cantitate;
	string producator;
	string numejoc;


public:

	VideoGame(int price, int quantity, string producer, string game);

	virtual string GetType();
	virtual int GetQuantity();
	virtual int GetPrice();
	virtual void Print();
};

