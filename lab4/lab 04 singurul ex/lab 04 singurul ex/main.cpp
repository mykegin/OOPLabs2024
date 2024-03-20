#include "Sort.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
	///Sort Pconstr(10, 15, 99);
	///Pconstr.Print();
	printf("\n");
	///Pconstr. InsertSort(false);
	///Pconstr.QuickSort (true);
	char c[] = "10,32,18,26,11";
	Sort caracter(c);
	caracter.Print();
}