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

	Scalar mag();
	void normalize();

	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(Scalar scale);
	Vector& operator/=(Scalar scale);

	Vector operator+(const Vector& other);
	Vector operator-(const Vector& other);	
	Vector operator*(Scalar scale);
	Vector operator/(Scalar scale);

	Scalar operator*(const Vector& other); // dot product

	void print();
	void print_fancy();
	void print_horizontal();

};
#endif
