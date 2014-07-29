#ifndef CHESS_DIMENSIONS
#define CHESS_DIMENSIONS

#define NUM_SQUARES 64
#define NUM_PIECES 12
#define NUM_DIMENSIONS (NUM_SQUARES*NUM_PIECES)

struct Square
{
	int rank, file;
	inline int index() {return 8*rank + file;}
	Square() {}
	Square(int index)
	{
		file = index%8; index /= 8;
		rank = index%8; 
	}
	Square(int r, int f): rank(r), file(f) {}
};
enum Color {black, white};
enum Species {pawn, knight, bishop, rook, queen, king};
struct Piece
{
	Color color;
	Species species;
	inline int index() {return 6*color + species;}
	Piece() {}
	Piece(int index)
	{
		species = static_cast<Species>(index%6); index /= 6;
		color = static_cast<Color>(index%2); index /= 2;
	}
	Piece(Color c, Species s): color(c), species(s) {}
};
struct Dimension
{
	Square square;
	Piece piece;
	inline int index() {return NUM_PIECES*square.index() + piece.index();}
	Dimension(int index)
	{
		piece.species = static_cast<Species>(index%6); index /= 6;
		piece.color = static_cast<Color>(index%2); index /= 2;
		square.file = index%8; index /= 8;
		square.rank = index%8;
	}
	Dimension(int r, int f, Color c, Species s): square(r, f), piece(c, s) {}
	Dimension(Square S, Piece P): square(S), piece(P) {}
};
#endif
