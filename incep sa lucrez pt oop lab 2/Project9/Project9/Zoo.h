#pragma once
#include "Feline.h"
#include "Animal.h"
#include <vector>
#include <string>
using namespace std;
class Zoo
{

private:

	vector <Animal*> animals;

public:

	vector<Animal*> GetFishes();
	vector<Animal*> GetBirds();
	vector<Animal*> GetMammals();
	vector<Feline*> GetFelines();
	int GetTotalAnimals();
	void operator += (Animal*);
	bool operator () (string name);
};

