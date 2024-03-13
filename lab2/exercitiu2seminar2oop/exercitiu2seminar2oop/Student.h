#pragma once
#include <string>
using namespace std;

class Student
{
private:
	string name;
	float gradeMatematics;
	float gradeEnglish;
	float gradeHistory;
public:
	void SetNume(string nameToSet);
	string GetNume();

	void SetGradeMatematics(float gradeToSet);
	float GetGradeMatematics() ;
	void SetGradeEnglish(float gradeToSet);
	float GetGradeEnglish() ;
	void SetGradeHistory(float gradeToSet);
	float GetGradeHistory() ;

	float GetAverageGrade() ;
};