#include <iostream>

using namespace std;

template <class T>class MatrixNM;
template <class T>ostream &operator<<(ostream &out, const MatrixNM<T>&);

//template MatrixNM
template <class T> MatrixNM<T> &operator*(MatrixNM<T>&);


template <class T>
class MatrixNM {
public:
	int rows, columns;
	T **A;
public:
	//Constructor
	MatrixNM() { rows = 0; columns = 0; }

	//Parameterised Constructor
	MatrixNM(int Rows, int Cols) {
		rows = Rows;
		columns = Cols;
		A = new T*[rows];
		for (int i = 0; i<rows; i++)
			A[i] = new T[columns];
	}

	//VectorND Constructor
	MatrixNM(int Rows) {
		rows = Rows;
		columns = 1;
		A = new T*[rows];
		for (int i = 0; i<rows; i++)
			A[i] = new T[columns];
	}

	void displayMatrixNM(); //print
	MatrixNM<T>& operator* (MatrixNM<T> &X);//Matrix Multiply overloading
	friend ostream &operator<< <T>(ostream &out, const MatrixNM<T> &X);

};

template <class T>
void MatrixNM<T>::displayMatrixNM() {
	for (int i = 0; i<rows; i++) {
		cout << "|";
		for (int j = 0; j<columns; j++)
			cout << A[i][j] << " ";

		cout << "|" << endl;
	}
	
}

template <class T>
MatrixNM<T> &MatrixNM<T>::operator*(MatrixNM<T> &X) {
	T sum = 0;
	if (columns = X.rows) {
		MatrixNM<T> Q(rows, X.columns);
		for (int i = 0; i<rows; i++) {
			for (int j = 0; j<X.columns; j++) {
				for (int k = 0; k<columns; k++)
					sum += A[i][k] * (X.A[k][j]);
				Q.A[i][j] = sum;
				sum = 0;
			}
		}
		return Q;
	}
	else {
		cout << "Error";
		return *this;
	}
}

int main() {
	MatrixNM<double> x(3, 3);
	MatrixNM<double> y(3);
	MatrixNM<double> z(3);

	// initialization 
	for (int i = 0; i < x.rows; i++)
		for (int j = 0; j < x.columns; j++)
			x.A[i][j] = i + j;

	for (int i = 0; i<x.rows; i++)
		for (int j = 0; j<x.columns; j++)
			y.A[i][j] = i + j;

	// Multiply
	z = x*y;

	// print
	z.displayMatrixNM();
	return 0;
}