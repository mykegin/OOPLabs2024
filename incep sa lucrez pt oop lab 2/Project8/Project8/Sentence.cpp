#include "Sentence.h"
#include <iostream>

Sentence::Sentence(string s)
{
	this->name = s;
}
void Sentence::RunAll()
{
	for (auto i : procesator)
	{
		cout << "Name: " << i->GetName() << " => " << i->Compute(name) << '\n';
	}
}
void Sentence::ListAll()
{
	for (auto i : procesator)
	{
		cout << "Name: " << i->GetName() << '\n';
	}
}
void Sentence::Run(string s)
{
	for (auto i : procesator)
		if (i->GetName() == s)
			cout << i->Compute(name) << '\n';
}
Sentence& Sentence::operator +=(Procesor* p)
{
	procesator.push_back(p);
	return (*this);
}