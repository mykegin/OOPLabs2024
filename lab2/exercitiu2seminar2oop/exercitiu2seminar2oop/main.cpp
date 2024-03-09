#include <iostream>
#include "Functions.h"
#include "Student.h"
using namespace std;

int main()
{
	Student Foamea, Datoria;
	Foamea.SetName("Foamea");
	Foamea.SetGradeMatematics(10);
	Foamea.SetGradeEnglish(5);
	Foamea.SetGradeHistory(9);

	Datoria.SetName("Datoria");
	Datoria.SetGradeMatematics(6);
	Datoria.SetGradeEnglish(8);
	Datoria.SetGradeHistory(10);

	printf("Compare name (Foamea, Datoria) = %d\n", CompareName(&Foamea, &Datoria));
	printf("Compare grade matematics (Foamea, Datoria) = %d\n", CompareGradeMatematics(&Foamea, &Datoria));
	printf("Compare grade english (Foamea, Datoria) = %d\n", CompareGradeEnglish(&Foamea, &Datoria));
	printf("Compare grade history (Foamea, Datoria) = %d\n", CompareGradeHistory(&Foamea, &Datoria));
	printf("Compare average grade (Foamea, Datoria) = %d\n", CompareAverageGrade(&Foamea, &Datoria));

	return 0;
}