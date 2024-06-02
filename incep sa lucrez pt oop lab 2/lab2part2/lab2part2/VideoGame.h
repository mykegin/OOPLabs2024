#pragma once
#include <string>
#include "Article.h"
class VideoGame : public Article
{
private:
    int price, quantity;
    std::string platform;
    std::string name;
public:
    //constructor
    VideoGame(int, int, std::string, std::string);

    //methods
    std::string GetType();
    std::string GetPlatform();
    std::string GetName();
    int GetQuantity();
    int GetPrice();
    void Print();
};