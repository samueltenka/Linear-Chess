#include "Scalar.h"
#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include <iostream>
using namespace std;


void main()
{
	// TEST MatrixEigen.cpp on large matrices:
	Matrix M(20, 20);
	for(int r = 0; r < 20; r++)
	{
		for(int c = 0; c <= r; c++)
		{
			M[c][r] = M[r][c] = rand()%5;
		}
	}
	cout << "computing eigenvectors..." << endl;
	Matrix E = M.eigenvectors(20);
	E[19].print_fancy();
	Vector V = M*E[19];
	V.normalize();
	V.print_fancy();
	cout << "done!" << endl;

	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
