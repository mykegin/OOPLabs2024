#pragma once
#include <string>
#include "Article.h"
class Apple : public Article
{
private:
    int price, quantity;
    std::string country;
public:
    //constructor
    Apple(int, int, std::string);

    //methods
    std::string GetType();
    int GetQuantity();
    std::string GetCountry();
    int GetPrice();
    void Print();
};