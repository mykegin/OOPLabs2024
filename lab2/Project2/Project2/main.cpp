#include <stdio.h>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList myClass;

	myClass.Init();
	myClass.Print();
	printf("\n");
	myClass.Add(28);
	myClass.Add(10);
	myClass.Add(35);
	myClass.Add(64);
	myClass.Add(5);

	myClass.Print();
	printf("\n");

	myClass.Sort();
	myClass.Print();
	return 0;
}