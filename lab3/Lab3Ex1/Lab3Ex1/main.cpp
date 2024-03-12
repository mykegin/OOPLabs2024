#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
#include <cstring>
using namespace std;

int main()
{
	Math Mate;
	printf("adunare de 2: %d\n", Mate.Add(23, 35));
	printf("adunare de 3: %d\n", Mate.Add(23, 35, 11));
	printf("adunare de 2: %f\n", Mate.Add(23.5, 35.21));///nu da cu virgula din cauza ca functia e int
	printf("adunare de 3: %f\n", Mate.Add(23.1, 35.1, 11.49));///la fel si aici
	printf("inmultire de 2: %d\n", Mate.Mul(23, 3));
	printf("inmultire de 3: %d\n", Mate.Mul(23, 3, 1));
	printf("inmultire de 2: %f\n", Mate.Mul(23.9, 3.8));
	printf("inmultire de 3: %f\n", Mate.Mul(23.9, 3.8, 6.9));
	printf("adunarea a 10 numere: %d\n", Mate.Add(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
	printf("concatenarea a doua siruri: %s\n", Mate.Add("Myke", "Gin"));
}