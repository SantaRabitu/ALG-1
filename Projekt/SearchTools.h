#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::string;
using std::fstream;
using std::ios;
using std::get;
using std::swap;

/* Binary search is a remarkably efficient algorithm for searching in a sorted array
* Levitin p150;
ALGORITHM BinarySearch(A[0..n−1], K)
//Implements nonrecursive binary search
//Input: An array A[0..n − 1]sorted in ascending order and
//
a search key K
//Output: An index of the array’s element that is equal to K
//
or −1if there is no such element
l ←0; r←n−1
while l ≤ r do
m←(l + r) / 2
if K = A[m]return m
else if K < A[m] r ←m−1
else l ←m + 1
return −1
*/

/**
* @brief Funkcia BinarySearch reprezentuje algoritmus binarneho vyhladavania, ktory sluzi na hladanie klucovych cisel v uz zoradenom poli.
*  Levitin p150.
* Funguje to na principe porovnavania so stredom pola a posuvania bud vlavo alebo vpravo.
* Pre potreby kodu som funkciu upravil tak, aby nevracala index kluca, ale boolean hodnotu.
* Algoritmus je velmi lahko pochopitelny a implementovatelny za cenu logaritmickej zlozitosti.
* @param sorted_vector je referencia na uz usporiadany vektor cisel pre pracu.
* @param key Sluzi ako hladany prvok.
* @return Funkcia vracia false v pripade neuspechu.
*/

bool BinarySearch(const vector<long>&sorted_vector,long key) {

	long n = sorted_vector.size();


	long left=0;
	long right=n-1;
	long middle = 0;


	while (left <= right) {

		middle = (left + right) / 2;

		if (key == sorted_vector[middle]) {
			return true;
		}
		else if (key < sorted_vector[middle]) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}

		
	}
	return false;
}

//Intersection

/**
* @brief Funkcia Intersection vytvori nami vyzadovany prienik dvoch mnozin. Je to teda mnozinova operacia, ktoru chceme v tomto projekte docielit.
* Funkcia pouziva funkciu BinarySearch(), ktora tu sluzi na vyhladavanie rovnakych cisel v oboch mnozinach ako kluce.
* V pripade ze sa tam dane cislo nachadza, vlozi ho do vektora kde je prienik.
* Zlozitost by tak mala byt O(mlogn) kedze prechadza jednu mnozinu a hlada v nej kluce z binarneho vyhladavania z mnoziny druhej.
* @param set1 Ocakava sa vlozenie prvej mnoziny.
* @param set2 Ocakava sa ako vstup druha mnozina.
* @return Funkcia vracia vektor, v ktorom je prienik mnozin vykonany.
*/

vector<long> Intersection(vector<long>&set1, vector<long>&set2) {

	vector<long> prienik;
	//long kluce;

	for ( long kluce : set1) {

		if (BinarySearch(set2, kluce)) {
			prienik.push_back(kluce);
		}

	}

	/*Kontrola*/
	//cout << "Prienik hotovy" << endl;
	return prienik;
	
}

/**
	*@brief Funkciu rozdiel množín som vytvoril za účelom dokázať, že rozdiel dvoch rovnakých množín je prázdna množina.
	* Z toho vyplýva, že ak použijeme túto funkciu na nami vytvorený prienik a prienik v testovacom súbore...ak sme správne pracovali, výstupný súbor
	* bude prázdna množina.
	* Vypliva to vsetko z operacii s mnozinami
	* @param set1 prijma ako parameter prvu mnozinu
	* @param set2 prijma ako parameter druhu mnozinu
	*@return Funkcia vráti vektor, kde je rozdiel množín vykonaný.
	*/
vector<long>RozdielMnozin(vector<long>& set1, vector<long>& set2) {

	

	vector<long>rozdiel;

	for (long kluce : set1) {

		if (!BinarySearch(set2, kluce)) {
			rozdiel.push_back(kluce);
		}
	}/*Kontrola
	 
	*cout << "Rozdiel hotovy" << endl;
	*/
	return rozdiel;
}