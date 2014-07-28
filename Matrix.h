#include "Vector.h"

#ifndef MATRIX
#define MATRIX
class Matrix: public Array<Vector>	// array of rows
									// so access as M[r][c]
{
private:
	int height, width;

	Vector row(int r) const; // used for arithmetic
	Vector column(int c) const; //  ` ` `

public:

	Matrix(int h, int w);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other); // copy

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(Scalar scale);
	Matrix& operator/=(Scalar scale);

	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other); // matrix multiplication
	Matrix operator*(Scalar scale);
	Matrix operator/(Scalar scale);
	Vector operator*(const Vector& v); // action on vector

	void print();
	void print_fancy();
};
#endif
