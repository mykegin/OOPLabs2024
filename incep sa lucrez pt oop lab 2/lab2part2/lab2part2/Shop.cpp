#include "Shop.h"

int Shop::GetTotalPrice() {
    int totalPrice = 0;
    for (auto i : articles)
    {
        totalPrice += i->GetPrice() * i->GetQuantity();
    }
    return totalPrice;
}

int Shop::GetQuantity(std::string type) {
    int totalQuantity = 0;
    for (auto i : articles)
    {
        if (i->GetType() == type)
            totalQuantity += i->GetQuantity();
    }
    return totalQuantity;
}

void Shop::List() {
    for (auto i : articles)
        i->Print();
}

Shop& Shop::Add(Article* toAdd) {
    articles.push_back(toAdd);
    return (*this);
}