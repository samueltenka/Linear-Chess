#include "Matrix.h"


Matrix Matrix::transpose() const
{
	Matrix rtrn(width, height); // width and height are switched
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			rtrn[c][r] = (*this)[r][c];
		}
	}

	return rtrn;
}

//
// In the following methods, we interpret (*this) as scattercloud, each row being a point:
Vector Matrix::center_of_mass() const
{
	Vector sum(width);
	sum.zero();
	for(int r = 0; r < height; r++)
	{
		sum += (*this)[r];
	}

	return sum/height;
}

void Matrix::center()
{
	Vector com = center_of_mass();

	for(int r = 0; r < height; r++)
	{
		(*this)[r] -= com;
	}
}

Matrix Matrix::covariance_matrix() const
{
	Matrix centered(*this);
	centered.center();

	return centered.transpose() * centered;	// as opposed to centered * centered.transpose().
}											// we want to correlate all the x-values with all the y-values,
											// so we need slices __across__ the rows --- i.e. columns of centered.
											// 
											// or think of it this way: whether there are 2 or 100 vectors, 
											// the covariance matrix should be DxD for a D-dimensional space.
											// centered is 2xD, so we want (Dx2 * 2xD), or (transpose * centered).

Matrix Matrix::principal_components(int number) const
{
	return covariance_matrix().eigenvectors(number);
}
