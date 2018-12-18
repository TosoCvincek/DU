#include "Pretekar.h"
#include "Preteky.h"
#include <iostream>
#include <string>
#include <fstream>

/* Aplik�ciu mo�no ovl�da� nasleduj�co
	1, ak do vstupn�ch parametrov zad�me n�zov s�boru, d�ta sa ��taj� zo s�boru
	2, ak vo vstupn�ch parametroch nieje ni�, ��ta sa cez konzolu ru�n�m zad�van�m

	Zadanie va�ej �lohy som ale nesplnil �plne, �itanie zo s�boru typu "meno priezvisko pohlavie"
	z riadku mi ne�lo, preto som program upravil tak, aby ��tal nasleduj�ci druh s�boru:
	"
	meno
	priezvisko
	pohlavie
	"

	Autor: Tom� Cvin�ek 5zy022;
	M�m s vami cvi�enia v pondelok o 16:00, ak dovtedy stihnete �lohu skontrolova�,
	r�d s Vami budem nezrovnalosti konzultova�.

	S pozdravom Tom� Cvin�ek

*/

using namespace std;

int main(int argc, char*argv[]) {
	Preteky *zavody = new Preteky();
	if (argv[0] != nullptr) {
		const char* menoSuboru = argv[1];
		ifstream citac;
		citac.open(menoSuboru);
		string meno;
		string priezvisko;
		string pohlavie;
		while (!citac.eof())
		{
			getline(citac,meno);
			getline(citac, priezvisko);
			getline(citac, pohlavie);
			Pretekar *p1 = new Pretekar();
			char * menoChar = new char[meno.length() + 1];
			strcpy(menoChar, meno.c_str());
			char * priezviskoChar = new char[priezvisko.length() + 1];
			strcpy(priezviskoChar, priezvisko.c_str());
			char *pohlavieChar = new char[pohlavie.length() + 1];
			strcpy(pohlavieChar, pohlavie.c_str());
			char pohlavieC = pohlavieChar[0];
			p1->NahodPretekara(menoChar, priezviskoChar, pohlavieC);
			zavody->PridajPretekara(p1);
		}
		if(citac.is_open()) citac.close();
	}
	else {
		int este = 0;
		while (este == 0) {
			string meno;
			string priezvisko;
			string cgon;
			char pohlavie;
			cout << "Meno pretekara:";
			getline(cin, meno);
			cout << "Priezvisko pretekara:";
			getline(cin, priezvisko);
			cout << "Pohlavie (m - muz / z - zena):";
			cin >> pohlavie;
			if (pohlavie != 'm' || pohlavie != 'z') {
				cout << "Chyba vstupu, skuste znova" << endl;
				cout << "Pohlavie (m - muz / z - zena):";
				cin >> pohlavie;
			}
			Pretekar *p1 = new Pretekar();
			char * menoChar = new char[meno.length() + 1];
			strcpy(menoChar, meno.c_str());
			char * priezviskoChar = new char[priezvisko.length() + 1];
			strcpy(priezviskoChar, priezvisko.c_str());
			p1->NahodPretekara(menoChar, priezviskoChar, pohlavie);
			zavody->PridajPretekara(p1);
			cout << "ak chcete pridat dalsieho pretekara, stlacte d, inak stlacte cokolvek pre zacatie pretekov:";
			char d;
			cin >> d;
			getline(cin, cgon);
			if (d == 'd') este = 0;
			else este++;
		}
	}
	zavody->simulujCasy();
	zavody->ZoradPodlaCisla();
	zavody->ZoradPodlaCasu();
	zavody->ZoradPodlaCasuPohlavie();
	zavody->ZoradPodlaPriezviska();
	zavody->zapisDoSuboru("vysledky.txt");
	/*Pretekar *p1 = new Pretekar();
	Pretekar *p2 = new Pretekar();
	Pretekar *p3 = new Pretekar();
	Pretekar *p4 = new Pretekar();
	p1->NahodPretekara((char*)"Cigi", (char*)"Cgon", 'm');
	p2->NahodPretekara((char*)"Kubo", (char*)"Trencinsky", 'm');
	p3->NahodPretekara((char*)"Mirko", (char*)"Skalicky", 'm');
	p4->NahodPretekara((char*)"Ivana", (char*)"Horecka", 'z');
	Preteky *zavody = new Preteky();
	zavody->PridajPretekara(p1);
	zavody->PridajPretekara(p2);
	zavody->PridajPretekara(p3);
	zavody->PridajPretekara(p4);
	zavody->simulujCasy();
	zavody->ZoradPodlaCisla();
	zavody->ZoradPodlaCasu();
	zavody->ZoradPodlaCasuPohlavie();
	zavody->ZoradPodlaPriezviska();
	zavody->zapisDoSuboru("vysledky.txt");*/
}

