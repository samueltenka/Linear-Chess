#include "Scalar.h"
#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include <iostream>
using namespace std;

void main()
{
	Array<int> A(3);
	A[0] = 0;
	A[1] = 3;
	A[2] = 1;

	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
