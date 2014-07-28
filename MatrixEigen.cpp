#include "Matrix.h"
#include <random>
#include <iostream>
using namespace std;

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
			//cout << "    multiplying..." << endl;
			Vector better = (*this) * guess;
			//cout << "      done!" << endl;
			better.normalize();
			better.positivify();
			if((better-guess).mag() < TOLERANCE)
			{
				break;
			}
			
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

Matrix Matrix::eigenvectors(int number) const
{
	Matrix rtrn(number, width);
	
	Matrix M = *this;
	//cout << "hei";
	for(int r = 0; r < number; r++)
	{
		cout << "r = " << r << endl;
		Vector next_eigenvector = M.biggest_eigenvector();

		M.remove_from_span(next_eigenvector);	// on account of this, new eigenvectors 
												//must be perpendicular to all previous ones.
		rtrn[r] = next_eigenvector;
	}

	return rtrn;
}
