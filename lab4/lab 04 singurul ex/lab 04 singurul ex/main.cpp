#include "Sorti.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
	Sorti Pconstr(10, 15, 99);
	Pconstr.Print();
	printf("\n");
	///Pconstr. InsertSort(false);
	Pconstr.BubbleSort (false);
	Pconstr. Print();
}