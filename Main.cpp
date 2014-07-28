#include "Scalar.h"
#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include <iostream>
using namespace std;


void main()
{
	// TEST MatrixEigen.cpp:
	Matrix M(3, 3);
	M[0][0] =  1;  M[0][1] =  0;  M[0][2] =  0;
	M[1][0] =  0;  M[1][1] = -2;  M[1][2] =  0;
	M[2][0] =  0;  M[2][1] =  0;  M[2][2] =  3;
	cout << "eigenvectors of: " << endl;
	M.print_fancy();
	cout << "are:" << endl;
	M.eigenvectors().print_rowvectors();
	cout << endl;

	Matrix T(3, 3);
	T[0][0] =  1;  T[0][1] =  1;  T[0][2] =  0;
	T[1][0] =  1;  T[1][1] =  2;  T[1][2] =  2;
	T[2][0] =  0;  T[2][1] =  2;  T[2][2] =  3;
	cout << "eigenvectors of: " << endl;
	T.print_fancy();
	cout << "are:" << endl;
	T.eigenvectors().print_rowvectors();


	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
