#pragma once
#include "Procesor.h"
using namespace std;
class LongestWord :
    public Procesor
{
private:

    string s;

public:
    LongestWord(string x);
    string GetName() override;
    int Compute(string s) override;
};

