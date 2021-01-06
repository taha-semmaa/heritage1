#include "Heure.h"
#include <iostream>
using namespace std;
Heure::Heure(int h, int m, int s)
{
	if (h >= 0 && h <= 23)
		this->heure = h;
	if (m >= 0 && m <= 60)
		this->minute = m;
	if (s >= 0 && s <= 60)
		this->seconde = s;
}

void Heure::affiche() const
{
	cout << this->heure << ":" << this->minute << ":" << this->seconde << endl;
}

int Heure::comparer(const Heure& H) const
{
	if (this->heure == H.heure && this->minute == H.minute && this->seconde == H.seconde)
		return 0;
	if (this->heure > H.heure || (this->heure == H.heure && this->minute > H.minute) ||
		(this->heure == H.heure && this->minute == H.minute && this->seconde > H.seconde))
		return 1;
	return -1;
}

bool Heure::operator>(const Heure &H) const
{
	return this->comparer(H);
}

