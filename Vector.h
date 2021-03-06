#include "Scalar.h"
#include "Array.h"

#ifndef VECTOR
#define VECTOR
class Vector: public Array<Scalar>
{
public:
	inline int dimension() const; // gets Array::length
	Vector(); // goes with Array::initialize
	Vector(int d);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other); // copy
	void zero(); // zeroes out all components

	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(Scalar scale);
	Vector& operator/=(Scalar scale);

	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;	
	Vector operator*(Scalar scale) const;
	Vector operator/(Scalar scale) const;

	Scalar operator*(const Vector& other) const; // dot product
	Vector perpendicular(const Vector& axis) const;
	Vector projection(const Vector& axis) const;
	inline Scalar mag2() const;
	inline Scalar mag() const;
	void normalize();
	void positivify();	// standardizes representatives of rays;
						// used in MatrixEigen.cpp (Matrix::biggest_eigenvector)
						// to exit even when eigenvalue negative.
	void intuitive_normalize(); // based on taxicab magnitude with modifications.

	void print() const;
	void print_fancy() const;
	void print_horizontal() const;

};
#endif
