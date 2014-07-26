#include "Vector.h"

#ifndef MATRIX
#define MATRIX
class Matrix
{
private:
	int height, width;
	Vector row(int r);
	Vector column(int c);

public:
	Matrix(int h, int w);
	Matrix();
	Matrix operator=(Matrix other); // copy
	void print();

	Matrix operator+=(Matrix other);
	Matrix operator-=(Matrix other);
	Matrix operator*=(Matrix other);
	Matrix operator*=(Scalar scale);
	Matrix operator/=(Scalar scale);

	Matrix operator+(Matrix other);
	Matrix operator-(Matrix other);
	Matrix operator*(Matrix other); // matrix multiplication
	Matrix operator*(Scalar scale);
	Matrix operator/(Scalar scale);
	Vector operator*(Vector v); // action on vector
};
#endif
