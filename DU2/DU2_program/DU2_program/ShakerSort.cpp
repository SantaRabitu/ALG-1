#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<chrono>
#include<cmath>


using namespace std;


vector<int> GenerateRandomVector(int length, int minVal, int maxVal) {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int>distribution(minVal, maxVal);
	vector<int> result;
	result.reserve(length); //better then series of push_backs

	for (int i = 0; i < length; ++i) {
		 result.push_back(distribution(gen));
	}
	 return result;

}

/*
Algorithm 2 leftToRight(A, Lef t, Right)
1: j ← 0; j==0;
2: for i ← Lef t to Right − 1 do i<right;i++
3 : if A[i] > A[i + 1] then
4: Swap(A[i], A[i + 1]);
5: j ← i;
6: end if
7 : end for
8 : Right ← j;
Algorithm 3 rightToLeft(A, Lef t, Right)
1: j ← 0;
2: for i ← Right downto Lef t + 1 do i--i musi byt vacsie ako left
3 : if A[i − 1] > A[i] then
4: Swap(A[i − 1], A[i]);
5: j ← i;
6: end if
7 : end for
8 : Lef t ← j;

*/


bool LeftToRight(vector<int>& A, int& left, int& right) {

	bool swapped = false;
	int j = 0;

	for (int i = left; i < right; i++) {
		if (A[i] > A[i + 1]) {
			swap(A[i], A[i + 1]);
			j = i;
			swapped = true;
		}
	}

	right = j;
	return swapped;
}

bool RightToLeft(vector<int>& A, int& left, int& right) {

	bool swapped = false;
	int j = 0;

	for (int i = right; i > left; i--) {

		if (A[i - 1] > A[i]) {

			swap(A[i - 1], A[i]);
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




void ShakerSort(vector<int>& A) {

	int n = A.size();
	int left = 0;
	int right = n - 1;
	
	while (left < right) {

		bool leftSwapped = LeftToRight(A, left, right);

		bool rightSwapped = false;
		if (!leftSwapped) {

			rightSwapped = RightToLeft(A, left, right);
		}

		if (!leftSwapped && !rightSwapped) {
			break;
		}
	}

}

double rozdielcasu(double d1,double d2){

	if (d1 < d2) {   ///d1 je introsort d2 shakesort

		cout << "IntroSort je rychlejsi o :";
		return d2- d1;/// 3-5 =-2

	}
	else if (d2 < d1) {
		cout << "ShakerSort je rychlejsi o: ";
		return d1 - d2;
	}
	else {
		cout << "rovnake" << endl;
		return 0.0;
	}

	
}

int main() {


	vector<int> RandomVector = GenerateRandomVector(25, 5, 60);

	int velkost = RandomVector.size();
/*
	//introsort
	auto start = chrono::high_resolution_clock::now();
	 sort(RandomVector.begin(), RandomVector.end());
	auto end = chrono::high_resolution_clock::now();
	 chrono::duration < double > duration = end - start;
	cout << " Time taken to sort the vector : " << duration.count() << "seconds " <<endl ;


	*/

	
	cout << "introsort" << endl;
	cout << endl;

	cout << "Povodny vektor:" << endl;

	for (int i = 0; i < velkost; i++) {

		cout << RandomVector[i] << ",";
	}
	cout << endl;

	

	vector<int> zaloha = RandomVector;

	auto startintr = chrono::high_resolution_clock::now();
	sort(zaloha.begin(), zaloha.end());
	auto endintr = chrono::high_resolution_clock::now();
	chrono::duration < double > durationintr = endintr - startintr;

	cout << "Usporiadany vektor:" << endl;

	for (int i = 0; i < velkost; i++) {

		cout << zaloha[i] << ",";
	}
	cout << endl;

	cout << " Time taken to sort the vector : " << durationintr.count() << "seconds " << endl;

	cout << endl;


	//shakersort
	//auto newVector = RandomVector;
	cout << "Shakersort" << endl;
	cout << endl;
	vector<int> newVector = RandomVector;


	
	auto start = chrono::high_resolution_clock::now();
	ShakerSort(newVector);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration < double > duration = end - start;
	
	cout << "Povodny vektor:" << endl;
	for (int i = 0; i < velkost; i++) {
		cout << RandomVector[i] << ",";
	}
	cout << endl;

	cout << "Usporiadany vektor:" << endl;
	for (int i = 0; i < velkost; i++) {
		cout << newVector[i] << ",";
	}
	cout << endl;
	
	cout << " Time taken to sort the vector : " << duration.count() << "seconds " << endl;

	


	cout << endl;

	double rozdiel = rozdielcasu(abs(durationintr.count()), duration.count());
	cout << rozdiel<< "sekund" << endl;


	

	return 0;
}
