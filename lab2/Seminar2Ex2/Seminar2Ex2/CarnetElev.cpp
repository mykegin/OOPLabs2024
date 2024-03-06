#include "CarnetElev.h"
#include <stdio.h>

void CarnetElev::SetNume(char numeElev[])
{
	int i = 0;
	while (numeElev[i] != '\n')
	{
		this->numeElev[i] = numeElev[i];
		i++;
	}
}

void CarnetElev::GetNume()
{
	printf("%d\n", this->numeElev);
	return;
}



void CarnetElev::SetMate(float notaMate)
{
	this->notaMate = notaMate;
}

int CarnetElev::GetMate()
{
	return this->notaMate;
}



void CarnetElev::SetEngleza(float notaEngleza)
{
	this->notaEngleza = notaEngleza;
}

int CarnetElev::GetEngleza()
{
	return this->notaEngleza;
}



void CarnetElev::SetIstorie(float notaIstorie)
{
	this->notaIstorie = notaIstorie;
}

int CarnetElev::GetIstorie()
{
	return this->notaIstorie;
}



float CarnetElev::MedieFinala(float notaMate, float notaEngleza, float notaIstorie)
{
	return (this->notaMate + this->notaEngleza + this->notaIstorie) / 3;
}



void CarnetElev::ComparareNume(char NumeElev1[], char NumeElev2[])
{
	int i=0;
	while (NumeElev1[i] != '\n')
	{
		if (NumeElev1[i] < NumeElev2[i])
		{
			printf("%d\n", NumeElev1);
			return;
		}
		else
		{
			printf("%d\n", NumeElev2);
			return;
		}
		i++;
	}

	printf("%d\n", "AU ACELASI NUME!!!");
		return;
}



int CarnetElev::ComparareNotaMate(float NotaMate1, float NotaMate2)
{
	if (NotaMate1 > NotaMate2)
		return NotaMate1;
	else
		return NotaMate2;
}



int CarnetElev::ComparareNotaEngleza(float NotaEngleza1, float NotaEngleza2)
{
	if (NotaEngleza1 > NotaEngleza2)
		return NotaEngleza1;
	else
		return NotaEngleza2;
}



int CarnetElev::ComparareNotaIstorie(float NotaIstorie1, float NotaIstorie2)
{
	if (NotaIstorie1 > NotaIstorie2)
		return NotaIstorie1;
	else
		return NotaIstorie2;
}



int CarnetElev::ComparareMedie(float NotaMedie1, float NotaMedie2)
{
	NotaMedie1 = MedieFinala(this->notaMate, this->notaEngleza, this->notaIstorie);
	NotaMedie2 = MedieFinala(this->notaMate, this->notaEngleza, this->notaIstorie);

	if (NotaMedie1 > NotaMedie2)
		return NotaMedie1;
	else
		return NotaMedie2;
}
