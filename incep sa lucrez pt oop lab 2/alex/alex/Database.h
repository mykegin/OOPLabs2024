#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Entry.h"
#include <stdio.h>
#include <iterator>
using namespace std;
class Database
{
private:
    vector < Entry* > entries;

public:
    Database& operator +=(  Entry* e);
    Database& operator -=(string name);
    vector <Entry*>::iterator begin() { return this->entries.begin(); }
    vector <Entry*>::iterator end() { return this->entries.end(); }
    void Print();
};

