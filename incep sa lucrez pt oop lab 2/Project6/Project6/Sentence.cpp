#include "Sentence.h"

Sentence::Sentence(string s)
{
	this->name = s;
}

void Sentence::RunAll()
{
	for (auto i : procesator)
		cout << "Name:" << i->GetName() <<" => "<<i->Compute(i->GetName()) << "\n";
	return;
}

void Sentence::ListAll()
{
	for (auto i : procesator)
		cout << "Name:" << i->GetName()<<"\n";
	return;
}

void Sentence::Run(string p)
{
	for (auto i : procesator)
		if (p == i->GetName())
			cout << i->Compute(p);
	return;
}

Sentence& Sentence::operator+=(Procesor* p)
{
	procesator.push_back(p);
	return(*this);
}
