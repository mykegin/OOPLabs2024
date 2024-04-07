#include "Functions.h"
int movie_compare_name(const Movie& m1, const Movie& m2)
{
	const char* fm = m1.get_name();
	const char* sm = m2.get_name();

	int i = 0;
	while(fm[i]=='\0' || sm[i]=='\0')
	{
		if (fm[i] > sm[i])
			return 1;
		else if (fm[i] < sm[i])
			return -1;
		i++;
	}
		return 0;
}

int movie_compare_year(const Movie& m1, const Movie& m2)
{
	if (m1.get_year() > m2.get_year())
		return 1;
	else
		if (m1.get_year() == m2.get_year())
			return 0;
		else
			return -1;
}

int movie_compare_score(const Movie& m1, const Movie& m2)
{
	if (m1.get_score() > m2.get_score())
		return 1;
	else
		if (m1.get_score() == m2.get_score())
			return 0;
		else
			return -1;
}

int movie_compare_length(const Movie& m1, const Movie& m2)
{
	if (m1.get_length() > m2.get_length())
		return 1;
	else
		if (m1.get_length() == m2.get_length())
			return 0;
		else
			return -1;
}

int movie_compare_passed_years(const Movie& m1, const Movie& m2)
{
	int passed_years_m1 = 2024 - m1.get_year();
	int passed_years_m2 = 2024 - m2.get_year();

	if (passed_years_m1 > passed_years_m2)
		return 1;
	else if (passed_years_m1 == passed_years_m2)
		return 0;
	else
		return -1;
}