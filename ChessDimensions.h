#ifndef CHESS_DIMENSIONS
#define CHESS_DIMENSIONS

#define SIDELENGTH 8
#define NUM_SQUARES (SIDELENGTH*SIDELENGTH)
#define NUM_COLORS 2
#define NUM_SPECIES 6
#define NUM_PIECES (NUM_COLORS*NUM_SPECIES)
#define NUM_DIMENSIONS (NUM_SQUARES*NUM_PIECES)

class ChessPosition;

struct Square
{
	int rank, file;
	inline int index() {return 8*rank + file;}
	Square() {}
	Square(int index)
	{
		file = index%SIDELENGTH; index /= SIDELENGTH;
		rank = index%SIDELENGTH;
	}
	Square(int r, int f): rank(r), file(f) {}

	inline bool empty_on(ChessPosition& CP);
	inline bool on_board();
};
enum Color {black, white};
enum Species {pawn, knight, bishop, rook, queen, king};
struct Piece
{
	Color color;
	Species species;
	inline int index() {return NUM_SPECIES*color + species;}
	Piece() {}
	Piece(int index)
	{
		species = static_cast<Species>(index%NUM_SPECIES); index /= NUM_SPECIES;
		color = static_cast<Color>(index%NUM_COLORS);
	}
	Piece(Color c, Species s): color(c), species(s) {}

	inline bool can_arrive_at(Square destination, ChessPosition& CP, bool takingOK, bool taking_required); // needs piece's color info
};
struct Dimension
{
	Square square;
	Piece piece;
	inline int index() {return NUM_PIECES*square.index() + piece.index();}
	Dimension() {}
	Dimension(int index)
	{
		piece.species = static_cast<Species>(index%NUM_SPECIES); index /= NUM_SPECIES;
		piece.color = static_cast<Color>(index%NUM_COLORS); index /= NUM_COLORS;
		square.file = index%SIDELENGTH; index /= SIDELENGTH;
		square.rank = index%SIDELENGTH;
	}
	Dimension(int r, int f, Color c, Species s): square(r, f), piece(c, s) {}
	Dimension(Square S, Piece P): square(S), piece(P) {}
};
#endif
