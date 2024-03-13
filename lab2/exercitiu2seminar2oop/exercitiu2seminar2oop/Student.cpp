#include "Student.h"

void Student::SetNume(string nameToSet)
{
	name = nameToSet;
}

string Student::GetNume()
{
	return name;
}

void Student::SetGradeMatematics(float gradeToSet)
{
	gradeMatematics = gradeToSet;
}

float Student::GetGradeMatematics() 
{
	return gradeMatematics;
}

void Student::SetGradeEnglish(float gradeToSet)
{
	gradeEnglish = gradeToSet;
}

float Student::GetGradeEnglish() 
{
	return gradeEnglish;
}

void Student::SetGradeHistory(float gradeToSet)
{
	gradeHistory = gradeToSet;
}

float Student::GetGradeHistory() 
{
	return gradeHistory;
}

float Student::GetAverageGrade() 
{
	return (gradeEnglish + gradeHistory + gradeMatematics) / 3.0f;
}