#include "Number.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

using namespace std;
int main()
{
	Number numar("10110", 2);
	numar.GetDigitsCount();
	numar.Print();
	numar.SwitchBase(5);
	numar.Print();
	///printf("%d \n", numar.GetDigitsCount());
}

