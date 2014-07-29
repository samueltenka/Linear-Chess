#include "Vector.h"
#include <iostream>
using namespace std;

#define SPACE 5
#define HORIZONTAL_SPACE 7


//
// Data-management (i.e. Dimension-getter, Constructors, Copier, Initializer-by-Zeroer)
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
void Vector::zero()
{
	for(int r = 0; r < dimension(); r++)
	{
		(*this)[r] = 0;
	}
}

//
// Printing:
void Vector::print() const
{
	for(int r = 0; r < dimension(); r++)
	{
		printf("%*.4f\n", SPACE, (*this)[r]);
	}
}
void Vector::print_fancy() const
{
	for(int r = 0; r < dimension(); r++)
	{
		Scalar value = (*this)[r];
		if(r == 0) // top:
		{
			printf(" / %*.4f \\ \n", SPACE, value);
		}
		else if(r < dimension()-1) // main body:
		{
			printf("|  %*.4f  |\n", SPACE, value);
		}
		else // bottom:
		{
			printf(" \\ %*.4f / \n", SPACE, value);
		}
	}
}
void Vector::print_horizontal() const
{
	for(int r = 0; r < dimension(); r++)
	{
		printf("%*.4f ", HORIZONTAL_SPACE, (*this)[r]);
	}
}
