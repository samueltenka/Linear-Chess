#include "Scalar.h"
#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include <iostream>
using namespace std;


void main()
{
	// TEST VectorArith.cpp:
	Vector V(3);
	V[0] = 1;
	V[1] = 2;
	V[2] = 4;
	Vector W(3);
	W = V;
	W += (W+V*2)/2;
	V.normalize();

	cout << "V = " << endl;
	V.print_fancy();
	cout << "|V| = " << V.mag() << endl;
	cout << "W = " << endl;
	W.print_fancy();
	cout << "|W| = " << W.mag() << endl;

	// TEST MatrixBasic.cpp:
	Matrix M(3, 3);
	M[0][0] =  0;  M[1][0] = +1;  M[2][0] = +2;
	M[0][1] = +2;  M[1][1] =  0;  M[2][1] = +1;
	M[0][2] = -1;  M[1][2] = -1;  M[2][2] =  0;
	Matrix A(M);
	Matrix S = A;
	S.print_fancy();

	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
