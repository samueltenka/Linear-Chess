#include "Matrix.h"
#include <random>

#define TOLERANCE 0.0001 // one in ten thousand


Vector random_unit_vector(int dimension) // not quite uniform on sphere, since corners of cubes get more.
{
	Vector rtrn(dimension);

	for(int r = 0; r < dimension; r++)
	{
		rtrn[r] = rand() - RAND_MAX/2;
	}

	rtrn.normalize();
	return rtrn;
}

Vector Matrix::biggest_eigenvector() const
{
	if(height == width)
	{
		int d = height;
		Vector guess = random_unit_vector(d);
		
		while(true) // dangerous! might not exit!
		{
			Vector better = (*this) * guess;
			better.normalize();
			better.positivify();
			if((better-guess).mag() < TOLERANCE)
			{
				break;
			}
			
			//// HERE WAS THE CODE THAT SHOWED THE PROBLEM OF NEGATIVE EIGENVALUES,
			//// A PROBLEM MANIFESTED BY better == -guess and hence better-guess != zero, 
			//// A PROBLEM NOW FIXED BY CALLING Vector::positivify.
			//Matrix P(3, d);
			//P[0] = guess; P[1] = better; P[2] = better-guess;
			//P.print_fancy();
			
			guess = better;
		}

		return guess;
	}
}

void Matrix::remove_from_span(Vector target)
{
	for(int r = 0; r < height; r++)
	{
		(*this)[r] = (*this)[r].perpendicular(target);
	}
}

Matrix Matrix::eigenvectors() const
{
	Matrix rtrn(height, width);

	Matrix M(*this);
	for(int r = 0; r < height; r++)
	{
		Vector next_eigenvector = M.biggest_eigenvector();

		M.remove_from_span(next_eigenvector);	// on account of this, new eigenvectors 
												//must be perpendicular to all previous ones.
		rtrn[r] = next_eigenvector;
	}

	return rtrn;
}
