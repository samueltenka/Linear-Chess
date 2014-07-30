#include "Scalar.h"

#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include "LinkedList.h"

#include "ChessDimensions.h"
#include "ChessVector.h"
#include "ChessPosition.h"

#include "GraphicsRGB.h"
#include "GraphicsArray2D.h"
#include "GraphicsBitmap.h"

#include <iostream>
using namespace std;


void main()
{
	ChessPosition C;
	C.set_up();
	C.print();

	ChessVector V = C.state();

	Bitmap I(256, 256);
	V.paint(I);
	I.write_to("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\canvas2.bmp");


	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
