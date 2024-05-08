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
*@brief Funkcia PrintVector slúi na vypísanie obsahu vektora.
* Zíde sa nám hlavne na kontrolu.
* @param vektor_cisel  Vektor_cisel je parameter, ktory slúi na uchovavanie vektoru, ktory chceme vypísat.
*/
void PrintVector(vector<long>& vektor_cisel) {

	for (long cislo : vektor_cisel) {
		cout << cislo << endl;

	}
	cout << endl;
}

/**
* @brief Funkcia AddVector nám slúi na vloenie vektoru do súboru v takom tvare, akı spåòa aj testovací súbor.
* @param vektor_cisel Vektor_cisel je referencia na vektor, ktory sa bude vklada do súboru.
* @param subor Subor slui ako referencia na súbor do ktorého sa bude vklada.
*/
void AddVector(vector<long>& vektor_cisel,fstream &subor) {

	for (long cislo : vektor_cisel) {
		subor << cislo << endl;
	}
}

/**
* @brief Funkcia VytvoritSubor slúi na vytvorenie súboru.
* Vyuíva funkciu AddVector() na zápis vektoru do súboru.
* @param subor_txt Slúi na vloenie konkretného  názvu textového súboru, kde sa bude mnoina uklada.
* @param set Obsahuje mnoinu, ktorá sa uloí.

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
* @brief Funkcia StringToVector zabezpeèi, e prevedie naèitany reazec znakov do vektora èísel.
* Istringstream vytvára virtuálny reazcovı prúd, ktorı umoòuje pohodlné èítanie dát z reazca, ktorı je u k dispozícii v pamäti.
* Funkciu pouivam kvôli tomu, e nemusi by vdy isté, e na riadku je èíslo. zároveò to pre mòa slúi aj ako zjednodušenie a potvrdenie, e skutoène pracujem 
*	s vektorom longov a nie s reazcami.
* >>je operator na èitanie z reazca (token je prave naèitany riadok suboru   -retazec-).
* @param subor_txt Slúi ako referencia na názov textového súboru z ktorého sa budu èerpa znaky.
* @param cisla Slúi ako referencia na vektor, do ktorého sa budú vkláda u takımto spôsobom vybrané èísla (push_back)
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
*@brief Táto funkcia NacitatSubor je súèas upraveného súboru. Úplne prvotná funkcia.
*Zaroveò si pomocou neho vieme overi napriklad rozdiel mnoin vïaka tomu, e nie je nijak upravovany, je len naèitany do pola longov.
*Vyuíva aj funkciu StringToVectorLong() pre pohodlnú prácu a ¾ahšiu manipuláciu.
* @param subor_txt Je referencia na konkrétny názov súboru (.txt), ktorı chceme naèíta.
* @return Funkcia vracia vektor èísel naèítanıch zo súboru...je teda pripravená na to, e sa dá vloi do nejakej premeny pre pohodlné operácie.
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
*@brief Funkcia KontrolaPoctuCisel slúi len na úèely kontroly pre tvorcu programu.
* Nijako ju ani nevyuívam vo finále. Išlo len o pokus, èi všetko správne funguje v zaèiatkoch projektu.
* @param vektor_cisel Parametrom je referencia na vektor cisel.
*/
void KontrolaPoctuCisel(vector<long>& vektor_cisel) {
	cout << "Velkost vektora je:" << vektor_cisel.size();


}

/**
* @brief Funkcia RemoveDuplicities slúi na odstránenie rovnakıch èísel v u zoradenom vektore nejakım Sort algoritmom
* Vhodná je pre zoradené pole, pretoe sa tam pracuje systémom porovnávania predchadzajuceho prvku s aktuálne vybranım
* Pridávaju sa do finalneho vektora prvky, ktore su unikatne(nerovnaju sa predchadzajucim)
* @param sorted_vector Ako parameter je referencia na u zoradenı vektor. Názov nás nabáda k tomu, aby sme tam vloili zoradenı vektor, inak to nebude pracova
* správne.
*/
void RemoveDuplicities( vector<long>& sorted_vector) {
	vector<long> final_vector;
	

	
	final_vector.push_back(sorted_vector[0]); // Prida prvı prvok do vıstupného vektoru
	long n = sorted_vector.size();
	// Prejdi cez zvyšné prvky vstupného vektoru
	for (long i = 1; i < n; i++) {
		// Ak sa aktuálny prvok nerovna predchádzajúcemu, prida ho do vıstupného vektoru
		if (sorted_vector[i] != sorted_vector[i - 1]) {
			final_vector.push_back(sorted_vector[i]);
		}
	}

	sorted_vector = final_vector; //nakoniec bude odkazovat na zoradeny vektor bez duplicit
	cout << "Duplicity boli odstranene" << endl;
}


/**
* @brief Funkcia UpravenySubor je hlavna funkcia, ktorej telo tvoria funkcie dostavajuce súbor do idealného stavu pre náš úèel. Máme prostredníctvom nej istotu, e ak do parametru zadáme názov súboru, ktorı chceme pre náš úèel upravi , tak toho skutoène dosiahneme
	*Obsahuje všetky funkcie, ktorı postupne danı súbor upravujú.
*@param nazov_suboru Je referencia na konkretneho (.txt) súboru, ktorı sa má upravi pre náš úèel
* @return Funkcia vráti mnoinu s ktorou sa ïalej dajú vykonáva úèelové operácie (nás teda zaujíma prienik)
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
