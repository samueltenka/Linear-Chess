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
	void positivify();	// used as standardizer in Matrix::biggest_eigenvector
						// to exit even when eigenvalue negative.

	void print() const;
	void print_fancy() const;
	void print_horizontal() const;

};
#endif
