#include "Canvas.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{

    Canvas Pictura(100, 100);
    Pictura.Clear();
    /*Pictura.DrawLine(5, 5, 5, 30, '0');
    Pictura.Clear();*/
    Pictura.DrawRect(5, 5, 10, 30, '0');
    Pictura.FillRect(5, 5, 10, 30, '0');
    Pictura.Clear();
    Pictura.DrawCircle(50, 50, 30, '0');
    Pictura.FillCircle(50, 50, 30, '0');
    Pictura.Print();
}