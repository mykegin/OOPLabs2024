#pragma once
#include <string>
#include "Article.h"
class Book : public Article
{
private:
    int price, quantity;
    std::string author;
    std::string title;
public:
    //constructor
    Book(int, int, std::string, std::string);

    //methods
    std::string GetType();
    std::string GetTitle();
    std::string GetAuthor();
    int GetQuantity();
    int GetPrice();
    void Print();
};