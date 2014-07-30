#include "ChessPosition.h"
#include <cstdlib>


ChessPosition::ChessPosition()
{
	set_up();
}

Piece* ChessPosition::piece_at(Square square)
{
	return board[square.rank][square.file];
}

void ChessPosition::set_up()
{
	Species setup[8] = {rook, knight, bishop, queen, king, bishop, knight, rook};

	for(int f = 0; f < SIDELENGTH; f++) board[0][f] = new Piece(black, setup[f]);
	for(int f = 0; f < SIDELENGTH; f++) board[1][f] = NULL; //new Piece(black, pawn);

	for(int r = 2; r < 6; r++)
		for(int f = 0; f < SIDELENGTH; f++) board[r][f] = NULL;

	for(int f = 0; f < SIDELENGTH; f++) board[6][f] = new Piece(white, pawn);
	for(int f = 0; f < SIDELENGTH; f++) board[7][f] = new Piece(white, setup[f]);
}

ChessPosition::~ChessPosition()
{
	for(int r = 0; r < SIDELENGTH; r++)
	{
		for(int f = 0; f < SIDELENGTH; f++)
		{
			delete board[r][f]; // OK if NULL.
		}
	}
}

void ChessPosition::print()
{
	for(int r = 0; r < SIDELENGTH; r++)
	{
		for(int f = 0; f < SIDELENGTH; f++)
		{
			if(board[r][f] != NULL)
			cout << static_cast<int>(board[r][f]->species) << " ";
		}
		cout << endl;
	}
}



