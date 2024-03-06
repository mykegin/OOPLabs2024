#pragma once
class CarnetElev
{
	char numeElev[256];
	float notaMate;
	float notaEngleza;
	float notaIstorie;

public:
	void SetNume(char numeElev[]);
	void GetNume();

	void SetMate(float notaMate);
	int GetMate();

	void SetEngleza(float notaEngleza);
	int GetEngleza();

	void SetIstorie(float notaIstorie);
	int GetIstorie();

	float MedieFinala(float notaMate, float notaEngleza, float notaIstorie);

	void ComparareNume(char NumeElev1[], char NumeElev2[]);
	int ComparareNotaMate(float NotaMate1, float NotaMate2);
	int ComparareNotaEngleza(float NotaEngleza1, float NotaEngleza2);
	int ComparareNotaIstorie(float NotaIstorie1, float NotaIstorie2);
	int ComparareMedie(float NotaMedie1, float NotaMedie2);

	///media se returneaza
};

