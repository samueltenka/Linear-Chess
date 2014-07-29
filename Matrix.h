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

	// Eigenstuff:
private:
	void remove_from_span(Vector target);
	Vector biggest_eigenvector() const; // probabilistic: might not exit, and might not be biggest.
public:
	Matrix eigenvectors(int number) const;	// returns top number-many eigenvectors, by eigen-value,
											// as (orthonormal) rows. In other words, so that:
											// V*rtrn changes standard coordinates into eigenbasis-coordinates.

	// PCA stuff (builds on Eigenstuff):
	// (here, we interpret input matrices as scatterclouds of rows)
	Matrix transpose() const;
	Vector center_of_mass() const;
	void center(); // centers scattercloud around zero.
	Matrix covariance_matrix() const;
	Matrix principal_components(int number) const;

	//
	// Printing:
	void print() const;
	void print_fancy() const;
	void print_fancy_intuitive() const;
	void print_rowvectors() const;
};
#endif
