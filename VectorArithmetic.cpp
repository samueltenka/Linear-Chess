#include "Vector.h"
#include <math.h>

// 
// Norm stuff:
Scalar Vector::mag()
{
	return sqrt((*this) * (*this));
}
void Vector::normalize()
{
	(*this) /= mag();
}

// 
// Operator-Equals:
Vector& Vector::operator+=(const Vector& other)
{
	for(int r = 0; r < dimension; r++)
	{
		(*this)[r] += other[r];
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& other)
{
	for(int r = 0; r < dimension; r++)
	{
		(*this)[r] -= other[r];
	}
	return *this;
}
Vector& Vector::operator*=(Scalar scale)
{
	for(int r = 0; r < dimension; r++)
	{
		(*this)[r] *= scale;
	}
	return *this;
}
Vector& Vector::operator/=(Scalar scale)
{
	for(int r = 0; r < dimension; r++)
	{
		(*this)[r] /= scale;
	}
	return *this;
}

//
// Vector-Returning Operators:
Vector Vector::operator+(const Vector& other)
{
	return Vector(*this) += other;
}
Vector Vector::operator-(const Vector& other)
{
	return Vector(*this) -= other;
}
Vector Vector::operator*(Scalar scale)
{
	return Vector(*this) *= scale;
}
Vector Vector::operator/(Scalar scale)
{
	return Vector(*this) /= scale;
}

//
// Dot Product:
Scalar Vector::operator*(const Vector& other)
{
	Scalar rtrn = 0.0;
	for(int r = 0; r < dimension; r++)
	{
		rtrn += (*this)[r] * other[r];
	}
	return rtrn;
}
