#include "Matrix.h"


// row/column getters:
Vector Matrix::row(int r) const
{
	return (*this)[r];
}
Vector Matrix::column(int c) const
{
	Vector rtrn(height);
	for(int r = 0; r < height; r++)
	{
		rtrn[r] = (*this)[r][c];
	}
	return rtrn;
}


//
// Op-Equals on Components:
Matrix& Matrix::operator+=(const Matrix& other)
{
	for(int r = 0; r < height; r++)
	{
		(*this)[r] += other[r];
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& other)
{
	for(int r = 0; r < height; r++)
	{
		(*this)[r] -= other[r];
	}
	return *this;
}
Matrix& Matrix::operator*=(Scalar scale)
{
	for(int r = 0; r < height; r++)
	{
		(*this)[r] *= scale;
	}
	return *this;
}
Matrix& Matrix::operator/=(Scalar scale)
{
	for(int r = 0; r < height; r++)
	{
		(*this)[r] /= scale;
	}
	return *this;
}

//
// Operators on Components:
Matrix Matrix::operator+(const Matrix& other)
{
	return Matrix(*this) += other;
}
Matrix Matrix::operator-(const Matrix& other)
{
	return Matrix(*this) -= other;
}
Matrix Matrix::operator*(Scalar scale)
{
	return Matrix(*this) *= scale;
}
Matrix Matrix::operator/(Scalar scale)
{
	return Matrix(*this) /= scale;
}

//
// Action on a Vector
Vector Matrix::operator*(const Vector& v)
{
	Vector rtrn(height);
	for(int r = 0; r < height; r++)
	{
		rtrn[r] = row(r) * v; // dot product
	}
	return rtrn;
}

//
// Matrix Multiplication:
Matrix Matrix::operator*(const Matrix& other)
{	
	Matrix rtrn(height, other.width);
	for(int c = 0; c < other.width; c++)
	{
		rtrn[c] = (*this) * other.column(c); // M*v product
	}
	return rtrn;
}
//
// Matrix Multiplication with assignment:
Matrix& Matrix::operator*=(const Matrix& other)
{
	return ((*this) = (*this) * other);
}
