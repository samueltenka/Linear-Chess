#include "Scalar.h"
#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include <iostream>
using namespace std;


void main()
{
	// TEST MatrixEigen.cpp on large matrices:
	Matrix M(100, 100);
	for(int r = 0; r < 100; r++)
	{
		for(int c = 0; c <= r; c++)
		{
			M[c][r] = M[r][c] = rand()%5;
		}
	}
	cout << "First two eigenvectors of M" << endl;
	cout << "are:" << endl;
	Matrix E = M.eigenvectors(2);
	E.print_fancy();

	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
