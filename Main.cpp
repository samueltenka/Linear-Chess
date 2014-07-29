#include "Scalar.h"

#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include "ChessDimensions.h"
#include "ChessPosition.h"

#include "GraphicsBitmap.h"

#include <iostream>
using namespace std;


void main()
{
	//
	// Painting test:
	ChessPosition CP;
	Bitmap C(256, 256);
	
	CP.set_up();
	CP.move(Square(6, 4), Square(4, 4));

	CP.paint(C);
	C.write_to("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\canvas.bmp");


	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
