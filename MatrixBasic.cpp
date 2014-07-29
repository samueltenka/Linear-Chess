#include "Matrix.h"
#include <iostream>
using namespace std;


//
// Constructors:
Matrix::Matrix(int h, int w):
	height(h),
	width(w),
	Array(h) // array of rows
{
	// initialize rows:
	for(int r = 0; r < height; r++)
	{
		(*this)[r].initialize(w);
	}
}
Matrix::Matrix(const Matrix& other):
	height(other.height),
	width(other.width),
	Array(other.height) // array of rows
{
	// initialize rows:
	for(int r = 0; r < height; r++)
	{
		(*this)[r].initialize(width);
	}

	// copy:
	(*this) = other;
}

//
// Copier:
Matrix& Matrix::operator=(const Matrix& other)
{
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			(*this)[r] = other[r];
		}
	}
	return (*this);
}

//
// Print functions:
void Matrix::print() const
{
	for(int r = 0; r < height; r++)
	{
		(*this)[r].print_horizontal();
		cout << endl;
	}
}
void Matrix::print_fancy() const
{
	for(int r = 0; r < height; r++)
	{
		Vector row = (*this)[r];

		if(r == 0) // top:
		{
			cout << " / "; row.print_horizontal(); cout << "\\ ";
		}
		else if(r < height-1) // main body:
		{
			cout << "|  "; row.print_horizontal(); cout << " |";
		}
		else // bottom:
		{
			cout << " \\ "; row.print_horizontal(); cout << "/ ";
		}

		cout << endl;
	}
}
void Matrix::print_rowvectors() const
{
	for(int r = 0; r < height; r++)
	{
		(*this)[r].print_fancy();
		cout << endl;
	}
}
