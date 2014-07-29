#include "Scalar.h"
#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include <iostream>
using namespace std;


void main()
{
	// TEST PCA.cpp:
	Matrix M(5, 3);
	Vector	V0(3),
			V1(3),
			V2(3), 
			V3(3), 
			V4(3);
	V0[0] = 0.0;
	V0[1] = 0.0;
	V0[2] = 0.0;

	V1[0] = 1.0;
	V1[1] = 1.0;
	V1[2] = 1.0;

	V2[0] = 2.0;
	V2[1] = 2.0;
	V2[2] = 2.0;

	V3[0] = 1.1;
	V3[1] = 0.9;
	V3[2] = 1.0;

	V4[0] = 1.2;
	V4[1] = 0.8;
	V4[2] = 1.001;

	M[0] = V0;
	M[1] = V1;
	M[2] = V2;
	M[3] = V3;
	M[4] = V4;
	
	cout << "The principal components of the following dataset " << endl;
	M.print_rowvectors();
	
	Matrix P = M.principal_components(3);
	cout << "are: " << endl;
	P.print_fancy();
	
	cout << "or, more intuitively scaled: " << endl;
	P.print_fancy_intuitive();

	Matrix C(M);
	//C.center();
	//C.print_fancy();
	

	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
