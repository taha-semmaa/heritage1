#include "DateH.h"
#include <iostream>
using namespace std;
DateH::DateH(int h, int m, int s, int jj, int mm, int aa):Heure(h,m,s)
{
	if (aa >= 1900)
		this->annee = aa;
	if (mm >= 1 && mm <= 12)
		this->mois = mm;
	if (mm == 1 || mm == 3 || mm == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (jj >= 1 && jj <= 31)
			this->jour = jj;
	}
	else if (mm == 4 || m == 6 || m == 9 || m == 11)
	{
		if (jj >= 1 && jj <= 30)
			this->jour = jj;
	}
	else
	{
		if (this->annee % 4 == 0)
		{
			if (jj >= 1 && jj <= 29)
				this->jour = jj;
		}
		else
		{
			if (jj >= 1 && jj <= 28)
				this->jour = jj;

		}
	}


}

void DateH::affiche() const
{
	this->Heure::affiche();
	cout << this->jour << "/" << this->mois << "/" << this->annee << endl;
}

int DateH::comparer(const DateH &D) const
{
	if (this->annee == D.annee && this->mois == D.mois && this->jour == D.jour && this->Heure::comparer(D) == 0)
		return 0;
	if (this->annee > D.annee || (this->annee == D.annee && this->mois > D.mois)
		|| (this->annee == D.annee && this->mois == D.mois && this->jour > D.jour)
		|| (this->annee == D.annee && this->mois == D.mois && this->jour == D.jour && this->Heure::comparer(D) == 1))
		return 1;
	else
		return -1;


}

bool DateH::operator<(const DateH &D) const
{
	if (this->comparer(D) == -1)
		return true;
	return false;
}
