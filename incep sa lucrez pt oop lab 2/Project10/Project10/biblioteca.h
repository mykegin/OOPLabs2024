#pragma once
#include <functional>
#include "carte.h"
using namespace std;
class biblioteca
{
private:
	int count;
	carte** carti;

public:
	biblioteca();
	~biblioteca();
	biblioteca& operator+=(carte* d);
	operator int();
	void PrintFilter( function <bool(carte*)> x);
	carte* begin() const;
	carte* end() const;
};

