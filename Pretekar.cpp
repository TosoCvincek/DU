#include "Pretekar.h"


Pretekar::Pretekar()
{
}

void Pretekar::NahodPretekara(char * pMeno, char * pPriezvisko, char pPohlavie)
{
	meno = pMeno;
	priezvisko = pPriezvisko;
	pohlavie = pPohlavie;
}

Pretekar::~Pretekar()
{
	delete[] meno;
	delete[] priezvisko;
}
