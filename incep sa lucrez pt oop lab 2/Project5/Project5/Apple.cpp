#include "Apple.h"

Apple::Apple(int price, int quantity, string country)
{
	this->pret = price;
	this->cantitate = quantity;
	this->provenienta = country;
}

string Apple::GetType()
{
	return "Apple";
}

int Apple::GetQuantity()
{
	return this->cantitate;
}

int Apple::GetPrice()
{
	return this->pret;
}

void Apple::Print()
{
	cout << "Apple (from=" << this->provenienta << ") Price=" << this->pret << " Quantity=" << this->cantitate << "\n";
	return;
}
