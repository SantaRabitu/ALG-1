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
using std::swap;

/*
bool LeftToRight(vector<long>& vektor_cisel, long& left, long& right) {
	long pocet_iteracii=0;
	bool swapped = false;
	long j = 0;

	for (long i = left; i <= right-1; i++) {
		if (vektor_cisel[i] > vektor_cisel[i + 1]) {
			swap(vektor_cisel[i], vektor_cisel[i + 1]);
			j = i;
			swapped = true;
		}

		pocet_iteracii++;
	}

	right = j;
	return swapped;
}

bool RightToLeft(vector<long>& vektor_cisel, long& left, long& right) {

	bool swapped = false;
	long j = 0;

	for (long i = right; i > left; i--) {

		if (vektor_cisel[i - 1] > vektor_cisel[i]) {

			swap(vektor_cisel[i - 1], vektor_cisel[i]);
			j = i;
			swapped = true;
		}
	}

	left = j;
	return swapped;
}




/*
Algorithm 1 shakerSort(A)
1: Lef t ← 0;
2: Right ← n − 1; menej ako velkost
3: repeat   while
4 : LeftToRight(A, Lef t, Right);
5: RightToLeft(A, Lef t, Right);
6: until Lef t ≥ Right;  nejaky while left je mensi ako right
*/

/*

void ShakerSort(vector<long>& vektor_cisel) {

	long n = vektor_cisel.size();
	long left = 0;
	long right = n - 1;

	while (left <= right) {

		bool leftSwapped = LeftToRight(vektor_cisel, left, right);

		bool rightSwapped = false;
		if (!leftSwapped) {

			rightSwapped = RightToLeft(vektor_cisel, left, right);
		}

		if (!leftSwapped && !rightSwapped) {
			break;
		}
	}

	cout << "Zosortovane" << endl;

}
*/
/*
*Shaker sort neefektívny pre velké pole
* Ukazalo sa, že je nezbytné použiť rychlejši algoritmus s logaritmickou zložitosťou
* ShakerSort je zaujímavý pri menšom počte čísel, pri cvičných súborom s nižším obsahom všetko fungovalo správne, ale na základe
* veľkosti vstupu bolo treba skúsiť iný, lepší algoritmus
*/




//quicksort   //oproti staršiemu MergeSortu sa triedi rozdelovanim a nie zlucovanim
/*
* Pseudokód:
*/
/* ALGORITHM Quicksort(A[l..r])
 //Sorts a subarray by quicksort
 //Input: Subarray of array A[0..n − 1], defined by its left and right
 //
 indices l and r
 //Output: Subarray A[l..r] sorted in nondecreasing order
 if l<r
 s ←Partition(A[l..r]) //s is a split position pivot
 Quicksort(A[l..s − 1])
 Quicksort(A[s + 1..r])
 //Levitin 176

  ALGORITHM HoarePartition(A[l..r])
 as a pivot
 //Partitions a subarray by Hoare’s algorithm, using the first element
 //
 //Input: Subarray of array A[0..n − 1], defined by its left and right
 //
 indices l and r(l<r)
 //Output: Partition of A[l..r], with the split position returned as
 //
 this function’s value
 p ←A[l] //pivot
 i ←l; j ←r+1
 repeat
 repeat i ←i +1 (i++)until A[i]≥p (while a[i]<pivot)
 repeat j ←j −1 (j--)until A[j]≤p (while a[j]>pivot
 swap(A[i],A[j])
 until i ≥ j (while i<j) mozno if
 swap(A[i],A[j]) //undo last swap when i ≥ j
 swap(A[l],A[j])
 return j
 
 
 */

/**
*@brief HoareDelenie je funkcia, ktorá využíva algoritmus Hoare Partition. Algoritmus má za úlohu rozdeliť pole čísel
*spočívajúci vo výbere nového indexu pivota pre algoritmus Quick Sort. Oproti Lomuto Partition je zložitosť finalneho sortu O(N). Berie totiž prvý prvok pola ako pivot a 2 indexy (i,j),ktore sa ku sebe približuju.
* umiestnuje všetky prvky menšie ako pivot na lavu stranu a vačšie ako pivot na pravu stranu.
* @param array je referencia na vektor v ktorom sa bude daný pivot hladať a ktorý bude rozdelovaný
* @param left Má za úlohu zobrať si nultý index prvku z pola ako pivot.
* @param right Slúži na zachytenie posledného indexu prvku pola (n-1)
* @return Funkcia vráti index pivotu keď lavy index prekroci pravy.
*/


long HoareDelenie(vector<long>& array, long left, long right) {
	long pivot = array[left];
	long i = left-1;
	long j = right + 1;

	while (1) {
		do {
		i++;
		}
		while (array[i] < pivot);
		do {
		j--;
		} 
		while (array[j] > pivot);
		if (i >= j) {
			return j; 
		}
		swap(array[i], array[j]);
	}
	
}

/**
* @brief Funkcia QuickSortRekurzia slúži na jej rekurzivne volanie, Obsahuje už aj implementaciu Hoareho Delenia, konkrétne vieme zistiť aj index pivotu potrebny pre ucel rekurzie.
* funkcia QuickSortRekurzia sa tu volá 2 krát. Raz pre lavu stranu po index pivota (bez neho), druhýkrát pre pravú stranu od indexu pivota. Je to ideálne pre veľké polia, že sa to takto delí. V takomto prípade je teda zložitosť logaritmická
* @param array Slúži na zadanie vstupného pola vektoru
* @param left Popisuje nám lavú stranu tohto vektora za účelom indexu - lava strana by mala byt vzdy mensia pre ucel algoritmu, kedze sa to bude rekurzivne volat a velakrat menit.
* @param right Popisuje nám pravú stranu tohto vektora za účelom indexu
*/



void QuickSortRekurzia(vector<long>& array, long left, long right) {
	if (left < right) {
		long index_pivot =HoareDelenie(array, left, right);
		
		/*Hoare*/
		QuickSortRekurzia(array, left, index_pivot);
		QuickSortRekurzia(array, index_pivot + 1, right);
	}
}

/**
* @brief Funkcia QuickSort obsahujúca rekurzivne volanie pre celu dlzku pola zabezpecuje rychly a efektivny sposob triedenia so zlozitostou O(nlogn) pre ucely
* velkych vstupov ovela efektivnejsi ako pôvodny ShakerSort, ktory som implementoval. Oproti starsiemu algoritmu Merge Sort triedi rozdelovanim a nie zlucovanim.
* *Rozdel a panuj

*	1. krok: analýza – rozdělení problému
*	2. krok : rekurze pro řešení problémů menšího rozsahu
*	3. krok : syntéza – z řešení menších problémů se syntetizuje řešení původního problému

*(Jiři Prokop:Algoritmy v jazyku C a C++ ,st 43.
* @param array Je referencia na vstupne pole.
*/
void QuickSort(vector<long>& array) {
	long n = array.size();
	QuickSortRekurzia(array, 0, n - 1);
	/*
	*Kontrola
	*cout << "Zosortovane" << endl;
	 */
}
