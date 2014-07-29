#include "ChessPosition.h"
#include "GraphicsBitmap.h"


void ChessPosition::paint(Bitmap& C)
{
	RGB green_opacities(0.0, 1.0, 0.0);
	RGB red_opacities(1.0, 0.0, 0.0);
	RGB opacities[2] = {red_opacities, green_opacities};

	// read icons:
	Bitmap S("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\blue_square.bmp");

	Bitmap K("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\king.bmp");
	Bitmap Q("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\queen.bmp");
	Bitmap R("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\rook.bmp");
	Bitmap B("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\bishop.bmp");
	Bitmap N("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\knight.bmp");
	Bitmap P("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\pawn.bmp");
	Bitmap* icon[6] = {&P, &N, &B, &R, &Q, &K};


	// render on board:
	for(int i = 0; i < NUM_DIMENSIONS; i++)
	{
		Dimension D(i);
		int rank = D.square.rank, file = D.square.file;

		// checkerboard blue squares:
		if((rank+file)%2 == 1)
		{
			C.paint_icon(S, 0.1, rank*32, file*32);
		}

		// pieces:
		C.paint_icon(*icon[D.piece.species], opacities[D.piece.color] * component(D), rank*32, file*32);
	}
}
