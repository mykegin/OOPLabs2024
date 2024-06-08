#include "Sentence.h"

Sentence::Sentence(string s)
{
	this->name = s;
}

Sentence& Sentence::operator+=(Procesor* p)
{
	procesators.push_back(p);
	return (*this);
}

void Sentence::ListAll()
{
	for (auto i : procesators)
	{
		cout << "Name:" << i->GetName()<<"\n";
	}
}

void Sentence::RunAll()
{
	for (auto i : procesators)
	{
		cout << "Name:" << i->GetName() << " => "<< i->Compute(this->name)<< '\n';
	}
}

void Sentence::Run(string s)
{
	for (auto i : procesators)
	{
		if (s == i->GetName())
		{
			cout << i->Compute(this->name) << "\n";
		}
	}
}
