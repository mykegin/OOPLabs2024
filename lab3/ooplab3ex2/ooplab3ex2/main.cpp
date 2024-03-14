#include "Canvas.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	Canvas Canvas;
	Canvas.DrawRect(5, 5, 5, 5, '0');
	Canvas.Print();

	return 0;
}