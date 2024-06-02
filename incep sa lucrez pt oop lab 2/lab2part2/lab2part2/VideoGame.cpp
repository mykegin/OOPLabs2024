#include "VideoGame.h"
#include <iostream>

int VideoGame::GetPrice() {
    return this->price;
}

int VideoGame::GetQuantity() {
    return this->quantity;
}

std::string VideoGame::GetType() {
    return "VideoGame";
}

VideoGame::VideoGame(int p, int q, std::string plat, std::string name)
{
    this->price = p;
    this->quantity = q;
    this->platform = plat;
    this->name = name;
}

std::string VideoGame::GetName() {
    return this->name;
}

std::string VideoGame::GetPlatform() {
    return this->platform;
}

void VideoGame::Print() {
    std::cout << "VideoGame (Platform=" << this->GetPlatform() << " Name=" << this->GetName() << ") Price=" << this->GetPrice() << " Quantity=" << this->GetQuantity() << '\n';
}