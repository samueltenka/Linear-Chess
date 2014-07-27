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
	
	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
