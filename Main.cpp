#include "Scalar.h"
#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include <iostream>
using namespace std;

void main()
{
	// TEST VectorBasic.cpp:
	Vector V(5);
	V[0] = 0;
	V[1] = 3;
	V[2] = -9.8;
	V[3] = 3;
	V[4] = 1;
	V.print_fancy();

	Vector W(5);
	W = V;
	W.print_fancy();

	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
