#include <iostream>
#include "Map.h"
#include <stdio.h>
using namespace std;

class exceptie : public exception
{
    virtual const char* what() const throw()
    {
        return "nu se poate divide la 0";
    }
};

int main()
{
    int x = 10, y = 5, z = 1;
    exceptie ex;

    try
    {
        if (z == 0)
            throw ex;
        x = z / y;
        printf("asta in cazul in care z nu e zero, x din 10 va deveni %d", x);
    }

    catch (exception& e)
    {
        cout << "Exceptie: " << e.what() << endl;
    }

}