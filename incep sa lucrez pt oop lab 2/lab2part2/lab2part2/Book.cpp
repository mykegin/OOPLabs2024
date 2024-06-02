#include "Book.h"
#include <iostream>

int Book::GetPrice() {
    return this->price;
}

int Book::GetQuantity() {
    return this->quantity;
}

std::string Book::GetType() {
    return "Book";
}

Book::Book(int p, int q, std::string t, std::string a) {
    this->price = p;
    this->quantity = q;
    this->author = a;
    this->title = t;
}

std::string Book::GetAuthor() {
    return this->author;
}

std::string Book::GetTitle() {
    return this->title;
}

void Book::Print()
{
    std::cout << "Book (Title=" << this->GetTitle() << " Author=" << this->GetAuthor() << ") Price=" << this->GetPrice() << " Quantity=" << this->GetQuantity() << '\n';
}