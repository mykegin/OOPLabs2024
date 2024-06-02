#include "Shop.h"

Shop& Shop::Add(Article* p)
{
	items.push_back(p);
	return (*this);
}

int Shop::GetTotalPrice()
{
	int pt = 0;
	for (auto i : items)
		pt += i->GetPrice()*i->GetQuantity();
	return pt;
}

int Shop::GetQuantity(const string p)
{
	int qt = 0;
	for (auto i : items)
		if(i->GetType()==p)
		qt += i->GetQuantity();
	return qt;
}

void Shop::List()
{
	for (auto i : items)
		i->Print();
	return;
}
