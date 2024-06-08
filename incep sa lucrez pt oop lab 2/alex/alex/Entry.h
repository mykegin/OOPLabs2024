#pragma once
#include <iostream>
using namespace std;
#include <string>
class Entry
{
protected:
	string name;

public:
	Entry(string nume);
	virtual string GetName()=0;
	virtual void Add(string d)=0;
	virtual bool Substract(int d)=0;
	virtual void Print()=0;

};

