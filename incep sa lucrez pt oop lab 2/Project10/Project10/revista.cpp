#include "revista.h"

revista::revista(string titlu, int nrArticole)
{
	this->titlu = titlu;
	this->nrArticole = nrArticole;
}

string revista::GetInfo()
{
	return "Revista " + this->titlu + " cu " + to_string(this->nrArticole) + " articole";
}
