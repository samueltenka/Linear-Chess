#include "Scalar.h"
#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include <iostream>
using namespace std;


void main()
{
	// TEST MatrixArithmetic.cpp:
	Matrix M(3, 3);
	M[0][0] =  0;  M[0][1] = +1;  M[0][2] = +2;
	M[1][0] = +2;  M[1][1] =  0;  M[1][2] = +1;
	M[2][0] = -1;  M[2][1] = -1;  M[2][2] =  0;
	M.print_fancy();

	cout << "squared: " << endl;
	(M*M).print_fancy();

	cout << "doubled: " << endl;
	(M+M).print_fancy();

	Vector V(3);
	V[0] = 1;
	V[1] = 2;
	V[2] = 4;
	cout << "on vector: " << endl;
	(M*V).print_fancy();

	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
