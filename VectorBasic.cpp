#include "Vector.h"
#include <iostream>
using namespace std;


//
// Data-management (i.e. Dimension-getter, Constructors w/ Initializer, and Copier)
inline int Vector::dimension() const
{
	return length;
}
Vector::Vector()
{
}
Vector::Vector(int d):
	Array(d)
{
}
Vector::Vector(const Vector& other):
	Array(other.dimension())
{
	(*this) = other;
}
Vector& Vector::operator=(const Vector& other) // copy
{
	for(int r = 0; r < dimension(); r++)
	{
		(*this)[r] = other[r];
	}
	return (*this);
}

//
// Printing:
void Vector::print()
{
	for(int r = 0; r < dimension(); r++)
	{
		printf("%+f\n", (*this)[r]);
	}
}
void Vector::print_fancy()
{
	for(int r = 0; r < dimension(); r++)
	{
		Scalar value = (*this)[r];
		if(r == 0) // top:
		{
			printf(" / %+f \\ \n", value);
		}
		else if(r < dimension()-1) // main body:
		{
			printf("|  %+f  |\n", value);
		}
		else // bottom:
		{
			printf(" \\ %+f / \n", value);
		}
	}
}
void Vector::print_horizontal()
{
	for(int r = 0; r < dimension(); r++)
	{
		printf("%+f ", (*this)[r]);
	}
}
