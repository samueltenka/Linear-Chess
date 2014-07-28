#include "Vector.h"

#ifndef MATRIX
#define MATRIX
class Matrix: public Array<Vector>	// array of rows
									// so access as M[r][c]
{
private:
	int height, width;

	Vector row(int r) const;	// used for arithmetic
	Vector column(int c) const;	//  ` ` `

public:
	Matrix(int h, int w);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other); // copy

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(Scalar scale);
	Matrix& operator/=(Scalar scale);

	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const; // matrix multiplication
	Matrix operator*(Scalar scale) const;
	Matrix operator/(Scalar scale) const;
	Vector operator*(const Vector& v) const; // action on vector

private:
	void remove_from_span(Vector target);
	Vector biggest_eigenvector() const; // probabilistic: might not exit, and might not be biggest.
public:
	Matrix eigenvectors() const;	// rows of rtrn are (orthonormal) eigenvectors,
									// so that V*rtrn changes standard coordinates into eigenbasis-coordinates.

	void print() const;
	void print_fancy() const;
	void print_rowvectors() const;
};
#endif
