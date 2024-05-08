#include"Functions.h"

/**
*@ brief Zoznam použitých súborov na testovanie.
* Súbory vo formáte .txt uložené v prieèinku, kde je uložený projekt.


*"CvicnyA.txt//
*"CvicnyB.txt//
*"CvicnyC.txt//

*"SourceSeqA.txt"//
*"SourceSeqB.txt"//

*"Intersection.txt"//

*/

/**
	*@brief Telo celého programu.
	* @return Program vráti 0 po správnom ukonèení.
	*/
int main() {
	

	cout << "Program sa spustil" << endl;
	
	vector<long> set1=UpravenySubor("SourceSeqA.txt");
	vector<long> set2 = UpravenySubor("SourceSeqB.txt");
	vector<long> prienik = Intersection(set1, set2);
	vector<long> prienik_test_data = NacitatSubor("Intersection.txt");

	vector<long> a_minus_b = RozdielMnozin(prienik,prienik_test_data);
	
	VytvoritSubor("overenie.txt",a_minus_b );
	VytvoritSubor("pruniik.txt", prienik);



	//PrintVector(set3);

//	cout << endl << endl;
//	UpravenySubor("CvicnyB.txt");

	

	return 0;
}



