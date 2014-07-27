#include "Vector.h"
#include <iostream>
using namespace std;


Vector::Vector(int d):
	dimension(d),
	Array(d)
{
}
Vector& Vector::operator=(Vector other) // copy
{
	for(int r = 0; r < dimension; r++)
	{
		(*this)[r] = other[r];
	}
	return *this;
}
void Vector::print()
{
	for(int r = 0; r < dimension; r++)
	{
		cout << (*this)[r] << endl;
	}
}
void Vector::print_fancy()
{
	for(int r = 0; r < dimension; r++)
	{
		Scalar value = (*this)[r];
		if(r == 0) // top
		{
			printf(" / %+f \\ \n", value);
		}
		else if(r < dimension-1) // main body:
		{
			printf("|  %+f  |\n", value);
		}
		else // bottom:
		{
			printf(" \\ %+f / \n", value);
		}
	}
}
