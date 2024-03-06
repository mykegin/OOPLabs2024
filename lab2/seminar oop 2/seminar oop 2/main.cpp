#include "FirstClass.h"
#include <stdio.h>
using namespace std;

int main()
{
	FirstClass myClass;
	myClass.Setx(25);
	printf("val x: %d\n", myClass.Getx());
		myClass.Setx(30);
	printf("val x: %d\n", myClass.Getx());

}