#pragma once
#include<fstream>
#include<iostream>
#include <sstream>
#include<string>
#include<vector>


#include"SortTools.h"
#include"SearchTools.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::string;
using std::fstream;
using std::ios;
using std::get;
using std::istringstream;
using std::stringstream;
using std::ifstream;

//string nazov_txt;
//fstream nazov_suboru;

/**
*@brief Funkcia PrintVector slúži na vypísanie obsahu vektora.
* Zíde sa nám hlavne na kontrolu.
* @param vektor_cisel  Vektor_cisel je parameter, ktory slúži na uchovavanie vektoru, ktory chceme vypísat.
*/
void PrintVector(vector<long>& vektor_cisel) {

	for (long cislo : vektor_cisel) {
		cout << cislo << endl;

	}
	cout << endl;
}

/**
* @brief Funkcia AddVector nám slúži na vloženie vektoru do súboru v takom tvare, aký spĺňa aj testovací súbor.
* @param vektor_cisel Vektor_cisel je referencia na vektor, ktory sa bude vkladať do súboru.
* @param subor Subor služi ako referencia na súbor do ktorého sa bude vkladať.
*/
void AddVector(vector<long>& vektor_cisel,fstream &subor) {

	for (long cislo : vektor_cisel) {
		subor << cislo << endl;
	}
}

/**
* @brief Funkcia VytvoritSubor slúži na vytvorenie súboru.
* Využíva funkciu AddVector() na zápis vektoru do súboru.
* @param subor_txt Slúži na vloženie konkretného  názvu textového súboru, kde sa bude množina ukladať.
* @param set Obsahuje množinu, ktorá sa uloží.

*/

void VytvoritSubor(const string& subor_txt, vector<long> set) {

	fstream subor;
	subor.open(subor_txt, ios::out);

	if (subor.is_open()) {
		
		AddVector(set,subor);
		subor.close();
		cout << "cisla zapisane" << endl;
	}

}
/**
* @brief Funkcia StringToVector zabezpeči, že prevedie načitany reťazec znakov do vektora čísel.
* Istringstream vytvára virtuálny reťazcový prúd, ktorý umožňuje pohodlné čítanie dát z reťazca, ktorý je už k dispozícii v pamäti.
* Funkciu použivam kvôli tomu, že nemusi byť vždy isté, že na riadku je číslo. zároveň to pre mňa slúži aj ako zjednodušenie a potvrdenie, že skutočne pracujem 
*	s vektorom longov a nie s reťazcami.
* >>je operator na čitanie z reťazca (token je prave načitany riadok suboru   -retazec-).
* @param subor_txt Slúži ako referencia na názov textového súboru z ktorého sa budu čerpať znaky.
* @param cisla Slúži ako referencia na vektor, do ktorého sa budú vkládať už takýmto spôsobom vybrané čísla (push_back)
*/

void StringToVectorLong(const string& subor_txt, vector<long>& cisla) {
	
	istringstream iss(subor_txt);
	string token;
	while (iss >> token) { 
		long cislo_riadok = stol(token);
		cisla.push_back(cislo_riadok);
	}

}

/**
*@brief Táto funkcia NacitatSubor je súčasť upraveného súboru. Úplne prvotná funkcia.
*Zaroveň si pomocou neho vieme overiť napriklad rozdiel množin vďaka tomu, že nie je nijak upravovany, je len načitany do pola longov.
*Využíva aj funkciu StringToVectorLong() pre pohodlnú prácu a ľahšiu manipuláciu.
* @param subor_txt Je referencia na konkrétny názov súboru (.txt), ktorý chceme načítať.
* @return Funkcia vracia vektor čísel načítaných zo súboru...je teda pripravená na to, že sa dá vložiť do nejakej premeny pre pohodlné operácie.
*/

vector<long>NacitatSubor(const string& subor_txt) {

	fstream subor;
	string text;
	vector<long> cisla;
	subor.open(subor_txt, ios::in);

	if (subor.is_open()) {
		

		while (getline(subor, text)) {
			
			StringToVectorLong(text, cisla);
			
		}

		subor.close();
		cout << "Stringy boli uspesne nacitane zo suboru." << endl;
	}
	else {
		cout << "Subor sa neotvoril" << endl;
	}
	return cisla;

}


/*Kontrola*/

/**
*@brief Funkcia KontrolaPoctuCisel slúži len na účely kontroly pre tvorcu programu.
* Nijako ju ani nevyužívam vo finále. Išlo len o pokus, či všetko správne funguje v začiatkoch projektu.
* @param vektor_cisel Parametrom je referencia na vektor cisel.
*/
void KontrolaPoctuCisel(vector<long>& vektor_cisel) {
	cout << "Velkost vektora je:" << vektor_cisel.size();


}

/**
* @brief Funkcia RemoveDuplicities slúži na odstránenie rovnakých čísel v už zoradenom vektore nejakým Sort algoritmom
* Vhodná je pre zoradené pole, pretože sa tam pracuje systémom porovnávania predchadzajuceho prvku s aktuálne vybraným
* Pridávaju sa do finalneho vektora prvky, ktore su unikatne(nerovnaju sa predchadzajucim)
* @param sorted_vector Ako parameter je referencia na už zoradený vektor. Názov nás nabáda k tomu, aby sme tam vložili zoradený vektor, inak to nebude pracovať
* správne.
*/
void RemoveDuplicities( vector<long>& sorted_vector) {
	vector<long> final_vector;
	

	
	final_vector.push_back(sorted_vector[0]); // Prida prvý prvok do výstupného vektoru
	long n = sorted_vector.size();
	// Prejdi cez zvyšné prvky vstupného vektoru
	for (long i = 1; i < n; i++) {
		// Ak sa aktuálny prvok nerovna predchádzajúcemu, prida ho do výstupného vektoru
		if (sorted_vector[i] != sorted_vector[i - 1]) {
			final_vector.push_back(sorted_vector[i]);
		}
	}

	sorted_vector = final_vector; //nakoniec bude odkazovat na zoradeny vektor bez duplicit
	cout << "Duplicity boli odstranene" << endl;
}


/**
* @brief Funkcia UpravenySubor je hlavna funkcia, ktorej telo tvoria funkcie dostavajuce súbor do idealného stavu pre náš účel. Máme prostredníctvom nej istotu, že ak do parametru zadáme názov súboru, ktorý chceme pre náš účel upraviť , tak toho skutočne dosiahneme
	*Obsahuje všetky funkcie, ktorý postupne daný súbor upravujú.
*@param nazov_suboru Je referencia na konkretneho (.txt) súboru, ktorý sa má upraviť pre náš účel
* @return Funkcia vráti množinu s ktorou sa ďalej dajú vykonávať účelové operácie (nás teda zaujíma prienik)
*/

vector<long> UpravenySubor(const string& nazov_suboru) {
	
	
	vector<long>cisla =NacitatSubor(nazov_suboru);
	
	QuickSort(cisla);
	RemoveDuplicities(cisla);
	/*
	*Kontrola
	
	*PrintVector(cisla);
	*KontrolaPoctuCisel(cisla);
	
	*cout << "Subor upraveny" << endl;
	*/
	return cisla;
}
