#pragma once
#include "carte.h"
#include <string>
using namespace std;
class revista :
    public carte
{
    string titlu;
    int nrArticole;

public:

    revista(string titlu, int nrArticole);
    string GetInfo() override;
};

