#include "biblioteca.h"
#include <iostream>
using namespace std;

biblioteca::biblioteca()
{
	this->count = 0;
	carti = new carte * [100];
}

biblioteca::~biblioteca()
{
	this->count = 0;
	carti = new carte * [100];
}

biblioteca& biblioteca::operator+=(carte* d)
{
	carti[count] = d;
	count++;
	return (*this);
}

biblioteca::operator int()
{
	return this->count;
}

void biblioteca::PrintFilter(function<bool(carte*)> x)
{
	int i;
	for (i = 0; i < count; i++)
		if (x(carti[i]))
			cout << carti[i]->GetInfo() << '\n';
}

carte* biblioteca::begin() const
{
	return carti[0];
}
carte* biblioteca::end() const
{
	return carti[count - 1];
}
