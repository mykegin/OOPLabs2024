#include "Zoo.h"

vector<Animal*> Zoo::GetFishes()
{
    vector<Animal*> retur;
    for (auto i : animals)
    {
        if (i->IsAFish() == true)
            retur.push_back(i);
    }
    return retur;
}

vector<Animal*> Zoo::GetBirds()
{
    vector<Animal*> retur;
    for (auto i : animals)
    {
        if (i->IsABird() == true)
            retur.push_back(i);
    }
    return retur;
}

vector<Animal*> Zoo::GetMammals()
{
    vector<Animal*> retur;
    for (auto i : animals)
    {
        if (i->IsAMammal() == true)
            retur.push_back(i);
    }
    return retur;
}

vector<Feline*> Zoo::GetFelines()
{
    vector<Feline*> toReturn;
    for (auto i : animals)
        if (i->GetName() == "Tiger" || i->GetName() == "Lion")
            toReturn.push_back((Feline*)(i));

    return toReturn;
}

int Zoo::GetTotalAnimals()
{
    int k = 0;
    for (auto i : animals)
        k++;
    return k;
}

void Zoo::operator+=(Animal* p)
{
    animals.push_back(p);
}

bool Zoo::operator()(string name)
{
    for (auto i : animals)
        if (i->GetName() == name) 
            return true;
    return false;
}
