#include "Pretekar.h"
#include <string>
#pragma once
class Preteky
{
private:
	Pretekar* zoznam;
	unsigned int pocet = 0;
	void VypisNaKonzolu(Pretekar *zoznam, int pocetPretekarov);
public:
	Preteky();
	void PridajPretekara(Pretekar *pridavany);
	~Preteky();
	Pretekar* ZoradPodlaCasu();
	void ZoradPodlaCisla();
	void ZoradPodlaCasuPohlavie();
	void ZoradPodlaPriezviska();
	void simulujCasy();
	void zapisDoSuboru(const char* menoSuboru);
};

