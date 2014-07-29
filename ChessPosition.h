#include "Vector.h"
#include "ChessDimensions.h"
#include "GraphicsBitmap.h"


#ifndef CHESS_POSITION
#define CHESS_POSITION
class ChessPosition
{
private:
	Vector as_vector;
public:
	ChessPosition();
	ChessPosition(const ChessPosition& other);
	void set_up();

	Scalar& component(Dimension d);

	void move(Square source, Square destination);

	void paint(Bitmap& C);
};
#endif
