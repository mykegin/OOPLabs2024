#include <iostream>
#include <cstring>
#include "Functions.h"
int main()
{
	Student b1;
	Student b2;
	Functions k;
	b1.setname("Mihaita");
	b1.getname();
	b1.setengleza(10);
	b1.setmate(7);
	b1.setistorie(5);

	b2.setname("Alexutzu");
	b2.getname();
	b2.setengleza(9);
	b2.setmate(9);
	b2.setistorie(8);

	printf("%d \n", k.comparename(b1, b2));
	printf("%d \n", k.comparemate(b1, b2));
	printf("%d \n", k.compareengleza(b1, b2));
	printf("%d \n", k.compareistorie(b1, b2));
	printf("%d \n", k.comparemedie(b1, b2));

	return 0;
}