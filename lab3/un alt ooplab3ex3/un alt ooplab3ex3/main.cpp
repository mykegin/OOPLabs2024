#include "Canvas.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	
	Canvas Pictura(30,30);
	Pictura.DrawRect(5, 5, 5, 5, '0');
	Pictura.Print();
}