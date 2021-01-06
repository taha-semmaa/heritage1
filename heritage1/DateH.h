#pragma once
#include "Heure.h"
class DateH : public Heure
{
public:
	DateH(int, int, int, int jj = 1, int mm = 1, int aa = 1900);
	void affiche()const;
	int comparer(const DateH&)const;
	bool operator<(const DateH&)const;
public:
	int jour, mois, annee;
};

