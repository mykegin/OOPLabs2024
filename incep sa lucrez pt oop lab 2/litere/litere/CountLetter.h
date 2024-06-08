#pragma once
#include "Procesor.h"
#include <functional>
#include <iostream>
using namespace std;
class CountLetter :
    public Procesor
{

    function <bool(char)> x;
    string s;

public:
    CountLetter(string s, function <bool(char)> x);
    string GetName() override;
    int Compute(string s) override;
};

