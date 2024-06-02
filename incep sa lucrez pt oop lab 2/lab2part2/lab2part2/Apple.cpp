#include "Apple.h"
#include <iostream>

int Apple::GetPrice() {
    return this->price;
}

int Apple::GetQuantity() {
    return this->quantity;
}

std::string Apple::GetType() {
    return "Apple";
}

Apple::Apple(int p, int q, std::string c) {
    this->price = p;
    this->quantity = q;
    this->country = c;
}

std::string Apple::GetCountry() {
    return this->country;
}
void Apple::Print() {
    std::cout << "Apple (from=" << this->GetCountry() << ") Price=" << this->GetPrice() << " Quantity=" << this->GetQuantity() << '\n';
}