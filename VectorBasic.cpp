#include "Vector.h"
#include <iostream>
using namespace std;

#define SPACE 5
#define HORIZONTAL_SPACE 7


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
void Vector::print() const
{
	for(int r = 0; r < dimension(); r++)
	{
		printf("%*.2f\n", SPACE, (*this)[r]);
	}
}
void Vector::print_fancy() const
{
	for(int r = 0; r < dimension(); r++)
	{
		Scalar value = (*this)[r];
		if(r == 0) // top:
		{
			printf(" / %*.2f \\ \n", SPACE, value);
		}
		else if(r < dimension()-1) // main body:
		{
			printf("|  %*.2f  |\n", SPACE, value);
		}
		else // bottom:
		{
			printf(" \\ %*.2f / \n", SPACE, value);
		}
	}
}
void Vector::print_horizontal() const
{
	for(int r = 0; r < dimension(); r++)
	{
		printf("%*.2f ", HORIZONTAL_SPACE, (*this)[r]);
	}
}
