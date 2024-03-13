#include <iostream>
#include "Functions.h"
#include "Student.h"
using namespace std;

int main()
{
	Student Foamea, Datoria;
	Foamea.SetNume("Foamea");
	Foamea.SetGradeMatematics(6);
	Foamea.SetGradeEnglish(9);
	Foamea.SetGradeHistory(8);

	Datoria.SetNume("Datoria");
	Datoria.SetGradeMatematics(7);
	Datoria.SetGradeEnglish(5);
	Datoria.SetGradeHistory(6);

	printf("Compare name (Foamea, Datoria) = %d\n", CompareName(&Foamea, &Datoria));
	printf("Compare grade matematics (Foamea, Datoria) = %d\n", CompareGradeMatematics(&Foamea, &Datoria));
	printf("Compare grade english (Foamea, Datoria) = %d\n", CompareGradeEnglish(&Foamea, &Datoria));
	printf("Compare grade history (Foamea, Datoria) = %d\n", CompareGradeHistory(&Foamea, &Datoria));
	printf("Compare average grade (Foamea, Datoria) = %d\n", CompareAverageGrade(&Foamea, &Datoria));

	return 0;
}