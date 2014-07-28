#include "Vector.h"


// 
// Operators with Assignment:
Vector& Vector::operator+=(const Vector& other)
{
	for(int r = 0; r < dimension(); r++)
	{
		(*this)[r] += other[r];
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& other)
{
	for(int r = 0; r < dimension(); r++)
	{
		(*this)[r] -= other[r];
	}
	return *this;
}
Vector& Vector::operator*=(Scalar scale)
{
	for(int r = 0; r < dimension(); r++)
	{
		(*this)[r] *= scale;
	}
	return *this;
}
Vector& Vector::operator/=(Scalar scale)
{
	for(int r = 0; r < dimension(); r++)
	{
		(*this)[r] /= scale;
	}
	return *this;
}

//
// Plain Operators (no assignment):
Vector Vector::operator+(const Vector& other) const
{
	return Vector(*this) += other;
}
Vector Vector::operator-(const Vector& other) const
{
	return Vector(*this) -= other;
}
Vector Vector::operator*(Scalar scale) const
{
	return Vector(*this) *= scale;
}
Vector Vector::operator/(Scalar scale) const
{
	return Vector(*this) /= scale;
}
