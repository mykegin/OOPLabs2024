#pragma once
#include "Article.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class Shop
{
private:
	vector <Article*> items;

public:
	Shop& Add( Article* p );
	int GetTotalPrice();
	int GetQuantity( const string p);
	void List();
};

