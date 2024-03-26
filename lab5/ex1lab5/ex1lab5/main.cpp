#include "Number.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

using namespace std;
int main()
{
	Number numar("9", 10);
	numar.Print();
	numar.SwitchBase(2);
	numar.Print();
	///printf("%d \n", numar.GetDigitsCount());
}

