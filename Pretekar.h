#pragma once

class Pretekar
{
private:
	char* meno;
	char *priezvisko;
	char pohlavie;
	unsigned int vysledok = 0;
public:
	Pretekar();
	void NahodPretekara(char *pMeno, char *pPriezvisko, char pPohlavie);
	~Pretekar();
	void setCas(unsigned int pVysledok) { vysledok = pVysledok; };
	void setPriezvisko(char* novePriezvisko) { priezvisko = novePriezvisko; };
	char* getMeno() { return meno; };
	char* getPriezvisko() { return priezvisko; };
	char getPohlavie() { return pohlavie; };
	unsigned int getVysledok() { return vysledok; }

};
