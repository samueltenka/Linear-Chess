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
	//
	// Test manual-movement:
	ChessPosition C;
	C.set_up();

	C.move(C.from_algebraic("pe4", black));
	C.move(C.from_algebraic("pe5", white));
	C.move(C.from_algebraic("Nf3", black));
	C.move(C.from_algebraic("Nc6", white));
	
	C.print();

	C.display("C:\\Users\\Sam\\Desktop\\Fall_2014\\Chess\\Programs\\canvas3.bmp");




	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
