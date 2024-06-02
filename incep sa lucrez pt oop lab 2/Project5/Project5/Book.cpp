#include "Book.h"

Book::Book(int price, int quantity, string name, string author)
{
	this->pret = price;
	this->cantitate = quantity;
	this->nume = name;
	this->autor = author;
}

string Book::GetType()
{
	return "Book";
}

int Book::GetQuantity()
{
	return this->cantitate;
}

int Book::GetPrice()
{
	return this->pret;
}

void Book::Print()
{
	cout << "Book (Title=" << this->nume << ", Autor=" << this->autor << ") Price=" << this->pret << " Quanitity=" << this->cantitate << "\n";
	return;
}
