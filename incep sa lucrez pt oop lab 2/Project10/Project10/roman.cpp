#include "roman.h"
#include <string>
using namespace std;

roman::roman(string nume, string autor)
{
	this->nume = nume;
	this->autor = autor;
}

string roman::GetInfo()
{
	return "Roman " + this->nume + " de " + this->autor;
}
