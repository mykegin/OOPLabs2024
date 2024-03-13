#pragma once
#include <string>
#include "Student.h"
using namespace std;

int CompareName(Student* firstStudent, Student* secondStudent);

int CompareGradeMatematics( Student* firstStudent,  Student* secondStudent);

int CompareGradeEnglish( Student* firstStudent,  Student* secondStudent);

int CompareGradeHistory( Student* firstStudent,  Student* secondStudent);

int CompareAverageGrade( Student* firstStudent,  Student* secondStudent);