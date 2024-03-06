#include "NumberList.h"
#include <stdio.h>
using namespace std;

int main()
{
	NumberList myClass;
	myClass.Init();
	myClass.Add(28);
	myClass.Add(10);
	myClass.Add(35);
	myClass.Add(64);
	myClass.Add(5);

	myClass.Sort();
	myClass.Print();

	/*printf("val x: %d\n", myClass.Getx());
	myClass.Setx(30);
	printf("val x: %d\n", myClass.Getx());*/

}