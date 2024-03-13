#include "Functions.h"

int CompareName(Student* firstStudent, Student* secondStudent)
{
	 string nameFirstStudent = firstStudent->GetNume();
	 string nameSecondStudent = secondStudent->GetNume();

	if (nameFirstStudent < nameSecondStudent)
		return -1;
	if (nameFirstStudent > nameSecondStudent)
		return 1;
	return 0;
}

int CompareGradeMatematics( Student* firstStudent,  Student* secondStudent)
{
	 float gradeFirstStudent = firstStudent->GetGradeMatematics();
	 float gradeSecondStudent = secondStudent->GetGradeMatematics();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}

int CompareGradeHistory( Student* firstStudent,  Student* secondStudent)
{
	 float gradeFirstStudent = firstStudent->GetGradeHistory();
	 float gradeSecondStudent = secondStudent->GetGradeHistory();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}


int CompareGradeEnglish( Student* firstStudent,  Student* secondStudent)
{
	 float gradeFirstStudent = firstStudent->GetGradeEnglish();
	 float gradeSecondStudent = secondStudent->GetGradeEnglish();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}

int CompareAverageGrade( Student* firstStudent,  Student* secondStudent)
{
	 float gradeFirstStudent = firstStudent->GetAverageGrade();
	 float gradeSecondStudent = secondStudent->GetAverageGrade();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}