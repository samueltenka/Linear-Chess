#include "ChessPosition.h"



ChessPosition::ChessPosition()
{
	as_vector.initialize(NUM_DIMENSIONS);
}
ChessPosition::ChessPosition(const ChessPosition& other)
{
	as_vector.initialize(NUM_DIMENSIONS);
	as_vector = other.as_vector;
}

void ChessPosition::set_up()
{
	as_vector.zero();

	Species setup[8] = {rook, knight, bishop, queen, king, bishop, knight, rook};
	for(int file = 0; file < 8; file++)
	{
		component(Dimension(0, file, black, setup[file])) = 1.0;	// black back
		component(Dimension(1, file, black, pawn)) = 1.0;			// black fore
		component(Dimension(6, file, white, pawn)) = 1.0;			// white back
		component(Dimension(7, file, white, setup[file])) = 1.0;	// white fore
	}
}

Scalar& ChessPosition::component(Dimension d)
{
	return as_vector[d.index()];
}

void ChessPosition::move(Square source, Square destination)
{
	int s = NUM_PIECES*source.index();
	int d = NUM_PIECES*destination.index();
	for(int p = 0; p < NUM_PIECES; p++)
	{
		// destination = source:
		as_vector[p + d] = as_vector[p + s];
		// source = 0
		as_vector[p + s] = 0;
	}
}
