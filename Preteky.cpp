#include "Preteky.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
Preteky::Preteky()
{
}
void Preteky::PridajPretekara(Pretekar * pridavany)
{
	if(pocet == 0) {
		zoznam = new Pretekar[1];
		pocet++;
		zoznam[pocet - 1] = *pridavany;
	}
	else {
		pocet++;
		Pretekar *pomocny = new Pretekar[pocet];
		if (zoznam) {
			for (unsigned int i = 0; i < pocet - 1; ++i)
			{
				pomocny[i] = zoznam[i];
			}
			pomocny[pocet-1] = *pridavany;
			delete[] zoznam;
		}
		zoznam = pomocny;
	}
}


Preteky::~Preteky()
{
	delete[] zoznam;
}

Pretekar* Preteky::ZoradPodlaCasu()
{
	int cas = 10000;
	int index;
	Pretekar *novyZoznam = new Pretekar[pocet];
	Pretekar *pom = new Pretekar[pocet];
	for (unsigned int i = 0; i < pocet; i++)
	{
		pom[i] = zoznam[i];
	}
	for (unsigned int i = 0; i < pocet; i++)
	{
		for (unsigned int j = 0; j < pocet; j++)
		{
			if (pom[j].getVysledok() < cas) {
				cas = pom[j].getVysledok();
				index = j;
			}
		}
		novyZoznam[i] = pom[index];
		pom[index].setCas(10001);
		cas = 10000;
	}
	cout << "Zoradenie podla casu :" << endl;
	VypisNaKonzolu(novyZoznam,pocet);
	return novyZoznam;
}

void Preteky::ZoradPodlaCisla()
{
	cout << "Zoradenie podla cisla :" << endl;
	VypisNaKonzolu(zoznam,pocet);
}

void Preteky::ZoradPodlaCasuPohlavie()
{
	Pretekar * sorted = new Pretekar[pocet];
	sorted = ZoradPodlaCasu();
	int pocMuzov = 0;
	for (int i = 0; i < pocet; i++)
	{
		if (sorted[i].getPohlavie() == 'm') {
			pocMuzov++;
		}
	}
	Pretekar * muzi = new Pretekar[pocMuzov];
	Pretekar * zeny = new Pretekar[pocet - pocMuzov];
	int pocZeny = 0;
	pocMuzov = 0;
	for (int i = 0; i < pocet; i++)
	{
		if (sorted[i].getPohlavie() == 'm') {
			muzi[pocMuzov] = sorted[i];
			pocMuzov++;
		} else {
			zeny[pocZeny] = sorted[i];
			pocZeny++;
		}
	}
	cout << "Zoradenie podla casov :" << endl;
	cout << "Zeny :" << endl;
	if(pocZeny > 0) VypisNaKonzolu(zeny,pocZeny);
	cout << "Muzi :" << endl;
	if(pocMuzov > 0) VypisNaKonzolu(muzi,pocMuzov);
}

void Preteky::ZoradPodlaPriezviska()
{
	int kodPismena = 90;
	int index;
	Pretekar *novyZoznam = new Pretekar[pocet];
	Pretekar *pom = new Pretekar[pocet];
	for (unsigned int i = 0; i < pocet; i++)
	{
		pom[i] = zoznam[i];
	}
	for (unsigned int i = 0; i < pocet; i++)
	{
		for (unsigned int j = 0; j < pocet; j++)
		{
			if ((pom[j].getPriezvisko())[0] < kodPismena) {
				kodPismena = (pom[j].getPriezvisko())[0];
				index = j;
			}
		}
		novyZoznam[i] = pom[index];
		pom[index].setPriezvisko((char*)"[[");
		kodPismena = 90;
	}
	cout << "Zoradenie podla priezviska abecedne:" << endl;
	VypisNaKonzolu(novyZoznam, pocet);
}

void Preteky::VypisNaKonzolu(Pretekar * zoznamPretekarov, int pocetPretekarov)
{
	for (int i = 0; i < pocetPretekarov; i++) {
		int hodiny, minuty, sekundy;
		hodiny = zoznamPretekarov[i].getVysledok() / (60 * 60);
		minuty = zoznamPretekarov[i].getVysledok() % (60 * 60);
		minuty = minuty / 60;
		sekundy = minuty % 60;
		std::string minutky =" vtok";
 		std::string sekundicky;
		if (minuty < 10) {
			minutky = ":0" + std::to_string(minuty);
		}
		else {
			minutky =":" + std::to_string(minuty);
		}
		if (sekundy < 10) {
			sekundicky = ":0" + std::to_string(sekundy);
		}
		else {
			sekundicky = ":" + std::to_string(sekundy);
		}
		//string cas = (string)hodiny + minutky + sekundicky;
		cout <<i + 1<< ". " << zoznamPretekarov[i].getMeno()<< " " << zoznamPretekarov[i].getPriezvisko() << ", " << zoznamPretekarov[i].getPohlavie() << ", mal/a vysledny cas: " << hodiny << minutky << sekundicky << endl;
	
	}

}

void Preteky::zapisDoSuboru(const char * menoSuboru)
{
	ofstream zapisovac;
	zapisovac.open(menoSuboru);
	zapisovac << "vysledky:" << endl;
	for (int i = 0; i < pocet; i++) {
		int hodiny, minuty, sekundy;
		hodiny = zoznam[i].getVysledok() / (60 * 60);
		minuty = zoznam[i].getVysledok() % (60 * 60);
		minuty = minuty / 60;
		sekundy = minuty % 60;
		std::string minutky;
		std::string sekundicky;
		if (minuty < 10) {
			minutky = ":0" + std::to_string(minuty);
		}
		else {
			minutky = ":" + std::to_string(minuty);
		}
		if (sekundy < 10) {
			sekundicky = ":0" + std::to_string(sekundy);
		}
		else {
			sekundicky = ":" + std::to_string(sekundy);
		}
		zapisovac << i + 1 << ". " << zoznam[i].getMeno() << " " << zoznam[i].getPriezvisko() << ", " << zoznam[i].getPohlavie() << ", mal/a vysledny cas: " << hodiny << minutky << sekundicky << endl;
	}
	if (zapisovac.is_open()) zapisovac.close();
}

void Preteky::simulujCasy()
{
	for (unsigned int i = 0; i < pocet; i++)
	{
		zoznam[i].setCas(rand() % 1955 + 7140);
	}
}
