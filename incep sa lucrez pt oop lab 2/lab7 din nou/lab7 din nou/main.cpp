#include <iostream>
#include "Vector.h"
using namespace std;
int compare_ints(int x, int y) 
{
    // return -1, x < y
    // return 1, x > y
    // return 0, x == y
    return 0;
}

int main() {
    Vector<int> v;

    // index, element
    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);

    Vector<int> w = v;

    // index
    v.remove(0);
    printf("%d\n", w[0]);

    v.print();
}