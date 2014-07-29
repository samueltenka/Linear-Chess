#include "Scalar.h"

#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

//#include "ChessDimensions.h"
//#include "ChessPosition.h"
//#include "ChessGraphics.h"

#include "GraphicsBitmap.h"

#include <iostream>
using namespace std;


void main()
{
	//
	// Painting test:
	Bitmap C(256, 256);

	Bitmap S(32, 32);
	S.read_from("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\square.bmp");
	for(int rank = 0; rank < 8; rank++)
	{
		for(int file = 0; file < 8; file++)
		{
			if((rank+file)%2 == 0) continue;

			C.paint_icon(S, 1.0, rank*32, file*32);
		}
	}

	Bitmap I(32, 32);
	I.read_from("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\red_king.bmp");

	C.paint_icon(I, 0.2, 60, 60);
	C.paint_icon(I, 0.8, 120, 40);
	C.paint_icon(I, 0.8, 110, 45);
	C.write_to("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\canvas.bmp");


	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
