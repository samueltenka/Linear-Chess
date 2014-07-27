#include "Scalar.h"
#include "Array.h"


#ifndef VECTOR
#define VECTOR
class Vector: public Array<Scalar>
{
private:
	int dimension;

public:
	Vector(int d);
	Vector();
	Vector& operator=(Vector& other); // copy
	void print();
	void print_fancy();

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
};
#endif
