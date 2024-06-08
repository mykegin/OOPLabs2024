#pragma once
#include "carte.h"
#include <string>
using namespace std;
class roman :
    public carte
{
    string nume;
    string autor;

public:

    roman(string nume, string autor);
    string GetInfo() override;
};

