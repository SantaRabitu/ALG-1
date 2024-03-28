#include<iostream>
#include<cmath>
#include<vector>


using namespace std;

class Matica {

public:
	Matica(int rows, int cols);// : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {};

	int GetRows() const {
		return this->rows;
	}

	int GetCols() {
		return this->cols;
	}

	double& GetPrvok(int i, int j){
		return this->data[i][j];
	}

	Matica Add(Matica& mat);
	Matica Multiply( Matica& mat);
	void VypisMatice();
	Matica Exp(int N);
	Matica Sinus(int N);
	Matica Kosinus(int N);


private:
	int rows;
	int cols;
	std::vector<std::vector<double>> data;

};

Matica::Matica(int rows,int cols) {

	this->rows = rows;
	this->cols = cols;
	this->data = std::vector<std::vector<double>>(rows, std::vector<double>(cols, 0.0));


}

Matica Matica::Add(Matica& mat){
	int rows_2 = mat.GetRows();
	int cols_2 = mat.GetCols();

	if (this->rows != rows_2 || this->cols != cols_2) {
		std::cerr << "Matice majú rôzne rozmery." << std::endl;
		exit(1);
	}

	Matica result(this->rows, this->cols);
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			result.GetPrvok(i, j) = this->data[i][j] + mat.GetPrvok(i, j);
		}
	}
	return result;
}

Matica Matica::Multiply(Matica& mat){
	int rows_2 = mat.GetRows();
	int cols_2 = mat.GetCols();

	if (this->cols != rows_2) {
		exit(1);
	}

	Matica result(this->rows, mat.GetCols());
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < mat.GetCols(); ++j) {
			for (int k = 0; k < this->cols; ++k) {
				result.GetPrvok(i, j) += this->data[i][k] * mat.GetPrvok(k, j);
			}
		}
	}
	return result;
}

double factorial(int n) {
	if (n == 0) return 1;
	double result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}
	return result;
}
Matica Matica::Exp(int N) {
	Matica result(this->rows, this->cols);
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			double val = 1;
			double power = 1;
			for (int k = 1; k <= N; ++k) {
				power *= this->data[i][j];
				val += power / factorial(k);
			}
			result.GetPrvok(i, j) = val;
		}
	}
	return result;

}


Matica Matica::Sinus(int N)
{
	if (this->rows != this->cols) {
		exit(1);
	}
	Matica result(this->rows, this->cols);
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			double val = this->data[i][j];
			double power = this->data[i][j];
			int sign = -1;
			for (int k = 2; k <= N; k =k+ 2) {
				power *= this->data[i][j] * this->data[i][j];
				val += sign * power / factorial(k);
				sign *= -1;
			}
			result.GetPrvok(i, j) = val;
		}
	}
	return result;
}

Matica Matica::Kosinus(int N){
	if (this->rows != this->cols) {
		exit(1);
	}
	
	Matica result(this->rows, this->cols);
	
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			double val = 1;
			double power = 1;
			int sign = -1;
			for (int k = 2; k <= N; k += 2) {
				power *= this->data[i][j] * this->data[i][j];
				val += sign * power / factorial(k);
				sign *= -1;
			}
			result.GetPrvok(i, j) = val;
		}
	}
	return result;
}

void Matica::VypisMatice() {
	for (int i = 0; i <this-> rows; ++i) {
		for (int j = 0; j <this-> cols; ++j) {
			cout << this->data[i][j] << " ";
		}
		cout << endl;
	}
}


//2-rekurzia:
double powerR(double x, int n) {

	// power(x, 0) = 1;
	if (n ==0) {
		return 1;

	}

	double half = powerR(x, n / 2);
	if (n % 2 == 0) {
		return (half * half);
	}
	else {
		return(half * half * x);
	}
}

//2.Iterativna forma:

double powerI(double x, int n) {

	double resultI = 1;
	while(n>0){
	if (n % 2 == 1) {
		resultI *= x;
	}
	x *= x;
	n /= 2;
}
return resultI;
}


int main() {

	Matica mat1(3, 3);
	mat1.GetPrvok(0, 0) = -1;
	mat1.GetPrvok(0, 1) = 2;
	mat1.GetPrvok(0, 2) = 1;
	mat1.GetPrvok(1, 0) = 2;
	mat1.GetPrvok(1, 1) = 0;
	mat1.GetPrvok(1, 2) = 4;
	//mat1.GetPrvok(2, 0) = 1;
	//mat1.GetPrvok(2, 1) = 2;
	//mat1.GetPrvok(2, 2) = 3;

	Matica mat2(3, 3);
	mat2.GetPrvok(0, 0) = 2;
	mat2.GetPrvok(0, 1) = -3;
	//mat2.GetPrvok(0, 2) = 6;
	mat2.GetPrvok(1, 0) = 1;
	mat2.GetPrvok(1, 1) = 4;
	//mat2.GetPrvok(1, 2) = 8;
	mat2.GetPrvok(2, 0) = -2;
	mat2.GetPrvok(2, 1) = 3;
	//mat2.GetPrvok(2, 2) = 6;

	cout << endl;
	mat1.VypisMatice();
	cout << endl;
	mat2.VypisMatice();
	cout << endl;
	// Sèítanie matíc
	Matica sum = mat1.Add(mat2);
	cout << "sum:" << endl;	
	sum.VypisMatice();

	// Násobenie matíc
	Matica product = mat1.Multiply(mat2);
	cout << "multiply:" << endl;
	product.VypisMatice();

	Matica matica_test(3, 3);
	matica_test.GetPrvok(0, 0) = 1;
	matica_test.GetPrvok(0, 1) = 2;
	matica_test.GetPrvok(0, 2) = 3;
	matica_test.GetPrvok(1, 0) = 4;
	matica_test.GetPrvok(1, 1) = 5;
	matica_test.GetPrvok(1, 2) = 6;
	matica_test.GetPrvok(2, 0) = 7;
	matica_test.GetPrvok(2, 1) = 8;
	matica_test.GetPrvok(2, 2) = 9;
	
	cout << endl;
	matica_test.VypisMatice();
	cout << endl;

	Matica exp_mat = matica_test.Exp(2);
	cout << "Exponenciala:" << endl;
	exp_mat.VypisMatice();
	cout << endl;

	Matica sin_mat = matica_test.Sinus(2);
	cout << "Sinus:" << endl;
	sin_mat.VypisMatice();
	cout << endl;

	Matica cos_mat = matica_test.Kosinus(2);
	cout << "Cosinus:" << endl;
	cos_mat.VypisMatice();
	cout << endl;
	//èo sa týka zložitosti tak vždy je to vzhladom na velkost matice , ale nebudem klamat, nie som si s tymto moc isty :D :D




// 2.rekurzia a iteracia:

	double x = 2;
	int n = 6;

	double result2r = powerR(x, n);
	cout << "Rekurzia:" << result2r << endl;

	double x2 = 2;
		int n2 = 7;
		double resultI = powerI(x2, n2);
		cout << "Iteracia" << resultI << endl;




	return 0;
}




