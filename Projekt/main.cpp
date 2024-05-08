#include"Functions.h"

/**
*@ brief Zoznam pou�it�ch s�borov na testovanie.
* S�bory vo form�te .txt ulo�en� v prie�inku, kde je ulo�en� projekt.


*"CvicnyA.txt//
*"CvicnyB.txt//
*"CvicnyC.txt//

*"SourceSeqA.txt"//
*"SourceSeqB.txt"//

*"Intersection.txt"//

*/

/**
	*@brief Telo cel�ho programu.
	* @return Program vr�ti 0 po spr�vnom ukon�en�.
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



