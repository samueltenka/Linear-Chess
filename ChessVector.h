#include "Vector.h"
#include "ChessDimensions.h"
#include "GraphicsBitmap.h"


#ifndef CHESS_VECTOR
#define CHESS_VECTOR
class ChessVector
{
private:
	Vector as_vector;
public:
	ChessVector();
	ChessVector(const ChessVector& other);
	void set_up();
	void zero();

	Scalar& component(Dimension d);
	void move(Square source, Square destination);

	void paint(Bitmap& C);
};
#endif
