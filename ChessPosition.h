#include "ChessDimensions.h"
#include "ChessVector.h"
#include "LinkedList.h"


#ifndef CHESS_POSITION
#define CHESS_POSITION

struct Move
{
	Square source, destination;
	Move(Square s, Square d): source(s), destination(d) {}
	Move() {}
};

class ChessPosition // classical, i.e. exactly 1 or 0 pieces at each square
{
private:
	Piece* board[8][8]; // pointer to allow for empty. 

public:
	ChessPosition();
	~ChessPosition();
	void set_up();
	Piece*& piece_at(Square square);

private:
	LinkedList<Square> ray_from(Square source, int y_inc, int x_inc,								// geometry
								int max_length, Piece piece, bool takingOK, bool taking_required);	// stopping requirements (handles Kings, Queens, Rooks, Bishops, Pawns)
																									// (piece is needed to compare colors with destinations)
	LinkedList<Square> possible_destinations(Square source, Piece piece);
public:
	LinkedList<Move> possible_moves();

private:
	ChessVector state(); // some weight to possible moves.
public:
	void display(const char* filename);
	void print();

	void move(Move m);
	Move from_algebraic(const char* algebraic);
};
#endif
