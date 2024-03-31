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
		Number n1("10110010", 2); ///178
		Number n2("734", 8); ///476
		Number n3("FF", 16);

		/*n1.Print();
		printf("n1 has %d digits and it is written in base %d\n \n \n", n1.GetDigitsCount(), n1.GetBase());


		for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
		{
			printf("n1[%d]=%c\n", tr, n1[tr]);
		}
		
		n1.SwitchBase(10);
		n2.SwitchBase(10);
		n3.SwitchBase(7);

		if (n1 > n2)
			printf("asta trebuia afisat si e bine \n \n");
		else
			printf("nu asta trebuia afisat \n \n");*/

		

		/*n1.Print();
		n2.Print();
		n3.Print();
		
		n1.Print();*/

		n1.Print();
		n2.Print();

		printf("\n");

		printf("aici e: %s \n\n\n", n1 + n2);

		n3 = n1 + n2;

		printf("ar trebui sa dea 654 \n %s \n \n \n", n3.GetNumber());
		n3.Print();


		/*
		* 
		* testele pentru add
		* 
		printf("aici ese afla testul acutal: \n");
		n1.Print();
		n2.Print();

		printf("\n");

		n2 = n1 + 2;

		n2.Print();
		*/

		/*Number n4 = 12345; // n4 will be in base 10
		n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
		n4 += n1;
		n4.Print();*/

		return 0;
}