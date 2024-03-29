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
	Number n1("10110010", 2);
	Number n2("734", 8);

	/*if (n1 < n2)
		printf("haleluijah \n");
	else
		printf("teapa \n");

	if (n1 > n2)
		printf("haleluijah \n");
	else
		printf("teapa \n");

	if (n1 >= n2)
		printf("haleluijah \n");
	else
		printf("teapa \n");*/

	if (n1 <= n2)
		printf("haleluijah \n");
	else
		printf("teapa \n");

	/*if (n1 == n2)
		printf("haleluijah \n");
	else
		printf("teapa \n");*/

	Number n4("13130", 4);

	/*if (n2 == n4)
		printf("haleluijah \n");
	else
		printf("teapa \n");*/

	Number n3("FF", 16);
	printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
	n1.Print();
	n2.Print();




	/*numar.GetDigitsCount();
	numar.Print();
	numar.SwitchBase(5);
	nr.GetDigitsCount();*/

	//numar.Print();
	//printf("%d \n", numar.GetDigitsCount());
}

