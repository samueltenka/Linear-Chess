#include "Vector.h"
#include <math.h>


//
// Dot Product:
Scalar Vector::operator*(const Vector& other) const
{
	Scalar rtrn = 0.0;
	for(int r = 0; r < dimension(); r++)
	{
		rtrn += (*this)[r] * other[r];
	}
	return rtrn;
}

//
// Components of Projection:
Vector Vector::projection(const Vector& axis) const
{
	// concentrate the two mags in (a/|a|)(v*(a/|a|)
	// to get                      (a)(v*a)/(|a|^2)
	return axis * ((*this)*axis)/axis.mag2();
}
Vector Vector::perpendicular(const Vector& axis) const
{
	return *this - projection(axis);
}

// 
// Norm stuff:
inline Scalar Vector::mag2() const
{
	return (*this) * (*this);
}
inline Scalar Vector::mag() const
{
	return sqrt(mag2());
}
void Vector::normalize()
{
	(*this) /= mag();
}

void Vector::positivify() // ensures first non-zero element is positive.
{
	Scalar val;
	for(int r = 0; r < dimension(); r++)
	{
		val = (*this)[r];
		if(val < 0)
		{
			(*this) *= -1;
		}
		if(val != 0)
		{
			 break;
		}
	}
}
