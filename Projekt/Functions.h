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
*@brief Funkcia PrintVector sl��i na vyp�sanie obsahu vektora.
* Z�de sa n�m hlavne na kontrolu.
* @param vektor_cisel  Vektor_cisel je parameter, ktory sl��i na uchovavanie vektoru, ktory chceme vyp�sat.
*/
void PrintVector(vector<long>& vektor_cisel) {

	for (long cislo : vektor_cisel) {
		cout << cislo << endl;

	}
	cout << endl;
}

/**
* @brief Funkcia AddVector n�m sl��i na vlo�enie vektoru do s�boru v takom tvare, ak� sp��a aj testovac� s�bor.
* @param vektor_cisel Vektor_cisel je referencia na vektor, ktory sa bude vklada� do s�boru.
* @param subor Subor slu�i ako referencia na s�bor do ktor�ho sa bude vklada�.
*/
void AddVector(vector<long>& vektor_cisel,fstream &subor) {

	for (long cislo : vektor_cisel) {
		subor << cislo << endl;
	}
}

/**
* @brief Funkcia VytvoritSubor sl��i na vytvorenie s�boru.
* Vyu��va funkciu AddVector() na z�pis vektoru do s�boru.
* @param subor_txt Sl��i na vlo�enie konkretn�ho  n�zvu textov�ho s�boru, kde sa bude mno�ina uklada�.
* @param set Obsahuje mno�inu, ktor� sa ulo��.

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
* @brief Funkcia StringToVector zabezpe�i, �e prevedie na�itany re�azec znakov do vektora ��sel.
* Istringstream vytv�ra virtu�lny re�azcov� pr�d, ktor� umo��uje pohodln� ��tanie d�t z re�azca, ktor� je u� k dispoz�cii v pam�ti.
* Funkciu pou�ivam kv�li tomu, �e nemusi by� v�dy ist�, �e na riadku je ��slo. z�rove� to pre m�a sl��i aj ako zjednodu�enie a potvrdenie, �e skuto�ne pracujem 
*	s vektorom longov a nie s re�azcami.
* >>je operator na �itanie z re�azca (token je prave na�itany riadok suboru   -retazec-).
* @param subor_txt Sl��i ako referencia na n�zov textov�ho s�boru z ktor�ho sa budu �erpa� znaky.
* @param cisla Sl��i ako referencia na vektor, do ktor�ho sa bud� vkl�da� u� tak�mto sp�sobom vybran� ��sla (push_back)
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
*@brief T�to funkcia NacitatSubor je s��as� upraven�ho s�boru. �plne prvotn� funkcia.
*Zarove� si pomocou neho vieme overi� napriklad rozdiel mno�in v�aka tomu, �e nie je nijak upravovany, je len na�itany do pola longov.
*Vyu��va aj funkciu StringToVectorLong() pre pohodln� pr�cu a �ah�iu manipul�ciu.
* @param subor_txt Je referencia na konkr�tny n�zov s�boru (.txt), ktor� chceme na��ta�.
* @return Funkcia vracia vektor ��sel na��tan�ch zo s�boru...je teda pripraven� na to, �e sa d� vlo�i� do nejakej premeny pre pohodln� oper�cie.
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
*@brief Funkcia KontrolaPoctuCisel sl��i len na ��ely kontroly pre tvorcu programu.
* Nijako ju ani nevyu��vam vo fin�le. I�lo len o pokus, �i v�etko spr�vne funguje v za�iatkoch projektu.
* @param vektor_cisel Parametrom je referencia na vektor cisel.
*/
void KontrolaPoctuCisel(vector<long>& vektor_cisel) {
	cout << "Velkost vektora je:" << vektor_cisel.size();


}

/**
* @brief Funkcia RemoveDuplicities sl��i na odstr�nenie rovnak�ch ��sel v u� zoradenom vektore nejak�m Sort algoritmom
* Vhodn� je pre zoraden� pole, preto�e sa tam pracuje syst�mom porovn�vania predchadzajuceho prvku s aktu�lne vybran�m
* Prid�vaju sa do finalneho vektora prvky, ktore su unikatne(nerovnaju sa predchadzajucim)
* @param sorted_vector Ako parameter je referencia na u� zoraden� vektor. N�zov n�s nab�da k tomu, aby sme tam vlo�ili zoraden� vektor, inak to nebude pracova�
* spr�vne.
*/
void RemoveDuplicities( vector<long>& sorted_vector) {
	vector<long> final_vector;
	

	
	final_vector.push_back(sorted_vector[0]); // Prida prv� prvok do v�stupn�ho vektoru
	long n = sorted_vector.size();
	// Prejdi cez zvy�n� prvky vstupn�ho vektoru
	for (long i = 1; i < n; i++) {
		// Ak sa aktu�lny prvok nerovna predch�dzaj�cemu, prida ho do v�stupn�ho vektoru
		if (sorted_vector[i] != sorted_vector[i - 1]) {
			final_vector.push_back(sorted_vector[i]);
		}
	}

	sorted_vector = final_vector; //nakoniec bude odkazovat na zoradeny vektor bez duplicit
	cout << "Duplicity boli odstranene" << endl;
}


/**
* @brief Funkcia UpravenySubor je hlavna funkcia, ktorej telo tvoria funkcie dostavajuce s�bor do idealn�ho stavu pre n� ��el. M�me prostredn�ctvom nej istotu, �e ak do parametru zad�me n�zov s�boru, ktor� chceme pre n� ��el upravi� , tak toho skuto�ne dosiahneme
	*Obsahuje v�etky funkcie, ktor� postupne dan� s�bor upravuj�.
*@param nazov_suboru Je referencia na konkretneho (.txt) s�boru, ktor� sa m� upravi� pre n� ��el
* @return Funkcia vr�ti mno�inu s ktorou sa �alej daj� vykon�va� ��elov� oper�cie (n�s teda zauj�ma prienik)
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
