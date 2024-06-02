#pragma once
#include <vector>
#include "Article.h"

using namespace std;

class Shop
{
private:
    vector<Article*> articles;
public:
    Shop& Add(Article*);
    int GetTotalPrice();
    int GetQuantity(std::string);
    void List();
};