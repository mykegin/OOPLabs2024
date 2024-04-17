#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "Math.h"

int main()
{
	Math mate;
	printf("%d \n", mate.Add(1, 5));
	printf("%d \n", mate.Add(1, 2, 4));
	printf("%d \n", mate.Add(1.7, 4.3));
	printf("%d \n", mate.Add(1.5, 1.3, 3.2));
	printf("%d \n", mate.Add(3, 2, 2, 2));
	printf("%s \n", mate.Add("101", "208"));

	printf("%d \n", mate.Mul(2, 3));
	printf("%d \n", mate.Mul(1, 2, 4));
	printf("%d \n", mate.Mul(1.5, 4.0));
	printf("%d \n", mate.Mul(1.5, 1.333, 4.0));


}