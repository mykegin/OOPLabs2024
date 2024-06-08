#pragma once
#include "Procesor.h"
using namespace std;
class ComputeVowals :
    public Procesor
{
    string s;

public:
    ComputeVowals(string s);
    string GetName() override;
    int Compute(string s) override;
};

